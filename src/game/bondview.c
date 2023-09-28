#include <ultra64.h>
#include <math.h>
#include <bondtypes.h>
#include <boss.h>
#include <fr.h>
#include <joy.h>
#include <music.h>
#include <snd.h>
#include <str.h>
#include <watch.h>
#include "bg.h"
#include "bondview.h"
#include "bondinv.h"
#include "bondhead.h"
#include "chr.h"
#include "chrai.h"
#include "chr_b.h"
#include "chrlv.h"
#include "chrobjhandler.h"
#include "debugmenu_handler.h"
#include "file.h"
#include "front.h"
#include "gun.h"
#include "initanitable.h"
#include "loadobjectmodel.h"
#include "lvl.h"
#include "lvl_text.h"
#include "math_atan2f.h"
#include "matrixmath.h"
#include "mp_music.h"
#include "mp_watch.h"
#include "objecthandler.h"
#include "player.h"
#include "player_2.h"
#include "quaternion.h"
#include "random.h"
#include "stan.h"
#include "textrelated.h"
#include "unk_0C0A70.h"
#include "unk_0BC530.h"
#include "unk_0A1DA0.h"
#include "explosions.h"
#include "os_extension.h"
#include "unk_0B3200.h"

#ifdef VERSION_EU

    #define BONDVIEW_AUTOAIM_TIME 0x19 /* 25 */

    #define BONDVIEW_INTRO_CAMERA_BONDMESSCNT_A 0x1a
    #define BONDVIEW_INTRO_CAMERA_BONDMESSCNT_B 0x19
    #define BONDVIEW_INTRO_CAMERA_BONDMESSCNT_C 0x64

    #define BONDVIEW_UPPER_TEXT_TIMER_A 0x33
    #define BONDVIEW_UPPER_TEXT_TIMER_B 0x32
    #define BONDVIEW_UPPER_TEXT_TIMER_C 0xc8

    #define EU_CAMERA_8003642C_ASPECT 1.19047617912f

#else

    #define BONDVIEW_AUTOAIM_TIME 0x1e /* 30 */

    #define BONDVIEW_INTRO_CAMERA_BONDMESSCNT_A 0x1f
    #define BONDVIEW_INTRO_CAMERA_BONDMESSCNT_B 0x1e
    #define BONDVIEW_INTRO_CAMERA_BONDMESSCNT_C 0x78

    #define BONDVIEW_UPPER_TEXT_TIMER_A 0x3d
    #define BONDVIEW_UPPER_TEXT_TIMER_B 0x3c
    #define BONDVIEW_UPPER_TEXT_TIMER_C 0xf0

#endif

#define BONDVIEW_HUD_MSG_TOP_BUFFER_LENGTH 0x97
#define BONDVIEW_HUD_MSG_BOTTOM_BUFFER_LENGTH 0x65


#if defined(VERSION_US)
    #define BONDVIEW_2ND_FONTTABLE(_param) copy_2ndfonttable
    #define BONDVIEW_1ST_FONTTABLE(_param) copy_1stfonttable
#elif defined(VERSION_JP) || defined(VERSION_EU)
    #define BONDVIEW_2ND_FONTTABLE(_param) dword_CODE_bss_jp80079CEC[_param]
    #define BONDVIEW_1ST_FONTTABLE(_param) dword_CODE_bss_jp80079Cd8[_param]
#endif


#if defined(VERSION_US) || defined(VERSION_JP)
    #define BONDVIEW_VIEW_TOP_OFFSET_1 0x0C
    #define BONDVIEW_VIEW_TOP_OFFSET_2 0x28
    #define BONDVIEW_VIEW_TOP_OFFSET_3 0x10
#elif defined(VERSION_EU)
    #define BONDVIEW_VIEW_TOP_OFFSET_1 0x16
    #define BONDVIEW_VIEW_TOP_OFFSET_2 0x32
    #define BONDVIEW_VIEW_TOP_OFFSET_3 0x14
#endif


#if defined(VERSION_EU)
    #define TANKUPDATEROTATION_SCALE 0.904799997807f      
    #define TANKTURRETVERTICALANGLERELATED_SCALE 0.928399980068f
    #define TANK_UNKD0_SCALE 0.79960000515f
    #define CHR_OBJ_ACCEL_SPEED_FACTOR 0.6f
    #define CHR_OBJ_MAXSPEED 6.0f
    #define MAX_SPEED_FACTOR 0.8f
    #define TANK_DAMAGE_PENTALTY_TICKS 75

    #define TANK_VERT_ANGLE_FACTOR 0.0716000199318f
    #define TANK_VERT_ANGLE_RAD_FACTOR 0.0952f

    #define MAX_AIMLOCK_SPEED_DEFAULT 0.8344f

    #define THREE_SECOND_TICKS 150
    #define PLAYER_TICKEXPLODE_FACTOR 12

    #define CLIPPING_CLOCK_FACTOR 0.765100002289f
    #define CLIPPING_FIELD88_FACTOR 0.234899997711f
    #define CLIPPING_FIELD8C_VALUE 12
    #define CLIPPING_FIELD90_VALUE -5.625f
#else
    #define TANKUPDATEROTATION_SCALE 0.92f
    #define TANKTURRETVERTICALANGLERELATED_SCALE 0.94f
    #define TANK_UNKD0_SCALE 0.83f
    #define CHR_OBJ_ACCEL_SPEED_FACTOR 0.5f
    #define CHR_OBJ_MAXSPEED 5.0f
    #define MAX_SPEED_FACTOR 0.8f
    #define TANK_DAMAGE_PENTALTY_TICKS 90

    #define TANK_VERT_ANGLE_FACTOR 0.0600000023842f
    #define TANK_VERT_ANGLE_RAD_FACTOR 0.0799999833107f
    #define MAX_AIMLOCK_SPEED_DEFAULT 0.86f

    #define THREE_SECOND_TICKS 180
    #define PLAYER_TICKEXPLODE_FACTOR 15

    #define CLIPPING_CLOCK_FACTOR 0.8f
    #define CLIPPING_FIELD88_FACTOR 0.19999999f
    #define CLIPPING_FIELD8C_VALUE 15
    #define CLIPPING_FIELD90_VALUE -4.5f
#endif

#define FULL_CROUCH_OFFSET -100.0f

#define SPEED_REGULAR_MAX  1.0f
#define SPEED_RUN_MAX      1.25f
#define SPEED_TICK_ADJUST  0.01f
#define TANK_MAX_SPEED     15.0f


#define FLOAT_TEN_A 10.0f
#define FLOAT_TEN_B 10.00f


// bss
coord3d flt_CODE_bss_80079940;
f32 flt_CODE_bss_8007994C;
coord3d flt_CODE_bss_80079950;
f32 flt_CODE_bss_8007995C;
coord3d flt_CODE_bss_80079960;
f32 flt_CODE_bss_8007996C;
coord3d flt_CODE_bss_80079970;
f32 flt_CODE_bss_8007997C;
//CODE.bss:80079980
f32 flt_CODE_bss_80079980;
//CODE.bss:80079984
f32 flt_CODE_bss_80079984;
//CODE.bss:80079988
f32 flt_CODE_bss_80079988;
//CODE.bss:8007998C
f32 flt_CODE_bss_8007998C;

//CODE.bss:80079990
vec3d g_ForceBondMoveOffset;
// //CODE.bss:80079994
// f32 flt_CODE_bss_80079994;
// //CODE.bss:80079998
// f32 flt_CODE_bss_80079998;

//CODE.bss:8007999C
s32 g_SurroundBondWithExplosionsTicks;
//CODE.bss:800799A0
s32 g_PlayerTickExplodeCreatePosition;
//CODE.bss:800799A4
s32 dword_CODE_bss_800799A4;

//CODE.bss:800799A8
struct coord3d g_TankModelPositionOffset;

//CODE.bss:800799B4
s32 g_TankEngineSfxVolume;

/**
 * Address 0x800799B8.
 * State 0: begin.
 * State 1: Finished sitting down/turning, queue audio.
 * State 2: complete
*/
s32 g_EnterTankAudioState;

/**
 * Address 0x800799BC.
*/
f32 g_TankEnteringSitHeight;

/**
 * Address 0x800799C0.
*/
f32 g_TankEnteringSitHeightRemain;

/**
 * Address 0x800799C4.
*/
f32 g_TankEnterBondHorizAngleDeg;

/**
 * Address 0x800799C8.
*/
f32 g_TankEnterBondVertAngleDeg;

//CODE.bss:800799CC
f32 flt_CODE_bss_800799CC;

//CODE.bss:800799D0
struct coord3d g_EnterTankCoord;

//CODE.bss:800799DC
f32 flt_CODE_bss_800799DC;
//CODE.bss:800799E0
s32 starting_right_weapon;
//CODE.bss:800799E4
s32 starting_left_weapon;

//CODE.bss:800799E8
struct coord3d flt_CODE_bss_800799E8;

//CODE.bss:800799F4
struct PropRecord* dword_CODE_bss_800799F4;

//CODE.bss:800799F8
PadRecord * dword_CODE_bss_800799F8;
//CODE.bss:800799FC
CutsceneRecord *gBondViewCutscene;
//CODE.bss:80079A00
f32 flt_CODE_bss_80079A00;
//CODE.bss:80079A04
f32 flt_CODE_bss_80079A04;
//CODE.bss:80079A08
f32 flt_CODE_bss_80079A08;
//CODE.bss:80079A0C
f32 flt_CODE_bss_80079A0C;
//CODE.bss:80079A10
f32 flt_CODE_bss_80079A10;
//CODE.bss:80079A14
s32 dword_CODE_bss_80079A14;
//CODE.bss:80079A18
enum CAMERAMODE dword_CODE_bss_80079A18;
//CODE.bss:80079A1C
s32 dword_CODE_bss_80079A1C;
//CODE.bss:80079A20
s32 mission_timer;

#if defined(VERSION_JP) || defined(VERSION_EU)
//CODE.bss:80079A24
f32 watch_time_0;
#else
//CODE.bss:80079A24
s32 watch_time_0;
#endif

/**
 * Address 80079A28
 * EU .bss 80068508
*/
char stringbuffer_lowerleft[0x5][BONDVIEW_HUD_MSG_BOTTOM_BUFFER_LENGTH];
char dword_CODE_bss_80079c21[0x04];

#if defined(BUGFIX_R1)
//CODE.bss:80079Cd8
s32 dword_CODE_bss_jp80079Cd8[0x05];
s32 dword_CODE_bss_jp80079CEC[0x05];
#endif

/**
 * Address 80079C28
 * EU .bss 80068738
*/
PadRecord *g_Startpad[0x10];

//CODE.bss:80079C68
s32 startpadcount;
//CODE.bss:80079C6C
s32 dword_CODE_bss_80079C6C;

#if defined LEFTOVERDEBUG
//CODE.bss:80079C70
/***/
char stringbuffer_top[0x2][BONDVIEW_HUD_MSG_TOP_BUFFER_LENGTH];
u16 dword_CODE_bss_80079d9E;
#endif

//CODE.bss:80079DA0
/**
 * EU .bss 80078780
*/
StandTilePoint *dword_CODE_bss_80079DA0;
//CODE.bss:80079DA4
StandTilePoint *dword_CODE_bss_80079DA4;

//CODE.bss:80079DA8
s32 dword_CODE_bss_80079DA8[BSS_80079DA8_LENGTH];

#ifndef VERSION_EU
//CODE.bss:80079DC8
char dword_CODE_bss_80079DC8[0x3C];
#else
char dword_CODE_bss_80079DC8[0x2][BONDVIEW_HUD_MSG_TOP_BUFFER_LENGTH];
char dword_CODE_bss_80079EF6[0x3C];
#endif

//CODE.bss:80079E04
f32 g_MpSwirlRotateSpeed;
//CODE.bss:80079E08
f32 g_MpSwirlAngleDegrees;
//CODE.bss:80079E0C
f32 g_MpSwirlForwardSpeed;
//CODE.bss:80079E10
f32 g_MpSwirlDistance;


// data
//D:80036420
s32 D_80036420 = 0;

/**
 * When set, will increment each tick until reaching a threshold value (4).
 * Then current items will be unequipped from left and run hands.
 * Address 0x80036424.
*/
s32 g_bondviewForceDisarm = 0;

//D:80036428
s32 resolution = 0;
//D:8003642C
s32 camera_8003642C = 0;
//D:80036430
s32 camera_80036430 = 0;
//D:80036434
s32 camera_80036434 = 0;
//D:80036438
s32 camera_80036438 = 0;
//D:8003643C
s32 D_8003643C = 0;
//D:80036440
CreditsEntry *D_80036440 = NULL;
//D:80036444
s32 g_SurroundBondWithExplosionsFlag = 0;

//D:80036448
s32 in_tank_flag = 0;

//D:8003644C
struct PropRecord *g_WorldTankProp = NULL;

//D:80036450
struct PropRecord *g_PlayerTankProp = NULL;

/**
 * Related to g_PlayerTankProp.
 * Address 0x80036454.
 */
f32 g_PlayerTankYOffset = 0;

/**
 * US address 80036458.
*/
ALSoundState * g_TankSfxState[2] = { NULL, NULL };

/**
 * min -3.749999, max +3.749999
 * Address 0x80036460.
*/
f32 g_TankTurnSpeed = 0;

/**
 * Address 0x80036464.
*/
f32 g_TankOrientationAngle = 0;

//D:80036468
f32 D_80036468 = 0.0f;

/**
 * Argument to sinf,cosf.
 * 
 * Address 0x8003646C.
 */
f32 g_TankTurretVerticalAngle = 0;

/**
 * Address 0x80036470.
*/
f32 g_TankTurretVerticalAngleRelated = 0;

/**
 * Address 0x80036474.
*/
f32 g_TankTurretOrientationAngleRad = 0;

//D:80036478
f32 D_80036478 = 0;

//D:8003647C
f32 D_8003647C = 0;

/**
 * Can enter tank, remains set once Bond is in tank.
 * Address 0x80036480.80036480
*/
s32 g_BondCanEnterTank = 0;

/**
 * Address 0x80036484.
*/
f32 g_TankTurretAngle = 0;

/**
 * Address 0x80036488.
*/
f32 g_TankTurretTurn = 0;

//D:8003648C
s32 g_ExplodeTankOnDeathFlag = 0;
//D:80036490
s32 g_TankDamagePenaltyTicks = 0;
//D:80036494
enum CAMERAMODE g_CameraMode = CAMERAMODE_NONE;
//D:80036498
enum CAMERAMODE g_CameraAfterCinema = CAMERAMODE_NONE;
//D:8003649C
s32 D_8003649C = 0;
//D:800364A0
s32 stop_time_flag = 0;
//D:800364A4
f32 D_800364A4 = 0;
//D:800364A8
s32 D_800364A8 = 1;
//D:800364AC
struct SetupIntroSwirl *g_IntroSwirl = NULL;
//D:800364B0
s32 D_800364B0 = 1;
//D:800364B4
s32 g_PlayerInvincible = 0;
//D:800364B8
struct SetupIntroCamera* g_CurrentSetupIntroCamera = NULL;
//D:800364BC
s32 g_SetupIntroCameraCount = 0;
//D:800364C0
struct SetupIntroCamera *ptr_random06cam_entry = NULL;

/**
 * Flag to toggle invisibility cheat.
 * 1 = visible to guards
 * 0 = not visible to guards
 * 
 * Address 0x800364C4.
 */
s32 g_VisibleToGuardsFlag = 1;

//D:800364C8
s32 obj_collision_flag = 1;
//D:800364CC
f32 D_800364CC = 1.0;
//D:800364D0
f32 D_800364D0 = 1.0;
//D:800364D4
f32 D_800364D4 = 1.0;

/**
 * Address 0x800364D8.
*/
s32 g_bondviewBondDeathAnimations[] = {
    PTR_ANIM_death_forward_face_down,
    PTR_ANIM_death_forward_spin_face_up,
    PTR_ANIM_death_backward_fall_face_up1,
    PTR_ANIM_death_backward_spin_face_down_right,
    PTR_ANIM_death_backward_spin_face_up_right,
    PTR_ANIM_death_backward_spin_face_down_left,
    PTR_ANIM_death_backward_spin_face_up_left,
    PTR_ANIM_death_forward_face_down_hard,
    PTR_ANIM_death_forward_face_down_soft,
    PTR_ANIM_death_fetal_position_right,
    PTR_ANIM_death_fetal_position_left,
    PTR_ANIM_death_backward_fall_face_up2,
    0
};

/**
 * Address 0x8003650C.
*/
s32 g_bondviewBondDeathAnimationsCount = 0;

//D:80036510
enum CAMERAMODE D_80036510 = CAMERAMODE_NONE;
//D:80036514
s32 g_IntroAnimationIndex = 0;

//D:80036518
struct struct_4 stage_intro_anim_table[] = {
    {0x5744, 95.0, -1.0, 0.02},
    {0x6254, 7.0, 40.0, 0.5},
    {0x78C8, 0.0, -1.0, 0.5},
    {0x7AA8, 0.0, -1.0, 0.5},
    {0x7C4C, 0.0, -1.0, 0.5},
    {0x7D04, 0.0, -1.0, 0.5},
    {0x7F0C, 0.0, -1.0, 0.5},
    {0x7FB4, 0.0, -1.0, 0.5},
    {0xD89C, 0.0, -1.0, 0.5}
};

//D:800365A8
f32 watch_transition_time = 0.90909088;

//D:800365AC
WeaponObjRecord dummy_08_pp7_obj[] = {
    0x0100,
    0x00,
    0x08,
    PROP_CHRWPPK,
    0x4000, 
    0x00000000, 
    0x00000000,
    NULL, 
    NULL, 
    {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    },
    {0.0f, 0.0f, 0.0f},
    {0x00000000},
    NULL, 
    NULL,
    0.0f, 
    1000.0f,
    {0xff, 0xff, 0xff, 0x00},
    0xff,
    0xff,
    0xff,
    0x00,
    ITEM_WPPK,
    -1,
    -1,
    NULL
};


//D:80036634
struct DamageType g_DamageTypes[] = {
        {   0,    10.0,    60.0,    0.6,    0,    5.0,    40.0,    1.0,            0xFF,       0xFF,       0xFF},
        {   0,    10.0,    60.0,    0.6,    0,    5.0,    40.0,    1.0,            0xFF,       0xFF,       0xFF},
        {   0,    10.0,    50.0,    0.6,    0,    5.0,    30.0,    0.800000011921, 0xFF,       0xFF,       0xFF},
        {   0,    10.0,    40.0,    0.6,    0,    5.0,    25.0,    0.600000023842, 0xFF,       0xFF,       0xFF},
        {   0,    10.0,    35.0,    0.6,    0,    5.0,    22.0,    0.550000011921, 0xFF,       0xFF,       0xFF},
        {   0,    10.0,    30.0,    0.6,    0,    5.0,    19.0,    0.5,            0xFF,       0xFF,       0xFF},
        {   0,    10.0,    30.0,    0.6,    0,    5.0,    17.0,    0.449999988079, 0xFF,       0xFF,       0xFF},
        {   0,    10.0,    30.0,    0.6,    0,    5.0,    15.0,    0.40000000596,  0xFF,       0xFF,       0xFF}
};


//D:80036794
struct HealthDamageType g_HealthDamageTypes[8] = {
    { 0, 40, 100 },
    { 0, 30, 80 },
    { 0, 20, 60 },
    { 0, 20, 60 },
    { 0, 20, 60 },
    { 0, 20, 50 },
    { 0, 20, 50 },
    { 0, 20, 50 }
};

/**
 * US Address 0x800367F4.
*/
struct coord3d g_DefaultMoveBondOffset = { 0 };


/**
 * struct player property `pos` .
 * US address 80036800.
 */
struct coord3d g_DefaultFrozenPlayerPos = { 0 };

/**
 * struct player property `pos2`.
 * US address 8003680C.
 */
struct coord3d g_DefaultFrozenPlayerPos2 = { 0, 0, 1.0f };

/**
 * struct player property `offset`.
 * US address 80036818.
 */
struct coord3d g_DefaultFrozenPlayerOffset = { 0, 1.0f, 0 };

/**
 * struct player property `offset`.
 * US address 80036824.
 */
struct coord3d g_DefaultFrozenMoveOffset = { 0 };

//D:80036830
s32 D_80036830 = 0;
//D:80036834
s32 D_80036834 = 0;
//D:80036838
s32 D_80036838 = 0;
//D:8003683C
struct unk_joint_list D_8003683C = {NULL, 1, 3, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, 0};
//D:8003687C
s32 D_8003687C = 0;

//D:80036880
s32 D_80036880 = 0;
//D:80036884
s32 D_80036884 = 0;
//D:80036888
s32 D_80036888 = 0;

//D:8003688C
s32 D_8003688C = 0;
//D:80036890
s32 D_80036890 = 0;
//D:80036894
s32 D_80036894 = 0;
//D:80036898
s32 status_bar_text_buffer_index = 0;
//D:8003689C
s32 display_statusbar = 0;
#ifdef BUGFIX_R0
//D:800368A0
s32 copy_1stfonttable = 0;
//D:800368A4
s32 copy_2ndfonttable = 0;
#endif
//D:800368A8
s32 upper_text_buffer_index = 0;
//D:800368AC
s32 display_upper_text_window = 0;
//D:800368B0
s32 upper_text_window_timer = 0xFFFFFFFF;
s32 g_UpperTextDisplayFlag = 0;
//D:800368B8
u8 D_800368B8[10][3] = {"n", "ne", "e", "se", "s", "sw", "w", "nw", "n", "" };

//D:800368D8
struct firing_anim_struct firing_animation_groups[] = {
    {pistol_firing_animation_group1, 0, 0.1, 79.0, 87.0},
    {&D_80030660[2], 0, 0.5, 0.0, -1.0},
    {&D_80030660[3], 0, 0.5, 0.0, -1.0},
    {&D_80030660[8], 0, 0.5, 0.0, -1.0},
    {&D_80030660[9], 0, 0.5, 0.0, -1.0},
    {crouched_pistol_firing_animation_group1, 0, 0.1, 56.0, 68.0},
    {rifle_firing_animation_group1, 0, 0.050000001, 35.0, 40.0},
    {&D_80030660[0], 0, 0.5, 0.0, -1.0},
    {&D_80030660[1], 0, 0.5, 0.0, -1.0},
    {&D_80030660[8], 0, 0.5, 0.0, -1.0},
    {&D_80030660[9], 0, 0.5, 0.0, -1.0},
    {crouched_rifle_firing_animation_groupA, 0, 0.1, 45.0, 55.0},
    {NULL, 0x8194, 0.25, 0.0, -1.0},
    {NULL, 0x8204, 0.5, 0.0, -1.0},
    {NULL, 0x777C, 0.5, 0.0, -1.0},
    {&D_80030660[8], 0, 0.5, 0.0, -1.0},
    {&D_80030660[9], 0, 0.5, 0.0, -1.0},
    {NULL, 0x6C18, 0.050000001, 28.0, 29.0},
    {doubles_firing_animation_group1, 0, 0.1, 32.0, 42.0},
    {&D_80030660[4], 0, 0.5, 0.0, -1.0},
    {&D_80030660[5], 0, 0.5, 0.0, -1.0},
    {&D_80030660[8], 0, 0.5, 0.0, -1.0},
    {&D_80030660[8], 0, 0.5, 0.0, -1.0},
    {crouched_doubles_firing_animation_group1, 0, 0.1, 37.0, 47.0}
};

//D:80036AB8
s32 D_80036AB8 = 2;
//D:80036ABC
s32 D_80036ABC = 0xFFFFFFFF;
//D:80036AC0
f32 D_80036AC0 = 1.0;
//D:80036AC4
f32 D_80036AC4 = 0.1;

// forward declarations

void sub_GAME_7F07DE9C(struct player *player);
void sub_GAME_7F07DE64(struct player *player);
void bondviewUpdateWatchZoomIn(void);
void bondviewSetPauseWatchRelated(f32 arg0);
void bondviewSetPauseWatchRelatedAlt(f32 arg0);
void bondviewStepWatchAnimation(void);
f32 bondviewGetPauseAnimationPercent(void);
void bondviewCurrentPlayerUpdateSpeedVerta(f32 value);
void bondviewCurrentPlayerUpdateSpeedTheta(f32 value);
s16 bondviewGetCurrentPlayerViewportWidth(void);
s16 bondviewGetCurrentPlayerViewportHeight(void);
s16 bondviewGetCurrentPlayerViewportUly(void);
void currentPlayerTickChrFade(void);
void currentPlayerUpdateColourScreenProperties(void);
s16 getWidth320or440(void);
s16 getHeight330or240(void);
void sub_GAME_7F07B1A4(void);
bool currentPlayerIsFadeComplete(void);
s16 get_curplayer_viewport_ulx(void);
void bondviewFrozenMoveBond(s8, s8, u16, u16);
void bondviewMovePlayerUpdateViewport(s8 arg0, s8 arg1, u16 arg2);
void bondviewUpdateCurrentRoomPosition(s32 arg0);
void trigger_solo_watch_menu(s32 arg0);
void bondviewUpdatePlayerCollisionBounds(void);
void bondviewGetTankCollisionBounds(struct rect4f *, coord3d *, f32);
void bondviewIntroCameraTextTick(void);
void bondviewUpperTextWindowTimerTick(void);
void sub_GAME_7F07DEFC(void);
void MoveBond(s8 arg0, s8 arg1, u16 arg2, u16 arg3);
void bondviewProcessInput(s8 arg0, s8 arg1, u16 arg2, u16 arg3);
void bondviewPlayerTickDamageAndHealth(void);
void bondviewPlayerTickExplode(void);
void bondviewPlayerStopAudioForPause(void);
void bondviewWatchAnimationTick(void);
void bondviewUpdatePlayerCollisionPositionFields(void);
void bondviewTankModelRotationRelated(void);
s32 bondviewTankCollisionStatus(struct coord3d *collision_position, StandTile *arg1, f32 tank_orientation_angle, struct coord3d *arg3, struct coord3d *arg4);
s32 bondviewCallTankCollisionStatus(struct coord3d *arg0, struct StandTile *arg1, f32 arg2);
s32 sub_GAME_7F07CDD4(struct coord3d *arg0, f32 arg1, struct StandTile **arg2);
s32 bondviewTryMoveToStan(struct coord3d *arg0, struct StandTile **stan);
s32 bondviewTestLineUnobstructed(StandTile **pTile, f32 p_x, f32 p_z, f32 dest_x, f32 dest_z, s32 objFlags, struct coord3d *coord_p, struct coord3d *coord_dest);

s32 bondviewTryFractionMovePlayerCollision(struct coord3d *next_pos, struct coord3d *collision1_pt0, struct coord3d *collision1_pt1, struct coord3d *collision2_pt0, struct coord3d *collision2_pt1);
s32 bondviewTryEdgeMovePlayerCollision(struct coord3d *prior_next_pos, struct coord3d *collision_pt0, struct coord3d *collision_pt1);
s32 bondviewTryEndHopPlayerCollision(struct coord3d *prior_next_pos, struct coord3d *collision_pt0, struct coord3d *collision_pt1);
void bondviewApplyVertaTheta(void);

f32 bheadGetBreathingValue(void);
void bondviewMoveAnimationTick(f32 speed, f32 speedforwards, f32 speedsideways);
void bondviewCalcUpdatePlayerCollision(struct coord3d *offset, s32 allow_scoot);
f32 bondviewPauseAngleRelated(s32 arg0);
void sub_GAME_7F07E010(f32 arg0);
void sub_GAME_7F07E03C(f32 arg0);
s32 sub_GAME_7F07E068(void);
f32 sub_GAME_7F080228(f32 arg0);
void currentPlayerSetSwayTarget(s32 value);
void currentPlayerAdjustCrouchPos(s32 value);
void bondviewUpdateSpeedSideways(s32 arg0);
void bondviewUpdateSpeedForwards(s32 arg0);
void bondviewFrozenCameraTick(u16 buttons, u16 oldbuttons, struct coord3d *pos, struct coord3d *pos2, struct coord3d *offset, struct StandTile **stan, struct coord3d *arg6);
void sub_GAME_7F07B2A0(s32, f32, struct coord3d *, struct coord3d *);

// end forward declarations

void nullsub_75(void)
{
    return;
}

void currentPlayerSetScreenSize(f32 width, f32 height)
{
    g_CurrentPlayer->c_screenwidth = width;
    g_CurrentPlayer->c_screenheight = height;
    g_CurrentPlayer->c_halfwidth = width * 0.5f;
    g_CurrentPlayer->c_halfheight = height * 0.5f;
}

void currentPlayerSetScreenPosition(f32 left, f32 top)
{
    g_CurrentPlayer->c_screenleft = left;
    g_CurrentPlayer->c_screentop = top;
}

void currentPlayerSetPerspective(f32 near, f32 fovy, f32 aspect)
{
    g_CurrentPlayer->c_perspnear = near;
    g_CurrentPlayer->c_perspfovy = fovy;
    g_CurrentPlayer->c_perspaspect = aspect;
}

void currentPlayerSetCameraScale(void)
{
	f32 fVar4;
	f32 tmp;
	f32 fVar5;
	f32 fVar2;

	g_CurrentPlayer->c_scaley = sinf(mDegToHalfRad(g_CurrentPlayer->c_perspfovy)) / (cosf(mDegToHalfRad(g_CurrentPlayer->c_perspfovy)) * g_CurrentPlayer->c_halfheight);
	g_CurrentPlayer->c_scalex = (g_CurrentPlayer->c_scaley * g_CurrentPlayer->c_perspaspect * g_CurrentPlayer->c_halfheight) / g_CurrentPlayer->c_halfwidth;

	g_CurrentPlayer->c_recipscalex = 1.0f / g_CurrentPlayer->c_scalex;
	g_CurrentPlayer->c_recipscaley = 1.0f / g_CurrentPlayer->c_scaley;

    g_CurrentPlayer->c_scalelod = g_CurrentPlayer->c_scaley;
    g_CurrentPlayer->c_scalelod60 = sinf(DegToRad(30)) / (cosf(DegToRad(30)) * 120.0f);
	g_CurrentPlayer->c_lodscalez = g_CurrentPlayer->c_scalelod / g_CurrentPlayer->c_scalelod60;
	tmp = (g_CurrentPlayer->c_lodscalez * M_U16_MAX_VALUE_F);

	if (tmp > M_U32_MAX_VALUE_F) {
		g_CurrentPlayer->c_lodscalezu32 = -1;
	} else {
		g_CurrentPlayer->c_lodscalezu32 = tmp;
	}

	fVar2 = g_CurrentPlayer->c_halfheight * g_CurrentPlayer->c_scaley;
	fVar4 = 1.0f / sqrtf(fVar2 * fVar2 + 1.0f);
	g_CurrentPlayer->c_cameratopnorm.x = 0;
	g_CurrentPlayer->c_cameratopnorm.y = fVar4;
	g_CurrentPlayer->c_cameratopnorm.z = fVar2 * fVar4;

	fVar5 = -g_CurrentPlayer->c_halfwidth * g_CurrentPlayer->c_scalex;
	fVar4 = 1.0f / sqrtf(fVar5 * fVar5 + 1.0f);
	g_CurrentPlayer->c_cameraleftnorm.x = -fVar4;
	g_CurrentPlayer->c_cameraleftnorm.y = 0;
	g_CurrentPlayer->c_cameraleftnorm.z = -fVar5 * fVar4;
}

void sub_GAME_7F077EEC(coord2d *in, coord3d *out, f32 value) {
    f32 norm;
    f32 x;
    f32 y;
    f32 z;
    y = (g_CurrentPlayer->c_halfheight - (in->y - g_CurrentPlayer->c_screentop)) * g_CurrentPlayer->c_scaley;
    x = ((in->x - g_CurrentPlayer->c_screenleft) - g_CurrentPlayer->c_halfwidth) * g_CurrentPlayer->c_scalex;
    z = -1.0f;
    norm = value / sqrtf((x * x) + (y * y) + (z * z));
    out->x = (x * norm);
    out->y = (y * norm);
    out->z = (-1.0f * norm);
}

void sub_GAME_7F077FB4(coord3d *in, f32 value, coord3d *out) {
    out->y = ((in->y * value) * g_CurrentPlayer->c_scaley);
    out->x = ((in->x * value) * g_CurrentPlayer->c_scalex);
}

void sub_GAME_7F077FF4(coord3d *in, coord3d *out) {
    f32 inv_z = (1.0f / in->z);
    out->y = (in->y * inv_z * g_CurrentPlayer->c_recipscaley) + (g_CurrentPlayer->c_screentop + g_CurrentPlayer->c_halfheight);
    out->x = (g_CurrentPlayer->c_screenleft + g_CurrentPlayer->c_halfwidth) - (in->x * inv_z * g_CurrentPlayer->c_recipscalex);
}

void sub_GAME_7F078060(coord3d *in, coord3d *out)
{
	f32 inv_z;

	if (in->z == 0.0f) {
		inv_z = -100000000000000000000.0f;
	} else {
		inv_z = 1.0f / in->z;
	}

	out->y = in->y * inv_z * g_CurrentPlayer->c_recipscaley + (g_CurrentPlayer->c_screentop + g_CurrentPlayer->c_halfheight);
	out->x = (g_CurrentPlayer->c_screenleft + g_CurrentPlayer->c_halfwidth) - in->x * inv_z * g_CurrentPlayer->c_recipscalex;
}

void sub_GAME_7F0780F0(coord3d *in, f32 divisor, coord3d *out)
{
	out->y = in->y * (1.0f / divisor) * g_CurrentPlayer->c_recipscaley;
	out->x = in->x * (1.0f / divisor) * g_CurrentPlayer->c_recipscalex;
}

void sub_GAME_7F078140(coord3d *in, coord3d *out, f32 value1, f32 angle, f32 value2) {
    f32 var1;
    f32 x;
    f32 y;
    f32 z;
    f32 var2 = sinf(mDegToHalfRad(angle)) / (cosf(mDegToHalfRad(angle)) * g_CurrentPlayer->c_halfheight);
    f32 var3 = (var2 * value2 * g_CurrentPlayer->c_halfheight) / g_CurrentPlayer->c_halfwidth;
    y = (g_CurrentPlayer->c_halfheight - (in->y - g_CurrentPlayer->c_screentop)) * var2;
    x = ((in->x - g_CurrentPlayer->c_screenleft) - g_CurrentPlayer->c_halfwidth) * var3;
    z = -1.0f;
    var1 = value1 / sqrtf((x * x) + (y * y) + (z * z));
    out->x = (x * var1);
    out->y = (y * var1);
    out->z = (-1.0f * var1);
}

/**
 * Unreferenced.
 * 
 * Address 0x7F078258.
 */
void sub_GAME_7F078258(coord3d *in, coord3d *out, f32 angle, f32 value)
{
    f32 var1 = (cosf(mDegToHalfRad(angle)) * g_CurrentPlayer->c_halfheight) / (sinf(mDegToHalfRad(angle)) * in->f[2]);
    f32 var2 = (var1 * g_CurrentPlayer->c_halfwidth) / (value * g_CurrentPlayer->c_halfheight);

    out->f[1] = (in->f[1] * var1) + (g_CurrentPlayer->c_screentop + g_CurrentPlayer->c_halfheight);
    out->f[0] = (g_CurrentPlayer->c_screenleft + g_CurrentPlayer->c_halfwidth) - (in->f[0] * var2);
}

void currentPlayerSetMatrix10C4(Mtx *matrix) {
    g_CurrentPlayer->field_10C4 = matrix;
}

Mtx *currentPlayerGetMatrix10C4(void) {
    return g_CurrentPlayer->field_10C4;
}

void currentPlayerSetMatrix10C8(Mtx *matrix) {
    g_CurrentPlayer->field_10C8 = matrix;
}

Mtx *currentPlayerGetMatrix10C8(void) {
    return g_CurrentPlayer->field_10C8;
}

void currentPlayerSetProjectionMatrix(Mtx *matrix) {
    g_CurrentPlayer->projmatrix = matrix;
}

Mtx *currentPlayerGetProjectionMatrix(void) {
    return g_CurrentPlayer->projmatrix;
}

void set_BONDdata_field_10E0(s32 arg0) {
    g_CurrentPlayer->field_10E0 = arg0;
}

s32 get_BONDdata_field_10E0(void) {
    return g_CurrentPlayer->field_10E0;
}

void *currentPlayerSetMatrix10CC(Mtxf *matrix) {
    g_CurrentPlayer->field_10E8 = g_CurrentPlayer->field_10CC;
    g_CurrentPlayer->field_10CC = matrix;
}

Mtxf *camGetWorldToScreenMtxf(void) {
    return g_CurrentPlayer->field_10CC;
}

void currentPlayerSetProjectionMatrixF(Mtxf *matrix) {
    g_CurrentPlayer->projmatrixf = matrix;
}

Mtxf *currentPlayerGetProjectionMatrixF(void) {
    return g_CurrentPlayer->projmatrixf;
}

Mtxf *currentPlayerGetMatrix10E8(void) {
    return g_CurrentPlayer->field_10E8;
}

void sub_GAME_7F078404(s32 arg0) {
    g_CurrentPlayer->field_10D0 = arg0;
}

s32 sub_GAME_7F078414(void) {
    return g_CurrentPlayer->field_10D0;
}

void currentPlayerSetMatrix10D4(Mtxf *matrix) {
    g_CurrentPlayer->field_10EC = g_CurrentPlayer->field_10D4;
    g_CurrentPlayer->field_10D4 = matrix;
}

Mtxf *currentPlayerGetMatrix10D4(void) {
    return g_CurrentPlayer->field_10D4;
}

Mtxf *currentPlayerGetMatrix10EC(void) {
    return g_CurrentPlayer->field_10EC;
}

void sub_GAME_7F078464(s32 arg0) {
    g_CurrentPlayer->field_10E4 = arg0;
}

s32 sub_GAME_7F078474(void)
{
    return g_CurrentPlayer->field_10E4;
}

f32 getPlayer_c_lodscalez(void)
{
    return g_CurrentPlayer->c_lodscalez;
}

u32 getPlayer_c_lodscalezu32(void)
{
    return g_CurrentPlayer->c_lodscalezu32;
}

f32 getPlayer_c_screenwidth(void)
{
    return g_CurrentPlayer->c_screenwidth;
}

f32 getPlayer_c_screenheight(void)
{
    return g_CurrentPlayer->c_screenheight;
}

f32 getPlayer_c_screenleft(void)
{
    return g_CurrentPlayer->c_screenleft;
}

f32 getPlayer_c_screentop(void)
{
    return g_CurrentPlayer->c_screentop;
}

f32 getPlayer_c_perspfovy(void)
{
    return g_CurrentPlayer->c_perspfovy;
}

f32 getPlayer_c_perspaspect(void)
{
    return g_CurrentPlayer->c_perspaspect;
}

void getPlayer_c_cameratopnorm(coord3d *out)
{
    out->x = (g_CurrentPlayer->c_cameratopnorm).x;
    out->y = (g_CurrentPlayer->c_cameratopnorm).y;
    out->z = (g_CurrentPlayer->c_cameratopnorm).z;
}

void getPlayer_c_cameratopnorm_inverted_y(coord3d *out)
{
    out->x = (g_CurrentPlayer->c_cameratopnorm).x;
    out->y = -(g_CurrentPlayer->c_cameratopnorm).y;
    out->z = (g_CurrentPlayer->c_cameratopnorm).z;
}

void getPlayer_c_cameraleftnorm(coord3d *out)
{
    out->x = (g_CurrentPlayer->c_cameraleftnorm).x;
    out->y = (g_CurrentPlayer->c_cameraleftnorm).y;
    out->z = (g_CurrentPlayer->c_cameraleftnorm).z;
}

void getPlayer_c_cameraleftnorm_inverted_x(coord3d *out)
{
    out->x = -(g_CurrentPlayer->c_cameraleftnorm).x;
    out->y = (g_CurrentPlayer->c_cameraleftnorm).y;
    out->z = (g_CurrentPlayer->c_cameraleftnorm).z;
}

f32 getPlayer_c_perspnear(void)
{
    return g_CurrentPlayer->c_perspnear;
}

void sub_GAME_7F0785DC()
{
    f32 h_div;
    f32 h2;
    f32 h;
    f32 nh_div;
    f32 nh2_div;
    f32 h2_div;

    h = g_CurrentPlayer->c_halfheight * g_CurrentPlayer->c_scaley;
    h_div = 1.0f / sqrtf((h * h) + 1.0f);
    h *= h_div;
    nh_div = -h_div;

    flt_CODE_bss_80079940.x = (-nh_div * g_CurrentPlayer->field_10D4->m[1][0]) + (h * g_CurrentPlayer->field_10D4->m[2][0]);
    flt_CODE_bss_80079940.y = (-nh_div * g_CurrentPlayer->field_10D4->m[1][1]) + (h * g_CurrentPlayer->field_10D4->m[2][1]);
    flt_CODE_bss_80079940.z = (-nh_div * g_CurrentPlayer->field_10D4->m[1][2]) + (h * g_CurrentPlayer->field_10D4->m[2][2]);

    flt_CODE_bss_8007994C = (flt_CODE_bss_80079940.x * g_CurrentPlayer->field_10D4->m[3][0])
                          + (flt_CODE_bss_80079940.y * g_CurrentPlayer->field_10D4->m[3][1])
                          + (flt_CODE_bss_80079940.z * g_CurrentPlayer->field_10D4->m[3][2]);

    flt_CODE_bss_80079950.x = (nh_div * g_CurrentPlayer->field_10D4->m[1][0]) + (h * g_CurrentPlayer->field_10D4->m[2][0]);
    flt_CODE_bss_80079950.y = (nh_div * g_CurrentPlayer->field_10D4->m[1][1]) + (h * g_CurrentPlayer->field_10D4->m[2][1]);
    flt_CODE_bss_80079950.z = (nh_div * g_CurrentPlayer->field_10D4->m[1][2]) + (h * g_CurrentPlayer->field_10D4->m[2][2]);

    flt_CODE_bss_8007995C = (flt_CODE_bss_80079950.x * g_CurrentPlayer->field_10D4->m[3][0])
                          + (flt_CODE_bss_80079950.y * g_CurrentPlayer->field_10D4->m[3][1])
                          + (flt_CODE_bss_80079950.z * g_CurrentPlayer->field_10D4->m[3][2]);

    h2 = (-g_CurrentPlayer->c_halfwidth) * g_CurrentPlayer->c_scalex;
    h2_div = 1.0f / sqrtf((h2 * h2) + 1.0f);
    h2 *= h2_div;
    nh2_div = -h2_div;

    flt_CODE_bss_80079960.x = (nh2_div * g_CurrentPlayer->field_10D4->m[0][0]) - (h2 * g_CurrentPlayer->field_10D4->m[2][0]);
    flt_CODE_bss_80079960.y = (nh2_div * g_CurrentPlayer->field_10D4->m[0][1]) - (h2 * g_CurrentPlayer->field_10D4->m[2][1]);
    flt_CODE_bss_80079960.z = (nh2_div * g_CurrentPlayer->field_10D4->m[0][2]) - (h2 * g_CurrentPlayer->field_10D4->m[2][2]);

    flt_CODE_bss_8007996C = (flt_CODE_bss_80079960.x * g_CurrentPlayer->field_10D4->m[3][0])
                          + (flt_CODE_bss_80079960.y * g_CurrentPlayer->field_10D4->m[3][1])
                          + (flt_CODE_bss_80079960.z * g_CurrentPlayer->field_10D4->m[3][2]);

    flt_CODE_bss_80079970.x = (-nh2_div * g_CurrentPlayer->field_10D4->m[0][0]) - (h2 * g_CurrentPlayer->field_10D4->m[2][0]);
    flt_CODE_bss_80079970.y = (-nh2_div * g_CurrentPlayer->field_10D4->m[0][1]) - (h2 * g_CurrentPlayer->field_10D4->m[2][1]);
    flt_CODE_bss_80079970.z = (-nh2_div * g_CurrentPlayer->field_10D4->m[0][2]) - (h2 * g_CurrentPlayer->field_10D4->m[2][2]);

    flt_CODE_bss_8007997C = (flt_CODE_bss_80079970.x * g_CurrentPlayer->field_10D4->m[3][0])
                          + (flt_CODE_bss_80079970.y * g_CurrentPlayer->field_10D4->m[3][1])
                          + (flt_CODE_bss_80079970.z * g_CurrentPlayer->field_10D4->m[3][2]);

    flt_CODE_bss_80079980 = (g_CurrentPlayer->field_10D4->m[2][0] * g_CurrentPlayer->field_10D4->m[3][0])
                          + (g_CurrentPlayer->field_10D4->m[2][1] * g_CurrentPlayer->field_10D4->m[3][1])
                          + (g_CurrentPlayer->field_10D4->m[2][2] * g_CurrentPlayer->field_10D4->m[3][2]);
}

void sub_GAME_7F078950(coord3d *arg0, f32 *arg1) {
    arg0->x = flt_CODE_bss_80079940.x;
    arg0->y = flt_CODE_bss_80079940.y;
    arg0->z = flt_CODE_bss_80079940.z;
    *arg1 = flt_CODE_bss_8007994C;
}

void sub_GAME_7F078980(coord3d *arg0, f32 *arg1) {
    arg0->x = flt_CODE_bss_80079950.x;
    arg0->y = flt_CODE_bss_80079950.y;
    arg0->z = flt_CODE_bss_80079950.z;
    *arg1 = flt_CODE_bss_8007995C;
}

void sub_GAME_7F0789B0(coord3d *arg0, f32 *arg1) {
    arg0->x = flt_CODE_bss_80079960.x;
    arg0->y = flt_CODE_bss_80079960.y;
    arg0->z = flt_CODE_bss_80079960.z;
    *arg1 = flt_CODE_bss_8007996C;
}

void sub_GAME_7F0789E0(coord3d *arg0, f32 *arg1) {
    arg0->x = flt_CODE_bss_80079970.x;
    arg0->y = flt_CODE_bss_80079970.y;
    arg0->z = flt_CODE_bss_80079970.z;
    *arg1 = flt_CODE_bss_8007997C;
}

void sub_GAME_7F078A10(coord3d *arg0, f32 *arg1) {
    arg0->x = g_CurrentPlayer->field_10D4->m[2][0];
    arg0->y = g_CurrentPlayer->field_10D4->m[2][1];
    arg0->z = g_CurrentPlayer->field_10D4->m[2][2];
    *arg1 = flt_CODE_bss_80079980;
}

/**
 * Takes dot product of some vectors and compares each to an associated scalar value.
 * Returns 0 if the dot product exceeds the scalar amount, 1 otherwise.
 * 
 * @param vec_scale: Applies dot product of this vector against g_CurrentPlayer->field_10D4
 * and four coords starting at flt_CODE_bss_80079960.
 * 
 * @param norm_scale: Value added to flt_CODE_bss_80079980 to compare g_CurrentPlayer->field_10D4,
 * and the four values starting at flt_CODE_bss_8007996C.
 * 
 * Address 0x7F078A58.
 */
s32 sub_GAME_7F078A58(coord3d *vec_scale, f32 norm_scale)
{
    if (flt_CODE_bss_80079980 + norm_scale < (g_CurrentPlayer->field_10D4->m[2][0] * vec_scale->f[0]) + (g_CurrentPlayer->field_10D4->m[2][1] * vec_scale->f[1]) + (g_CurrentPlayer->field_10D4->m[2][2] * vec_scale->f[2]))
    {
        return 0;
    }

    if (flt_CODE_bss_8007996C + norm_scale < (flt_CODE_bss_80079960.f[0] * vec_scale->f[0]) + (flt_CODE_bss_80079960.f[1] * vec_scale->f[1]) + (flt_CODE_bss_80079960.f[2] * vec_scale->f[2]))
    {
        return 0;
    }

    if (flt_CODE_bss_8007997C + norm_scale < (flt_CODE_bss_80079970.f[0] * vec_scale->f[0]) + (flt_CODE_bss_80079970.f[1] * vec_scale->f[1]) + (flt_CODE_bss_80079970.f[2] * vec_scale->f[2]))
    {
        return 0;
    }

    if (flt_CODE_bss_8007994C + norm_scale < (flt_CODE_bss_80079940.f[0] * vec_scale->f[0]) + (flt_CODE_bss_80079940.f[1] * vec_scale->f[1]) + (flt_CODE_bss_80079940.f[2] * vec_scale->f[2]))
    {
        return 0;
    }

    if (flt_CODE_bss_8007995C + norm_scale < (flt_CODE_bss_80079950.f[0] * vec_scale->f[0]) + (flt_CODE_bss_80079950.f[1] * vec_scale->f[1]) + (flt_CODE_bss_80079950.f[2] * vec_scale->f[2]))
    {
        return 0;
    }

    return 1;
}


bool camIsPosInScreenBox(coord3d *pos, f32 arg1, bbox2d *arg2)
{
    coord3d sp74;
    f32 sp70;
    coord3d sp64;
    f32 sp60;
    coord3d sp54;
    f32 sp50;
    coord3d sp44;
    f32 sp40;
    f32 sp3c;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2c;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1c;
    f32 sp18;

    if (flt_CODE_bss_80079980 + arg1 < g_CurrentPlayer->field_10D4->m[2][0] * pos->f[0] + g_CurrentPlayer->field_10D4->m[2][1] * pos->f[1] + g_CurrentPlayer->field_10D4->m[2][2] * pos->f[2])
    {
        return FALSE;
    }

    sp38 = (arg2->min.x - g_CurrentPlayer->c_screenleft - g_CurrentPlayer->c_halfwidth) * g_CurrentPlayer->c_scalex;

    sp3c = 1.0f / sqrtf(sp38 * sp38 + 1.0f);
    sp38 *= sp3c;
    sp24 = -sp3c;

    sp54.f[0] = sp24 * g_CurrentPlayer->field_10D4->m[0][0] - sp38 * g_CurrentPlayer->field_10D4->m[2][0];
    sp54.f[1] = sp24 * g_CurrentPlayer->field_10D4->m[0][1] - sp38 * g_CurrentPlayer->field_10D4->m[2][1];
    sp54.f[2] = sp24 * g_CurrentPlayer->field_10D4->m[0][2] - sp38 * g_CurrentPlayer->field_10D4->m[2][2];

    sp50 = sp54.f[0] * g_CurrentPlayer->field_10D4->m[3][0] + sp54.f[1] * g_CurrentPlayer->field_10D4->m[3][1] + sp54.f[2] * g_CurrentPlayer->field_10D4->m[3][2];

    if (sp50 + arg1 < sp54.f[0] * pos->f[0] + sp54.f[1] * pos->f[1] + sp54.f[2] * pos->f[2])
    {
        return FALSE;
    }

    sp38 = -(arg2->max.x - g_CurrentPlayer->c_screenleft - g_CurrentPlayer->c_halfwidth) * g_CurrentPlayer->c_scalex;
    sp30 = 1.0f / sqrtf(sp38 * sp38 + 1.0f);
    sp38 *= sp30;
    sp20 = -sp30;

    sp44.f[0] = -sp20 * g_CurrentPlayer->field_10D4->m[0][0] - sp38 * g_CurrentPlayer->field_10D4->m[2][0];
    sp44.f[1] = -sp20 * g_CurrentPlayer->field_10D4->m[0][1] - sp38 * g_CurrentPlayer->field_10D4->m[2][1];
    sp44.f[2] = -sp20 * g_CurrentPlayer->field_10D4->m[0][2] - sp38 * g_CurrentPlayer->field_10D4->m[2][2];

    sp40 = sp44.f[0] * g_CurrentPlayer->field_10D4->m[3][0] + sp44.f[1] * g_CurrentPlayer->field_10D4->m[3][1] + sp44.f[2] * g_CurrentPlayer->field_10D4->m[3][2];

    if (sp40 + arg1 < sp44.f[0] * pos->f[0] + sp44.f[1] * pos->f[1] + sp44.f[2] * pos->f[2])
    {
        return FALSE;
    }

    sp34 = (g_CurrentPlayer->c_halfheight - (arg2->min.y - g_CurrentPlayer->c_screentop)) * g_CurrentPlayer->c_scaley;
    sp2c = 1.0f / sqrtf(sp34 * sp34 + 1.0f);
    sp34 *= sp2c;
    sp1c = -sp2c;

    sp74.f[0] = -sp1c * g_CurrentPlayer->field_10D4->m[1][0] + sp34 * g_CurrentPlayer->field_10D4->m[2][0];
    sp74.f[1] = -sp1c * g_CurrentPlayer->field_10D4->m[1][1] + sp34 * g_CurrentPlayer->field_10D4->m[2][1];
    sp74.f[2] = -sp1c * g_CurrentPlayer->field_10D4->m[1][2] + sp34 * g_CurrentPlayer->field_10D4->m[2][2];

    sp70 = sp74.f[0] * g_CurrentPlayer->field_10D4->m[3][0] + sp74.f[1] * g_CurrentPlayer->field_10D4->m[3][1] + sp74.f[2] * g_CurrentPlayer->field_10D4->m[3][2];

    if (sp70 + arg1 < sp74.f[0] * pos->f[0] + sp74.f[1] * pos->f[1] + sp74.f[2] * pos->f[2])
    {
        return FALSE;
    }

    sp34 = -(g_CurrentPlayer->c_halfheight - (arg2->max.y - g_CurrentPlayer->c_screentop)) * g_CurrentPlayer->c_scaley;
    sp28 = 1.0f / sqrtf(sp34 * sp34 + 1.0f);
    sp34 *= sp28;
    sp18 = -sp28;

    sp64.f[0] = sp18 * g_CurrentPlayer->field_10D4->m[1][0] + sp34 * g_CurrentPlayer->field_10D4->m[2][0];
    sp64.f[1] = sp18 * g_CurrentPlayer->field_10D4->m[1][1] + sp34 * g_CurrentPlayer->field_10D4->m[2][1];
    sp64.f[2] = sp18 * g_CurrentPlayer->field_10D4->m[1][2] + sp34 * g_CurrentPlayer->field_10D4->m[2][2];

    sp60 = sp64.f[0] * g_CurrentPlayer->field_10D4->m[3][0] + sp64.f[1] * g_CurrentPlayer->field_10D4->m[3][1] + sp64.f[2] * g_CurrentPlayer->field_10D4->m[3][2];

    if (sp60 + arg1 < sp64.f[0] * pos->f[0] + sp64.f[1] * pos->f[1] + sp64.f[2] * pos->f[2])
    {
        return FALSE;
    }

    return TRUE;
}


s32 bondviewGetRandomSpawnPadIndex(void)
{
    PadRecord *pad;
    PropRecord *player_prop;
    s32 player_count;
    f32 diff_x;
    s32 pad_index;
    s32 player_num;
    s32 player_index;
    s32 enemy_nearby;
    s32 attempt_num;
    f32 dist;
    f32 diff_z;

    // set up initial values
    player_num = get_cur_playernum();
    player_count = getPlayerCount();
    enemy_nearby = TRUE;

    // loop pads until no enemy is within 1000 units
    for (attempt_num = 0; enemy_nearby && (attempt_num < startpadcount);)
    {
        attempt_num++;
        enemy_nearby = FALSE;
        g_CurrentPlayer->field_29E0++;
        pad_index = ( g_CurrentPlayer->field_29E0) % (startpadcount);

        for (player_index = 0; player_index < player_count; player_index++)
        {
            // don't consider yourself as an enemy
            if (player_index == player_num) { continue; }

            // make sure the player prop is valid
            player_prop = g_playerPointers[player_index]->prop;
            if (player_prop == 0) { continue; }

            // find distance between enemy and this pad
            pad = g_Startpad[pad_index];
            diff_x = player_prop->pos.x - pad->pos.x;
            diff_z = player_prop->pos.z - pad->pos.z;
            dist = sqrtf((diff_x * diff_x) + (diff_z * diff_z));

            // if pad is within 1000, don't pick it
            if (dist < 1000) { enemy_nearby = TRUE; }
        }
    }

    do {  } while(0); // leftover debug code?

    // loop pads until no enemy is within 100 units
    for (; enemy_nearby && (attempt_num < startpadcount);)
    {
        attempt_num++;
        enemy_nearby = FALSE;
        g_CurrentPlayer->field_29E0++;
        pad_index = ((s32) g_CurrentPlayer->field_29E0) % ((s32) startpadcount);

        for (player_index = 0; player_index < player_count; player_index++)
        {
            // don't consider yourself as an enemy
            if (player_index == player_num) { continue; }

            // make sure the player prop is valid
            player_prop = g_playerPointers[player_index]->prop;
            if (player_prop == 0) { continue; }

            // find distance between enemy and this pad
            pad = g_Startpad[pad_index];
            diff_x = player_prop->pos.x - pad->pos.x;
            diff_z = player_prop->pos.z - pad->pos.z;
            dist = sqrtf((diff_x * diff_x) + (diff_z * diff_z));

            // if pad is within 100, don't pick it
            if (dist < 100.f) { enemy_nearby = TRUE; }
        }
    }

    // if we searched through all pads and failed to find a safe one, just pick one at random
    if (enemy_nearby)
    {
        pad_index = (randomGetNext() % (startpadcount));
    }

    return pad_index;
}


//file split per pd
void init_player_BONDdata(void)
{
    if (getPlayerCount() >= 2)
    {
        g_CurrentPlayer->controldef = get_player_control_style(get_cur_playernum());
        cur_player_set_control_type(get_player_control_style(get_cur_playernum()));
    }
    g_CurrentPlayer->current_model_pos.f[0] = 0.0f;
    g_CurrentPlayer->current_model_pos.f[1] = 0.0f;
    g_CurrentPlayer->current_model_pos.f[2] = 0.0f;
    g_CurrentPlayer->previous_model_pos.f[0] = 0.0f;
    g_CurrentPlayer->previous_model_pos.f[1] = 0.0f;
    g_CurrentPlayer->previous_model_pos.f[2] = 0.0f;
    g_CurrentPlayer->current_room_pos.f[0] = 0.0f;
    g_CurrentPlayer->current_room_pos.f[1] = 0.0f;
    g_CurrentPlayer->current_room_pos.f[2] = 0.0f;
    g_CurrentPlayer->unknown = 0;
    g_CurrentPlayer->pos.f[0] = 0.0f;
    g_CurrentPlayer->pos.f[1] = 0.0f;
    g_CurrentPlayer->pos.f[2] = 0.0f;
    g_CurrentPlayer->pos2.f[0] = 0.0f;
    g_CurrentPlayer->pos2.f[1] = 0.0f;
    g_CurrentPlayer->pos2.f[2] = 1.0f;
    g_CurrentPlayer->offset.f[0] = 0.0f;
    g_CurrentPlayer->offset.f[1] = 1.0f;
    g_CurrentPlayer->offset.f[2] = 0.0f;
    g_CurrentPlayer->pos3.f[0] = 0.0f;
    g_CurrentPlayer->pos3.f[1] = 0.0f;
    g_CurrentPlayer->pos3.f[2] = 0.0f;
    g_CurrentPlayer->room_pointer = 0;
    g_CurrentPlayer->field_3C4 = 0.0f;
    g_CurrentPlayer->field_3C8 = 0.0f;
    g_CurrentPlayer->field_3CC = 1.0f;
    g_CurrentPlayer->field_84 = 0.0f;
    g_CurrentPlayer->field_88 = 0.0f;
    g_CurrentPlayer->field_8C = 0;
    g_CurrentPlayer->vertical_bounce_adjust = 0.0f;
    g_CurrentPlayer->field_94 = 0;
    g_CurrentPlayer->field_98 = 0.0f;
    g_CurrentPlayer->swaytarget = 0.0f;
    g_CurrentPlayer->swayoffset0 = 0.0f;
    g_CurrentPlayer->swayoffset2 = 0.0f;
    g_CurrentPlayer->crouchpos = CROUCH_STAND;
    g_CurrentPlayer->autocrouchpos = CROUCH_STAND;
    g_CurrentPlayer->ducking_height_offset = 0.0f;
    g_CurrentPlayer->field_A4 = 0.0f;
    g_CurrentPlayer->field_AC = 1;
    g_CurrentPlayer->field_D0 = 0;
    g_CurrentPlayer->bonddead = 0;
    g_CurrentPlayer->bondhealth = 1.0f;
    g_CurrentPlayer->bondarmour = 0.0f;
    g_CurrentPlayer->oldhealth = 1.0f;
    g_CurrentPlayer->oldarmour = 0.0f;
    g_CurrentPlayer->apparenthealth = 1.0f;
    g_CurrentPlayer->apparentarmour = 0.0f;
    g_CurrentPlayer->damageshowtime = -1;
    g_CurrentPlayer->healthshowtime = -1;
    g_CurrentPlayer->watch_pause_time = 0;
    g_CurrentPlayer->field_1C4 = 0;
    g_CurrentPlayer->watch_animation_state = WATCH_ANIMATION_0x0;
    g_CurrentPlayer->outside_watch_menu = 1;
    g_CurrentPlayer->open_close_solo_watch_menu = 0;
    g_CurrentPlayer->field_1A0 = 0;
    g_CurrentPlayer->bondbreathing = 0.0f;
    g_CurrentPlayer->speedtheta = 0.0f;
    g_CurrentPlayer->vv_costheta = 1.0f;
    g_CurrentPlayer->vv_sintheta = 0.0f;
    g_CurrentPlayer->vv_verta = -4.0f;
    g_CurrentPlayer->vv_verta360 = (f32) g_CurrentPlayer->vv_verta;
    if (g_CurrentPlayer->vv_verta360 < 0.0f)
    {
        g_CurrentPlayer->vv_verta360 = (f32) (g_CurrentPlayer->vv_verta360 + 360.0f);
    }
    g_CurrentPlayer->speedverta = 0.0f;
    g_CurrentPlayer->vv_cosverta = 1.0f;
    g_CurrentPlayer->vv_sinverta = 0.0f;
    g_CurrentPlayer->speedsideways = 0.0f;
    g_CurrentPlayer->speedstrafe = 0.0f;
    g_CurrentPlayer->speedforwards = 0.0f;
    g_CurrentPlayer->field_2A4C = 0.0f;
    g_CurrentPlayer->speedboost = 1.0f;
    g_CurrentPlayer->speedmaxtime60 = 0;
    g_CurrentPlayer->bondshotspeed.x = 0.0f;
    g_CurrentPlayer->bondshotspeed.y = 0.0f;
    g_CurrentPlayer->bondshotspeed.z = 0.0f;
    g_CurrentPlayer->field_104 = 0;
    g_CurrentPlayer->field_108 = 0;
    g_CurrentPlayer->field_10C = 0;
    g_CurrentPlayer->movecentrerelease = 0;
    g_CurrentPlayer->lookaheadcentreenabled = 1;
    g_CurrentPlayer->automovecentreenabled = 1;
    g_CurrentPlayer->fastmovecentreenabled = 0;
    g_CurrentPlayer->automovecentre = 1;
    g_CurrentPlayer->insightaimmode = 0;
    g_CurrentPlayer->autoyaimenabled = 1;
    g_CurrentPlayer->autoaimy = 0.0f;
    g_CurrentPlayer->autoaim_target_y = NULL;
    g_CurrentPlayer->autoyaimtime60 = -1;
    g_CurrentPlayer->autoxaimenabled = 1;
    g_CurrentPlayer->autoaimx = 0.0f;
    g_CurrentPlayer->autoaim_target_x = NULL;
    g_CurrentPlayer->autoxaimtime60 = -1;
    g_CurrentPlayer->colourscreenred = 0xff;
    g_CurrentPlayer->colourscreengreen = 0xff;
    g_CurrentPlayer->colourscreenblue = 0xff;
    g_CurrentPlayer->colourscreenfrac = 0.0f;
    g_CurrentPlayer->colourfadetime60 = -1.0f;
    g_CurrentPlayer->colourfadetimemax60 = -1.0f;
    g_CurrentPlayer->colourfaderedold = 0xff;
    g_CurrentPlayer->colourfaderednew = 0xff;
    g_CurrentPlayer->colourfadegreenold = 0xff;
    g_CurrentPlayer->colourfadegreennew = 0xff;
    g_CurrentPlayer->colourfadeblueold = 0xff;
    g_CurrentPlayer->colourfadebluenew = 0xff;
    g_CurrentPlayer->colourfadefracold = 0.0f;
    g_CurrentPlayer->colourfadefracnew = 0.0f;
    g_CurrentPlayer->bondfadetime60 = -1.0f;
    g_CurrentPlayer->bondfadetimemax60 = -1.0f;
    g_CurrentPlayer->bondfadefracold = 0.0f;
    g_CurrentPlayer->bondfadefracnew = 0.0f;
    g_CurrentPlayer->field_42c = 2;
    g_CurrentPlayer->controldef = 0;
    g_CurrentPlayer->pause_starting_angle = 0.0f;
    g_CurrentPlayer->pause_related = 0.0f;
    g_CurrentPlayer->pause_target_angle = 0.0f;
    g_CurrentPlayer->field_210 = 0.0f;
    g_CurrentPlayer->field_214 = 0.0f;
    g_CurrentPlayer->field_218 = 0;
    g_CurrentPlayer->step_in_view_watch_animation = 0;
    g_CurrentPlayer->pause_animation_counter = 0.0f;
    g_CurrentPlayer->pausing_flag = 0;
    g_CurrentPlayer->buttons_pressed = (u16)0;
    g_CurrentPlayer->prev_buttons_pressed = (u16)0;
    g_CurrentPlayer->field_29C0 = 15.0f;
    g_CurrentPlayer->field_2A04 = -1;
    g_CurrentPlayer->field_2A08 = 0.0f;
    g_CurrentPlayer->field_2A0C = 0.0f;
    g_CurrentPlayer->field_2A6C = 0;
    g_CurrentPlayer->field_2A70 = 0;
}

//split per pd

void bondviewPlayerSpawnRelated(void)
{
    g_CurrentPlayer->field_29BC = ((g_playerPerm->player_perspective_height * 185.0f * (s32)1) - 10.0f);

    g_CurrentPlayer->field_29F8 = 0;
    g_CurrentPlayer->field_29F4 = getMissiontimer();
    g_CurrentPlayer->healthdisplaytime = 0;

    bondinvAddInvItem(ITEM_FIST);

    if (getPlayerCount() >= 2)
    {
        currentPlayerEquipWeaponWrapper(GUNLEFT, starting_left_weapon);
        currentPlayerEquipWeaponWrapper(GUNRIGHT, starting_right_weapon);

        if (g_CurrentPlayer->ptr_char_objectinstance == NULL)
        {
            solo_char_load();
        }
    }
}


void currentPlayerSetSwayTarget(s32 value) {
    g_CurrentPlayer->swaytarget = (value * 75.0f);
}

void currentPlayerAdjustCrouchPos(s32 value) {
    g_CurrentPlayer->crouchpos = g_CurrentPlayer->crouchpos + value;

    if (g_CurrentPlayer->crouchpos < CROUCH_SQUAT) {
        g_CurrentPlayer->crouchpos = CROUCH_SQUAT;
    } else if (g_CurrentPlayer->crouchpos > CROUCH_STAND) {
        g_CurrentPlayer->crouchpos = CROUCH_STAND;
    }
}

s32 currentPlayerGetCrouchPos(void) {
    return ((g_CurrentPlayer->crouchpos < g_CurrentPlayer->autocrouchpos) ? g_CurrentPlayer->crouchpos : g_CurrentPlayer->autocrouchpos);
}

s32 playerGetCrouchPos(s32 playernum) {
	return (g_playerPointers[playernum]->crouchpos < g_playerPointers[playernum]->autocrouchpos)
		? g_playerPointers[playernum]->crouchpos
		: g_playerPointers[playernum]->autocrouchpos;
}

void currentPlayerSetField00(s32 value) {
    g_CurrentPlayer->unknown = value;
}

/**
 * Compares current player position to parameters. If different, sets current
 * player position values to parameter values.
 * Also updates related room pointer.
 * 
 * Address 0x7F079A60.
 */
void bondviewSetCurrentPlayerPosition(coord3d *pos, coord3d *pos2, coord3d *offset, StandTile *tile, coord3d *stan_walk_start)
{
    StandTile *sp34;
    StandTile *sp30;

    if (
        (pos->f[0] != g_CurrentPlayer->pos.f[0])
        || (pos->f[1] != g_CurrentPlayer->pos.f[1])
        || (pos->f[2] != g_CurrentPlayer->pos.f[2])
        || (pos2->f[0] != g_CurrentPlayer->pos2.f[0])
        || (pos2->f[1] != g_CurrentPlayer->pos2.f[1])
        || (pos2->f[2] != g_CurrentPlayer->pos2.f[2])
        || (offset->f[0] != g_CurrentPlayer->offset.f[0])
        || (offset->f[1] != g_CurrentPlayer->offset.f[1])
        || (offset->f[2] != g_CurrentPlayer->offset.f[2])
        || (g_CurrentPlayer->room_pointer == NULL))
    {
        sp34 = tile;
        if (walkTilesBetweenPoints_NoCallback((StandTile **) &sp34, stan_walk_start->f[0], stan_walk_start->f[2], pos->f[0], pos->f[2]))
        {
            // @bug ...? This is either a bug or removed code, this function has no side effects.
            // Return value should used to check if point is safe for stan.
            stanTestPointWithinTileBoundsMaybe(sp34, pos->f[0], pos->f[2]);
            g_CurrentPlayer->room_pointer = sp34;
        }
        else
        {
            if (g_CurrentPlayer->room_pointer != NULL)
            {
                sp30 = g_CurrentPlayer->room_pointer;
                if (walkTilesBetweenPoints_NoCallback((StandTile **) &sp30, g_CurrentPlayer->pos.f[0], g_CurrentPlayer->pos.f[2], pos->f[0], pos->f[2]))
                {
                    g_CurrentPlayer->room_pointer = sp30;
                }
                else
                {
                    g_CurrentPlayer->room_pointer = sp34;
                }
            }
            else
            {
                g_CurrentPlayer->room_pointer = sp34;
            }
        }

        g_CurrentPlayer->pos.f[0] = pos->f[0];
        g_CurrentPlayer->pos.f[1] = pos->f[1];
        g_CurrentPlayer->pos.f[2] = pos->f[2];
        g_CurrentPlayer->pos2.f[0] = pos2->f[0];
        g_CurrentPlayer->pos2.f[1] = pos2->f[1];
        g_CurrentPlayer->pos2.f[2] = pos2->f[2];
        g_CurrentPlayer->offset.f[0] = offset->f[0];
        g_CurrentPlayer->offset.f[1] = offset->f[1];
        g_CurrentPlayer->offset.f[2] = offset->f[2];
        g_CurrentPlayer->pos3.f[0] = g_CurrentPlayer->pos.f[0];
        g_CurrentPlayer->pos3.f[2] = g_CurrentPlayer->pos.f[2];
        g_CurrentPlayer->pos3.f[1] = stanGetPositionYValue(g_CurrentPlayer->room_pointer, g_CurrentPlayer->pos.f[0], g_CurrentPlayer->pos.f[2]);
    }
}





#ifdef NONMATCHING
/*
            if ((g_CurrentPlayer->gunmemused[0] != 0) && (g_CurrentPlayer->gunmemtype[0] != 0)) {
                assertPrint_8291E690
                          (".\\ported\\bondview.cpp",0x342,
                           "Assertion failed: g_CurrentPlayer->gunmemused[GUNRIGHT]==0 || g_CurrentPlayer->gunmemtype[GUNRIGHT]==0"
                          );
            }
            if ((g_CurrentPlayer->gunmemused[1] != 0) && (g_CurrentPlayer->gunmemtype[1] != 0)) {
                assertPrint_8291E690
                          (".\\ported\\bondview.cpp",0x343,
                           "Assertion failed: g_CurrentPlayer->gunmemused[GUNLEFT]==0 || g_CurrentPlayer->gunmemtype[GUNLEFT]==0"
                          );
            }
//*/
#define ALIGN64_V3(val) (((val) | 0x3f) ^ 0x3f)
void solo_char_load(void)
{
    f32 hRot;
    ModelFileHeader *pBody;
    ModelFileHeader *pHead;
    ModelFileHeader *p_leftHeader;
    ModelFileHeader *bodyBuffer;
    ModelFileHeader *headBuffer;
    s32 totalsize;
    s32 bodyBufSize;
    s32 headBufSize;
    WeaponObjRecord *p_rightHeader;
    //? sp54;
    s32 rhandweapID;
    s32 body;
    s32 head;
    Model *model;
    s32 numRecords;
    ChrModelFileRecord *p_modelEntry;                       /* compiler-managed */
    ChrModelFileRecord *p_bodyEntry;
    ChrModelFileRecord *p_headEntry;
    ChrRecord *curChr;
    ModelFileHeader *p_headHeader;
    ModelFileHeader *p_headEntryHeader;
    ModelFileHeader *p_rhandItemHeader;
    ModelFileHeader *p_bodyEntryHeader;
    ModelFileHeader *p_bodyHeader;
    ModelFileHeader *p_lhandItemHeader;
    s32 rhandPropID;
    s32 bodyalignedSizeRemainPlus0x5F;
    s32 bufferSizeRemain;
    s32 folderBond;
    //s32 numRecords;
    s32 cuffId;
    hRot = get_curplay_horizontal_rotation_in_degrees();
    curChr = g_CurrentPlayer->prop->chr;
    if (curChr == NULL)
    {
        bodyBuffer = getPlayerWeaponBufferForHand(GUNRIGHT);
        headBuffer = getPlayerWeaponBufferForHand(GUNLEFT);
        totalsize = 0;
        bodyBufSize = getSizeBufferWeaponInHand(GUNRIGHT);
        headBufSize = getSizeBufferWeaponInHand(GUNLEFT);
        //M2C_MEMCPY_ALIGNED(&sp54, &dummy_08_pp7_obj, 0x84);
        //*(&sp54 + 0x84) = *(&dummy_08_pp7_obj + 0x84);
        rhandweapID = get_item_in_hand_or_watch_menu(GUNRIGHT);
        body = BODY_Formal_Wear;
        head = HEAD_Male_Brosnan_Default;
        model = NULL;
        sub_GAME_7F07DE64(g_CurrentPlayer);
        if (getPlayerCount() == 1)
        {
            folderBond = getSelectedFolderBond();
            cuffId = g_CurrentPlayer->bondtype;
            switch (cuffId)                        /* switch 1 */
            {
            case CUFF_BOILER:                                 /* switch 1 */
                body = BODY_Special_Operations_Uniform; break;
            case CUFF_JUNGLE:                                 /* switch 1 */
                body = BODY_Jungle_Fatigues; break;
            case CUFF_SNOW:                                 /* switch 1 */
                body = BODY_Parka; break;
            case CUFF_BROSNAN:                                 /* switch 1 */
                body = BODY_Brosnan_Tuxedo; break;
            case CUFF_CONNERY:                                 /* switch 1 */
                body = BODY_Brosnan_Tuxedo; break;
            case CUFF_DALTON:                                 /* switch 1 */
                body = BODY_Brosnan_Tuxedo; break;
            case CUFF_MOORE:                                 /* switch 1 */
                body = BODY_Brosnan_Tuxedo; break;
            case CUFF_FOLDER:                                 /* switch 1 */
                switch (folderBond)                  /* switch 3; irregular */
                {
                case 0:                             /* switch 3 */
                    body = BODY_Brosnan_Tuxedo; break;
                case 1:                             /* switch 3 */
                    body = BODY_Brosnan_Tuxedo; break;
                case 2:                             /* switch 3 */
                    body = BODY_Brosnan_Tuxedo; break;
                case 3:
                    body = BODY_Brosnan_Tuxedo; break;
                }
                break;
            }
            switch (folderBond)                      /* switch 4; irregular */
            {
            case 0:                                 /* switch 4 */
                switch (cuffId)                    /* switch 2 */
                {
                case CUFF_BOILER:                             /* switch 2 */
                    head = HEAD_Male_Brosnan_Boiler; break;
                case CUFF_JUNGLE:                             /* switch 2 */
                    head = HEAD_Male_Brosnan_Jungle; break;
                case CUFF_BROSNAN:                             /* switch 2 */
                    head = HEAD_Male_Brosnan_Tuxedo; break;
                case CUFF_CONNERY:                             /* switch 2 */
                    head = HEAD_Male_Brosnan_Tuxedo; break;
                case CUFF_DALTON:                             /* switch 2 */
                    head = HEAD_Male_Brosnan_Tuxedo; break;
                case CUFF_MOORE:                             /* switch 2 */
                    head = HEAD_Male_Brosnan_Tuxedo; break;
                case CUFF_FOLDER:                             /* switch 2 */
                    head = HEAD_Male_Brosnan_Tuxedo; break;
                }
                break;
            case 1:                                 /* switch 4 */
                head = HEAD_Male_Brosnan_Tuxedo; break;
            case 2:                                 /* switch 4 */
                head = HEAD_Male_Brosnan_Tuxedo; break;
            case 3:                                 /* switch 4 */
                head = HEAD_Male_Brosnan_Tuxedo; break;
            }
        }
        else
        {
            head = get_player_mp_char_head(get_cur_playernum());
            body = get_player_mp_char_body(get_cur_playernum());
        }
        if (g_CameraMode == CAMERAMODE_SWIRL)
        {
            rhandweapID = starting_right_weapon;
        }
        if (getPlayerCount() == 1)
        {
            remove_item_in_hand(GUNLEFT);
            remove_item_in_hand(GUNRIGHT);
            texInitPool(&texPool, headBuffer, headBufSize);
            p_bodyHeader = get_ptr_itemheader_in_hand(GUNRIGHT);

            p_bodyEntry = &c_item_entries[body];
            p_bodyEntryHeader = p_bodyEntry->header;

            pBody = p_bodyHeader;
            
            p_bodyHeader->RootNode = p_bodyEntryHeader->RootNode;
            p_bodyHeader->Skeleton = p_bodyEntryHeader->Skeleton;
            p_bodyHeader->Switches = p_bodyEntryHeader->Switches;
            p_bodyHeader->unkC = p_bodyEntryHeader->unkC;
            p_bodyHeader->BoundingVolumeRadius = p_bodyEntryHeader->BoundingVolumeRadius;
            p_bodyHeader->unk14 = p_bodyEntryHeader->unk14;
            p_bodyHeader->Textures = p_bodyEntryHeader->Textures;
            p_bodyHeader->isLoaded = p_bodyEntryHeader->isLoaded;
            
            p_modelEntry = p_bodyEntry;
            load_object_fill_header(p_bodyHeader, p_bodyEntry->filename, bodyBuffer, bodyBufSize, &texPool);

            p_headEntry = &c_item_entries[head];
            p_headEntryHeader = p_headEntry->header;

            bufferSizeRemain = ALIGN64_V3(get_pc_buffer_remaining_value(p_modelEntry->filename) + 0x3F);
            p_headHeader = bodyBuffer + bufferSizeRemain;
            bodyalignedSizeRemainPlus0x5F = ALIGN64_V3(bufferSizeRemain + 0x5F);

            p_headHeader->RootNode = p_headEntryHeader->RootNode;
            p_headHeader->Skeleton = p_headEntryHeader->Skeleton;
            p_headHeader->Switches = p_headEntryHeader->Switches;
            p_headHeader->unkC = p_headEntryHeader->unkC;
            p_headHeader->BoundingVolumeRadius = p_headEntryHeader->BoundingVolumeRadius;
            p_headHeader->unk14 = p_headEntryHeader->unk14;
            p_headHeader->Textures = p_headEntryHeader->Textures;
            p_headHeader->isLoaded = p_headEntryHeader->isLoaded;
            
            totalsize = bodyalignedSizeRemainPlus0x5F;
            pHead = p_headHeader;
            p_modelEntry = p_headEntry;
            load_object_fill_header(p_headHeader, p_headEntry->filename, bodyBuffer + bodyalignedSizeRemainPlus0x5F, bodyBufSize - bodyalignedSizeRemainPlus0x5F, &texPool);

            bufferSizeRemain = ALIGN64_V3(get_pc_buffer_remaining_value(p_modelEntry->filename) + totalsize + 0x3F);
            model = bodyBuffer + bufferSizeRemain;
            totalsize = ALIGN64_V3(bufferSizeRemain + 0xFB);

            modelCalculateRwDataLen(pBody);
            modelCalculateRwDataLen(pHead);
            numRecords = pBody->numRecords + pHead->numRecords + 0xA;
            
            totalsize = ALIGN64_V3((numRecords * 4) + totalsize + 0x3F);
            
            animInit(model, pBody, bodyBuffer + totalsize);
            model->Type = numRecords; //???
            //goto block_46;
            //&c_item_entries[head]->header = pHead;
        }

        pBody = &c_item_entries[body]->header;
        if (&c_item_entries[body]->header->RootNode == NULL)
        {
            fileLoad(&c_item_entries[body]->header, &c_item_entries[body]->filename);
        }

        if (&c_item_entries[head]->header->RootNode == NULL)
        {
            pHead = &c_item_entries[head]->header;
            fileLoad(&c_item_entries[head]->header, &c_item_entries[head]->filename);
//block_46:
//            &c_item_entries[head]->header = pHead;
        }
        g_CurrentPlayer->ptr_char_objectinstance = makeonebody(body, head, pBody, &c_item_entries[head]->header/*pHead maybe?*/, 0, model);
        
        modelSetScale((Model *) g_CurrentPlayer->ptr_char_objectinstance, g_CurrentPlayer->ptr_char_objectinstance->unk14 * 0.97f);
        init_GUARDdata_with_set_values(g_CurrentPlayer->prop, g_CurrentPlayer->ptr_char_objectinstance, &g_CurrentPlayer->prop->pos, hRot, g_CurrentPlayer->prop->stan, 0);
        g_CurrentPlayer->prop->type = VIEWER;
        g_CurrentPlayer->prop->chr->chrflags |= CHRFLAG_INIT;
        setsuboffset(g_CurrentPlayer->ptr_char_objectinstance, &g_CurrentPlayer->prop->pos);
        setsubroty(g_CurrentPlayer->ptr_char_objectinstance, hRot);
        rhandPropID = getPropForHeldItem(rhandweapID);
        if (rhandPropID >= 0)
        {
            if (getPlayerCount() == 1)
            {
                p_rightHeader = bodyBuffer + totalsize;
                totalsize = ALIGN64_V3(totalsize + 0xC7);
                p_lhandItemHeader = get_ptr_itemheader_in_hand(GUNLEFT);
                p_rhandItemHeader = &PitemZ_entries[rhandPropID]->header;
                p_leftHeader = p_lhandItemHeader;
                p_lhandItemHeader->RootNode = p_rhandItemHeader->RootNode;
                p_lhandItemHeader->Skeleton = p_rhandItemHeader->Skeleton;
                p_lhandItemHeader->Switches = p_rhandItemHeader->Switches;
                p_lhandItemHeader->unkC = p_rhandItemHeader->unkC;
                p_lhandItemHeader->BoundingVolumeRadius = p_rhandItemHeader->BoundingVolumeRadius;
                p_lhandItemHeader->unk14 = p_rhandItemHeader->unk14;
                p_lhandItemHeader->Textures = p_rhandItemHeader->Textures;
                p_lhandItemHeader->isLoaded = p_rhandItemHeader->isLoaded;
                p_modelEntry = &PitemZ_entries[rhandPropID];
                load_object_fill_header(p_lhandItemHeader, &PitemZ_entries[rhandPropID]->filename, bodyBuffer + totalsize, bodyBufSize - totalsize, &texPool);
                get_pc_buffer_remaining_value(p_modelEntry->filename);
                modelCalculateRwDataLen(p_leftHeader);
            }
            else
            {
                p_rightHeader = NULL;
                p_leftHeader = NULL;
            }
            something_with_generating_object(g_CurrentPlayer->prop->chr, rhandPropID, rhandweapID, 0, p_rightHeader, p_leftHeader);
        }
        chrlvIdleAnimationRelated7F023A94(g_CurrentPlayer->prop->chr, 0.0f);
        return;
    }
    if (curChr->model->anim == NULL)
    {
        curChr->chrflags |= 1;
        chrlvIdleAnimationRelated7F023A94(curChr, 0.0f);
        setsuboffset(g_CurrentPlayer->ptr_char_objectinstance, &g_CurrentPlayer->prop->pos);
        setsubroty(g_CurrentPlayer->ptr_char_objectinstance, hRot);
    }
}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80054FB8
.word 0
glabel D_80054FBC
.word 0

/*D:80054FC0*/
glabel a8s
/*"%8s"*/
.word 0x25387300

glabel aX4_0f
/*"x %4.0f"*/
.word 0x78202534
.word 0x2E306600

glabel aY4_0f
/*"y %4.0f"*/
.word 0x79202534
.word 0x2E306600

glabel aZ4_0f
/*"z %4.0f"*/
.word 0x7A202534
.word 0x2E306600

glabel aS3d
/*"%s %3d"*/
.word 0x25732025
.word 0x33640000
/*D:80054FE4*/
glabel jpt_bondcuff
.word .L7F079EA4
.word cuff_1_brosnan
.word cuff_2_jungle
.word cuff_3_boiler
.word cuff_4_snowsuit
.word cuff_5_connery
.word cuff_6_moore
.word cuff_7_dalton
.word cuff_8_variable_bond_head

/*D:80055008*/
glabel jpt_bondhead
.word .L7F079F84
.word brosnan_tux_head_set
.word jungle_head_set
.word boiler_bond_head_set
.word .L7F079F84
.word connery_head_set
.word moore_head_set
.word dalton_head_set
.word variable_body_head

glabel D_8005502C
.word 0x3f7851ec /*0.97000003*/
.text
glabel solo_char_load
/* 0AE820 7F079CF0 27BDFEE8 */  addiu $sp, $sp, -0x118
/* 0AE824 7F079CF4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0AE828 7F079CF8 0FC227B9 */  jal   get_curplay_horizontal_rotation_in_degrees
/* 0AE82C 7F079CFC 00000000 */   nop
/* 0AE830 7F079D00 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0AE834 7F079D04 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0AE838 7F079D08 E7A00114 */  swc1  $f0, 0x114($sp)
/* 0AE83C 7F079D0C 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0AE840 7F079D10 8DE20004 */  lw    $v0, 4($t7)
/* 0AE844 7F079D14 544001CA */  bnezl $v0, .L7F07A440
/* 0AE848 7F079D18 8C4F001C */   lw    $t7, 0x1c($v0)
/* 0AE84C 7F079D1C 0FC173CC */  jal   getPlayerWeaponBufferForHand
/* 0AE850 7F079D20 00002025 */   move  $a0, $zero
/* 0AE854 7F079D24 AFA200F0 */  sw    $v0, 0xf0($sp)
/* 0AE858 7F079D28 0FC173CC */  jal   getPlayerWeaponBufferForHand
/* 0AE85C 7F079D2C 24040001 */   li    $a0, 1
/* 0AE860 7F079D30 AFA200EC */  sw    $v0, 0xec($sp)
/* 0AE864 7F079D34 AFA000E8 */  sw    $zero, 0xe8($sp)
/* 0AE868 7F079D38 0FC173D2 */  jal   getSizeBufferWeaponInHand
/* 0AE86C 7F079D3C 00002025 */   move  $a0, $zero
/* 0AE870 7F079D40 AFA200E4 */  sw    $v0, 0xe4($sp)
/* 0AE874 7F079D44 0FC173D2 */  jal   getSizeBufferWeaponInHand
/* 0AE878 7F079D48 24040001 */   li    $a0, 1
/* 0AE87C 7F079D4C 3C198003 */  lui   $t9, %hi(dummy_08_pp7_obj)
/* 0AE880 7F079D50 273965AC */  addiu $t9, %lo(dummy_08_pp7_obj) # addiu $t9, $t9, 0x65ac
/* 0AE884 7F079D54 AFA200E0 */  sw    $v0, 0xe0($sp)
/* 0AE888 7F079D58 272C0084 */  addiu $t4, $t9, 0x84
/* 0AE88C 7F079D5C 27B80054 */  addiu $t8, $sp, 0x54
.L7F079D60:
/* 0AE890 7F079D60 8F210000 */  lw    $at, ($t9)
/* 0AE894 7F079D64 2739000C */  addiu $t9, $t9, 0xc
/* 0AE898 7F079D68 2718000C */  addiu $t8, $t8, 0xc
/* 0AE89C 7F079D6C AF01FFF4 */  sw    $at, -0xc($t8)
/* 0AE8A0 7F079D70 8F21FFF8 */  lw    $at, -8($t9)
/* 0AE8A4 7F079D74 AF01FFF8 */  sw    $at, -8($t8)
/* 0AE8A8 7F079D78 8F21FFFC */  lw    $at, -4($t9)
/* 0AE8AC 7F079D7C 172CFFF8 */  bne   $t9, $t4, .L7F079D60
/* 0AE8B0 7F079D80 AF01FFFC */   sw    $at, -4($t8)
/* 0AE8B4 7F079D84 8F210000 */  lw    $at, ($t9)
/* 0AE8B8 7F079D88 00002025 */  move  $a0, $zero
/* 0AE8BC 7F079D8C 0FC17691 */  jal   get_item_in_hand_or_watch_menu
/* 0AE8C0 7F079D90 AF010000 */   sw    $at, ($t8)
/* 0AE8C4 7F079D94 240D0017 */  li    $t5, 23
/* 0AE8C8 7F079D98 240E004B */  li    $t6, 75
/* 0AE8CC 7F079D9C 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0AE8D0 7F079DA0 AFA20048 */  sw    $v0, 0x48($sp)
/* 0AE8D4 7F079DA4 AFAD0044 */  sw    $t5, 0x44($sp)
/* 0AE8D8 7F079DA8 AFAE0040 */  sw    $t6, 0x40($sp)
/* 0AE8DC 7F079DAC AFA00038 */  sw    $zero, 0x38($sp)
/* 0AE8E0 7F079DB0 0FC1F799 */  jal   sub_GAME_7F07DE64
/* 0AE8E4 7F079DB4 8C84A0B0 */   lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0AE8E8 7F079DB8 0FC26919 */  jal   getPlayerCount
/* 0AE8EC 7F079DBC 00000000 */   nop
/* 0AE8F0 7F079DC0 24010001 */  li    $at, 1
/* 0AE8F4 7F079DC4 14410066 */  bne   $v0, $at, .L7F079F60
/* 0AE8F8 7F079DC8 00000000 */   nop
/* 0AE8FC 7F079DCC 0FC0755B */  jal   getSelectedFolderBond
/* 0AE900 7F079DD0 00000000 */   nop
/* 0AE904 7F079DD4 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer)
/* 0AE908 7F079DD8 8DEFA0B0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0AE90C 7F079DDC 8DE3041C */  lw    $v1, 0x41c($t7)
/* 0AE910 7F079DE0 2C610009 */  sltiu $at, $v1, 9
/* 0AE914 7F079DE4 1020002F */  beqz  $at, .L7F079EA4
/* 0AE918 7F079DE8 00035880 */   sll   $t3, $v1, 2
/* 0AE91C 7F079DEC 3C018005 */  lui   $at, %hi(jpt_bondcuff)
/* 0AE920 7F079DF0 002B0821 */  addu  $at, $at, $t3
/* 0AE924 7F079DF4 8C2B4FE4 */  lw    $t3, %lo(jpt_bondcuff)($at)
/* 0AE928 7F079DF8 01600008 */  jr    $t3
/* 0AE92C 7F079DFC 00000000 */   nop
cuff_3_boiler:
/* 0AE930 7F079E00 240A0016 */  li    $t2, 22
/* 0AE934 7F079E04 10000027 */  b     .L7F079EA4
/* 0AE938 7F079E08 AFAA0044 */   sw    $t2, 0x44($sp)
cuff_2_jungle:
/* 0AE93C 7F079E0C 240C0018 */  li    $t4, 24
/* 0AE940 7F079E10 10000024 */  b     .L7F079EA4
/* 0AE944 7F079E14 AFAC0044 */   sw    $t4, 0x44($sp)
cuff_4_snowsuit:
/* 0AE948 7F079E18 24190019 */  li    $t9, 25
/* 0AE94C 7F079E1C 10000021 */  b     .L7F079EA4
/* 0AE950 7F079E20 AFB90044 */   sw    $t9, 0x44($sp)
cuff_1_brosnan:
/* 0AE954 7F079E24 24180005 */  li    $t8, 5
/* 0AE958 7F079E28 1000001E */  b     .L7F079EA4
/* 0AE95C 7F079E2C AFB80044 */   sw    $t8, 0x44($sp)
cuff_5_connery:
/* 0AE960 7F079E30 240D0005 */  li    $t5, 5
/* 0AE964 7F079E34 1000001B */  b     .L7F079EA4
/* 0AE968 7F079E38 AFAD0044 */   sw    $t5, 0x44($sp)
cuff_6_moore:
/* 0AE96C 7F079E3C 240E0005 */  li    $t6, 5
/* 0AE970 7F079E40 10000018 */  b     .L7F079EA4
/* 0AE974 7F079E44 AFAE0044 */   sw    $t6, 0x44($sp)
cuff_7_dalton:
/* 0AE978 7F079E48 240F0005 */  li    $t7, 5
/* 0AE97C 7F079E4C 10000015 */  b     .L7F079EA4
/* 0AE980 7F079E50 AFAF0044 */   sw    $t7, 0x44($sp)
cuff_8_variable_bond_head:
/* 0AE984 7F079E54 1040000C */  beqz  $v0, .L7F079E88
/* 0AE988 7F079E58 240B0005 */   li    $t3, 5
/* 0AE98C 7F079E5C 24010001 */  li    $at, 1
/* 0AE990 7F079E60 1041000B */  beq   $v0, $at, .L7F079E90
/* 0AE994 7F079E64 240A0005 */   li    $t2, 5
/* 0AE998 7F079E68 24010002 */  li    $at, 2
/* 0AE99C 7F079E6C 1041000A */  beq   $v0, $at, .L7F079E98
/* 0AE9A0 7F079E70 240C0005 */   li    $t4, 5
/* 0AE9A4 7F079E74 24010003 */  li    $at, 3
/* 0AE9A8 7F079E78 10410009 */  beq   $v0, $at, .L7F079EA0
/* 0AE9AC 7F079E7C 24190005 */   li    $t9, 5
/* 0AE9B0 7F079E80 10000008 */  b     .L7F079EA4
/* 0AE9B4 7F079E84 00000000 */   nop
.L7F079E88:
/* 0AE9B8 7F079E88 10000006 */  b     .L7F079EA4
/* 0AE9BC 7F079E8C AFAB0044 */   sw    $t3, 0x44($sp)
.L7F079E90:
/* 0AE9C0 7F079E90 10000004 */  b     .L7F079EA4
/* 0AE9C4 7F079E94 AFAA0044 */   sw    $t2, 0x44($sp)
.L7F079E98:
/* 0AE9C8 7F079E98 10000002 */  b     .L7F079EA4
/* 0AE9CC 7F079E9C AFAC0044 */   sw    $t4, 0x44($sp)
.L7F079EA0:
/* 0AE9D0 7F079EA0 AFB90044 */  sw    $t9, 0x44($sp)
.L7F079EA4:
/* 0AE9D4 7F079EA4 1040000C */  beqz  $v0, .L7F079ED8
/* 0AE9D8 7F079EA8 2C610009 */   sltiu $at, $v1, 9
/* 0AE9DC 7F079EAC 24010001 */  li    $at, 1
/* 0AE9E0 7F079EB0 10410025 */  beq   $v0, $at, .L7F079F48
/* 0AE9E4 7F079EB4 2418004E */   li    $t8, 78
/* 0AE9E8 7F079EB8 24010002 */  li    $at, 2
/* 0AE9EC 7F079EBC 10410024 */  beq   $v0, $at, .L7F079F50
/* 0AE9F0 7F079EC0 240D004E */   li    $t5, 78
/* 0AE9F4 7F079EC4 24010003 */  li    $at, 3
/* 0AE9F8 7F079EC8 10410023 */  beq   $v0, $at, .L7F079F58
/* 0AE9FC 7F079ECC 240E004E */   li    $t6, 78
/* 0AEA00 7F079ED0 1000002C */  b     .L7F079F84
/* 0AEA04 7F079ED4 00000000 */   nop
.L7F079ED8:
/* 0AEA08 7F079ED8 1020002A */  beqz  $at, .L7F079F84
/* 0AEA0C 7F079EDC 0003C080 */   sll   $t8, $v1, 2
/* 0AEA10 7F079EE0 3C018005 */  lui   $at, %hi(jpt_bondhead)
/* 0AEA14 7F079EE4 00380821 */  addu  $at, $at, $t8
/* 0AEA18 7F079EE8 8C385008 */  lw    $t8, %lo(jpt_bondhead)($at)
/* 0AEA1C 7F079EEC 03000008 */  jr    $t8
/* 0AEA20 7F079EF0 00000000 */   nop
boiler_bond_head_set:
/* 0AEA24 7F079EF4 240D004A */  li    $t5, 74
/* 0AEA28 7F079EF8 10000022 */  b     .L7F079F84
/* 0AEA2C 7F079EFC AFAD0040 */   sw    $t5, 0x40($sp)
jungle_head_set:
/* 0AEA30 7F079F00 240E004C */  li    $t6, 76
/* 0AEA34 7F079F04 1000001F */  b     .L7F079F84
/* 0AEA38 7F079F08 AFAE0040 */   sw    $t6, 0x40($sp)
brosnan_tux_head_set:
/* 0AEA3C 7F079F0C 240F004E */  li    $t7, 78
/* 0AEA40 7F079F10 1000001C */  b     .L7F079F84
/* 0AEA44 7F079F14 AFAF0040 */   sw    $t7, 0x40($sp)
connery_head_set:
/* 0AEA48 7F079F18 240B004E */  li    $t3, 78
/* 0AEA4C 7F079F1C 10000019 */  b     .L7F079F84
/* 0AEA50 7F079F20 AFAB0040 */   sw    $t3, 0x40($sp)
moore_head_set:
/* 0AEA54 7F079F24 240A004E */  li    $t2, 78
/* 0AEA58 7F079F28 10000016 */  b     .L7F079F84
/* 0AEA5C 7F079F2C AFAA0040 */   sw    $t2, 0x40($sp)
dalton_head_set:
/* 0AEA60 7F079F30 240C004E */  li    $t4, 78
/* 0AEA64 7F079F34 10000013 */  b     .L7F079F84
/* 0AEA68 7F079F38 AFAC0040 */   sw    $t4, 0x40($sp)
variable_body_head:
/* 0AEA6C 7F079F3C 2419004E */  li    $t9, 78
/* 0AEA70 7F079F40 10000010 */  b     .L7F079F84
/* 0AEA74 7F079F44 AFB90040 */   sw    $t9, 0x40($sp)
.L7F079F48:
/* 0AEA78 7F079F48 1000000E */  b     .L7F079F84
/* 0AEA7C 7F079F4C AFB80040 */   sw    $t8, 0x40($sp)
.L7F079F50:
/* 0AEA80 7F079F50 1000000C */  b     .L7F079F84
/* 0AEA84 7F079F54 AFAD0040 */   sw    $t5, 0x40($sp)
.L7F079F58:
/* 0AEA88 7F079F58 1000000A */  b     .L7F079F84
/* 0AEA8C 7F079F5C AFAE0040 */   sw    $t6, 0x40($sp)
.L7F079F60:
/* 0AEA90 7F079F60 0FC26C54 */  jal   get_cur_playernum
/* 0AEA94 7F079F64 00000000 */   nop
/* 0AEA98 7F079F68 0FC040AF */  jal   get_player_mp_char_head
/* 0AEA9C 7F079F6C 00402025 */   move  $a0, $v0
/* 0AEAA0 7F079F70 0FC26C54 */  jal   get_cur_playernum
/* 0AEAA4 7F079F74 AFA20040 */   sw    $v0, 0x40($sp)
/* 0AEAA8 7F079F78 0FC040D7 */  jal   get_player_mp_char_body
/* 0AEAAC 7F079F7C 00402025 */   move  $a0, $v0
/* 0AEAB0 7F079F80 AFA20044 */  sw    $v0, 0x44($sp)
.L7F079F84:
/* 0AEAB4 7F079F84 3C0F8003 */  lui   $t7, %hi(g_CameraMode)
/* 0AEAB8 7F079F88 8DEF6494 */  lw    $t7, %lo(g_CameraMode)($t7)
/* 0AEABC 7F079F8C 24010003 */  li    $at, 3
/* 0AEAC0 7F079F90 15E10003 */  bne   $t7, $at, .L7F079FA0
/* 0AEAC4 7F079F94 3C0B8008 */   lui   $t3, %hi(starting_right_weapon)
/* 0AEAC8 7F079F98 8D6B99E0 */  lw    $t3, %lo(starting_right_weapon)($t3)
/* 0AEACC 7F079F9C AFAB0048 */  sw    $t3, 0x48($sp)
.L7F079FA0:
/* 0AEAD0 7F079FA0 0FC26919 */  jal   getPlayerCount
/* 0AEAD4 7F079FA4 00000000 */   nop
/* 0AEAD8 7F079FA8 24010001 */  li    $at, 1
/* 0AEADC 7F079FAC 14410083 */  bne   $v0, $at, .L7F07A1BC
/* 0AEAE0 7F079FB0 8FAF0044 */   lw    $t7, 0x44($sp)
/* 0AEAE4 7F079FB4 0FC173D7 */  jal   remove_item_in_hand
/* 0AEAE8 7F079FB8 24040001 */   li    $a0, 1
/* 0AEAEC 7F079FBC 0FC173D7 */  jal   remove_item_in_hand
/* 0AEAF0 7F079FC0 00002025 */   move  $a0, $zero
/* 0AEAF4 7F079FC4 27A40100 */  addiu $a0, $sp, 0x100
/* 0AEAF8 7F079FC8 8FA500EC */  lw    $a1, 0xec($sp)
/* 0AEAFC 7F079FCC 0FC32EBD */  jal   texInitPool
/* 0AEB00 7F079FD0 8FA600E0 */   lw    $a2, 0xe0($sp)
/* 0AEB04 7F079FD4 0FC173C6 */  jal   get_ptr_itemheader_in_hand
/* 0AEB08 7F079FD8 00002025 */   move  $a0, $zero
/* 0AEB0C 7F079FDC 8FAA0044 */  lw    $t2, 0x44($sp)
/* 0AEB10 7F079FE0 3C198004 */  lui   $t9, %hi(c_item_entries)
/* 0AEB14 7F079FE4 2739DE10 */  addiu $t9, %lo(c_item_entries) # addiu $t9, $t9, -0x21f0
/* 0AEB18 7F079FE8 000A6080 */  sll   $t4, $t2, 2
/* 0AEB1C 7F079FEC 018A6021 */  addu  $t4, $t4, $t2
/* 0AEB20 7F079FF0 000C6080 */  sll   $t4, $t4, 2
/* 0AEB24 7F079FF4 01991821 */  addu  $v1, $t4, $t9
/* 0AEB28 7F079FF8 8C780000 */  lw    $t8, ($v1)
/* 0AEB2C 7F079FFC AFA200FC */  sw    $v0, 0xfc($sp)
/* 0AEB30 7F07A000 27AB0100 */  addiu $t3, $sp, 0x100
/* 0AEB34 7F07A004 8F010000 */  lw    $at, ($t8)
/* 0AEB38 7F07A008 00402025 */  move  $a0, $v0
/* 0AEB3C 7F07A00C AC410000 */  sw    $at, ($v0)
/* 0AEB40 7F07A010 8F0F0004 */  lw    $t7, 4($t8)
/* 0AEB44 7F07A014 AC4F0004 */  sw    $t7, 4($v0)
/* 0AEB48 7F07A018 8F010008 */  lw    $at, 8($t8)
/* 0AEB4C 7F07A01C AC410008 */  sw    $at, 8($v0)
/* 0AEB50 7F07A020 8F0F000C */  lw    $t7, 0xc($t8)
/* 0AEB54 7F07A024 AC4F000C */  sw    $t7, 0xc($v0)
/* 0AEB58 7F07A028 8F010010 */  lw    $at, 0x10($t8)
/* 0AEB5C 7F07A02C AC410010 */  sw    $at, 0x10($v0)
/* 0AEB60 7F07A030 8F0F0014 */  lw    $t7, 0x14($t8)
/* 0AEB64 7F07A034 AC4F0014 */  sw    $t7, 0x14($v0)
/* 0AEB68 7F07A038 8F010018 */  lw    $at, 0x18($t8)
/* 0AEB6C 7F07A03C AC410018 */  sw    $at, 0x18($v0)
/* 0AEB70 7F07A040 8F0F001C */  lw    $t7, 0x1c($t8)
/* 0AEB74 7F07A044 AC4F001C */  sw    $t7, 0x1c($v0)
/* 0AEB78 7F07A048 AFA30028 */  sw    $v1, 0x28($sp)
/* 0AEB7C 7F07A04C AFAB0010 */  sw    $t3, 0x10($sp)
/* 0AEB80 7F07A050 8FA700E4 */  lw    $a3, 0xe4($sp)
/* 0AEB84 7F07A054 8FA600F0 */  lw    $a2, 0xf0($sp)
/* 0AEB88 7F07A058 0FC1D929 */  jal   load_object_fill_header
/* 0AEB8C 7F07A05C 8C650004 */   lw    $a1, 4($v1)
/* 0AEB90 7F07A060 8FA30028 */  lw    $v1, 0x28($sp)
/* 0AEB94 7F07A064 0FC2F462 */  jal   get_pc_buffer_remaining_value
/* 0AEB98 7F07A068 8C640004 */   lw    $a0, 4($v1)
/* 0AEB9C 7F07A06C 8FAD0040 */  lw    $t5, 0x40($sp)
/* 0AEBA0 7F07A070 3C0F8004 */  lui   $t7, %hi(c_item_entries)
/* 0AEBA4 7F07A074 25EFDE10 */  addiu $t7, %lo(c_item_entries) # addiu $t7, $t7, -0x21f0
/* 0AEBA8 7F07A078 000DC080 */  sll   $t8, $t5, 2
/* 0AEBAC 7F07A07C 030DC021 */  addu  $t8, $t8, $t5
/* 0AEBB0 7F07A080 0018C080 */  sll   $t8, $t8, 2
/* 0AEBB4 7F07A084 030F1821 */  addu  $v1, $t8, $t7
/* 0AEBB8 7F07A088 8C6B0000 */  lw    $t3, ($v1)
/* 0AEBBC 7F07A08C 2448003F */  addiu $t0, $v0, 0x3f
/* 0AEBC0 7F07A090 8FA900F0 */  lw    $t1, 0xf0($sp)
/* 0AEBC4 7F07A094 350A003F */  ori   $t2, $t0, 0x3f
/* 0AEBC8 7F07A098 8D610000 */  lw    $at, ($t3)
/* 0AEBCC 7F07A09C 394C003F */  xori  $t4, $t2, 0x3f
/* 0AEBD0 7F07A0A0 2588005F */  addiu $t0, $t4, 0x5f
/* 0AEBD4 7F07A0A4 3519003F */  ori   $t9, $t0, 0x3f
/* 0AEBD8 7F07A0A8 012C2021 */  addu  $a0, $t1, $t4
/* 0AEBDC 7F07A0AC 3B28003F */  xori  $t0, $t9, 0x3f
/* 0AEBE0 7F07A0B0 AC810000 */  sw    $at, ($a0)
/* 0AEBE4 7F07A0B4 8D790004 */  lw    $t9, 4($t3)
/* 0AEBE8 7F07A0B8 27AD0100 */  addiu $t5, $sp, 0x100
/* 0AEBEC 7F07A0BC 01283021 */  addu  $a2, $t1, $t0
/* 0AEBF0 7F07A0C0 AC990004 */  sw    $t9, 4($a0)
/* 0AEBF4 7F07A0C4 8D610008 */  lw    $at, 8($t3)
/* 0AEBF8 7F07A0C8 AC810008 */  sw    $at, 8($a0)
/* 0AEBFC 7F07A0CC 8D79000C */  lw    $t9, 0xc($t3)
/* 0AEC00 7F07A0D0 AC99000C */  sw    $t9, 0xc($a0)
/* 0AEC04 7F07A0D4 8D610010 */  lw    $at, 0x10($t3)
/* 0AEC08 7F07A0D8 AC810010 */  sw    $at, 0x10($a0)
/* 0AEC0C 7F07A0DC 8D790014 */  lw    $t9, 0x14($t3)
/* 0AEC10 7F07A0E0 AC990014 */  sw    $t9, 0x14($a0)
/* 0AEC14 7F07A0E4 8D610018 */  lw    $at, 0x18($t3)
/* 0AEC18 7F07A0E8 AC810018 */  sw    $at, 0x18($a0)
/* 0AEC1C 7F07A0EC 8D79001C */  lw    $t9, 0x1c($t3)
/* 0AEC20 7F07A0F0 AC99001C */  sw    $t9, 0x1c($a0)
/* 0AEC24 7F07A0F4 8FAE00E4 */  lw    $t6, 0xe4($sp)
/* 0AEC28 7F07A0F8 AFA800E8 */  sw    $t0, 0xe8($sp)
/* 0AEC2C 7F07A0FC AFA400F8 */  sw    $a0, 0xf8($sp)
/* 0AEC30 7F07A100 AFA30028 */  sw    $v1, 0x28($sp)
/* 0AEC34 7F07A104 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0AEC38 7F07A108 8C650004 */  lw    $a1, 4($v1)
/* 0AEC3C 7F07A10C 0FC1D929 */  jal   load_object_fill_header
/* 0AEC40 7F07A110 01C83823 */   subu  $a3, $t6, $t0
/* 0AEC44 7F07A114 8FA30028 */  lw    $v1, 0x28($sp)
/* 0AEC48 7F07A118 0FC2F462 */  jal   get_pc_buffer_remaining_value
/* 0AEC4C 7F07A11C 8C640004 */   lw    $a0, 4($v1)
/* 0AEC50 7F07A120 8FA300E8 */  lw    $v1, 0xe8($sp)
/* 0AEC54 7F07A124 8FAC00F0 */  lw    $t4, 0xf0($sp)
/* 0AEC58 7F07A128 8FA400FC */  lw    $a0, 0xfc($sp)
/* 0AEC5C 7F07A12C 00431821 */  addu  $v1, $v0, $v1
/* 0AEC60 7F07A130 2463003F */  addiu $v1, $v1, 0x3f
/* 0AEC64 7F07A134 3478003F */  ori   $t8, $v1, 0x3f
/* 0AEC68 7F07A138 3B0F003F */  xori  $t7, $t8, 0x3f
/* 0AEC6C 7F07A13C 25E300FB */  addiu $v1, $t7, 0xfb
/* 0AEC70 7F07A140 346B003F */  ori   $t3, $v1, 0x3f
/* 0AEC74 7F07A144 3979003F */  xori  $t9, $t3, 0x3f
/* 0AEC78 7F07A148 018F5021 */  addu  $t2, $t4, $t7
/* 0AEC7C 7F07A14C AFAA0038 */  sw    $t2, 0x38($sp)
/* 0AEC80 7F07A150 0FC1D73D */  jal   modelCalculateRwDataLen
/* 0AEC84 7F07A154 AFB900E8 */   sw    $t9, 0xe8($sp)
/* 0AEC88 7F07A158 0FC1D73D */  jal   modelCalculateRwDataLen
/* 0AEC8C 7F07A15C 8FA400F8 */   lw    $a0, 0xf8($sp)
/* 0AEC90 7F07A160 8FA500FC */  lw    $a1, 0xfc($sp)
/* 0AEC94 7F07A164 8FAF00F8 */  lw    $t7, 0xf8($sp)
/* 0AEC98 7F07A168 8FA300E8 */  lw    $v1, 0xe8($sp)
/* 0AEC9C 7F07A16C 84B80014 */  lh    $t8, 0x14($a1)
/* 0AECA0 7F07A170 85EC0014 */  lh    $t4, 0x14($t7)
/* 0AECA4 7F07A174 8FAE00F0 */  lw    $t6, 0xf0($sp)
/* 0AECA8 7F07A178 8FA40038 */  lw    $a0, 0x38($sp)
/* 0AECAC 7F07A17C 030C1021 */  addu  $v0, $t8, $t4
/* 0AECB0 7F07A180 2442000A */  addiu $v0, $v0, 0xa
/* 0AECB4 7F07A184 00025080 */  sll   $t2, $v0, 2
/* 0AECB8 7F07A188 01C33021 */  addu  $a2, $t6, $v1
/* 0AECBC 7F07A18C 01431821 */  addu  $v1, $t2, $v1
/* 0AECC0 7F07A190 2463003F */  addiu $v1, $v1, 0x3f
/* 0AECC4 7F07A194 346B003F */  ori   $t3, $v1, 0x3f
/* 0AECC8 7F07A198 3979003F */  xori  $t9, $t3, 0x3f
/* 0AECCC 7F07A19C AFB900E8 */  sw    $t9, 0xe8($sp)
/* 0AECD0 7F07A1A0 0FC1D7EB */  jal   animInit
/* 0AECD4 7F07A1A4 AFA20030 */   sw    $v0, 0x30($sp)
/* 0AECD8 7F07A1A8 8FA20030 */  lw    $v0, 0x30($sp)
/* 0AECDC 7F07A1AC 8FAE0038 */  lw    $t6, 0x38($sp)
/* 0AECE0 7F07A1B0 A5C20002 */  sh    $v0, 2($t6)
/* 0AECE4 7F07A1B4 1000001F */  b     .L7F07A234
/* 0AECE8 7F07A1B8 8FA700F8 */   lw    $a3, 0xf8($sp)
.L7F07A1BC:
/* 0AECEC 7F07A1BC 000FC080 */  sll   $t8, $t7, 2
/* 0AECF0 7F07A1C0 030FC021 */  addu  $t8, $t8, $t7
/* 0AECF4 7F07A1C4 3C0C8004 */  lui   $t4, %hi(c_item_entries)
/* 0AECF8 7F07A1C8 258CDE10 */  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21f0
/* 0AECFC 7F07A1CC 0018C080 */  sll   $t8, $t8, 2
/* 0AED00 7F07A1D0 030C1821 */  addu  $v1, $t8, $t4
/* 0AED04 7F07A1D4 8C6A0000 */  lw    $t2, ($v1)
/* 0AED08 7F07A1D8 AFAA00FC */  sw    $t2, 0xfc($sp)
/* 0AED0C 7F07A1DC 8D590000 */  lw    $t9, ($t2)
/* 0AED10 7F07A1E0 01402025 */  move  $a0, $t2
/* 0AED14 7F07A1E4 57200004 */  bnezl $t9, .L7F07A1F8
/* 0AED18 7F07A1E8 8FAD0040 */   lw    $t5, 0x40($sp)
/* 0AED1C 7F07A1EC 0FC1D953 */  jal   fileLoad
/* 0AED20 7F07A1F0 8C650004 */   lw    $a1, 4($v1)
/* 0AED24 7F07A1F4 8FAD0040 */  lw    $t5, 0x40($sp)
.L7F07A1F8:
/* 0AED28 7F07A1F8 3C0F8004 */  lui   $t7, %hi(c_item_entries)
/* 0AED2C 7F07A1FC 25EFDE10 */  addiu $t7, %lo(c_item_entries) # addiu $t7, $t7, -0x21f0
/* 0AED30 7F07A200 000D7080 */  sll   $t6, $t5, 2
/* 0AED34 7F07A204 01CD7021 */  addu  $t6, $t6, $t5
/* 0AED38 7F07A208 000E7080 */  sll   $t6, $t6, 2
/* 0AED3C 7F07A20C 01CF1821 */  addu  $v1, $t6, $t7
/* 0AED40 7F07A210 8C670000 */  lw    $a3, ($v1)
/* 0AED44 7F07A214 8CF80000 */  lw    $t8, ($a3)
/* 0AED48 7F07A218 00E02025 */  move  $a0, $a3
/* 0AED4C 7F07A21C 57000006 */  bnezl $t8, .L7F07A238
/* 0AED50 7F07A220 8FAC0038 */   lw    $t4, 0x38($sp)
/* 0AED54 7F07A224 8C650004 */  lw    $a1, 4($v1)
/* 0AED58 7F07A228 0FC1D953 */  jal   fileLoad
/* 0AED5C 7F07A22C AFA700F8 */   sw    $a3, 0xf8($sp)
/* 0AED60 7F07A230 8FA700F8 */  lw    $a3, 0xf8($sp)
.L7F07A234:
/* 0AED64 7F07A234 8FAC0038 */  lw    $t4, 0x38($sp)
.L7F07A238:
/* 0AED68 7F07A238 8FA40044 */  lw    $a0, 0x44($sp)
/* 0AED6C 7F07A23C 8FA50040 */  lw    $a1, 0x40($sp)
/* 0AED70 7F07A240 8FA600FC */  lw    $a2, 0xfc($sp)
/* 0AED74 7F07A244 AFA00010 */  sw    $zero, 0x10($sp)
/* 0AED78 7F07A248 0FC08CBA */  jal   makeonebody
/* 0AED7C 7F07A24C AFAC0014 */   sw    $t4, 0x14($sp)
/* 0AED80 7F07A250 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0AED84 7F07A254 2463A0B0 */  addiu $v1, %lo(g_CurrentPlayer) # addiu $v1, $v1, -0x5f50
/* 0AED88 7F07A258 8C6A0000 */  lw    $t2, ($v1)
/* 0AED8C 7F07A25C 3C018005 */  lui   $at, %hi(D_8005502C)
/* 0AED90 7F07A260 AD4200D4 */  sw    $v0, 0xd4($t2)
/* 0AED94 7F07A264 8C790000 */  lw    $t9, ($v1)
/* 0AED98 7F07A268 C426502C */  lwc1  $f6, %lo(D_8005502C)($at)
/* 0AED9C 7F07A26C 8F2400D4 */  lw    $a0, 0xd4($t9)
/* 0AEDA0 7F07A270 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0AEDA4 7F07A274 46062202 */  mul.s $f8, $f4, $f6
/* 0AEDA8 7F07A278 44054000 */  mfc1  $a1, $f8
/* 0AEDAC 7F07A27C 0FC1B39E */  jal   modelSetScale
/* 0AEDB0 7F07A280 00000000 */   nop
/* 0AEDB4 7F07A284 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0AEDB8 7F07A288 8C63A0B0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0AEDBC 7F07A28C 8FA70114 */  lw    $a3, 0x114($sp)
/* 0AEDC0 7F07A290 8C6400A8 */  lw    $a0, 0xa8($v1)
/* 0AEDC4 7F07A294 8C6500D4 */  lw    $a1, 0xd4($v1)
/* 0AEDC8 7F07A298 8C8B0014 */  lw    $t3, 0x14($a0)
/* 0AEDCC 7F07A29C AFA00014 */  sw    $zero, 0x14($sp)
/* 0AEDD0 7F07A2A0 24860008 */  addiu $a2, $a0, 8
/* 0AEDD4 7F07A2A4 0FC0802F */  jal   init_GUARDdata_with_set_values
/* 0AEDD8 7F07A2A8 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0AEDDC 7F07A2AC 3C078008 */  lui   $a3, %hi(g_CurrentPlayer)
/* 0AEDE0 7F07A2B0 24E7A0B0 */  addiu $a3, %lo(g_CurrentPlayer) # addiu $a3, $a3, -0x5f50
/* 0AEDE4 7F07A2B4 8CEE0000 */  lw    $t6, ($a3)
/* 0AEDE8 7F07A2B8 240D0006 */  li    $t5, 6
/* 0AEDEC 7F07A2BC 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0AEDF0 7F07A2C0 A1ED0000 */  sb    $t5, ($t7)
/* 0AEDF4 7F07A2C4 8CF80000 */  lw    $t8, ($a3)
/* 0AEDF8 7F07A2C8 8F0C00A8 */  lw    $t4, 0xa8($t8)
/* 0AEDFC 7F07A2CC 8D860004 */  lw    $a2, 4($t4)
/* 0AEE00 7F07A2D0 8CCA0014 */  lw    $t2, 0x14($a2)
/* 0AEE04 7F07A2D4 35590001 */  ori   $t9, $t2, 1
/* 0AEE08 7F07A2D8 ACD90014 */  sw    $t9, 0x14($a2)
/* 0AEE0C 7F07A2DC 8CE30000 */  lw    $v1, ($a3)
/* 0AEE10 7F07A2E0 8C6500A8 */  lw    $a1, 0xa8($v1)
/* 0AEE14 7F07A2E4 8C6400D4 */  lw    $a0, 0xd4($v1)
/* 0AEE18 7F07A2E8 AFA60110 */  sw    $a2, 0x110($sp)
/* 0AEE1C 7F07A2EC 0FC1B303 */  jal   setsuboffset
/* 0AEE20 7F07A2F0 24A50008 */   addiu $a1, $a1, 8
/* 0AEE24 7F07A2F4 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer)
/* 0AEE28 7F07A2F8 8D6BA0B0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0AEE2C 7F07A2FC 8FA50114 */  lw    $a1, 0x114($sp)
/* 0AEE30 7F07A300 0FC1B34F */  jal   setsubroty
/* 0AEE34 7F07A304 8D6400D4 */   lw    $a0, 0xd4($t3)
/* 0AEE38 7F07A308 0FC26C91 */  jal   getPropForHeldItem
/* 0AEE3C 7F07A30C 8FA40048 */   lw    $a0, 0x48($sp)
/* 0AEE40 7F07A310 04400045 */  bltz  $v0, .L7F07A428
/* 0AEE44 7F07A314 AFA2004C */   sw    $v0, 0x4c($sp)
/* 0AEE48 7F07A318 0FC26919 */  jal   getPlayerCount
/* 0AEE4C 7F07A31C 00000000 */   nop
/* 0AEE50 7F07A320 24010001 */  li    $at, 1
/* 0AEE54 7F07A324 14410035 */  bne   $v0, $at, .L7F07A3FC
/* 0AEE58 7F07A328 8FAE00F0 */   lw    $t6, 0xf0($sp)
/* 0AEE5C 7F07A32C 8FA200E8 */  lw    $v0, 0xe8($sp)
/* 0AEE60 7F07A330 24040001 */  li    $a0, 1
/* 0AEE64 7F07A334 01C26821 */  addu  $t5, $t6, $v0
/* 0AEE68 7F07A338 244200C7 */  addiu $v0, $v0, 0xc7
/* 0AEE6C 7F07A33C 344F003F */  ori   $t7, $v0, 0x3f
/* 0AEE70 7F07A340 39F8003F */  xori  $t8, $t7, 0x3f
/* 0AEE74 7F07A344 AFAD00DC */  sw    $t5, 0xdc($sp)
/* 0AEE78 7F07A348 0FC173C6 */  jal   get_ptr_itemheader_in_hand
/* 0AEE7C 7F07A34C AFB800E8 */   sw    $t8, 0xe8($sp)
/* 0AEE80 7F07A350 8FAC004C */  lw    $t4, 0x4c($sp)
/* 0AEE84 7F07A354 3C198004 */  lui   $t9, %hi(PitemZ_entries)
/* 0AEE88 7F07A358 2739A228 */  addiu $t9, %lo(PitemZ_entries) # addiu $t9, $t9, -0x5dd8
/* 0AEE8C 7F07A35C 000C5080 */  sll   $t2, $t4, 2
/* 0AEE90 7F07A360 014C5023 */  subu  $t2, $t2, $t4
/* 0AEE94 7F07A364 000A5080 */  sll   $t2, $t2, 2
/* 0AEE98 7F07A368 01591821 */  addu  $v1, $t2, $t9
/* 0AEE9C 7F07A36C 8C6B0000 */  lw    $t3, ($v1)
/* 0AEEA0 7F07A370 AFA200F4 */  sw    $v0, 0xf4($sp)
/* 0AEEA4 7F07A374 27AD0100 */  addiu $t5, $sp, 0x100
/* 0AEEA8 7F07A378 8D610000 */  lw    $at, ($t3)
/* 0AEEAC 7F07A37C 00402025 */  move  $a0, $v0
/* 0AEEB0 7F07A380 AC410000 */  sw    $at, ($v0)
/* 0AEEB4 7F07A384 8D6F0004 */  lw    $t7, 4($t3)
/* 0AEEB8 7F07A388 AC4F0004 */  sw    $t7, 4($v0)
/* 0AEEBC 7F07A38C 8D610008 */  lw    $at, 8($t3)
/* 0AEEC0 7F07A390 AC410008 */  sw    $at, 8($v0)
/* 0AEEC4 7F07A394 8D6F000C */  lw    $t7, 0xc($t3)
/* 0AEEC8 7F07A398 AC4F000C */  sw    $t7, 0xc($v0)
/* 0AEECC 7F07A39C 8D610010 */  lw    $at, 0x10($t3)
/* 0AEED0 7F07A3A0 AC410010 */  sw    $at, 0x10($v0)
/* 0AEED4 7F07A3A4 8D6F0014 */  lw    $t7, 0x14($t3)
/* 0AEED8 7F07A3A8 AC4F0014 */  sw    $t7, 0x14($v0)
/* 0AEEDC 7F07A3AC 8D610018 */  lw    $at, 0x18($t3)
/* 0AEEE0 7F07A3B0 AC410018 */  sw    $at, 0x18($v0)
/* 0AEEE4 7F07A3B4 8D6F001C */  lw    $t7, 0x1c($t3)
/* 0AEEE8 7F07A3B8 AC4F001C */  sw    $t7, 0x1c($v0)
/* 0AEEEC 7F07A3BC 8FAC00E8 */  lw    $t4, 0xe8($sp)
/* 0AEEF0 7F07A3C0 8FAA00E4 */  lw    $t2, 0xe4($sp)
/* 0AEEF4 7F07A3C4 8FB800F0 */  lw    $t8, 0xf0($sp)
/* 0AEEF8 7F07A3C8 AFA30028 */  sw    $v1, 0x28($sp)
/* 0AEEFC 7F07A3CC AFAD0010 */  sw    $t5, 0x10($sp)
/* 0AEF00 7F07A3D0 8C650004 */  lw    $a1, 4($v1)
/* 0AEF04 7F07A3D4 014C3823 */  subu  $a3, $t2, $t4
/* 0AEF08 7F07A3D8 0FC1D929 */  jal   load_object_fill_header
/* 0AEF0C 7F07A3DC 030C3021 */   addu  $a2, $t8, $t4
/* 0AEF10 7F07A3E0 8FA30028 */  lw    $v1, 0x28($sp)
/* 0AEF14 7F07A3E4 0FC2F462 */  jal   get_pc_buffer_remaining_value
/* 0AEF18 7F07A3E8 8C640004 */   lw    $a0, 4($v1)
/* 0AEF1C 7F07A3EC 0FC1D73D */  jal   modelCalculateRwDataLen
/* 0AEF20 7F07A3F0 8FA400F4 */   lw    $a0, 0xf4($sp)
/* 0AEF24 7F07A3F4 10000004 */  b     .L7F07A408
/* 0AEF28 7F07A3F8 8FAE00DC */   lw    $t6, 0xdc($sp)
.L7F07A3FC:
/* 0AEF2C 7F07A3FC AFA000DC */  sw    $zero, 0xdc($sp)
/* 0AEF30 7F07A400 AFA000F4 */  sw    $zero, 0xf4($sp)
/* 0AEF34 7F07A404 8FAE00DC */  lw    $t6, 0xdc($sp)
.L7F07A408:
/* 0AEF38 7F07A408 8FAB00F4 */  lw    $t3, 0xf4($sp)
/* 0AEF3C 7F07A40C 8FA40110 */  lw    $a0, 0x110($sp)
/* 0AEF40 7F07A410 8FA5004C */  lw    $a1, 0x4c($sp)
/* 0AEF44 7F07A414 8FA60048 */  lw    $a2, 0x48($sp)
/* 0AEF48 7F07A418 00003825 */  move  $a3, $zero
/* 0AEF4C 7F07A41C AFAE0010 */  sw    $t6, 0x10($sp)
/* 0AEF50 7F07A420 0FC14885 */  jal   something_with_generating_object
/* 0AEF54 7F07A424 AFAB0014 */   sw    $t3, 0x14($sp)
.L7F07A428:
/* 0AEF58 7F07A428 8FA40110 */  lw    $a0, 0x110($sp)
/* 0AEF5C 7F07A42C 0FC08EA5 */  jal   chrlvIdleAnimationRelated7F023A94
/* 0AEF60 7F07A430 24050000 */   li    $a1, 0
/* 0AEF64 7F07A434 10000017 */  b     .L7F07A494
/* 0AEF68 7F07A438 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0AEF6C 7F07A43C 8C4F001C */  lw    $t7, 0x1c($v0)
.L7F07A440:
/* 0AEF70 7F07A440 00402025 */  move  $a0, $v0
/* 0AEF74 7F07A444 8DF80020 */  lw    $t8, 0x20($t7)
/* 0AEF78 7F07A448 57000012 */  bnezl $t8, .L7F07A494
/* 0AEF7C 7F07A44C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0AEF80 7F07A450 8C4C0014 */  lw    $t4, 0x14($v0)
/* 0AEF84 7F07A454 24050000 */  li    $a1, 0
/* 0AEF88 7F07A458 358A0001 */  ori   $t2, $t4, 1
/* 0AEF8C 7F07A45C 0FC08EA5 */  jal   chrlvIdleAnimationRelated7F023A94
/* 0AEF90 7F07A460 AC4A0014 */   sw    $t2, 0x14($v0)
/* 0AEF94 7F07A464 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0AEF98 7F07A468 8C63A0B0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0AEF9C 7F07A46C 8C6500A8 */  lw    $a1, 0xa8($v1)
/* 0AEFA0 7F07A470 8C6400D4 */  lw    $a0, 0xd4($v1)
/* 0AEFA4 7F07A474 0FC1B303 */  jal   setsuboffset
/* 0AEFA8 7F07A478 24A50008 */   addiu $a1, $a1, 8
/* 0AEFAC 7F07A47C 3C198008 */  lui   $t9, %hi(g_CurrentPlayer)
/* 0AEFB0 7F07A480 8F39A0B0 */  lw    $t9, %lo(g_CurrentPlayer)($t9)
/* 0AEFB4 7F07A484 8FA50114 */  lw    $a1, 0x114($sp)
/* 0AEFB8 7F07A488 0FC1B34F */  jal   setsubroty
/* 0AEFBC 7F07A48C 8F2400D4 */   lw    $a0, 0xd4($t9)
/* 0AEFC0 7F07A490 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F07A494:
/* 0AEFC4 7F07A494 27BD0118 */  addiu $sp, $sp, 0x118
/* 0AEFC8 7F07A498 03E00008 */  jr    $ra
/* 0AEFCC 7F07A49C 00000000 */   nop
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_80054FB8
.word 0
glabel D_80054FBC
.word 0

/*D:80054FC0*/
glabel a8s
/*"%8s"*/
.word 0x25387300

glabel aX4_0f
/*"x %4.0f"*/
.word 0x78202534
.word 0x2E306600

glabel aY4_0f
/*"y %4.0f"*/
.word 0x79202534
.word 0x2E306600

glabel aZ4_0f
/*"z %4.0f"*/
.word 0x7A202534
.word 0x2E306600

glabel aS3d
/*"%s %3d"*/
.word 0x25732025
.word 0x33640000
/*D:80054FE4*/
glabel jpt_bondcuff
.word .Ljp7F07A494
.word cuff_1_brosnan
.word cuff_2_jungle
.word cuff_3_boiler
.word cuff_4_snowsuit
.word cuff_5_connery
.word cuff_6_moore
.word cuff_7_dalton
.word cuff_8_variable_bond_head

/*D:80055008*/
glabel jpt_bondhead
.word .Ljp7F07A574
.word brosnan_tux_head_set
.word jungle_head_set
.word boiler_bond_head_set
.word .Ljp7F07A574
.word connery_head_set
.word moore_head_set
.word dalton_head_set
.word variable_body_head

glabel D_8005502C
.word 0x3f7851ec /*0.97000003*/
.text
glabel solo_char_load
/* 0AEE50 7F07A2E0 27BDFEE8 */  addiu $sp, $sp, -0x118
/* 0AEE54 7F07A2E4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0AEE58 7F07A2E8 0FC22987 */  jal   get_curplay_horizontal_rotation_in_degrees
/* 0AEE5C 7F07A2EC 00000000 */   nop
/* 0AEE60 7F07A2F0 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8008
/* 0AEE64 7F07A2F4 8DCEA120 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0AEE68 7F07A2F8 E7A00114 */  swc1  $f0, 0x114($sp)
/* 0AEE6C 7F07A2FC 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0AEE70 7F07A300 8DE20004 */  lw    $v0, 4($t7)
/* 0AEE74 7F07A304 544001D6 */  bnezl $v0, .Ljp7F07AA60
/* 0AEE78 7F07A308 8C59001C */   lw    $t9, 0x1c($v0)
/* 0AEE7C 7F07A30C 0FC17514 */  jal   getPlayerWeaponBufferForHand
/* 0AEE80 7F07A310 00002025 */   move  $a0, $zero
/* 0AEE84 7F07A314 AFA200F0 */  sw    $v0, 0xf0($sp)
/* 0AEE88 7F07A318 0FC17514 */  jal   getPlayerWeaponBufferForHand
/* 0AEE8C 7F07A31C 24040001 */   li    $a0, 1
/* 0AEE90 7F07A320 AFA200EC */  sw    $v0, 0xec($sp)
/* 0AEE94 7F07A324 AFA000E8 */  sw    $zero, 0xe8($sp)
/* 0AEE98 7F07A328 0FC1751A */  jal   getSizeBufferWeaponInHand
/* 0AEE9C 7F07A32C 00002025 */   move  $a0, $zero
/* 0AEEA0 7F07A330 AFA200E4 */  sw    $v0, 0xe4($sp)
/* 0AEEA4 7F07A334 0FC1751A */  jal   getSizeBufferWeaponInHand
/* 0AEEA8 7F07A338 24040001 */   li    $a0, 1
/* 0AEEAC 7F07A33C 3C198003 */  lui   $t9, %hi(dummy_08_pp7_obj) # $t9, 0x8003
/* 0AEEB0 7F07A340 273965EC */  addiu $t9, %lo(dummy_08_pp7_obj) # addiu $t9, $t9, 0x65ec
/* 0AEEB4 7F07A344 AFA200E0 */  sw    $v0, 0xe0($sp)
/* 0AEEB8 7F07A348 272C0084 */  addiu $t4, $t9, 0x84
/* 0AEEBC 7F07A34C 27B80054 */  addiu $t8, $sp, 0x54
.Ljp7F07A350:
/* 0AEEC0 7F07A350 8F210000 */  lw    $at, ($t9)
/* 0AEEC4 7F07A354 2739000C */  addiu $t9, $t9, 0xc
/* 0AEEC8 7F07A358 2718000C */  addiu $t8, $t8, 0xc
/* 0AEECC 7F07A35C AF01FFF4 */  sw    $at, -0xc($t8)
/* 0AEED0 7F07A360 8F21FFF8 */  lw    $at, -8($t9)
/* 0AEED4 7F07A364 AF01FFF8 */  sw    $at, -8($t8)
/* 0AEED8 7F07A368 8F21FFFC */  lw    $at, -4($t9)
/* 0AEEDC 7F07A36C 172CFFF8 */  bne   $t9, $t4, .Ljp7F07A350
/* 0AEEE0 7F07A370 AF01FFFC */   sw    $at, -4($t8)
/* 0AEEE4 7F07A374 8F210000 */  lw    $at, ($t9)
/* 0AEEE8 7F07A378 00002025 */  move  $a0, $zero
/* 0AEEEC 7F07A37C 0FC177D9 */  jal   get_item_in_hand_or_watch_menu
/* 0AEEF0 7F07A380 AF010000 */   sw    $at, ($t8)
/* 0AEEF4 7F07A384 240D0017 */  li    $t5, 23
/* 0AEEF8 7F07A388 240E004B */  li    $t6, 75
/* 0AEEFC 7F07A38C 3C048008 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8008
/* 0AEF00 7F07A390 AFA20048 */  sw    $v0, 0x48($sp)
/* 0AEF04 7F07A394 AFAD0044 */  sw    $t5, 0x44($sp)
/* 0AEF08 7F07A398 AFAE0040 */  sw    $t6, 0x40($sp)
/* 0AEF0C 7F07A39C AFA00038 */  sw    $zero, 0x38($sp)
/* 0AEF10 7F07A3A0 0FC1F922 */  jal   sub_GAME_7F07DE64
/* 0AEF14 7F07A3A4 8C84A120 */   lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0AEF18 7F07A3A8 0FC26C01 */  jal   getPlayerCount
/* 0AEF1C 7F07A3AC 00000000 */   nop
/* 0AEF20 7F07A3B0 24010001 */  li    $at, 1
/* 0AEF24 7F07A3B4 14410066 */  bne   $v0, $at, .Ljp7F07A550
/* 0AEF28 7F07A3B8 00000000 */   nop
/* 0AEF2C 7F07A3BC 0FC075C4 */  jal   getSelectedFolderBond
/* 0AEF30 7F07A3C0 00000000 */   nop
/* 0AEF34 7F07A3C4 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8008
/* 0AEF38 7F07A3C8 8DEFA120 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0AEF3C 7F07A3CC 8DE3041C */  lw    $v1, 0x41c($t7)
/* 0AEF40 7F07A3D0 2C610009 */  sltiu $at, $v1, 9
/* 0AEF44 7F07A3D4 1020002F */  beqz  $at, .Ljp7F07A494
/* 0AEF48 7F07A3D8 00035880 */   sll   $t3, $v1, 2
/* 0AEF4C 7F07A3DC 3C018005 */  lui   $at, %hi(jpt_bondcuff)
/* 0AEF50 7F07A3E0 002B0821 */  addu  $at, $at, $t3
/* 0AEF54 7F07A3E4 8C2B5014 */  lw    $t3, %lo(jpt_bondcuff)($at)
/* 0AEF58 7F07A3E8 01600008 */  jr    $t3
/* 0AEF5C 7F07A3EC 00000000 */   nop
cuff_3_boiler:
/* 0AEF60 7F07A3F0 240A0016 */  li    $t2, 22
/* 0AEF64 7F07A3F4 10000027 */  b     .Ljp7F07A494
/* 0AEF68 7F07A3F8 AFAA0044 */   sw    $t2, 0x44($sp)
cuff_2_jungle:
/* 0AEF6C 7F07A3FC 240C0018 */  li    $t4, 24
/* 0AEF70 7F07A400 10000024 */  b     .Ljp7F07A494
/* 0AEF74 7F07A404 AFAC0044 */   sw    $t4, 0x44($sp)
cuff_4_snowsuit:
/* 0AEF78 7F07A408 24190019 */  li    $t9, 25
/* 0AEF7C 7F07A40C 10000021 */  b     .Ljp7F07A494
/* 0AEF80 7F07A410 AFB90044 */   sw    $t9, 0x44($sp)
cuff_1_brosnan:
/* 0AEF84 7F07A414 24180005 */  li    $t8, 5
/* 0AEF88 7F07A418 1000001E */  b     .Ljp7F07A494
/* 0AEF8C 7F07A41C AFB80044 */   sw    $t8, 0x44($sp)
cuff_5_connery:
/* 0AEF90 7F07A420 240D0005 */  li    $t5, 5
/* 0AEF94 7F07A424 1000001B */  b     .Ljp7F07A494
/* 0AEF98 7F07A428 AFAD0044 */   sw    $t5, 0x44($sp)
cuff_6_moore:
/* 0AEF9C 7F07A42C 240E0005 */  li    $t6, 5
/* 0AEFA0 7F07A430 10000018 */  b     .Ljp7F07A494
/* 0AEFA4 7F07A434 AFAE0044 */   sw    $t6, 0x44($sp)
cuff_7_dalton:
/* 0AEFA8 7F07A438 240F0005 */  li    $t7, 5
/* 0AEFAC 7F07A43C 10000015 */  b     .Ljp7F07A494
/* 0AEFB0 7F07A440 AFAF0044 */   sw    $t7, 0x44($sp)
cuff_8_variable_bond_head:
/* 0AEFB4 7F07A444 1040000C */  beqz  $v0, .Ljp7F07A478
/* 0AEFB8 7F07A448 240B0005 */   li    $t3, 5
/* 0AEFBC 7F07A44C 24010001 */  li    $at, 1
/* 0AEFC0 7F07A450 1041000B */  beq   $v0, $at, .Ljp7F07A480
/* 0AEFC4 7F07A454 240A0005 */   li    $t2, 5
/* 0AEFC8 7F07A458 24010002 */  li    $at, 2
/* 0AEFCC 7F07A45C 1041000A */  beq   $v0, $at, .Ljp7F07A488
/* 0AEFD0 7F07A460 240C0005 */   li    $t4, 5
/* 0AEFD4 7F07A464 24010003 */  li    $at, 3
/* 0AEFD8 7F07A468 10410009 */  beq   $v0, $at, .Ljp7F07A490
/* 0AEFDC 7F07A46C 24190005 */   li    $t9, 5
/* 0AEFE0 7F07A470 10000008 */  b     .Ljp7F07A494
/* 0AEFE4 7F07A474 00000000 */   nop
.Ljp7F07A478:
/* 0AEFE8 7F07A478 10000006 */  b     .Ljp7F07A494
/* 0AEFEC 7F07A47C AFAB0044 */   sw    $t3, 0x44($sp)
.Ljp7F07A480:
/* 0AEFF0 7F07A480 10000004 */  b     .Ljp7F07A494
/* 0AEFF4 7F07A484 AFAA0044 */   sw    $t2, 0x44($sp)
.Ljp7F07A488:
/* 0AEFF8 7F07A488 10000002 */  b     .Ljp7F07A494
/* 0AEFFC 7F07A48C AFAC0044 */   sw    $t4, 0x44($sp)
.Ljp7F07A490:
/* 0AF000 7F07A490 AFB90044 */  sw    $t9, 0x44($sp)
.Ljp7F07A494:
/* 0AF004 7F07A494 1040000C */  beqz  $v0, .Ljp7F07A4C8
/* 0AF008 7F07A498 2C610009 */   sltiu $at, $v1, 9
/* 0AF00C 7F07A49C 24010001 */  li    $at, 1
/* 0AF010 7F07A4A0 10410025 */  beq   $v0, $at, .Ljp7F07A538
/* 0AF014 7F07A4A4 2418004E */   li    $t8, 78
/* 0AF018 7F07A4A8 24010002 */  li    $at, 2
/* 0AF01C 7F07A4AC 10410024 */  beq   $v0, $at, .Ljp7F07A540
/* 0AF020 7F07A4B0 240D004E */   li    $t5, 78
/* 0AF024 7F07A4B4 24010003 */  li    $at, 3
/* 0AF028 7F07A4B8 10410023 */  beq   $v0, $at, .Ljp7F07A548
/* 0AF02C 7F07A4BC 240E004E */   li    $t6, 78
/* 0AF030 7F07A4C0 1000002C */  b     .Ljp7F07A574
/* 0AF034 7F07A4C4 00000000 */   nop
.Ljp7F07A4C8:
/* 0AF038 7F07A4C8 1020002A */  beqz  $at, .Ljp7F07A574
/* 0AF03C 7F07A4CC 0003C080 */   sll   $t8, $v1, 2
/* 0AF040 7F07A4D0 3C018005 */  lui   $at, %hi(jpt_bondhead)
/* 0AF044 7F07A4D4 00380821 */  addu  $at, $at, $t8
/* 0AF048 7F07A4D8 8C385038 */  lw    $t8, %lo(jpt_bondhead)($at)
/* 0AF04C 7F07A4DC 03000008 */  jr    $t8
/* 0AF050 7F07A4E0 00000000 */   nop
boiler_bond_head_set:
/* 0AF054 7F07A4E4 240D004A */  li    $t5, 74
/* 0AF058 7F07A4E8 10000022 */  b     .Ljp7F07A574
/* 0AF05C 7F07A4EC AFAD0040 */   sw    $t5, 0x40($sp)
jungle_head_set:
/* 0AF060 7F07A4F0 240E004C */  li    $t6, 76
/* 0AF064 7F07A4F4 1000001F */  b     .Ljp7F07A574
/* 0AF068 7F07A4F8 AFAE0040 */   sw    $t6, 0x40($sp)
brosnan_tux_head_set:
/* 0AF06C 7F07A4FC 240F004E */  li    $t7, 78
/* 0AF070 7F07A500 1000001C */  b     .Ljp7F07A574
/* 0AF074 7F07A504 AFAF0040 */   sw    $t7, 0x40($sp)
connery_head_set:
/* 0AF078 7F07A508 240B004E */  li    $t3, 78
/* 0AF07C 7F07A50C 10000019 */  b     .Ljp7F07A574
/* 0AF080 7F07A510 AFAB0040 */   sw    $t3, 0x40($sp)
moore_head_set:
/* 0AF084 7F07A514 240A004E */  li    $t2, 78
/* 0AF088 7F07A518 10000016 */  b     .Ljp7F07A574
/* 0AF08C 7F07A51C AFAA0040 */   sw    $t2, 0x40($sp)
dalton_head_set:
/* 0AF090 7F07A520 240C004E */  li    $t4, 78
/* 0AF094 7F07A524 10000013 */  b     .Ljp7F07A574
/* 0AF098 7F07A528 AFAC0040 */   sw    $t4, 0x40($sp)
variable_body_head:
/* 0AF09C 7F07A52C 2419004E */  li    $t9, 78
/* 0AF0A0 7F07A530 10000010 */  b     .Ljp7F07A574
/* 0AF0A4 7F07A534 AFB90040 */   sw    $t9, 0x40($sp)
.Ljp7F07A538:
/* 0AF0A8 7F07A538 1000000E */  b     .Ljp7F07A574
/* 0AF0AC 7F07A53C AFB80040 */   sw    $t8, 0x40($sp)
.Ljp7F07A540:
/* 0AF0B0 7F07A540 1000000C */  b     .Ljp7F07A574
/* 0AF0B4 7F07A544 AFAD0040 */   sw    $t5, 0x40($sp)
.Ljp7F07A548:
/* 0AF0B8 7F07A548 1000000A */  b     .Ljp7F07A574
/* 0AF0BC 7F07A54C AFAE0040 */   sw    $t6, 0x40($sp)
.Ljp7F07A550:
/* 0AF0C0 7F07A550 0FC26F3C */  jal   get_cur_playernum
/* 0AF0C4 7F07A554 00000000 */   nop
/* 0AF0C8 7F07A558 0FC040BF */  jal   get_player_mp_char_head
/* 0AF0CC 7F07A55C 00402025 */   move  $a0, $v0
/* 0AF0D0 7F07A560 0FC26F3C */  jal   get_cur_playernum
/* 0AF0D4 7F07A564 AFA20040 */   sw    $v0, 0x40($sp)
/* 0AF0D8 7F07A568 0FC040E7 */  jal   get_player_mp_char_body
/* 0AF0DC 7F07A56C 00402025 */   move  $a0, $v0
/* 0AF0E0 7F07A570 AFA20044 */  sw    $v0, 0x44($sp)
.Ljp7F07A574:
/* 0AF0E4 7F07A574 3C0F8003 */  lui   $t7, %hi(g_CameraMode) # $t7, 0x8003
/* 0AF0E8 7F07A578 8DEF64D4 */  lw    $t7, %lo(g_CameraMode)($t7)
/* 0AF0EC 7F07A57C 24010003 */  li    $at, 3
/* 0AF0F0 7F07A580 15E10003 */  bne   $t7, $at, .Ljp7F07A590
/* 0AF0F4 7F07A584 3C0B8008 */   lui   $t3, %hi(starting_right_weapon) # $t3, 0x8008
/* 0AF0F8 7F07A588 8D6B9A20 */  lw    $t3, %lo(starting_right_weapon)($t3)
/* 0AF0FC 7F07A58C AFAB0048 */  sw    $t3, 0x48($sp)
.Ljp7F07A590:
/* 0AF100 7F07A590 0FC26C01 */  jal   getPlayerCount
/* 0AF104 7F07A594 00000000 */   nop
/* 0AF108 7F07A598 24010001 */  li    $at, 1
/* 0AF10C 7F07A59C 14410082 */  bne   $v0, $at, .Ljp7F07A7A8
/* 0AF110 7F07A5A0 8FAF0044 */   lw    $t7, 0x44($sp)
/* 0AF114 7F07A5A4 0FC1751F */  jal   remove_item_in_hand
/* 0AF118 7F07A5A8 24040001 */   li    $a0, 1
/* 0AF11C 7F07A5AC 0FC1751F */  jal   remove_item_in_hand
/* 0AF120 7F07A5B0 00002025 */   move  $a0, $zero
/* 0AF124 7F07A5B4 27A40100 */  addiu $a0, $sp, 0x100
/* 0AF128 7F07A5B8 8FA500EC */  lw    $a1, 0xec($sp)
/* 0AF12C 7F07A5BC 0FC331F5 */  jal   texInitPool
/* 0AF130 7F07A5C0 8FA600E0 */   lw    $a2, 0xe0($sp)
/* 0AF134 7F07A5C4 0FC1750E */  jal   get_ptr_itemheader_in_hand
/* 0AF138 7F07A5C8 00002025 */   move  $a0, $zero
/* 0AF13C 7F07A5CC 8FAA0044 */  lw    $t2, 0x44($sp)
/* 0AF140 7F07A5D0 3C198004 */  lui   $t9, %hi(c_item_entries) # $t9, 0x8004
/* 0AF144 7F07A5D4 2739DE40 */  addiu $t9, %lo(c_item_entries) # addiu $t9, $t9, -0x21c0
/* 0AF148 7F07A5D8 000A6080 */  sll   $t4, $t2, 2
/* 0AF14C 7F07A5DC 018A6021 */  addu  $t4, $t4, $t2
/* 0AF150 7F07A5E0 000C6080 */  sll   $t4, $t4, 2
/* 0AF154 7F07A5E4 01991821 */  addu  $v1, $t4, $t9
/* 0AF158 7F07A5E8 8C780000 */  lw    $t8, ($v1)
/* 0AF15C 7F07A5EC AFA200FC */  sw    $v0, 0xfc($sp)
/* 0AF160 7F07A5F0 27AB0100 */  addiu $t3, $sp, 0x100
/* 0AF164 7F07A5F4 8F010000 */  lw    $at, ($t8)
/* 0AF168 7F07A5F8 00402025 */  move  $a0, $v0
/* 0AF16C 7F07A5FC AC410000 */  sw    $at, ($v0)
/* 0AF170 7F07A600 8F0F0004 */  lw    $t7, 4($t8)
/* 0AF174 7F07A604 AC4F0004 */  sw    $t7, 4($v0)
/* 0AF178 7F07A608 8F010008 */  lw    $at, 8($t8)
/* 0AF17C 7F07A60C AC410008 */  sw    $at, 8($v0)
/* 0AF180 7F07A610 8F0F000C */  lw    $t7, 0xc($t8)
/* 0AF184 7F07A614 AC4F000C */  sw    $t7, 0xc($v0)
/* 0AF188 7F07A618 8F010010 */  lw    $at, 0x10($t8)
/* 0AF18C 7F07A61C AC410010 */  sw    $at, 0x10($v0)
/* 0AF190 7F07A620 8F0F0014 */  lw    $t7, 0x14($t8)
/* 0AF194 7F07A624 AC4F0014 */  sw    $t7, 0x14($v0)
/* 0AF198 7F07A628 8F010018 */  lw    $at, 0x18($t8)
/* 0AF19C 7F07A62C AC410018 */  sw    $at, 0x18($v0)
/* 0AF1A0 7F07A630 8F0F001C */  lw    $t7, 0x1c($t8)
/* 0AF1A4 7F07A634 AC4F001C */  sw    $t7, 0x1c($v0)
/* 0AF1A8 7F07A638 AFA30028 */  sw    $v1, 0x28($sp)
/* 0AF1AC 7F07A63C AFAB0010 */  sw    $t3, 0x10($sp)
/* 0AF1B0 7F07A640 8FA700E4 */  lw    $a3, 0xe4($sp)
/* 0AF1B4 7F07A644 8FA600F0 */  lw    $a2, 0xf0($sp)
/* 0AF1B8 7F07A648 0FC1DAA5 */  jal   load_object_fill_header
/* 0AF1BC 7F07A64C 8C650004 */   lw    $a1, 4($v1)
/* 0AF1C0 7F07A650 8FA30028 */  lw    $v1, 0x28($sp)
/* 0AF1C4 7F07A654 0FC2F74E */  jal   get_pc_buffer_remaining_value
/* 0AF1C8 7F07A658 8C640004 */   lw    $a0, 4($v1)
/* 0AF1CC 7F07A65C 8FAD0040 */  lw    $t5, 0x40($sp)
/* 0AF1D0 7F07A660 3C0F8004 */  lui   $t7, %hi(c_item_entries) # $t7, 0x8004
/* 0AF1D4 7F07A664 25EFDE40 */  addiu $t7, %lo(c_item_entries) # addiu $t7, $t7, -0x21c0
/* 0AF1D8 7F07A668 000DC080 */  sll   $t8, $t5, 2
/* 0AF1DC 7F07A66C 030DC021 */  addu  $t8, $t8, $t5
/* 0AF1E0 7F07A670 0018C080 */  sll   $t8, $t8, 2
/* 0AF1E4 7F07A674 030F1821 */  addu  $v1, $t8, $t7
/* 0AF1E8 7F07A678 8C6B0000 */  lw    $t3, ($v1)
/* 0AF1EC 7F07A67C 2448003F */  addiu $t0, $v0, 0x3f
/* 0AF1F0 7F07A680 8FA900F0 */  lw    $t1, 0xf0($sp)
/* 0AF1F4 7F07A684 350A003F */  ori   $t2, $t0, 0x3f
/* 0AF1F8 7F07A688 8D610000 */  lw    $at, ($t3)
/* 0AF1FC 7F07A68C 394C003F */  xori  $t4, $t2, 0x3f
/* 0AF200 7F07A690 2588005F */  addiu $t0, $t4, 0x5f
/* 0AF204 7F07A694 3519003F */  ori   $t9, $t0, 0x3f
/* 0AF208 7F07A698 012C2021 */  addu  $a0, $t1, $t4
/* 0AF20C 7F07A69C 3B28003F */  xori  $t0, $t9, 0x3f
/* 0AF210 7F07A6A0 AC810000 */  sw    $at, ($a0)
/* 0AF214 7F07A6A4 8D790004 */  lw    $t9, 4($t3)
/* 0AF218 7F07A6A8 27AD0100 */  addiu $t5, $sp, 0x100
/* 0AF21C 7F07A6AC 01283021 */  addu  $a2, $t1, $t0
/* 0AF220 7F07A6B0 AC990004 */  sw    $t9, 4($a0)
/* 0AF224 7F07A6B4 8D610008 */  lw    $at, 8($t3)
/* 0AF228 7F07A6B8 AC810008 */  sw    $at, 8($a0)
/* 0AF22C 7F07A6BC 8D79000C */  lw    $t9, 0xc($t3)
/* 0AF230 7F07A6C0 AC99000C */  sw    $t9, 0xc($a0)
/* 0AF234 7F07A6C4 8D610010 */  lw    $at, 0x10($t3)
/* 0AF238 7F07A6C8 AC810010 */  sw    $at, 0x10($a0)
/* 0AF23C 7F07A6CC 8D790014 */  lw    $t9, 0x14($t3)
/* 0AF240 7F07A6D0 AC990014 */  sw    $t9, 0x14($a0)
/* 0AF244 7F07A6D4 8D610018 */  lw    $at, 0x18($t3)
/* 0AF248 7F07A6D8 AC810018 */  sw    $at, 0x18($a0)
/* 0AF24C 7F07A6DC 8D79001C */  lw    $t9, 0x1c($t3)
/* 0AF250 7F07A6E0 AC99001C */  sw    $t9, 0x1c($a0)
/* 0AF254 7F07A6E4 8FAE00E4 */  lw    $t6, 0xe4($sp)
/* 0AF258 7F07A6E8 AFA800E8 */  sw    $t0, 0xe8($sp)
/* 0AF25C 7F07A6EC AFA400F8 */  sw    $a0, 0xf8($sp)
/* 0AF260 7F07A6F0 AFA30028 */  sw    $v1, 0x28($sp)
/* 0AF264 7F07A6F4 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0AF268 7F07A6F8 8C650004 */  lw    $a1, 4($v1)
/* 0AF26C 7F07A6FC 0FC1DAA5 */  jal   load_object_fill_header
/* 0AF270 7F07A700 01C83823 */   subu  $a3, $t6, $t0
/* 0AF274 7F07A704 8FA30028 */  lw    $v1, 0x28($sp)
/* 0AF278 7F07A708 0FC2F74E */  jal   get_pc_buffer_remaining_value
/* 0AF27C 7F07A70C 8C640004 */   lw    $a0, 4($v1)
/* 0AF280 7F07A710 8FA300E8 */  lw    $v1, 0xe8($sp)
/* 0AF284 7F07A714 8FAC00F0 */  lw    $t4, 0xf0($sp)
/* 0AF288 7F07A718 8FA400FC */  lw    $a0, 0xfc($sp)
/* 0AF28C 7F07A71C 00431821 */  addu  $v1, $v0, $v1
/* 0AF290 7F07A720 2463003F */  addiu $v1, $v1, 0x3f
/* 0AF294 7F07A724 3478003F */  ori   $t8, $v1, 0x3f
/* 0AF298 7F07A728 3B0F003F */  xori  $t7, $t8, 0x3f
/* 0AF29C 7F07A72C 25E300FB */  addiu $v1, $t7, 0xfb
/* 0AF2A0 7F07A730 346B003F */  ori   $t3, $v1, 0x3f
/* 0AF2A4 7F07A734 3979003F */  xori  $t9, $t3, 0x3f
/* 0AF2A8 7F07A738 018F5021 */  addu  $t2, $t4, $t7
/* 0AF2AC 7F07A73C AFAA0038 */  sw    $t2, 0x38($sp)
/* 0AF2B0 7F07A740 0FC1D8B9 */  jal   modelCalculateRwDataLen
/* 0AF2B4 7F07A744 AFB900E8 */   sw    $t9, 0xe8($sp)
/* 0AF2B8 7F07A748 0FC1D8B9 */  jal   modelCalculateRwDataLen
/* 0AF2BC 7F07A74C 8FA400F8 */   lw    $a0, 0xf8($sp)
/* 0AF2C0 7F07A750 8FA500FC */  lw    $a1, 0xfc($sp)
/* 0AF2C4 7F07A754 8FAF00F8 */  lw    $t7, 0xf8($sp)
/* 0AF2C8 7F07A758 8FA300E8 */  lw    $v1, 0xe8($sp)
/* 0AF2CC 7F07A75C 84B80014 */  lh    $t8, 0x14($a1)
/* 0AF2D0 7F07A760 85EC0014 */  lh    $t4, 0x14($t7)
/* 0AF2D4 7F07A764 8FAE00F0 */  lw    $t6, 0xf0($sp)
/* 0AF2D8 7F07A768 8FA40038 */  lw    $a0, 0x38($sp)
/* 0AF2DC 7F07A76C 030C1021 */  addu  $v0, $t8, $t4
/* 0AF2E0 7F07A770 2442000A */  addiu $v0, $v0, 0xa
/* 0AF2E4 7F07A774 00025080 */  sll   $t2, $v0, 2
/* 0AF2E8 7F07A778 01C33021 */  addu  $a2, $t6, $v1
/* 0AF2EC 7F07A77C 01431821 */  addu  $v1, $t2, $v1
/* 0AF2F0 7F07A780 2463003F */  addiu $v1, $v1, 0x3f
/* 0AF2F4 7F07A784 346B003F */  ori   $t3, $v1, 0x3f
/* 0AF2F8 7F07A788 3979003F */  xori  $t9, $t3, 0x3f
/* 0AF2FC 7F07A78C AFB900E8 */  sw    $t9, 0xe8($sp)
/* 0AF300 7F07A790 0FC1D967 */  jal   animInit
/* 0AF304 7F07A794 AFA20030 */   sw    $v0, 0x30($sp)
/* 0AF308 7F07A798 8FA20030 */  lw    $v0, 0x30($sp)
/* 0AF30C 7F07A79C 8FAE0038 */  lw    $t6, 0x38($sp)
/* 0AF310 7F07A7A0 10000026 */  b     .Ljp7F07A83C
/* 0AF314 7F07A7A4 A5C20002 */   sh    $v0, 2($t6)
.Ljp7F07A7A8:
/* 0AF318 7F07A7A8 000FC080 */  sll   $t8, $t7, 2
/* 0AF31C 7F07A7AC 030FC021 */  addu  $t8, $t8, $t7
/* 0AF320 7F07A7B0 3C0C8004 */  lui   $t4, %hi(c_item_entries) # $t4, 0x8004
/* 0AF324 7F07A7B4 258CDE40 */  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21c0
/* 0AF328 7F07A7B8 0018C080 */  sll   $t8, $t8, 2
/* 0AF32C 7F07A7BC 030C1821 */  addu  $v1, $t8, $t4
/* 0AF330 7F07A7C0 8C6A0000 */  lw    $t2, ($v1)
/* 0AF334 7F07A7C4 AFAA00FC */  sw    $t2, 0xfc($sp)
/* 0AF338 7F07A7C8 8D590000 */  lw    $t9, ($t2)
/* 0AF33C 7F07A7CC 01402025 */  move  $a0, $t2
/* 0AF340 7F07A7D0 57200006 */  bnezl $t9, .Ljp7F07A7EC
/* 0AF344 7F07A7D4 906D0011 */   lbu   $t5, 0x11($v1)
/* 0AF348 7F07A7D8 8C650004 */  lw    $a1, 4($v1)
/* 0AF34C 7F07A7DC 0FC1DACF */  jal   fileLoad
/* 0AF350 7F07A7E0 AFA30028 */   sw    $v1, 0x28($sp)
/* 0AF354 7F07A7E4 8FA30028 */  lw    $v1, 0x28($sp)
/* 0AF358 7F07A7E8 906D0011 */  lbu   $t5, 0x11($v1)
.Ljp7F07A7EC:
/* 0AF35C 7F07A7EC 8FAF0040 */  lw    $t7, 0x40($sp)
/* 0AF360 7F07A7F0 3C0C8004 */  lui   $t4, %hi(c_item_entries) # $t4, 0x8004
/* 0AF364 7F07A7F4 11A00005 */  beqz  $t5, .Ljp7F07A80C
/* 0AF368 7F07A7F8 000FC080 */   sll   $t8, $t7, 2
/* 0AF36C 7F07A7FC 240EFFFF */  li    $t6, -1
/* 0AF370 7F07A800 AFAE0040 */  sw    $t6, 0x40($sp)
/* 0AF374 7F07A804 1000000D */  b     .Ljp7F07A83C
/* 0AF378 7F07A808 AFA000F8 */   sw    $zero, 0xf8($sp)
.Ljp7F07A80C:
/* 0AF37C 7F07A80C 030FC021 */  addu  $t8, $t8, $t7
/* 0AF380 7F07A810 0018C080 */  sll   $t8, $t8, 2
/* 0AF384 7F07A814 258CDE40 */  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21c0
/* 0AF388 7F07A818 030C1821 */  addu  $v1, $t8, $t4
/* 0AF38C 7F07A81C 8C640000 */  lw    $a0, ($v1)
/* 0AF390 7F07A820 AFA400F8 */  sw    $a0, 0xf8($sp)
/* 0AF394 7F07A824 8C8A0000 */  lw    $t2, ($a0)
/* 0AF398 7F07A828 55400005 */  bnezl $t2, .Ljp7F07A840
/* 0AF39C 7F07A82C 8FB90038 */   lw    $t9, 0x38($sp)
/* 0AF3A0 7F07A830 8C650004 */  lw    $a1, 4($v1)
/* 0AF3A4 7F07A834 0FC1DACF */  jal   fileLoad
/* 0AF3A8 7F07A838 AFA400F8 */   sw    $a0, 0xf8($sp)
.Ljp7F07A83C:
/* 0AF3AC 7F07A83C 8FB90038 */  lw    $t9, 0x38($sp)
.Ljp7F07A840:
/* 0AF3B0 7F07A840 8FA40044 */  lw    $a0, 0x44($sp)
/* 0AF3B4 7F07A844 8FA50040 */  lw    $a1, 0x40($sp)
/* 0AF3B8 7F07A848 8FA600FC */  lw    $a2, 0xfc($sp)
/* 0AF3BC 7F07A84C 8FA700F8 */  lw    $a3, 0xf8($sp)
/* 0AF3C0 7F07A850 AFA00010 */  sw    $zero, 0x10($sp)
/* 0AF3C4 7F07A854 0FC08D76 */  jal   makeonebody
/* 0AF3C8 7F07A858 AFB90014 */   sw    $t9, 0x14($sp)
/* 0AF3CC 7F07A85C 3C038008 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8008
/* 0AF3D0 7F07A860 2463A120 */  addiu $v1, %lo(g_CurrentPlayer) # addiu $v1, $v1, -0x5ee0
/* 0AF3D4 7F07A864 8C6B0000 */  lw    $t3, ($v1)
/* 0AF3D8 7F07A868 3C018005 */  lui   $at, %hi(D_8005502C) # $at, 0x8005
/* 0AF3DC 7F07A86C AD6200D4 */  sw    $v0, 0xd4($t3)
/* 0AF3E0 7F07A870 8C6D0000 */  lw    $t5, ($v1)
/* 0AF3E4 7F07A874 C426505C */  lwc1  $f6, %lo(D_8005502C)($at)
/* 0AF3E8 7F07A878 8DA400D4 */  lw    $a0, 0xd4($t5)
/* 0AF3EC 7F07A87C C4840014 */  lwc1  $f4, 0x14($a0)
/* 0AF3F0 7F07A880 46062202 */  mul.s $f8, $f4, $f6
/* 0AF3F4 7F07A884 44054000 */  mfc1  $a1, $f8
/* 0AF3F8 7F07A888 0FC1B51A */  jal   modelSetScale
/* 0AF3FC 7F07A88C 00000000 */   nop
/* 0AF400 7F07A890 3C038008 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8008
/* 0AF404 7F07A894 8C63A120 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0AF408 7F07A898 8FA70114 */  lw    $a3, 0x114($sp)
/* 0AF40C 7F07A89C 8C6400A8 */  lw    $a0, 0xa8($v1)
/* 0AF410 7F07A8A0 8C6500D4 */  lw    $a1, 0xd4($v1)
/* 0AF414 7F07A8A4 8C8E0014 */  lw    $t6, 0x14($a0)
/* 0AF418 7F07A8A8 AFA00014 */  sw    $zero, 0x14($sp)
/* 0AF41C 7F07A8AC 24860008 */  addiu $a2, $a0, 8
/* 0AF420 7F07A8B0 0FC0809B */  jal   init_GUARDdata_with_set_values
/* 0AF424 7F07A8B4 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0AF428 7F07A8B8 3C078008 */  lui   $a3, %hi(g_CurrentPlayer) # $a3, 0x8008
/* 0AF42C 7F07A8BC 24E7A120 */  addiu $a3, %lo(g_CurrentPlayer) # addiu $a3, $a3, -0x5ee0
/* 0AF430 7F07A8C0 8CF80000 */  lw    $t8, ($a3)
/* 0AF434 7F07A8C4 240F0006 */  li    $t7, 6
/* 0AF438 7F07A8C8 8F0C00A8 */  lw    $t4, 0xa8($t8)
/* 0AF43C 7F07A8CC A18F0000 */  sb    $t7, ($t4)
/* 0AF440 7F07A8D0 8CEA0000 */  lw    $t2, ($a3)
/* 0AF444 7F07A8D4 8D5900A8 */  lw    $t9, 0xa8($t2)
/* 0AF448 7F07A8D8 8F260004 */  lw    $a2, 4($t9)
/* 0AF44C 7F07A8DC 8CCB0014 */  lw    $t3, 0x14($a2)
/* 0AF450 7F07A8E0 356D0001 */  ori   $t5, $t3, 1
/* 0AF454 7F07A8E4 ACCD0014 */  sw    $t5, 0x14($a2)
/* 0AF458 7F07A8E8 8CE30000 */  lw    $v1, ($a3)
/* 0AF45C 7F07A8EC 8C6500A8 */  lw    $a1, 0xa8($v1)
/* 0AF460 7F07A8F0 8C6400D4 */  lw    $a0, 0xd4($v1)
/* 0AF464 7F07A8F4 AFA60110 */  sw    $a2, 0x110($sp)
/* 0AF468 7F07A8F8 0FC1B47F */  jal   setsuboffset
/* 0AF46C 7F07A8FC 24A50008 */   addiu $a1, $a1, 8
/* 0AF470 7F07A900 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8008
/* 0AF474 7F07A904 8DCEA120 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0AF478 7F07A908 8FA50114 */  lw    $a1, 0x114($sp)
/* 0AF47C 7F07A90C 0FC1B4CB */  jal   setsubroty
/* 0AF480 7F07A910 8DC400D4 */   lw    $a0, 0xd4($t6)
/* 0AF484 7F07A914 8FA20110 */  lw    $v0, 0x110($sp)
/* 0AF488 7F07A918 8FB80040 */  lw    $t8, 0x40($sp)
/* 0AF48C 7F07A91C A0580006 */  sb    $t8, 6($v0)
/* 0AF490 7F07A920 8FAF0044 */  lw    $t7, 0x44($sp)
/* 0AF494 7F07A924 A04F000F */  sb    $t7, 0xf($v0)
/* 0AF498 7F07A928 0FC26F79 */  jal   getPropForHeldItem
/* 0AF49C 7F07A92C 8FA40048 */   lw    $a0, 0x48($sp)
/* 0AF4A0 7F07A930 04400045 */  bltz  $v0, .Ljp7F07AA48
/* 0AF4A4 7F07A934 AFA2004C */   sw    $v0, 0x4c($sp)
/* 0AF4A8 7F07A938 0FC26C01 */  jal   getPlayerCount
/* 0AF4AC 7F07A93C 00000000 */   nop
/* 0AF4B0 7F07A940 24010001 */  li    $at, 1
/* 0AF4B4 7F07A944 14410035 */  bne   $v0, $at, .Ljp7F07AA1C
/* 0AF4B8 7F07A948 8FAC00F0 */   lw    $t4, 0xf0($sp)
/* 0AF4BC 7F07A94C 8FA200E8 */  lw    $v0, 0xe8($sp)
/* 0AF4C0 7F07A950 24040001 */  li    $a0, 1
/* 0AF4C4 7F07A954 01825021 */  addu  $t2, $t4, $v0
/* 0AF4C8 7F07A958 244200C7 */  addiu $v0, $v0, 0xc7
/* 0AF4CC 7F07A95C 3459003F */  ori   $t9, $v0, 0x3f
/* 0AF4D0 7F07A960 3B2B003F */  xori  $t3, $t9, 0x3f
/* 0AF4D4 7F07A964 AFAA00DC */  sw    $t2, 0xdc($sp)
/* 0AF4D8 7F07A968 0FC1750E */  jal   get_ptr_itemheader_in_hand
/* 0AF4DC 7F07A96C AFAB00E8 */   sw    $t3, 0xe8($sp)
/* 0AF4E0 7F07A970 8FAD004C */  lw    $t5, 0x4c($sp)
/* 0AF4E4 7F07A974 3C188004 */  lui   $t8, %hi(PitemZ_entries) # $t8, 0x8004
/* 0AF4E8 7F07A978 2718A258 */  addiu $t8, %lo(PitemZ_entries) # addiu $t8, $t8, -0x5da8
/* 0AF4EC 7F07A97C 000D7080 */  sll   $t6, $t5, 2
/* 0AF4F0 7F07A980 01CD7023 */  subu  $t6, $t6, $t5
/* 0AF4F4 7F07A984 000E7080 */  sll   $t6, $t6, 2
/* 0AF4F8 7F07A988 01D81821 */  addu  $v1, $t6, $t8
/* 0AF4FC 7F07A98C 8C6F0000 */  lw    $t7, ($v1)
/* 0AF500 7F07A990 AFA200F4 */  sw    $v0, 0xf4($sp)
/* 0AF504 7F07A994 27AA0100 */  addiu $t2, $sp, 0x100
/* 0AF508 7F07A998 8DE10000 */  lw    $at, ($t7)
/* 0AF50C 7F07A99C 00402025 */  move  $a0, $v0
/* 0AF510 7F07A9A0 AC410000 */  sw    $at, ($v0)
/* 0AF514 7F07A9A4 8DF90004 */  lw    $t9, 4($t7)
/* 0AF518 7F07A9A8 AC590004 */  sw    $t9, 4($v0)
/* 0AF51C 7F07A9AC 8DE10008 */  lw    $at, 8($t7)
/* 0AF520 7F07A9B0 AC410008 */  sw    $at, 8($v0)
/* 0AF524 7F07A9B4 8DF9000C */  lw    $t9, 0xc($t7)
/* 0AF528 7F07A9B8 AC59000C */  sw    $t9, 0xc($v0)
/* 0AF52C 7F07A9BC 8DE10010 */  lw    $at, 0x10($t7)
/* 0AF530 7F07A9C0 AC410010 */  sw    $at, 0x10($v0)
/* 0AF534 7F07A9C4 8DF90014 */  lw    $t9, 0x14($t7)
/* 0AF538 7F07A9C8 AC590014 */  sw    $t9, 0x14($v0)
/* 0AF53C 7F07A9CC 8DE10018 */  lw    $at, 0x18($t7)
/* 0AF540 7F07A9D0 AC410018 */  sw    $at, 0x18($v0)
/* 0AF544 7F07A9D4 8DF9001C */  lw    $t9, 0x1c($t7)
/* 0AF548 7F07A9D8 AC59001C */  sw    $t9, 0x1c($v0)
/* 0AF54C 7F07A9DC 8FAD00E8 */  lw    $t5, 0xe8($sp)
/* 0AF550 7F07A9E0 8FAE00E4 */  lw    $t6, 0xe4($sp)
/* 0AF554 7F07A9E4 8FAB00F0 */  lw    $t3, 0xf0($sp)
/* 0AF558 7F07A9E8 AFA30028 */  sw    $v1, 0x28($sp)
/* 0AF55C 7F07A9EC AFAA0010 */  sw    $t2, 0x10($sp)
/* 0AF560 7F07A9F0 8C650004 */  lw    $a1, 4($v1)
/* 0AF564 7F07A9F4 01CD3823 */  subu  $a3, $t6, $t5
/* 0AF568 7F07A9F8 0FC1DAA5 */  jal   load_object_fill_header
/* 0AF56C 7F07A9FC 016D3021 */   addu  $a2, $t3, $t5
/* 0AF570 7F07AA00 8FA30028 */  lw    $v1, 0x28($sp)
/* 0AF574 7F07AA04 0FC2F74E */  jal   get_pc_buffer_remaining_value
/* 0AF578 7F07AA08 8C640004 */   lw    $a0, 4($v1)
/* 0AF57C 7F07AA0C 0FC1D8B9 */  jal   modelCalculateRwDataLen
/* 0AF580 7F07AA10 8FA400F4 */   lw    $a0, 0xf4($sp)
/* 0AF584 7F07AA14 10000004 */  b     .Ljp7F07AA28
/* 0AF588 7F07AA18 8FAC00DC */   lw    $t4, 0xdc($sp)
.Ljp7F07AA1C:
/* 0AF58C 7F07AA1C AFA000DC */  sw    $zero, 0xdc($sp)
/* 0AF590 7F07AA20 AFA000F4 */  sw    $zero, 0xf4($sp)
/* 0AF594 7F07AA24 8FAC00DC */  lw    $t4, 0xdc($sp)
.Ljp7F07AA28:
/* 0AF598 7F07AA28 8FAF00F4 */  lw    $t7, 0xf4($sp)
/* 0AF59C 7F07AA2C 8FA40110 */  lw    $a0, 0x110($sp)
/* 0AF5A0 7F07AA30 8FA5004C */  lw    $a1, 0x4c($sp)
/* 0AF5A4 7F07AA34 8FA60048 */  lw    $a2, 0x48($sp)
/* 0AF5A8 7F07AA38 00003825 */  move  $a3, $zero
/* 0AF5AC 7F07AA3C AFAC0010 */  sw    $t4, 0x10($sp)
/* 0AF5B0 7F07AA40 0FC149C4 */  jal   something_with_generating_object
/* 0AF5B4 7F07AA44 AFAF0014 */   sw    $t7, 0x14($sp)
.Ljp7F07AA48:
/* 0AF5B8 7F07AA48 8FA40110 */  lw    $a0, 0x110($sp)
/* 0AF5BC 7F07AA4C 0FC08F65 */  jal   chrlvIdleAnimationRelated7F023A94
/* 0AF5C0 7F07AA50 24050000 */   li    $a1, 0
/* 0AF5C4 7F07AA54 10000017 */  b     .Ljp7F07AAB4
/* 0AF5C8 7F07AA58 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0AF5CC 7F07AA5C 8C59001C */  lw    $t9, 0x1c($v0)
.Ljp7F07AA60:
/* 0AF5D0 7F07AA60 00402025 */  move  $a0, $v0
/* 0AF5D4 7F07AA64 8F2B0020 */  lw    $t3, 0x20($t9)
/* 0AF5D8 7F07AA68 55600012 */  bnezl $t3, .Ljp7F07AAB4
/* 0AF5DC 7F07AA6C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0AF5E0 7F07AA70 8C4D0014 */  lw    $t5, 0x14($v0)
/* 0AF5E4 7F07AA74 24050000 */  li    $a1, 0
/* 0AF5E8 7F07AA78 35AE0001 */  ori   $t6, $t5, 1
/* 0AF5EC 7F07AA7C 0FC08F65 */  jal   chrlvIdleAnimationRelated7F023A94
/* 0AF5F0 7F07AA80 AC4E0014 */   sw    $t6, 0x14($v0)
/* 0AF5F4 7F07AA84 3C038008 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8008
/* 0AF5F8 7F07AA88 8C63A120 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0AF5FC 7F07AA8C 8C6500A8 */  lw    $a1, 0xa8($v1)
/* 0AF600 7F07AA90 8C6400D4 */  lw    $a0, 0xd4($v1)
/* 0AF604 7F07AA94 0FC1B47F */  jal   setsuboffset
/* 0AF608 7F07AA98 24A50008 */   addiu $a1, $a1, 8
/* 0AF60C 7F07AA9C 3C188008 */  lui   $t8, %hi(g_CurrentPlayer) # $t8, 0x8008
/* 0AF610 7F07AAA0 8F18A120 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0AF614 7F07AAA4 8FA50114 */  lw    $a1, 0x114($sp)
/* 0AF618 7F07AAA8 0FC1B4CB */  jal   setsubroty
/* 0AF61C 7F07AAAC 8F0400D4 */   lw    $a0, 0xd4($t8)
/* 0AF620 7F07AAB0 8FBF001C */  lw    $ra, 0x1c($sp)
.Ljp7F07AAB4:
/* 0AF624 7F07AAB4 27BD0118 */  addiu $sp, $sp, 0x118
/* 0AF628 7F07AAB8 03E00008 */  jr    $ra
/* 0AF62C 7F07AABC 00000000 */   nop
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80054FB8
.word 0
glabel D_80054FBC
.word 0

/*D:80054FC0*/
glabel a8s
/*"%8s"*/
.word 0x25387300

glabel aX4_0f
/*"x %4.0f"*/
.word 0x78202534
.word 0x2E306600

glabel aY4_0f
/*"y %4.0f"*/
.word 0x79202534
.word 0x2E306600

glabel aZ4_0f
/*"z %4.0f"*/
.word 0x7A202534
.word 0x2E306600

glabel aS3d
/*"%s %3d"*/
.word 0x25732025
.word 0x33640000
/*D:80054FE4*/
glabel jpt_bondcuff
.word .L7F079EA4
.word cuff_1_brosnan
.word cuff_2_jungle
.word cuff_3_boiler
.word cuff_4_snowsuit
.word cuff_5_connery
.word cuff_6_moore
.word cuff_7_dalton
.word cuff_8_variable_bond_head

/*D:80055008*/
glabel jpt_bondhead
.word .L7F079F84
.word brosnan_tux_head_set
.word jungle_head_set
.word boiler_bond_head_set
.word .L7F079F84
.word connery_head_set
.word moore_head_set
.word dalton_head_set
.word variable_body_head

glabel D_8005502C
.word 0x3f7851ec /*0.97000003*/
.text
glabel solo_char_load
/* 0AC760 7F079D70 27BDFEE8 */  addiu $sp, $sp, -0x118
/* 0AC764 7F079D74 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0AC768 7F079D78 0FC2282C */  jal   get_curplay_horizontal_rotation_in_degrees
/* 0AC76C 7F079D7C 00000000 */   nop
/* 0AC770 7F079D80 3C0E8007 */  lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8007
/* 0AC774 7F079D84 8DCE8BC0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0AC778 7F079D88 E7A00114 */  swc1  $f0, 0x114($sp)
/* 0AC77C 7F079D8C 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0AC780 7F079D90 8DE20004 */  lw    $v0, 4($t7)
/* 0AC784 7F079D94 544001D0 */  bnezl $v0, .L7F07A4D8
/* 0AC788 7F079D98 8C59001C */   lw    $t9, 0x1c($v0)
/* 0AC78C 7F079D9C 0FC174FA */  jal   getPlayerWeaponBufferForHand
/* 0AC790 7F079DA0 00002025 */   move  $a0, $zero
/* 0AC794 7F079DA4 AFA200F0 */  sw    $v0, 0xf0($sp)
/* 0AC798 7F079DA8 0FC174FA */  jal   getPlayerWeaponBufferForHand
/* 0AC79C 7F079DAC 24040001 */   li    $a0, 1
/* 0AC7A0 7F079DB0 AFA200EC */  sw    $v0, 0xec($sp)
/* 0AC7A4 7F079DB4 AFA000E8 */  sw    $zero, 0xe8($sp)
/* 0AC7A8 7F079DB8 0FC17500 */  jal   getSizeBufferWeaponInHand
/* 0AC7AC 7F079DBC 00002025 */   move  $a0, $zero
/* 0AC7B0 7F079DC0 AFA200E4 */  sw    $v0, 0xe4($sp)
/* 0AC7B4 7F079DC4 0FC17500 */  jal   getSizeBufferWeaponInHand
/* 0AC7B8 7F079DC8 24040001 */   li    $a0, 1
/* 0AC7BC 7F079DCC 3C198003 */  lui   $t9, %hi(dummy_08_pp7_obj) # $t9, 0x8003
/* 0AC7C0 7F079DD0 27391AFC */  addiu $t9, %lo(dummy_08_pp7_obj) # addiu $t9, $t9, 0x1afc
/* 0AC7C4 7F079DD4 AFA200E0 */  sw    $v0, 0xe0($sp)
/* 0AC7C8 7F079DD8 272C0084 */  addiu $t4, $t9, 0x84
/* 0AC7CC 7F079DDC 27B80054 */  addiu $t8, $sp, 0x54
.L7F079DE0:
/* 0AC7D0 7F079DE0 8F210000 */  lw    $at, ($t9)
/* 0AC7D4 7F079DE4 2739000C */  addiu $t9, $t9, 0xc
/* 0AC7D8 7F079DE8 2718000C */  addiu $t8, $t8, 0xc
/* 0AC7DC 7F079DEC AF01FFF4 */  sw    $at, -0xc($t8)
/* 0AC7E0 7F079DF0 8F21FFF8 */  lw    $at, -8($t9)
/* 0AC7E4 7F079DF4 AF01FFF8 */  sw    $at, -8($t8)
/* 0AC7E8 7F079DF8 8F21FFFC */  lw    $at, -4($t9)
/* 0AC7EC 7F079DFC 172CFFF8 */  bne   $t9, $t4, .L7F079DE0
/* 0AC7F0 7F079E00 AF01FFFC */   sw    $at, -4($t8)
/* 0AC7F4 7F079E04 8F210000 */  lw    $at, ($t9)
/* 0AC7F8 7F079E08 00002025 */  move  $a0, $zero
/* 0AC7FC 7F079E0C 0FC177BF */  jal   get_item_in_hand_or_watch_menu
/* 0AC800 7F079E10 AF010000 */   sw    $at, ($t8)
/* 0AC804 7F079E14 240D0017 */  li    $t5, 23
/* 0AC808 7F079E18 240E004B */  li    $t6, 75
/* 0AC80C 7F079E1C 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0AC810 7F079E20 AFA20048 */  sw    $v0, 0x48($sp)
/* 0AC814 7F079E24 AFAD0044 */  sw    $t5, 0x44($sp)
/* 0AC818 7F079E28 AFAE0040 */  sw    $t6, 0x40($sp)
/* 0AC81C 7F079E2C AFA00038 */  sw    $zero, 0x38($sp)
/* 0AC820 7F079E30 0FC1F7CE */  jal   sub_GAME_7F07DE64
/* 0AC824 7F079E34 8C848BC0 */   lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0AC828 7F079E38 0FC26669 */  jal   getPlayerCount
/* 0AC82C 7F079E3C 00000000 */   nop
/* 0AC830 7F079E40 24010001 */  li    $at, 1
/* 0AC834 7F079E44 14410066 */  bne   $v0, $at, .L7F079FE0
/* 0AC838 7F079E48 00000000 */   nop
/* 0AC83C 7F079E4C 0FC074F0 */  jal   getSelectedFolderBond
/* 0AC840 7F079E50 00000000 */   nop
/* 0AC844 7F079E54 3C0F8007 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8007
/* 0AC848 7F079E58 8DEF8BC0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0AC84C 7F079E5C 8DE3041C */  lw    $v1, 0x41c($t7)
/* 0AC850 7F079E60 2C610009 */  sltiu $at, $v1, 9
/* 0AC854 7F079E64 1020002F */  beqz  $at, .L7F079F24
/* 0AC858 7F079E68 00035880 */   sll   $t3, $v1, 2
/* 0AC85C 7F079E6C 3C018005 */  lui   $at, %hi(jpt_bondcuff)
/* 0AC860 7F079E70 002B0821 */  addu  $at, $at, $t3
/* 0AC864 7F079E74 8C2BABB4 */  lw    $t3, %lo(jpt_bondcuff)($at)
/* 0AC868 7F079E78 01600008 */  jr    $t3
/* 0AC86C 7F079E7C 00000000 */   nop
cuff_3_boiler:
/* 0AC870 7F079E80 240A0016 */  li    $t2, 22
/* 0AC874 7F079E84 10000027 */  b     .L7F079F24
/* 0AC878 7F079E88 AFAA0044 */   sw    $t2, 0x44($sp)
cuff_2_jungle:
/* 0AC87C 7F079E8C 240C0018 */  li    $t4, 24
/* 0AC880 7F079E90 10000024 */  b     .L7F079F24
/* 0AC884 7F079E94 AFAC0044 */   sw    $t4, 0x44($sp)
cuff_4_snowsuit:
/* 0AC888 7F079E98 24190019 */  li    $t9, 25
/* 0AC88C 7F079E9C 10000021 */  b     .L7F079F24
/* 0AC890 7F079EA0 AFB90044 */   sw    $t9, 0x44($sp)
cuff_1_brosnan:
/* 0AC894 7F079EA4 24180005 */  li    $t8, 5
/* 0AC898 7F079EA8 1000001E */  b     .L7F079F24
/* 0AC89C 7F079EAC AFB80044 */   sw    $t8, 0x44($sp)
cuff_5_connery:
/* 0AC8A0 7F079EB0 240D0005 */  li    $t5, 5
/* 0AC8A4 7F079EB4 1000001B */  b     .L7F079F24
/* 0AC8A8 7F079EB8 AFAD0044 */   sw    $t5, 0x44($sp)
cuff_6_moore:
/* 0AC8AC 7F079EBC 240E0005 */  li    $t6, 5
/* 0AC8B0 7F079EC0 10000018 */  b     .L7F079F24
/* 0AC8B4 7F079EC4 AFAE0044 */   sw    $t6, 0x44($sp)
cuff_7_dalton:
/* 0AC8B8 7F079EC8 240F0005 */  li    $t7, 5
/* 0AC8BC 7F079ECC 10000015 */  b     .L7F079F24
/* 0AC8C0 7F079ED0 AFAF0044 */   sw    $t7, 0x44($sp)
cuff_8_variable_bond_head:
/* 0AC8C4 7F079ED4 1040000C */  beqz  $v0, .L7F079F08
/* 0AC8C8 7F079ED8 240B0005 */   li    $t3, 5
/* 0AC8CC 7F079EDC 24010001 */  li    $at, 1
/* 0AC8D0 7F079EE0 1041000B */  beq   $v0, $at, .L7F079F10
/* 0AC8D4 7F079EE4 240A0005 */   li    $t2, 5
/* 0AC8D8 7F079EE8 24010002 */  li    $at, 2
/* 0AC8DC 7F079EEC 1041000A */  beq   $v0, $at, .L7F079F18
/* 0AC8E0 7F079EF0 240C0005 */   li    $t4, 5
/* 0AC8E4 7F079EF4 24010003 */  li    $at, 3
/* 0AC8E8 7F079EF8 10410009 */  beq   $v0, $at, .L7F079F20
/* 0AC8EC 7F079EFC 24190005 */   li    $t9, 5
/* 0AC8F0 7F079F00 10000008 */  b     .L7F079F24
/* 0AC8F4 7F079F04 00000000 */   nop
.L7F079F08:
/* 0AC8F8 7F079F08 10000006 */  b     .L7F079F24
/* 0AC8FC 7F079F0C AFAB0044 */   sw    $t3, 0x44($sp)
.L7F079F10:
/* 0AC900 7F079F10 10000004 */  b     .L7F079F24
/* 0AC904 7F079F14 AFAA0044 */   sw    $t2, 0x44($sp)
.L7F079F18:
/* 0AC908 7F079F18 10000002 */  b     .L7F079F24
/* 0AC90C 7F079F1C AFAC0044 */   sw    $t4, 0x44($sp)
.L7F079F20:
/* 0AC910 7F079F20 AFB90044 */  sw    $t9, 0x44($sp)
.L7F079EA4:
.L7F079F24:
/* 0AC914 7F079F24 1040000C */  beqz  $v0, .L7F079F58
/* 0AC918 7F079F28 2C610009 */   sltiu $at, $v1, 9
/* 0AC91C 7F079F2C 24010001 */  li    $at, 1
/* 0AC920 7F079F30 10410025 */  beq   $v0, $at, .L7F079FC8
/* 0AC924 7F079F34 2418004E */   li    $t8, 78
/* 0AC928 7F079F38 24010002 */  li    $at, 2
/* 0AC92C 7F079F3C 10410024 */  beq   $v0, $at, .L7F079FD0
/* 0AC930 7F079F40 240D004E */   li    $t5, 78
/* 0AC934 7F079F44 24010003 */  li    $at, 3
/* 0AC938 7F079F48 10410023 */  beq   $v0, $at, .L7F079FD8
/* 0AC93C 7F079F4C 240E004E */   li    $t6, 78
/* 0AC940 7F079F50 1000002C */  b     .L7F07A004
/* 0AC944 7F079F54 00000000 */   nop
.L7F079F58:
/* 0AC948 7F079F58 1020002A */  beqz  $at, .L7F07A004
/* 0AC94C 7F079F5C 0003C080 */   sll   $t8, $v1, 2
/* 0AC950 7F079F60 3C018005 */  lui   $at, %hi(jpt_bondhead)
/* 0AC954 7F079F64 00380821 */  addu  $at, $at, $t8
/* 0AC958 7F079F68 8C38ABD8 */  lw    $t8, %lo(jpt_bondhead)($at)
/* 0AC95C 7F079F6C 03000008 */  jr    $t8
/* 0AC960 7F079F70 00000000 */   nop
boiler_bond_head_set:
/* 0AC964 7F079F74 240D004A */  li    $t5, 74
/* 0AC968 7F079F78 10000022 */  b     .L7F07A004
/* 0AC96C 7F079F7C AFAD0040 */   sw    $t5, 0x40($sp)
jungle_head_set:
/* 0AC970 7F079F80 240E004C */  li    $t6, 76
/* 0AC974 7F079F84 1000001F */  b     .L7F07A004
/* 0AC978 7F079F88 AFAE0040 */   sw    $t6, 0x40($sp)
brosnan_tux_head_set:
/* 0AC97C 7F079F8C 240F004E */  li    $t7, 78
/* 0AC980 7F079F90 1000001C */  b     .L7F07A004
/* 0AC984 7F079F94 AFAF0040 */   sw    $t7, 0x40($sp)
connery_head_set:
/* 0AC988 7F079F98 240B004E */  li    $t3, 78
/* 0AC98C 7F079F9C 10000019 */  b     .L7F07A004
/* 0AC990 7F079FA0 AFAB0040 */   sw    $t3, 0x40($sp)
moore_head_set:
/* 0AC994 7F079FA4 240A004E */  li    $t2, 78
/* 0AC998 7F079FA8 10000016 */  b     .L7F07A004
/* 0AC99C 7F079FAC AFAA0040 */   sw    $t2, 0x40($sp)
dalton_head_set:
/* 0AC9A0 7F079FB0 240C004E */  li    $t4, 78
/* 0AC9A4 7F079FB4 10000013 */  b     .L7F07A004
/* 0AC9A8 7F079FB8 AFAC0040 */   sw    $t4, 0x40($sp)
variable_body_head:
/* 0AC9AC 7F079FBC 2419004E */  li    $t9, 78
/* 0AC9B0 7F079FC0 10000010 */  b     .L7F07A004
/* 0AC9B4 7F079FC4 AFB90040 */   sw    $t9, 0x40($sp)
.L7F079FC8:
/* 0AC9B8 7F079FC8 1000000E */  b     .L7F07A004
/* 0AC9BC 7F079FCC AFB80040 */   sw    $t8, 0x40($sp)
.L7F079FD0:
/* 0AC9C0 7F079FD0 1000000C */  b     .L7F07A004
/* 0AC9C4 7F079FD4 AFAD0040 */   sw    $t5, 0x40($sp)
.L7F079FD8:
/* 0AC9C8 7F079FD8 1000000A */  b     .L7F07A004
/* 0AC9CC 7F079FDC AFAE0040 */   sw    $t6, 0x40($sp)
.L7F079FE0:
/* 0AC9D0 7F079FE0 0FC269A4 */  jal   get_cur_playernum
/* 0AC9D4 7F079FE4 00000000 */   nop
/* 0AC9D8 7F079FE8 0FC0406B */  jal   get_player_mp_char_head
/* 0AC9DC 7F079FEC 00402025 */   move  $a0, $v0
/* 0AC9E0 7F079FF0 0FC269A4 */  jal   get_cur_playernum
/* 0AC9E4 7F079FF4 AFA20040 */   sw    $v0, 0x40($sp)
/* 0AC9E8 7F079FF8 0FC04093 */  jal   get_player_mp_char_body
/* 0AC9EC 7F079FFC 00402025 */   move  $a0, $v0
/* 0AC9F0 7F07A000 AFA20044 */  sw    $v0, 0x44($sp)
.L7F079F84:
.L7F07A004:
/* 0AC9F4 7F07A004 3C0F8003 */  lui   $t7, %hi(g_CameraMode) # $t7, 0x8003
/* 0AC9F8 7F07A008 8DEF19E4 */  lw    $t7, %lo(g_CameraMode)($t7)
/* 0AC9FC 7F07A00C 24010003 */  li    $at, 3
/* 0ACA00 7F07A010 15E10003 */  bne   $t7, $at, .L7F07A020
/* 0ACA04 7F07A014 3C0B8007 */   lui   $t3, %hi(starting_right_weapon) # $t3, 0x8007
/* 0ACA08 7F07A018 8D6B84C0 */  lw    $t3, %lo(starting_right_weapon)($t3)
/* 0ACA0C 7F07A01C AFAB0048 */  sw    $t3, 0x48($sp)
.L7F07A020:
/* 0ACA10 7F07A020 0FC26669 */  jal   getPlayerCount
/* 0ACA14 7F07A024 00000000 */   nop
/* 0ACA18 7F07A028 24010001 */  li    $at, 1
/* 0ACA1C 7F07A02C 1441007E */  bne   $v0, $at, .L7F07A228
/* 0ACA20 7F07A030 8FAF0044 */   lw    $t7, 0x44($sp)
/* 0ACA24 7F07A034 0FC17505 */  jal   remove_item_in_hand
/* 0ACA28 7F07A038 24040001 */   li    $a0, 1
/* 0ACA2C 7F07A03C 0FC17505 */  jal   remove_item_in_hand
/* 0ACA30 7F07A040 00002025 */   move  $a0, $zero
/* 0ACA34 7F07A044 27A40100 */  addiu $a0, $sp, 0x100
/* 0ACA38 7F07A048 8FA500EC */  lw    $a1, 0xec($sp)
/* 0ACA3C 7F07A04C 0FC32C05 */  jal   texInitPool
/* 0ACA40 7F07A050 8FA600E0 */   lw    $a2, 0xe0($sp)
/* 0ACA44 7F07A054 0FC174F2 */  jal   get_ptr_itemheader_in_hand
/* 0ACA48 7F07A058 00002025 */   move  $a0, $zero
/* 0ACA4C 7F07A05C 8FAA0044 */  lw    $t2, 0x44($sp)
/* 0ACA50 7F07A060 3C198003 */  lui   $t9, %hi(c_item_entries) # $t9, 0x8003
/* 0ACA54 7F07A064 27397A60 */  addiu $t9, %lo(c_item_entries) # addiu $t9, $t9, 0x7a60
/* 0ACA58 7F07A068 000A6080 */  sll   $t4, $t2, 2
/* 0ACA5C 7F07A06C 018A6021 */  addu  $t4, $t4, $t2
/* 0ACA60 7F07A070 000C6080 */  sll   $t4, $t4, 2
/* 0ACA64 7F07A074 01991821 */  addu  $v1, $t4, $t9
/* 0ACA68 7F07A078 8C780000 */  lw    $t8, ($v1)
/* 0ACA6C 7F07A07C AFA200FC */  sw    $v0, 0xfc($sp)
/* 0ACA70 7F07A080 27AB0100 */  addiu $t3, $sp, 0x100
/* 0ACA74 7F07A084 8F010000 */  lw    $at, ($t8)
/* 0ACA78 7F07A088 00402025 */  move  $a0, $v0
/* 0ACA7C 7F07A08C AC410000 */  sw    $at, ($v0)
/* 0ACA80 7F07A090 8F0F0004 */  lw    $t7, 4($t8)
/* 0ACA84 7F07A094 AC4F0004 */  sw    $t7, 4($v0)
/* 0ACA88 7F07A098 8F010008 */  lw    $at, 8($t8)
/* 0ACA8C 7F07A09C AC410008 */  sw    $at, 8($v0)
/* 0ACA90 7F07A0A0 8F0F000C */  lw    $t7, 0xc($t8)
/* 0ACA94 7F07A0A4 AC4F000C */  sw    $t7, 0xc($v0)
/* 0ACA98 7F07A0A8 8F010010 */  lw    $at, 0x10($t8)
/* 0ACA9C 7F07A0AC AC410010 */  sw    $at, 0x10($v0)
/* 0ACAA0 7F07A0B0 8F0F0014 */  lw    $t7, 0x14($t8)
/* 0ACAA4 7F07A0B4 AC4F0014 */  sw    $t7, 0x14($v0)
/* 0ACAA8 7F07A0B8 8F010018 */  lw    $at, 0x18($t8)
/* 0ACAAC 7F07A0BC AC410018 */  sw    $at, 0x18($v0)
/* 0ACAB0 7F07A0C0 AFA30028 */  sw    $v1, 0x28($sp)
/* 0ACAB4 7F07A0C4 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0ACAB8 7F07A0C8 8FA700E4 */  lw    $a3, 0xe4($sp)
/* 0ACABC 7F07A0CC 8FA600F0 */  lw    $a2, 0xf0($sp)
/* 0ACAC0 7F07A0D0 0FC1D949 */  jal   load_object_fill_header
/* 0ACAC4 7F07A0D4 8C650004 */   lw    $a1, 4($v1)
/* 0ACAC8 7F07A0D8 8FA30028 */  lw    $v1, 0x28($sp)
/* 0ACACC 7F07A0DC 0FC2F150 */  jal   get_pc_buffer_remaining_value
/* 0ACAD0 7F07A0E0 8C640004 */   lw    $a0, 4($v1)
/* 0ACAD4 7F07A0E4 8FAD0040 */  lw    $t5, 0x40($sp)
/* 0ACAD8 7F07A0E8 3C0F8003 */  lui   $t7, %hi(c_item_entries) # $t7, 0x8003
/* 0ACADC 7F07A0EC 25EF7A60 */  addiu $t7, %lo(c_item_entries) # addiu $t7, $t7, 0x7a60
/* 0ACAE0 7F07A0F0 000DC080 */  sll   $t8, $t5, 2
/* 0ACAE4 7F07A0F4 030DC021 */  addu  $t8, $t8, $t5
/* 0ACAE8 7F07A0F8 0018C080 */  sll   $t8, $t8, 2
/* 0ACAEC 7F07A0FC 030F1821 */  addu  $v1, $t8, $t7
/* 0ACAF0 7F07A100 8C6B0000 */  lw    $t3, ($v1)
/* 0ACAF4 7F07A104 2448003F */  addiu $t0, $v0, 0x3f
/* 0ACAF8 7F07A108 8FA900F0 */  lw    $t1, 0xf0($sp)
/* 0ACAFC 7F07A10C 350A003F */  ori   $t2, $t0, 0x3f
/* 0ACB00 7F07A110 8D610000 */  lw    $at, ($t3)
/* 0ACB04 7F07A114 394C003F */  xori  $t4, $t2, 0x3f
/* 0ACB08 7F07A118 2588005B */  addiu $t0, $t4, 0x5b
/* 0ACB0C 7F07A11C 3519003F */  ori   $t9, $t0, 0x3f
/* 0ACB10 7F07A120 012C2021 */  addu  $a0, $t1, $t4
/* 0ACB14 7F07A124 3B28003F */  xori  $t0, $t9, 0x3f
/* 0ACB18 7F07A128 AC810000 */  sw    $at, ($a0)
/* 0ACB1C 7F07A12C 8D790004 */  lw    $t9, 4($t3)
/* 0ACB20 7F07A130 27AD0100 */  addiu $t5, $sp, 0x100
/* 0ACB24 7F07A134 01283021 */  addu  $a2, $t1, $t0
/* 0ACB28 7F07A138 AC990004 */  sw    $t9, 4($a0)
/* 0ACB2C 7F07A13C 8D610008 */  lw    $at, 8($t3)
/* 0ACB30 7F07A140 AC810008 */  sw    $at, 8($a0)
/* 0ACB34 7F07A144 8D79000C */  lw    $t9, 0xc($t3)
/* 0ACB38 7F07A148 AC99000C */  sw    $t9, 0xc($a0)
/* 0ACB3C 7F07A14C 8D610010 */  lw    $at, 0x10($t3)
/* 0ACB40 7F07A150 AC810010 */  sw    $at, 0x10($a0)
/* 0ACB44 7F07A154 8D790014 */  lw    $t9, 0x14($t3)
/* 0ACB48 7F07A158 AC990014 */  sw    $t9, 0x14($a0)
/* 0ACB4C 7F07A15C 8D610018 */  lw    $at, 0x18($t3)
/* 0ACB50 7F07A160 AC810018 */  sw    $at, 0x18($a0)
/* 0ACB54 7F07A164 8FAE00E4 */  lw    $t6, 0xe4($sp)
/* 0ACB58 7F07A168 AFA800E8 */  sw    $t0, 0xe8($sp)
/* 0ACB5C 7F07A16C AFA400F8 */  sw    $a0, 0xf8($sp)
/* 0ACB60 7F07A170 AFA30028 */  sw    $v1, 0x28($sp)
/* 0ACB64 7F07A174 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0ACB68 7F07A178 8C650004 */  lw    $a1, 4($v1)
/* 0ACB6C 7F07A17C 0FC1D949 */  jal   load_object_fill_header
/* 0ACB70 7F07A180 01C83823 */   subu  $a3, $t6, $t0
/* 0ACB74 7F07A184 8FA30028 */  lw    $v1, 0x28($sp)
/* 0ACB78 7F07A188 0FC2F150 */  jal   get_pc_buffer_remaining_value
/* 0ACB7C 7F07A18C 8C640004 */   lw    $a0, 4($v1)
/* 0ACB80 7F07A190 8FA300E8 */  lw    $v1, 0xe8($sp)
/* 0ACB84 7F07A194 8FAC00F0 */  lw    $t4, 0xf0($sp)
/* 0ACB88 7F07A198 8FA400FC */  lw    $a0, 0xfc($sp)
/* 0ACB8C 7F07A19C 00431821 */  addu  $v1, $v0, $v1
/* 0ACB90 7F07A1A0 2463003F */  addiu $v1, $v1, 0x3f
/* 0ACB94 7F07A1A4 3478003F */  ori   $t8, $v1, 0x3f
/* 0ACB98 7F07A1A8 3B0F003F */  xori  $t7, $t8, 0x3f
/* 0ACB9C 7F07A1AC 25E300FB */  addiu $v1, $t7, 0xfb
/* 0ACBA0 7F07A1B0 346B003F */  ori   $t3, $v1, 0x3f
/* 0ACBA4 7F07A1B4 3979003F */  xori  $t9, $t3, 0x3f
/* 0ACBA8 7F07A1B8 018F5021 */  addu  $t2, $t4, $t7
/* 0ACBAC 7F07A1BC AFAA0038 */  sw    $t2, 0x38($sp)
/* 0ACBB0 7F07A1C0 0FC1D75F */  jal   modelCalculateRwDataLen
/* 0ACBB4 7F07A1C4 AFB900E8 */   sw    $t9, 0xe8($sp)
/* 0ACBB8 7F07A1C8 0FC1D75F */  jal   modelCalculateRwDataLen
/* 0ACBBC 7F07A1CC 8FA400F8 */   lw    $a0, 0xf8($sp)
/* 0ACBC0 7F07A1D0 8FA500FC */  lw    $a1, 0xfc($sp)
/* 0ACBC4 7F07A1D4 8FAF00F8 */  lw    $t7, 0xf8($sp)
/* 0ACBC8 7F07A1D8 8FA300E8 */  lw    $v1, 0xe8($sp)
/* 0ACBCC 7F07A1DC 84B80014 */  lh    $t8, 0x14($a1)
/* 0ACBD0 7F07A1E0 85EC0014 */  lh    $t4, 0x14($t7)
/* 0ACBD4 7F07A1E4 8FAE00F0 */  lw    $t6, 0xf0($sp)
/* 0ACBD8 7F07A1E8 8FA40038 */  lw    $a0, 0x38($sp)
/* 0ACBDC 7F07A1EC 030C1021 */  addu  $v0, $t8, $t4
/* 0ACBE0 7F07A1F0 2442000A */  addiu $v0, $v0, 0xa
/* 0ACBE4 7F07A1F4 00025080 */  sll   $t2, $v0, 2
/* 0ACBE8 7F07A1F8 01C33021 */  addu  $a2, $t6, $v1
/* 0ACBEC 7F07A1FC 01431821 */  addu  $v1, $t2, $v1
/* 0ACBF0 7F07A200 2463003F */  addiu $v1, $v1, 0x3f
/* 0ACBF4 7F07A204 346B003F */  ori   $t3, $v1, 0x3f
/* 0ACBF8 7F07A208 3979003F */  xori  $t9, $t3, 0x3f
/* 0ACBFC 7F07A20C AFB900E8 */  sw    $t9, 0xe8($sp)
/* 0ACC00 7F07A210 0FC1D80A */  jal   animInit
/* 0ACC04 7F07A214 AFA20030 */   sw    $v0, 0x30($sp)
/* 0ACC08 7F07A218 8FA20030 */  lw    $v0, 0x30($sp)
/* 0ACC0C 7F07A21C 8FAE0038 */  lw    $t6, 0x38($sp)
/* 0ACC10 7F07A220 10000026 */  b     .L7F07A2BC
/* 0ACC14 7F07A224 A5C20002 */   sh    $v0, 2($t6)
.L7F07A228:
/* 0ACC18 7F07A228 000FC080 */  sll   $t8, $t7, 2
/* 0ACC1C 7F07A22C 030FC021 */  addu  $t8, $t8, $t7
/* 0ACC20 7F07A230 3C0C8003 */  lui   $t4, %hi(c_item_entries) # $t4, 0x8003
/* 0ACC24 7F07A234 258C7A60 */  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, 0x7a60
/* 0ACC28 7F07A238 0018C080 */  sll   $t8, $t8, 2
/* 0ACC2C 7F07A23C 030C1821 */  addu  $v1, $t8, $t4
/* 0ACC30 7F07A240 8C6A0000 */  lw    $t2, ($v1)
/* 0ACC34 7F07A244 AFAA00FC */  sw    $t2, 0xfc($sp)
/* 0ACC38 7F07A248 8D590000 */  lw    $t9, ($t2)
/* 0ACC3C 7F07A24C 01402025 */  move  $a0, $t2
/* 0ACC40 7F07A250 57200006 */  bnezl $t9, .L7F07A26C
/* 0ACC44 7F07A254 906D0011 */   lbu   $t5, 0x11($v1)
/* 0ACC48 7F07A258 8C650004 */  lw    $a1, 4($v1)
/* 0ACC4C 7F07A25C 0FC1D973 */  jal   fileLoad
/* 0ACC50 7F07A260 AFA30028 */   sw    $v1, 0x28($sp)
/* 0ACC54 7F07A264 8FA30028 */  lw    $v1, 0x28($sp)
/* 0ACC58 7F07A268 906D0011 */  lbu   $t5, 0x11($v1)
.L7F07A26C:
/* 0ACC5C 7F07A26C 8FAF0040 */  lw    $t7, 0x40($sp)
/* 0ACC60 7F07A270 3C0C8003 */  lui   $t4, %hi(c_item_entries) # $t4, 0x8003
/* 0ACC64 7F07A274 11A00005 */  beqz  $t5, .L7F07A28C
/* 0ACC68 7F07A278 000FC080 */   sll   $t8, $t7, 2
/* 0ACC6C 7F07A27C 240EFFFF */  li    $t6, -1
/* 0ACC70 7F07A280 AFAE0040 */  sw    $t6, 0x40($sp)
/* 0ACC74 7F07A284 1000000D */  b     .L7F07A2BC
/* 0ACC78 7F07A288 AFA000F8 */   sw    $zero, 0xf8($sp)
.L7F07A28C:
/* 0ACC7C 7F07A28C 030FC021 */  addu  $t8, $t8, $t7
/* 0ACC80 7F07A290 0018C080 */  sll   $t8, $t8, 2
/* 0ACC84 7F07A294 258C7A60 */  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, 0x7a60
/* 0ACC88 7F07A298 030C1821 */  addu  $v1, $t8, $t4
/* 0ACC8C 7F07A29C 8C640000 */  lw    $a0, ($v1)
/* 0ACC90 7F07A2A0 AFA400F8 */  sw    $a0, 0xf8($sp)
/* 0ACC94 7F07A2A4 8C8A0000 */  lw    $t2, ($a0)
/* 0ACC98 7F07A2A8 55400005 */  bnezl $t2, .L7F07A2C0
/* 0ACC9C 7F07A2AC 8FB90038 */   lw    $t9, 0x38($sp)
/* 0ACCA0 7F07A2B0 8C650004 */  lw    $a1, 4($v1)
/* 0ACCA4 7F07A2B4 0FC1D973 */  jal   fileLoad
/* 0ACCA8 7F07A2B8 AFA400F8 */   sw    $a0, 0xf8($sp)
.L7F07A2BC:
/* 0ACCAC 7F07A2BC 8FB90038 */  lw    $t9, 0x38($sp)
.L7F07A2C0:
/* 0ACCB0 7F07A2C0 8FA40044 */  lw    $a0, 0x44($sp)
/* 0ACCB4 7F07A2C4 8FA50040 */  lw    $a1, 0x40($sp)
/* 0ACCB8 7F07A2C8 8FA600FC */  lw    $a2, 0xfc($sp)
/* 0ACCBC 7F07A2CC 8FA700F8 */  lw    $a3, 0xf8($sp)
/* 0ACCC0 7F07A2D0 AFA00010 */  sw    $zero, 0x10($sp)
/* 0ACCC4 7F07A2D4 0FC08CAE */  jal   makeonebody
/* 0ACCC8 7F07A2D8 AFB90014 */   sw    $t9, 0x14($sp)
/* 0ACCCC 7F07A2DC 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0ACCD0 7F07A2E0 24638BC0 */  addiu $v1, %lo(g_CurrentPlayer) # addiu $v1, $v1, -0x7440
/* 0ACCD4 7F07A2E4 8C6B0000 */  lw    $t3, ($v1)
/* 0ACCD8 7F07A2E8 3C018005 */  lui   $at, %hi(D_8005502C) # $at, 0x8005
/* 0ACCDC 7F07A2EC AD6200D4 */  sw    $v0, 0xd4($t3)
/* 0ACCE0 7F07A2F0 8C6D0000 */  lw    $t5, ($v1)
/* 0ACCE4 7F07A2F4 C426ABFC */  lwc1  $f6, %lo(D_8005502C)($at)
/* 0ACCE8 7F07A2F8 8DA400D4 */  lw    $a0, 0xd4($t5)
/* 0ACCEC 7F07A2FC C4840014 */  lwc1  $f4, 0x14($a0)
/* 0ACCF0 7F07A300 46062202 */  mul.s $f8, $f4, $f6
/* 0ACCF4 7F07A304 44054000 */  mfc1  $a1, $f8
/* 0ACCF8 7F07A308 0FC1B4CF */  jal   modelSetScale
/* 0ACCFC 7F07A30C 00000000 */   nop
/* 0ACD00 7F07A310 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0ACD04 7F07A314 8C638BC0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0ACD08 7F07A318 8FA70114 */  lw    $a3, 0x114($sp)
/* 0ACD0C 7F07A31C 8C6400A8 */  lw    $a0, 0xa8($v1)
/* 0ACD10 7F07A320 8C6500D4 */  lw    $a1, 0xd4($v1)
/* 0ACD14 7F07A324 8C8E0014 */  lw    $t6, 0x14($a0)
/* 0ACD18 7F07A328 AFA00014 */  sw    $zero, 0x14($sp)
/* 0ACD1C 7F07A32C 24860008 */  addiu $a2, $a0, 8
/* 0ACD20 7F07A330 0FC07FC7 */  jal   init_GUARDdata_with_set_values
/* 0ACD24 7F07A334 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0ACD28 7F07A338 3C078007 */  lui   $a3, %hi(g_CurrentPlayer) # $a3, 0x8007
/* 0ACD2C 7F07A33C 24E78BC0 */  addiu $a3, %lo(g_CurrentPlayer) # addiu $a3, $a3, -0x7440
/* 0ACD30 7F07A340 8CF80000 */  lw    $t8, ($a3)
/* 0ACD34 7F07A344 240F0006 */  li    $t7, 6
/* 0ACD38 7F07A348 8F0C00A8 */  lw    $t4, 0xa8($t8)
/* 0ACD3C 7F07A34C A18F0000 */  sb    $t7, ($t4)
/* 0ACD40 7F07A350 8CEA0000 */  lw    $t2, ($a3)
/* 0ACD44 7F07A354 8D5900A8 */  lw    $t9, 0xa8($t2)
/* 0ACD48 7F07A358 8F260004 */  lw    $a2, 4($t9)
/* 0ACD4C 7F07A35C 8CCB0014 */  lw    $t3, 0x14($a2)
/* 0ACD50 7F07A360 356D0001 */  ori   $t5, $t3, 1
/* 0ACD54 7F07A364 ACCD0014 */  sw    $t5, 0x14($a2)
/* 0ACD58 7F07A368 8CE30000 */  lw    $v1, ($a3)
/* 0ACD5C 7F07A36C 8C6500A8 */  lw    $a1, 0xa8($v1)
/* 0ACD60 7F07A370 8C6400D4 */  lw    $a0, 0xd4($v1)
/* 0ACD64 7F07A374 AFA60110 */  sw    $a2, 0x110($sp)
/* 0ACD68 7F07A378 0FC1B480 */  jal   setsuboffset
/* 0ACD6C 7F07A37C 24A50008 */   addiu $a1, $a1, 8
/* 0ACD70 7F07A380 3C0E8007 */  lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8007
/* 0ACD74 7F07A384 8DCE8BC0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0ACD78 7F07A388 8FA50114 */  lw    $a1, 0x114($sp)
/* 0ACD7C 7F07A38C 0FC1B49D */  jal   setsubroty
/* 0ACD80 7F07A390 8DC400D4 */   lw    $a0, 0xd4($t6)
/* 0ACD84 7F07A394 8FA20110 */  lw    $v0, 0x110($sp)
/* 0ACD88 7F07A398 8FB80040 */  lw    $t8, 0x40($sp)
/* 0ACD8C 7F07A39C A0580006 */  sb    $t8, 6($v0)
/* 0ACD90 7F07A3A0 8FAF0044 */  lw    $t7, 0x44($sp)
/* 0ACD94 7F07A3A4 A04F000F */  sb    $t7, 0xf($v0)
/* 0ACD98 7F07A3A8 0FC269E1 */  jal   getPropForHeldItem
/* 0ACD9C 7F07A3AC 8FA40048 */   lw    $a0, 0x48($sp)
/* 0ACDA0 7F07A3B0 04400043 */  bltz  $v0, .L7F07A4C0
/* 0ACDA4 7F07A3B4 AFA2004C */   sw    $v0, 0x4c($sp)
/* 0ACDA8 7F07A3B8 0FC26669 */  jal   getPlayerCount
/* 0ACDAC 7F07A3BC 00000000 */   nop
/* 0ACDB0 7F07A3C0 24010001 */  li    $at, 1
/* 0ACDB4 7F07A3C4 14410033 */  bne   $v0, $at, .L7F07A494
/* 0ACDB8 7F07A3C8 8FAC00F0 */   lw    $t4, 0xf0($sp)
/* 0ACDBC 7F07A3CC 8FA200E8 */  lw    $v0, 0xe8($sp)
/* 0ACDC0 7F07A3D0 24040001 */  li    $a0, 1
/* 0ACDC4 7F07A3D4 01825021 */  addu  $t2, $t4, $v0
/* 0ACDC8 7F07A3D8 244200C7 */  addiu $v0, $v0, 0xc7
/* 0ACDCC 7F07A3DC 3459003F */  ori   $t9, $v0, 0x3f
/* 0ACDD0 7F07A3E0 3B2B003F */  xori  $t3, $t9, 0x3f
/* 0ACDD4 7F07A3E4 AFAA00DC */  sw    $t2, 0xdc($sp)
/* 0ACDD8 7F07A3E8 0FC174F2 */  jal   get_ptr_itemheader_in_hand
/* 0ACDDC 7F07A3EC AFAB00E8 */   sw    $t3, 0xe8($sp)
/* 0ACDE0 7F07A3F0 8FAD004C */  lw    $t5, 0x4c($sp)
/* 0ACDE4 7F07A3F4 3C188003 */  lui   $t8, %hi(PitemZ_entries) # $t8, 0x8003
/* 0ACDE8 7F07A3F8 27184D88 */  addiu $t8, %lo(PitemZ_entries) # addiu $t8, $t8, 0x4d88
/* 0ACDEC 7F07A3FC 000D7080 */  sll   $t6, $t5, 2
/* 0ACDF0 7F07A400 01CD7023 */  subu  $t6, $t6, $t5
/* 0ACDF4 7F07A404 000E7080 */  sll   $t6, $t6, 2
/* 0ACDF8 7F07A408 01D81821 */  addu  $v1, $t6, $t8
/* 0ACDFC 7F07A40C 8C6F0000 */  lw    $t7, ($v1)
/* 0ACE00 7F07A410 AFA200F4 */  sw    $v0, 0xf4($sp)
/* 0ACE04 7F07A414 27AA0100 */  addiu $t2, $sp, 0x100
/* 0ACE08 7F07A418 8DE10000 */  lw    $at, ($t7)
/* 0ACE0C 7F07A41C 00402025 */  move  $a0, $v0
/* 0ACE10 7F07A420 AC410000 */  sw    $at, ($v0)
/* 0ACE14 7F07A424 8DF90004 */  lw    $t9, 4($t7)
/* 0ACE18 7F07A428 AC590004 */  sw    $t9, 4($v0)
/* 0ACE1C 7F07A42C 8DE10008 */  lw    $at, 8($t7)
/* 0ACE20 7F07A430 AC410008 */  sw    $at, 8($v0)
/* 0ACE24 7F07A434 8DF9000C */  lw    $t9, 0xc($t7)
/* 0ACE28 7F07A438 AC59000C */  sw    $t9, 0xc($v0)
/* 0ACE2C 7F07A43C 8DE10010 */  lw    $at, 0x10($t7)
/* 0ACE30 7F07A440 AC410010 */  sw    $at, 0x10($v0)
/* 0ACE34 7F07A444 8DF90014 */  lw    $t9, 0x14($t7)
/* 0ACE38 7F07A448 AC590014 */  sw    $t9, 0x14($v0)
/* 0ACE3C 7F07A44C 8DE10018 */  lw    $at, 0x18($t7)
/* 0ACE40 7F07A450 AC410018 */  sw    $at, 0x18($v0)
/* 0ACE44 7F07A454 8FAD00E8 */  lw    $t5, 0xe8($sp)
/* 0ACE48 7F07A458 8FAE00E4 */  lw    $t6, 0xe4($sp)
/* 0ACE4C 7F07A45C 8FAB00F0 */  lw    $t3, 0xf0($sp)
/* 0ACE50 7F07A460 AFA30028 */  sw    $v1, 0x28($sp)
/* 0ACE54 7F07A464 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0ACE58 7F07A468 8C650004 */  lw    $a1, 4($v1)
/* 0ACE5C 7F07A46C 01CD3823 */  subu  $a3, $t6, $t5
/* 0ACE60 7F07A470 0FC1D949 */  jal   load_object_fill_header
/* 0ACE64 7F07A474 016D3021 */   addu  $a2, $t3, $t5
/* 0ACE68 7F07A478 8FA30028 */  lw    $v1, 0x28($sp)
/* 0ACE6C 7F07A47C 0FC2F150 */  jal   get_pc_buffer_remaining_value
/* 0ACE70 7F07A480 8C640004 */   lw    $a0, 4($v1)
/* 0ACE74 7F07A484 0FC1D75F */  jal   modelCalculateRwDataLen
/* 0ACE78 7F07A488 8FA400F4 */   lw    $a0, 0xf4($sp)
/* 0ACE7C 7F07A48C 10000004 */  b     .L7F07A4A0
/* 0ACE80 7F07A490 8FAC00DC */   lw    $t4, 0xdc($sp)
.L7F07A494:
/* 0ACE84 7F07A494 AFA000DC */  sw    $zero, 0xdc($sp)
/* 0ACE88 7F07A498 AFA000F4 */  sw    $zero, 0xf4($sp)
/* 0ACE8C 7F07A49C 8FAC00DC */  lw    $t4, 0xdc($sp)
.L7F07A4A0:
/* 0ACE90 7F07A4A0 8FAF00F4 */  lw    $t7, 0xf4($sp)
/* 0ACE94 7F07A4A4 8FA40110 */  lw    $a0, 0x110($sp)
/* 0ACE98 7F07A4A8 8FA5004C */  lw    $a1, 0x4c($sp)
/* 0ACE9C 7F07A4AC 8FA60048 */  lw    $a2, 0x48($sp)
/* 0ACEA0 7F07A4B0 00003825 */  move  $a3, $zero
/* 0ACEA4 7F07A4B4 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0ACEA8 7F07A4B8 0FC1493D */  jal   something_with_generating_object
/* 0ACEAC 7F07A4BC AFAF0014 */   sw    $t7, 0x14($sp)
.L7F07A4C0:
/* 0ACEB0 7F07A4C0 8FA40110 */  lw    $a0, 0x110($sp)
/* 0ACEB4 7F07A4C4 0FC08E9D */  jal   chrlvIdleAnimationRelated7F023A94
/* 0ACEB8 7F07A4C8 24050000 */   li    $a1, 0
/* 0ACEBC 7F07A4CC 10000017 */  b     .L7F07A52C
/* 0ACEC0 7F07A4D0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0ACEC4 7F07A4D4 8C59001C */  lw    $t9, 0x1c($v0)
.L7F07A4D8:
/* 0ACEC8 7F07A4D8 00402025 */  move  $a0, $v0
/* 0ACECC 7F07A4DC 8F2B0020 */  lw    $t3, 0x20($t9)
/* 0ACED0 7F07A4E0 55600012 */  bnezl $t3, .L7F07A52C
/* 0ACED4 7F07A4E4 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0ACED8 7F07A4E8 8C4D0014 */  lw    $t5, 0x14($v0)
/* 0ACEDC 7F07A4EC 24050000 */  li    $a1, 0
/* 0ACEE0 7F07A4F0 35AE0001 */  ori   $t6, $t5, 1
/* 0ACEE4 7F07A4F4 0FC08E9D */  jal   chrlvIdleAnimationRelated7F023A94
/* 0ACEE8 7F07A4F8 AC4E0014 */   sw    $t6, 0x14($v0)
/* 0ACEEC 7F07A4FC 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0ACEF0 7F07A500 8C638BC0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0ACEF4 7F07A504 8C6500A8 */  lw    $a1, 0xa8($v1)
/* 0ACEF8 7F07A508 8C6400D4 */  lw    $a0, 0xd4($v1)
/* 0ACEFC 7F07A50C 0FC1B480 */  jal   setsuboffset
/* 0ACF00 7F07A510 24A50008 */   addiu $a1, $a1, 8
/* 0ACF04 7F07A514 3C188007 */  lui   $t8, %hi(g_CurrentPlayer) # $t8, 0x8007
/* 0ACF08 7F07A518 8F188BC0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0ACF0C 7F07A51C 8FA50114 */  lw    $a1, 0x114($sp)
/* 0ACF10 7F07A520 0FC1B49D */  jal   setsubroty
/* 0ACF14 7F07A524 8F0400D4 */   lw    $a0, 0xd4($t8)
/* 0ACF18 7F07A528 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F07A52C:
/* 0ACF1C 7F07A52C 27BD0118 */  addiu $sp, $sp, 0x118
/* 0ACF20 7F07A530 03E00008 */  jr    $ra
/* 0ACF24 7F07A534 00000000 */   nop
)
#endif


#endif

/**
 * Address 0x7F07A4A0.
 */
void maybe_solo_intro_camera_handler(void)
{
    if ((g_CurrentPlayer->prop->chr != 0) && (getPlayerCount() == 1))
    {
        disable_sounds_attached_to_player_then_something(g_CurrentPlayer->prop);
        g_CurrentPlayer->prop->chr = NULL;
        g_CurrentPlayer->ptr_char_objectinstance = 0;
        g_bondviewForceDisarm = 1;
        sub_GAME_7F07DE9C(g_CurrentPlayer);
    }
}




u32 get_camera_mode(void) {
    // Node 0
    return g_CameraMode;
}






#ifdef NONMATCHING
void sub_GAME_7F07A534(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80055030
.word 0x40c90fdb /*6.2831855*/
glabel D_80055034
.word 0x44bb8000 /*1500.0*/
glabel D_80055038
.word 0x40c90fdb /*6.2831855*/
glabel D_8005503C
.word 0x3ec90fdb /*0.39269909*/
glabel D_80055040
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F07A534
/* 0AF064 7F07A534 27BDFF20 */  addiu $sp, $sp, -0xe0
/* 0AF068 7F07A538 3C018008 */  lui   $at, %hi(dword_CODE_bss_800799F4)
/* 0AF06C 7F07A53C AC2499F4 */  sw    $a0, %lo(dword_CODE_bss_800799F4)($at)
/* 0AF070 7F07A540 F7BE0058 */  sdc1  $f30, 0x58($sp)
/* 0AF074 7F07A544 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AF078 7F07A548 AFB10064 */  sw    $s1, 0x64($sp)
/* 0AF07C 7F07A54C F7BA0048 */  sdc1  $f26, 0x48($sp)
/* 0AF080 7F07A550 4481F000 */  mtc1  $at, $f30
/* 0AF084 7F07A554 AFB7007C */  sw    $s7, 0x7c($sp)
/* 0AF088 7F07A558 AFB60078 */  sw    $s6, 0x78($sp)
/* 0AF08C 7F07A55C AFB50074 */  sw    $s5, 0x74($sp)
/* 0AF090 7F07A560 AFB40070 */  sw    $s4, 0x70($sp)
/* 0AF094 7F07A564 AFB3006C */  sw    $s3, 0x6c($sp)
/* 0AF098 7F07A568 AFB20068 */  sw    $s2, 0x68($sp)
/* 0AF09C 7F07A56C F7B40030 */  sdc1  $f20, 0x30($sp)
/* 0AF0A0 7F07A570 3C018005 */  lui   $at, %hi(D_80055030)
/* 0AF0A4 7F07A574 3C118008 */  lui   $s1, %hi(flt_CODE_bss_800799E8)
/* 0AF0A8 7F07A578 4480D000 */  mtc1  $zero, $f26
/* 0AF0AC 7F07A57C 00A09025 */  move  $s2, $a1
/* 0AF0B0 7F07A580 00E09825 */  move  $s3, $a3
/* 0AF0B4 7F07A584 00C0A025 */  move  $s4, $a2
/* 0AF0B8 7F07A588 AFBF0084 */  sw    $ra, 0x84($sp)
/* 0AF0BC 7F07A58C AFBE0080 */  sw    $fp, 0x80($sp)
/* 0AF0C0 7F07A590 AFB00060 */  sw    $s0, 0x60($sp)
/* 0AF0C4 7F07A594 F7BC0050 */  sdc1  $f28, 0x50($sp)
/* 0AF0C8 7F07A598 F7B80040 */  sdc1  $f24, 0x40($sp)
/* 0AF0CC 7F07A59C F7B60038 */  sdc1  $f22, 0x38($sp)
/* 0AF0D0 7F07A5A0 0000B025 */  move  $s6, $zero
/* 0AF0D4 7F07A5A4 AFA000D8 */  sw    $zero, 0xd8($sp)
/* 0AF0D8 7F07A5A8 263199E8 */  addiu $s1, %lo(flt_CODE_bss_800799E8) # addiu $s1, $s1, -0x6618
/* 0AF0DC 7F07A5AC C4345030 */  lwc1  $f20, %lo(D_80055030)($at)
/* 0AF0E0 7F07A5B0 27B500C8 */  addiu $s5, $sp, 0xc8
/* 0AF0E4 7F07A5B4 8FB700F0 */  lw    $s7, 0xf0($sp)
.L7F07A5B8:
/* 0AF0E8 7F07A5B8 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0AF0EC 7F07A5BC 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0AF0F0 7F07A5C0 3C018005 */  lui   $at, %hi(D_80055034)
/* 0AF0F4 7F07A5C4 C4245034 */  lwc1  $f4, %lo(D_80055034)($at)
/* 0AF0F8 7F07A5C8 C5DC04B0 */  lwc1  $f28, 0x4b0($t6)
/* 0AF0FC 7F07A5CC 0000F025 */  move  $fp, $zero
/* 0AF100 7F07A5D0 461C2180 */  add.s $f6, $f4, $f28
/* 0AF104 7F07A5D4 0C002914 */  jal   randomGetNext
/* 0AF108 7F07A5D8 E7A600D0 */   swc1  $f6, 0xd0($sp)
/* 0AF10C 7F07A5DC 44824000 */  mtc1  $v0, $f8
/* 0AF110 7F07A5E0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0AF114 7F07A5E4 04410004 */  bgez  $v0, .L7F07A5F8
/* 0AF118 7F07A5E8 468042A0 */   cvt.s.w $f10, $f8
/* 0AF11C 7F07A5EC 44818000 */  mtc1  $at, $f16
/* 0AF120 7F07A5F0 00000000 */  nop
/* 0AF124 7F07A5F4 46105280 */  add.s $f10, $f10, $f16
.L7F07A5F8:
/* 0AF128 7F07A5F8 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0AF12C 7F07A5FC 44819000 */  mtc1  $at, $f18
/* 0AF130 7F07A600 00000000 */  nop
/* 0AF134 7F07A604 46125102 */  mul.s $f4, $f10, $f18
/* 0AF138 7F07A608 00000000 */  nop
/* 0AF13C 7F07A60C 46142302 */  mul.s $f12, $f4, $f20
/* 0AF140 7F07A610 16C000CD */  bnez  $s6, .L7F07A948
/* 0AF144 7F07A614 00000000 */   nop
/* 0AF148 7F07A618 E7AC00CC */  swc1  $f12, 0xcc($sp)
.L7F07A61C:
/* 0AF14C 7F07A61C 3C018005 */  lui   $at, %hi(D_80055038)
/* 0AF150 7F07A620 C4345038 */  lwc1  $f20, %lo(D_80055038)($at)
/* 0AF154 7F07A624 3C018005 */  lui   $at, %hi(D_8005503C)
/* 0AF158 7F07A628 C7AC00CC */  lwc1  $f12, 0xcc($sp)
/* 0AF15C 7F07A62C C426503C */  lwc1  $f6, %lo(D_8005503C)($at)
/* 0AF160 7F07A630 46066300 */  add.s $f12, $f12, $f6
/* 0AF164 7F07A634 460CA03E */  c.le.s $f20, $f12
/* 0AF168 7F07A638 00000000 */  nop
/* 0AF16C 7F07A63C 45000002 */  bc1f  .L7F07A648
/* 0AF170 7F07A640 00000000 */   nop
/* 0AF174 7F07A644 46146301 */  sub.s $f12, $f12, $f20
.L7F07A648:
/* 0AF178 7F07A648 0FC15FAB */  jal   sinf
/* 0AF17C 7F07A64C E7AC00CC */   swc1  $f12, 0xcc($sp)
/* 0AF180 7F07A650 E7A000BC */  swc1  $f0, 0xbc($sp)
/* 0AF184 7F07A654 E7BA00C0 */  swc1  $f26, 0xc0($sp)
/* 0AF188 7F07A658 0FC15FA8 */  jal   cosf
/* 0AF18C 7F07A65C C7AC00CC */   lwc1  $f12, 0xcc($sp)
/* 0AF190 7F07A660 C7A800BC */  lwc1  $f8, 0xbc($sp)
/* 0AF194 7F07A664 C7B000D0 */  lwc1  $f16, 0xd0($sp)
/* 0AF198 7F07A668 E7A000C4 */  swc1  $f0, 0xc4($sp)
/* 0AF19C 7F07A66C C6520000 */  lwc1  $f18, ($s2)
/* 0AF1A0 7F07A670 46104282 */  mul.s $f10, $f8, $f16
/* 0AF1A4 7F07A674 C7A800C4 */  lwc1  $f8, 0xc4($sp)
/* 0AF1A8 7F07A678 46125100 */  add.s $f4, $f10, $f18
/* 0AF1AC 7F07A67C 46104282 */  mul.s $f10, $f8, $f16
/* 0AF1B0 7F07A680 E7A400B0 */  swc1  $f4, 0xb0($sp)
/* 0AF1B4 7F07A684 C6460004 */  lwc1  $f6, 4($s2)
/* 0AF1B8 7F07A688 E7A600B4 */  swc1  $f6, 0xb4($sp)
/* 0AF1BC 7F07A68C C6520008 */  lwc1  $f18, 8($s2)
/* 0AF1C0 7F07A690 46125100 */  add.s $f4, $f10, $f18
/* 0AF1C4 7F07A694 0FC2C731 */  jal   sub_GAME_7F0B1CC4
/* 0AF1C8 7F07A698 E7A400B8 */   swc1  $f4, 0xb8($sp)
/* 0AF1CC 7F07A69C AFB700C8 */  sw    $s7, 0xc8($sp)
/* 0AF1D0 7F07A6A0 02802025 */  move  $a0, $s4
/* 0AF1D4 7F07A6A4 0FC0F416 */  jal   sub_GAME_7F03D058
/* 0AF1D8 7F07A6A8 00002825 */   move  $a1, $zero
/* 0AF1DC 7F07A6AC 8E650000 */  lw    $a1, ($s3)
/* 0AF1E0 7F07A6B0 8E660008 */  lw    $a2, 8($s3)
/* 0AF1E4 7F07A6B4 C7A600B8 */  lwc1  $f6, 0xb8($sp)
/* 0AF1E8 7F07A6B8 240F0013 */  li    $t7, 19
/* 0AF1EC 7F07A6BC AFAF0014 */  sw    $t7, 0x14($sp)
/* 0AF1F0 7F07A6C0 E7BE0024 */  swc1  $f30, 0x24($sp)
/* 0AF1F4 7F07A6C4 E7BA0020 */  swc1  $f26, 0x20($sp)
/* 0AF1F8 7F07A6C8 E7BE001C */  swc1  $f30, 0x1c($sp)
/* 0AF1FC 7F07A6CC E7BA0018 */  swc1  $f26, 0x18($sp)
/* 0AF200 7F07A6D0 02A02025 */  move  $a0, $s5
/* 0AF204 7F07A6D4 8FA700B0 */  lw    $a3, 0xb0($sp)
/* 0AF208 7F07A6D8 0FC2C389 */  jal   stanTestLineUnobstructed
/* 0AF20C 7F07A6DC E7A60010 */   swc1  $f6, 0x10($sp)
/* 0AF210 7F07A6E0 00408025 */  move  $s0, $v0
/* 0AF214 7F07A6E4 02802025 */  move  $a0, $s4
/* 0AF218 7F07A6E8 0FC0F416 */  jal   sub_GAME_7F03D058
/* 0AF21C 7F07A6EC 24050001 */   li    $a1, 1
/* 0AF220 7F07A6F0 16000010 */  bnez  $s0, .L7F07A734
/* 0AF224 7F07A6F4 02602025 */   move  $a0, $s3
/* 0AF228 7F07A6F8 27A500BC */  addiu $a1, $sp, 0xbc
/* 0AF22C 7F07A6FC 0FC098A6 */  jal   chrlvStanPointPointIntersection
/* 0AF230 7F07A700 27A600B0 */   addiu $a2, $sp, 0xb0
/* 0AF234 7F07A704 C7A800B0 */  lwc1  $f8, 0xb0($sp)
/* 0AF238 7F07A708 C6700000 */  lwc1  $f16, ($s3)
/* 0AF23C 7F07A70C C7AA00B8 */  lwc1  $f10, 0xb8($sp)
/* 0AF240 7F07A710 C6720008 */  lwc1  $f18, 8($s3)
/* 0AF244 7F07A714 46104001 */  sub.s $f0, $f8, $f16
/* 0AF248 7F07A718 46125081 */  sub.s $f2, $f10, $f18
/* 0AF24C 7F07A71C 46000102 */  mul.s $f4, $f0, $f0
/* 0AF250 7F07A720 00000000 */  nop
/* 0AF254 7F07A724 46021182 */  mul.s $f6, $f2, $f2
/* 0AF258 7F07A728 0C007DF8 */  jal   sqrtf
/* 0AF25C 7F07A72C 46062300 */   add.s $f12, $f4, $f6
/* 0AF260 7F07A730 E7A000D0 */  swc1  $f0, 0xd0($sp)
.L7F07A734:
/* 0AF264 7F07A734 C7A800D0 */  lwc1  $f8, 0xd0($sp)
/* 0AF268 7F07A738 C7AA00F4 */  lwc1  $f10, 0xf4($sp)
/* 0AF26C 7F07A73C 461C4401 */  sub.s $f16, $f8, $f28
/* 0AF270 7F07A740 4610503E */  c.le.s $f10, $f16
/* 0AF274 7F07A744 E7B000D0 */  swc1  $f16, 0xd0($sp)
/* 0AF278 7F07A748 4502007A */  bc1fl .L7F07A934
/* 0AF27C 7F07A74C 27DE0001 */   addiu $fp, $fp, 1
/* 0AF280 7F07A750 461ED03C */  c.lt.s $f26, $f30
/* 0AF284 7F07A754 4600F606 */  mov.s $f24, $f30
/* 0AF288 7F07A758 45020076 */  bc1fl .L7F07A934
/* 0AF28C 7F07A75C 27DE0001 */   addiu $fp, $fp, 1
/* 0AF290 7F07A760 56C00074 */  bnezl $s6, .L7F07A934
/* 0AF294 7F07A764 27DE0001 */   addiu $fp, $fp, 1
/* 0AF298 7F07A768 460A8481 */  sub.s $f18, $f16, $f10
/* 0AF29C 7F07A76C E7B20090 */  swc1  $f18, 0x90($sp)
.L7F07A770:
/* 0AF2A0 7F07A770 0C002914 */  jal   randomGetNext
/* 0AF2A4 7F07A774 00000000 */   nop
/* 0AF2A8 7F07A778 44822000 */  mtc1  $v0, $f4
/* 0AF2AC 7F07A77C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0AF2B0 7F07A780 04410004 */  bgez  $v0, .L7F07A794
/* 0AF2B4 7F07A784 468021A0 */   cvt.s.w $f6, $f4
/* 0AF2B8 7F07A788 44814000 */  mtc1  $at, $f8
/* 0AF2BC 7F07A78C 00000000 */  nop
/* 0AF2C0 7F07A790 46083180 */  add.s $f6, $f6, $f8
.L7F07A794:
/* 0AF2C4 7F07A794 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0AF2C8 7F07A798 44818000 */  mtc1  $at, $f16
/* 0AF2CC 7F07A79C C7B20090 */  lwc1  $f18, 0x90($sp)
/* 0AF2D0 7F07A7A0 02802025 */  move  $a0, $s4
/* 0AF2D4 7F07A7A4 46103282 */  mul.s $f10, $f6, $f16
/* 0AF2D8 7F07A7A8 C7A600F4 */  lwc1  $f6, 0xf4($sp)
/* 0AF2DC 7F07A7AC C7B000BC */  lwc1  $f16, 0xbc($sp)
/* 0AF2E0 7F07A7B0 00002825 */  move  $a1, $zero
/* 0AF2E4 7F07A7B4 46125102 */  mul.s $f4, $f10, $f18
/* 0AF2E8 7F07A7B8 C6520000 */  lwc1  $f18, ($s2)
/* 0AF2EC 7F07A7BC 46182202 */  mul.s $f8, $f4, $f24
/* 0AF2F0 7F07A7C0 46064000 */  add.s $f0, $f8, $f6
/* 0AF2F4 7F07A7C4 C7A600C4 */  lwc1  $f6, 0xc4($sp)
/* 0AF2F8 7F07A7C8 46008282 */  mul.s $f10, $f16, $f0
/* 0AF2FC 7F07A7CC 46125100 */  add.s $f4, $f10, $f18
/* 0AF300 7F07A7D0 46003402 */  mul.s $f16, $f6, $f0
/* 0AF304 7F07A7D4 E6240000 */  swc1  $f4, ($s1)
/* 0AF308 7F07A7D8 C6480004 */  lwc1  $f8, 4($s2)
/* 0AF30C 7F07A7DC E6280004 */  swc1  $f8, 4($s1)
/* 0AF310 7F07A7E0 C64A0008 */  lwc1  $f10, 8($s2)
/* 0AF314 7F07A7E4 AFB700C8 */  sw    $s7, 0xc8($sp)
/* 0AF318 7F07A7E8 460A8480 */  add.s $f18, $f16, $f10
/* 0AF31C 7F07A7EC 0FC0F416 */  jal   sub_GAME_7F03D058
/* 0AF320 7F07A7F0 E6320008 */   swc1  $f18, 8($s1)
/* 0AF324 7F07A7F4 8E650000 */  lw    $a1, ($s3)
/* 0AF328 7F07A7F8 8E660008 */  lw    $a2, 8($s3)
/* 0AF32C 7F07A7FC C6240008 */  lwc1  $f4, 8($s1)
/* 0AF330 7F07A800 24180013 */  li    $t8, 19
/* 0AF334 7F07A804 AFB80014 */  sw    $t8, 0x14($sp)
/* 0AF338 7F07A808 E7BE0024 */  swc1  $f30, 0x24($sp)
/* 0AF33C 7F07A80C E7BA0020 */  swc1  $f26, 0x20($sp)
/* 0AF340 7F07A810 E7BE001C */  swc1  $f30, 0x1c($sp)
/* 0AF344 7F07A814 E7BA0018 */  swc1  $f26, 0x18($sp)
/* 0AF348 7F07A818 02A02025 */  move  $a0, $s5
/* 0AF34C 7F07A81C 8E270000 */  lw    $a3, ($s1)
/* 0AF350 7F07A820 0FC2C389 */  jal   stanTestLineUnobstructed
/* 0AF354 7F07A824 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0AF358 7F07A828 00408025 */  move  $s0, $v0
/* 0AF35C 7F07A82C 02802025 */  move  $a0, $s4
/* 0AF360 7F07A830 0FC0F416 */  jal   sub_GAME_7F03D058
/* 0AF364 7F07A834 24050001 */   li    $a1, 1
/* 0AF368 7F07A838 12000033 */  beqz  $s0, .L7F07A908
/* 0AF36C 7F07A83C 02A02025 */   move  $a0, $s5
/* 0AF370 7F07A840 4407E000 */  mfc1  $a3, $f28
/* 0AF374 7F07A844 2419001F */  li    $t9, 31
/* 0AF378 7F07A848 AFB90010 */  sw    $t9, 0x10($sp)
/* 0AF37C 7F07A84C 8E250000 */  lw    $a1, ($s1)
/* 0AF380 7F07A850 8E260008 */  lw    $a2, 8($s1)
/* 0AF384 7F07A854 E7BA0014 */  swc1  $f26, 0x14($sp)
/* 0AF388 7F07A858 0FC2C62E */  jal   stanTestVolume
/* 0AF38C 7F07A85C E7BE0018 */   swc1  $f30, 0x18($sp)
/* 0AF390 7F07A860 04410029 */  bgez  $v0, .L7F07A908
/* 0AF394 7F07A864 8FA400C8 */   lw    $a0, 0xc8($sp)
/* 0AF398 7F07A868 3C014339 */  li    $at, 0x43390000 # 185.000000
/* 0AF39C 7F07A86C 44814000 */  mtc1  $at, $f8
/* 0AF3A0 7F07A870 8E250000 */  lw    $a1, ($s1)
/* 0AF3A4 7F07A874 8E260008 */  lw    $a2, 8($s1)
/* 0AF3A8 7F07A878 0FC2CA5C */  jal   stanGetPositionYValue
/* 0AF3AC 7F07A87C 461C4581 */   sub.s $f22, $f8, $f28
/* 0AF3B0 7F07A880 0C002914 */  jal   randomGetNext
/* 0AF3B4 7F07A884 46000506 */   mov.s $f20, $f0
/* 0AF3B8 7F07A888 44823000 */  mtc1  $v0, $f6
/* 0AF3BC 7F07A88C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0AF3C0 7F07A890 04410004 */  bgez  $v0, .L7F07A8A4
/* 0AF3C4 7F07A894 46803420 */   cvt.s.w $f16, $f6
/* 0AF3C8 7F07A898 44815000 */  mtc1  $at, $f10
/* 0AF3CC 7F07A89C 00000000 */  nop
/* 0AF3D0 7F07A8A0 460A8400 */  add.s $f16, $f16, $f10
.L7F07A8A4:
/* 0AF3D4 7F07A8A4 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0AF3D8 7F07A8A8 44819000 */  mtc1  $at, $f18
/* 0AF3DC 7F07A8AC 461CA180 */  add.s $f6, $f20, $f28
/* 0AF3E0 7F07A8B0 3C01C47A */  li    $at, 0xC47A0000 # -1000.000000
/* 0AF3E4 7F07A8B4 46128102 */  mul.s $f4, $f16, $f18
/* 0AF3E8 7F07A8B8 00000000 */  nop
/* 0AF3EC 7F07A8BC 46162202 */  mul.s $f8, $f4, $f22
/* 0AF3F0 7F07A8C0 44812000 */  mtc1  $at, $f4
/* 0AF3F4 7F07A8C4 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0AF3F8 7F07A8C8 46064280 */  add.s $f10, $f8, $f6
/* 0AF3FC 7F07A8CC E62A0004 */  swc1  $f10, 4($s1)
/* 0AF400 7F07A8D0 C6520004 */  lwc1  $f18, 4($s2)
/* 0AF404 7F07A8D4 C6300004 */  lwc1  $f16, 4($s1)
/* 0AF408 7F07A8D8 46128001 */  sub.s $f0, $f16, $f18
/* 0AF40C 7F07A8DC 4600203C */  c.lt.s $f4, $f0
/* 0AF410 7F07A8E0 00000000 */  nop
/* 0AF414 7F07A8E4 45000008 */  bc1f  .L7F07A908
/* 0AF418 7F07A8E8 00000000 */   nop
/* 0AF41C 7F07A8EC 44814000 */  mtc1  $at, $f8
/* 0AF420 7F07A8F0 00000000 */  nop
/* 0AF424 7F07A8F4 4608003C */  c.lt.s $f0, $f8
/* 0AF428 7F07A8F8 00000000 */  nop
/* 0AF42C 7F07A8FC 45020003 */  bc1fl .L7F07A90C
/* 0AF430 7F07A900 3C013E80 */   lui   $at, 0x3e80
/* 0AF434 7F07A904 24160001 */  li    $s6, 1
.L7F07A908:
/* 0AF438 7F07A908 3C013E80 */  li    $at, 0x3E800000 # 0.250000
.L7F07A90C:
/* 0AF43C 7F07A90C 44813000 */  mtc1  $at, $f6
/* 0AF440 7F07A910 00000000 */  nop
/* 0AF444 7F07A914 4606C601 */  sub.s $f24, $f24, $f6
/* 0AF448 7F07A918 4618D03C */  c.lt.s $f26, $f24
/* 0AF44C 7F07A91C 00000000 */  nop
/* 0AF450 7F07A920 45020004 */  bc1fl .L7F07A934
/* 0AF454 7F07A924 27DE0001 */   addiu $fp, $fp, 1
/* 0AF458 7F07A928 12C0FF91 */  beqz  $s6, .L7F07A770
/* 0AF45C 7F07A92C 00000000 */   nop
/* 0AF460 7F07A930 27DE0001 */  addiu $fp, $fp, 1
.L7F07A934:
/* 0AF464 7F07A934 2BC10010 */  slti  $at, $fp, 0x10
/* 0AF468 7F07A938 50200004 */  beql  $at, $zero, .L7F07A94C
/* 0AF46C 7F07A93C 8FA200D8 */   lw    $v0, 0xd8($sp)
/* 0AF470 7F07A940 12C0FF36 */  beqz  $s6, .L7F07A61C
/* 0AF474 7F07A944 00000000 */   nop
.L7F07A948:
/* 0AF478 7F07A948 8FA200D8 */  lw    $v0, 0xd8($sp)
.L7F07A94C:
/* 0AF47C 7F07A94C 3C018005 */  lui   $at, %hi(D_80055040)
/* 0AF480 7F07A950 C4345040 */  lwc1  $f20, %lo(D_80055040)($at)
/* 0AF484 7F07A954 24420001 */  addiu $v0, $v0, 1
/* 0AF488 7F07A958 28410081 */  slti  $at, $v0, 0x81
/* 0AF48C 7F07A95C 50200004 */  beql  $at, $zero, .L7F07A970
/* 0AF490 7F07A960 8FBF0084 */   lw    $ra, 0x84($sp)
/* 0AF494 7F07A964 12C0FF14 */  beqz  $s6, .L7F07A5B8
/* 0AF498 7F07A968 AFA200D8 */   sw    $v0, 0xd8($sp)
/* 0AF49C 7F07A96C 8FBF0084 */  lw    $ra, 0x84($sp)
.L7F07A970:
/* 0AF4A0 7F07A970 02C01025 */  move  $v0, $s6
/* 0AF4A4 7F07A974 8FB60078 */  lw    $s6, 0x78($sp)
/* 0AF4A8 7F07A978 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 0AF4AC 7F07A97C D7B60038 */  ldc1  $f22, 0x38($sp)
/* 0AF4B0 7F07A980 D7B80040 */  ldc1  $f24, 0x40($sp)
/* 0AF4B4 7F07A984 D7BA0048 */  ldc1  $f26, 0x48($sp)
/* 0AF4B8 7F07A988 D7BC0050 */  ldc1  $f28, 0x50($sp)
/* 0AF4BC 7F07A98C D7BE0058 */  ldc1  $f30, 0x58($sp)
/* 0AF4C0 7F07A990 8FB00060 */  lw    $s0, 0x60($sp)
/* 0AF4C4 7F07A994 8FB10064 */  lw    $s1, 0x64($sp)
/* 0AF4C8 7F07A998 8FB20068 */  lw    $s2, 0x68($sp)
/* 0AF4CC 7F07A99C 8FB3006C */  lw    $s3, 0x6c($sp)
/* 0AF4D0 7F07A9A0 8FB40070 */  lw    $s4, 0x70($sp)
/* 0AF4D4 7F07A9A4 8FB50074 */  lw    $s5, 0x74($sp)
/* 0AF4D8 7F07A9A8 8FB7007C */  lw    $s7, 0x7c($sp)
/* 0AF4DC 7F07A9AC 8FBE0080 */  lw    $fp, 0x80($sp)
/* 0AF4E0 7F07A9B0 03E00008 */  jr    $ra
/* 0AF4E4 7F07A9B4 27BD00E0 */   addiu $sp, $sp, 0xe0
)
#endif





#ifdef NONMATCHING
void set_camera_mode(s32 arg0)
{
    f32 sp78;
    void *sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    void *sp38;
    f32 temp_f12;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_4;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_t8;
    void *temp_t9;
    void *temp_t9_2;
    void *temp_v0_10;
    void *temp_v0_11;
    void *temp_v0_12;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1;
    void *phi_t8;
    void *phi_t9;
    s32 phi_v0;
    void *phi_a2;
    s32 phi_v1;
    f32 phi_f0;
    s32 phi_s0;

    g_CameraMode               = arg0;
    g_CameraAfterCinema = 0;
    temp_v0                  = g_CameraMode;
    if (temp_v0 == 1)
    {
        if ((ptr_random06cam_entry != 0) && (get_recording_ramrom_flag() == 0) && (get_is_ramrom_flag() == 0))
        {
            D_800364A4 = 0.0f;
            currentPlayerSetFadeColour(0, 0, 0, 0x3F800000);
            currentPlayerSetFadeFrac(0x42700000, 0);
            load_enviroment(bossGetStageNum(), 1);
            pPlayer->unk34 = 0;
            return;
        }
        set_camera_mode(3);
        return;
    }
    if (temp_v0 == 2)
    {
        currentPlayerSetFadeColour(0, 0, 0, 0);
        currentPlayerSetFadeFrac(0x42700000, 0x3F800000);
        return;
    }
    if (temp_v0 == 9)
    {
        g_MpSwirlRotateSpeed = 0.0f;
        g_MpSwirlAngleDegrees = -90.0f;
        g_MpSwirlForwardSpeed = 0.0f;
        g_MpSwirlDistance = 80.0f;
        load_enviroment(bossGetStageNum(0), 0);
        return;
    }
    if (temp_v0 == 3)
    {
        D_8003649C = 0;
        currentPlayerSetFadeColour(0, 0, 0, 0x3F800000);
        currentPlayerSetFadeFrac(0x42700000, 0);
        load_enviroment(bossGetStageNum(), 0);
        if ((g_IntroSwirl != 0) && (get_recording_ramrom_flag() == 0) && (get_is_ramrom_flag() == 0))
        {
            D_800364A4 = 0.0f;
            D_800364A8 = 1;
            currentPlayerStartChrFade(0.0f, 0x3F800000);
            solo_char_load();
            temp_v0_2 = (g_IntroAnimationIndex * 0x10) + &stage_intro_anim_table;
            temp_f12  = temp_v0_2->unk8;
            sp78      = temp_f12;
            modelSetAnimation(pPlayer->unkD4, temp_v0_2->unk0 + ptr_animation_table, 0, temp_v0_2->unk4, temp_v0_2->unkC, 0.0f);
            if (temp_f12 > 0.0f)
            {
                modelSetAnimEndFrame(pPlayer->unkD4, temp_f12);
            }
            temp_v0_3       = pPlayer->unkA8->unk4;
            temp_v0_3->unk7 = 0x17;
            temp_v0_3->unk8 = 0;
            pPlayer->unk34  = 0;
            return;
        }
        set_camera_mode(4);
        return;
    }
    if (temp_v0 == 4)
    {
        if (bossGetStageNum(0) == 0x36)
        {
            currentPlayerSetFadeColour(0, 0, 0, 0x3F800000);
            currentPlayerSetFadeFrac(0, 0x3F800000);
        }
        else if (D_8003649C != 0)
        {
            currentPlayerSetFadeColour(0, 0, 0, 0x3F800000);
            currentPlayerSetFadeFrac(0x42700000, 0);
        }
        if (getPlayerCount() >= 2)
        {
            load_enviroment(bossGetStageNum(), 0);
        }
        if (pPlayer->unk1C8 == 0)
        {
            currentPlayerEquipWeaponWrapper(1, starting_right_weapon.unk4);
            currentPlayerEquipWeaponWrapper(0, starting_right_weapon.unk0);
        }
        stop_time_flag = 0;
        return;
    }
    if (temp_v0 == 5)
    {
        D_800364A4 = 0.0f;
        D_800364A8 = 1;
        currentPlayerSetFadeColour(0, 0, 0, 0x3F800000);
        currentPlayerSetFadeFrac(0x42700000, 0);
        temp_v0_4 = g_ExplodeTankOnDeathFlag;
        phi_v0    = temp_v0_4;
        if ((temp_v0_4 != 0) && (g_PlayerTankProp != 0))
        {
        }
        else
        {
            in_tank_flag = 0;
            temp_t9      = pPlayer;
            phi_t8       = temp_t9;
            phi_t9       = temp_t9;
            do
            {
                temp_t8           = phi_t8 + 0xC;
                temp_t9_2         = phi_t9 + 0xC;
                temp_t9_2->unk47C = phi_t8->unk434;
                temp_t9_2->unk480 = temp_t8->unk42C;
                temp_t9_2->unk484 = temp_t8->unk430;
                phi_t8            = temp_t8;
                phi_t9            = temp_t9_2;
            } while (temp_t8 != (temp_t9 + 0x54));
            temp_v0_5                = pPlayer;
            temp_v0_5->unk148        = temp_v0_5->unk414;
            temp_v0_6                = pPlayer;
            temp_v0_6->unk158        = temp_v0_6->unk418;
            temp_v0_7                = pPlayer;
            temp_v0_7->unkA8->unk8   = temp_v0_7->unk48C;
            temp_v0_8                = pPlayer;
            temp_v0_8->unkA8->unkC   = temp_v0_8->unk490;
            temp_v0_9                = pPlayer;
            temp_v0_9->unkA8->unk10  = temp_v0_9->unk494;
            temp_v0_10               = pPlayer;
            temp_v0_10->unkA8->unk14 = temp_v0_10->unk488;
            bondviewApplyVertaTheta();
            bondviewMoveAnimationTick(0, 0, 0);
            bondviewUpdatePlayerCollisionPositionFields();
            currentPlayerStartChrFade(0.0f, 0x3F800000);
            solo_char_load();
            sp38 = sub_GAME_7F06F5AC(pPlayer + 0x598);
            modelSetAnimation(pPlayer->unkD4, sp38, objecthandlerGetModelGunhand(pPlayer + 0x598), 0.0f, 0.5f, 0.0f);
            temp_v1        = pPlayer->unkA8->unk4;
            temp_v1->unk7  = 0x18;
            temp_v1->unk8  = 0;
            temp_v1->unk14 = temp_v1->unk14 | 1;
            temp_v0_11     = pPlayer;
            setsuboffset(temp_v0_11->unkD4, temp_v0_11->unkA8 + 8);
            setsubroty(pPlayer->unkD4, get_curplay_horizontal_rotation_in_degrees());
            phi_v0 = g_ExplodeTankOnDeathFlag;
        }
        if ((phi_v0 != 0) && (temp_a0 = g_PlayerTankProp, (temp_a0 != 0)))
        {
            sp64   = temp_a0;
            sp58   = temp_a0->unk8;
            sp5C   = temp_a0->unkC;
            sp60   = temp_a0->unk10;
            sp48   = temp_a0->unk8;
            sp4C   = temp_a0->unkC;
            sp50   = temp_a0->unk10;
            phi_a2 = temp_a0;
            phi_v1 = temp_a0->unk14;
            phi_f0 = 500.0f;
        }
        else
        {
            temp_v0_12 = pPlayer;
            sp64       = temp_v0_12->unkA8;
            sp58       = temp_v0_12->unk3C4;
            sp5C       = temp_v0_12->unk3C8;
            sp60       = temp_v0_12->unk3CC;
            sp48       = temp_v0_12->unk48C;
            sp4C       = temp_v0_12->unk490;
            sp50       = temp_v0_12->unk494;
            phi_a2     = temp_v0_12->unkA8;
            phi_v1     = temp_v0_12->unk488;
            phi_f0     = 200.0f;
        }
        if (sub_GAME_7F07A534(sp64, &sp58, phi_a2, &sp48, phi_v1, phi_f0) != 0)
        {
            if (D_80036510 == CAMERAMODE_NONE)
            {
                musicTrack1Play(M_INTROSWOOSH);
                sndSetScalerApplyVolumeAllSfxSlot(0x3F000000);
            }
            if ((g_ExplodeTankOnDeathFlag != 0) && (g_PlayerTankProp != 0))
            {
                temp_a0_2 = g_PlayerTankProp;
                explosionCreate(temp_a0_2, temp_a0_2 + 8, temp_a0_2->unk14, 0xD, 0, get_cur_playernum(), temp_a0_2 + 0x2C, 0);
                return;
            }
            // Duplicate return node #56. Try simplifying control flow for better match
            return;
        }
        bossRunTitleStage();
        return;
    }
    if (temp_v0 == 6)
    {
        currentPlayerSetFadeColour(0, 0, 0, 0);
        currentPlayerSetFadeFrac(0x42700000, 0x3F800000);
        return;
    }
    if (temp_v0 == 7)
    {
        solo_char_load(0);
        pPlayer->unk34 = 0;
        return;
    }
    if (temp_v0 == 8)
    {
        maybe_solo_intro_camera_handler(0);
        g_CameraMode = CAMERAMODE_FP;
        return;
    }
    if (temp_v0 == 0xA)
    {
        phi_s0 = 0;
        if (getPlayerCount(0) > 0)
        {
            do
            {
                set_cur_player(phi_s0);
                currentPlayerSetFadeColour(0, 0, 0, 0);
                currentPlayerSetFadeFrac(0x42700000, 0x3F800000);
                temp_s0 = phi_s0 + 1;
                phi_s0  = temp_s0;
            } while (temp_s0 < getPlayerCount());
        }
        set_cur_player(0);
    }
}
#else
GLOBAL_ASM(
.text
glabel set_camera_mode
/* 0AF4E8 7F07A9B8 27BDFF78 */  addiu $sp, $sp, -0x88
/* 0AF4EC 7F07A9BC AFB00028 */  sw    $s0, 0x28($sp)
/* 0AF4F0 7F07A9C0 3C108003 */  lui   $s0, %hi(g_CameraMode)
/* 0AF4F4 7F07A9C4 26106494 */  addiu $s0, %lo(g_CameraMode) # addiu $s0, $s0, 0x6494
/* 0AF4F8 7F07A9C8 AE040000 */  sw    $a0, ($s0)
/* 0AF4FC 7F07A9CC 3C018003 */  lui   $at, %hi(g_CameraAfterCinema)
/* 0AF500 7F07A9D0 AC206498 */  sw    $zero, %lo(g_CameraAfterCinema)($at)
/* 0AF504 7F07A9D4 8E020000 */  lw    $v0, ($s0)
/* 0AF508 7F07A9D8 24030001 */  li    $v1, 1
/* 0AF50C 7F07A9DC AFBF002C */  sw    $ra, 0x2c($sp)
/* 0AF510 7F07A9E0 14620027 */  bne   $v1, $v0, .L7F07AA80
/* 0AF514 7F07A9E4 24010002 */   li    $at, 2
/* 0AF518 7F07A9E8 3C0E8003 */  lui   $t6, %hi(ptr_random06cam_entry)
/* 0AF51C 7F07A9EC 8DCE64C0 */  lw    $t6, %lo(ptr_random06cam_entry)($t6)
/* 0AF520 7F07A9F0 11C0001F */  beqz  $t6, .L7F07AA70
/* 0AF524 7F07A9F4 00000000 */   nop
/* 0AF528 7F07A9F8 0FC2FF26 */  jal   get_recording_ramrom_flag
/* 0AF52C 7F07A9FC 00000000 */   nop
/* 0AF530 7F07AA00 1440001B */  bnez  $v0, .L7F07AA70
/* 0AF534 7F07AA04 00000000 */   nop
/* 0AF538 7F07AA08 0FC2FF23 */  jal   get_is_ramrom_flag
/* 0AF53C 7F07AA0C 00000000 */   nop
/* 0AF540 7F07AA10 14400017 */  bnez  $v0, .L7F07AA70
/* 0AF544 7F07AA14 3C018003 */   lui   $at, %hi(D_800364A4)
/* 0AF548 7F07AA18 44802000 */  mtc1  $zero, $f4
/* 0AF54C 7F07AA1C 00002025 */  move  $a0, $zero
/* 0AF550 7F07AA20 00002825 */  move  $a1, $zero
/* 0AF554 7F07AA24 00003025 */  move  $a2, $zero
/* 0AF558 7F07AA28 3C073F80 */  lui   $a3, 0x3f80
/* 0AF55C 7F07AA2C 0FC201EC */  jal   currentPlayerSetFadeColour
/* 0AF560 7F07AA30 E42464A4 */   swc1  $f4, %lo(D_800364A4)($at)
/* 0AF564 7F07AA34 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0AF568 7F07AA38 44816000 */  mtc1  $at, $f12
/* 0AF56C 7F07AA3C 44807000 */  mtc1  $zero, $f14
/* 0AF570 7F07AA40 0FC20216 */  jal   currentPlayerSetFadeFrac
/* 0AF574 7F07AA44 00000000 */   nop
/* 0AF578 7F07AA48 0C001A57 */  jal   bossGetStageNum
/* 0AF57C 7F07AA4C 00000000 */   nop
/* 0AF580 7F07AA50 00402025 */  move  $a0, $v0
/* 0AF584 7F07AA54 0FC2EA99 */  jal   fogLoadLevelEnvironment
/* 0AF588 7F07AA58 24050001 */   li    $a1, 1
/* 0AF58C 7F07AA5C 3C108008 */  lui   $s0, %hi(g_CurrentPlayer)
/* 0AF590 7F07AA60 2610A0B0 */  addiu $s0, %lo(g_CurrentPlayer) # addiu $s0, $s0, -0x5f50
/* 0AF594 7F07AA64 8E0F0000 */  lw    $t7, ($s0)
/* 0AF598 7F07AA68 100001C9 */  b     .L7F07B190
/* 0AF59C 7F07AA6C ADE00034 */   sw    $zero, 0x34($t7)
.L7F07AA70:
/* 0AF5A0 7F07AA70 0FC1EA6E */  jal   set_camera_mode
/* 0AF5A4 7F07AA74 24040003 */   li    $a0, 3
/* 0AF5A8 7F07AA78 100001C6 */  b     .L7F07B194
/* 0AF5AC 7F07AA7C 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F07AA80:
/* 0AF5B0 7F07AA80 1441000D */  bne   $v0, $at, .L7F07AAB8
/* 0AF5B4 7F07AA84 00002025 */   move  $a0, $zero
/* 0AF5B8 7F07AA88 00002825 */  move  $a1, $zero
/* 0AF5BC 7F07AA8C 00003025 */  move  $a2, $zero
/* 0AF5C0 7F07AA90 0FC201EC */  jal   currentPlayerSetFadeColour
/* 0AF5C4 7F07AA94 24070000 */   li    $a3, 0
/* 0AF5C8 7F07AA98 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0AF5CC 7F07AA9C 44816000 */  mtc1  $at, $f12
/* 0AF5D0 7F07AAA0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AF5D4 7F07AAA4 44817000 */  mtc1  $at, $f14
/* 0AF5D8 7F07AAA8 0FC20216 */  jal   currentPlayerSetFadeFrac
/* 0AF5DC 7F07AAAC 00000000 */   nop
/* 0AF5E0 7F07AAB0 100001B8 */  b     .L7F07B194
/* 0AF5E4 7F07AAB4 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F07AAB8:
/* 0AF5E8 7F07AAB8 24010009 */  li    $at, 9
/* 0AF5EC 7F07AABC 54410015 */  bnel  $v0, $at, .L7F07AB14
/* 0AF5F0 7F07AAC0 24010003 */   li    $at, 3
/* 0AF5F4 7F07AAC4 44800000 */  mtc1  $zero, $f0
/* 0AF5F8 7F07AAC8 3C018008 */  lui   $at, %hi(g_MpSwirlRotateSpeed)
/* 0AF5FC 7F07AACC E4209E04 */  swc1  $f0, %lo(g_MpSwirlRotateSpeed)($at)
/* 0AF600 7F07AAD0 3C01C2B4 */  li    $at, 0xC2B40000 # -90.000000
/* 0AF604 7F07AAD4 44813000 */  mtc1  $at, $f6
/* 0AF608 7F07AAD8 3C018008 */  lui   $at, %hi(g_MpSwirlAngleDegrees)
/* 0AF60C 7F07AADC E4269E08 */  swc1  $f6, %lo(g_MpSwirlAngleDegrees)($at)
/* 0AF610 7F07AAE0 3C018008 */  lui   $at, %hi(g_MpSwirlForwardSpeed)
/* 0AF614 7F07AAE4 E4209E0C */  swc1  $f0, %lo(g_MpSwirlForwardSpeed)($at)
/* 0AF618 7F07AAE8 3C0142A0 */  li    $at, 0x42A00000 # 80.000000
/* 0AF61C 7F07AAEC 44814000 */  mtc1  $at, $f8
/* 0AF620 7F07AAF0 3C018008 */  lui   $at, %hi(g_MpSwirlDistance)
/* 0AF624 7F07AAF4 0C001A57 */  jal   bossGetStageNum
/* 0AF628 7F07AAF8 E4289E10 */   swc1  $f8, %lo(g_MpSwirlDistance)($at)
/* 0AF62C 7F07AAFC 00402025 */  move  $a0, $v0
/* 0AF630 7F07AB00 0FC2EA99 */  jal   fogLoadLevelEnvironment
/* 0AF634 7F07AB04 00002825 */   move  $a1, $zero
/* 0AF638 7F07AB08 100001A2 */  b     .L7F07B194
/* 0AF63C 7F07AB0C 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0AF640 7F07AB10 24010003 */  li    $at, 3
.L7F07AB14:
/* 0AF644 7F07AB14 14410059 */  bne   $v0, $at, .L7F07AC7C
/* 0AF648 7F07AB18 00002025 */   move  $a0, $zero
/* 0AF64C 7F07AB1C 3C018003 */  lui   $at, %hi(D_8003649C)
/* 0AF650 7F07AB20 AC20649C */  sw    $zero, %lo(D_8003649C)($at)
/* 0AF654 7F07AB24 00002825 */  move  $a1, $zero
/* 0AF658 7F07AB28 00003025 */  move  $a2, $zero
/* 0AF65C 7F07AB2C 0FC201EC */  jal   currentPlayerSetFadeColour
/* 0AF660 7F07AB30 3C073F80 */   lui   $a3, 0x3f80
/* 0AF664 7F07AB34 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0AF668 7F07AB38 44816000 */  mtc1  $at, $f12
/* 0AF66C 7F07AB3C 44807000 */  mtc1  $zero, $f14
/* 0AF670 7F07AB40 0FC20216 */  jal   currentPlayerSetFadeFrac
/* 0AF674 7F07AB44 00000000 */   nop
/* 0AF678 7F07AB48 0C001A57 */  jal   bossGetStageNum
/* 0AF67C 7F07AB4C 00000000 */   nop
/* 0AF680 7F07AB50 00402025 */  move  $a0, $v0
/* 0AF684 7F07AB54 0FC2EA99 */  jal   fogLoadLevelEnvironment
/* 0AF688 7F07AB58 00002825 */   move  $a1, $zero
/* 0AF68C 7F07AB5C 3C188003 */  lui   $t8, %hi(g_IntroSwirl)
/* 0AF690 7F07AB60 8F1864AC */  lw    $t8, %lo(g_IntroSwirl)($t8)
/* 0AF694 7F07AB64 13000041 */  beqz  $t8, .L7F07AC6C
/* 0AF698 7F07AB68 00000000 */   nop
/* 0AF69C 7F07AB6C 0FC2FF26 */  jal   get_recording_ramrom_flag
/* 0AF6A0 7F07AB70 00000000 */   nop
/* 0AF6A4 7F07AB74 1440003D */  bnez  $v0, .L7F07AC6C
/* 0AF6A8 7F07AB78 00000000 */   nop
/* 0AF6AC 7F07AB7C 0FC2FF23 */  jal   get_is_ramrom_flag
/* 0AF6B0 7F07AB80 00000000 */   nop
/* 0AF6B4 7F07AB84 14400039 */  bnez  $v0, .L7F07AC6C
/* 0AF6B8 7F07AB88 00000000 */   nop
/* 0AF6BC 7F07AB8C 44806000 */  mtc1  $zero, $f12
/* 0AF6C0 7F07AB90 3C018003 */  lui   $at, %hi(D_800364A4)
/* 0AF6C4 7F07AB94 24190001 */  li    $t9, 1
/* 0AF6C8 7F07AB98 E42C64A4 */  swc1  $f12, %lo(D_800364A4)($at)
/* 0AF6CC 7F07AB9C 3C018003 */  lui   $at, %hi(D_800364A8)
/* 0AF6D0 7F07ABA0 AC3964A8 */  sw    $t9, %lo(D_800364A8)($at)
/* 0AF6D4 7F07ABA4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AF6D8 7F07ABA8 44817000 */  mtc1  $at, $f14
/* 0AF6DC 7F07ABAC 0FC20284 */  jal   currentPlayerStartChrFade
/* 0AF6E0 7F07ABB0 00000000 */   nop
/* 0AF6E4 7F07ABB4 0FC1E73C */  jal   solo_char_load
/* 0AF6E8 7F07ABB8 00000000 */   nop
/* 0AF6EC 7F07ABBC 3C088003 */  lui   $t0, %hi(g_IntroAnimationIndex)
/* 0AF6F0 7F07ABC0 8D086514 */  lw    $t0, %lo(g_IntroAnimationIndex)($t0)
/* 0AF6F4 7F07ABC4 3C0A8003 */  lui   $t2, %hi(stage_intro_anim_table)
/* 0AF6F8 7F07ABC8 3C108008 */  lui   $s0, %hi(g_CurrentPlayer)
/* 0AF6FC 7F07ABCC 254A6518 */  addiu $t2, %lo(stage_intro_anim_table) # addiu $t2, $t2, 0x6518
/* 0AF700 7F07ABD0 00084900 */  sll   $t1, $t0, 4
/* 0AF704 7F07ABD4 2610A0B0 */  addiu $s0, %lo(g_CurrentPlayer) # addiu $s0, $s0, -0x5f50
/* 0AF708 7F07ABD8 012A1021 */  addu  $v0, $t1, $t2
/* 0AF70C 7F07ABDC 8E0D0000 */  lw    $t5, ($s0)
/* 0AF710 7F07ABE0 C4400004 */  lwc1  $f0, 4($v0)
/* 0AF714 7F07ABE4 3C0C8007 */  lui   $t4, %hi(ptr_animation_table)
/* 0AF718 7F07ABE8 8D8C9538 */  lw    $t4, %lo(ptr_animation_table)($t4)
/* 0AF71C 7F07ABEC 8C4B0000 */  lw    $t3, ($v0)
/* 0AF720 7F07ABF0 C44C0008 */  lwc1  $f12, 8($v0)
/* 0AF724 7F07ABF4 C442000C */  lwc1  $f2, 0xc($v0)
/* 0AF728 7F07ABF8 44805000 */  mtc1  $zero, $f10
/* 0AF72C 7F07ABFC 8DA400D4 */  lw    $a0, 0xd4($t5)
/* 0AF730 7F07AC00 44070000 */  mfc1  $a3, $f0
/* 0AF734 7F07AC04 00003025 */  move  $a2, $zero
/* 0AF738 7F07AC08 016C2821 */  addu  $a1, $t3, $t4
/* 0AF73C 7F07AC0C E7AC0078 */  swc1  $f12, 0x78($sp)
/* 0AF740 7F07AC10 E7A20010 */  swc1  $f2, 0x10($sp)
/* 0AF744 7F07AC14 0FC1BF2A */  jal   modelSetAnimation
/* 0AF748 7F07AC18 E7AA0014 */   swc1  $f10, 0x14($sp)
/* 0AF74C 7F07AC1C C7AC0078 */  lwc1  $f12, 0x78($sp)
/* 0AF750 7F07AC20 44808000 */  mtc1  $zero, $f16
/* 0AF754 7F07AC24 00000000 */  nop
/* 0AF758 7F07AC28 460C803C */  c.lt.s $f16, $f12
/* 0AF75C 7F07AC2C 00000000 */  nop
/* 0AF760 7F07AC30 45020006 */  bc1fl .L7F07AC4C
/* 0AF764 7F07AC34 8E0F0000 */   lw    $t7, ($s0)
/* 0AF768 7F07AC38 8E0E0000 */  lw    $t6, ($s0)
/* 0AF76C 7F07AC3C 44056000 */  mfc1  $a1, $f12
/* 0AF770 7F07AC40 0FC1BF7A */  jal   modelSetAnimEndFrame
/* 0AF774 7F07AC44 8DC400D4 */   lw    $a0, 0xd4($t6)
/* 0AF778 7F07AC48 8E0F0000 */  lw    $t7, ($s0)
.L7F07AC4C:
/* 0AF77C 7F07AC4C 24190017 */  li    $t9, 23
/* 0AF780 7F07AC50 8DF800A8 */  lw    $t8, 0xa8($t7)
/* 0AF784 7F07AC54 8F020004 */  lw    $v0, 4($t8)
/* 0AF788 7F07AC58 A0590007 */  sb    $t9, 7($v0)
/* 0AF78C 7F07AC5C A0400008 */  sb    $zero, 8($v0)
/* 0AF790 7F07AC60 8E080000 */  lw    $t0, ($s0)
/* 0AF794 7F07AC64 1000014A */  b     .L7F07B190
/* 0AF798 7F07AC68 AD000034 */   sw    $zero, 0x34($t0)
.L7F07AC6C:
/* 0AF79C 7F07AC6C 0FC1EA6E */  jal   set_camera_mode
/* 0AF7A0 7F07AC70 24040004 */   li    $a0, 4
/* 0AF7A4 7F07AC74 10000147 */  b     .L7F07B194
/* 0AF7A8 7F07AC78 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F07AC7C:
/* 0AF7AC 7F07AC7C 24010004 */  li    $at, 4
/* 0AF7B0 7F07AC80 5441003A */  bnel  $v0, $at, .L7F07AD6C
/* 0AF7B4 7F07AC84 24010005 */   li    $at, 5
/* 0AF7B8 7F07AC88 0C001A57 */  jal   bossGetStageNum
/* 0AF7BC 7F07AC8C 00000000 */   nop
/* 0AF7C0 7F07AC90 24010036 */  li    $at, 54
/* 0AF7C4 7F07AC94 1441000D */  bne   $v0, $at, .L7F07ACCC
/* 0AF7C8 7F07AC98 3C098003 */   lui   $t1, %hi(D_8003649C)
/* 0AF7CC 7F07AC9C 00002025 */  move  $a0, $zero
/* 0AF7D0 7F07ACA0 00002825 */  move  $a1, $zero
/* 0AF7D4 7F07ACA4 00003025 */  move  $a2, $zero
/* 0AF7D8 7F07ACA8 0FC201EC */  jal   currentPlayerSetFadeColour
/* 0AF7DC 7F07ACAC 3C073F80 */   lui   $a3, 0x3f80
/* 0AF7E0 7F07ACB0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AF7E4 7F07ACB4 44817000 */  mtc1  $at, $f14
/* 0AF7E8 7F07ACB8 44806000 */  mtc1  $zero, $f12
/* 0AF7EC 7F07ACBC 0FC20216 */  jal   currentPlayerSetFadeFrac
/* 0AF7F0 7F07ACC0 00000000 */   nop
/* 0AF7F4 7F07ACC4 1000000D */  b     .L7F07ACFC
/* 0AF7F8 7F07ACC8 00000000 */   nop
.L7F07ACCC:
/* 0AF7FC 7F07ACCC 8D29649C */  lw    $t1, %lo(D_8003649C)($t1)
/* 0AF800 7F07ACD0 00002025 */  move  $a0, $zero
/* 0AF804 7F07ACD4 00002825 */  move  $a1, $zero
/* 0AF808 7F07ACD8 11200008 */  beqz  $t1, .L7F07ACFC
/* 0AF80C 7F07ACDC 00003025 */   move  $a2, $zero
/* 0AF810 7F07ACE0 0FC201EC */  jal   currentPlayerSetFadeColour
/* 0AF814 7F07ACE4 3C073F80 */   lui   $a3, 0x3f80
/* 0AF818 7F07ACE8 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0AF81C 7F07ACEC 44816000 */  mtc1  $at, $f12
/* 0AF820 7F07ACF0 44807000 */  mtc1  $zero, $f14
/* 0AF824 7F07ACF4 0FC20216 */  jal   currentPlayerSetFadeFrac
/* 0AF828 7F07ACF8 00000000 */   nop
.L7F07ACFC:
/* 0AF82C 7F07ACFC 0FC26919 */  jal   getPlayerCount
/* 0AF830 7F07AD00 00000000 */   nop
/* 0AF834 7F07AD04 28410002 */  slti  $at, $v0, 2
/* 0AF838 7F07AD08 14200006 */  bnez  $at, .L7F07AD24
/* 0AF83C 7F07AD0C 00000000 */   nop
/* 0AF840 7F07AD10 0C001A57 */  jal   bossGetStageNum
/* 0AF844 7F07AD14 00000000 */   nop
/* 0AF848 7F07AD18 00402025 */  move  $a0, $v0
/* 0AF84C 7F07AD1C 0FC2EA99 */  jal   fogLoadLevelEnvironment
/* 0AF850 7F07AD20 00002825 */   move  $a1, $zero
.L7F07AD24:
/* 0AF854 7F07AD24 3C108008 */  lui   $s0, %hi(g_CurrentPlayer)
/* 0AF858 7F07AD28 2610A0B0 */  addiu $s0, %lo(g_CurrentPlayer) # addiu $s0, $s0, -0x5f50
/* 0AF85C 7F07AD2C 8E0A0000 */  lw    $t2, ($s0)
/* 0AF860 7F07AD30 3C108008 */  lui   $s0, %hi(starting_right_weapon)
/* 0AF864 7F07AD34 261099E0 */  addiu $s0, %lo(starting_right_weapon) # addiu $s0, $s0, -0x6620
/* 0AF868 7F07AD38 8D4B01C8 */  lw    $t3, 0x1c8($t2)
/* 0AF86C 7F07AD3C 24040001 */  li    $a0, 1
/* 0AF870 7F07AD40 15600006 */  bnez  $t3, .L7F07AD5C
/* 0AF874 7F07AD44 00000000 */   nop
/* 0AF878 7F07AD48 0FC17645 */  jal   currentPlayerEquipWeaponWrapper
/* 0AF87C 7F07AD4C 8E050004 */   lw    $a1, 4($s0)
/* 0AF880 7F07AD50 00002025 */  move  $a0, $zero
/* 0AF884 7F07AD54 0FC17645 */  jal   currentPlayerEquipWeaponWrapper
/* 0AF888 7F07AD58 8E050000 */   lw    $a1, ($s0)
.L7F07AD5C:
/* 0AF88C 7F07AD5C 3C018003 */  lui   $at, %hi(stop_time_flag)
/* 0AF890 7F07AD60 1000010B */  b     .L7F07B190
/* 0AF894 7F07AD64 AC2064A0 */   sw    $zero, %lo(stop_time_flag)($at)
/* 0AF898 7F07AD68 24010005 */  li    $at, 5
.L7F07AD6C:
/* 0AF89C 7F07AD6C 144100CC */  bne   $v0, $at, .L7F07B0A0
/* 0AF8A0 7F07AD70 00002025 */   move  $a0, $zero
/* 0AF8A4 7F07AD74 44809000 */  mtc1  $zero, $f18
/* 0AF8A8 7F07AD78 3C018003 */  lui   $at, %hi(D_800364A4)
/* 0AF8AC 7F07AD7C 00002825 */  move  $a1, $zero
/* 0AF8B0 7F07AD80 E43264A4 */  swc1  $f18, %lo(D_800364A4)($at)
/* 0AF8B4 7F07AD84 3C018003 */  lui   $at, %hi(D_800364A8)
/* 0AF8B8 7F07AD88 AC2364A8 */  sw    $v1, %lo(D_800364A8)($at)
/* 0AF8BC 7F07AD8C 00003025 */  move  $a2, $zero
/* 0AF8C0 7F07AD90 0FC201EC */  jal   currentPlayerSetFadeColour
/* 0AF8C4 7F07AD94 3C073F80 */   lui   $a3, 0x3f80
/* 0AF8C8 7F07AD98 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0AF8CC 7F07AD9C 44816000 */  mtc1  $at, $f12
/* 0AF8D0 7F07ADA0 44807000 */  mtc1  $zero, $f14
/* 0AF8D4 7F07ADA4 0FC20216 */  jal   currentPlayerSetFadeFrac
/* 0AF8D8 7F07ADA8 00000000 */   nop
/* 0AF8DC 7F07ADAC 3C028003 */  lui   $v0, %hi(g_ExplodeTankOnDeathFlag)
/* 0AF8E0 7F07ADB0 8C42648C */  lw    $v0, %lo(g_ExplodeTankOnDeathFlag)($v0)
/* 0AF8E4 7F07ADB4 3C108008 */  lui   $s0, %hi(g_CurrentPlayer)
/* 0AF8E8 7F07ADB8 3C0C8003 */  lui   $t4, %hi(g_PlayerTankProp)
/* 0AF8EC 7F07ADBC 10400007 */  beqz  $v0, .L7F07ADDC
/* 0AF8F0 7F07ADC0 2610A0B0 */   addiu $s0, %lo(g_CurrentPlayer) # addiu $s0, $s0, -0x5f50
/* 0AF8F4 7F07ADC4 8D8C6450 */  lw    $t4, %lo(g_PlayerTankProp)($t4)
/* 0AF8F8 7F07ADC8 11800004 */  beqz  $t4, .L7F07ADDC
/* 0AF8FC 7F07ADCC 00000000 */   nop
/* 0AF900 7F07ADD0 3C108008 */  lui   $s0, %hi(g_CurrentPlayer)
/* 0AF904 7F07ADD4 1000005C */  b     .L7F07AF48
/* 0AF908 7F07ADD8 2610A0B0 */   addiu $s0, %lo(g_CurrentPlayer) # addiu $s0, $s0, -0x5f50
.L7F07ADDC:
/* 0AF90C 7F07ADDC 3C018003 */  lui   $at, %hi(in_tank_flag)
/* 0AF910 7F07ADE0 AC206448 */  sw    $zero, %lo(in_tank_flag)($at)
/* 0AF914 7F07ADE4 8E190000 */  lw    $t9, ($s0)
/* 0AF918 7F07ADE8 0320C025 */  move  $t8, $t9
/* 0AF91C 7F07ADEC 272F0054 */  addiu $t7, $t9, 0x54
.L7F07ADF0:
/* 0AF920 7F07ADF0 8F010434 */  lw    $at, 0x434($t8)
/* 0AF924 7F07ADF4 2718000C */  addiu $t8, $t8, 0xc
/* 0AF928 7F07ADF8 2739000C */  addiu $t9, $t9, 0xc
/* 0AF92C 7F07ADFC AF21047C */  sw    $at, 0x47c($t9)
/* 0AF930 7F07AE00 8F01042C */  lw    $at, 0x42c($t8)
/* 0AF934 7F07AE04 AF210480 */  sw    $at, 0x480($t9)
/* 0AF938 7F07AE08 8F010430 */  lw    $at, 0x430($t8)
/* 0AF93C 7F07AE0C 170FFFF8 */  bne   $t8, $t7, .L7F07ADF0
/* 0AF940 7F07AE10 AF210484 */   sw    $at, 0x484($t9)
/* 0AF944 7F07AE14 8E020000 */  lw    $v0, ($s0)
/* 0AF948 7F07AE18 C4440414 */  lwc1  $f4, 0x414($v0)
/* 0AF94C 7F07AE1C E4440148 */  swc1  $f4, 0x148($v0)
/* 0AF950 7F07AE20 8E020000 */  lw    $v0, ($s0)
/* 0AF954 7F07AE24 C4460418 */  lwc1  $f6, 0x418($v0)
/* 0AF958 7F07AE28 E4460158 */  swc1  $f6, 0x158($v0)
/* 0AF95C 7F07AE2C 8E020000 */  lw    $v0, ($s0)
/* 0AF960 7F07AE30 C448048C */  lwc1  $f8, 0x48c($v0)
/* 0AF964 7F07AE34 8C4800A8 */  lw    $t0, 0xa8($v0)
/* 0AF968 7F07AE38 E5080008 */  swc1  $f8, 8($t0)
/* 0AF96C 7F07AE3C 8E020000 */  lw    $v0, ($s0)
/* 0AF970 7F07AE40 C44A0490 */  lwc1  $f10, 0x490($v0)
/* 0AF974 7F07AE44 8C4900A8 */  lw    $t1, 0xa8($v0)
/* 0AF978 7F07AE48 E52A000C */  swc1  $f10, 0xc($t1)
/* 0AF97C 7F07AE4C 8E020000 */  lw    $v0, ($s0)
/* 0AF980 7F07AE50 C4500494 */  lwc1  $f16, 0x494($v0)
/* 0AF984 7F07AE54 8C4A00A8 */  lw    $t2, 0xa8($v0)
/* 0AF988 7F07AE58 E5500010 */  swc1  $f16, 0x10($t2)
/* 0AF98C 7F07AE5C 8E020000 */  lw    $v0, ($s0)
/* 0AF990 7F07AE60 8C4B0488 */  lw    $t3, 0x488($v0)
/* 0AF994 7F07AE64 8C4C00A8 */  lw    $t4, 0xa8($v0)
/* 0AF998 7F07AE68 0FC205E4 */  jal   bondviewApplyVertaTheta
/* 0AF99C 7F07AE6C AD8B0014 */   sw    $t3, 0x14($t4)
/* 0AF9A0 7F07AE70 44806000 */  mtc1  $zero, $f12
/* 0AF9A4 7F07AE74 00000000 */  nop
/* 0AF9A8 7F07AE78 44066000 */  mfc1  $a2, $f12
/* 0AF9AC 7F07AE7C 0FC202CD */  jal   bondviewMoveAnimationTick
/* 0AF9B0 7F07AE80 46006386 */   mov.s $f14, $f12
/* 0AF9B4 7F07AE84 0FC2051E */  jal   bondviewUpdatePlayerCollisionPositionFields
/* 0AF9B8 7F07AE88 00000000 */   nop
/* 0AF9BC 7F07AE8C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AF9C0 7F07AE90 44817000 */  mtc1  $at, $f14
/* 0AF9C4 7F07AE94 44806000 */  mtc1  $zero, $f12
/* 0AF9C8 7F07AE98 0FC20284 */  jal   currentPlayerStartChrFade
/* 0AF9CC 7F07AE9C 00000000 */   nop
/* 0AF9D0 7F07AEA0 0FC1E73C */  jal   solo_char_load
/* 0AF9D4 7F07AEA4 00000000 */   nop
/* 0AF9D8 7F07AEA8 8E040000 */  lw    $a0, ($s0)
/* 0AF9DC 7F07AEAC 0FC1BD6B */  jal   objecthandlerGetModelAnim
/* 0AF9E0 7F07AEB0 24840598 */   addiu $a0, $a0, 0x598
/* 0AF9E4 7F07AEB4 8E040000 */  lw    $a0, ($s0)
/* 0AF9E8 7F07AEB8 AFA20038 */  sw    $v0, 0x38($sp)
/* 0AF9EC 7F07AEBC 0FC1BD6D */  jal   objecthandlerGetModelGunhand
/* 0AF9F0 7F07AEC0 24840598 */   addiu $a0, $a0, 0x598
/* 0AF9F4 7F07AEC4 44800000 */  mtc1  $zero, $f0
/* 0AF9F8 7F07AEC8 8E0E0000 */  lw    $t6, ($s0)
/* 0AF9FC 7F07AECC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0AFA00 7F07AED0 44819000 */  mtc1  $at, $f18
/* 0AFA04 7F07AED4 8DC400D4 */  lw    $a0, 0xd4($t6)
/* 0AFA08 7F07AED8 44070000 */  mfc1  $a3, $f0
/* 0AFA0C 7F07AEDC 8FA50038 */  lw    $a1, 0x38($sp)
/* 0AFA10 7F07AEE0 00403025 */  move  $a2, $v0
/* 0AFA14 7F07AEE4 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0AFA18 7F07AEE8 0FC1BF2A */  jal   modelSetAnimation
/* 0AFA1C 7F07AEEC E7B20010 */   swc1  $f18, 0x10($sp)
/* 0AFA20 7F07AEF0 8E0D0000 */  lw    $t5, ($s0)
/* 0AFA24 7F07AEF4 24180018 */  li    $t8, 24
/* 0AFA28 7F07AEF8 8DAF00A8 */  lw    $t7, 0xa8($t5)
/* 0AFA2C 7F07AEFC 8DE30004 */  lw    $v1, 4($t7)
/* 0AFA30 7F07AF00 8C790014 */  lw    $t9, 0x14($v1)
/* 0AFA34 7F07AF04 A0780007 */  sb    $t8, 7($v1)
/* 0AFA38 7F07AF08 A0600008 */  sb    $zero, 8($v1)
/* 0AFA3C 7F07AF0C 37280001 */  ori   $t0, $t9, 1
/* 0AFA40 7F07AF10 AC680014 */  sw    $t0, 0x14($v1)
/* 0AFA44 7F07AF14 8E020000 */  lw    $v0, ($s0)
/* 0AFA48 7F07AF18 8C4500A8 */  lw    $a1, 0xa8($v0)
/* 0AFA4C 7F07AF1C 8C4400D4 */  lw    $a0, 0xd4($v0)
/* 0AFA50 7F07AF20 0FC1B303 */  jal   setsuboffset
/* 0AFA54 7F07AF24 24A50008 */   addiu $a1, $a1, 8
/* 0AFA58 7F07AF28 0FC227B9 */  jal   get_curplay_horizontal_rotation_in_degrees
/* 0AFA5C 7F07AF2C 00000000 */   nop
/* 0AFA60 7F07AF30 8E090000 */  lw    $t1, ($s0)
/* 0AFA64 7F07AF34 44050000 */  mfc1  $a1, $f0
/* 0AFA68 7F07AF38 0FC1B34F */  jal   setsubroty
/* 0AFA6C 7F07AF3C 8D2400D4 */   lw    $a0, 0xd4($t1)
/* 0AFA70 7F07AF40 3C028003 */  lui   $v0, %hi(g_ExplodeTankOnDeathFlag)
/* 0AFA74 7F07AF44 8C42648C */  lw    $v0, %lo(g_ExplodeTankOnDeathFlag)($v0)
.L7F07AF48:
/* 0AFA78 7F07AF48 10400017 */  beqz  $v0, .L7F07AFA8
/* 0AFA7C 7F07AF4C 27A50058 */   addiu $a1, $sp, 0x58
/* 0AFA80 7F07AF50 3C048003 */  lui   $a0, %hi(g_PlayerTankProp)
/* 0AFA84 7F07AF54 8C846450 */  lw    $a0, %lo(g_PlayerTankProp)($a0)
/* 0AFA88 7F07AF58 50800014 */  beql  $a0, $zero, .L7F07AFAC
/* 0AFA8C 7F07AF5C 8E020000 */   lw    $v0, ($s0)
/* 0AFA90 7F07AF60 AFA40064 */  sw    $a0, 0x64($sp)
/* 0AFA94 7F07AF64 C4840008 */  lwc1  $f4, 8($a0)
/* 0AFA98 7F07AF68 3C0143FA */  li    $at, 0x43FA0000 # 500.000000
/* 0AFA9C 7F07AF6C 44810000 */  mtc1  $at, $f0
/* 0AFAA0 7F07AF70 E7A40058 */  swc1  $f4, 0x58($sp)
/* 0AFAA4 7F07AF74 C486000C */  lwc1  $f6, 0xc($a0)
/* 0AFAA8 7F07AF78 00803025 */  move  $a2, $a0
/* 0AFAAC 7F07AF7C E7A6005C */  swc1  $f6, 0x5c($sp)
/* 0AFAB0 7F07AF80 C4880010 */  lwc1  $f8, 0x10($a0)
/* 0AFAB4 7F07AF84 E7A80060 */  swc1  $f8, 0x60($sp)
/* 0AFAB8 7F07AF88 C48A0008 */  lwc1  $f10, 8($a0)
/* 0AFABC 7F07AF8C E7AA0048 */  swc1  $f10, 0x48($sp)
/* 0AFAC0 7F07AF90 C490000C */  lwc1  $f16, 0xc($a0)
/* 0AFAC4 7F07AF94 E7B0004C */  swc1  $f16, 0x4c($sp)
/* 0AFAC8 7F07AF98 C4920010 */  lwc1  $f18, 0x10($a0)
/* 0AFACC 7F07AF9C E7B20050 */  swc1  $f18, 0x50($sp)
/* 0AFAD0 7F07AFA0 10000014 */  b     .L7F07AFF4
/* 0AFAD4 7F07AFA4 8C830014 */   lw    $v1, 0x14($a0)
.L7F07AFA8:
/* 0AFAD8 7F07AFA8 8E020000 */  lw    $v0, ($s0)
.L7F07AFAC:
/* 0AFADC 7F07AFAC 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 0AFAE0 7F07AFB0 44810000 */  mtc1  $at, $f0
/* 0AFAE4 7F07AFB4 8C4A00A8 */  lw    $t2, 0xa8($v0)
/* 0AFAE8 7F07AFB8 AFAA0064 */  sw    $t2, 0x64($sp)
/* 0AFAEC 7F07AFBC C44403C4 */  lwc1  $f4, 0x3c4($v0)
/* 0AFAF0 7F07AFC0 E7A40058 */  swc1  $f4, 0x58($sp)
/* 0AFAF4 7F07AFC4 C44603C8 */  lwc1  $f6, 0x3c8($v0)
/* 0AFAF8 7F07AFC8 E7A6005C */  swc1  $f6, 0x5c($sp)
/* 0AFAFC 7F07AFCC C44803CC */  lwc1  $f8, 0x3cc($v0)
/* 0AFB00 7F07AFD0 E7A80060 */  swc1  $f8, 0x60($sp)
/* 0AFB04 7F07AFD4 C44A048C */  lwc1  $f10, 0x48c($v0)
/* 0AFB08 7F07AFD8 8C4600A8 */  lw    $a2, 0xa8($v0)
/* 0AFB0C 7F07AFDC E7AA0048 */  swc1  $f10, 0x48($sp)
/* 0AFB10 7F07AFE0 C4500490 */  lwc1  $f16, 0x490($v0)
/* 0AFB14 7F07AFE4 E7B0004C */  swc1  $f16, 0x4c($sp)
/* 0AFB18 7F07AFE8 C4520494 */  lwc1  $f18, 0x494($v0)
/* 0AFB1C 7F07AFEC E7B20050 */  swc1  $f18, 0x50($sp)
/* 0AFB20 7F07AFF0 8C430488 */  lw    $v1, 0x488($v0)
.L7F07AFF4:
/* 0AFB24 7F07AFF4 8FA40064 */  lw    $a0, 0x64($sp)
/* 0AFB28 7F07AFF8 27A70048 */  addiu $a3, $sp, 0x48
/* 0AFB2C 7F07AFFC AFA30010 */  sw    $v1, 0x10($sp)
/* 0AFB30 7F07B000 0FC1E94D */  jal   sub_GAME_7F07A534
/* 0AFB34 7F07B004 E7A00014 */   swc1  $f0, 0x14($sp)
/* 0AFB38 7F07B008 10400021 */  beqz  $v0, .L7F07B090
/* 0AFB3C 7F07B00C 3C0B8003 */   lui   $t3, %hi(D_80036510)
/* 0AFB40 7F07B010 8D6B6510 */  lw    $t3, %lo(D_80036510)($t3)
/* 0AFB44 7F07B014 15600007 */  bnez  $t3, .L7F07B034
/* 0AFB48 7F07B018 00000000 */   nop
/* 0AFB4C 7F07B01C 0C001B9F */  jal   musicTrack1Play
/* 0AFB50 7F07B020 2404002C */   li    $a0, 44
/* 0AFB54 7F07B024 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0AFB58 7F07B028 44816000 */  mtc1  $at, $f12
/* 0AFB5C 7F07B02C 0C00248E */  jal   sndSetScalerApplyVolumeAllSfxSlot
/* 0AFB60 7F07B030 00000000 */   nop
.L7F07B034:
/* 0AFB64 7F07B034 3C0C8003 */  lui   $t4, %hi(g_ExplodeTankOnDeathFlag)
/* 0AFB68 7F07B038 8D8C648C */  lw    $t4, %lo(g_ExplodeTankOnDeathFlag)($t4)
/* 0AFB6C 7F07B03C 3C0E8003 */  lui   $t6, %hi(g_PlayerTankProp)
/* 0AFB70 7F07B040 51800054 */  beql  $t4, $zero, .L7F07B194
/* 0AFB74 7F07B044 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0AFB78 7F07B048 8DCE6450 */  lw    $t6, %lo(g_PlayerTankProp)($t6)
/* 0AFB7C 7F07B04C 51C00051 */  beql  $t6, $zero, .L7F07B194
/* 0AFB80 7F07B050 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0AFB84 7F07B054 0FC26C54 */  jal   get_cur_playernum
/* 0AFB88 7F07B058 00000000 */   nop
/* 0AFB8C 7F07B05C 3C048003 */  lui   $a0, %hi(g_PlayerTankProp)
/* 0AFB90 7F07B060 8C846450 */  lw    $a0, %lo(g_PlayerTankProp)($a0)
/* 0AFB94 7F07B064 2407000D */  li    $a3, 13
/* 0AFB98 7F07B068 8C860014 */  lw    $a2, 0x14($a0)
/* 0AFB9C 7F07B06C 248D002C */  addiu $t5, $a0, 0x2c
/* 0AFBA0 7F07B070 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0AFBA4 7F07B074 AFA0001C */  sw    $zero, 0x1c($sp)
/* 0AFBA8 7F07B078 AFA20014 */  sw    $v0, 0x14($sp)
/* 0AFBAC 7F07B07C AFA00010 */  sw    $zero, 0x10($sp)
/* 0AFBB0 7F07B080 0FC27094 */  jal   explosionCreate
/* 0AFBB4 7F07B084 24850008 */   addiu $a1, $a0, 8
/* 0AFBB8 7F07B088 10000042 */  b     .L7F07B194
/* 0AFBBC 7F07B08C 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F07B090:
/* 0AFBC0 7F07B090 0C001A4C */  jal   bossRunTitleStage
/* 0AFBC4 7F07B094 00000000 */   nop
/* 0AFBC8 7F07B098 1000003E */  b     .L7F07B194
/* 0AFBCC 7F07B09C 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F07B0A0:
/* 0AFBD0 7F07B0A0 24010006 */  li    $at, 6
/* 0AFBD4 7F07B0A4 1441000D */  bne   $v0, $at, .L7F07B0DC
/* 0AFBD8 7F07B0A8 00002025 */   move  $a0, $zero
/* 0AFBDC 7F07B0AC 00002825 */  move  $a1, $zero
/* 0AFBE0 7F07B0B0 00003025 */  move  $a2, $zero
/* 0AFBE4 7F07B0B4 0FC201EC */  jal   currentPlayerSetFadeColour
/* 0AFBE8 7F07B0B8 24070000 */   li    $a3, 0
/* 0AFBEC 7F07B0BC 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0AFBF0 7F07B0C0 44816000 */  mtc1  $at, $f12
/* 0AFBF4 7F07B0C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AFBF8 7F07B0C8 44817000 */  mtc1  $at, $f14
/* 0AFBFC 7F07B0CC 0FC20216 */  jal   currentPlayerSetFadeFrac
/* 0AFC00 7F07B0D0 00000000 */   nop
/* 0AFC04 7F07B0D4 1000002F */  b     .L7F07B194
/* 0AFC08 7F07B0D8 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F07B0DC:
/* 0AFC0C 7F07B0DC 24010007 */  li    $at, 7
/* 0AFC10 7F07B0E0 54410009 */  bnel  $v0, $at, .L7F07B108
/* 0AFC14 7F07B0E4 24010008 */   li    $at, 8
/* 0AFC18 7F07B0E8 0FC1E73C */  jal   solo_char_load
/* 0AFC1C 7F07B0EC 00000000 */   nop
/* 0AFC20 7F07B0F0 3C108008 */  lui   $s0, %hi(g_CurrentPlayer)
/* 0AFC24 7F07B0F4 2610A0B0 */  addiu $s0, %lo(g_CurrentPlayer) # addiu $s0, $s0, -0x5f50
/* 0AFC28 7F07B0F8 8E0F0000 */  lw    $t7, ($s0)
/* 0AFC2C 7F07B0FC 10000024 */  b     .L7F07B190
/* 0AFC30 7F07B100 ADE00034 */   sw    $zero, 0x34($t7)
/* 0AFC34 7F07B104 24010008 */  li    $at, 8
.L7F07B108:
/* 0AFC38 7F07B108 54410007 */  bnel  $v0, $at, .L7F07B128
/* 0AFC3C 7F07B10C 2401000A */   li    $at, 10
/* 0AFC40 7F07B110 0FC1E928 */  jal   maybe_solo_intro_camera_handler
/* 0AFC44 7F07B114 00000000 */   nop
/* 0AFC48 7F07B118 24180004 */  li    $t8, 4
/* 0AFC4C 7F07B11C 1000001C */  b     .L7F07B190
/* 0AFC50 7F07B120 AE180000 */   sw    $t8, ($s0)
/* 0AFC54 7F07B124 2401000A */  li    $at, 10
.L7F07B128:
/* 0AFC58 7F07B128 5441001A */  bnel  $v0, $at, .L7F07B194
/* 0AFC5C 7F07B12C 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0AFC60 7F07B130 0FC26919 */  jal   getPlayerCount
/* 0AFC64 7F07B134 00008025 */   move  $s0, $zero
/* 0AFC68 7F07B138 18400013 */  blez  $v0, .L7F07B188
/* 0AFC6C 7F07B13C 00000000 */   nop
.L7F07B140:
/* 0AFC70 7F07B140 0FC26C43 */  jal   set_cur_player
/* 0AFC74 7F07B144 02002025 */   move  $a0, $s0
/* 0AFC78 7F07B148 00002025 */  move  $a0, $zero
/* 0AFC7C 7F07B14C 00002825 */  move  $a1, $zero
/* 0AFC80 7F07B150 00003025 */  move  $a2, $zero
/* 0AFC84 7F07B154 0FC201EC */  jal   currentPlayerSetFadeColour
/* 0AFC88 7F07B158 24070000 */   li    $a3, 0
/* 0AFC8C 7F07B15C 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0AFC90 7F07B160 44816000 */  mtc1  $at, $f12
/* 0AFC94 7F07B164 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AFC98 7F07B168 44817000 */  mtc1  $at, $f14
/* 0AFC9C 7F07B16C 0FC20216 */  jal   currentPlayerSetFadeFrac
/* 0AFCA0 7F07B170 00000000 */   nop
/* 0AFCA4 7F07B174 0FC26919 */  jal   getPlayerCount
/* 0AFCA8 7F07B178 26100001 */   addiu $s0, $s0, 1
/* 0AFCAC 7F07B17C 0202082A */  slt   $at, $s0, $v0
/* 0AFCB0 7F07B180 1420FFEF */  bnez  $at, .L7F07B140
/* 0AFCB4 7F07B184 00000000 */   nop
.L7F07B188:
/* 0AFCB8 7F07B188 0FC26C43 */  jal   set_cur_player
/* 0AFCBC 7F07B18C 00002025 */   move  $a0, $zero
.L7F07B190:
/* 0AFCC0 7F07B190 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F07B194:
/* 0AFCC4 7F07B194 8FB00028 */  lw    $s0, 0x28($sp)
/* 0AFCC8 7F07B198 27BD0088 */  addiu $sp, $sp, 0x88
/* 0AFCCC 7F07B19C 03E00008 */  jr    $ra
/* 0AFCD0 7F07B1A0 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F07B1A4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F07B1A4
/* 0AFCD4 7F07B1A4 3C038003 */  lui   $v1, %hi(g_CameraMode)
/* 0AFCD8 7F07B1A8 24636494 */  addiu $v1, %lo(g_CameraMode) # addiu $v1, $v1, 0x6494
/* 0AFCDC 7F07B1AC 8C620000 */  lw    $v0, ($v1)
/* 0AFCE0 7F07B1B0 AC600000 */  sw    $zero, ($v1)
/* 0AFCE4 7F07B1B4 3C018003 */  lui   $at, %hi(g_CameraAfterCinema)
/* 0AFCE8 7F07B1B8 AC206498 */  sw    $zero, %lo(g_CameraAfterCinema)($at)
/* 0AFCEC 7F07B1BC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0AFCF0 7F07B1C0 24010001 */  li    $at, 1
/* 0AFCF4 7F07B1C4 14410005 */  bne   $v0, $at, .L7F07B1DC
/* 0AFCF8 7F07B1C8 AFBF0014 */   sw    $ra, 0x14($sp)
/* 0AFCFC 7F07B1CC 0FC1EA6E */  jal   set_camera_mode
/* 0AFD00 7F07B1D0 24040002 */   li    $a0, 2
/* 0AFD04 7F07B1D4 1000002F */  b     .L7F07B294
/* 0AFD08 7F07B1D8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F07B1DC:
/* 0AFD0C 7F07B1DC 24010002 */  li    $at, 2
/* 0AFD10 7F07B1E0 54410008 */  bnel  $v0, $at, .L7F07B204
/* 0AFD14 7F07B1E4 24010009 */   li    $at, 9
/* 0AFD18 7F07B1E8 0FC228CC */  jal   bondviewResetIntroCameraMessageDialogs
/* 0AFD1C 7F07B1EC 00000000 */   nop
/* 0AFD20 7F07B1F0 0FC1EA6E */  jal   set_camera_mode
/* 0AFD24 7F07B1F4 24040003 */   li    $a0, 3
/* 0AFD28 7F07B1F8 10000026 */  b     .L7F07B294
/* 0AFD2C 7F07B1FC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0AFD30 7F07B200 24010009 */  li    $at, 9
.L7F07B204:
/* 0AFD34 7F07B204 10410022 */  beq   $v0, $at, .L7F07B290
/* 0AFD38 7F07B208 24010003 */   li    $at, 3
/* 0AFD3C 7F07B20C 5441000D */  bnel  $v0, $at, .L7F07B244
/* 0AFD40 7F07B210 24010004 */   li    $at, 4
/* 0AFD44 7F07B214 0FC1E928 */  jal   maybe_solo_intro_camera_handler
/* 0AFD48 7F07B218 00000000 */   nop
/* 0AFD4C 7F07B21C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AFD50 7F07B220 44817000 */  mtc1  $at, $f14
/* 0AFD54 7F07B224 44806000 */  mtc1  $zero, $f12
/* 0AFD58 7F07B228 0FC20284 */  jal   currentPlayerStartChrFade
/* 0AFD5C 7F07B22C 00000000 */   nop
/* 0AFD60 7F07B230 0FC1EA6E */  jal   set_camera_mode
/* 0AFD64 7F07B234 24040004 */   li    $a0, 4
/* 0AFD68 7F07B238 10000016 */  b     .L7F07B294
/* 0AFD6C 7F07B23C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0AFD70 7F07B240 24010004 */  li    $at, 4
.L7F07B244:
/* 0AFD74 7F07B244 10410012 */  beq   $v0, $at, .L7F07B290
/* 0AFD78 7F07B248 24010005 */   li    $at, 5
/* 0AFD7C 7F07B24C 54410006 */  bnel  $v0, $at, .L7F07B268
/* 0AFD80 7F07B250 24010006 */   li    $at, 6
/* 0AFD84 7F07B254 0FC1EA6E */  jal   set_camera_mode
/* 0AFD88 7F07B258 24040006 */   li    $a0, 6
/* 0AFD8C 7F07B25C 1000000D */  b     .L7F07B294
/* 0AFD90 7F07B260 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0AFD94 7F07B264 24010006 */  li    $at, 6
.L7F07B268:
/* 0AFD98 7F07B268 14410009 */  bne   $v0, $at, .L7F07B290
/* 0AFD9C 7F07B26C 3C028003 */   lui   $v0, %hi(D_80036510)
/* 0AFDA0 7F07B270 24426510 */  addiu $v0, %lo(D_80036510) # addiu $v0, $v0, 0x6510
/* 0AFDA4 7F07B274 8C4E0000 */  lw    $t6, ($v0)
/* 0AFDA8 7F07B278 25CF0001 */  addiu $t7, $t6, 1
/* 0AFDAC 7F07B27C 29E10003 */  slti  $at, $t7, 3
/* 0AFDB0 7F07B280 10200003 */  beqz  $at, .L7F07B290
/* 0AFDB4 7F07B284 AC4F0000 */   sw    $t7, ($v0)
/* 0AFDB8 7F07B288 0FC1EA6E */  jal   set_camera_mode
/* 0AFDBC 7F07B28C 24040005 */   li    $a0, 5
.L7F07B290:
/* 0AFDC0 7F07B290 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F07B294:
/* 0AFDC4 7F07B294 27BD0018 */  addiu $sp, $sp, 0x18
/* 0AFDC8 7F07B298 03E00008 */  jr    $ra
/* 0AFDCC 7F07B29C 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F07B2A0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F07B2A0
/* 0AFDD0 7F07B2A0 3C088003 */  lui   $t0, %hi(g_IntroSwirl)
/* 0AFDD4 7F07B2A4 8D0864AC */  lw    $t0, %lo(g_IntroSwirl)($t0)
/* 0AFDD8 7F07B2A8 27BDFF70 */  addiu $sp, $sp, -0x90
/* 0AFDDC 7F07B2AC 00046140 */  sll   $t4, $a0, 5
/* 0AFDE0 7F07B2B0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0AFDE4 7F07B2B4 AFB00028 */  sw    $s0, 0x28($sp)
/* 0AFDE8 7F07B2B8 AFA60098 */  sw    $a2, 0x98($sp)
/* 0AFDEC 7F07B2BC 010C5821 */  addu  $t3, $t0, $t4
/* 0AFDF0 7F07B2C0 44801000 */  mtc1  $zero, $f2
/* 0AFDF4 7F07B2C4 C5600018 */  lwc1  $f0, 0x18($t3)
/* 0AFDF8 7F07B2C8 00E08025 */  move  $s0, $a3
/* 0AFDFC 7F07B2CC 44856000 */  mtc1  $a1, $f12
/* 0AFE00 7F07B2D0 4600103C */  c.lt.s $f2, $f0
/* 0AFE04 7F07B2D4 00047140 */  sll   $t6, $a0, 5
/* 0AFE08 7F07B2D8 27A50054 */  addiu $a1, $sp, 0x54
/* 0AFE0C 7F07B2DC 2406FFFF */  li    $a2, -1
/* 0AFE10 7F07B2E0 45000002 */  bc1f  .L7F07B2EC
/* 0AFE14 7F07B2E4 01C83821 */   addu  $a3, $t6, $t0
/* 0AFE18 7F07B2E8 46006083 */  div.s $f2, $f12, $f0
.L7F07B2EC:
/* 0AFE1C 7F07B2EC 3C098008 */  lui   $t1, %hi(g_CurrentPlayer)
/* 0AFE20 7F07B2F0 2529A0B0 */  addiu $t1, %lo(g_CurrentPlayer) # addiu $t1, $t1, -0x5f50
/* 0AFE24 7F07B2F4 240A0003 */  li    $t2, 3
.L7F07B2F8:
/* 0AFE28 7F07B2F8 00067940 */  sll   $t7, $a2, 5
/* 0AFE2C 7F07B2FC 01E72021 */  addu  $a0, $t7, $a3
/* 0AFE30 7F07B300 00E01025 */  move  $v0, $a3
/* 0AFE34 7F07B304 04C10008 */  bgez  $a2, .L7F07B328
/* 0AFE38 7F07B308 00801825 */   move  $v1, $a0
/* 0AFE3C 7F07B30C 0088082B */  sltu  $at, $a0, $t0
/* 0AFE40 7F07B310 10200003 */  beqz  $at, .L7F07B320
/* 0AFE44 7F07B314 00000000 */   nop
/* 0AFE48 7F07B318 1000000E */  b     .L7F07B354
/* 0AFE4C 7F07B31C 01001025 */   move  $v0, $t0
.L7F07B320:
/* 0AFE50 7F07B320 1000000C */  b     .L7F07B354
/* 0AFE54 7F07B324 00601025 */   move  $v0, $v1
.L7F07B328:
/* 0AFE58 7F07B328 0044082B */  sltu  $at, $v0, $a0
/* 0AFE5C 7F07B32C 5020000A */  beql  $at, $zero, .L7F07B358
/* 0AFE60 7F07B330 8C4D0004 */   lw    $t5, 4($v0)
/* 0AFE64 7F07B334 8C580024 */  lw    $t8, 0x24($v0)
.L7F07B338:
/* 0AFE68 7F07B338 33190001 */  andi  $t9, $t8, 1
/* 0AFE6C 7F07B33C 57200006 */  bnezl $t9, .L7F07B358
/* 0AFE70 7F07B340 8C4D0004 */   lw    $t5, 4($v0)
/* 0AFE74 7F07B344 24420020 */  addiu $v0, $v0, 0x20
/* 0AFE78 7F07B348 0043082B */  sltu  $at, $v0, $v1
/* 0AFE7C 7F07B34C 5420FFFA */  bnezl $at, .L7F07B338
/* 0AFE80 7F07B350 8C580024 */   lw    $t8, 0x24($v0)
.L7F07B354:
/* 0AFE84 7F07B354 8C4D0004 */  lw    $t5, 4($v0)
.L7F07B358:
/* 0AFE88 7F07B358 24C60001 */  addiu $a2, $a2, 1
/* 0AFE8C 7F07B35C 31AE0002 */  andi  $t6, $t5, 2
/* 0AFE90 7F07B360 51C00018 */  beql  $t6, $zero, .L7F07B3C4
/* 0AFE94 7F07B364 C4500008 */   lwc1  $f16, 8($v0)
/* 0AFE98 7F07B368 8D230000 */  lw    $v1, ($t1)
/* 0AFE9C 7F07B36C C4460008 */  lwc1  $f6, 8($v0)
/* 0AFEA0 7F07B370 C44A0010 */  lwc1  $f10, 0x10($v0)
/* 0AFEA4 7F07B374 C46404A0 */  lwc1  $f4, 0x4a0($v1)
/* 0AFEA8 7F07B378 C4700498 */  lwc1  $f16, 0x498($v1)
/* 0AFEAC 7F07B37C 46062202 */  mul.s $f8, $f4, $f6
/* 0AFEB0 7F07B380 00000000 */  nop
/* 0AFEB4 7F07B384 46105482 */  mul.s $f18, $f10, $f16
/* 0AFEB8 7F07B388 46124100 */  add.s $f4, $f8, $f18
/* 0AFEBC 7F07B38C E4A4000C */  swc1  $f4, 0xc($a1)
/* 0AFEC0 7F07B390 C446000C */  lwc1  $f6, 0xc($v0)
/* 0AFEC4 7F07B394 E4A60010 */  swc1  $f6, 0x10($a1)
/* 0AFEC8 7F07B398 C44A0010 */  lwc1  $f10, 0x10($v0)
/* 0AFECC 7F07B39C C47004A0 */  lwc1  $f16, 0x4a0($v1)
/* 0AFED0 7F07B3A0 C4440008 */  lwc1  $f4, 8($v0)
/* 0AFED4 7F07B3A4 C4720498 */  lwc1  $f18, 0x498($v1)
/* 0AFED8 7F07B3A8 46105202 */  mul.s $f8, $f10, $f16
/* 0AFEDC 7F07B3AC 00000000 */  nop
/* 0AFEE0 7F07B3B0 46049182 */  mul.s $f6, $f18, $f4
/* 0AFEE4 7F07B3B4 46064281 */  sub.s $f10, $f8, $f6
/* 0AFEE8 7F07B3B8 10000007 */  b     .L7F07B3D8
/* 0AFEEC 7F07B3BC E4AA0014 */   swc1  $f10, 0x14($a1)
/* 0AFEF0 7F07B3C0 C4500008 */  lwc1  $f16, 8($v0)
.L7F07B3C4:
/* 0AFEF4 7F07B3C4 E4B0000C */  swc1  $f16, 0xc($a1)
/* 0AFEF8 7F07B3C8 C452000C */  lwc1  $f18, 0xc($v0)
/* 0AFEFC 7F07B3CC E4B20010 */  swc1  $f18, 0x10($a1)
/* 0AFF00 7F07B3D0 C4440010 */  lwc1  $f4, 0x10($v0)
/* 0AFF04 7F07B3D4 E4A40014 */  swc1  $f4, 0x14($a1)
.L7F07B3D8:
/* 0AFF08 7F07B3D8 14CAFFC7 */  bne   $a2, $t2, .L7F07B2F8
/* 0AFF0C 7F07B3DC 24A5000C */   addiu $a1, $a1, 0xc
/* 0AFF10 7F07B3E0 C5600014 */  lwc1  $f0, 0x14($t3)
/* 0AFF14 7F07B3E4 8FAF0098 */  lw    $t7, 0x98($sp)
/* 0AFF18 7F07B3E8 E7A20058 */  swc1  $f2, 0x58($sp)
/* 0AFF1C 7F07B3EC AFAC0040 */  sw    $t4, 0x40($sp)
/* 0AFF20 7F07B3F0 E7A20010 */  swc1  $f2, 0x10($sp)
/* 0AFF24 7F07B3F4 27A40060 */  addiu $a0, $sp, 0x60
/* 0AFF28 7F07B3F8 27A5006C */  addiu $a1, $sp, 0x6c
/* 0AFF2C 7F07B3FC 27A60078 */  addiu $a2, $sp, 0x78
/* 0AFF30 7F07B400 27A70084 */  addiu $a3, $sp, 0x84
/* 0AFF34 7F07B404 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0AFF38 7F07B408 0FC16C09 */  jal   sub_GAME_7F05B024
/* 0AFF3C 7F07B40C AFAF0018 */   sw    $t7, 0x18($sp)
/* 0AFF40 7F07B410 3C098008 */  lui   $t1, %hi(g_CurrentPlayer)
/* 0AFF44 7F07B414 2529A0B0 */  addiu $t1, %lo(g_CurrentPlayer) # addiu $t1, $t1, -0x5f50
/* 0AFF48 7F07B418 8FA20098 */  lw    $v0, 0x98($sp)
/* 0AFF4C 7F07B41C 8D380000 */  lw    $t8, ($t1)
/* 0AFF50 7F07B420 8FAC0040 */  lw    $t4, 0x40($sp)
/* 0AFF54 7F07B424 C4480000 */  lwc1  $f8, ($v0)
/* 0AFF58 7F07B428 C70603C4 */  lwc1  $f6, 0x3c4($t8)
/* 0AFF5C 7F07B42C C7A20058 */  lwc1  $f2, 0x58($sp)
/* 0AFF60 7F07B430 C4500004 */  lwc1  $f16, 4($v0)
/* 0AFF64 7F07B434 46064280 */  add.s $f10, $f8, $f6
/* 0AFF68 7F07B438 C4480008 */  lwc1  $f8, 8($v0)
/* 0AFF6C 7F07B43C 44807000 */  mtc1  $zero, $f14
/* 0AFF70 7F07B440 E44A0000 */  swc1  $f10, ($v0)
/* 0AFF74 7F07B444 8D390000 */  lw    $t9, ($t1)
/* 0AFF78 7F07B448 C73203C8 */  lwc1  $f18, 0x3c8($t9)
/* 0AFF7C 7F07B44C 3C198003 */  lui   $t9, %hi(g_IntroSwirl)
/* 0AFF80 7F07B450 46128100 */  add.s $f4, $f16, $f18
/* 0AFF84 7F07B454 E4440004 */  swc1  $f4, 4($v0)
/* 0AFF88 7F07B458 8D2D0000 */  lw    $t5, ($t1)
/* 0AFF8C 7F07B45C C5A603CC */  lwc1  $f6, 0x3cc($t5)
/* 0AFF90 7F07B460 46064280 */  add.s $f10, $f8, $f6
/* 0AFF94 7F07B464 E44A0008 */  swc1  $f10, 8($v0)
/* 0AFF98 7F07B468 8D2E0000 */  lw    $t6, ($t1)
/* 0AFF9C 7F07B46C C5D003C4 */  lwc1  $f16, 0x3c4($t6)
/* 0AFFA0 7F07B470 E6100000 */  swc1  $f16, ($s0)
/* 0AFFA4 7F07B474 8D2F0000 */  lw    $t7, ($t1)
/* 0AFFA8 7F07B478 C5F203C8 */  lwc1  $f18, 0x3c8($t7)
/* 0AFFAC 7F07B47C E6120004 */  swc1  $f18, 4($s0)
/* 0AFFB0 7F07B480 8D380000 */  lw    $t8, ($t1)
/* 0AFFB4 7F07B484 C70403CC */  lwc1  $f4, 0x3cc($t8)
/* 0AFFB8 7F07B488 E6040008 */  swc1  $f4, 8($s0)
/* 0AFFBC 7F07B48C 8F3964AC */  lw    $t9, %lo(g_IntroSwirl)($t9)
/* 0AFFC0 7F07B490 032C5821 */  addu  $t3, $t9, $t4
/* 0AFFC4 7F07B494 8D6D0004 */  lw    $t5, 4($t3)
/* 0AFFC8 7F07B498 31AE0004 */  andi  $t6, $t5, 4
/* 0AFFCC 7F07B49C 55C0000E */  bnezl $t6, .L7F07B4D8
/* 0AFFD0 7F07B4A0 8D790024 */   lw    $t9, 0x24($t3)
/* 0AFFD4 7F07B4A4 8D6F0024 */  lw    $t7, 0x24($t3)
/* 0AFFD8 7F07B4A8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AFFDC 7F07B4AC 31F80004 */  andi  $t8, $t7, 4
/* 0AFFE0 7F07B4B0 57000006 */  bnezl $t8, .L7F07B4CC
/* 0AFFE4 7F07B4B4 44814000 */   mtc1  $at, $f8
/* 0AFFE8 7F07B4B8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0AFFEC 7F07B4BC 44810000 */  mtc1  $at, $f0
/* 0AFFF0 7F07B4C0 1000000C */  b     .L7F07B4F4
/* 0AFFF4 7F07B4C4 8D2E0000 */   lw    $t6, ($t1)
/* 0AFFF8 7F07B4C8 44814000 */  mtc1  $at, $f8
.L7F07B4CC:
/* 0AFFFC 7F07B4CC 10000008 */  b     .L7F07B4F0
/* 0B0000 7F07B4D0 46024001 */   sub.s $f0, $f8, $f2
/* 0B0004 7F07B4D4 8D790024 */  lw    $t9, 0x24($t3)
.L7F07B4D8:
/* 0B0008 7F07B4D8 332D0004 */  andi  $t5, $t9, 4
/* 0B000C 7F07B4DC 51A00004 */  beql  $t5, $zero, .L7F07B4F0
/* 0B0010 7F07B4E0 46001006 */   mov.s $f0, $f2
/* 0B0014 7F07B4E4 10000002 */  b     .L7F07B4F0
/* 0B0018 7F07B4E8 46007006 */   mov.s $f0, $f14
/* 0B001C 7F07B4EC 46001006 */  mov.s $f0, $f2
.L7F07B4F0:
/* 0B0020 7F07B4F0 8D2E0000 */  lw    $t6, ($t1)
.L7F07B4F4:
/* 0B0024 7F07B4F4 3C014220 */  li    $at, 0x42200000 # 40.000000
/* 0B0028 7F07B4F8 44811000 */  mtc1  $at, $f2
/* 0B002C 7F07B4FC C5CA04C0 */  lwc1  $f10, 0x4c0($t6)
/* 0B0030 7F07B500 C6060000 */  lwc1  $f6, ($s0)
/* 0B0034 7F07B504 C6080004 */  lwc1  $f8, 4($s0)
/* 0B0038 7F07B508 46025402 */  mul.s $f16, $f10, $f2
/* 0B003C 7F07B50C 00000000 */  nop
/* 0B0040 7F07B510 46008482 */  mul.s $f18, $f16, $f0
/* 0B0044 7F07B514 46123100 */  add.s $f4, $f6, $f18
/* 0B0048 7F07B518 E6040000 */  swc1  $f4, ($s0)
/* 0B004C 7F07B51C 8D2F0000 */  lw    $t7, ($t1)
/* 0B0050 7F07B520 C6040008 */  lwc1  $f4, 8($s0)
/* 0B0054 7F07B524 C5EA04C4 */  lwc1  $f10, 0x4c4($t7)
/* 0B0058 7F07B528 46025402 */  mul.s $f16, $f10, $f2
/* 0B005C 7F07B52C 00000000 */  nop
/* 0B0060 7F07B530 46008182 */  mul.s $f6, $f16, $f0
/* 0B0064 7F07B534 46064480 */  add.s $f18, $f8, $f6
/* 0B0068 7F07B538 E6120004 */  swc1  $f18, 4($s0)
/* 0B006C 7F07B53C 8D380000 */  lw    $t8, ($t1)
/* 0B0070 7F07B540 C70A04C8 */  lwc1  $f10, 0x4c8($t8)
/* 0B0074 7F07B544 46025402 */  mul.s $f16, $f10, $f2
/* 0B0078 7F07B548 00000000 */  nop
/* 0B007C 7F07B54C 46008202 */  mul.s $f8, $f16, $f0
/* 0B0080 7F07B550 46082180 */  add.s $f6, $f4, $f8
/* 0B0084 7F07B554 E6060008 */  swc1  $f6, 8($s0)
/* 0B0088 7F07B558 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0B008C 7F07B55C 8FB00028 */  lw    $s0, 0x28($sp)
/* 0B0090 7F07B560 27BD0090 */  addiu $sp, $sp, 0x90
/* 0B0094 7F07B564 03E00008 */  jr    $ra
/* 0B0098 7F07B568 00000000 */   nop
)
#endif






/**
 * US address 7F07B56C.
 * JP address 7F07BB8C.
 * EU address 7F07B604.
*/
void bondviewFrozenCameraTick(u16 buttons, u16 oldbuttons, struct coord3d *pos, struct coord3d *pos2, struct coord3d *offset, StandTile **stan, struct coord3d *arg6)
{
    s32 i;
    f32 sp38;
    s32 i2;
    f32 sp30 = 0.0f;
    s32 padding2;
    f32 zero = 0.0f;
    void *p;
    struct PadRecord *setupPad;
    
    if ((g_CameraMode == CAMERAMODE_INTRO) || (g_CameraMode == CAMERAMODE_FADESWIRL))
    {
        if (g_CameraMode == CAMERAMODE_INTRO)
        {
            if ((D_800364A4 < 120.0f) && ((D_800364A4 + g_GlobalTimerDelta) >= 120.0f))
            {
#if defined(VERSION_US)
                setFontTables(ptrFontZurichBoldChars, ptrFontZurichBold);
                hudmsgBottomShow(ptr_random06cam_entry->lang1c.lang_ptr);
#else
                hudmsgBottomShow(ptr_random06cam_entry->lang1c.lang_ptr, ptrFontZurichBoldChars, ptrFontZurichBold);
#endif
            }

            if (ptr_random06cam_entry->lang20.lang_ptr != NULL)
            {
                if ((D_800364A4 < 300.0f) && ((D_800364A4 + g_GlobalTimerDelta) >= 300.0f))
                {
#if defined(VERSION_US)
                    hudmsgBottomShow(ptr_random06cam_entry->lang20.lang_ptr);
#else
                    hudmsgBottomShow(ptr_random06cam_entry->lang20.lang_ptr, ptrFontZurichBoldChars, ptrFontZurichBold);
#endif
                }
                
                if (D_800364A4 > 480.0f)
                {
                    g_CameraAfterCinema = CAMERAMODE_INTRO;
                }
            }
            else if (D_800364A4 > 300.0f)
            {
                g_CameraAfterCinema = CAMERAMODE_INTRO;
            }

            D_800364A4 += g_GlobalTimerDelta;

            if ((lvlGetControlsLockedFlag() == 0)
                && (buttons & ~oldbuttons & (CONT_A | B_BUTTON | Z_TRIG | START_BUTTON | CONT_R | CONT_L)))
            {
                g_CameraAfterCinema = CAMERAMODE_INTRO;
            }
        }
        else if (g_CurrentPlayer->colourfadetimemax60 < 0.0f)
        {
            g_CameraAfterCinema = CAMERAMODE_INTRO;
        }

        pos->f[0] = ptr_random06cam_entry->unk04.fval;
        pos->f[1] = ptr_random06cam_entry->unk08.fval;
        pos->f[2] = ptr_random06cam_entry->unk0C.fval;

        pos2->f[0] = pos->f[0] + (cosf(ptr_random06cam_entry->unk14.fval) * sinf(ptr_random06cam_entry->unk10.fval));
        pos2->f[1] = pos->f[1] + sinf(ptr_random06cam_entry->unk14.fval);
        pos2->f[2] = pos->f[2] - (cosf(ptr_random06cam_entry->unk14.fval) * cosf(ptr_random06cam_entry->unk10.fval));
        
        p = &g_CurrentSetup.pads[ptr_random06cam_entry->unk18];
        setupPad = p;
        *stan = setupPad->stan;
        
        arg6->f[0] = setupPad->pos.f[0];
        arg6->f[1] = setupPad->pos.f[1];
        arg6->f[2] = setupPad->pos.f[2];
    }
    else if (g_CameraMode == CAMERAMODE_MP)
    {
        /**
        * CAMERAMODE_MP: Perfect Dark method playerTickMpSwirl
        */
        if (sub_GAME_7F09B4D8(get_cur_playernum()) == 0)
        {
            for (i2=0; i2<g_ClockTimer; i2++)
            {
                if (g_MpSwirlAngleDegrees < 179.5f)
                {
                    if (g_MpSwirlAngleDegrees < -20.0f)
                    {
                        g_MpSwirlRotateSpeed += 0.1f;
                    }
                    
                    if (g_MpSwirlAngleDegrees > 110.0f)
                    {
                        g_MpSwirlRotateSpeed -= 0.1f;
                    }
                    
                    g_MpSwirlAngleDegrees += g_MpSwirlRotateSpeed;
                }
#if defined(VERSION_EU)
                if (g_MpSwirlAngleDegrees >= 179.5f)
#else
                else
#endif
                {
                    g_MpSwirlAngleDegrees = 180.0f;
                }
            
                if (g_MpSwirlAngleDegrees > 80.0f)
                {
                    if (g_MpSwirlDistance > 60.0f)
                    {
                        g_MpSwirlForwardSpeed -= 0.1f;
                    }
                    else
                    {
                        g_MpSwirlForwardSpeed += 0.015f;
                    }
                    
                    g_MpSwirlDistance += g_MpSwirlForwardSpeed;
                    
                    if (g_MpSwirlDistance < 1.0f)
                    {
                        g_MpSwirlDistance = 1.0f;
                    }
                }
            }
        }

        sp38 = ((g_MpSwirlAngleDegrees - g_CurrentPlayer->vv_theta) * M_PI_F) / 180.0f;
        
        pos->f[0] = g_CurrentPlayer->field_488.pos.f[0] + (sinf(sp38) * g_MpSwirlDistance);
        pos->f[1] = g_CurrentPlayer->field_488.pos.f[1] + (g_MpSwirlDistance * 0.08f);
        pos->f[2] = g_CurrentPlayer->field_488.pos.f[2] + (cosf(sp38) * g_MpSwirlDistance);

        pos2->f[0] = g_CurrentPlayer->field_488.pos.f[0];
        pos2->f[1] = g_CurrentPlayer->field_488.pos.f[1];
        pos2->f[2] = g_CurrentPlayer->field_488.pos.f[2];
        
        *stan = g_CurrentPlayer->prop->stan;
        
        arg6->f[0] = g_CurrentPlayer->field_488.pos.f[0];
        arg6->f[1] = g_CurrentPlayer->field_488.pos.f[1] + (g_MpSwirlDistance * 0.08f);
        arg6->f[2] = g_CurrentPlayer->field_488.pos.f[2];

#if defined(VERSION_EU)
        if (((sub_GAME_7F09B4D8(get_cur_playernum()) + 1) == getPlayerCount()) && (g_MpSwirlDistance < 5.0f))
        {
            g_CameraAfterCinema = CAMERAMODE_INTRO;
        }
#else
        if (g_MpSwirlDistance < 5.0f)
        {
            g_CameraAfterCinema = CAMERAMODE_INTRO;
        }
#endif
    }
    else if (g_CameraMode == CAMERAMODE_SWIRL)
    {
        D_800364A4 += g_GlobalTimerDelta;
        
        while (g_IntroSwirl[D_800364A8].unk18.fval <= D_800364A4)
        {
            if (!(g_IntroSwirl[D_800364A8 + 3].unk04 & 1))
            {
                D_800364A4 -= g_IntroSwirl[D_800364A8].unk18.fval;
                D_800364A8++;
            }
            else
            {
                D_800364A4 = g_IntroSwirl[D_800364A8].unk18.fval;
                g_CameraAfterCinema = CAMERAMODE_INTRO;
                break;
            }
        }
        
        sp30 += (g_IntroSwirl[D_800364A8].unk18.fval - D_800364A4);

        for (i = D_800364A8 + 1; !(g_IntroSwirl[i+2].unk04 & 1); i++)
        {
            sp30 += g_IntroSwirl[i].unk18.fval;
        }

        if ((sp30 < 30.0f) && ((sp30 + g_GlobalTimerDelta) >= 30.0f))
        {
            currentPlayerStartChrFade(30.0f, 0.0f);
        }

        if (D_8003649C != 0)
        {
            if (currentPlayerIsFadeComplete() != 0)
            {
                g_CameraAfterCinema = CAMERAMODE_INTRO;
            }
        }

        if ((sp30 > 60.0f) && (D_8003649C == 0))
        {
            if ((lvlGetControlsLockedFlag() == 0) 
                && (buttons & ~oldbuttons & (A_BUTTON | B_BUTTON | Z_TRIG | START_BUTTON | L_TRIG | R_TRIG)))
            {
                D_8003649C = 1;
                currentPlayerSetFadeColour(0, 0, 0, g_CurrentPlayer->colourscreenfrac);
                        
                if (currentPlayerIsFadeComplete() != 0)
                {
                    currentPlayerSetFadeFrac(60.0f, 1.0f);
                }
                else
                {
                    currentPlayerSetFadeFrac(g_CurrentPlayer->colourfadetime60, 1.0f);
                }
            }
        }

        sub_GAME_7F07B2A0(D_800364A8, D_800364A4, pos, pos2);

        if (g_IntroSwirl[D_800364A8].unk1C >= 0)
        {
            p = &g_CurrentSetup.pads[g_IntroSwirl[D_800364A8].unk1C];
            setupPad = p;
            *stan = setupPad->stan;
            
            arg6->f[0] = setupPad->pos.f[0];
            arg6->f[1] = setupPad->pos.f[1];
            arg6->f[2] = setupPad->pos.f[2];
        }
        else
        {
            *stan = g_CurrentPlayer->field_488.current_tile_ptr;
            arg6->f[0] = g_CurrentPlayer->field_488.collision_position.f[0];
            arg6->f[1] = g_CurrentPlayer->field_488.collision_position.f[1];
            arg6->f[2] = g_CurrentPlayer->field_488.collision_position.f[2];
        }
    }
    else if ((g_CameraMode == CAMERAMODE_DEATH_CAM_FIRST) || (g_CameraMode == CAMERAMODE_DEATH_CAM_SECOND))
    {
        if (g_CameraMode == CAMERAMODE_DEATH_CAM_FIRST)
        {
            D_800364A4 += g_GlobalTimerDelta;
            
            if (g_CurrentPlayer->ptr_char_objectinstance != NULL)
            {
                if (objecthandlerGetModelField28((Model *) g_CurrentPlayer->ptr_char_objectinstance)
                    >= sub_GAME_7F06F5C4((Model *) g_CurrentPlayer->ptr_char_objectinstance))
                {
                    g_CameraAfterCinema = CAMERAMODE_INTRO;
                }
            }
            else if (D_800364A4 >= 180.0f)
            {
                g_CameraAfterCinema = CAMERAMODE_INTRO;
            }
            
            if ((buttons & ~oldbuttons & (CONT_A | B_BUTTON | Z_TRIG | START_BUTTON))
                && (g_CurrentPlayer->bonddead != 0)
                && (g_CurrentPlayer->redbloodfinished != 0)
                && (g_CurrentPlayer->deathanimfinished != 0))
            {
                g_CameraAfterCinema = CAMERAMODE_INTRO;
                D_80036510 = CAMERAMODE_FADESWIRL;
            }
        }
        else if (g_CameraMode == CAMERAMODE_DEATH_CAM_SECOND)
        {
            D_800364A4 += g_GlobalTimerDelta;
            
            if (g_CurrentPlayer->colourfadetimemax60 < 0.0f)
            {
                g_CameraAfterCinema = CAMERAMODE_INTRO;
            }
            
            if ((buttons & ~oldbuttons & (CONT_A | B_BUTTON | Z_TRIG | START_BUTTON))
                && (g_CurrentPlayer->bonddead != 0)
                && (g_CurrentPlayer->redbloodfinished != 0)
                && (g_CurrentPlayer->deathanimfinished != 0))
            {
                D_80036510 = CAMERAMODE_FADESWIRL;
            }
        }

        pos->f[0] = flt_CODE_bss_800799E8.f[0];
        pos->f[1] = flt_CODE_bss_800799E8.f[1];
        pos->f[2] = flt_CODE_bss_800799E8.f[2];
    
        if (dword_CODE_bss_800799F4 == g_CurrentPlayer->prop)
        {
            pos2->f[0] = g_CurrentPlayer->field_3C4;
            pos2->f[1] = g_CurrentPlayer->field_3C8;
            pos2->f[2] = g_CurrentPlayer->field_3CC;
        }
        else
        {
            pos2->f[0] = dword_CODE_bss_800799F4->pos.f[0];
            pos2->f[1] = dword_CODE_bss_800799F4->pos.f[1];
            pos2->f[2] = dword_CODE_bss_800799F4->pos.f[2];
        }
    
        *stan = g_CurrentPlayer->field_488.current_tile_ptr;
    
        arg6->f[0] = g_CurrentPlayer->field_488.collision_position.f[0];
        arg6->f[1] = g_CurrentPlayer->field_488.collision_position.f[1];
        arg6->f[2] = g_CurrentPlayer->field_488.collision_position.f[2];
    }
    else if (g_CameraMode == CAMERAMODE_POSEND)
    {
        if (dword_CODE_bss_800799F8 != NULL)
        {
            pos->f[0] = dword_CODE_bss_800799F8->pos.f[0];
            pos->f[1] = dword_CODE_bss_800799F8->pos.f[1];
            pos->f[2] = dword_CODE_bss_800799F8->pos.f[2];
            
            pos2->f[0] = g_CurrentPlayer->field_3C4;
            pos2->f[1] = g_CurrentPlayer->field_3C8;
            pos2->f[2] = g_CurrentPlayer->field_3CC;
            
            *stan = dword_CODE_bss_800799F8->stan;
            
            arg6->f[0] = dword_CODE_bss_800799F8->pos.f[0];
            arg6->f[1] = dword_CODE_bss_800799F8->pos.f[1];
            arg6->f[2] = dword_CODE_bss_800799F8->pos.f[2];
            
            return;
        }
        
        if (gBondViewCutscene != NULL)
        {
            if (isNotBoundPad(gBondViewCutscene->pad))
            {
                p = &g_CurrentSetup.pads[gBondViewCutscene->pad];
            }
            else
            {
                p = &g_CurrentSetup.boundpads[getBoundPadNum(gBondViewCutscene->pad)];
            }
            
            pos->f[0] = gBondViewCutscene->pos.f[0];
            pos->f[1] = gBondViewCutscene->pos.f[1];
            pos->f[2] = gBondViewCutscene->pos.f[2];
            
            setupPad = p;
            *stan = setupPad->stan;
        
            arg6->f[0] = setupPad->pos.f[0];
            arg6->f[1] = setupPad->pos.f[1];
            arg6->f[2] = setupPad->pos.f[2];
            
            if (dword_CODE_bss_80079A18 == CAMERAMODE_INTRO)
            {
                pos2->f[0] = g_CurrentPlayer->field_3C4;
                pos2->f[1] = g_CurrentPlayer->field_3C8;
                pos2->f[2] = g_CurrentPlayer->field_3CC;
            }
            else
            {
                pos2->f[0] = pos->f[0] + (cosf(gBondViewCutscene->verta) * sinf(gBondViewCutscene->theta));
                pos2->f[1] = pos->f[1] + sinf(gBondViewCutscene->verta);
                pos2->f[2] = pos->f[2] - (cosf(gBondViewCutscene->verta) * cosf(gBondViewCutscene->theta));
            }
            
            return;
        }

        if (isNotBoundPad(dword_CODE_bss_80079A14))
        {
            setupPad = &g_CurrentSetup.pads[dword_CODE_bss_80079A14];
        }
        else
        {
            setupPad = (struct PadRecord*)&g_CurrentSetup.boundpads[getBoundPadNum(dword_CODE_bss_80079A14)];
        }
        
        *stan = setupPad->stan;
        
        arg6->f[0] = setupPad->pos.f[0];
        arg6->f[1] = setupPad->pos.f[1];
        arg6->f[2] = setupPad->pos.f[2];

        pos2->f[0] = setupPad->pos.f[0] + cosf(flt_CODE_bss_80079A00) * 0.0f;
        pos2->f[1] = setupPad->pos.f[1] + flt_CODE_bss_80079A10;
        pos2->f[2] = setupPad->pos.f[2] + sinf(flt_CODE_bss_80079A00) * 0.0f;
        
        pos->f[0] = setupPad->pos.f[0] + (sinf(flt_CODE_bss_80079A00) * flt_CODE_bss_80079A08) + cosf(flt_CODE_bss_80079A00) * 0.0f;
        pos->f[1] = setupPad->pos.f[1] + flt_CODE_bss_80079A10 + flt_CODE_bss_80079A0C;
        pos->f[2] = setupPad->pos.f[2] + (cosf(flt_CODE_bss_80079A00) * flt_CODE_bss_80079A08) + sinf(flt_CODE_bss_80079A00) * 0.0f;

        flt_CODE_bss_80079A00 += flt_CODE_bss_80079A04 * g_GlobalTimerDelta;
        
        while (flt_CODE_bss_80079A00 >= M_TAU_F)
        {
            flt_CODE_bss_80079A00 -= M_TAU_F;
        }
        
        while (flt_CODE_bss_80079A00 < 0.0f)
        {
            flt_CODE_bss_80079A00 += M_TAU_F;
        }
    }
}



//begin bondmove.c per pd

void sub_GAME_7F07C540(s32 arg0)
{
    g_CurrentPlayer->field_42c = arg0;
}

void set_BONDdata_lookahead_setting(s32 arg0)
{
    g_CurrentPlayer->automovecentreenabled = arg0;
}

s32 get_BONDdata_lookahead_setting(void)
{
    return g_CurrentPlayer->automovecentreenabled;
}

void set_BONDdata_autoaim_y(s32 param_1)
{
  g_CurrentPlayer->autoyaimenabled = param_1;
}






/**
 * Address 0x7F07C580.
 */
s32 get_BONDdata_autoaim_y(void)
{
    if (getPlayerCount() == 1)
    {
        return g_CurrentPlayer->autoyaimenabled;
    }
    return (s32) g_playerPerm->autoaim;
}





int redirect_get_BONDdata_autoaim_y(void) {
    // Node 0
    return get_BONDdata_autoaim_y();
}

s32 get_BONDdata_is_aiming(void) {
  return g_CurrentPlayer->insightaimmode;
}





/**
 * Updates autoyaimtime60 by g_ClockTimer.
 * Will update player->autoaimy if new autoyaimtime60 < 0 or autoaim_target != g_CurrentPlayer->autoaim_target_y.
 * 
 * Address 0x7F07C5F0.
 */
void bondviewUpdateYAutoAimTime(struct PropRecord *autoaim_target, f32 auto_aim_y)
{
    if (g_CurrentPlayer->autoyaimtime60 >= 0)
    {
        g_CurrentPlayer->autoyaimtime60 = g_CurrentPlayer->autoyaimtime60 - g_ClockTimer;
    }

    if (autoaim_target != g_CurrentPlayer->autoaim_target_y)
    {
        if (g_CurrentPlayer->autoyaimtime60 < 0)
        {
            g_CurrentPlayer->autoyaimtime60 = BONDVIEW_AUTOAIM_TIME;
            g_CurrentPlayer->autoaim_target_y = autoaim_target;
        }
        else
        {
            return;
        }
    }

    g_CurrentPlayer->autoaimy = auto_aim_y;
}





void set_BONDdata_autoaim_x(s32 param_1) {
  g_CurrentPlayer->autoxaimenabled = param_1;
  return;
}





/**
 * Address 0x7F07C668.
 */
s32 get_BONDdata_autoaim_x(void)
{
    if (getPlayerCount() == 1)
    {
        return g_CurrentPlayer->autoxaimenabled;
    }
    return (s32) g_playerPerm->autoaim;
}






int redirect_get_BONDdata_autoaim_x(void) {
    return get_BONDdata_autoaim_x();
}






/**
 * Updates autoxaimtime60 by g_ClockTimer.
 * Will update player->autoaimx if new autoxaimtime60 < 0 or autoaim_target_x != g_CurrentPlayer->autoaim_target_x.
 * 
 * Address 0x7F07C6C8.
 */
void bondviewUpdateXAutoAimTime(struct PropRecord *autoaim_target, f32 auto_aim_x)
{
    if (g_CurrentPlayer->autoxaimtime60 >= 0)
    {
        g_CurrentPlayer->autoxaimtime60 = g_CurrentPlayer->autoxaimtime60 - g_ClockTimer;
    }

    if (autoaim_target != g_CurrentPlayer->autoaim_target_x)
    {
        if (g_CurrentPlayer->autoxaimtime60 < 0)
        {
            g_CurrentPlayer->autoxaimtime60 = BONDVIEW_AUTOAIM_TIME;
            g_CurrentPlayer->autoaim_target_x = autoaim_target;
        }
        else
        {
            return;
        }
    }

    g_CurrentPlayer->autoaimx = auto_aim_x;

}


void change_player_pos_to_target(struct collision434 *col, coord3d *pos, StandTile *stan)
{
    f32 store_x;
    f32 store_x2;
    f32 store_z;
    f32 store_y;
    col->collision_position.x = pos->x;
    store_x = col->collision_position.x;
    col->collision_position.y = pos->y;
    store_y = col->collision_position.y;
    col->collision_position.z = pos->z;
    store_z = col->collision_position.z;
    store_x2 = pos->x;
    col->current_tile_ptr = stan;
    col->current_tile_ptr_for_portals = stan;
    col->applied_view.y = 0.0f;
    col->applied_view.z = 0.0f;
    col->applied_view2.x = 0.0f;
    col->applied_view2.z = store_x2 * 0.0f;
    col->theta_transform.x = 0.0f;
    col->theta_transform.y = 0.0f;
    col->pos.x = store_x;
    col->pos3.x = store_x;
    col->applied_view.x = 1.0f;
    col->applied_view2.y = 1.0f;
    col->theta_transform.z = 1.0f;
    col->pos.y = store_y;
    col->pos3.y = store_y;
    col->pos.z = store_z;
    col->pos3.z = store_z;
    col->collision_radius = 30;
}


/**
 * US address 7F07C7B4.
*/
void bondviewTankModelRotationRelated(void) {
    struct ObjectRecord *obj;
    struct coord3d *sp68;
    struct coord3d *sp64;
    Mtxf sp24;
    ModelNode **temp_v0;

    if (g_PlayerTankProp != NULL)
    {
        obj = g_PlayerTankProp->obj;
        
        /// TODO: Fix Model struct Data type.
        temp_v0 = obj->model->obj->Switches;
        sp68 = (struct coord3d *)temp_v0[2]->Data;
        sp64 = (struct coord3d *)temp_v0[1]->Data;
        matrix_4x4_set_rotation_around_y(M_TAU_F - g_TankTurretOrientationAngleRad, &sp24);
        g_TankModelPositionOffset.f[0] = sp68->f[0];
        g_TankModelPositionOffset.f[1] = sp68->f[1];
        g_TankModelPositionOffset.f[2] = sp68->f[2];
        mtx4RotateVecInPlace(&sp24, g_TankModelPositionOffset.f);
        g_TankModelPositionOffset.f[0] += sp64->f[0];
        g_TankModelPositionOffset.f[1] += sp64->f[1];
        g_TankModelPositionOffset.f[2] += sp64->f[2];
    }
}



/**
 * Address 0x7F07C888.
*/
void bondviewGetTankCollisionBounds(struct rect4f *tank_collision_bounds, struct coord3d *collision_position, f32 tank_orientation_angle)
{
    ObjectRecord *sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    struct ModelRoData_BoundingBoxRecord *bbox;

    sp4C = g_PlayerTankProp->obj;

    bbox = chrobjGetBboxFromObjectRecord(sp4C);

    sp44 = bbox->Bounds.xmin - g_TankModelPositionOffset.f[0];
    sp40 = bbox->Bounds.xmax - g_TankModelPositionOffset.f[0];
    
    sp3C = bbox->Bounds.zmin - g_TankModelPositionOffset.f[2];
    sp38 = bbox->Bounds.zmax - g_TankModelPositionOffset.f[2];

    sp34 = sp4C->model->scale * cosf(tank_orientation_angle);
    sp48 = sp4C->model->scale * sinf(tank_orientation_angle);
    
    tank_collision_bounds->points[0].f[0] = collision_position->f[0] + (-sp3C * sp48) + (sp44 * sp34);
    tank_collision_bounds->points[0].f[1] = collision_position->f[2] + (sp3C * sp34) + (sp44 * sp48);

    tank_collision_bounds->points[1].f[0] = collision_position->f[0] + (-sp3C * sp48) + (sp40 * sp34);
    tank_collision_bounds->points[1].f[1] = collision_position->f[2] + (sp3C * sp34) + (sp40 * sp48);

    tank_collision_bounds->points[2].f[0] = collision_position->f[0] + (-sp38 * sp48) + (sp40 * sp34);
    tank_collision_bounds->points[2].f[1] = collision_position->f[2] + (sp38 * sp34) + (sp40 * sp48);
    
    tank_collision_bounds->points[3].f[0] = collision_position->f[0] + (-sp38 * sp48) + (sp44 * sp34);
    tank_collision_bounds->points[3].f[1] = collision_position->f[2] + (sp38 * sp34) + (sp44 * sp48);
}



/**
 * Address 0x7F07CA2C.
*/
s32 bondviewTestLineUnobstructed(StandTile **pTile, f32 p_x, f32 p_z, f32 dest_x, f32 dest_z, s32 objFlags, struct coord3d *coord_p, struct coord3d *coord_dest)
{
    s32 temp_v0;

    temp_v0 = stanTestLineUnobstructed(pTile, p_x, p_z, dest_x, dest_z, objFlags, 0.0f, 1.0f, 0.0f, 1.0f);
    if ((temp_v0 == 0) && (coord_p != NULL))
    {
        coord_p->f[0] = p_x;
        coord_p->f[1] = 0.0f;
        coord_p->f[2] = p_z;
        coord_dest->f[0] = dest_x;
        coord_dest->f[1] = 0.0f;
        coord_dest->f[2] = dest_z;
    }

    return temp_v0;
}





/**
 * Address 0x7F07CAC8.
*/
s32 bondviewTankCollisionStatus(struct coord3d *collision_position, StandTile *arg1, f32 tank_orientation_angle, struct coord3d *arg3, struct coord3d *arg4)
{
    StandTile *spBC;
    s32 stack_padding;
    struct rect4f tank_collision_bounds;
    s32 sp94;
    f32 temp_f0;
    
    Model *sp8C;

    ModelNode **switches;
    struct coord3d *temp_a1;
    struct coord3d *temp_a2;
    struct coord3d sp74;
    Mtxf sp34;
    struct coord3d *temp_v1;

    spBC = arg1;
    sp94 = 0;

    bondviewGetTankCollisionBounds(&tank_collision_bounds, collision_position, tank_orientation_angle);
    
    if (g_PlayerTankProp != NULL)
    {
        sub_GAME_7F03D058(g_PlayerTankProp, 0);
    }

    if ((bondviewTestLineUnobstructed(&spBC, collision_position->f[0], collision_position->f[2], tank_collision_bounds.points[0].f[0], tank_collision_bounds.points[0].f[1], 0x213, arg3, arg4) != 0) 
        && (bondviewTestLineUnobstructed(&spBC, tank_collision_bounds.points[0].f[0], tank_collision_bounds.points[0].f[1], tank_collision_bounds.points[1].f[0], tank_collision_bounds.points[1].f[1], 0x213, arg3, arg4) != 0) 
        && (bondviewTestLineUnobstructed(&spBC, tank_collision_bounds.points[1].f[0], tank_collision_bounds.points[1].f[1], tank_collision_bounds.points[2].f[0], tank_collision_bounds.points[2].f[1], 0x213, arg3, arg4) != 0)
        && (bondviewTestLineUnobstructed(&spBC, tank_collision_bounds.points[2].f[0], tank_collision_bounds.points[2].f[1], tank_collision_bounds.points[3].f[0], tank_collision_bounds.points[3].f[1], 0x213, arg3, arg4) != 0)
        && (bondviewTestLineUnobstructed(&spBC, tank_collision_bounds.points[3].f[0], tank_collision_bounds.points[3].f[1], tank_collision_bounds.points[0].f[0], tank_collision_bounds.points[0].f[1], 0x213, arg3, arg4) != 0))
    {
        sp94 = 1;

        if (g_PlayerTankProp != NULL)
        {
            ObjectRecord *obj = g_PlayerTankProp->obj;
            sp8C = obj->model;
            switches = sp8C->obj->Switches;

            temp_v1 = switches[3]->Data;
            temp_a1 = switches[4]->Data;
            temp_a2 = switches[2]->Data;

            sp74.f[0] = temp_a1->f[0] + temp_v1->f[0] - temp_a2->f[0];
            sp74.f[1] = 0.0f;
            sp74.f[2] = temp_a1->f[2] + temp_v1->f[2] - temp_a2->f[2];

            temp_f0 = tank_orientation_angle + g_TankTurretOrientationAngleRad;

            if (temp_f0 >= M_TAU_F)
            {
                temp_f0 -= M_TAU_F;
            }

            if (temp_f0 < 0.0f)
            {
                temp_f0 += M_TAU_F;
            }

            matrix_4x4_set_rotation_around_y(M_TAU_F - temp_f0, &sp34);
            mtx4RotateVecInPlace(&sp34, (f32*)&sp74);

            sp74.f[0] *= sp8C->scale;
            sp74.f[2] *= sp8C->scale;

            sp74.f[0] += collision_position->f[0];
            sp74.f[2] += collision_position->f[2];

            spBC = arg1;
            
            if (bondviewTestLineUnobstructed(&spBC, collision_position->f[0], collision_position->f[2], sp74.f[0], sp74.f[2], 0x213, arg3, arg4) == 0)
            {
                sp94 = 0;
            }

        }
    }

    if (g_PlayerTankProp != NULL)
    {
        sub_GAME_7F03D058(g_PlayerTankProp, 1);
    }

    return sp94;
}




/**
 * Address 0x7F07CDA8.
*/
s32 bondviewCallTankCollisionStatus(struct coord3d *collision_position, StandTile *arg1, f32 tank_orientation_angle)
{
    return bondviewTankCollisionStatus(collision_position, arg1, tank_orientation_angle, NULL, NULL);
}





/**
 * Address 0x7F07CDD4.
*/
s32 sub_GAME_7F07CDD4(struct coord3d *arg0, f32 arg1, StandTile **arg2)
{
    StandTile *sp3C;
    s32 unused_padding[2];

    sp3C = g_CurrentPlayer->field_488.current_tile_ptr;

    if ((
        stanTestLineUnobstructed(
            &sp3C,
            g_CurrentPlayer->field_488.collision_position.f[0],
            g_CurrentPlayer->field_488.collision_position.f[2], 
            arg0->f[0],
            arg0->f[2],
            0,
            0.0f,
            1.0f,
            0.0f,
            1.0f) != 0)
        && (bondviewCallTankCollisionStatus(arg0, sp3C, arg1) != 0))
    {
        *arg2 = sp3C;
        return 1;
    }

    return 0;
}





bool isBondInTank(void)
{
    return in_tank_flag;
}






struct PropRecord *get_ptr_for_players_tank(void)
{
    if (in_tank_flag == 1)
    {
        return g_PlayerTankProp;
    }

    return 0;
}





/**
 * Sets paraameter position based on global variables g_TankOrientationAngle, g_TankTurretOrientationAngleRad, g_TankTurretVerticalAngle.
 * 
 * Address 0x7F07CEB0.
 */
void bondviewSet3dCoord7F07CEB0(coord3d *arg0)
{
    f32 f;

    f = g_TankOrientationAngle + g_TankTurretOrientationAngleRad;

    if (f >= M_TAU_F)
    {
        f = f - M_TAU_F;
    }

    if (f < 0.0f)
    {
        f = f + M_TAU_F;
    }

    arg0->f[0] = -sinf(f) * cosf(g_TankTurretVerticalAngle);
    arg0->f[1] = sinf(g_TankTurretVerticalAngle);
    arg0->f[2] = cosf(f) * cosf(g_TankTurretVerticalAngle);
}






/**
 * Unreferenced.
 * 
 * Returns global variable g_TankTurretVerticalAngle, which is in radians.
 * 
 * Address 0x7F07CF80.
 */
f32 bondviewGet8003646CRad(void)
{
    return g_TankTurretVerticalAngle;
}



/**
 * Address 0x7F07CF8C.
*/
s32 bondviewTryMoveToStan(struct coord3d *arg0, StandTile **stan)
{
    s32 sp94;
    StandTile *sp90;
    s32 sp8C;
    f32 height;
    f32 always_30;
    f32 collision_radius;
    s32 sp7C;
    struct TankRecord *tank;
    s32 stack_padding[11];
    struct StandTileLocusCallbackRecord sp3C;

    sp94 = 0;

    if ((in_tank_flag == 1) && (g_EnterTankAudioState != TANK_RUN_STATE_NOT_RUNNING))
    {
        sp94 = sub_GAME_7F07CDD4(arg0, g_TankOrientationAngle, stan);
    }
    else
    {
        sp90 = g_CurrentPlayer->field_488.current_tile_ptr;

        if (obj_collision_flag != 0)
        {
            sp8C = 0x1F;
        }
        else
        {
            sp8C = 0;
        }

        bondviewGetCollisionRadius(g_CurrentPlayer->prop, &collision_radius, &height, &always_30);

        if (g_WorldTankProp != NULL)
        {
            sub_GAME_7F03D058(g_WorldTankProp, 0);
        }

        sub_GAME_7F03D058(g_CurrentPlayer->prop, 0);
        sp7C = stanTileDistanceRelated(&sp90, arg0->f[0], arg0->f[2], collision_radius, &sp3C);
        
        if (stanGetLocusField0(&sp3C) != 0)
        {
            g_CurrentPlayer->autocrouchpos = 0;
        }

        if ((stanTestLineUnobstructed(
                &sp90,
                g_CurrentPlayer->field_488.collision_position.f[0],
                g_CurrentPlayer->field_488.collision_position.f[2],
                arg0->f[0],
                arg0->f[2],
                sp8C,
                height,
                always_30,
                0.0f,
                1.0f) != 0)
            && stanTestVolume(&sp90, arg0->f[0], arg0->f[2], collision_radius, sp8C, height, always_30) < 0)
        {
            if (g_CurrentPlayer->ducking_height_offset == FULL_CROUCH_OFFSET || sp7C < 0)
            {
                if (stanGetLocusCount(&sp3C) == 0 && sub_GAME_7F0B26B8(&sp90, arg0->f[0], arg0->f[2], collision_radius, g_CurrentPlayer->field_488.collision_position.f[1] + 175.0f) >= 0)
                {
                    goto block_20;
                }
                else
                {
                    *stan = sp90;
                    sp94 = 1;                
                }
            }
            else
            {
                goto block_20;
            }
        }
        else
        {
block_20:
            /* I'm sorry, this is the only way I could make it match. */
            if (g_PlayerTankProp == NULL
                && (stanSavedColl_posData != NULL)
                && (stanSavedColl_posData->type == PROP_TYPE_OBJ))
            {
                tank = (struct TankRecord *)stanSavedColl_posData->obj;
                if (tank->type == PROPDEF_TANK)
                {
                    g_WorldTankProp = stanSavedColl_posData;
                }
            }
        }

        sub_GAME_7F03D058(g_CurrentPlayer->prop, 1);

        if (g_WorldTankProp != NULL)
        {
            sub_GAME_7F03D058(g_WorldTankProp, 1);
        }
    }

    return sp94;
}



/**
 * Calculates collision with current player.
 * 
 * @param next_pos: 3d coordinate to attempt to move to.
 * @param collision_pt0: Out parameter. Will set {x,0,z} position of first point (from line edge) if Bond is in collision, otherwise {0}.
 * @param collision_pt1: Out parameter. Will set {x,0,z} position of second point (from line edge) if Bond is in collision, otherwise ... Bond's look angle?
 * 
 * @return 1 if able to update stan and collision position, zero otherwise.
 * 
 * Address 0x7F07D234.
 */
s32 bondviewTrySimpleMovePlayerCollision(coord3d *next_pos, coord3d *collision_pt0, coord3d *collision_pt1)
{
    struct StandTile *stan;

    // resets stan global collision variables
    sub_GAME_7F0B1CC4();

    if (bondviewTryMoveToStan(next_pos, &stan) != 0)
    {
        g_CurrentPlayer->field_488.current_tile_ptr = stan;
        g_CurrentPlayer->field_488.collision_position.f[0] = next_pos->f[0];
        g_CurrentPlayer->field_488.collision_position.f[2] = next_pos->f[2];

        return 1;
    }

    getCollisionEdge_maybe(collision_pt0, collision_pt1);

    return 0;
}


/**
 * This is a fallback method used when bondviewTrySimpleMovePlayerCollision fails.
 * Instead of moving to the full coordinate specified by `next_pos`, it will
 * scale the position using `unkGeometry7F0B33DC` and try to move to that position.
 * 
 * @param next_pos: 3d coordinate to attempt to move to.
 * @param collision1_pt0: Prior collision point 0.
 * @param collision1_pt1: Prior collision point 1.
 * @param collision2_pt0: Out parameter. Will set {x,0,z} position of first point (from line edge) if Bond is in collision, otherwise {0}.
 * @param collision2_pt1: Out parameter. Will set {x,0,z} position of second point (from line edge) if Bond is in collision, otherwise ... Bond's look angle?
 * 
 * @return 1 if able to update stan and collision position, zero if still unable to move by failing on the same collision edge, -1 otherwise (still unable to move).
 * 
 * US address 7F07D2B4.
 * Perfect Dark, see bondwalk.c bwalk0f0c47d0, bondbike.c bbike0f0d36d4.
*/
s32 bondviewTryFractionMovePlayerCollision(
    struct coord3d *next_pos,
    struct coord3d *collision1_pt0,
    struct coord3d *collision1_pt1,
    struct coord3d *collision2_pt0,
    struct coord3d *collision2_pt1)
{
    StandTile *stan;
    f32 height;
    f32 always_30;
    struct coord3d try_next_pos;
    struct coord3d delta_pos;
    struct coord3d sp50;
    struct coord2d sp48;
    struct coord2d sp40;
    struct coord2d sp38;
    f32 temp_f0;
    f32 collision_radius;
    
    bondviewGetCollisionRadius(g_CurrentPlayer->prop, &collision_radius, &height, &always_30);
    
    delta_pos.f[0] = next_pos->f[0] - g_CurrentPlayer->field_488.collision_position.f[0];
    delta_pos.f[2] = next_pos->f[2] - g_CurrentPlayer->field_488.collision_position.f[2];
    
    sp50.f[0] = collision_radius;
    sp50.f[1] = g_CurrentPlayer->field_488.collision_position.f[0];
    sp50.f[2] = g_CurrentPlayer->field_488.collision_position.f[2];
    
    sp48.f[0] = collision1_pt0->f[0];
    sp48.f[1] = collision1_pt0->f[2];
    
    sp40.f[0] = collision1_pt1->f[0];
    sp40.f[1] = collision1_pt1->f[2];
    
    sp38.f[0] = delta_pos.f[0];
    sp38.f[1] = delta_pos.f[2];
    
    temp_f0 = unkGeometry7F0B33DC(&sp50, &sp48, &sp40, &sp38);
    
    try_next_pos.f[0] = g_CurrentPlayer->field_488.collision_position.f[0] + (delta_pos.f[0] * temp_f0 * 0.25f);
    try_next_pos.f[2] = g_CurrentPlayer->field_488.collision_position.f[2] + (delta_pos.f[2] * temp_f0 * 0.25f);
    
    if (bondviewTryMoveToStan(&try_next_pos, &stan) != 0)
    {
        g_CurrentPlayer->field_488.current_tile_ptr = stan;
        g_CurrentPlayer->field_488.collision_position.f[0] = try_next_pos.f[0];
        g_CurrentPlayer->field_488.collision_position.f[2] = try_next_pos.f[2];
        
        return 1;
    }
    
    getCollisionEdge_maybe(collision2_pt0, collision2_pt1);
    
    if (collision2_pt0->f[0] != collision1_pt0->f[0]
        || collision2_pt0->f[1] != collision1_pt0->f[1]
        || collision2_pt0->f[2] != collision1_pt0->f[2]
        || collision2_pt1->f[0] != collision1_pt1->f[0]
        || collision2_pt1->f[1] != collision1_pt1->f[1]
        || collision2_pt1->f[2] != collision1_pt1->f[2])
    {
        return 0;
    }
    
    return -1;
}




/**
 * This is a fallback method used when bondviewTrySimpleMovePlayerCollision fails.
 * Instead of moving to the full coordinate specified by `next_pos`, it will
 * attempt to move along the collision edge.
 * 
 * @param prior_next_pos: Prior 3d coordinate that Bond failed to move to.
 * @param collision1_pt0: Prior collision point 0.
 * @param collision1_pt1: Prior collision point 1.
 * 
 * @return -1 if either x or z coordinates are the same for the collision points, 1 if able to update stan and collision position, zero otherwise.
 * 
 * US address 7F07D4C0.
 */
s32 bondviewTryEdgeMovePlayerCollision(struct coord3d *prior_next_pos, struct coord3d *collision_pt0, struct coord3d *collision_pt1)
{
    struct coord3d delta_pos;
    f32 tempf;
    struct coord3d norm_collision_edge;
    struct coord3d try_next_pos;
    StandTile *stan;

    delta_pos.f[0] = prior_next_pos->f[0] - g_CurrentPlayer->field_488.collision_position.f[0];
    delta_pos.f[2] = prior_next_pos->f[2] - g_CurrentPlayer->field_488.collision_position.f[2];

    if (collision_pt0->f[0] != collision_pt1->f[0] || collision_pt0->f[2] != collision_pt1->f[2])
    {
        norm_collision_edge.f[0] = collision_pt1->f[0] - collision_pt0->f[0];
        norm_collision_edge.f[2] = collision_pt1->f[2] - collision_pt0->f[2];

        tempf = (norm_collision_edge.f[0] * norm_collision_edge.f[0]) + (norm_collision_edge.f[2] * norm_collision_edge.f[2]);
        tempf =  1.0f / sqrtf(tempf);
        norm_collision_edge.f[0] *= tempf;
        norm_collision_edge.f[2] *= tempf;

        /**
         * Normalizing gives you the direction vector of the wall, so the dot product in the assignment to
         * tempf gives you the distance moved along the direction of the wall.
         * Then try_next_pos is simply the point of the collision with the wall, plus the
         * length moved along the wall times the direction vector of the wall.
         **/
        tempf = (delta_pos.f[0] * norm_collision_edge.f[0]) + (delta_pos.f[2] * norm_collision_edge.f[2]);
        try_next_pos.f[0] = g_CurrentPlayer->field_488.collision_position.f[0] + (tempf * norm_collision_edge.f[0]);
        try_next_pos.f[2] = g_CurrentPlayer->field_488.collision_position.f[2] + (tempf * norm_collision_edge.f[2]);

        if (bondviewTryMoveToStan(&try_next_pos, &stan))
        {
            g_CurrentPlayer->field_488.current_tile_ptr = stan;
            g_CurrentPlayer->field_488.collision_position.f[0] = try_next_pos.f[0];
            g_CurrentPlayer->field_488.collision_position.f[2] = try_next_pos.f[2];
            
            return 1;
        }

        return 0;
    }

    return -1;
}



/**
 * This is a fallback method used when bondviewTrySimpleMovePlayerCollision fails.
 * If Bond previously failed to move because of a collision, this will check
 * if Bond is near the end point of the collision edge. If within the collision
 * radius of Bond to the edge endpoint, then allow movement.
 * 
 * @param prior_next_pos: Prior 3d coordinate that Bond failed to move to.
 * @param collision1_pt0: Prior collision point 0.
 * @param collision1_pt1: Prior collision point 1.
 * 
 * @return 1 if able to update stan and collision position, zero otherwise.
 * 
 * US address 7F07D61C.
 * 
 * Perfect Dark bwalk0f0c4a5c.
*/
s32 bondviewTryEndHopPlayerCollision(struct coord3d *prior_next_pos, struct coord3d *collision_pt0, struct coord3d *collision_pt1)
{
    struct coord3d delta_pos;
    struct coord3d sp50;
    struct coord3d try_next_pos;
    f32 height;
    f32 always_30;
    f32 tempf;
    StandTile *stan;
    f32 collision_radius;

    bondviewGetCollisionRadius(g_CurrentPlayer->prop, &collision_radius, &height, &always_30);
    
    delta_pos.f[0] = prior_next_pos->f[0] - g_CurrentPlayer->field_488.collision_position.f[0];
    delta_pos.f[2] = prior_next_pos->f[2] - g_CurrentPlayer->field_488.collision_position.f[2];

    sp50.f[0] = collision_pt0->f[0] - prior_next_pos->f[0];
    sp50.f[2] = collision_pt0->f[2] - prior_next_pos->f[2];

    if (((sp50.f[0] * sp50.f[0]) + (sp50.f[2] * sp50.f[2])) <= (collision_radius * collision_radius))
    {
        if (collision_pt0->f[0] != g_CurrentPlayer->field_488.collision_position.f[0] || collision_pt0->f[2] != g_CurrentPlayer->field_488.collision_position.f[2])
        {
            sp50.f[0] = -(collision_pt0->f[2] - g_CurrentPlayer->field_488.collision_position.f[2]);
            sp50.f[2] = collision_pt0->f[0] - g_CurrentPlayer->field_488.collision_position.f[0];
    
            tempf = (sp50.f[0] * sp50.f[0]) + (sp50.f[2] * sp50.f[2]);
            tempf =  1.0f / sqrtf(tempf);
            sp50.f[0] *= tempf;
            sp50.f[2] *= tempf;
    
            tempf = (delta_pos.f[0] * sp50.f[0]) + (delta_pos.f[2] * sp50.f[2]);
            sp50.f[0] *= tempf;
            sp50.f[2] *= tempf;
            try_next_pos.f[0] = g_CurrentPlayer->field_488.collision_position.f[0] + (sp50.f[0]);
            try_next_pos.f[2] = g_CurrentPlayer->field_488.collision_position.f[2] + (sp50.f[2]);
    
            if (bondviewTryMoveToStan(&try_next_pos, &stan))
            {
                g_CurrentPlayer->field_488.current_tile_ptr = stan;
                g_CurrentPlayer->field_488.collision_position.f[0] = try_next_pos.f[0];
                g_CurrentPlayer->field_488.collision_position.f[2] = try_next_pos.f[2];
                
                return 1;
            }
        }
    }
    else
    {
        sp50.f[0] = collision_pt1->f[0] - prior_next_pos->f[0];
        sp50.f[2] = collision_pt1->f[2] - prior_next_pos->f[2];
    
        if (((sp50.f[0] * sp50.f[0]) + (sp50.f[2] * sp50.f[2])) <= (collision_radius * collision_radius))
        {
            if (collision_pt1->f[0] != g_CurrentPlayer->field_488.collision_position.f[0] || collision_pt1->f[2] != g_CurrentPlayer->field_488.collision_position.f[2])
            {
                sp50.f[0] = -(collision_pt1->f[2] - g_CurrentPlayer->field_488.collision_position.f[2]);
                sp50.f[2] = collision_pt1->f[0] - g_CurrentPlayer->field_488.collision_position.f[0];
        
                tempf = (sp50.f[0] * sp50.f[0]) + (sp50.f[2] * sp50.f[2]);
                tempf =  1.0f / sqrtf(tempf);
                sp50.f[0] *= tempf;
                sp50.f[2] *= tempf;
        
                tempf = (delta_pos.f[0] * sp50.f[0]) + (delta_pos.f[2] * sp50.f[2]);
                sp50.f[0] *= tempf;
                sp50.f[2] *= tempf;
                try_next_pos.f[0] = g_CurrentPlayer->field_488.collision_position.f[0] + (sp50.f[0]);
                try_next_pos.f[2] = g_CurrentPlayer->field_488.collision_position.f[2] + (sp50.f[2]);
        
                if (bondviewTryMoveToStan(&try_next_pos, &stan))
                {
                    g_CurrentPlayer->field_488.current_tile_ptr = stan;
                    g_CurrentPlayer->field_488.collision_position.f[0] = try_next_pos.f[0];
                    g_CurrentPlayer->field_488.collision_position.f[2] = try_next_pos.f[2];
                    
                    return 1;
                }
            }
        }
    }
    
    return 0;
}


/**
 * Unreferenced.
 * 
 * Bitwise convert 32bit int to float.
 * 
 * Address 0x7F07D954.
 */
f32 bondviewBitconvertIntToFloat(s32 arg0)
{
    return *(f32*)&arg0;
}




struct dummy_struct {
    s32 unk00;
    s32 unk04;
};

/**
 * Sets Bond bondprevpos, attempts to move by `offset`.
 * 
 * @param offset: Attempt to move Bond by {x,0,z} amount.
 * @param allow_scoot: If movement causes collision, when set will allow Bond to scoot along the collision edge and to bump around corner edges. Otherwise, any collision will stop movement.
 * 
 * US address 7F07D960.
 * JP address 7F07DA34 (maybe).
 */
void bondviewCalcUpdatePlayerCollision(struct coord3d *offset, s32 allow_scoot)
{
    struct coord3d next_pos; // spb4
    struct coord3d collision1_pt0; // spa8
    struct coord3d collision1_pt1; // sp9c
    struct rect4f *sp98; // sp98
    s32 sp94; // sp94
    struct TankRecord *tank_objrecord; // no stack
    struct ObjectRecord *obj;
    f32 *farr5;
    f32 *farr6;
    f32 temp_f2; // sp80
    struct coord3d collision2_pt0;  // sp74
    struct coord3d collision2_pt1; // sp68
    StandTile *stan; // no stack
    struct coord3d collision3_pt0; // sp58
    struct coord3d collision3_pt1; // sp4c
    s32 tile_count; // sp48
    s32 i; // sp44
    s32 temp_a3; // no stack
    s32 phi_a0_3; // sp3c
    s32 temp_v0_7; // no stack


    g_CurrentPlayer->bondprevpos.f[0] = g_CurrentPlayer->field_488.collision_position.f[0];
    g_CurrentPlayer->bondprevpos.f[1] = g_CurrentPlayer->field_488.collision_position.f[1];
    g_CurrentPlayer->bondprevpos.f[2] = g_CurrentPlayer->field_488.collision_position.f[2];

    next_pos.f[0] = g_CurrentPlayer->field_488.collision_position.f[0] + offset->f[0];
    next_pos.f[2] = g_CurrentPlayer->field_488.collision_position.f[2] + offset->f[2];

    g_BondCanEnterTank = 0;

    g_CurrentPlayer->autocrouchpos = CROUCH_STAND;
    
    if (g_WorldTankProp != NULL)
    {
        chraiGetCollisionBoundsWithoutY(g_WorldTankProp, &sp98, &sp94);

        if ((in_tank_flag == 1)
            || (chrpropTestPointInPolygon(&g_CurrentPlayer->field_488.collision_position, sp98, sp94) != 0)
            || ((chrobjTestPointPolygonCollision(&g_CurrentPlayer->field_488.collision_position, g_CurrentPlayer->field_488.collision_radius, sp98, sp94) != 0)))
        {
            
            obj = g_WorldTankProp->obj;
            tank_objrecord = (struct TankRecord *)g_WorldTankProp->obj;
            
            /// TODO: replace with ModelNode structs
            farr5 = (f32*)obj->model->obj->Switches[5]->Data;
            farr6 = (f32*)obj->model->obj->Switches[6]->Data;
            g_PlayerTankProp = g_WorldTankProp;

            temp_f2 = (farr5[4] - farr5[3]) * obj->model->scale;

            if (in_tank_flag == 1
                || (chrpropTestPointInPolygon(&g_CurrentPlayer->field_488.collision_position, &tank_objrecord->rect, (s32)tank_objrecord->unk80) != 0))
            {
                temp_f2 += (farr6[4] - farr6[3]) * obj->model->scale;
                g_BondCanEnterTank = 1;
            }

            if ((in_tank_flag == 0) && (g_PlayerTankYOffset < temp_f2))
            {
                g_PlayerTankYOffset += (20.0f * g_GlobalTimerDelta);
                if ((temp_f2 < g_PlayerTankYOffset))
                {
                    //empty;
                }
                else
                {
                    return;
                }
                
                g_PlayerTankYOffset = temp_f2;
            }
            else
            {
                g_PlayerTankYOffset = temp_f2;
            }

            if (in_tank_flag == 1)
            {
                if (g_EnterTankAudioState == TANK_RUN_STATE_NOT_RUNNING)
                {
                    g_PlayerTankYOffset += -37.0f * (1.0f - g_TankEnteringSitHeightRemain);
                }
                else
                {
                    g_PlayerTankYOffset += -37.0f;
                }
            }
        }
        else
        {
            if (g_PlayerTankProp != NULL)
            {
                g_WorldTankProp = NULL;
                g_PlayerTankProp = NULL;
                g_PlayerTankYOffset = 0.0f;
            }
        }
    }

    // This `if` block looks like Perfect Dark bbike0f0d3c60
    if (bondviewTrySimpleMovePlayerCollision(&next_pos, &collision1_pt0, &collision1_pt1) == 0)
    {
        // return values are:
        //   1 if able to update stan and collision position
        //   zero if still unable to move by failing on the same collision edge
        //   -1 otherwise (still unable to move).
        temp_v0_7 = bondviewTryFractionMovePlayerCollision(&next_pos, &collision1_pt0, &collision1_pt1, &collision2_pt0, &collision2_pt1);
        
        if ((temp_v0_7 > 0) || (temp_v0_7 < 0))
        {
            if ((allow_scoot != 0)
                && (bondviewTryEdgeMovePlayerCollision(&next_pos, &collision1_pt0, &collision1_pt1) <= 0)
                && (bondviewTryEndHopPlayerCollision(&next_pos, &collision1_pt0, &collision1_pt1) == 0))
            {
                // empty
            }
        }
        else if (temp_v0_7 == 0)
        {
            bondviewTryFractionMovePlayerCollision(&next_pos, &collision2_pt0, &collision2_pt1, &collision3_pt0, &collision3_pt1);
            
            if ((allow_scoot != 0)
                && (bondviewTryEdgeMovePlayerCollision(&next_pos, &collision2_pt0, &collision2_pt1) <= 0)
                && (bondviewTryEdgeMovePlayerCollision(&next_pos, &collision1_pt0, &collision1_pt1) <= 0)
                && (bondviewTryEndHopPlayerCollision(&next_pos, &collision2_pt0, &collision2_pt1) == 0))
            {
                bondviewTryEndHopPlayerCollision(&next_pos, &collision1_pt0, &collision1_pt1);
            }
        }
    }

    /**
     * This block seems to be some error checking code, this will only occur when Bond
     * goes out of bounds.
    */
    if (stanTestPointWithinTileBoundsMaybe(
            g_CurrentPlayer->field_488.current_tile_ptr,
            g_CurrentPlayer->field_488.collision_position.f[0],
            g_CurrentPlayer->field_488.collision_position.f[2]) == 0)
    {
        if(1);
        
        stan = g_CurrentPlayer->field_488.current_tile_ptr;
        
        for (tile_count=0; tile_count<5; tile_count++)
        {
            /// TODO: fix the horrible casts below.

            for (i=0, phi_a0_3 = 0; i<((stan->tail.half >> 0xC) & 0xF); i++)
            {
                // maybe: if (( stan->points[i+1].link >> 4) != 0)
                if (( ((struct StandTilePoint*)stan) [i+1].link >> 4) != 0)
                {
                    if(1);
                    phi_a0_3++;
                }
            }

            temp_a3 = randomGetNext() % (u32)phi_a0_3;

            for (i=0, phi_a0_3 = 0; i<(((s16) stan->tail.half >> 0xC) & 0xF); i++)
            {
                // maybe: if (( stan->points[i+1].link >> 4) != 0)
                if (( ((struct StandTilePoint*)stan) [i+1].link >> 4) != 0)
                {
                    if (phi_a0_3 == temp_a3)
                    {
                        // note: no `>> 4`
                        // maybe: stan = &(standTileStart)[stan->points[i+1].link];
                        stan = (struct StandTile*)&((struct dummy_struct*)standTileStart)[( ((struct StandTilePoint*)stan)[i+1].link)];
                        break;
                    }

                    phi_a0_3++;
                }
            }
            
            if(1);

            if (stanTestPointWithinTileBoundsMaybe(
                stan,
                g_CurrentPlayer->field_488.collision_position.f[0],
                g_CurrentPlayer->field_488.collision_position.f[2]))
            {
                g_CurrentPlayer->field_488.current_tile_ptr = stan;
                break;
            }
        }
    }

    sub_GAME_7F07DE9C(g_CurrentPlayer);

    if (g_CurrentPlayer->field_488.current_tile_ptr != NULL)
    {
        objectivestatusCheckRoomEntered(g_CurrentPlayer->field_488.current_tile_ptr->room);
    }
}



void sub_GAME_7F07DE64(struct player *player) {
    chrpropDeregisterRoom(player->prop, player->field_2A04, player);
    player->field_2A04 = -1;
}


 /* extern */

/**
 * Address 0x7F07DE9C.
 */
void sub_GAME_7F07DE9C(struct player *player)
{
    sub_GAME_7F07DE64(player);

    if (player->prop->chr)
    {
        chrPositionRelated7F020D94(player->prop->chr);
        return;
    }

    if (player->field_488.current_tile_ptr)
    {
        player->field_2A04 = (s16) player->field_488.current_tile_ptr->room;

        chrpropRegisterRoom(player->prop, player->field_2A04);
    }
}


void sub_GAME_7F07DEFC(void)
{
    g_CurrentPlayer->pause_starting_angle = g_CurrentPlayer->vv_verta;
    g_CurrentPlayer->field_210 = 0.0f;
    g_CurrentPlayer->field_218 = 0;
}

/**
 * Pause angle related.
 * 
 * @param arg0: When set, pause_target_angle will be -40.0f, otherwise g_CurrentPlayer->vv_verta.
 * 
 * Address 0x7F07DF28.
 */
f32 bondviewPauseAngleRelated(s32 arg0)
{
    f32 f;
    f32 ret;

    if (arg0)
    {
        g_CurrentPlayer->pause_related = g_CurrentPlayer->vv_verta;
        g_CurrentPlayer->pause_target_angle = -40.0f;
    }
    else
    {
        g_CurrentPlayer->pause_related = g_CurrentPlayer->pause_starting_angle;
        g_CurrentPlayer->pause_target_angle = g_CurrentPlayer->vv_verta;
    }

    f = g_CurrentPlayer->pause_related - g_CurrentPlayer->pause_target_angle;

    if (f < 0.0f)
    {
        f = -f;
    }

    if (f >= 60.0f)
    {
        ret = (((f - 60.0f) * 60.0f * 0.5f) / 60.0f) + 60.0f;
    }
    else if (f <= 0.0f)
    {
        ret = 0.0f;
    }
    else
    {
        // this is a different `60` than the other values above!
        ret = (f * 60.f) / 60.f;
    }

    return ret;
}



void sub_GAME_7F07E010(f32 arg0) {
    g_CurrentPlayer->field_210 = 0.0f;
    g_CurrentPlayer->field_214 = arg0;
    g_CurrentPlayer->field_218 = 1;
}

void sub_GAME_7F07E03C(f32 arg0) {
    g_CurrentPlayer->field_210 = 0.0f;
    g_CurrentPlayer->field_214 = arg0;
    g_CurrentPlayer->field_218 = 2;
}


s32 sub_GAME_7F07E068(void) {
    return (g_CurrentPlayer->field_218 != 0 && g_CurrentPlayer->field_218 != 3);
}



#ifdef NONMATCHING
void sub_GAME_7F07E090(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8005506C
.word 0x40c90fdb /*6.2831855*/
glabel D_80055070
.word 0x40c90fdb /*6.2831855*/
glabel D_80055074
.word 0xbf333333 /*-0.69999999*/
glabel D_80055078
.word 0x3f333333 /*0.69999999*/
.text
glabel sub_GAME_7F07E090
/* 0B2BC0 7F07E090 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0B2BC4 7F07E094 2484A0B0 */  addiu $a0, %lo(g_CurrentPlayer) # addiu $a0, $a0, -0x5f50
/* 0B2BC8 7F07E098 8C820000 */  lw    $v0, ($a0)
/* 0B2BCC 7F07E09C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0B2BD0 7F07E0A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0B2BD4 7F07E0A4 C4420158 */  lwc1  $f2, 0x158($v0)
/* 0B2BD8 7F07E0A8 24010001 */  li    $at, 1
/* 0B2BDC 7F07E0AC E7A2001C */  swc1  $f2, 0x1c($sp)
/* 0B2BE0 7F07E0B0 8C430218 */  lw    $v1, 0x218($v0)
/* 0B2BE4 7F07E0B4 14610031 */  bne   $v1, $at, .L7F07E17C
/* 0B2BE8 7F07E0B8 3C018005 */   lui   $at, %hi(g_GlobalTimerDelta)
/* 0B2BEC 7F07E0BC C4248378 */  lwc1  $f4, %lo(g_GlobalTimerDelta)($at)
/* 0B2BF0 7F07E0C0 3C018003 */  lui   $at, %hi(watch_transition_time)
/* 0B2BF4 7F07E0C4 C42665A8 */  lwc1  $f6, %lo(watch_transition_time)($at)
/* 0B2BF8 7F07E0C8 C44A0210 */  lwc1  $f10, 0x210($v0)
/* 0B2BFC 7F07E0CC 46062202 */  mul.s $f8, $f4, $f6
/* 0B2C00 7F07E0D0 46085400 */  add.s $f16, $f10, $f8
/* 0B2C04 7F07E0D4 E4500210 */  swc1  $f16, 0x210($v0)
/* 0B2C08 7F07E0D8 8C820000 */  lw    $v0, ($a0)
/* 0B2C0C 7F07E0DC C4400210 */  lwc1  $f0, 0x210($v0)
/* 0B2C10 7F07E0E0 C4420214 */  lwc1  $f2, 0x214($v0)
/* 0B2C14 7F07E0E4 4602003C */  c.lt.s $f0, $f2
/* 0B2C18 7F07E0E8 00000000 */  nop
/* 0B2C1C 7F07E0EC 4502001C */  bc1fl .L7F07E160
/* 0B2C20 7F07E0F0 C450020C */   lwc1  $f16, 0x20c($v0)
/* 0B2C24 7F07E0F4 46020383 */  div.s $f14, $f0, $f2
/* 0B2C28 7F07E0F8 3C018005 */  lui   $at, %hi(D_8005506C)
/* 0B2C2C 7F07E0FC C432506C */  lwc1  $f18, %lo(D_8005506C)($at)
/* 0B2C30 7F07E100 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0B2C34 7F07E104 44813000 */  mtc1  $at, $f6
/* 0B2C38 7F07E108 46127102 */  mul.s $f4, $f14, $f18
/* 0B2C3C 7F07E10C 00000000 */  nop
/* 0B2C40 7F07E110 46062302 */  mul.s $f12, $f4, $f6
/* 0B2C44 7F07E114 0FC15FA8 */  jal   cosf
/* 0B2C48 7F07E118 00000000 */   nop
/* 0B2C4C 7F07E11C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0B2C50 7F07E120 44815000 */  mtc1  $at, $f10
/* 0B2C54 7F07E124 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0B2C58 7F07E128 2484A0B0 */  addiu $a0, %lo(g_CurrentPlayer) # addiu $a0, $a0, -0x5f50
/* 0B2C5C 7F07E12C 46005201 */  sub.s $f8, $f10, $f0
/* 0B2C60 7F07E130 8C820000 */  lw    $v0, ($a0)
/* 0B2C64 7F07E134 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0B2C68 7F07E138 44818000 */  mtc1  $at, $f16
/* 0B2C6C 7F07E13C C4420208 */  lwc1  $f2, 0x208($v0)
/* 0B2C70 7F07E140 C444020C */  lwc1  $f4, 0x20c($v0)
/* 0B2C74 7F07E144 46104482 */  mul.s $f18, $f8, $f16
/* 0B2C78 7F07E148 46022181 */  sub.s $f6, $f4, $f2
/* 0B2C7C 7F07E14C 46123282 */  mul.s $f10, $f6, $f18
/* 0B2C80 7F07E150 460A1200 */  add.s $f8, $f2, $f10
/* 0B2C84 7F07E154 10000006 */  b     .L7F07E170
/* 0B2C88 7F07E158 E4480158 */   swc1  $f8, 0x158($v0)
/* 0B2C8C 7F07E15C C450020C */  lwc1  $f16, 0x20c($v0)
.L7F07E160:
/* 0B2C90 7F07E160 240E0003 */  li    $t6, 3
/* 0B2C94 7F07E164 E4500158 */  swc1  $f16, 0x158($v0)
/* 0B2C98 7F07E168 8C8F0000 */  lw    $t7, ($a0)
/* 0B2C9C 7F07E16C ADEE0218 */  sw    $t6, 0x218($t7)
.L7F07E170:
/* 0B2CA0 7F07E170 8C820000 */  lw    $v0, ($a0)
/* 0B2CA4 7F07E174 10000034 */  b     .L7F07E248
/* 0B2CA8 7F07E178 C4420158 */   lwc1  $f2, 0x158($v0)
.L7F07E17C:
/* 0B2CAC 7F07E17C 24010002 */  li    $at, 2
/* 0B2CB0 7F07E180 14610031 */  bne   $v1, $at, .L7F07E248
/* 0B2CB4 7F07E184 3C018005 */   lui   $at, %hi(g_GlobalTimerDelta)
/* 0B2CB8 7F07E188 C4248378 */  lwc1  $f4, %lo(g_GlobalTimerDelta)($at)
/* 0B2CBC 7F07E18C 3C018003 */  lui   $at, %hi(watch_transition_time)
/* 0B2CC0 7F07E190 C42665A8 */  lwc1  $f6, %lo(watch_transition_time)($at)
/* 0B2CC4 7F07E194 C44A0210 */  lwc1  $f10, 0x210($v0)
/* 0B2CC8 7F07E198 46062482 */  mul.s $f18, $f4, $f6
/* 0B2CCC 7F07E19C 46125200 */  add.s $f8, $f10, $f18
/* 0B2CD0 7F07E1A0 E4480210 */  swc1  $f8, 0x210($v0)
/* 0B2CD4 7F07E1A4 8C820000 */  lw    $v0, ($a0)
/* 0B2CD8 7F07E1A8 C4400210 */  lwc1  $f0, 0x210($v0)
/* 0B2CDC 7F07E1AC C4420214 */  lwc1  $f2, 0x214($v0)
/* 0B2CE0 7F07E1B0 4602003C */  c.lt.s $f0, $f2
/* 0B2CE4 7F07E1B4 00000000 */  nop
/* 0B2CE8 7F07E1B8 4502001E */  bc1fl .L7F07E234
/* 0B2CEC 7F07E1BC C4480208 */   lwc1  $f8, 0x208($v0)
/* 0B2CF0 7F07E1C0 46020383 */  div.s $f14, $f0, $f2
/* 0B2CF4 7F07E1C4 3C018005 */  lui    $at, %hi(D_80055070)
/* 0B2CF8 7F07E1C8 C4305070 */  lwc1  $f16, %lo(D_80055070)($at)
/* 0B2CFC 7F07E1CC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0B2D00 7F07E1D0 44813000 */  mtc1  $at, $f6
/* 0B2D04 7F07E1D4 46107102 */  mul.s $f4, $f14, $f16
/* 0B2D08 7F07E1D8 00000000 */  nop
/* 0B2D0C 7F07E1DC 46062302 */  mul.s $f12, $f4, $f6
/* 0B2D10 7F07E1E0 0FC15FA8 */  jal   cosf
/* 0B2D14 7F07E1E4 00000000 */   nop
/* 0B2D18 7F07E1E8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0B2D1C 7F07E1EC 44815000 */  mtc1  $at, $f10
/* 0B2D20 7F07E1F0 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0B2D24 7F07E1F4 2484A0B0 */  addiu $a0, %lo(g_CurrentPlayer) # addiu $a0, $a0, -0x5f50
/* 0B2D28 7F07E1F8 46005481 */  sub.s $f18, $f10, $f0
/* 0B2D2C 7F07E1FC 8C820000 */  lw    $v0, ($a0)
/* 0B2D30 7F07E200 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0B2D34 7F07E204 44814000 */  mtc1  $at, $f8
/* 0B2D38 7F07E208 C44C020C */  lwc1  $f12, 0x20c($v0)
/* 0B2D3C 7F07E20C C4440208 */  lwc1  $f4, 0x208($v0)
/* 0B2D40 7F07E210 46089402 */  mul.s $f16, $f18, $f8
/* 0B2D44 7F07E214 460C2181 */  sub.s $f6, $f4, $f12
/* 0B2D48 7F07E218 46103282 */  mul.s $f10, $f6, $f16
/* 0B2D4C 7F07E21C 460A6480 */  add.s $f18, $f12, $f10
/* 0B2D50 7F07E220 E4520158 */  swc1  $f18, 0x158($v0)
/* 0B2D54 7F07E224 8C820000 */  lw    $v0, ($a0)
/* 0B2D58 7F07E228 10000007 */  b     .L7F07E248
/* 0B2D5C 7F07E22C C4420158 */   lwc1  $f2, 0x158($v0)
/* 0B2D60 7F07E230 C4480208 */  lwc1  $f8, 0x208($v0)
.L7F07E234:
/* 0B2D64 7F07E234 E4480158 */  swc1  $f8, 0x158($v0)
/* 0B2D68 7F07E238 8C980000 */  lw    $t8, ($a0)
/* 0B2D6C 7F07E23C AF000218 */  sw    $zero, 0x218($t8)
/* 0B2D70 7F07E240 8C820000 */  lw    $v0, ($a0)
/* 0B2D74 7F07E244 C4420158 */  lwc1  $f2, 0x158($v0)
.L7F07E248:
/* 0B2D78 7F07E248 3C01C334 */  li    $at, 0xC3340000 # -180.000000
/* 0B2D7C 7F07E24C 44812000 */  mtc1  $at, $f4
/* 0B2D80 7F07E250 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 0B2D84 7F07E254 3C198005 */  lui   $t9, %hi(g_ClockTimer)
/* 0B2D88 7F07E258 4604103C */  c.lt.s $f2, $f4
/* 0B2D8C 7F07E25C 00000000 */  nop
/* 0B2D90 7F07E260 45020008 */  bc1fl .L7F07E284
/* 0B2D94 7F07E264 44818000 */   mtc1  $at, $f16
/* 0B2D98 7F07E268 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0B2D9C 7F07E26C 44816000 */  mtc1  $at, $f12
/* 0B2DA0 7F07E270 00000000 */  nop
/* 0B2DA4 7F07E274 460C1180 */  add.s $f6, $f2, $f12
/* 0B2DA8 7F07E278 1000000B */  b     .L7F07E2A8
/* 0B2DAC 7F07E27C E4460158 */   swc1  $f6, 0x158($v0)
/* 0B2DB0 7F07E280 44818000 */  mtc1  $at, $f16
.L7F07E284:
/* 0B2DB4 7F07E284 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0B2DB8 7F07E288 4602803E */  c.le.s $f16, $f2
/* 0B2DBC 7F07E28C 00000000 */  nop
/* 0B2DC0 7F07E290 45000005 */  bc1f  .L7F07E2A8
/* 0B2DC4 7F07E294 00000000 */   nop
/* 0B2DC8 7F07E298 44816000 */  mtc1  $at, $f12
/* 0B2DCC 7F07E29C 00000000 */  nop
/* 0B2DD0 7F07E2A0 460C1281 */  sub.s $f10, $f2, $f12
/* 0B2DD4 7F07E2A4 E44A0158 */  swc1  $f10, 0x158($v0)
.L7F07E2A8:
/* 0B2DD8 7F07E2A8 8F398374 */  lw    $t9, %lo(g_ClockTimer)($t9)
/* 0B2DDC 7F07E2AC 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0B2DE0 7F07E2B0 44816000 */  mtc1  $at, $f12
/* 0B2DE4 7F07E2B4 1B200030 */  blez  $t9, .L7F07E378
/* 0B2DE8 7F07E2B8 3C014334 */   li    $at, 0x43340000 # 180.000000
/* 0B2DEC 7F07E2BC 8C820000 */  lw    $v0, ($a0)
/* 0B2DF0 7F07E2C0 C7A8001C */  lwc1  $f8, 0x1c($sp)
/* 0B2DF4 7F07E2C4 44803000 */  mtc1  $zero, $f6
/* 0B2DF8 7F07E2C8 C4520158 */  lwc1  $f18, 0x158($v0)
/* 0B2DFC 7F07E2CC 44815000 */  mtc1  $at, $f10
/* 0B2E00 7F07E2D0 3C018005 */  lui   $at, %hi(D_80055074)
/* 0B2E04 7F07E2D4 46089101 */  sub.s $f4, $f18, $f8
/* 0B2E08 7F07E2D8 E4440160 */  swc1  $f4, 0x160($v0)
/* 0B2E0C 7F07E2DC 8C820000 */  lw    $v0, ($a0)
/* 0B2E10 7F07E2E0 C4400160 */  lwc1  $f0, 0x160($v0)
/* 0B2E14 7F07E2E4 4606003C */  c.lt.s $f0, $f6
/* 0B2E18 7F07E2E8 00000000 */  nop
/* 0B2E1C 7F07E2EC 45020006 */  bc1fl .L7F07E308
/* 0B2E20 7F07E2F0 4600503C */   c.lt.s $f10, $f0
/* 0B2E24 7F07E2F4 460C0400 */  add.s $f16, $f0, $f12
/* 0B2E28 7F07E2F8 E4500160 */  swc1  $f16, 0x160($v0)
/* 0B2E2C 7F07E2FC 8C820000 */  lw    $v0, ($a0)
/* 0B2E30 7F07E300 C4400160 */  lwc1  $f0, 0x160($v0)
/* 0B2E34 7F07E304 4600503C */  c.lt.s $f10, $f0
.L7F07E308:
/* 0B2E38 7F07E308 00000000 */  nop
/* 0B2E3C 7F07E30C 45000005 */  bc1f  .L7F07E324
/* 0B2E40 7F07E310 00000000 */   nop
/* 0B2E44 7F07E314 460C0481 */  sub.s $f18, $f0, $f12
/* 0B2E48 7F07E318 E4520160 */  swc1  $f18, 0x160($v0)
/* 0B2E4C 7F07E31C 8C820000 */  lw    $v0, ($a0)
/* 0B2E50 7F07E320 C4400160 */  lwc1  $f0, 0x160($v0)
.L7F07E324:
/* 0B2E54 7F07E324 C42C5074 */  lwc1  $f12, %lo(D_80055074)($at)
/* 0B2E58 7F07E328 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 0B2E5C 7F07E32C C4228378 */  lwc1  $f2, %lo(g_GlobalTimerDelta)($at)
/* 0B2E60 7F07E330 3C018005 */  lui   $at, %hi(D_80055078)
/* 0B2E64 7F07E334 46021200 */  add.s $f8, $f2, $f2
/* 0B2E68 7F07E338 46080103 */  div.s $f4, $f0, $f8
/* 0B2E6C 7F07E33C E4440160 */  swc1  $f4, 0x160($v0)
/* 0B2E70 7F07E340 8C820000 */  lw    $v0, ($a0)
/* 0B2E74 7F07E344 C4400160 */  lwc1  $f0, 0x160($v0)
/* 0B2E78 7F07E348 460C003C */  c.lt.s $f0, $f12
/* 0B2E7C 7F07E34C 00000000 */  nop
/* 0B2E80 7F07E350 45000003 */  bc1f  .L7F07E360
/* 0B2E84 7F07E354 00000000 */   nop
/* 0B2E88 7F07E358 10000007 */  b     .L7F07E378
/* 0B2E8C 7F07E35C E44C0160 */   swc1  $f12, 0x160($v0)
.L7F07E360:
/* 0B2E90 7F07E360 C4225078 */  lwc1  $f2, %lo(D_80055078)($at)
/* 0B2E94 7F07E364 4600103C */  c.lt.s $f2, $f0
/* 0B2E98 7F07E368 00000000 */  nop
/* 0B2E9C 7F07E36C 45020003 */  bc1fl .L7F07E37C
/* 0B2EA0 7F07E370 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0B2EA4 7F07E374 E4420160 */  swc1  $f2, 0x160($v0)
.L7F07E378:
/* 0B2EA8 7F07E378 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F07E37C:
/* 0B2EAC 7F07E37C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0B2EB0 7F07E380 03E00008 */  jr    $ra
/* 0B2EB4 7F07E384 00000000 */   nop
)
#endif


f32 sub_GAME_7F07E388(void) {

    if (g_CurrentPlayer->field_218 == 1) {
        return g_CurrentPlayer->field_210 / g_CurrentPlayer->field_214;
    }
    if (g_CurrentPlayer->field_218 == 2) {
        return 1.0f - (g_CurrentPlayer->field_210 / g_CurrentPlayer->field_214);
    }
    if (g_CurrentPlayer->field_218 == 3) {
        return 1.0f;
    }
    return 0.0f;
}

void trigger_watch_zoom(f32 final,f32 time)
{
  g_CurrentPlayer->zoomintime = 0.00000000;
  g_CurrentPlayer->zoomintimemax = time;
  g_CurrentPlayer->zoominfovyold = g_CurrentPlayer->zoominfovy;
  g_CurrentPlayer->zoominfovynew = final;
}


f32 bondviewGetWatchZoomFovy(void) {

    if (g_CurrentPlayer->zoomintime < g_CurrentPlayer->zoomintimemax)
    {
        return g_CurrentPlayer->zoominfovynew;
    }

    return g_CurrentPlayer->zoominfovy;
}

/**
 * Triggers watch zoom if new value.
 * 
 * @param zoominfovy: watch zoom fovy.
 * 
 * Address 0x7F07E46C.
 */
void bondviewTriggerWatchZoom(f32 zoominfovy)
{
    if (bondviewGetWatchZoomFovy() != zoominfovy)
    {
        if (zoominfovy < g_CurrentPlayer->zoominfovy)
        {
            trigger_watch_zoom(zoominfovy, ((g_CurrentPlayer->zoominfovy - zoominfovy) * 15.0f) / 30.0f);

            return;
        }

        trigger_watch_zoom(zoominfovy, ((zoominfovy - g_CurrentPlayer->zoominfovy) * 15.0f) / 30.0f);
    }
}


/**
 * Trigger watch zoom with default angle.
 * 
 * Address 0x7F07E504.
 */
void bondviewTriggerWatchZoomDefault(void)
{
    bondviewTriggerWatchZoom(60.0f);
}


/**
 * Address 0x7F07E52C.
 */
void bondviewZoomToWatchOnOpen(void)
{
    f32 f;

#if defined(VERSION_EU)
    f = ((6.09999990463f - g_CurrentPlayer->zoominfovy) * 45.0f) / -53.9000015259f;
#else
    f = ((5.9f - g_CurrentPlayer->zoominfovy) * 45.0f) / -54.1f;
#endif

    if (f < 0.0f)
    {
        f = -f;
    }

#if defined(VERSION_EU)
    trigger_watch_zoom(6.09999990463f, f);
#else
    trigger_watch_zoom(5.9f, f);
#endif
    
}



/**
 * Address 0x7F07E594.
 */
void bondviewZoomFromWatchOnExit(void)
{
    f32 f;

#if defined(VERSION_EU)
    f = ((60.0f - g_CurrentPlayer->zoominfovy) * 45.0f) / -53.9000015259f;
#else
    f = ((60.0f - g_CurrentPlayer->zoominfovy) * 45.0f) / -54.1f;
#endif

    if (f < 0.0f)
    {
        f = -f;
    }

    trigger_watch_zoom(60.0f, f);
}



s32 check_watch_page_transistion_running(void)
{
    return (g_CurrentPlayer->zoomintime < g_CurrentPlayer->zoomintimemax);
}


/**
 * Address 0x7F07E62C.
 */
void bondviewUpdateWatchZoomIn(void)
{
    if (g_CurrentPlayer->zoomintime < g_CurrentPlayer->zoomintimemax)
    {
        if ((g_CurrentPlayer->watch_animation_state == WATCH_ANIMATION_0x5) || (g_CurrentPlayer->watch_animation_state == WATCH_ANIMATION_0xc))
        {
#if defined(BUGFIX_R1)
            g_CurrentPlayer->zoomintime = g_CurrentPlayer->zoomintime + (f32) jpD_800484D0;      
#else
            g_CurrentPlayer->zoomintime = g_CurrentPlayer->zoomintime + (f32) speedgraphframes;
#endif
        }
        else
        {
#if defined(BUGFIX_R1)
            g_CurrentPlayer->zoomintime = g_CurrentPlayer->zoomintime + (jpD_800484D0 * watch_transition_time);
#else
            g_CurrentPlayer->zoomintime = g_CurrentPlayer->zoomintime + (speedgraphframes * watch_transition_time);
#endif
        }

        if (g_CurrentPlayer->zoomintimemax < g_CurrentPlayer->zoomintime)
        {
            g_CurrentPlayer->zoomintime = g_CurrentPlayer->zoomintimemax;
        }

        g_CurrentPlayer->zoominfovy =
            g_CurrentPlayer->zoominfovyold + 
            (
                (g_CurrentPlayer->zoomintime *
                    (g_CurrentPlayer->zoominfovynew - g_CurrentPlayer->zoominfovyold)
                )
                / g_CurrentPlayer->zoomintimemax
            );
    }
    else
    {
        g_CurrentPlayer->zoomintime = g_CurrentPlayer->zoomintimemax;
        g_CurrentPlayer->zoominfovy = g_CurrentPlayer->zoominfovynew;
    }

    set_cur_player_fovy(g_CurrentPlayer->zoominfovy);
    viSetFovY(g_CurrentPlayer->zoominfovy);
}




/**
 * Address 0x7F07E740.
 */
f32 bondviewWatchAnimationRelated(void)
{
    if (g_CurrentPlayer->watch_animation_state == WATCH_ANIMATION_0x4)
    {
        return ((45.0f - g_CurrentPlayer->zoomintimemax) + g_CurrentPlayer->zoomintime) / 45.0f;
    }

    if (g_CurrentPlayer->watch_animation_state == WATCH_ANIMATION_0x6)
    {
        return (g_CurrentPlayer->zoomintimemax - g_CurrentPlayer->zoomintime) / 45.0f;
    }

    if ((g_CurrentPlayer->watch_animation_state == WATCH_ANIMATION_0x5) || (g_CurrentPlayer->watch_animation_state == WATCH_ANIMATION_0xc))
    {
        return 1.0f;
    }

    return 0.0f;
}





#ifdef NONMATCHING
void sub_GAME_7F07E7CC(void)
{
    ModelFileHeader *objheader;

    objheader = get_ptr_itemheader_in_hand(HAND_LEFT);
    modelCalculateRwDataLen(objheader);
    #ifndef VERSION_EU
    if (0x32 < objheader->numRecords) {
        return_null();
    }
    #endif
    _sub_GAME_7F075FAC(&g_CurrentPlayer->something_with_watch_object_instance, objheader, &g_CurrentPlayer->field_2EC);
    modelSetScale(&g_CurrentPlayer->something_with_watch_object_instance, c_item_entries[41].scale * 0.1f);
    _ modelSetAnimation(&g_CurrentPlayer->something_with_watch_object_instance, ptr_animation_table + PTR_ANIM_bond_watch, 0, 0.0, watch_transition_time * 0.5, 0.0);
    g_CurrentPlayer->step_in_view_watch_animation = 0;
    return;
}

#else
#ifndef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80055088
.word 0x3dccccce /*0.10000001*/
.text
glabel sub_GAME_7F07E7CC
/* 0B32FC 7F07E7CC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0B3300 7F07E7D0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0B3304 7F07E7D4 0FC173C6 */  jal   get_ptr_itemheader_in_hand
/* 0B3308 7F07E7D8 24040001 */   li    $a0, 1
/* 0B330C 7F07E7DC AFA20024 */  sw    $v0, 0x24($sp)
/* 0B3310 7F07E7E0 0FC1D73D */  jal   modelCalculateRwDataLen
/* 0B3314 7F07E7E4 00402025 */   move  $a0, $v0
/* 0B3318 7F07E7E8 8FAE0024 */  lw    $t6, 0x24($sp)
/* 0B331C 7F07E7EC 85CF0014 */  lh    $t7, 0x14($t6)
/* 0B3320 7F07E7F0 29E10033 */  slti  $at, $t7, 0x33
/* 0B3324 7F07E7F4 14200003 */  bnez  $at, .L7F07E804
/* 0B3328 7F07E7F8 00000000 */   nop
/* 0B332C 7F07E7FC 0FC1B11B */  jal   return_null
/* 0B3330 7F07E800 00000000 */   nop
.L7F07E804:
/* 0B3334 7F07E804 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0B3338 7F07E808 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0B333C 7F07E80C 8FA50024 */  lw    $a1, 0x24($sp)
/* 0B3340 7F07E810 24440230 */  addiu $a0, $v0, 0x230
/* 0B3344 7F07E814 0FC1D7EB */  jal   animInit
/* 0B3348 7F07E818 244602EC */   addiu $a2, $v0, 0x2ec
/* 0B334C 7F07E81C 3C018004 */  lui   $at, %hi(c_item_entries+0x33C)
/* 0B3350 7F07E820 C424E14C */  lwc1  $f4, %lo(c_item_entries+0x33C)($at)
/* 0B3354 7F07E824 3C018005 */  lui   $at, %hi(D_80055088)
/* 0B3358 7F07E828 C4265088 */  lwc1  $f6, %lo(D_80055088)($at)
/* 0B335C 7F07E82C 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0B3360 7F07E830 8C84A0B0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0B3364 7F07E834 46062202 */  mul.s $f8, $f4, $f6
/* 0B3368 7F07E838 24840230 */  addiu $a0, $a0, 0x230
/* 0B336C 7F07E83C 44054000 */  mfc1  $a1, $f8
/* 0B3370 7F07E840 0FC1B39E */  jal   modelSetScale
/* 0B3374 7F07E844 00000000 */   nop
/* 0B3378 7F07E848 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0B337C 7F07E84C 44815000 */  mtc1  $at, $f10
/* 0B3380 7F07E850 3C018003 */  lui   $at, %hi(watch_transition_time)
/* 0B3384 7F07E854 C43065A8 */  lwc1  $f16, %lo(watch_transition_time)($at)
/* 0B3388 7F07E858 44800000 */  mtc1  $zero, $f0
/* 0B338C 7F07E85C 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0B3390 7F07E860 46105482 */  mul.s $f18, $f10, $f16
/* 0B3394 7F07E864 3C188007 */  lui   $t8, %hi(ptr_animation_table)
/* 0B3398 7F07E868 8F189538 */  lw    $t8, %lo(ptr_animation_table)($t8)
/* 0B339C 7F07E86C 8C84A0B0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0B33A0 7F07E870 3C190000 */  lui   $t9, %hi(0x000042C8) # $t9, 0
/* 0B33A4 7F07E874 273942C8 */  addiu $t9, %lo(0x000042C8) # addiu $t9, $t9, 0x42c8
/* 0B33A8 7F07E878 44070000 */  mfc1  $a3, $f0
/* 0B33AC 7F07E87C E7B20010 */  swc1  $f18, 0x10($sp)
/* 0B33B0 7F07E880 00003025 */  move  $a2, $zero
/* 0B33B4 7F07E884 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0B33B8 7F07E888 03192821 */  addu  $a1, $t8, $t9
/* 0B33BC 7F07E88C 0FC1BF2A */  jal   modelSetAnimation
/* 0B33C0 7F07E890 24840230 */   addiu $a0, $a0, 0x230
/* 0B33C4 7F07E894 3C088008 */  lui   $t0, %hi(g_CurrentPlayer)
/* 0B33C8 7F07E898 8D08A0B0 */  lw    $t0, %lo(g_CurrentPlayer)($t0)
/* 0B33CC 7F07E89C AD000220 */  sw    $zero, 0x220($t0)
/* 0B33D0 7F07E8A0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0B33D4 7F07E8A4 27BD0028 */  addiu $sp, $sp, 0x28
/* 0B33D8 7F07E8A8 03E00008 */  jr    $ra
/* 0B33DC 7F07E8AC 00000000 */   nop
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80055088
.word 0x3dccccce /*0.10000001*/
.text
glabel sub_GAME_7F07E7CC
/* 0B1278 7F07E888 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0B127C 7F07E88C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0B1280 7F07E890 0FC174F2 */  jal   get_ptr_itemheader_in_hand
/* 0B1284 7F07E894 24040001 */   li    $a0, 1
/* 0B1288 7F07E898 AFA20024 */  sw    $v0, 0x24($sp)
/* 0B128C 7F07E89C 0FC1D75F */  jal   modelCalculateRwDataLen
/* 0B1290 7F07E8A0 00402025 */   move  $a0, $v0
/* 0B1294 7F07E8A4 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0B1298 7F07E8A8 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0B129C 7F07E8AC 8FA50024 */  lw    $a1, 0x24($sp)
/* 0B12A0 7F07E8B0 24440230 */  addiu $a0, $v0, 0x230
/* 0B12A4 7F07E8B4 0FC1D80A */  jal   animInit
/* 0B12A8 7F07E8B8 244602EC */   addiu $a2, $v0, 0x2ec
/* 0B12AC 7F07E8BC 3C018003 */  lui   $at, %hi(c_item_entries+0x33C) # $at, 0x8003
/* 0B12B0 7F07E8C0 C4247D9C */  lwc1  $f4, %lo(c_item_entries+0x33C)($at)
/* 0B12B4 7F07E8C4 3C018005 */  lui   $at, %hi(D_80055088) # $at, 0x8005
/* 0B12B8 7F07E8C8 C426AC58 */  lwc1  $f6, %lo(D_80055088)($at)
/* 0B12BC 7F07E8CC 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0B12C0 7F07E8D0 8C848BC0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0B12C4 7F07E8D4 46062202 */  mul.s $f8, $f4, $f6
/* 0B12C8 7F07E8D8 24840230 */  addiu $a0, $a0, 0x230
/* 0B12CC 7F07E8DC 44054000 */  mfc1  $a1, $f8
/* 0B12D0 7F07E8E0 0FC1B4CF */  jal   modelSetScale
/* 0B12D4 7F07E8E4 00000000 */   nop
/* 0B12D8 7F07E8E8 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0B12DC 7F07E8EC 44815000 */  mtc1  $at, $f10
/* 0B12E0 7F07E8F0 3C018003 */  lui   $at, %hi(watch_transition_time) # $at, 0x8003
/* 0B12E4 7F07E8F4 C4301AF8 */  lwc1  $f16, %lo(watch_transition_time)($at)
/* 0B12E8 7F07E8F8 44800000 */  mtc1  $zero, $f0
/* 0B12EC 7F07E8FC 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0B12F0 7F07E900 46105482 */  mul.s $f18, $f10, $f16
/* 0B12F4 7F07E904 3C0E8006 */  lui   $t6, %hi(ptr_animation_table) # $t6, 0x8006
/* 0B12F8 7F07E908 8DCE8478 */  lw    $t6, %lo(ptr_animation_table)($t6)
/* 0B12FC 7F07E90C 8C848BC0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0B1300 7F07E910 3C0F0000 */  lui   $t7, %hi(0x000042C8) # $t7, 0
/* 0B1304 7F07E914 25EF42C8 */  addiu $t7, %lo(0x000042C8) # addiu $t7, $t7, 0x42c8
/* 0B1308 7F07E918 44070000 */  mfc1  $a3, $f0
/* 0B130C 7F07E91C E7B20010 */  swc1  $f18, 0x10($sp)
/* 0B1310 7F07E920 00003025 */  move  $a2, $zero
/* 0B1314 7F07E924 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0B1318 7F07E928 01CF2821 */  addu  $a1, $t6, $t7
/* 0B131C 7F07E92C 0FC1BF92 */  jal   modelSetAnimation
/* 0B1320 7F07E930 24840230 */   addiu $a0, $a0, 0x230
/* 0B1324 7F07E934 3C188007 */  lui   $t8, %hi(g_CurrentPlayer) # $t8, 0x8007
/* 0B1328 7F07E938 8F188BC0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0B132C 7F07E93C AF000220 */  sw    $zero, 0x220($t8)
/* 0B1330 7F07E940 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0B1334 7F07E944 27BD0028 */  addiu $sp, $sp, 0x28
/* 0B1338 7F07E948 03E00008 */  jr    $ra
/* 0B133C 7F07E94C 00000000 */   nop
)
#endif
#endif





/**
 * Address 0x7F07E8B0.
 */
void bondviewSetPauseWatchRelated(f32 arg0)
{
    if (g_CurrentPlayer->step_in_view_watch_animation == 0)
    {
        g_CurrentPlayer->pause_watch_related_scaled = 20.0f / arg0;
    }
    else
    {
        g_CurrentPlayer->pause_watch_related_scaled = (20.0f - g_CurrentPlayer->pause_watch_related_adjust) / arg0;
    }

    g_CurrentPlayer->step_in_view_watch_animation = 1;
    g_CurrentPlayer->pause_watch_related = arg0;
}




/**
 * Address 0x7F07E910.
 */
void bondviewSetPauseWatchRelatedAlt(f32 arg0)
{
    if (g_CurrentPlayer->step_in_view_watch_animation == 3)
    {
        g_CurrentPlayer->pause_watch_related_scaled = 20.0f / arg0;
    }
    else
    {
        g_CurrentPlayer->pause_watch_related_scaled = g_CurrentPlayer->pause_watch_related_adjust / arg0;
    }

    g_CurrentPlayer->step_in_view_watch_animation = 2;
    g_CurrentPlayer->pause_watch_related = arg0;
}





/**
 * Address 0x7F07E964.
 */
void bondviewStepWatchAnimation(void)
{
    if ((g_CurrentPlayer->step_in_view_watch_animation != 0) && (g_CurrentPlayer->step_in_view_watch_animation != 3))
    {
        if (g_CurrentPlayer->step_in_view_watch_animation == 1)
        {
            g_CurrentPlayer->pause_animation_counter += g_GlobalTimerDelta * watch_transition_time * g_CurrentPlayer->pause_watch_related_scaled;

            if (g_CurrentPlayer->pause_animation_counter > 20.0f)
            {
                g_CurrentPlayer->pause_animation_counter = 20.0f;
                g_CurrentPlayer->step_in_view_watch_animation = 3;
            }
        }
        else if (g_CurrentPlayer->step_in_view_watch_animation == 2)
        {
            g_CurrentPlayer->pause_animation_counter -= g_GlobalTimerDelta * watch_transition_time * g_CurrentPlayer->pause_watch_related_scaled;

            if (g_CurrentPlayer->pause_animation_counter < 0.0f)
            {
                g_CurrentPlayer->pause_animation_counter = 0.0f;
                g_CurrentPlayer->step_in_view_watch_animation = 0;
            }
        }

        modelSetAnimFrame2((void*)&g_CurrentPlayer->something_with_watch_object_instance, g_CurrentPlayer->pause_animation_counter, 0.0f);
    }
}






/**
 * Address 0x7F07EA78.
 */
f32 bondviewGetPauseAnimationPercent(void)
{
    if ((g_CurrentPlayer->step_in_view_watch_animation == 1) || (g_CurrentPlayer->step_in_view_watch_animation == 2))
    {
        return g_CurrentPlayer->pause_animation_counter / 20.0f;
    }
    
    if (g_CurrentPlayer->step_in_view_watch_animation == 3)
    {
        return 1.0f;
    }

    return 0.0f;
}




void set_BONDdata_outside_watch_menu_flag(s32 arg0) {
    g_CurrentPlayer->outside_watch_menu = arg0;
}

s32 get_BONDdata_outside_watch_menu_flag(void) {
    return g_CurrentPlayer->outside_watch_menu;
}





void bondviewPlayerStopAudioForPause(void)
{
    struct hand *hand;
	s32 i;
    ObjectRecord *obj;
    PropRecord *prop;
    
    deactivate_alarm_sound_effect();
    check_deactivate_gas_sound();

    for (i = 0; i < 2; i++)
    {
        hand = &g_CurrentPlayer->hands[i];

        if (hand->audioHandle && sndGetPlayingState(hand->audioHandle) != AL_STOPPED) {
			sndDeactivate(hand->audioHandle);
		}
    }

    for (i = 0; i < 2; i++)
    {
        if (g_TankSfxState[i] && sndGetPlayingState(g_TankSfxState[i]) != AL_STOPPED) {
			sndDeactivate(g_TankSfxState[i]);
		}
    }

    for (prop = get_ptr_obj_pos_list_current_entry(); prop; prop = prop->prev)
    {
        if (prop->type != PROP_TYPE_DOOR && prop->type == PROP_TYPE_OBJ)
        {
            obj = prop->obj;
            
            if (obj->type == PROPDEF_VEHICHLE)
            {
                VehichleRecord *vehicle = (VehichleRecord *)prop->obj;
                if (vehicle->Sound && sndGetPlayingState(vehicle->Sound) != AL_STOPPED) {
                    sndDeactivate(vehicle->Sound);
                }
            }            
            else if (obj->type == PROPDEF_AIRCRAFT)
            {
                AircraftRecord *aircraft = (AircraftRecord *)prop->obj;
                if (aircraft->Sound && sndGetPlayingState(aircraft->Sound) != AL_STOPPED) {
                    sndDeactivate(aircraft->Sound);
                }
            }
            
            if(1);
        }
    }
}





/**
 * US address 7F07EC54.
 * JP address 7F07F260.
 * EU address 7F07ECF4.
*/
void bondviewWatchAnimationTick(void)
{
#if defined(VERSION_EU)
    #define WATCH_VAR_LOWER 14
    #define WATCH_VAR_UPPER 29
#else
    #define WATCH_VAR_LOWER 17
    #define WATCH_VAR_UPPER 35
#endif

    s32 sp3c;
    s32 sp38;
    s32 sp34;
    f32 sp30;
    f32 sp2c;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    if (g_CurrentPlayer->watch_animation_state)
    {
        sp34 = getCurrentPlayerWeaponId(GUNRIGHT) == ITEM_TRIGGER || getCurrentPlayerWeaponId(GUNRIGHT) == ITEM_WATCHLASER;
        sp3c = sp34;

#if defined (VERSION_US)
        sp38 = WATCH_VAR_LOWER;

        if (sp34)
        {
            sp38 = WATCH_VAR_UPPER;
        }
#else
        sp38 = (sp34) ? WATCH_VAR_UPPER : WATCH_VAR_LOWER;
#endif
        
        g_CurrentPlayer->field_1C4 += g_ClockTimer;
        g_CurrentPlayer->watch_pause_time += 1;
        g_CurrentPlayer->pausing_flag = 0;

        if (g_CurrentPlayer->watch_animation_state == 1)
        {
            g_CurrentPlayer->pausing_flag = 0;
            
            if (g_CurrentPlayer->watch_pause_time == 1)
            {
                draw_item_in_hand(GUNLEFT, ITEM_SUIT_LF_HAND);
            }
            else if (g_CurrentPlayer->watch_pause_time == 2)
            {
                if (sp34)
                {
                    draw_item_in_hand(GUNRIGHT, ITEM_UNARMED);
                }
            }
            else
            {
                if (
                    (get_item_in_hand_or_watch_menu(1) == ITEM_SUIT_LF_HAND)
                    && (Gun_hand_without_item(GUNLEFT) != ITEM_UNARMED)
                    && (
                        (sp34 == 0)
                        || (
                            (get_item_in_hand_or_watch_menu(0) == ITEM_UNARMED)
                            && (Gun_hand_without_item(GUNRIGHT) != ITEM_UNARMED)))
                    && (g_CurrentPlayer->field_1C4 >= sp38))
                {
                    g_CurrentPlayer->watch_animation_state = 2;
                    g_CurrentPlayer->watch_pause_time = 1;
                    g_CurrentPlayer->field_1C4 = 0;
                }
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 2)
        {
            g_CurrentPlayer->pausing_flag = 0;
            
            if (g_CurrentPlayer->watch_pause_time == 1)
            {
                gunSetSightVisible(GUNAMMOREASON_DAMAGE, FALSE);
                gunSetGunAmmoVisible(GUNSIGHTREASON_NOCONTROL, FALSE);
                hudmsgsSetOff(PLAYERFLAG_LOCKCONTROLS);
                bondviewSetUpperTextDisplayFlag(PLAYERFLAG_LOCKCONTROLS);
                countdownTimerSetVisible(4, 0);
                
                if ((g_CurrentPlayer->field_218 == 0) || (g_CurrentPlayer->field_218 == 2) || (g_CurrentPlayer->field_218 == 3))
                {
                    sp20 = bondviewPauseAngleRelated(1);
                    
                    if (sp20 < 30.0f)
                    {
                        sp20 = 30.0f;
                    }
                    
                    sub_GAME_7F07E010(sp20);
                }
            }
            
            if ((g_CurrentPlayer->field_214 - g_CurrentPlayer->field_210) < 30.0f)
            {
                g_CurrentPlayer->watch_animation_state = 3;
                g_CurrentPlayer->watch_pause_time = 1;
                g_CurrentPlayer->field_1C4 = 0;
                
                sub_GAME_7F07E7CC();
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 3)
        {
            if (g_CurrentPlayer->watch_pause_time == 1)
            {
                sp30 = 40.0f;
                
                if ((g_CurrentPlayer->step_in_view_watch_animation != 0) && (g_CurrentPlayer->step_in_view_watch_animation != 3))
                {
                    sp30 = ((20.0f - g_CurrentPlayer->pause_watch_related_adjust) * 40.0f) / 20.0f;
                }
                
                if ((g_CurrentPlayer->field_218 == 0) || (g_CurrentPlayer->field_218 == 2) || (g_CurrentPlayer->field_218 == 3))
                {
                    sp2c = bondviewPauseAngleRelated(1);
                    sp20 = sp30 - 10.0f;
                    
                    if (sp2c < sp20)
                    {
                        sp2c = sp20;
                    }
                    
                    sub_GAME_7F07E010(sp2c);
                    
                    sp20 = sp2c + 10.0f;
                    
                    if (sp30 < sp20)
                    {
                        sp30 = sp20;
                    }
                }
                
                bondviewSetPauseWatchRelated(sp30);
            }
            
            if (
                ((g_CurrentPlayer->step_in_view_watch_animation != 0) && (g_CurrentPlayer->step_in_view_watch_animation != 3))
                ||
                sub_GAME_7F07E068() != 0
                )
            {
                g_CurrentPlayer->pausing_flag = 1;
            }
            else
            {
                g_CurrentPlayer->watch_animation_state = 4;
                g_CurrentPlayer->watch_pause_time = 1;
                g_CurrentPlayer->field_1C4 = 0;
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 4)
        {
            if ((g_CurrentPlayer->watch_pause_time == 1) && (g_CurrentPlayer->field_21C != 0))
            {
                sndPlaySfx(g_musicSfxBufferPtr, 0xED, NULL);
                g_CurrentPlayer->field_21C = 0;
            }
            
            bondviewZoomToWatchOnOpen();
            
            if (check_watch_page_transistion_running() != 0)
            {
                g_CurrentPlayer->pausing_flag = 1;
            }
            else
            {
                g_CurrentPlayer->watch_animation_state = 5;
                g_CurrentPlayer->watch_pause_time = 1;
                g_CurrentPlayer->field_1C4 = 0;
                g_CurrentPlayer->field_21C = 1;
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 5)
        {
            if (g_CurrentPlayer->watch_pause_time == 1)
            {
                sub_GAME_7F0C1310();
            }
            
            g_CurrentPlayer->pausing_flag = 1;
        }
        
        if (g_CurrentPlayer->watch_animation_state == 12)
        {
            g_CurrentPlayer->pausing_flag = 1;
            
            if (g_CurrentPlayer->watch_pause_time >= 3)
            {
                g_CurrentPlayer->watch_animation_state = 6;
                g_CurrentPlayer->watch_pause_time = 1;
                g_CurrentPlayer->field_1C4 = 0;
                sndPlaySfx(g_musicSfxBufferPtr, 0xEE, NULL);
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 6)
        {
            if (g_CurrentPlayer->watch_pause_time == 1)
            {
                bondviewZoomFromWatchOnExit();
                if (sp34)
                {
                    draw_item_in_hand(GUNRIGHT, ITEM_UNARMED);
                }
                else
                {
                    sub_GAME_7F05DAE4(0);
                }
            }
            if (check_watch_page_transistion_running())
            {
                g_CurrentPlayer->pausing_flag = 1;
            }
            else
            {
                g_CurrentPlayer->watch_animation_state = 7;
                g_CurrentPlayer->watch_pause_time = 1;
                g_CurrentPlayer->field_1C4 = 0;
                g_CurrentPlayer->field_21C = 1;
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 7)
        {
            if (g_CurrentPlayer->watch_pause_time == 1)
            {
                sp28 = 40.0f;
                sp24 = bondviewPauseAngleRelated(0);
                
                if ((g_CurrentPlayer->step_in_view_watch_animation != 0) && (g_CurrentPlayer->step_in_view_watch_animation != 3))
                {
                    sp28 = (g_CurrentPlayer->pause_watch_related_adjust * 40.0f) / 20.0f;
                }
                
                sp20 = sp28 + 20.0f;
                
                if (sp24 < sp20)
                {
                    sp24 = sp20;
                }
                
                sub_GAME_7F07E03C(sp24);
                bondviewSetPauseWatchRelatedAlt(sp28);
            }

            if ((g_CurrentPlayer->step_in_view_watch_animation != 0) && (g_CurrentPlayer->step_in_view_watch_animation != 3))
            {
                g_CurrentPlayer->pausing_flag = 1;
            }
            else
            {
                g_CurrentPlayer->watch_animation_state = 8;
                g_CurrentPlayer->watch_pause_time = 1;
                g_CurrentPlayer->field_1C4 = 0;
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 8)
        {
            g_CurrentPlayer->pausing_flag = 0;
            
            if (g_CurrentPlayer->watch_pause_time == 1)
            {
                
                if ((get_item_in_hand_or_watch_menu(GUNLEFT) != getCurrentPlayerWeaponId(GUNLEFT)) && (Gun_hand_without_item(GUNLEFT) != ITEM_UNARMED))
                {
                    draw_item_in_hand(GUNLEFT, getCurrentPlayerWeaponId(GUNLEFT));
                }
                
                if (sp3c)
                {
                    if ((get_item_in_hand_or_watch_menu(GUNRIGHT) != getCurrentPlayerWeaponId(GUNRIGHT)) && (Gun_hand_without_item(GUNRIGHT) != ITEM_UNARMED))
                    {
                        draw_item_in_hand(GUNRIGHT, getCurrentPlayerWeaponId(GUNRIGHT));
                    }
                }
            }
            else if (sub_GAME_7F07E068() == 0)
            {
                if (
                    (get_item_in_hand_or_watch_menu(GUNLEFT) == getCurrentPlayerWeaponId(GUNLEFT)) 
                    && (Gun_hand_without_item(GUNLEFT) != ITEM_UNARMED) 
                    && (
                        (sp3c == 0) 
                        || (((get_item_in_hand_or_watch_menu(GUNRIGHT) == getCurrentPlayerWeaponId(GUNRIGHT))) && (Gun_hand_without_item(GUNRIGHT) != ITEM_UNARMED))))
                {
                    sub_GAME_7F05DAE4(1);
                    
                    if (sp3c)
                    {
                        sub_GAME_7F05DAE4(0);
                    }
                    
                    gunSetSightVisible(GUNAMMOREASON_DAMAGE, TRUE);
                    gunSetGunAmmoVisible(GUNSIGHTREASON_NOCONTROL, TRUE);
                    hudmsgsSetOn(1);
                    bondviewClearUpperTextDisplayFlag(1);
                    countdownTimerSetVisible(4, 1);
                    
                    g_CurrentPlayer->watch_animation_state = 0;
                    g_CurrentPlayer->watch_pause_time = 0;
                    g_CurrentPlayer->field_1C4 = 0;
                }
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 9)
        {
            g_CurrentPlayer->pausing_flag = 0;
            
            if (
                (getCurrentPlayerWeaponId(GUNLEFT) != get_item_in_hand_or_watch_menu(GUNLEFT))
                && (Gun_hand_without_item(GUNLEFT) != ITEM_UNARMED)
                && (
                    (sp3c == 0)
                    || (((getCurrentPlayerWeaponId(GUNRIGHT) != get_item_in_hand_or_watch_menu(GUNRIGHT))) && (Gun_hand_without_item(GUNRIGHT) != ITEM_UNARMED))))
            {
                g_CurrentPlayer->watch_animation_state = 8;
                g_CurrentPlayer->watch_pause_time = 0;
                g_CurrentPlayer->field_1C4 = 0;
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 10)
        {
            g_CurrentPlayer->pausing_flag = 0;
            
            if (g_CurrentPlayer->watch_pause_time == 1)
            {
                sub_GAME_7F07E03C(bondviewPauseAngleRelated(0));
            }
            
            if (
                (getCurrentPlayerWeaponId(GUNLEFT) != get_item_in_hand_or_watch_menu(GUNLEFT)) 
                && (Gun_hand_without_item(GUNLEFT) != ITEM_UNARMED) 
                && (
                    (sp3c == 0)
                    || (((getCurrentPlayerWeaponId(GUNRIGHT) != get_item_in_hand_or_watch_menu(GUNRIGHT))) && (Gun_hand_without_item(GUNRIGHT) != ITEM_UNARMED))))
            {
                g_CurrentPlayer->watch_animation_state = 8;
                g_CurrentPlayer->watch_pause_time = 0;
                g_CurrentPlayer->field_1C4 = 0;
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 11)
        {
            g_CurrentPlayer->pausing_flag = 0;

            if (
                (getCurrentPlayerWeaponId(GUNLEFT) == get_item_in_hand_or_watch_menu(GUNLEFT)) 
                && (Gun_hand_without_item(GUNLEFT) != ITEM_UNARMED) 
                && (
                    (sp3c == 0) 
                    || (
                        ( (getCurrentPlayerWeaponId(GUNRIGHT) == get_item_in_hand_or_watch_menu(GUNRIGHT))) 
                        && (Gun_hand_without_item(GUNRIGHT) != ITEM_UNARMED))))
            {
                g_CurrentPlayer->watch_animation_state = 1;
                g_CurrentPlayer->watch_pause_time = 0;
                g_CurrentPlayer->field_1C4 = 0;
            }
        }
        
        if (g_CurrentPlayer->watch_animation_state == 13)
        {
            g_CurrentPlayer->pausing_flag = 0;
            
            if (Gun_hand_without_item(GUNLEFT)
                && Gun_hand_without_item(GUNRIGHT))
            {
                if ((g_CurrentPlayer->hands[1].when_detonating_mines_is_0 != 5)
                    && (g_CurrentPlayer->hands[1].when_detonating_mines_is_0 != 6)
                    && (g_CurrentPlayer->hands[1].when_detonating_mines_is_0 != 7)
                    && (g_CurrentPlayer->hands[1].when_detonating_mines_is_0 != 8))
                {
                    g_CurrentPlayer->watch_animation_state = 1;
                    g_CurrentPlayer->watch_pause_time = 0;
                    g_CurrentPlayer->field_1C4 = 0;
                }
            }
        }

        sub_GAME_7F07E090();
        bondviewStepWatchAnimation();
        bondviewUpdateWatchZoomIn();
    }

    if (g_CurrentPlayer->watch_animation_state == 5)
    {
        lvlSetControlsLockedFlag(TRUE);
        sub_GAME_7F0A6A80();
    }
    else if (g_CurrentPlayer->watch_animation_state == 12)
    {
        lvlSetControlsLockedFlag(TRUE);
    }
    else
    {
        lvlSetControlsLockedFlag(FALSE);
    }

#undef WATCH_VAR_LOWER
#undef WATCH_VAR_UPPER
}



void set_open_close_solo_watch_menu_to1(void) {
    g_CurrentPlayer->open_close_solo_watch_menu = 1;
}





/**
 * US address 7F07F874.
 * EU address 7F07F918.
*/
void trigger_solo_watch_menu(s32 arg0)
{
    struct WatchVertex *ptr_a;
    Gfx *ptr_b;
    struct WatchVertex *next;
    struct WatchVertex *ptr_copy;
    int i;

    if (g_CurrentPlayer->watch_animation_state == 0)
    {
        if (arg0 == 0)
        {
            watch_transition_time *= 1.1f;
            if (watch_transition_time > 1.7f)
            {
                watch_transition_time = 1.7f;
            }

            if ((Gun_hand_without_item(GUNLEFT) != ITEM_UNARMED)
                && (Gun_hand_without_item(GUNRIGHT) != ITEM_UNARMED)
                && (g_CurrentPlayer->hands[1].when_detonating_mines_is_0 != 5)
                && (g_CurrentPlayer->hands[1].when_detonating_mines_is_0 != 6)
                && (g_CurrentPlayer->hands[1].when_detonating_mines_is_0 != 7)
                && (g_CurrentPlayer->hands[1].when_detonating_mines_is_0 != 8))
            {
                g_CurrentPlayer->watch_animation_state = 1;
            }
            else
            {
                g_CurrentPlayer->watch_animation_state = 0xD;
            }
            
            g_CurrentPlayer->watch_pause_time = 0;
            g_CurrentPlayer->field_1C4 = 0;
            
            sub_GAME_7F07DEFC();
            bondviewTriggerWatchZoomDefault();

            sub_GAME_7F0A2F30(&g_CurrentPlayer->healthdamagetype, 0x2E, 1, get_BONDdata_watch_armor());
            sub_GAME_7F0A3330(&g_CurrentPlayer->watch_body_armor_bar_gdl, OS_K0_TO_PHYSICAL(&g_CurrentPlayer->healthdamagetype), 0x2E);

            sub_GAME_7F0A2F30(&g_CurrentPlayer->related_to_health_display, 0x2E, -1, bondviewGetCurrentPlayerHealth());
            sub_GAME_7F0A3330(&g_CurrentPlayer->watch_health_bar_gdl, OS_K0_TO_PHYSICAL(&g_CurrentPlayer->related_to_health_display), 0x2E);
            
            sub_GAME_7F0A69A8();

            /**
             * This section is for rendering the selected screen rectangles.
            */
            ptr_b = g_CurrentPlayer->buffer_for_watch_greenbackdrop_DL; // Gfx
            ptr_a = &g_CurrentPlayer->buffer_for_watch_greenbackdrop_vertices->vtx[0]; // struct WatchRectangle

            for (i=0;
                i<(WATCH_NUMBER_SCREENS * WATCH_SCREEN_SELECT_RECTANGLE_HSTEP);
                i+=WATCH_SCREEN_SELECT_RECTANGLE_HSTEP)
            {
                // Note: colors are set here but overwritten in watch.c set_page_rectangle_colors
                ptr_copy = ptr_a;
                ptr_a = setup_watch_rectangles(ptr_a, i, 0, 0x64, 0x14, -0x12B, 0x136);
                ptr_b = sub_GAME_7F0A3B40(ptr_b, OS_K0_TO_PHYSICAL(ptr_copy));
            }

            gSPEndDisplayList(ptr_b);
            /**
             * End watch screen select rectangles.
            */

            /**
             * This section is related to rendering static on the watch menu.
             * Static is defined by a horizontal bar in the middle of the screen.
            */
            ptr_a = &g_CurrentPlayer->buffer_for_watch_static_vertices->vtx[0]; // struct WatchRectangle
            ptr_b = g_CurrentPlayer->buffer_for_watch_static_DL; // Gfx

            ptr_copy = &g_CurrentPlayer->buffer_for_watch_static_vertices->vtx[0];
            next = setup_watch_rectangles(ptr_a, 0, 0, 0x398, 0x14, -0x1CC, 0);
            ptr_b = sub_GAME_7F0A3B40(ptr_b, OS_K0_TO_PHYSICAL(ptr_copy));

            gSPEndDisplayList(ptr_b);
            /**
             * End watch static section.
            */
        }
    }
    else if (g_CurrentPlayer->watch_animation_state == 1)
    {
        g_CurrentPlayer->watch_animation_state = 9;
        g_CurrentPlayer->watch_pause_time = 0;
        g_CurrentPlayer->field_1C4 = 0;
    }
    else if (g_CurrentPlayer->watch_animation_state == 2)
    {
        g_CurrentPlayer->watch_animation_state = 0xA;
        g_CurrentPlayer->watch_pause_time = 0;
        g_CurrentPlayer->field_1C4 = 0;
    }
    else if (g_CurrentPlayer->watch_animation_state == 3)
    {
        g_CurrentPlayer->watch_animation_state = 7;
        g_CurrentPlayer->watch_pause_time = 0;
        g_CurrentPlayer->field_1C4 = 0;
    }
    else if (g_CurrentPlayer->watch_animation_state == 4)
    {
        g_CurrentPlayer->watch_animation_state = 6;
        g_CurrentPlayer->watch_pause_time = 0;
        g_CurrentPlayer->field_1C4 = 0;
    }
    else if (g_CurrentPlayer->watch_animation_state == 5)
    {
        deleteCurrentSelectedFolder();
        sub_GAME_7F0C1340();
        g_CurrentPlayer->watch_animation_state = 0xC;
        g_CurrentPlayer->watch_pause_time = 0;
        g_CurrentPlayer->field_1C4 = 0;
        g_CurrentPlayer->open_close_solo_watch_menu = 0;
    }
    else if (g_CurrentPlayer->watch_animation_state == 12)
    {
        // removed
    }
    else if (g_CurrentPlayer->watch_animation_state == 6)
    {
        if (arg0 == 0)
        {
            g_CurrentPlayer->watch_animation_state = 4;
            g_CurrentPlayer->watch_pause_time = 0;
            g_CurrentPlayer->field_1C4 = 0;
            sub_GAME_7F0A69A8();
        }
    }
    else if (g_CurrentPlayer->watch_animation_state == 7)
    {
        if (arg0 == 0)
        {
            g_CurrentPlayer->watch_animation_state = 3;
            g_CurrentPlayer->watch_pause_time = 0;
            g_CurrentPlayer->field_1C4 = 0;
            sub_GAME_7F0A69A8();
        }
    }
    else if (g_CurrentPlayer->watch_animation_state == 8)
    {
        if (arg0 == 0)
        {
            g_CurrentPlayer->watch_animation_state = 0xB;
            g_CurrentPlayer->watch_pause_time = 0;
            g_CurrentPlayer->field_1C4 = 0;
            sub_GAME_7F0A69A8();
        }
    }
    else if (g_CurrentPlayer->watch_animation_state == 9)
    {
        if (arg0 == 0)
        {
            g_CurrentPlayer->watch_animation_state = 1;
            g_CurrentPlayer->watch_pause_time = 0;
            g_CurrentPlayer->field_1C4 = 0;
        }
    }
    else if (g_CurrentPlayer->watch_animation_state == 10)
    {
        if (arg0 == 0)
        {
            g_CurrentPlayer->watch_animation_state = 1;
            g_CurrentPlayer->watch_pause_time = 0;
            g_CurrentPlayer->field_1C4 = 0;
        }
    }
    else if (g_CurrentPlayer->watch_animation_state == 11)
    {
        g_CurrentPlayer->watch_animation_state = 8;
        g_CurrentPlayer->watch_pause_time = 0;
        g_CurrentPlayer->field_1C4 = 0;
    }
    else if (g_CurrentPlayer->watch_animation_state == 13)
    {
        g_CurrentPlayer->watch_animation_state = 0;
    }
}

/**
 * US address 7F07FCC4.
 * Perfect Dark bwalkUpdateSpeedSideways.
*/
void bondviewUpdateSpeedSideways(s32 arg0) {
    if (arg0 == -1) {
        g_CurrentPlayer->speedstrafe = (g_CurrentPlayer->speedstrafe - g_GlobalTimerDelta);
        if (g_CurrentPlayer->speedstrafe < -1.0f) {
            g_CurrentPlayer->speedstrafe = -1.0f;
        }
    }
    else {
        if (arg0 == 1) {
            g_CurrentPlayer->speedstrafe = (g_CurrentPlayer->speedstrafe + g_GlobalTimerDelta);
            if (1.0f < g_CurrentPlayer->speedstrafe) {
                g_CurrentPlayer->speedstrafe = 1.0f;
            }
        } else {
            if (0.0f < g_CurrentPlayer->speedstrafe) {
                g_CurrentPlayer->speedstrafe = (g_CurrentPlayer->speedstrafe - g_GlobalTimerDelta);
                if (g_CurrentPlayer->speedstrafe < 0.0f) {
                    g_CurrentPlayer->speedstrafe = 0.0f;
                }
            } else {
                g_CurrentPlayer->speedstrafe = (g_CurrentPlayer->speedstrafe + g_GlobalTimerDelta);
                if (0.0f < g_CurrentPlayer->speedstrafe) {
                    g_CurrentPlayer->speedstrafe = 0.0f;
                }
            }
        }
    }
    g_CurrentPlayer->speedsideways = g_CurrentPlayer->speedstrafe;
}

/**
 * US address 7F07FE1C.
 * Perfect Dark bwalkUpdateSpeedForwards.
*/
void bondviewUpdateSpeedForwards(s32 arg0) {
    if (arg0 == 1) {
        g_CurrentPlayer->field_2A4C = (g_CurrentPlayer->field_2A4C + g_GlobalTimerDelta);
        if (1.0f < g_CurrentPlayer->field_2A4C) {
            g_CurrentPlayer->field_2A4C = 1.0f;
        }
    } else {
        if (arg0 == -1) {
            g_CurrentPlayer->field_2A4C = (g_CurrentPlayer->field_2A4C - g_GlobalTimerDelta);
            if (g_CurrentPlayer->field_2A4C < -1.0f) {
                g_CurrentPlayer->field_2A4C = -1.0f;
            }
        } else {
            if (0.0f < g_CurrentPlayer->field_2A4C) {
                g_CurrentPlayer->field_2A4C = (g_CurrentPlayer->field_2A4C - g_GlobalTimerDelta);
                if (g_CurrentPlayer->field_2A4C < 0.0f) {
                    g_CurrentPlayer->field_2A4C = 0.0f;
                }
            } else {
                g_CurrentPlayer->field_2A4C = (g_CurrentPlayer->field_2A4C + g_GlobalTimerDelta);
                if (0.0f < g_CurrentPlayer->field_2A4C) {
                    g_CurrentPlayer->field_2A4C = 0.0f;
                }
            }
        }
    }
    g_CurrentPlayer->speedforwards = g_CurrentPlayer->field_2A4C;
}

/**
 * US address 7F07FF74.
 * Duplicate of sub_GAME_7F080228.
*/
f32 sub_GAME_7F07FF74(f32 value) {
    if (value > 0) {
        return (viGetFovY() * value * -0.7f) / FOV_Y_F;
    }

    if (value < 0) {
        return (viGetFovY() * -value * 0.7f) / FOV_Y_F;
    }

    return 0;
}


/**
 * Address 0x7F080010.
 */
void bondviewCurrentPlayerUpdateSpeedVerta(f32 value)
{
    f32 mult = viGetFovY() / FOV_Y_F;
    f32 limit = sub_GAME_7F07FF74(value);
    
    if (value > 0.0f)
    {
        if (g_CurrentPlayer->speedverta > 0.0f)
        {
            g_CurrentPlayer->speedverta -= (0.05f * g_GlobalTimerDelta * mult);
        }
        else
        {
            g_CurrentPlayer->speedverta -= (0.0125f * g_GlobalTimerDelta * mult);
        }

        if (g_CurrentPlayer->speedverta < limit)
        {
            g_CurrentPlayer->speedverta = limit;
        }
    }
    else if (value < 0.0f)
    {
        if (g_CurrentPlayer->speedverta < 0.0f)
        {
            g_CurrentPlayer->speedverta += (0.05f * g_GlobalTimerDelta * mult);
        }
        else
        {
            g_CurrentPlayer->speedverta += (0.0125f * g_GlobalTimerDelta * mult);
        }

        if (g_CurrentPlayer->speedverta > limit)
        {
            g_CurrentPlayer->speedverta = limit;
        }
    }
    else
    {
        if (g_CurrentPlayer->speedverta > limit)
        {
            g_CurrentPlayer->speedverta -= (0.05f * g_GlobalTimerDelta * mult);

            if (g_CurrentPlayer->speedverta < limit)
            {
                g_CurrentPlayer->speedverta = limit;
            }
        }
        else
        {
            g_CurrentPlayer->speedverta += (0.05f * g_GlobalTimerDelta * mult);

            if (g_CurrentPlayer->speedverta > limit)
            {
                g_CurrentPlayer->speedverta = limit;
            }
        }
    }
}



/**
 * US address 7F080228.
 * Duplicate of sub_GAME_7F07FF74.
*/
f32 sub_GAME_7F080228(f32 arg0) {
    if (0.0f < arg0) {
        return (viGetFovY() * arg0 * -0.7f) / FOV_Y_F;
    } else if (arg0 < 0.0f) {
        return (viGetFovY() * -arg0 * 0.7f) / FOV_Y_F;
    } else {
        return 0.0f;
    }
}

/**
 * Address 0x7F0802C4.
 */
void bondviewCurrentPlayerUpdateSpeedTheta(f32 value)
{
    f32 mult = viGetFovY() / FOV_Y_F;
    f32 limit = sub_GAME_7F080228(value);
    
    if (value > 0.0f)
    {
        if (g_CurrentPlayer->speedtheta > 0.0f)
        {
            g_CurrentPlayer->speedtheta -= (0.05f * g_GlobalTimerDelta * mult);
        }
        else
        {
            g_CurrentPlayer->speedtheta -= (0.0125f * g_GlobalTimerDelta * mult);
        }

        if (g_CurrentPlayer->speedtheta < limit)
        {
            g_CurrentPlayer->speedtheta = limit;
        }
    }
    else if (value < 0.0f)
    {
        if (g_CurrentPlayer->speedtheta < 0)
        {
            g_CurrentPlayer->speedtheta += (0.05f * g_GlobalTimerDelta * mult);
        }
        else
        {
            g_CurrentPlayer->speedtheta += (0.0125f * g_GlobalTimerDelta * mult);
        }

        if (limit < g_CurrentPlayer->speedtheta)
        {
            g_CurrentPlayer->speedtheta = limit;
        }
    }
    else
    {
        if (limit < g_CurrentPlayer->speedtheta)
        {
            g_CurrentPlayer->speedtheta -= (0.05f * g_GlobalTimerDelta * mult);

            if (g_CurrentPlayer->speedtheta < limit)
            {
                g_CurrentPlayer->speedtheta = limit;
            }
        }
        else
        {
            g_CurrentPlayer->speedtheta += (0.05f * g_GlobalTimerDelta * mult);

            if (limit < g_CurrentPlayer->speedtheta)
            {
                g_CurrentPlayer->speedtheta = limit;
            }
        }
    }
}


Gfx *currentPlayerDrawFade(Gfx *gdl) {
    f32 frac = g_CurrentPlayer->colourscreenfrac;
    s32 r = g_CurrentPlayer->colourscreenred;
    s32 g = g_CurrentPlayer->colourscreengreen;
    s32 b = g_CurrentPlayer->colourscreenblue;
    if ((camera_80036430 != 0) || (camera_80036434 != 0)) {
        frac = 1.0f;
        b = 0;
        g = 0;
        r = 0;
    }
    if (frac > 0) {
        gDPPipeSync(gdl++);
        gDPSetCycleType(gdl++, G_CYC_1CYCLE);
        gDPSetColorDither(gdl++, G_CD_DISABLE);
        gDPSetTexturePersp(gdl++, G_TP_NONE);
        gDPSetAlphaCompare(gdl++, G_AC_NONE);
        gDPSetTextureLOD(gdl++, G_TL_TILE);
        gDPSetTextureFilter(gdl++, G_TF_BILERP);
        gDPSetTextureConvert(gdl++, G_TC_FILT);
        gDPSetTextureLUT(gdl++, G_TT_NONE);
        gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetPrimColor(gdl++, 0, 0, r, g, b, (s32)(frac * 255.0f));
        gDPFillRectangle(gdl++, viGetViewLeft(), viGetViewTop(), (viGetViewLeft() + viGetViewWidth()), (viGetViewTop() + viGetViewHeight()));
        gDPPipeSync(gdl++);
        gDPSetColorDither(gdl++, G_CD_BAYER);
        gDPSetTexturePersp(gdl++, G_TP_PERSP);
        gDPSetTextureLOD(gdl++, G_TL_LOD);
    }

    return gdl;
}

void currentPlayerSetFadeColour(s32 r, s32 g, s32 b, f32 frac) {
    g_CurrentPlayer->colourscreenred = r;
    g_CurrentPlayer->colourscreengreen = g;
    g_CurrentPlayer->colourscreenblue = b;
    g_CurrentPlayer->colourscreenfrac = frac;
}

void currentPlayerAdjustFade(f32 maxfadetime, s32 r, s32 g, s32 b, f32 frac)
{
    g_CurrentPlayer->colourfadetime60    = 0;
    g_CurrentPlayer->colourfadetimemax60 = maxfadetime;
    g_CurrentPlayer->colourfaderedold    = g_CurrentPlayer->colourscreenred;
    g_CurrentPlayer->colourfaderednew    = r;
    g_CurrentPlayer->colourfadegreenold  = g_CurrentPlayer->colourscreengreen;
    g_CurrentPlayer->colourfadegreennew  = g;
    g_CurrentPlayer->colourfadeblueold   = g_CurrentPlayer->colourscreenblue;
    g_CurrentPlayer->colourfadebluenew   = b;
    g_CurrentPlayer->colourfadefracold   = g_CurrentPlayer->colourscreenfrac;
    g_CurrentPlayer->colourfadefracnew   = frac;
}

void currentPlayerSetFadeFrac(f32 maxfadetime, f32 frac)
{
    currentPlayerAdjustFade(maxfadetime, g_CurrentPlayer->colourscreenred, g_CurrentPlayer->colourscreengreen, g_CurrentPlayer->colourscreenblue, frac);
}

bool currentPlayerIsFadeComplete(void)
{
	return g_CurrentPlayer->colourfadetimemax60 < 0;
}

void currentPlayerUpdateColourScreenProperties(void)
{
    if (g_CurrentPlayer->colourfadetimemax60 >= 0)
    {
        g_CurrentPlayer->colourfadetime60 += g_GlobalTimerDelta;

        if (g_CurrentPlayer->colourfadetime60 < g_CurrentPlayer->colourfadetimemax60)
        {
            f32 mult                           = g_CurrentPlayer->colourfadetime60 / g_CurrentPlayer->colourfadetimemax60;
            g_CurrentPlayer->colourscreenfrac  = g_CurrentPlayer->colourfadefracold + (g_CurrentPlayer->colourfadefracnew - g_CurrentPlayer->colourfadefracold) * mult;
            g_CurrentPlayer->colourscreenred   = g_CurrentPlayer->colourfaderedold + (s32)((g_CurrentPlayer->colourfaderednew - g_CurrentPlayer->colourfaderedold) * mult);
            g_CurrentPlayer->colourscreengreen = g_CurrentPlayer->colourfadegreenold + (s32)((g_CurrentPlayer->colourfadegreennew - g_CurrentPlayer->colourfadegreenold) * mult);
            g_CurrentPlayer->colourscreenblue  = g_CurrentPlayer->colourfadeblueold + (s32)((g_CurrentPlayer->colourfadebluenew - g_CurrentPlayer->colourfadeblueold) * mult);
            return;
        }

        g_CurrentPlayer->colourscreenfrac    = g_CurrentPlayer->colourfadefracnew;
        g_CurrentPlayer->colourscreenred     = g_CurrentPlayer->colourfaderednew;
        g_CurrentPlayer->colourscreengreen   = g_CurrentPlayer->colourfadegreennew;
        g_CurrentPlayer->colourscreenblue    = g_CurrentPlayer->colourfadebluenew;
        g_CurrentPlayer->colourfadetimemax60 = -1;
    }
}

void currentPlayerStartChrFade(f32 duration60, f32 targetfrac)
{
    ChrRecord *chr = g_CurrentPlayer->prop->chr;

    if (chr)
    {
        g_CurrentPlayer->bondfadetime60    = 0;
        g_CurrentPlayer->bondfadetimemax60 = duration60;
        g_CurrentPlayer->bondfadefracold   = chr->fadealpha / 255.0f;
        g_CurrentPlayer->bondfadefracnew   = targetfrac;
    }
}

void currentPlayerTickChrFade(void)
{
    if (g_CurrentPlayer->bondfadetimemax60 >= 0)
    {
        ChrRecord *chr = g_CurrentPlayer->prop->chr;
        f32        frac;

        g_CurrentPlayer->bondfadetime60 += g_GlobalTimerDelta;

        if (g_CurrentPlayer->bondfadetime60 < g_CurrentPlayer->bondfadetimemax60)
        {
            frac = g_CurrentPlayer->bondfadefracold + (g_CurrentPlayer->bondfadefracnew - g_CurrentPlayer->bondfadefracold) * g_CurrentPlayer->bondfadetime60 / g_CurrentPlayer->bondfadetimemax60;
        }
        else
        {
            frac = g_CurrentPlayer->bondfadefracnew;
            g_CurrentPlayer->bondfadetimemax60 = -1;
        }

        if (chr)
        {
            chr->fadealpha = (s8)(frac * 255);
        }
    }
}

/**
 * Will apply a move animation update. The pass through call to bheadUpdate is
 * what allows Bond to move. This will also trigger the death animation once
 * Bond dies. This chooses a random death animation from g_bondviewBondDeathAnimations.
 * Address 0x7F080B34.
*/
void bondviewMoveAnimationTick(f32 speed, f32 speedforwards, f32 speedsideways)
{
    f32 percent_speed;
    Mtxf sp8C;
    Mtxf sp4C;

    percent_speed = 0.0f;

    if (g_CurrentPlayer->bonddead == 0)
    {
        bheadAdjustAnimation(speed);

        if (speed != 0.0f)
        {
            percent_speed = speedforwards / speed;
        }
        else if (speedforwards == 0.0f)
        {
            //
        }
    }
    else
    {
        if (g_CurrentPlayer->startnewbonddie != 0)
        {
            // HACK: ptr_animation_table dereference addition is backwards.
            // this should be:
            // ptr_animation_table->data[g_bondviewBondDeathAnimations[((u32) randomGetNext() % (u32) g_bondviewBondDeathAnimationsCount)]]
            bheadStartDeathAnimation((struct ModelAnimation *) ((s32)g_bondviewBondDeathAnimations[((u32) randomGetNext() % (u32) g_bondviewBondDeathAnimationsCount)] + (s32)&ptr_animation_table->data[0]), randomGetNext() & 1, 0.0f, 1.0f);
            g_CurrentPlayer->startnewbonddie = 0;
        }

        bheadSetSpeed(0.5f);
        speedsideways = 0.0f;
    }
    
    bheadUpdate(percent_speed, speedsideways);

    matrix_4x4_set_rotation_around_x((360.0f - g_CurrentPlayer->vv_verta360) * DegToRad1Fact(1), &sp8C);
    matrix_4x4_7F059908(&sp4C, 0.0f, 0.0f, 0.0f, -g_CurrentPlayer->headlook.f[0], -g_CurrentPlayer->headlook.f[1], -g_CurrentPlayer->headlook.f[2], g_CurrentPlayer->headup.f[0], g_CurrentPlayer->headup.f[1], g_CurrentPlayer->headup.f[2]);
    matrix_4x4_multiply_in_place(&sp4C, &sp8C);
    matrix_4x4_set_rotation_around_y((360.0f - g_CurrentPlayer->vv_theta) * DegToRad1Fact(1), &sp4C);
    matrix_4x4_multiply_in_place(&sp4C, &sp8C);

    g_CurrentPlayer->field_488.applied_view.f[0] = sp8C.m[2][0];
    g_CurrentPlayer->field_488.applied_view.f[1] = sp8C.m[2][1];
    g_CurrentPlayer->field_488.applied_view.f[2] = sp8C.m[2][2];
    
    g_CurrentPlayer->field_488.applied_view2.f[0] = sp8C.m[1][0];
    g_CurrentPlayer->field_488.applied_view2.f[1] = sp8C.m[1][1];
    g_CurrentPlayer->field_488.applied_view2.f[2] = sp8C.m[1][2];

}


/**
 * Address 0x7F080D60.
 */
f32 bondviewYPositionRelated(StandTile *arg0, f32 arg1, f32 arg2)
{
    f32 ret;

    if (g_PlayerTankProp != NULL)
    {
        ObjectRecord * obj = ((PropRecord *)g_PlayerTankProp)->obj;
        PropRecord *p = obj->prop;

        ret = stanGetPositionYValue(p->stan, p->pos.x, p->pos.z);
            
        ret += g_PlayerTankYOffset;
    }
    else
    {
        if (g_CurrentPlayer->field_2A6C)
        {
            ret = stanGetPositionYValue(g_CurrentPlayer->field_2A70, arg1, arg2);
        }
        else
        {
            ret = stanGetPositionYValue(arg0, arg1, arg2);
        }
    }

    return ret;
}



/**
 * US Address 0x7F080DF8.
 * EU Address 0x7F080E9C.
 */
void bondviewUpdatePlayerY(s32 use_stanHeight, f32 stanHeight_offset)
{
    s32 i; // sp6c
    f32 unused;
    f32 sp64;
    StandTile *stan; //sp60
    f32 collision_radius; //sp5c
    f32 height; //sp58
    f32 always_30; //sp54
    f32 temp_f0; // no stack
    f32 new_field_70; // sp4c
    f32 new_field_7c; //sp48
    f32 ftemp2;
    f32 sp40;

    if (1);

    if (in_tank_flag == 1)
    {
        g_CurrentPlayer->stanHeight = bondviewYPositionRelated(
            g_CurrentPlayer->field_488.current_tile_ptr,
            g_CurrentPlayer->field_488.collision_position.f[0],
            g_CurrentPlayer->field_488.collision_position.f[2]);

        g_CurrentPlayer->field_6C = g_CurrentPlayer->field_70 / (1.0f - TANK_UNKD0_SCALE);

        for (i=0; i<g_ClockTimer; i++)
        {
            g_CurrentPlayer->field_6C = (g_CurrentPlayer->field_6C * TANK_UNKD0_SCALE) + g_CurrentPlayer->stanHeight;
        }

        g_CurrentPlayer->field_70 = g_CurrentPlayer->field_6C * (1.0f - TANK_UNKD0_SCALE);
    }
    else
    {
        if (use_stanHeight != 0)
        {
            g_CurrentPlayer->stanHeight = g_CurrentPlayer->stanHeight + stanHeight_offset;

            temp_f0 = bondviewYPositionRelated(
                g_CurrentPlayer->field_488.current_tile_ptr,
                g_CurrentPlayer->field_488.collision_position.f[0],
                g_CurrentPlayer->field_488.collision_position.f[2]);
            
            if (g_CurrentPlayer->stanHeight < temp_f0)
            {
                g_CurrentPlayer->stanHeight = temp_f0;
            }
        }
        else
        {
            stan = g_CurrentPlayer->field_488.current_tile_ptr;

            bondviewGetCollisionRadius(g_CurrentPlayer->prop, &collision_radius, &height, &always_30);
            
            sp64 = bondviewYPositionRelated(
                g_CurrentPlayer->field_488.current_tile_ptr,
                g_CurrentPlayer->field_488.collision_position.f[0],
                g_CurrentPlayer->field_488.collision_position.f[2]);

            // Another error checking block, it seems this condition is almost never triggered in the game.
            if (sub_GAME_7F0B26B8(
                &stan,
                g_CurrentPlayer->field_488.collision_position.f[0],
                g_CurrentPlayer->field_488.collision_position.f[2],
                collision_radius,
                bondviewGetPlayerDuckingHeightRelated(g_CurrentPlayer) + sp64) >= 0)
            {
                if (sp64 < g_CurrentPlayer->stanHeight)
                {
                    sp64 = g_CurrentPlayer->stanHeight;
                }
            }
            
            g_CurrentPlayer->stanHeight = sp64;
        }

        if ((g_CurrentPlayer->field_2A6C != 0) && (g_CurrentPlayer->field_70 < g_CurrentPlayer->stanHeight))
        {
            g_CurrentPlayer->field_2A6C = 0;
            g_CurrentPlayer->field_488.current_tile_ptr = g_CurrentPlayer->field_2A70;
            g_CurrentPlayer->field_2A70 = NULL;
        }

        if ((g_CurrentPlayer->field_7C >= 0.0f) || (g_CurrentPlayer->field_70 < g_CurrentPlayer->stanHeight))
        {
            g_CurrentPlayer->field_6C = g_CurrentPlayer->field_70 / (1.0f - TANK_UNKD0_SCALE);

            for (i=0; i<g_ClockTimer; i++)
            {
                g_CurrentPlayer->field_6C = (g_CurrentPlayer->field_6C * TANK_UNKD0_SCALE) + g_CurrentPlayer->stanHeight;
            }

            if (g_CurrentPlayer->field_70 < g_CurrentPlayer->stanHeight)
            {
                g_CurrentPlayer->field_70 = g_CurrentPlayer->field_6C * (1.0f - TANK_UNKD0_SCALE);
            }
        }

        if (g_CurrentPlayer->stanHeight < g_CurrentPlayer->field_70)
        {
            new_field_7c = g_CurrentPlayer->field_7C;
            new_field_70 = g_CurrentPlayer->field_70;
            
            if ((get_debug_fast_bond_flag() != 0) && (g_ForceBondMoveOffset.f[0] == 0.0f) && (g_ForceBondMoveOffset.f[2] == 0.0f))
            {
                sp40 = 1.388889f;
            }
            else
            {
                sp40 = 0.27777779f;
            }
            
            ftemp2 = new_field_7c - (g_GlobalTimerDelta * sp40);
            new_field_70 += (g_GlobalTimerDelta * (new_field_7c + ftemp2) * 0.5f);
            new_field_7c = ftemp2;

            if (new_field_70 < g_CurrentPlayer->stanHeight)
            {
                new_field_70 = g_CurrentPlayer->stanHeight;
                new_field_7c = -sqrtf((g_CurrentPlayer->field_7C * g_CurrentPlayer->field_7C) + (((2.0f * (g_CurrentPlayer->field_70 - g_CurrentPlayer->stanHeight) * 0.27777779f) / 60.0f) * 60.0f));


                if (g_CurrentPlayer->field_2A6C != 0)
                {
                    g_CurrentPlayer->field_2A6C = 0;
                    g_CurrentPlayer->field_488.current_tile_ptr = g_CurrentPlayer->field_2A70;
                    g_CurrentPlayer->field_2A70 = NULL;
                }
            }

            g_CurrentPlayer->field_70 = new_field_70;
            g_CurrentPlayer->field_7C = new_field_7c;
        }

        if ((g_CurrentPlayer->field_7C < 0.0f) && (g_CurrentPlayer->field_70 <= g_CurrentPlayer->stanHeight))
        {
            if (g_CurrentPlayer->field_7C < -13.333333f)
            {
                g_CurrentPlayer->field_8C = CLIPPING_FIELD8C_VALUE;
                g_CurrentPlayer->vertical_bounce_adjust = -90.0f;
            }
            else if (g_CurrentPlayer->field_7C < -5.0f)
            {
                g_CurrentPlayer->field_8C = CLIPPING_FIELD8C_VALUE;
                g_CurrentPlayer->vertical_bounce_adjust = ((-5.0f - g_CurrentPlayer->field_7C) * -90.0f) / 8.333333f;
            }

            g_CurrentPlayer->field_7C = 0.0f;
        }

        if (g_CurrentPlayer->field_2A6C != 0)
        {
            if (g_CurrentPlayer->field_70 + bondviewGetPlayerDuckingHeightRelated(g_CurrentPlayer)
                < stanGetPositionYValue(
                    g_CurrentPlayer->field_488.current_tile_ptr,
                    g_CurrentPlayer->field_488.collision_position.f[0],
                    g_CurrentPlayer->field_488.collision_position.f[2]))
            {
                g_CurrentPlayer->field_2A6C = 0;
                g_CurrentPlayer->field_488.current_tile_ptr = g_CurrentPlayer->field_2A70;
                g_CurrentPlayer->field_2A70 = NULL;
            }
        }
    }

    for (i=0; i<g_ClockTimer; i++)
    {
        if (g_CurrentPlayer->field_8C > 0)
        {
            g_CurrentPlayer->field_84 = (g_CurrentPlayer->field_84 * CLIPPING_CLOCK_FACTOR) + g_CurrentPlayer->vertical_bounce_adjust;
            g_CurrentPlayer->field_8C += -1;
        }
        else
        {
            if (g_CurrentPlayer->vertical_bounce_adjust < 0.0f)
            {
                g_CurrentPlayer->vertical_bounce_adjust -= CLIPPING_FIELD90_VALUE;
                
                if (0.0f <= g_CurrentPlayer->vertical_bounce_adjust)
                {
                    g_CurrentPlayer->vertical_bounce_adjust = 0.0f;
                }
            }

            g_CurrentPlayer->field_84 = (g_CurrentPlayer->field_84 * CLIPPING_CLOCK_FACTOR) + g_CurrentPlayer->vertical_bounce_adjust;
        }
    }

    g_CurrentPlayer->field_88 = g_CurrentPlayer->field_84 * CLIPPING_FIELD88_FACTOR;
}





/**
 * Address 0x7F081478 (NTSC).
 * Address 0x7F08151C (PAL).
*/
void bondviewUpdatePlayerCollisionPositionFields(void)
{
    f32 phi_f0;
    s32 i;
    StandTile *sp2C;
    s32 sp28;

    g_CurrentPlayer->field_29BC = (g_CurrentPlayer->headpos.f[1] * g_playerPerm->player_perspective_height) + 7.0f;

    phi_f0 = g_CurrentPlayer->field_29BC + 
        ((g_CurrentPlayer->field_88 + g_CurrentPlayer->ducking_height_offset) * g_playerPerm->player_perspective_height);
    
    if (phi_f0 < 30.0f)
    {
        phi_f0 = 30.0f;
    }

    g_CurrentPlayer->field_488.collision_position.f[1] = g_CurrentPlayer->field_70 + phi_f0;
    
    if (((g_CameraMode != CAMERAMODE_DEATH_CAM_FIRST) && (g_CameraMode != CAMERAMODE_DEATH_CAM_SECOND) && (g_CameraMode != CAMERAMODE_POSEND))
        || (g_CurrentPlayer->ptr_char_objectinstance == 0))
    {
        g_CurrentPlayer->field_488.pos.f[0] = g_CurrentPlayer->field_488.collision_position.f[0];
        g_CurrentPlayer->field_488.pos.f[1] = g_CurrentPlayer->field_488.collision_position.f[1];
        g_CurrentPlayer->field_488.pos.f[2] = g_CurrentPlayer->field_488.collision_position.f[2];
    }
    
    if (g_CurrentPlayer->bonddead != 0)
    {
        if (g_CurrentPlayer->field_29C0 > 0.0f)
        {
            g_CurrentPlayer->field_29C0 -= 0.25f;

            if (g_CurrentPlayer->field_29C0 < 0.0f)
            {
                g_CurrentPlayer->field_29C0 = 0.0f;
            }
        }
    }

    if (g_CurrentPlayer->vv_verta < 0.0f)
    {
        g_CurrentPlayer->field_488.pos.f[1] += -(1.0f - g_CurrentPlayer->vv_cosverta) * g_CurrentPlayer->field_29C0;
    }

    sp2C = g_CurrentPlayer->field_488.current_tile_ptr;
    sp28 = stanlinelog_flag;
    stanlinelog_flag = 0;

    walkTilesBetweenPoints_NoCallback(
        &sp2C,
        g_CurrentPlayer->field_488.collision_position.f[0],
        g_CurrentPlayer->field_488.collision_position.f[2],
        g_CurrentPlayer->field_488.pos.f[0],
        g_CurrentPlayer->field_488.pos.f[2]);
    
    stanlinelog_flag = sp28;
    
    g_CurrentPlayer->field_488.current_tile_ptr_for_portals = sp2C;
    
    g_CurrentPlayer->field_488.pos3.f[0] = g_CurrentPlayer->field_488.pos.f[0];
    g_CurrentPlayer->field_488.pos3.f[2] = g_CurrentPlayer->field_488.pos.f[2];
    
    g_CurrentPlayer->field_488.pos3.f[1] = bondviewYPositionRelated(
        g_CurrentPlayer->field_488.current_tile_ptr_for_portals,
        g_CurrentPlayer->field_488.pos.f[0],
        g_CurrentPlayer->field_488.pos.f[2]);
    
    g_CurrentPlayer->prop->stan = g_CurrentPlayer->field_488.current_tile_ptr;
    
    g_CurrentPlayer->prop->pos.f[0] = g_CurrentPlayer->field_488.collision_position.f[0];
    g_CurrentPlayer->prop->pos.f[1] = g_CurrentPlayer->field_488.collision_position.f[1];
    g_CurrentPlayer->prop->pos.f[2] = g_CurrentPlayer->field_488.collision_position.f[2];
    
#if defined(VERSION_EU)
#define S7F081478_FACTOR_1 0.881200015545f
#else
#define S7F081478_FACTOR_1 0.9f
#endif
    for (i=0; i<g_ClockTimer; i++)
    {
        g_CurrentPlayer->field_3B8.f[0] = (S7F081478_FACTOR_1 * g_CurrentPlayer->field_3B8.f[0]) + g_CurrentPlayer->field_488.pos.f[0];
        g_CurrentPlayer->field_3B8.f[1] = (S7F081478_FACTOR_1 * g_CurrentPlayer->field_3B8.f[1]) + g_CurrentPlayer->field_488.pos.f[1];
        g_CurrentPlayer->field_3B8.f[2] = (S7F081478_FACTOR_1 * g_CurrentPlayer->field_3B8.f[2]) + g_CurrentPlayer->field_488.pos.f[2];
    }

#if defined(VERSION_EU)
#define S7F081478_FACTOR_2 0.118799984455f
#else
#define S7F081478_FACTOR_2 0.100000024f
#endif
    g_CurrentPlayer->field_3C4 = g_CurrentPlayer->field_3B8.f[0] * S7F081478_FACTOR_2;
    g_CurrentPlayer->field_3C8 = g_CurrentPlayer->field_3B8.f[1] * S7F081478_FACTOR_2;
    g_CurrentPlayer->field_3CC = g_CurrentPlayer->field_3B8.f[2] * S7F081478_FACTOR_2;
}





/**
 * Fixes vv_verta within -90 and +90.
 * Updates vv_costheta, vv_sintheta, vv_verta360, vv_cosverta, vv_sinverta, field_488.theta_transform.
 * Address 0x7F081790.
 * 
 * Perfect Dark function bmoveUpdateVerta.
*/
void bondviewApplyVertaTheta(void)
{
    while (g_CurrentPlayer->vv_verta < -180.0f)
    {
        g_CurrentPlayer->vv_verta += 360.0f;
    }

    while (g_CurrentPlayer->vv_verta >= 180.0f)
    {
        g_CurrentPlayer->vv_verta -= 360.0f;
    }

    if (g_CurrentPlayer->vv_verta > 90.0f)
    {
        g_CurrentPlayer->vv_verta = 90.0f;
    }
    else if (g_CurrentPlayer->vv_verta < -90.0f)
    {
        g_CurrentPlayer->vv_verta = -90.0f;
    }

    g_CurrentPlayer->vv_costheta = cosf(g_CurrentPlayer->vv_theta * DegToRad1Fact(1));
    g_CurrentPlayer->vv_sintheta = sinf(g_CurrentPlayer->vv_theta * DegToRad1Fact(1));

    g_CurrentPlayer->vv_verta360 = g_CurrentPlayer->vv_verta;
    if (g_CurrentPlayer->vv_verta360 < 0.0f)
    {
        g_CurrentPlayer->vv_verta360 += 360.0f;
    }

    g_CurrentPlayer->vv_cosverta = cosf(g_CurrentPlayer->vv_verta360 * DegToRad1Fact(1));
    g_CurrentPlayer->vv_sinverta = sinf(g_CurrentPlayer->vv_verta360 * DegToRad1Fact(1));

    g_CurrentPlayer->field_488.theta_transform.f[0] = -g_CurrentPlayer->vv_sintheta;
    g_CurrentPlayer->field_488.theta_transform.f[1] = 0;
    g_CurrentPlayer->field_488.theta_transform.f[2] = g_CurrentPlayer->vv_costheta;
}






/**
 * US address 7F081974.
 * EU address 7F081A18.
 * Perfect Dark method bmoveProcessInput.
*/
void bondviewProcessInput(s8 stick_x, s8 stick_y, u16 buttons, u16 oldbuttons)
{
    struct MoveData moveData; // sp120
    
    s8 player_joyGetStickX; // sp11F
    s8 player_joyGetStickY; // sp11E
    u16 player_joyGetButtons; // sp11C
    u16 copy_prev_buttons_pressed; // sp11A
    s32 tmpc2stickx;
    s32 tmpc2sticky;
    s32 sp10C;
    s32 sp108;
    s32 sp104;
    s32 sp100;
    u16 shootButtons; // spFE
    u16 aimButtons; // spFC
    u16 invButtons; // spFA
    // missing spF8
    TankRecord *spF4;
    s32 i_0; // spF0
    TankRecord *spEC;
    f32 ftemp_nostack_spE8; // unused
    f32 noiseRadius; // spE4
    f32 ftemp_nostack_spE0;
    f32 targetSpeed;
    f32 ftemp_nostack_spD8;
    f32 unadjustedTargetSpeed;
    f32 ftemp_nostack_spD0;
    f32 ftemp_nostack_spCC;
    f32 ftemp_nostack_spC8;
    f32 spC4;
    StandTile *spC0;
    f32 spBC;
    f32 ftemp_nostack_spB8;
    struct coord3d spAC;
    struct coord3d spA0;
    s32 stack_padding_sp9C; // unused
    f32 ftemp_nostack_sp98;
    f32 ftemp_nostack_sp94;
    f32 ftemp_nostack_sp90; // unused
    f32 ftemp_nostack_sp8C;
    f32 ftemp_nostack_sp88;
    f32 ftemp_nostack_sp84;
    f32 ftemp_nostack_sp80;
    s32 i_1;
    f32 ftemp_nostack_sp78;
    s32 canCycleWeapons; // sp74
    f32 sp70;


    moveData.canSwivelGun = 0;
    moveData.canManualAim = 0;
    moveData.triggerOn = 0;
    moveData.btap = 0;
    moveData.canLookAhead = 0;
    moveData.canTurnTank = 0;
    moveData.canNaturalTurn = 0;
    moveData.canNaturalPitch = 0;
    moveData.digitalStepForward = 0;
    moveData.digitalStepBack = 0;
    moveData.digitalStepLeft = 0;
    moveData.digitalStepRight = 0;
    moveData.tankTurnLeftSpeed = 0;
    moveData.tankTurnRightSpeed = 0;
    moveData.speedVertaDown = 0;
    moveData.speedVertaUp = 0;
    moveData.aimTurnLeftSpeed = 0;
    moveData.aimTurnRightSpeed = 0;    
    moveData.weaponBackOffset = 0;
    moveData.weaponForwardOffset = 0;
    moveData.aiming = 0;
    moveData.zooming = 0;
    moveData.zoomOutFovPersec = 0;
    moveData.zoomInFovPersec = 0;
    moveData.crouchDown = 0;
    moveData.crouchUp = 0;
    moveData.rLeanLeft = 0;
    moveData.rLeanRight = 0;
    moveData.detonating = 0;
    moveData.canAutoAim = 0;
    moveData.invertPitch = get_cur_player_look_vertical_inverted() == 0;
    moveData.disableLookAhead = 0;

    if (stick_x < -5) {
		moveData.controlStickXSafe = stick_x + 5;
	} else if (stick_x > 5) {
		moveData.controlStickXSafe = stick_x - 5;
	} else {
		moveData.controlStickXSafe = 0;
	}

	if (stick_y < -5) {
		moveData.controlStickYSafe = stick_y + 5;
	} else if (stick_y > 5) {
		moveData.controlStickYSafe = stick_y - 5;
	} else {
		moveData.controlStickYSafe = 0;
	}

    moveData.controlStickXRaw = (s32)stick_x;
    moveData.controlStickYRaw = (s32)stick_y;
    
    moveData.analogTurn = moveData.controlStickXSafe;    
    moveData.analogPitch = moveData.controlStickYSafe;
    moveData.analogStrafe = moveData.controlStickXSafe;
    moveData.analogWalk = moveData.controlStickYSafe;

    if (g_CurrentPlayer->bonddead == 0
        && g_bondviewForceDisarm <= 0
        && (
            (g_CurrentPlayer->watch_animation_state != 5 
                && ((buttons & ~oldbuttons) & START_BUTTON)
            ) 
            ||
            (g_CurrentPlayer->watch_animation_state == 5
                && g_CurrentPlayer->open_close_solo_watch_menu)
        )
        && (getPlayerCount() == 1))
    {
        trigger_solo_watch_menu(0);
    }

    if (g_CurrentPlayer->watch_animation_state == 0
        && g_CurrentPlayer->bonddead == 0
        && (
            getPlayerCount() == 1
            || (
                g_stopPlayFlag == 0
                && g_gameOverFlag == 0)))
    {
        if (cur_player_get_control_type() == CONTROLLER_CONFIG_DOMINO /* 2.3 */
            || cur_player_get_control_type() == CONTROLLER_CONFIG_GOODHEAD /* 2.4 */
            || cur_player_get_control_type() == CONTROLLER_CONFIG_GALORE /* 2.2 */
            || cur_player_get_control_type() == CONTROLLER_CONFIG_PLENTY /* 2.1 */
            )
        {
            player_joyGetStickX = joyGetStickX(get_cur_playernum() + getPlayerCount());
            player_joyGetStickY = joyGetStickY(get_cur_playernum() + getPlayerCount());
            player_joyGetButtons = joyGetButtons(get_cur_playernum() + getPlayerCount() , (u32)ANY_BUTTON);

            copy_prev_buttons_pressed = g_CurrentPlayer->prev_buttons_pressed;
            
            if (player_joyGetStickX < -5)
            {
                tmpc2stickx = player_joyGetStickX + 5;
            }
            else if (player_joyGetStickX > 5)
            {
                tmpc2stickx = player_joyGetStickX - 5;
            }
            else
            {
                tmpc2stickx = 0;
            }
            
            if (player_joyGetStickY < -5)
            {
                tmpc2sticky = player_joyGetStickY + 5;
            }
            else if (player_joyGetStickY >= 6)
            {
                tmpc2sticky = player_joyGetStickY - 5;
            }
            else
            {
                tmpc2sticky = 0;
            }

            /* 2.1 and 2.3 */
            if (cur_player_get_control_type() == CONTROLLER_CONFIG_PLENTY || (cur_player_get_control_type() == CONTROLLER_CONFIG_DOMINO))
            {
                moveData.analogStrafe = tmpc2stickx;
                moveData.analogPitch = tmpc2sticky;
            }
            else
            {
                if (in_tank_flag == 1 && !g_CurrentPlayer->insightaimmode)
                {
                    moveData.analogTurn = tmpc2stickx;
                }
                else
                {
                    moveData.analogStrafe = tmpc2stickx;
                }
                
                moveData.analogWalk = tmpc2sticky;
            }

            /* 2.1 and 2.2 */
            if (cur_player_get_control_type() == CONTROLLER_CONFIG_PLENTY || cur_player_get_control_type() == CONTROLLER_CONFIG_GALORE)
            {
                sp104 = (player_joyGetButtons & Z_TRIG) != 0;
                sp100 = ((player_joyGetButtons & ~copy_prev_buttons_pressed) & Z_TRIG) != 0;
                sp10C = (buttons & Z_TRIG) != 0;
                sp108 = ((buttons & ~oldbuttons) & Z_TRIG) != 0;
            }
            else
            {
                sp104 = (buttons & Z_TRIG) != 0;
                sp100 = ((buttons & ~oldbuttons) & Z_TRIG) != 0;
                sp10C = (player_joyGetButtons & Z_TRIG) != 0;
                sp108 = ((player_joyGetButtons & ~copy_prev_buttons_pressed) & Z_TRIG) != 0;
            }

            if (lvlGetControlsLockedFlag() == 0 && disablePlayerActionsWhenPausedOrInMpMenu())
            {
                if (cur_player_get_aim_control() == 0)
                {
                    g_CurrentPlayer->insightaimmode = sp104;
                }
                else if (sp100)
                {
                    g_CurrentPlayer->insightaimmode = !g_CurrentPlayer->insightaimmode;
                }

                moveData.canSwivelGun = !g_CurrentPlayer->insightaimmode;
                moveData.canAutoAim = !g_CurrentPlayer->insightaimmode;
                
                moveData.canManualAim = g_CurrentPlayer->insightaimmode;

                moveData.btap = (
                    (((buttons & ~oldbuttons) & B_BUTTON) != 0)
                    ||
                    ((((player_joyGetButtons & ~copy_prev_buttons_pressed) & B_BUTTON)) != 0)
                    );
                
                moveData.canLookAhead = !g_CurrentPlayer->insightaimmode;
                moveData.canTurnTank = 1;
                moveData.canNaturalTurn = !g_CurrentPlayer->insightaimmode;
                moveData.canNaturalPitch = !g_CurrentPlayer->insightaimmode;

                if (g_CurrentPlayer->insightaimmode && (stick_y > 60))
                {
                    moveData.speedVertaDown = (f32) (stick_y - 60) / FLOAT_TEN_B;
                    if (moveData.speedVertaDown > 1.0f)
                    {
                        moveData.speedVertaDown = 1.0f;
                    }
                }
                else
                {
                    //moveData.speedVertaDown = 0;
                }

                if (g_CurrentPlayer->insightaimmode && (stick_y < -60))
                {
                    moveData.speedVertaUp = (f32) (-60 - stick_y) / FLOAT_TEN_B;
                    if (moveData.speedVertaUp > 1.0f)
                    {
                        moveData.speedVertaUp = 1.0f;
                    }
                }
                else
                {
                    //moveData.speedVertaUp = 0;
                }

                
                if (g_CurrentPlayer->insightaimmode && (stick_x < -60))
                {
                    moveData.aimTurnLeftSpeed = (f32) (-60 - stick_x) / FLOAT_TEN_B;
                    if (moveData.aimTurnLeftSpeed > 1.0f)
                    {
                        moveData.aimTurnLeftSpeed = 1.0f;
                    }
                }
                else
                {
                    //moveData.aimTurnLeftSpeed = 0;
                }
                
                if (g_CurrentPlayer->insightaimmode && (stick_x > 60) )
                {
                    moveData.aimTurnRightSpeed = (f32) (stick_x - 60) / FLOAT_TEN_B;
                    if (moveData.aimTurnRightSpeed > 1.0f)
                    {
                        moveData.aimTurnRightSpeed = 1.0f;
                    }
                }
                else
                {
                    //moveData.aimTurnRightSpeed = 0;
                }
                
                moveData.weaponBackOffset = (
                        ((buttons & A_BUTTON) != 0)
                        ||
                        ((player_joyGetButtons & A_BUTTON) != 0)
                    )
                    && (sp108);
                
               moveData.weaponForwardOffset = (
                    (
                       (((buttons & ~oldbuttons) & A_BUTTON) != 0)
                       ||
                       (((player_joyGetButtons & ~copy_prev_buttons_pressed) & A_BUTTON) != 0)
                    ))
                    && (!sp10C);

                moveData.aiming = g_CurrentPlayer->insightaimmode;
                moveData.zooming = g_CurrentPlayer->insightaimmode;
                
                if ((bondwalkItemCheckBitflags(getCurrentPlayerWeaponId(GUNRIGHT), WEAPONSTATBITFLAG_DISABLE_CROUCH))
                    && g_CurrentPlayer->insightaimmode)
                {
                    if (tmpc2sticky < 0)
                    {
                        moveData.zoomOutFovPersec = (f32) -tmpc2sticky / 70.0f;
                        if (moveData.zoomOutFovPersec > 1.0f)
                        {
                            moveData.zoomOutFovPersec = 1.0f;
                        }
                        
                        moveData.zoomOutFovPersec *= 2.0f;
                    }
                    
                    if (tmpc2sticky > 0)
                    {
                        moveData.zoomInFovPersec = (f32) tmpc2sticky / 70.0f;
                        if (moveData.zoomInFovPersec > 1.0f)
                        {
                            moveData.zoomInFovPersec = 1.0f;
                        }
                        
                        moveData.zoomInFovPersec *= 2.0f;
                    }
                }
                
                moveData.crouchDown = (bondwalkItemCheckBitflags(getCurrentPlayerWeaponId(GUNRIGHT), WEAPONSTATBITFLAG_DISABLE_CROUCH) == 0)
                    && (g_CurrentPlayer->insightaimmode)
                    && (player_joyGetStickY < -30);

                moveData.crouchUp = (bondwalkItemCheckBitflags(getCurrentPlayerWeaponId(GUNRIGHT), WEAPONSTATBITFLAG_DISABLE_CROUCH) == 0)
                    && (g_CurrentPlayer->insightaimmode)
                    && (player_joyGetStickY > 30);

                if ((
                           (((buttons & A_BUTTON) != 0) && (((buttons & ~oldbuttons) & B_BUTTON) != 0))
                        || (((buttons & B_BUTTON) != 0) && (((buttons & ~oldbuttons) & A_BUTTON) != 0))
                        || ((player_joyGetButtons & A_BUTTON) && ((player_joyGetButtons & ~copy_prev_buttons_pressed) & B_BUTTON))
                        || ((player_joyGetButtons & B_BUTTON) && ((player_joyGetButtons & ~copy_prev_buttons_pressed) & A_BUTTON)))
                    && (getCurrentPlayerWeaponId(GUNRIGHT) == ITEM_REMOTEMINE))
                {
                    moveData.detonating = 1;
                    moveData.weaponBackOffset = 0;
                    moveData.weaponForwardOffset = 0;
                    moveData.btap = 0;
                }
                
                if (in_tank_flag == 1 && g_CurrentPlayer->insightaimmode)
                {
                    if (getCurrentPlayerWeaponId(GUNRIGHT) == ITEM_TANKSHELLS)
                    {
                        moveData.controlStickXRaw = 0;
                        
                        if (moveData.analogStrafe == 0)
                        {
                            moveData.analogStrafe = moveData.analogTurn;
                        }
                    }
                    else if (moveData.analogStrafe == 0)
                    {
                        if (moveData.aimTurnLeftSpeed > 0)
                        {
                            moveData.tankTurnLeftSpeed = moveData.aimTurnLeftSpeed;
                        }
                        
                        if (moveData.aimTurnRightSpeed > 0)
                        {
                            moveData.tankTurnRightSpeed = moveData.aimTurnRightSpeed;
                        }
                    }
                    
                    moveData.aimTurnLeftSpeed = 0;
                    moveData.aimTurnRightSpeed = 0;
                }
            }

            moveData.triggerOn = (sp10C)
                && (g_CurrentPlayer->watch_animation_state == 0)
                && ((buttons & A_BUTTON) == 0)
                && ((player_joyGetButtons & A_BUTTON) == 0);

            moveData.disableLookAhead = 1;
            g_CurrentPlayer->prev_buttons_pressed = player_joyGetButtons;
        }
        else
        {
            /* 1.3 and 1.4 */
            if (cur_player_get_control_type() == CONTROLLER_CONFIG_KISSY
                || cur_player_get_control_type() == CONTROLLER_CONFIG_GOODNIGHT)
            {
                shootButtons = A_BUTTON;
                aimButtons = Z_TRIG;
                invButtons = L_TRIG | R_TRIG;
            }
            else
            {
                shootButtons = Z_TRIG;
                aimButtons = L_TRIG | R_TRIG;
                invButtons = A_BUTTON;
            }

            if (lvlGetControlsLockedFlag() == 0)
            {
                if (disablePlayerActionsWhenPausedOrInMpMenu())
                {
                    if (cur_player_get_aim_control() == 0)
                    {
                        g_CurrentPlayer->insightaimmode = (buttons & aimButtons) != 0;
                    }
                    else if ((buttons & ~oldbuttons) & aimButtons)
                    {
                        g_CurrentPlayer->insightaimmode = !g_CurrentPlayer->insightaimmode;
                    }

                    moveData.canSwivelGun = !g_CurrentPlayer->insightaimmode;
                    moveData.canAutoAim = !g_CurrentPlayer->insightaimmode;
                    moveData.btap = ((buttons & ~oldbuttons) & B_BUTTON) != 0;
                    moveData.canManualAim = g_CurrentPlayer->insightaimmode;

                    /* 1.2 and 1.4 */
                    if (cur_player_get_control_type() == CONTROLLER_CONFIG_SOLITARE
                        || cur_player_get_control_type() == CONTROLLER_CONFIG_GOODNIGHT)
                    {
                        if ((buttons & (L_JPAD | L_CBUTTONS)) != 0)
                        {
                            if (!g_CurrentPlayer->insightaimmode)
                            {
                                if (in_tank_flag == 1)
                                {
                                    moveData.aimTurnLeftSpeed = 1.0f;
                                }
                                else
                                {
                                    moveData.digitalStepLeft = 1;
                                }
                            }
                            else
                            {
                                moveData.tankTurnLeftSpeed = 1.0f;
                            }
                        }
                        
                        if ((buttons & (R_JPAD | R_CBUTTONS)) != 0)
                        {
                            if (!g_CurrentPlayer->insightaimmode)
                            {
                                if (in_tank_flag == 1)
                                {
                                    moveData.aimTurnRightSpeed = 1.0f;
                                }
                                else
                                {
                                    moveData.digitalStepRight = 1;
                                }
                            }
                            else
                            {
                                moveData.tankTurnRightSpeed = 1.0f;
                            }
                        }

                        moveData.digitalStepForward = (!g_CurrentPlayer->insightaimmode)
                            && ((buttons & (U_JPAD | U_CBUTTONS)) );
                        
                        moveData.digitalStepBack = (!g_CurrentPlayer->insightaimmode)
                            && ((buttons & (D_JPAD | D_CBUTTONS)));

                        moveData.canNaturalPitch = !g_CurrentPlayer->insightaimmode;
                        
                        if (in_tank_flag == 1)
                        {
                            moveData.canTurnTank = !g_CurrentPlayer->insightaimmode;
                        }
                        else
                        {
                            moveData.canNaturalTurn = !g_CurrentPlayer->insightaimmode;
                        }
                    }
                    else
                    {
                        if ((buttons & (s32)(L_JPAD | L_CBUTTONS)) != 0)
                        {
                            moveData.tankTurnLeftSpeed = 1.0f;
                        }
                        /* optional else statement, matches with or without. */
                        else
                        {
                            moveData.tankTurnLeftSpeed = 0;
                        }
                        
                        if ((buttons & (s32)(R_JPAD | R_CBUTTONS)) != 0)
                        {
                            moveData.tankTurnRightSpeed = 1.0f;
                        }
                        /* optional else statement, matches with or without. */
                        else
                        {
                            moveData.tankTurnRightSpeed = 0;
                        }
                        
                        moveData.digitalStepLeft = (!g_CurrentPlayer->insightaimmode)
                            && ((buttons & (s32)(L_JPAD | L_CBUTTONS)) );
                        
                        moveData.digitalStepRight = (!g_CurrentPlayer->insightaimmode)
                            && ((buttons & (s32)(R_JPAD | R_CBUTTONS)));
                        
                        moveData.canLookAhead = !g_CurrentPlayer->insightaimmode;

                        if ((!g_CurrentPlayer->insightaimmode) && (buttons & (U_JPAD | U_CBUTTONS)) )
                        {
                            moveData.speedVertaDown = 1.0f;
                        }
                        
                        if ((!g_CurrentPlayer->insightaimmode) && (buttons & (D_JPAD | D_CBUTTONS)))
                        {
                            moveData.speedVertaUp = 1.0f;
                        }
                        
                        moveData.canNaturalTurn = !g_CurrentPlayer->insightaimmode;
                    }
                    
                    if ((g_CurrentPlayer->insightaimmode) && (stick_y > 60))
                    {
                        moveData.speedVertaDown = (f32) (stick_y - 60) / FLOAT_TEN_B;
                        if (moveData.speedVertaDown > 1.0f)
                        {
                            moveData.speedVertaDown = 1.0f;
                        }
                    }
                    else if ((g_CurrentPlayer->insightaimmode) && (stick_y < -60))
                    {
                        moveData.speedVertaUp = (f32) (-60 - stick_y) / FLOAT_TEN_B;
                        if (moveData.speedVertaUp > 1.0f)
                        {
                            moveData.speedVertaUp = 1.0f;
                        }
                    }
                    
                    if ((g_CurrentPlayer->insightaimmode) && (stick_x < -60))
                    {
                        moveData.aimTurnLeftSpeed = (f32) (-60 - stick_x) / FLOAT_TEN_B;
                        if (moveData.aimTurnLeftSpeed > 1.0f)
                        {
                            moveData.aimTurnLeftSpeed = 1.0f;
                        }
                    }
                    
                    if ((g_CurrentPlayer->insightaimmode) && (stick_x > 60))
                    {
                        moveData.aimTurnRightSpeed = (f32) (stick_x - 60) / FLOAT_TEN_B;
                        if (moveData.aimTurnRightSpeed > 1.0f)
                        {
                            moveData.aimTurnRightSpeed = 1.0f;
                        }
                    }

                    moveData.weaponBackOffset =
                        ((buttons & invButtons) != 0)
                        &&
                        (((buttons & ~oldbuttons) & shootButtons) != 0)
                        ;
                    
                    moveData.weaponForwardOffset = 
                        (((buttons & ~oldbuttons) & invButtons) != 0)
                        &&
                        ((buttons & shootButtons) == 0)
                        ;
                    
                    moveData.aiming = g_CurrentPlayer->insightaimmode;
                    moveData.zooming = g_CurrentPlayer->insightaimmode;

                    if ((bondwalkItemCheckBitflags(getCurrentPlayerWeaponId(GUNRIGHT), WEAPONSTATBITFLAG_DISABLE_CROUCH))
                        && g_CurrentPlayer->insightaimmode
                        )
                    {
                        /* down = 0x404 */
                        if ((buttons & (D_JPAD | D_CBUTTONS)) != 0)
                        {
                            moveData.zoomOutFovPersec = 1.0f;
                        }
                        
                        if ((buttons & (U_JPAD | U_CBUTTONS)) != 0)
                        {
                            moveData.zoomInFovPersec = 1.0f;
                        }
                    }
                    
                    moveData.crouchDown = (bondwalkItemCheckBitflags(getCurrentPlayerWeaponId(GUNRIGHT), WEAPONSTATBITFLAG_DISABLE_CROUCH) == 0)
                        && (g_CurrentPlayer->insightaimmode)
                        && ((buttons & (D_JPAD | D_CBUTTONS)));
                        
                    moveData.crouchUp = (bondwalkItemCheckBitflags(getCurrentPlayerWeaponId(GUNRIGHT), WEAPONSTATBITFLAG_DISABLE_CROUCH) == 0)
                        && (g_CurrentPlayer->insightaimmode)
                        && ((~buttons & (U_JPAD | U_CBUTTONS)));

                    moveData.rLeanLeft = (g_CurrentPlayer->insightaimmode)
                        && ((buttons & (L_JPAD | L_CBUTTONS)));

                    moveData.rLeanRight = (g_CurrentPlayer->insightaimmode)
                        && ((buttons & (R_JPAD | R_CBUTTONS)));

                    if (
                        ((((buttons & invButtons) != 0) && (((buttons & ~oldbuttons) & B_BUTTON) != 0)) 
                            || ((buttons & B_BUTTON) && (((buttons & ~oldbuttons) & invButtons) != 0)))
                        && (getCurrentPlayerWeaponId(GUNRIGHT) == ITEM_REMOTEMINE))
                    {
                        moveData.detonating = 1;
                        moveData.weaponBackOffset = 0;
                        moveData.weaponForwardOffset = 0;
                        moveData.btap = 0;
                    }

                    if ((in_tank_flag == 1) && (g_CurrentPlayer->insightaimmode))
                    {
                        if (getCurrentPlayerWeaponId(GUNRIGHT) == ITEM_TANKSHELLS)
                        {
                            moveData.controlStickXRaw = 0;
                            moveData.canTurnTank = 1;
                        }
                        else if ((moveData.tankTurnLeftSpeed == 0) && (moveData.tankTurnRightSpeed == 0))
                        {
                            if (moveData.aimTurnLeftSpeed > 0)
                            {
                                moveData.tankTurnLeftSpeed = moveData.aimTurnLeftSpeed;
                            }
                            
                            if (moveData.aimTurnRightSpeed > 0)
                            {
                                moveData.tankTurnRightSpeed = moveData.aimTurnRightSpeed;
                            }
                        }

                        moveData.aimTurnLeftSpeed = 0;
                        moveData.aimTurnRightSpeed = 0;
                    }
                }
            }

            moveData.triggerOn = ((buttons & shootButtons)  != 0)
                && (g_CurrentPlayer->watch_animation_state == 0)
                && ((buttons & invButtons) == 0);

            /* 1.2 and 1.4 */
            if (cur_player_get_control_type() == CONTROLLER_CONFIG_SOLITARE || cur_player_get_control_type() == CONTROLLER_CONFIG_GOODNIGHT)
            {
                moveData.disableLookAhead = 1;
            }
        }
    }

    g_CurrentPlayer->field_D0 = 0;

    if (moveData.btap)
    {
        /* If Bond is in the tank and pressed B, then exit. */
        if (in_tank_flag == 1)
        {
            spF4 = (struct TankRecord *)g_PlayerTankProp->obj;
            spF4->unkD8 = get_ammo_count_for_weapon(ITEM_TANKSHELLS);
            
            add_ammo_to_weapon(ITEM_TANKSHELLS, 0);
            bondinvRemoveItemByID(ITEM_TANKSHELLS);
            
            if (getCurrentPlayerWeaponId(GUNRIGHT) == ITEM_TANKSHELLS)
            {
                spF4->unkD8 += get_ammo_in_hands_magazine(GUNRIGHT);
                autoadvance_on_deplete_all_ammo();
            }
            
            spF4->is_firing_tank = 0;
            in_tank_flag = 0;
            g_CurrentPlayer->speedsideways = 0;
            g_CurrentPlayer->speedforwards = 0;
            g_CurrentPlayer->speedtheta = 0;

            for (i_0=0; i_0<3; i_0++)
            {
                g_CurrentPlayer->bondshotspeed.f[i_0] = 0;
            }
            
            g_CurrentPlayer->crouchpos = 2;
        }
        /* If Bond is standing on the tank and pressed B, enter the tank. */
        else if (g_PlayerTankProp != NULL
            && g_PlayerTankProp->type == PROP_TYPE_OBJ
            && g_PlayerTankProp->obj->type == PROPDEF_TANK
            && g_BondCanEnterTank)
        {
            spEC = (struct TankRecord *)g_PlayerTankProp->obj;
            
            bondinvAddInvItem(ITEM_TANKSHELLS);
            add_ammo_to_weapon(ITEM_TANKSHELLS, spEC->unkD8);
            spEC->unkD8 = 0;
            g_TankTurretVerticalAngle = spEC->turret_vertical_angle;
            g_TankTurretVerticalAngleRelated = g_TankTurretVerticalAngle / TANK_VERT_ANGLE_FACTOR;
            g_TankTurretAngle = spEC->turret_orientation_angle;
            g_TankTurretOrientationAngleRad = spEC->turret_orientation_angle;
            D_80036478 = g_TankTurretOrientationAngleRad / TANK_VERT_ANGLE_RAD_FACTOR;
            D_8003647C = 0;
            g_TankOrientationAngle = spEC->tank_orientation_angle;
            g_TankTurnSpeed = 0;
            in_tank_flag = 1;
            g_EnterTankAudioState = TANK_RUN_STATE_NOT_RUNNING;
            g_CurrentPlayer->speedsideways = 0;
            g_CurrentPlayer->speedforwards = 0;
            g_CurrentPlayer->speedtheta = 0;
            g_CurrentPlayer->crouchpos = 1;
            g_TankEnteringSitHeight = 0;
            g_TankEnteringSitHeightRemain = 1.0f;
            g_TankEnterBondHorizAngleDeg = g_CurrentPlayer->vv_theta;
            g_TankEnterBondVertAngleDeg = g_CurrentPlayer->vv_verta;
            g_EnterTankCoord.f[0] = g_CurrentPlayer->field_488.collision_position.f[0];
            g_EnterTankCoord.f[1] = g_CurrentPlayer->field_488.collision_position.f[1];
            g_EnterTankCoord.f[2] = g_CurrentPlayer->field_488.collision_position.f[2];
            g_TankDamagePenaltyTicks = 0;
            
            bondviewTankModelRotationRelated();
        }
        else
        {
            g_CurrentPlayer->field_D0 = 1;
        }
    }

    if (moveData.invertPitch == 0)
    {
        f32 ftemp_nostack_spE8;
        
        moveData.controlStickYRaw = (s32) -stick_y;
        moveData.analogPitch = -moveData.analogPitch;
        ftemp_nostack_spE8 = moveData.speedVertaDown;
        moveData.speedVertaDown = moveData.speedVertaUp;
        moveData.speedVertaUp = ftemp_nostack_spE8;
    }

    if (bondviewGetIfCurrentPlayerDamageShowTime() && getPlayerCount() == 1)
    {
        moveData.triggerOn = 0;
    }

    gunTickGameplay(moveData.triggerOn);

    if (bondviewGetVisibleToGuardsFlag()
        && (get_hands_firing_status(GUNRIGHT)
            || get_hands_firing_status(GUNLEFT)))
    {
        noiseRadius = 0;
        
        if (get_hands_firing_status(GUNRIGHT) && getCurrentPlayerNoise(GUNRIGHT) > noiseRadius)
        {
            noiseRadius = getCurrentPlayerNoise(GUNRIGHT);
        }
        
        if (get_hands_firing_status(GUNLEFT) && noiseRadius < getCurrentPlayerNoise(GUNLEFT))
        {
            noiseRadius = getCurrentPlayerNoise(GUNLEFT);
        }
        
        chrCheckGuardsHeardSound(noiseRadius);
    }

    gunSetSightVisible(GUNSIGHTREASON_NOTAIMING, moveData.aiming);
    
    if (moveData.zoomOutFovPersec > 0)
    {
        camera_sniper_zoom_out(moveData.zoomOutFovPersec);
    }
    
    if (moveData.zoomInFovPersec > 0)
    {
        camera_sniper_zoom_in(moveData.zoomInFovPersec);
    }

    if (g_CurrentPlayer->watch_animation_state == 0)
    {
        ftemp_nostack_spE0 = 60.0f;

        if (moveData.zooming)
        {
            ftemp_nostack_spE0 = get_item_in_hand_zoom();

            if (ftemp_nostack_spE0 <= 0)
            {
                ftemp_nostack_spE0 = 60.0f;
            }
        }
        
        bondviewTriggerWatchZoom(ftemp_nostack_spE0);
        bondviewUpdateWatchZoomIn();
    }
    
    if (in_tank_flag == 1)
    {
        g_TankTurretTurn = 0;

        if (g_EnterTankAudioState == TANK_RUN_STATE_RUNNING)
        {
            if (moveData.tankTurnRightSpeed > 0)
            {
                g_TankTurretTurn += g_GlobalTimerDelta * moveData.tankTurnRightSpeed * DegToRad1Fact(1);
            }
            else if (moveData.tankTurnLeftSpeed > 0)
            {
                g_TankTurretTurn -= g_GlobalTimerDelta * moveData.tankTurnLeftSpeed * DegToRad1Fact(1);
            }
            else if (moveData.canTurnTank)
            {
                targetSpeed = (f32) moveData.analogStrafe / 70.0f;
                
                if (targetSpeed > 1.0f)
                {
                    targetSpeed = 1.0f;
                }
                
                if (targetSpeed < -1.0f)
                {
                    targetSpeed = -1.0f;
                }
                
                g_TankTurretTurn += DegToRad1Fact(1) * targetSpeed * g_GlobalTimerDelta;
            }
            
            if (!g_CurrentPlayer->insightaimmode)
            {
                ftemp_nostack_spD8 = 0;
                targetSpeed = 1.0f;
                ftemp_nostack_spE8 = 1.0f;
                
                if (moveData.canLookAhead)
                {
                    ftemp_nostack_spD8 = (f32) moveData.analogWalk / 70.0f;
                }
                else if (moveData.digitalStepForward)
                {
                    ftemp_nostack_spD8 = 1.0f;
                }
                else if (moveData.digitalStepBack)
                {
                    ftemp_nostack_spD8 = -1.0f;
                }
                
                if (ftemp_nostack_spD8 > 1.0f)
                {
                    ftemp_nostack_spD8 = 1.0f;
                }
                else if (ftemp_nostack_spD8 < -1.0f)
                {
                    ftemp_nostack_spD8 = -1.0f;
                }
                
                unadjustedTargetSpeed = ftemp_nostack_spD8 * TANK_MAX_SPEED;
                targetSpeed = unadjustedTargetSpeed;

                if (g_TankDamagePenaltyTicks > 0)
                {
                    targetSpeed = unadjustedTargetSpeed * 0.5f;
                    ftemp_nostack_spE8 = 4.0f;
                    g_TankDamagePenaltyTicks -= g_ClockTimer;
                }

                if (targetSpeed != g_CurrentPlayer->speedforwards)
                {
                    if (g_CurrentPlayer->speedforwards < targetSpeed)
                    {
                        unadjustedTargetSpeed = ((((((targetSpeed - g_CurrentPlayer->speedforwards) / 4.0f) / TANK_MAX_SPEED) + 0.5f) * ftemp_nostack_spE8 * FLOAT_TEN_A) / 60.0f);

                        g_CurrentPlayer->speedforwards += (unadjustedTargetSpeed) * g_GlobalTimerDelta;
                        
                        if (targetSpeed < g_CurrentPlayer->speedforwards)
                        {
                            g_CurrentPlayer->speedforwards = targetSpeed;
                        }
                    }
                    else if (targetSpeed < g_CurrentPlayer->speedforwards)
                    {
                        unadjustedTargetSpeed = ((((((g_CurrentPlayer->speedforwards - targetSpeed) / 4.0f) / TANK_MAX_SPEED) + 0.5f) * ftemp_nostack_spE8 * -FLOAT_TEN_A) / 60.0f);

                        g_CurrentPlayer->speedforwards += (unadjustedTargetSpeed) * g_GlobalTimerDelta;
                        
                        if (g_CurrentPlayer->speedforwards < targetSpeed)
                        {
                            g_CurrentPlayer->speedforwards = targetSpeed;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (moveData.digitalStepLeft)
        {
            bondviewUpdateSpeedSideways(-1);
        }
        else if (moveData.digitalStepRight)
        {
            bondviewUpdateSpeedSideways(1);
        }
        else
        {
            bondviewUpdateSpeedSideways(0);
        }
        
        if (moveData.canTurnTank) // ?? not sure why this tank property is used here. Is the name wrong?
        {
            g_CurrentPlayer->speedsideways = (f32) moveData.analogStrafe / 70.0f;
        }
        
        if (moveData.digitalStepForward)
        {
            bondviewUpdateSpeedForwards(1);
            g_CurrentPlayer->speedmaxtime60 += g_ClockTimer;
        }
        else if (moveData.digitalStepBack)
        {
            bondviewUpdateSpeedForwards(-1);
        }
        else
        {
            bondviewUpdateSpeedForwards(0);
        }
        
        if (moveData.canLookAhead)
        {
            g_CurrentPlayer->speedforwards = (f32) moveData.analogWalk / 70.0f;
            
            if (moveData.analogWalk > 60)
            {
                g_CurrentPlayer->speedmaxtime60 += g_ClockTimer;
            }
            else
            {
                g_CurrentPlayer->speedmaxtime60 = 0;
            }
        }

        if (g_CurrentPlayer->speedforwards > 1.0f)
        {
            g_CurrentPlayer->speedforwards = 1;
        }
        
        if (g_CurrentPlayer->speedforwards < -1.0f)
        {
            g_CurrentPlayer->speedforwards = -1.0f;
        }

        if (g_CurrentPlayer->speedsideways > 1)
        {
            g_CurrentPlayer->speedsideways = 1;
        }
        
        if (g_CurrentPlayer->speedsideways < -1)
        {
            g_CurrentPlayer->speedsideways = -1;
        }
        
        g_CurrentPlayer->speedforwards *= 1.08f;
        g_CurrentPlayer->speedforwards *= g_CurrentPlayer->speedboost;
        
        if ((moveData.canLookAhead == 0) && (moveData.digitalStepForward == 0))
        {
            g_CurrentPlayer->speedmaxtime60 = 0;
        }
        
        if (moveData.rLeanLeft)
        {
            currentPlayerSetSwayTarget(-1);
        }
        else if (moveData.rLeanRight)
        {
            currentPlayerSetSwayTarget(1);
        }
        else
        {
            currentPlayerSetSwayTarget(0);
        }
        
        if (moveData.crouchDown)
        {
            currentPlayerAdjustCrouchPos(-2);
        }
        else if (moveData.crouchUp)
        {
            currentPlayerAdjustCrouchPos(2);
        }
    }

    if (g_CurrentPlayer->speedmaxtime60 >= THREE_SECOND_TICKS)
    {
        if (g_CurrentPlayer->speedboost < SPEED_RUN_MAX)
        {
            g_CurrentPlayer->speedboost += (SPEED_TICK_ADJUST * g_GlobalTimerDelta);
        }
        
        if (g_CurrentPlayer->speedboost > SPEED_RUN_MAX)
        {
            g_CurrentPlayer->speedboost = SPEED_RUN_MAX;
        }
    }
    else
    {
        if (g_CurrentPlayer->speedboost > SPEED_REGULAR_MAX)
        {
            g_CurrentPlayer->speedboost -= (SPEED_TICK_ADJUST * g_GlobalTimerDelta);
        }
        
        if (g_CurrentPlayer->speedboost < SPEED_REGULAR_MAX)
        {
            g_CurrentPlayer->speedboost = SPEED_REGULAR_MAX;
        }
    }

    if (g_CurrentPlayer->watch_animation_state == 0)
    {
        spC4 = -4.0f;
        
        if (g_CurrentPlayer->lookaheadcentreenabled)
        {
            spC0 = g_CurrentPlayer->field_488.current_tile_ptr;
            spBC = 300.0f;
            
            // prop, f32 *collision_radius, f32 *height, f32 *always_30
            bondviewGetCollisionRadius(g_CurrentPlayer->prop, &spA0.f[0], &spA0.f[2], &spA0.f[1]);
            
            spAC.f[0] = g_CurrentPlayer->field_488.collision_position.f[0] + (g_CurrentPlayer->field_488.theta_transform.f[0] * 300.0f);
            spAC.f[1] = g_CurrentPlayer->field_488.collision_position.f[1];
            spAC.f[2] = g_CurrentPlayer->field_488.collision_position.f[2] + (g_CurrentPlayer->field_488.theta_transform.f[2] * 300.0f);
           
            sub_GAME_7F0B1CC4();
            
            if (stanTestLineUnobstructed(&spC0, g_CurrentPlayer->field_488.collision_position.f[0], g_CurrentPlayer->field_488.collision_position.f[2], spAC.f[0], spAC.f[2], 0x1000, spA0.f[2], spA0.f[1], 0, 1.0f))
            {
                spAC.f[1] = bondviewYPositionRelated(spC0, spAC.f[0], spAC.f[2]);
            }
            else
            {
                chrlvStanPointPointIntersection(&g_CurrentPlayer->field_488.collision_position, &g_CurrentPlayer->field_488.theta_transform, (struct coord3d *) &spAC);
                ftemp_nostack_spD0 = spAC.f[0] - g_CurrentPlayer->field_488.collision_position.f[0];
                ftemp_nostack_spCC = spAC.f[2] - g_CurrentPlayer->field_488.collision_position.f[2];
                spBC = sqrtf((ftemp_nostack_spD0 * ftemp_nostack_spD0) + (ftemp_nostack_spCC * ftemp_nostack_spCC));
                spAC.f[1] = bondviewYPositionRelated(spC0, spAC.f[0], spAC.f[2]);
            }

            if (spBC > 0)
            {
                ftemp_nostack_spC8 = spAC.f[1] - g_CurrentPlayer->stanHeight;
                
                if ((ftemp_nostack_spC8 > -300.0f) && (ftemp_nostack_spC8 < 500.0f))
                {
                    spC4 = ((atan2f(ftemp_nostack_spC8, spBC) * 360.0f) / M_TAU_F) + -4.0f;

                    if (spC4 >= 180.0f)
                    {
                        spC4 -= 360.0f;
                    }

                    if (spC4 > 0)
                    {
                        spC4 *= 0.8666667f;
                    }
                }
            }
        }

        if ((g_CurrentPlayer->movecentrerelease) && (moveData.analogWalk < 40) && (moveData.analogWalk > -40))
        {
            g_CurrentPlayer->movecentrerelease = 0;
        }

        if (in_tank_flag == 0)
        {
            if ((moveData.speedVertaDown > 0) || (moveData.speedVertaUp > 0))
            {
                g_CurrentPlayer->field_104 = 0;
                g_CurrentPlayer->field_10C = 1;
                g_CurrentPlayer->automovecentre = 0;
            }
            else
            {
                if (moveData.disableLookAhead)
                {
                    g_CurrentPlayer->automovecentre = 0;
                }
                else if (g_CurrentPlayer->automovecentreenabled)
                {
                    if ((moveData.canLookAhead) && ((moveData.analogWalk > 60) || (moveData.analogWalk < -60)))
                    {
                        g_CurrentPlayer->automovecentre = 1;
                    }
                    
                    if ((
                        g_CurrentPlayer->automovecentre)
                        && (( ((spC4 + 5.0f) < g_CurrentPlayer->vv_verta)) || (g_CurrentPlayer->vv_verta < (spC4 + -FLOAT_TEN_A)))
                        && (g_CurrentPlayer->movecentrerelease == 0))
                    {
                        g_CurrentPlayer->field_104 = 1;
                    }
                }
                else if (
                    (g_CurrentPlayer->fastmovecentreenabled)
                    && (moveData.canLookAhead)
                    && (
                        (moveData.analogWalk > 60)
                        || (moveData.analogWalk < -60)
                    ) && (
                        ( ((spC4 + 5.0f) < g_CurrentPlayer->vv_verta)) || (g_CurrentPlayer->vv_verta < (spC4 + -FLOAT_TEN_A))
                    ) && (g_CurrentPlayer->movecentrerelease == 0))
                {
                    g_CurrentPlayer->field_104 = 1;
                }
                
                g_CurrentPlayer->field_10C = 0;
            }
        }

        if (g_CurrentPlayer->field_104)
        {
            if (in_tank_flag == 0)
            {
                ftemp_nostack_spB8 = (g_CurrentPlayer->speedverta * g_CurrentPlayer->speedverta * 0.5f) / 0.05f;
                
                if ((spC4 + ftemp_nostack_spB8) < g_CurrentPlayer->vv_verta)
                {
                    bondviewCurrentPlayerUpdateSpeedVerta(1.0f);
                }
                else if (g_CurrentPlayer->vv_verta < (spC4 - ftemp_nostack_spB8))
                {
                    bondviewCurrentPlayerUpdateSpeedVerta(-1.0f);
                }
                else
                {
                    bondviewCurrentPlayerUpdateSpeedVerta(0);
                }
                
                ftemp_nostack_spB8 = g_CurrentPlayer->vv_verta + (2.0f * (g_CurrentPlayer->speedverta * g_GlobalTimerDelta));
                
                if ((spC4 < g_CurrentPlayer->vv_verta) && (spC4 < ftemp_nostack_spB8))
                {
                    g_CurrentPlayer->vv_verta = ftemp_nostack_spB8;
                }
                else if ((g_CurrentPlayer->vv_verta < spC4) && (ftemp_nostack_spB8 < spC4))
                {
                    g_CurrentPlayer->vv_verta = ftemp_nostack_spB8;
                }
                else
                {
                    g_CurrentPlayer->vv_verta = spC4;
                    g_CurrentPlayer->speedverta = 0;
                    
                    if (g_CurrentPlayer->field_10C == 0)
                    {
                        g_CurrentPlayer->field_104 = 0;
                    }
                }
            }
        }
        else
        {
            if (moveData.canNaturalPitch)
            {
                ftemp_nostack_sp98 = viGetFovY() / 60.0f;
                ftemp_nostack_sp94 = (f32) moveData.analogPitch / 70.0f;
                
                if (ftemp_nostack_sp94 > 1)
                {
                    ftemp_nostack_sp94 = 1;
                }
                else if (ftemp_nostack_sp94 < -1)
                {
                    ftemp_nostack_sp94 = -1;
                }
                
                if (ftemp_nostack_sp94 >= 0)
                {
                    ftemp_nostack_sp94 *= ftemp_nostack_sp94;
                }
                else
                {
                    ftemp_nostack_sp94 *= -ftemp_nostack_sp94;
                }
                
                g_CurrentPlayer->speedverta = -ftemp_nostack_sp94 * ftemp_nostack_sp98;
            }
            else if (moveData.speedVertaDown > 0)
            {
                bondviewCurrentPlayerUpdateSpeedVerta(moveData.speedVertaDown);
                
                if ((moveData.canLookAhead) && ((moveData.analogWalk > 60) || (moveData.analogWalk < 60)))
                {
                    g_CurrentPlayer->movecentrerelease = 1;
                }
            }
            else if (moveData.speedVertaUp > 0)
            {
                bondviewCurrentPlayerUpdateSpeedVerta(-moveData.speedVertaUp);
                
                if ((moveData.canLookAhead) && ((moveData.analogWalk > 60) || (moveData.analogWalk < 60)))
                {
                    g_CurrentPlayer->movecentrerelease = 1;
                }
            }
            else
            {
                bondviewCurrentPlayerUpdateSpeedVerta(0);
            }
            
            g_CurrentPlayer->vv_verta += g_CurrentPlayer->speedverta * g_GlobalTimerDelta * 3.5f;
            
            if ((in_tank_flag == 1) && (g_EnterTankAudioState == TANK_RUN_STATE_RUNNING) && (g_CurrentPlayer->vv_verta < -20.0f))
            {
                g_CurrentPlayer->vv_verta = -20.0f;
            }
        }
    }

    if (moveData.canNaturalTurn)
    {
        ftemp_nostack_sp8C = viGetFovY();
        ftemp_nostack_sp84 = (f32) moveData.analogTurn / 70.0f;
        
        if (ftemp_nostack_sp84 > 1)
        {
            ftemp_nostack_sp84 = 1;
        }
        else if (ftemp_nostack_sp84 < -1)
        {
            ftemp_nostack_sp84 = -1;
        }
        
        if (ftemp_nostack_sp84 >= 0)
        {
            ftemp_nostack_sp84 *= ftemp_nostack_sp84;
        }
        else
        {
            ftemp_nostack_sp84 *= -ftemp_nostack_sp84;
        }

        ftemp_nostack_sp88 = (ftemp_nostack_sp8C / FOV_Y_F);
        g_CurrentPlayer->speedtheta = ftemp_nostack_sp84 * ftemp_nostack_sp88;
    }
    else if (moveData.aimTurnLeftSpeed > 0)
    {
        bondviewCurrentPlayerUpdateSpeedTheta(moveData.aimTurnLeftSpeed);
    }
    else if (moveData.aimTurnRightSpeed > 0)
    {
        bondviewCurrentPlayerUpdateSpeedTheta(-moveData.aimTurnRightSpeed);
    }
    else
    {
        bondviewCurrentPlayerUpdateSpeedTheta(0);
    }

    if (in_tank_flag == 1)
    {
        if (g_EnterTankAudioState == TANK_RUN_STATE_RUNNING)
        {
            ftemp_nostack_sp80 = 0;

            if (moveData.canNaturalTurn)
            {
                ftemp_nostack_sp80 = g_CurrentPlayer->speedtheta * 0.3f;
            }
            else if (moveData.aimTurnLeftSpeed > 0)
            {
                ftemp_nostack_sp80 = sub_GAME_7F080228(1) * 0.3f;
            }
            else if (moveData.aimTurnRightSpeed > 0)
            {
                ftemp_nostack_sp80 = sub_GAME_7F080228(-1) * 0.3f;
            }

            for (i_1=0; i_1<g_ClockTimer; i_1++)
            {
                g_TankTurnSpeed = (TANKUPDATEROTATION_SCALE * g_TankTurnSpeed) + ftemp_nostack_sp80;
            }

            g_CurrentPlayer->speedtheta = g_TankTurnSpeed * TANK_VERT_ANGLE_RAD_FACTOR;
        }
        else
        {
            g_CurrentPlayer->speedtheta = 0;
        }
    }

    if (moveData.detonating)
    {
        g_CurrentPlayer->hands[GUNRIGHT].when_detonating_mines_is_0 = 0;
        g_CurrentPlayer->hands[GUNRIGHT].weapon_current_animation = 0;
        trigger_remote_mine_detonation();
    }

    canCycleWeapons = 1;
    
    if ((getPlayerCount() >= 2) && (get_scenario() == 2) && (bondinvIsAliveWithFlag()))
    {
        canCycleWeapons = 0;
    }

    if (canCycleWeapons)
    {
        if (moveData.weaponBackOffset)
        {
            backstep_through_inventory();
        }

        if (moveData.weaponForwardOffset)
        {
            advance_through_inventory();
        }
    }

    if (moveData.canSwivelGun)
    {
        g_CurrentPlayer->controldef = 0;
    }
    else if (moveData.canManualAim)
    {
        g_CurrentPlayer->controldef = 2;
    }

    if (g_CurrentPlayer->controldef == 0)
    {
        gunSetAimType(0);
        
        if (moveData.canAutoAim
            && redirect_get_BONDdata_autoaim_x()
            && g_CurrentPlayer->autoaim_target_x
            && bondwalkItemCheckBitflags(getCurrentPlayerWeaponId(GUNRIGHT), WEAPONSTATBITFLAG_HAS_AUTO_AIM))
        {
            sp70 = g_CurrentPlayer->autoaimx;
        }
        else
        {
            sp70 = g_CurrentPlayer->speedtheta * 0.3f;
        }

        if (moveData.canAutoAim
            && redirect_get_BONDdata_autoaim_y()
            && g_CurrentPlayer->autoaim_target_y
            && bondwalkItemCheckBitflags(getCurrentPlayerWeaponId(GUNRIGHT), WEAPONSTATBITFLAG_HAS_AUTO_AIM))
        {
            ftemp_nostack_sp78 = g_CurrentPlayer->autoaimy;
        }
        else
        {
            ftemp_nostack_sp78 = -g_CurrentPlayer->speedverta * 0.1f;
        }

        sub_GAME_7F067F58(sp70, ftemp_nostack_sp78, MAX_AIMLOCK_SPEED_DEFAULT);
    }
    else if (g_CurrentPlayer->controldef == 2)
    {
        gunSetAimType(0);
        sub_GAME_7F067FBC(((f32) moveData.controlStickXRaw * 0.65f) / 80.0f, ((f32) moveData.controlStickYRaw * 0.65f) / 80.0f);
    }
}




/**
 * Perfect Dark playerTickDamageAndHealth
 * 
 * NTSC address 7F083FC8.
 * NTSC-J address 7F0845D8.
 * EU address 7F08406C.
*/
void bondviewPlayerTickDamageAndHealth(void)
{
    // update damage showtime
    if (g_CurrentPlayer->damageshowtime >= 0)
    {
        // 0: This is the first frame of damage
        if (g_CurrentPlayer->damageshowtime == 0)
        {
            gunSetGunAmmoVisible(GUNAMMOREASON_DAMAGE, FALSE);
            gunSetSightVisible(GUNSIGHTREASON_DAMAGE, FALSE);
            hudmsgsSetOff(4);
            bondviewSetUpperTextDisplayFlag(PLAYERFLAG_NOTIMER);
            countdownTimerSetVisible(8, 0);

            g_CurrentPlayer->damagetype = (s32)(bondviewGetCurrentPlayerHealth() * 8.0f);
            
            if (g_CurrentPlayer->damagetype >= 8)
            {
                g_CurrentPlayer->damagetype = 7;
            }

#if defined(VERSION_EU) || defined(VERSION_JP)
            if (g_CurrentPlayer->damagetype < 0)
            {
                g_CurrentPlayer->damagetype = 0;
            }
#endif
        }

#ifdef VERSION_US
        if (
            (g_DamageTypes[g_CurrentPlayer->damagetype].field_0x8 >= g_CurrentPlayer->damageshowtime) 
            || (g_DamageTypes[g_CurrentPlayer->damagetype].flashEndFrame >= g_CurrentPlayer->damageshowtime))
        {
            if (!g_CurrentPlayer->bonddead)
            {
#else
        if (!g_CurrentPlayer->bonddead
            && (
                (g_DamageTypes[g_CurrentPlayer->damagetype].field_0x8 >= g_CurrentPlayer->damageshowtime) 
                || (g_DamageTypes[g_CurrentPlayer->damagetype].flashEndFrame >= g_CurrentPlayer->damageshowtime)))
        {
#endif
            if (g_CurrentPlayer->damageshowtime >= g_DamageTypes[g_CurrentPlayer->damagetype].flashStartFrame
                && g_CurrentPlayer->damageshowtime <= g_DamageTypes[g_CurrentPlayer->damagetype].flashEndFrame)
            {
                f32 frac;
#ifdef VERSION_US
                s32 flashdoneframes;
                s32 totalframes;
                s32 flashfullframe;
#else
                f32 flashdoneframes;
                f32 totalframes;
                f32 flashfullframe;
#endif
                
                flashdoneframes = g_CurrentPlayer->damageshowtime - g_DamageTypes[g_CurrentPlayer->damagetype].flashStartFrame;
                flashfullframe = g_DamageTypes[g_CurrentPlayer->damagetype].flashFullFrame;
                totalframes = g_DamageTypes[g_CurrentPlayer->damagetype].flashEndFrame - g_DamageTypes[g_CurrentPlayer->damagetype].flashStartFrame;

                if (flashdoneframes < flashfullframe)
                {
                    frac = (g_DamageTypes[g_CurrentPlayer->damagetype].maxAlpha * (f32)flashdoneframes) / (f32)flashfullframe;
                }
                else
                {
                    frac = (g_DamageTypes[g_CurrentPlayer->damagetype].maxAlpha * (f32)(totalframes - flashdoneframes)) / (f32)(totalframes - flashfullframe);
                }

                currentPlayerSetFadeColour(
                    g_DamageTypes[g_CurrentPlayer->damagetype].red,
                    g_DamageTypes[g_CurrentPlayer->damagetype].green,
                    g_DamageTypes[g_CurrentPlayer->damagetype].blue,
                    frac);
            }
#ifdef VERSION_US
            }
#endif

            if (g_CurrentPlayer->watch_animation_state == 0)
            {
#if defined(VERSION_US)
                g_CurrentPlayer->damageshowtime += g_ClockTimer;
#else
                g_CurrentPlayer->damageshowtime += g_GlobalTimerDelta;
#endif
            }
            else
            {
#if defined(VERSION_US)
                g_CurrentPlayer->damageshowtime += speedgraphframes;
#else
                g_CurrentPlayer->damageshowtime += jpD_800484D0;
#endif
            }
        }
        else /* (damage showtime is over) */
        {
            g_CurrentPlayer->damageshowtime = -1;
            currentPlayerSetFadeColour(0xFF, 0xFF, 0xFF, 0);
            
            if (!g_CurrentPlayer->bonddead)
            {
                gunSetGunAmmoVisible(GUNAMMOREASON_DAMAGE, TRUE);
                gunSetSightVisible(GUNSIGHTREASON_DAMAGE, TRUE);
                hudmsgsSetOn(4);
                bondviewClearUpperTextDisplayFlag(PLAYERFLAG_NOTIMER);
                countdownTimerSetVisible(8, 1);
            }
        }
    }

    // update health showtime
    if (g_CurrentPlayer->healthshowtime >= 0)
    {
        // 0: This is the first frame of damage
        if (g_CurrentPlayer->healthshowtime == 0)
        {
            g_CurrentPlayer->healthDamageType = (s32)(bondviewGetCurrentPlayerHealth() * 8.0f);
            
            if (g_CurrentPlayer->healthDamageType >= 8)
            {
                g_CurrentPlayer->healthDamageType = 7;
            }

#if defined(VERSION_EU) || defined(VERSION_JP)
            if (g_CurrentPlayer->healthDamageType < 0)
            {
                g_CurrentPlayer->healthDamageType = 0;
            }
#endif
        }

        if (!g_CurrentPlayer->bonddead)
        {
            if ((g_CurrentPlayer->healthshowtime >= g_HealthDamageTypes[g_CurrentPlayer->healthDamageType].updateStartFrame) 
                && (g_HealthDamageTypes[g_CurrentPlayer->healthDamageType].updateEndFrame >= g_CurrentPlayer->healthshowtime))
            {
                g_CurrentPlayer->apparenthealth = g_CurrentPlayer->oldhealth;
                g_CurrentPlayer->apparentarmour = g_CurrentPlayer->oldarmour;
#if defined(VERSION_US)
                g_CurrentPlayer->healthshowtime += g_ClockTimer;
#else
                g_CurrentPlayer->healthshowtime += g_GlobalTimerDelta;
#endif
            }
            else if ((g_CurrentPlayer->healthshowtime >= g_HealthDamageTypes[g_CurrentPlayer->healthDamageType].updateStartFrame)
                && (g_HealthDamageTypes[g_CurrentPlayer->healthDamageType].otherEndFrame >= g_CurrentPlayer->healthshowtime))
            {
                g_CurrentPlayer->apparenthealth = g_CurrentPlayer->bondhealth;
                g_CurrentPlayer->apparentarmour = g_CurrentPlayer->bondarmour;
#if defined(VERSION_US)
                g_CurrentPlayer->healthshowtime += g_ClockTimer;
#else
                g_CurrentPlayer->healthshowtime += g_GlobalTimerDelta;
#endif
            }
            else
            {
                g_CurrentPlayer->healthshowtime = -1;                
            }
        }
        else
        {
            g_CurrentPlayer->healthshowtime = -1;
        }
    }
}

/**
 * If global flag g_SurroundBondWithExplosionsFlag is set then explosions
 * will be randomly created around Bond.
 * Perfect Dark method playerTickExplode.
 * NTSC address 7F084360.
 * EU address 7F0844A4.
*/
void bondviewPlayerTickExplode(void)
{
    g_PlayerTickExplodeCreatePosition++;

    if (g_SurroundBondWithExplosionsFlag
        && g_PlayerInvincible == 0
        && g_SurroundBondWithExplosionsTicks < g_GlobalTimer)
    {
        struct coord3d pos;

        pos.f[0] = g_CurrentPlayer->prop->pos.f[0];
        pos.f[1] = g_CurrentPlayer->prop->pos.f[1];
        pos.f[2] = g_CurrentPlayer->prop->pos.f[2];

        switch (g_PlayerTickExplodeCreatePosition % 4)
        {
            case 0: pos.x += 250.0f + 150.0f * RANDOMGETNEXT_F32(); break;
    		case 1: pos.x -= 250.0f + 150.0f * RANDOMGETNEXT_F32(); break;
    		case 2: pos.z += 250.0f + 150.0f * RANDOMGETNEXT_F32(); break;
    		case 3: pos.z -= 250.0f + 150.0f * RANDOMGETNEXT_F32(); break;
        }

        pos.y += 200.0f * RANDOMGETNEXT_F32() - 100.0f;

        explosionCreate(0, &pos, g_CurrentPlayer->prop->stan, EXPLOSION_DEF_PLAYER, 0, 0, g_CurrentPlayer->prop->rooms, 0);

        g_SurroundBondWithExplosionsTicks = (randomGetNext() % (u32)PLAYER_TICKEXPLODE_FACTOR) + g_GlobalTimer + PLAYER_TICKEXPLODE_FACTOR;
    }
}


/**
 * NTSC Address 0x7F084648.
 * NTSC-J address 0x7F084CF8.
 * 
 * Met by Saint Jon The Archangel in the writhing pits of hell, the beast was
 * pinned, prone on the floor. He had taken many forms throughout the ages.
 * From the creator of man to the far reaches of the universe, his perpetual
 * reincarnations reigned throughout space and time... until now. His form was
 * weak, the opposition strong. The time for atonement had finally come.
 * 
 * Battered, torn, exposed, the beast slacked his gaping maw.
 * 
 * "I'm sorry, Jon" he whispered.
 * 
 * The archangel raised his flaming blade.
 * 
 * "You are forgiven, Garfield"
 * 
 * And the beast exhaled his last.
 * 
 * 10 months of off and on work to match.
 * Thanks Trevor.
 * - Ben Burns
 */
void MoveBond(s8 stick_x, s8 stick_y, u16 buttons, u16 oldbuttons)
{
    struct coord3d move_offset;
    f32 ftemp;
    f32 stack_padding_9;
    f32 sp3A0;
    s32 i;
    f32 maxspeed;
    s32 use_stanHeight;
    f32 sp390;

    move_offset = g_DefaultMoveBondOffset;

    use_stanHeight = 0;
    maxspeed = 0.0f;
    sp390 = 0.0f;

    #if defined(VERSION_US) || defined(VERSION_JP)
    if (stick_x >= 100 || stick_x <= -100) return_null(); // __LINE__ __FILE__ (#6414 bondview.c) "joystick x has value %d!\n"
    if (stick_y >= 100 || stick_y <= -100) return_null(); // __LINE__ __FILE__ (#6415 bondview.c) "joystick y has value %d!\n"
    #endif

    if (g_bondviewForceDisarm > 0)
    {
        g_bondviewForceDisarm++;
        if (g_bondviewForceDisarm >= 4)
        {
            g_bondviewForceDisarm = 0;
            g_CurrentPlayer->lock_hand_model[GUNLEFT] = 0;
            g_CurrentPlayer->lock_hand_model[GUNRIGHT] = 0;
            currentPlayerUnEquipWeaponWrapper(GUNLEFT, getCurrentPlayerWeaponId(GUNLEFT));
            currentPlayerUnEquipWeaponWrapper(GUNRIGHT, getCurrentPlayerWeaponId(GUNRIGHT));
        }
    }

    currentPlayerSetField00(0);
    bondviewPlayerTickDamageAndHealth();
    bondviewPlayerTickExplode();
    bondviewProcessInput(stick_x, stick_y, buttons, oldbuttons);

    if (lvlGetControlsLockedFlag())
    {
        bondviewPlayerStopAudioForPause();
    }

    if (g_CurrentPlayer->watch_animation_state)
    {
        bondviewWatchAnimationTick();
    }

    /*
        Apply bondshotspeed vector to speedforwards scalar and speedsideways scalar.
        Crouching applies a 50% base speed reduction before applying boost.
        Bond can't be boosted while in the tank.
    */
    if (in_tank_flag == 0)
    {
        // This `if` block is Perfect Dark bwalkApplyCrouchSpeed.
        if (currentPlayerGetCrouchPos() == CROUCH_SQUAT)
        {
            g_CurrentPlayer->speedforwards *= 0.5f;
            g_CurrentPlayer->speedsideways *= 0.5f;
        }

        if ((g_CurrentPlayer->bondshotspeed.f[0] != 0.0f) || (g_CurrentPlayer->bondshotspeed.f[2] != 0.0f))
        {
            // boost forwards
            f32 shotboost_forward; // sp38C
            // boost sideways
            f32 shotboost_sideways; // sp388
            f32 shotboost_norm; // sp384
            
            // Assigning these two variables is done in Perfect Dark bmove0f0cba88.
            shotboost_forward = 
                (-g_CurrentPlayer->bondshotspeed.f[0] * g_CurrentPlayer->vv_sintheta)
                + (g_CurrentPlayer->bondshotspeed.f[2] * g_CurrentPlayer->vv_costheta);
            shotboost_sideways = 
                (-g_CurrentPlayer->bondshotspeed.f[0] * g_CurrentPlayer->vv_costheta)
                - (g_CurrentPlayer->bondshotspeed.f[2] * g_CurrentPlayer->vv_sintheta);

            shotboost_norm = sqrtf(
                (g_CurrentPlayer->bondshotspeed.f[0] * g_CurrentPlayer->bondshotspeed.f[0]) +
                (g_CurrentPlayer->bondshotspeed.f[2] * g_CurrentPlayer->bondshotspeed.f[2]));

            g_CurrentPlayer->speedforwards += shotboost_forward;
            g_CurrentPlayer->speedsideways += shotboost_sideways;

            // 3: x,y,z components of bondshotspeed
            for (i=0; i<3; i++)
            {
                if (g_CurrentPlayer->bondshotspeed.f[i] != 0.0f)
                {
                    if (g_CurrentPlayer->bondshotspeed.f[i] > 0.0f)
                    {
                        g_CurrentPlayer->bondshotspeed.f[i] -=
                            ((0.06666667f * g_GlobalTimerDelta * g_CurrentPlayer->bondshotspeed.f[i]) / shotboost_norm);
                        
                        if (g_CurrentPlayer->bondshotspeed.f[i] < 0.0f)
                        {
                            g_CurrentPlayer->bondshotspeed.f[i] = 0.0f;
                        }
                    }
                    else if (g_CurrentPlayer->bondshotspeed.f[i] < 0.0f)
                    {
                        g_CurrentPlayer->bondshotspeed.f[i] -=
                            ((0.06666667f * g_GlobalTimerDelta * g_CurrentPlayer->bondshotspeed.f[i]) / shotboost_norm);
                        
                        if (g_CurrentPlayer->bondshotspeed.f[i] > 0.0f)
                        {
                            g_CurrentPlayer->bondshotspeed.f[i] = 0.0f;
                        }
                    }
                }
            }
        }
    }

    /**
     * This section updates the tank turret horizontal position (turning left and right),
     * as well as turning the tank left and right.
    */
    if (in_tank_flag == 1)
    {
        f32 ftemp2;
        struct coord3d check_collision_p1;
        struct coord3d check_collision_p2;
        f32 stack_padding_1;
        s32 i_1;
        f32 curTankAngleRad;
        f32 tankChangeInAngle;
        f32 sp354;
        struct coord3d tank_collision_pt1;
        struct coord3d tank_collision_pt2;
        f32 tank_collision_dx;
        f32 tank_collision_dz;
        
        tankChangeInAngle = DegToRad1Fact(g_CurrentPlayer->speedtheta * g_GlobalTimerDelta) * 3.5f;
        curTankAngleRad = g_TankOrientationAngle + tankChangeInAngle;
        
        if (curTankAngleRad >= M_TAU_F)
        {
            curTankAngleRad -= M_TAU_F;
        }
        
        if (curTankAngleRad < 0.0f)
        {
            curTankAngleRad += M_TAU_F;
        }

        if (bondviewTankCollisionStatus(
            &g_CurrentPlayer->field_488.collision_position,
            g_CurrentPlayer->field_488.current_tile_ptr,
            curTankAngleRad,
            &check_collision_p1,
            &check_collision_p2))
        {
            g_TankOrientationAngle = curTankAngleRad;
        }
        else
        {
            f32 sp1E4; //x
            s32 stack_padding_1; //x
            f32 sp1FC; //x
            f32 sp324;
            f32 sp320;
            f32 sp31C;
            f32 sp20C; //x
            f32 tank_collision_norm; //x
            f32 sp210; //x
            f32 sp30C;
            f32 sp308;
            f32 sp304;
            
            sp31C = -1; //sp31C: scope within this block, used throughout
            sp304 = -1; //sp304: scope within this block, used throughout

            getCollisionEdge_maybe(&tank_collision_pt1, &tank_collision_pt2);
            
            tank_collision_dx = (tank_collision_pt2.f[0] - tank_collision_pt1.f[0]);
            tank_collision_dz = (tank_collision_pt2.f[2] - tank_collision_pt1.f[2]);

            tank_collision_norm = 1.0f / sqrtf((tank_collision_dx * tank_collision_dx) + (tank_collision_dz * tank_collision_dz));

            // sp320: scoped within this block, used throughout
            // sp324: scoped within this block, used throughout
            tank_collision_dx *= tank_collision_norm;
            tank_collision_dz *= tank_collision_norm;
            sp324 = tank_collision_dz;
            sp320 = -tank_collision_dx;

            // sp210: short lived variable
            sp210 =
                ((g_CurrentPlayer->field_488.collision_position.f[0] - check_collision_p2.f[0]) * sp324) +
                ((g_CurrentPlayer->field_488.collision_position.f[2] - check_collision_p2.f[2]) * sp320);
            
            if (sp210 < 0.0f)
            {
                sp210 = -sp210;
                sp324 = -sp324;
                sp320 = -sp320;
            }

            // sp20C: very short lived variable
            sp20C = 
                ((g_CurrentPlayer->field_488.collision_position.f[0] - tank_collision_pt1.f[0]) * sp324) +
                ((g_CurrentPlayer->field_488.collision_position.f[2] - tank_collision_pt1.f[2]) * sp320);

            if (sp20C < sp210)
            {
                sp31C = sp210 - sp20C;
            }
            
            tank_collision_dx = check_collision_p2.f[0] - check_collision_p1.f[0];
            tank_collision_dz = check_collision_p2.f[2] - check_collision_p1.f[2];

            tank_collision_norm = 1.0f / sqrtf((tank_collision_dx * tank_collision_dx) + (tank_collision_dz * tank_collision_dz));

            // sp308: scoped within this block, used throughout
            // sp30C: scoped within this block, used throughout
            tank_collision_dx *= tank_collision_norm;
            tank_collision_dz *= tank_collision_norm;
            sp30C = tank_collision_dz;
            sp308 = -tank_collision_dx;

            // sp1F8 -> sp210: short lived variable
            sp210 = 
                ((g_CurrentPlayer->field_488.collision_position.f[0] - check_collision_p2.f[0]) * sp30C) +
                ((g_CurrentPlayer->field_488.collision_position.f[2] - check_collision_p2.f[2]) * sp308);

            if (sp210 < 0.0f)
            {
                sp210 = -sp210;
                sp30C = -sp30C;
                sp308 = -sp308;
            }

            // sp1FC: very short lived variable
            // sp1E4: very short lived variable
            sp1FC =
                ((g_CurrentPlayer->field_488.collision_position.f[0] - tank_collision_pt1.f[0]) * sp30C) +
                ((g_CurrentPlayer->field_488.collision_position.f[2] - tank_collision_pt1.f[2]) * sp308);
            sp1E4 =
                ((g_CurrentPlayer->field_488.collision_position.f[0] - tank_collision_pt2.f[0]) * sp30C) +
                ((g_CurrentPlayer->field_488.collision_position.f[2] - tank_collision_pt2.f[2]) * sp308);
        
            if (sp1E4 < sp1FC)
            {
                sp1FC = sp1E4;
            }

            if (sp1FC < sp210)
            {
                sp304 = sp210 - sp1FC;
            }
     
            if ((sp304 >= 0.0f) && ((sp304 < sp31C) || (sp31C < 0.0f)))
            {
                sp324 = sp30C;
                sp320 = sp308;
                sp31C = sp304;
            }
            
            if (sp31C >= 0.0f)
            {
                move_offset.f[0] = sp31C * sp324 * 1.01f;
                move_offset.f[2] = sp31C * sp320 * 1.01f;
                
                bondviewCalcUpdatePlayerCollision(&move_offset, 1);
                
                move_offset.f[0] = 0.0f;
                move_offset.f[2] = 0.0f;

                if (bondviewTankCollisionStatus(
                    &g_CurrentPlayer->field_488.collision_position,
                    g_CurrentPlayer->field_488.current_tile_ptr,
                    curTankAngleRad,
                    &check_collision_p1,
                    &check_collision_p2))
                {
                    g_TankOrientationAngle = curTankAngleRad;
                }
                else
                {
                    tankChangeInAngle = 0.0f;
                }
            }
            else
            {
                tankChangeInAngle = 0.0f;
            }
        }

        sp354 = g_TankTurretOrientationAngleRad;
        g_TankTurretAngle += g_TankTurretTurn;
        if (g_TankTurretAngle >= M_TAU_F)
        {
            g_TankTurretAngle -= M_TAU_F;
        }

        if (g_TankTurretAngle < 0.0f)
        {
            g_TankTurretAngle += M_TAU_F;
        }

        ftemp = (DegToRad1Fact(g_CurrentPlayer->speedtheta * 3.5f) * 4.0f) + g_TankTurretAngle;
       
        if (ftemp < 0.0f)
        {
            ftemp += M_TAU_F;
        }
        
        if (ftemp >= M_TAU_F)
        {
            ftemp -= M_TAU_F;
        }

        if ((ftemp - g_TankTurretOrientationAngleRad) >= M_PI_F)
        {
            ftemp -= M_TAU_F;
        }
        else if ((ftemp - g_TankTurretOrientationAngleRad) < -M_PI_F)
        {
            ftemp += M_TAU_F;
        }

        for (i_1=0; i_1<g_ClockTimer; i_1++)
        {
            D_80036478 = ((TANKUPDATEROTATION_SCALE) * D_80036478) + ftemp;
        }

        g_TankTurretOrientationAngleRad = D_80036478 * (1.0f - TANKUPDATEROTATION_SCALE);

        if (g_TankTurretOrientationAngleRad >= M_TAU_F)
        {
            g_TankTurretOrientationAngleRad -= M_TAU_F;
            D_80036478 = g_TankTurretOrientationAngleRad / (1.0f - TANKUPDATEROTATION_SCALE);
        }
        
        if (g_TankTurretOrientationAngleRad < 0.0f)
        {
            g_TankTurretOrientationAngleRad += M_TAU_F;
            D_80036478 = g_TankTurretOrientationAngleRad / (1.0f - TANKUPDATEROTATION_SCALE);
        }
        
        if (bondviewCallTankCollisionStatus(
            &g_CurrentPlayer->field_488.collision_position,
            g_CurrentPlayer->field_488.current_tile_ptr,
            g_TankOrientationAngle) == 0)
        {
            g_TankTurretOrientationAngleRad = sp354;
            D_80036478 = g_TankTurretOrientationAngleRad / (1.0f - TANKUPDATEROTATION_SCALE);
            g_TankTurretAngle = sp354;
        }

        if (g_PlayerTankProp != NULL)
        {
            // sp 0x300
            struct TankRecord *temp_tank;
            struct coord3d tank_move_offset;
            Mtxf sp2B4;
            f32 stack_padding_4;
            
            temp_tank = (struct TankRecord *)g_PlayerTankProp->obj;
            
            tank_move_offset.f[1] = 0.0f;
            tank_move_offset.f[0] = g_TankModelPositionOffset.f[0];
            tank_move_offset.f[2] = g_TankModelPositionOffset.f[2];

            matrix_4x4_set_rotation_around_y(tankChangeInAngle, &sp2B4);
            mtx4RotateVecInPlace(&sp2B4, &tank_move_offset);
            bondviewTankModelRotationRelated();
            
            if (0) { }
            
            tank_move_offset.f[1] = 0.0f;
            tank_move_offset.f[0] = g_TankModelPositionOffset.f[0] - tank_move_offset.f[0];
            tank_move_offset.f[2] = g_TankModelPositionOffset.f[2] - tank_move_offset.f[2];

            matrix_4x4_set_rotation_around_y(M_TAU_F - g_TankOrientationAngle, &sp2B4);
            matrix_scalar_multiply(temp_tank->model->scale, &sp2B4);
            mtx4RotateVecInPlace(&sp2B4, &tank_move_offset);
            bondviewCalcUpdatePlayerCollision(&tank_move_offset, 1);
        }

        if (g_ClockTimer > 0) {
            for (i=0; i<g_ClockTimer; i++)
            {
                D_8003647C = (TANKUPDATEROTATION_SCALE * D_8003647C) + (g_TankTurretTurn / g_GlobalTimerDelta);
            }
        }

        ftemp = D_8003647C * (1.0f - TANKUPDATEROTATION_SCALE);

        g_CurrentPlayer->vv_theta = (
            g_TankOrientationAngle +
            g_TankTurretOrientationAngleRad +
            ((DegToRad1Fact(g_CurrentPlayer->speedtheta * 3.5f)) * (4.0f)) +
            (ftemp * 4.0f)
            ) * 360.0f / M_TAU_F;

        while (g_CurrentPlayer->vv_theta < 0.0f)
        {
            g_CurrentPlayer->vv_theta += 360.0f;
        }
        while (g_CurrentPlayer->vv_theta >= 360.0f)
        {
            g_CurrentPlayer->vv_theta -= 360.0f;
        }
    }
    else
    {
        stack_padding_9 = g_CurrentPlayer->vv_theta + (g_CurrentPlayer->speedtheta * g_GlobalTimerDelta * 3.5f);

        while (stack_padding_9 < 0.0f)
        {
            stack_padding_9 += 360.0f;
        }
        while (stack_padding_9 >= 360.0f)
        {
            stack_padding_9 -= 360.0f;
        }

        g_CurrentPlayer->vv_theta = stack_padding_9;
    }

    bondviewApplyVertaTheta();

    // Handle crouching, and animation between standing and crouching.
    // Add basic block to declare local variables at the correct stack position.
    {
        f32 sp2AC;
        f32 stack_padding_15;
        
        sp2AC = 0.0f;
        if (currentPlayerGetCrouchPos() == CROUCH_SQUAT)
        {
            sp2AC = FULL_CROUCH_OFFSET;
        }
        else if (currentPlayerGetCrouchPos() == CROUCH_HALF)
        {
            sp2AC = -60.0f;
        }
        else
        {
            // removed?
            currentPlayerGetCrouchPos();
        }

        if (sp2AC != g_CurrentPlayer->ducking_height_offset)
        {
            chrobjApplySpeed(
                &g_CurrentPlayer->ducking_height_offset,
                sp2AC,
                &g_CurrentPlayer->field_A4,
                CHR_OBJ_ACCEL_SPEED_FACTOR,
                CHR_OBJ_ACCEL_SPEED_FACTOR,
                CHR_OBJ_MAXSPEED);
        }
    
        if (sp2AC == g_CurrentPlayer->ducking_height_offset)
        {
            g_CurrentPlayer->field_A4 = 0.0f;
        }
    }

    /**
     * Update forwards/backwards movement.
    */
    if (in_tank_flag == 1)
    {
        /**
         * This section handles the forward/backwards movement of the tank.
        */

        Mtxf sp268;
        struct coord3d sp25C;
        f32 sp258;
        f32 sp254;
        s32 stack_padding_14;
        s32 i_3;
        f32 ftemp_5;
        f32 tank_engine_utilization_percent;
        struct TankRecord *tank_obj;

        /**
         * Check to see if Bond is just now entering the tank.
         * If so, initialize the tank prop.
         * This also handles spinning Bond around (if required) to face the same direction as the turret.
        */
        if (g_EnterTankAudioState == TANK_RUN_STATE_NOT_RUNNING)
        {
            if (g_PlayerTankProp != NULL)
            {
                tank_obj = g_PlayerTankProp->obj;
                matrix_4x4_set_rotation_around_y(M_TAU_F - g_TankOrientationAngle, &sp268);
                matrix_scalar_multiply(tank_obj->model->scale, &sp268);
                
                sp25C.f[0] = g_TankModelPositionOffset.f[0];
                sp25C.f[1] = g_TankModelPositionOffset.f[1];
                sp25C.f[2] = g_TankModelPositionOffset.f[2];
                mtx4RotateVecInPlace(&sp268, (f32*)&sp25C);
                
                sp25C.f[0] += tank_obj->runtime_pos.f[0];
                sp25C.f[1] += tank_obj->runtime_pos.f[1];
                sp25C.f[2] += tank_obj->runtime_pos.f[2];

                sp258 = ((g_TankOrientationAngle + g_TankTurretOrientationAngleRad) * 360.0f) / M_TAU_F;
                sp254 = g_CurrentPlayer->vv_verta;
                if (sp254 < -20.0f)
                {
                    sp254 = -20.0f;
                }

                g_TankEnteringSitHeight += g_GlobalTimerDelta / 45.0f;
                if (g_TankEnteringSitHeight >= 1.0f)
                {
                    g_TankEnteringSitHeight = 1.0f;
                }

                g_TankEnteringSitHeightRemain = (cosf(g_TankEnteringSitHeight * M_TAU_F * 0.5f) + 1.0f) * 0.5f;

                g_CurrentPlayer->vv_verta = 
                    (g_TankEnteringSitHeightRemain * g_TankEnterBondVertAngleDeg) 
                    + ((1.0f - g_TankEnteringSitHeightRemain) * sp254); 

                ftemp_5 = sp258 - g_TankEnterBondHorizAngleDeg;
                if (ftemp_5 > 180.0f)
                {
                    sp258 -= 360.0f;
                }
                if (ftemp_5 < -180.0f)
                {
                    sp258 += 360.0f;
                }

                g_CurrentPlayer->vv_theta =
                    (g_TankEnteringSitHeightRemain * g_TankEnterBondHorizAngleDeg)
                    + ((1.0f - g_TankEnteringSitHeightRemain) * sp258); 

                if (g_CurrentPlayer->vv_theta >= 360.0f)
                {
                    g_CurrentPlayer->vv_theta -= 360.0f;
                }

                if (g_CurrentPlayer->vv_theta < 0.0f)
                {
                    g_CurrentPlayer->vv_theta += 360.0f;
                }

                move_offset.f[0] = (
                        (g_TankEnteringSitHeightRemain * g_EnterTankCoord.f[0]) + 
                        ((1.0f - g_TankEnteringSitHeightRemain) * sp25C.f[0])
                    ) - 
                    g_CurrentPlayer->field_488.collision_position.f[0];

                move_offset.f[1] = 0.0f;

                move_offset.f[2] = (
                    (g_TankEnteringSitHeightRemain * g_EnterTankCoord.f[2]) +
                    ((1.0f - g_TankEnteringSitHeightRemain) * sp25C.f[2])
                    ) - 
                    g_CurrentPlayer->field_488.collision_position.f[2];
            }

            if (!(g_TankEnteringSitHeight >= 1.0f))
            {
            }
            else
            {
                g_EnterTankAudioState = TANK_RUN_STATE_STARTING;
            }
        }
        /**
         * Else, Bond has already entered the tank.
        */
        else
        {
            /**
             * There's an initial "starting" step.
            */
            if (g_EnterTankAudioState == TANK_RUN_STATE_STARTING)
            {
                g_EnterTankAudioState = TANK_RUN_STATE_RUNNING;
                if ((g_TankSfxState[0] == NULL) && (lvlGetControlsLockedFlag() == 0))
                {
                    sndPlaySfx(g_musicSfxBufferPtr, TRUCK_START_SFX, &g_TankSfxState[0]);
                }
                
                sndCreatePostEvent(g_TankSfxState[0], 8, 0x61A8);
                g_TankEngineSfxVolume = 0x61A8;
            }
            /**
             * Else Bond has fully entered the tank, and the engine is running.
             * Update turret vertical angle.
             * Update engine sound effect volume based on current tank speed.
            */
            else
            {
                f32 tank_scaled_speedforwards;
                f32 tank_scaled_speedtheta;
                f32 tank_vertical_angle;
                
                tank_scaled_speedforwards = g_CurrentPlayer->speedforwards / TANK_MAX_SPEED;
                tank_scaled_speedtheta = g_CurrentPlayer->speedtheta / 0.3f;
                
                if (tank_scaled_speedforwards < 0.0f)
                {
                    tank_scaled_speedforwards = -tank_scaled_speedforwards;
                }
                if (tank_scaled_speedtheta < 0.0f)
                {
                    tank_scaled_speedtheta = -tank_scaled_speedtheta;
                }

                tank_engine_utilization_percent = tank_scaled_speedforwards;
                if (tank_scaled_speedforwards < tank_scaled_speedtheta)
                {
                    tank_engine_utilization_percent = tank_scaled_speedtheta;
                }

                if (tank_engine_utilization_percent > 0.0f)
                {
                    if (tank_engine_utilization_percent > 1.0f)
                    {
                        tank_engine_utilization_percent = 1.0f;
                    }
                    
                    if (g_TankSfxState[1] == NULL)
                    {
                        if (lvlGetControlsLockedFlag() == 0)
                        {
                            sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, TANK_SFX, &g_TankSfxState[1]);
                        }
                    }

                    if (g_TankSfxState[1] != NULL)
                    {
                        s32 phi_a2;

                        phi_a2 = 0x7FFF;
                        if (tank_engine_utilization_percent < 0.15f)
                        {
                            phi_a2 = (s32) ((tank_engine_utilization_percent * 20000.0f) / 0.15f);
                        }
                        else if (tank_engine_utilization_percent < 0.9f)
                        {
                            phi_a2 = (s32) ((((tank_engine_utilization_percent - 0.15f) * 12767.0f) / 0.75f) + 20000.0f);
                        }
                        
                        sndCreatePostEvent(g_TankSfxState[1], 8, phi_a2);
                    }
                }
                else
                {
                    if (g_TankSfxState[1] != NULL)
                    {
                        if (sndGetPlayingState(g_TankSfxState[1]) != 0)
                        {
                            sndDeactivate(g_TankSfxState[1]);
                        }
                    }
                }

                if (g_TankSfxState[0] == NULL)
                {
                    if (lvlGetControlsLockedFlag() == 0)
                    {
                        sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, TRUCK_RUN_SFX, &g_TankSfxState[0]);
                    }
                }

                if (g_TankSfxState[0] != NULL)
                {
                    g_TankEngineSfxVolume = 0x7FFF;
                    if (tank_engine_utilization_percent < 0.9f)
                    {
                        g_TankEngineSfxVolume = (s32) (((tank_engine_utilization_percent * 7767.0f) / 0.9f) + 25000.0f);
                    }

                    sndCreatePostEvent(g_TankSfxState[0], 8, g_TankEngineSfxVolume);
                }

                if (getCurrentPlayerWeaponId(GUNRIGHT) == ITEM_TANKSHELLS)
                {
                    tank_vertical_angle = g_CurrentPlayer->field_2A08;
                    tank_vertical_angle += 0.17453294f; /* should be DegToRad1Fact(10), but that yields 0.17453293f */
                }
                else
                {
                    tank_vertical_angle = g_TankTurretVerticalAngle;
                }

                if (tank_vertical_angle > DegToRad1Fact(25))
                {
                    tank_vertical_angle = DegToRad1Fact(25);
                }

                /* -0.087266468f should be DegToRad1Fact(-5), but that yields -0.0872664600611 */
                if (tank_vertical_angle < -0.087266468f)
                {
                    tank_vertical_angle = -0.087266468f;
                }

                for (i_3=0; i_3<g_ClockTimer; i_3++)
                {
                    g_TankTurretVerticalAngleRelated = (TANKTURRETVERTICALANGLERELATED_SCALE * g_TankTurretVerticalAngleRelated) + tank_vertical_angle;
                }

                g_TankTurretVerticalAngle = g_TankTurretVerticalAngleRelated * (1.0f - TANKTURRETVERTICALANGLERELATED_SCALE);
            }
            
        }

        g_CurrentPlayer->bondbreathing -= (0.750f * g_GlobalTimerDelta) / 2700.0f;

        if (g_CurrentPlayer->bondbreathing < 0.0f)
        {
            g_CurrentPlayer->bondbreathing = 0.0f;
        }
        
        bondviewMoveAnimationTick(0.0f, 0.0f, 0.0f);

        move_offset.f[0] += g_CurrentPlayer->speedforwards * sinf(M_TAU_F - g_TankOrientationAngle) * g_GlobalTimerDelta;
        move_offset.f[2] += g_CurrentPlayer->speedforwards * cosf(M_TAU_F - g_TankOrientationAngle) * g_GlobalTimerDelta;

        bondviewCalcUpdatePlayerCollision(&move_offset, 1);
        
        if ((g_EnterTankAudioState == TANK_RUN_STATE_RUNNING) && (g_ClockTimer > 0))
        {
            f32 calc_x;
            f32 calc_z;
            f32 calc_speedforwards;

#if defined(VERSION_EU)
            // Divide by zero check.
            if (g_GlobalTimerDelta == 0)
            {
                #if DEBUG
                    // unknown what went here.
                    return_null();
                #endif
            }
#endif
            
            calc_x = (g_CurrentPlayer->field_488.collision_position.f[0] - g_CurrentPlayer->bondprevpos.f[0]) / g_GlobalTimerDelta;
            calc_z = (g_CurrentPlayer->field_488.collision_position.f[2] - g_CurrentPlayer->bondprevpos.f[2]) / g_GlobalTimerDelta;
            calc_speedforwards = sqrtf((calc_x * calc_x) + (calc_z * calc_z));
            
            if (g_CurrentPlayer->speedforwards < 0.0f)
            {
                calc_speedforwards = -calc_speedforwards;
            }
            
            g_CurrentPlayer->speedforwards = calc_speedforwards;
        }
    }
    else // not in tank: in_tank_flag != 1
    {
        f32 sp220;
        f32 sp21C;
        f32 dist;
        f32 ftemp_col_x;
        f32 ftemp_col_z;
        f32 stack_padding_12;
        f32 start_collision_pos_x;
        f32 start_collision_pos_z;
        struct StandTile *sp200;
        f32 stack_padding_2;
        s32 stack_padding_11;
        f32 speedforwards;
        f32 ftemp_11;
        f32 speedsideways;
        f32 speedtheta;
        f32 stack_padding_25;
        f32 stack_padding_5;
        s32 stack_padding_6;
        f32 sp164;
        f32 sp2B0;
        f32 stack_padding_3;
        f32 stack_padding_111;
        f32 ftemp_26;
        f32 nd; // canonical name
        f32 ftemp_7;
        f32 sp240;
        struct move_bond_temp_struct curLocus;
        struct move_bond_collision bondCollision;
        f32 shorten; // canonical name
        f32 headpos_x;
        f32 headpos_z;
        struct StandTile *sp174;
        struct StandTile *sp170;
        f32 sp16C;
        f32 sp168;

        if ((g_TankSfxState[0] != NULL) && (sndGetPlayingState(g_TankSfxState[0]) != 0))
        {
            #if defined(VERSION_US)
            g_TankEngineSfxVolume -= (g_ClockTimer * 1000);
            #endif

            #if defined(VERSION_JP) || defined(VERSION_EU)
            g_TankEngineSfxVolume -= (s32)(1000.0f * g_GlobalTimerDelta);
            #endif

            if (g_TankEngineSfxVolume > 0)
            {
                sndCreatePostEvent(g_TankSfxState[0], 8, g_TankEngineSfxVolume);
            }
            else
            {
                sndDeactivate(g_TankSfxState[0]);
            }
        }

        if ((g_TankSfxState[1] != NULL) && (sndGetPlayingState(g_TankSfxState[1]) != 0))
        {
            sndDeactivate(g_TankSfxState[1]);
        }


        ftemp_7 = (g_BondMoveAnimationSetup[1].unk0C * 0.5f  * g_GlobalTimerDelta);
        sp3A0  = g_CurrentPlayer->speedsideways * ftemp_7;

        /*
            The following is similar to a block of Perfect Dark bwalk0f0c69b8.
        */
        
        ftemp_26 = -g_CurrentPlayer->swaytarget * g_CurrentPlayer->field_488.theta_transform.f[2];
        ftemp_11 = g_CurrentPlayer->swaytarget * g_CurrentPlayer->field_488.theta_transform.f[0];
        
        sp220 = (ftemp_26) - g_CurrentPlayer->swayoffset0;
        sp21C = (ftemp_11) - g_CurrentPlayer->swayoffset2;
        
        dist = (sp220 * sp220) + (sp21C * sp21C);

        if (dist >= 100.0f)
        {
            sp220 *= 0.6f * 1.0f;
            sp21C *= 0.6f * 1.0f;
        }

        speedsideways = g_CurrentPlayer->speedsideways * MAX_SPEED_FACTOR;
        speedforwards = g_CurrentPlayer->speedforwards;
        speedtheta = g_CurrentPlayer->speedtheta * MAX_SPEED_FACTOR;

        if (speedsideways < 0.0f)
        {
            speedsideways = -speedsideways;
        }
        if (speedforwards < 0.0f)
        {
            speedforwards = -speedforwards;
        }
        if (speedtheta < 0.0f)
        {
            speedtheta = -speedtheta;
        }

        maxspeed = speedforwards;
        
#if defined(VERSION_EU)
        if (maxspeed < speedsideways && 1)
#else
        if (maxspeed < speedsideways)
#endif
        {
            maxspeed = speedsideways;
        }
        if (maxspeed < speedtheta)
        {
            maxspeed = speedtheta;
        }

        if (dist >= 0.1f && maxspeed < MAX_SPEED_FACTOR)
        {
            maxspeed = MAX_SPEED_FACTOR;
        }

        if (maxspeed >= 0.750f)
        {
            g_CurrentPlayer->bondbreathing += (maxspeed - 0.750f) * g_GlobalTimerDelta / 900.0f ;
        }
        else
        {
            g_CurrentPlayer->bondbreathing -= (0.750f - maxspeed) * g_GlobalTimerDelta / 2700.0f;
        }
        
        if (g_CurrentPlayer->bondbreathing < 0.0f)
        {
            g_CurrentPlayer->bondbreathing = 0.0f;
        }
        else if (g_CurrentPlayer->bondbreathing > 1.0f)
        {
            g_CurrentPlayer->bondbreathing = 1.0f;
        }
        
        // perfect dark call: bmove0f0cc654
        bondviewMoveAnimationTick(maxspeed, g_CurrentPlayer->speedforwards, sp3A0);

        headpos_x = g_CurrentPlayer->headpos.f[0];
        headpos_z = g_CurrentPlayer->headpos.f[2];

        move_offset.f[0] += 
            (
                (headpos_z * g_CurrentPlayer->field_488.theta_transform.f[0]) -
                (headpos_x * g_CurrentPlayer->field_488.theta_transform.f[2])
            ) * g_GlobalTimerDelta;

        move_offset.f[2] += 
            (
                (headpos_z * g_CurrentPlayer->field_488.theta_transform.f[2]) +
                (headpos_x * g_CurrentPlayer->field_488.theta_transform.f[0])
            ) * g_GlobalTimerDelta;

 
        move_offset.f[0] += sp220;
        move_offset.f[2] += sp21C;

        start_collision_pos_x = g_CurrentPlayer->field_488.collision_position.f[0];
        start_collision_pos_z = g_CurrentPlayer->field_488.collision_position.f[2];
        sp200 = g_CurrentPlayer->field_488.current_tile_ptr;
        
        if (get_debug_fast_bond_flag())
        {
            move_offset.f[0] += 
                (
                    (g_CurrentPlayer->field_488.theta_transform.f[0] * g_CurrentPlayer->speedforwards) -
                    (g_CurrentPlayer->field_488.theta_transform.f[2] * g_CurrentPlayer->speedsideways)
                ) * g_GlobalTimerDelta * 10.0f;

            move_offset.f[2] += 
                (
                    (g_CurrentPlayer->field_488.theta_transform.f[2] * g_CurrentPlayer->speedforwards) +
                    (g_CurrentPlayer->field_488.theta_transform.f[0] * g_CurrentPlayer->speedsideways)
                ) * g_GlobalTimerDelta * 10.0f;
        }
        
        bondviewCalcUpdatePlayerCollision(&move_offset, (g_CurrentPlayer->swaytarget == 0.0f));

        stanTileDistanceRelated(
            &sp200,
            start_collision_pos_x,
            start_collision_pos_z,
            g_CurrentPlayer->field_488.collision_radius * 1.16f,
            &curLocus);
        
        /* almost never true */
        if (stanGetLocusCount(&curLocus) != 0)
        {
            use_stanHeight = 1;
        }

        stanTileDistanceRelated(
            &g_CurrentPlayer->field_488.current_tile_ptr,
            g_CurrentPlayer->field_488.collision_position.f[0],
            g_CurrentPlayer->field_488.collision_position.f[2],
            g_CurrentPlayer->field_488.collision_radius * 1.01f,
            &curLocus);

        /* almost never true */
        if (stanGetLocusCount(&curLocus) != 0)
        {
            use_stanHeight = 1;
        }

        stanTileDistanceRelated(
            &g_CurrentPlayer->field_488.current_tile_ptr,
            g_CurrentPlayer->field_488.collision_position.f[0],
            g_CurrentPlayer->field_488.collision_position.f[2],
            g_CurrentPlayer->field_488.collision_radius,
            &curLocus);
        
        /* almost always true */
        if (stanGetLocusCount(&curLocus) == 0)
        {
            stanTileDistanceRelated(
                &sp200,
                start_collision_pos_x,
                start_collision_pos_z,
                g_CurrentPlayer->field_488.collision_radius * 0.990099f,
                &curLocus);
        }
        
        /* almost never true */
        if (stanGetLocusCount(&curLocus))
        {
            use_stanHeight = 1;
            stanGetMoveBondCollisionTiles(&sp174, &sp170, &bondCollision);

            if (g_CurrentPlayer->stanHeight <= bondCollision.sp19C.f[1])
            {
                f32 sp2A8;
                f32 sp24C;
                f32 sp250;
                f32 sp310;
                f32 sp314;
                
                sp168 = bondCollision.bondCollision.f[0] - bondCollision.sp190.f[0];
                sp16C = bondCollision.sp190.f[2] - bondCollision.bondCollision.f[2];

                nd = sqrtf((sp16C * sp16C) + (sp168 * sp168));
                
                sp168 = sp168 / nd;
                sp16C = sp16C / nd;

                sp164 =
                    ((start_collision_pos_x - bondCollision.bondCollision.f[0]) * sp16C) +
                    ((start_collision_pos_z - bondCollision.bondCollision.f[2]) * sp168);
                
                sp2B0 = 
                    (((start_collision_pos_x + move_offset.f[0]) - bondCollision.bondCollision.f[0]) * sp16C) +
                    (((start_collision_pos_z + move_offset.f[2]) - bondCollision.bondCollision.f[2]) * sp168);
                
                if ((sp164 * sp2B0) <= 0.0f)
                {
                    shorten = 0.0f;
                }
                else
                {
                    if (sp2B0 < 0.0f)
                    {
                        sp164 = -sp164;
                        sp2B0 = -sp2B0;
                    }

                    if (sp164 <= sp2B0)
                    {
                        shorten = 0.0f;
                    }
                    else if (g_CurrentPlayer->field_488.collision_radius < sp2B0)
                    {
                        shorten = 0.0f;
                    }
                    else if (sp164 < g_CurrentPlayer->field_488.collision_radius)
                    {
                        shorten = 0.0f;
                    }
                    else
                    {
                        shorten = (sp164 - g_CurrentPlayer->field_488.collision_radius) / (sp164 - sp2B0);
                    }
                }

                sp2A8 = sqrtf((move_offset.f[0] * move_offset.f[0]) + (move_offset.f[2] * move_offset.f[2]));
                if (sp2A8 > 0.0f)
                {
                    f32 sp318;
                    
                    sp318 = (1.0f - shorten) * sp2A8;
                    sp390 = sp318 * 0.25f;

                    if (bondCollision.sp19C.f[1] <= (g_CurrentPlayer->stanHeight + sp390))
                    {
                        sp390 = (bondCollision.sp19C.f[1] - g_CurrentPlayer->stanHeight);
                        sp318 -= (sp390 / 0.25f);
                        shorten += (sp318 / sp2A8);
                    }
                }

                sp314 = bondCollision.sp19C.f[0] - bondCollision.bondCollision.f[0];
                sp310 = bondCollision.sp19C.f[2] - bondCollision.bondCollision.f[2];
                sp250 = bondCollision.sp1A8.f[0] - bondCollision.bondCollision.f[0];
                sp24C = bondCollision.sp1A8.f[2] - bondCollision.bondCollision.f[2];

                if (((sp250 * sp250) + (sp24C * sp24C)) < ((sp314 * sp314) + (sp310 * sp310)))
                {
                    sp314 = sp250;
                    sp310 = sp24C;
                }

                move_offset.f[0] = (move_offset.f[0] * shorten) + (sp314 * (sp390 / (bondCollision.sp19C.f[1] - bondCollision.bondCollision.f[1])));
                move_offset.f[2] = (move_offset.f[2] * shorten) + (sp310 * (sp390 / (bondCollision.sp19C.f[1] - bondCollision.bondCollision.f[1])));

                g_CurrentPlayer->field_488.collision_position.f[0] = start_collision_pos_x;
                g_CurrentPlayer->field_488.collision_position.f[2] = start_collision_pos_z;
                g_CurrentPlayer->field_488.current_tile_ptr = sp200;
                
                bondviewCalcUpdatePlayerCollision(&move_offset, (g_CurrentPlayer->swaytarget == 0.0f));
            }
        }

        ftemp_col_x = g_CurrentPlayer->field_488.collision_position.f[0] - start_collision_pos_x;
        ftemp_col_z = g_CurrentPlayer->field_488.collision_position.f[2] - start_collision_pos_z;
        sp240 = (move_offset.f[0] * move_offset.f[0]) + (move_offset.f[2] * move_offset.f[2]);
        if (sp240 != 0.0f)
        {
            sp240 = ((ftemp_col_x * ftemp_col_x) + (ftemp_col_z * ftemp_col_z)) / sp240;
        }
        sp240 = sqrtf(sp240);
        g_CurrentPlayer->swayoffset0 += sp240 * sp220;
        g_CurrentPlayer->swayoffset2 += sp240 * sp21C;
    }

    // add basic block
    {
        f32 breathing;
        f32 sp14C_temp;
        f32 weapon_speed_verta;
        
        sp14C_temp = g_CurrentPlayer->speedtheta;
        weapon_speed_verta =
            (g_CurrentPlayer->speedverta / 0.7f) +
            (g_CurrentPlayer->field_A4 / CHR_OBJ_MAXSPEED);
    
        /*
        Following matches the end of Perfect Dark bwalk0f0c69b8
        */
        breathing = bheadGetBreathingValue();    
        
        if (weapon_speed_verta > 1.0f)
        {
            weapon_speed_verta = 1.0f;
        }
        else if (weapon_speed_verta < -1.0f)
        {
            weapon_speed_verta = -1.0f;
        }
    
        if (g_CurrentPlayer->headanim == 1)
        {
            breathing *= 1.2f;
        }
    
        // Perfect Dark call bgun0f09d8dc
        gunSetBondWeaponSway(breathing, maxspeed, weapon_speed_verta, sp14C_temp);

        // Perfect Dark call bgunSetAdjustPos
        gunSetOffsetRelated(DegToRad1Fact(g_CurrentPlayer->vv_verta360));
    }

    // end perfect dark `void bwalk0f0c69b8(void)`

    /**
     * The following section updates the TankRecord fields, and handles prop collision detection
     * with the tank. If colliding with character, play the "arrrhghhg" sound effect, or if
     * colliding with prop then set tank movement penalty and create an explosion.
    */
    if ((g_PlayerTankProp != NULL) && (in_tank_flag == 1) && (g_EnterTankAudioState == TANK_RUN_STATE_RUNNING))
    {
        struct PropRecord *prop;
        struct TankRecord *sp140_tank_as_TankRecord;
        struct ObjectRecord *sp138_tank_as_ObjectRecord;
        f32 ftemp_12;
        struct ModelNode_BoundingBoxRecord *sp130;
        Mtxf spF0;
        struct coord3d spE4;
        s32 stack_padding_13; 
        s32 i_4; 
        s32 stemp; 
        void *stack_padding_8; 
        struct rect4f spB4_tank_collision_bounds;
        // roomids
        s32 sp94[8];
        s32 stanlineret;
        s16 *lookup_index;
        
        sp140_tank_as_TankRecord = ((struct TankRecord *)g_PlayerTankProp->obj);
        sp138_tank_as_ObjectRecord = (struct  ObjectRecord*)g_PlayerTankProp->obj;
        sp130 = (struct ModelNode_BoundingBoxRecord *)((struct ModelNode *)sp138_tank_as_ObjectRecord->model->obj->Switches)->Child->Data;
        
        sp140_tank_as_TankRecord->is_firing_tank = (getCurrentPlayerWeaponId(GUNRIGHT) == ITEM_TANKSHELLS)
            && get_hands_firing_status(GUNRIGHT);

        sp140_tank_as_TankRecord->turret_vertical_angle = g_TankTurretVerticalAngle;
        sp140_tank_as_TankRecord->turret_orientation_angle = g_TankTurretOrientationAngleRad;
        sp140_tank_as_TankRecord->tank_orientation_angle = g_TankOrientationAngle;

        matrix_4x4_set_rotation_around_y(M_TAU_F - g_TankOrientationAngle, &spF0);
        matrix_scalar_multiply(sp138_tank_as_ObjectRecord->model->scale, &spF0);

        spE4.f[0] = -g_TankModelPositionOffset.f[0];
        spE4.f[1] = -g_TankModelPositionOffset.f[1];
        spE4.f[2] = -g_TankModelPositionOffset.f[2];
        
        mtx4RotateVecInPlace(&spF0, &spE4);

        spE4.f[0] += g_CurrentPlayer->field_488.collision_position.f[0];
        spE4.f[2] += g_CurrentPlayer->field_488.collision_position.f[2];

        sp138_tank_as_ObjectRecord->prop->stan = g_CurrentPlayer->field_488.current_tile_ptr;

        stanlineret = walkTilesBetweenPoints_NoCallback(
            &sp138_tank_as_ObjectRecord->prop->stan,
            g_CurrentPlayer->field_488.collision_position.f[0],
            g_CurrentPlayer->field_488.collision_position.f[2],
            spE4.f[0],
            spE4.f[2]);
        #ifdef DEBUG
        assert(stanlineret); // #7362
        #endif

        sp140_tank_as_TankRecord->stan_y = stanGetPositionYValue(sp138_tank_as_ObjectRecord->prop->stan, spE4.f[0], spE4.f[2]);

        for (i_4=0; i_4<g_ClockTimer; i_4++)
        {
            sp140_tank_as_TankRecord->unkD0 = (sp140_tank_as_TankRecord->unkD0 * TANK_UNKD0_SCALE) + sp140_tank_as_TankRecord->stan_y;
        }
        
        ftemp_12 = (sp140_tank_as_TankRecord->unkD0 * (1.0f - TANK_UNKD0_SCALE));
        spE4.f[1] = ftemp_12
            - (chrpropBBOXGetYmin(sp130) * sp138_tank_as_ObjectRecord->model->scale)
            + 4.0f;

        matrix_4x4_copy(&spF0,  &sp138_tank_as_ObjectRecord->mtx);
        
        sp138_tank_as_ObjectRecord->runtime_pos.f[0] = sp138_tank_as_ObjectRecord->prop->pos.f[0] = spE4.f[0];
        sp138_tank_as_ObjectRecord->runtime_pos.f[1] = sp138_tank_as_ObjectRecord->prop->pos.f[1] = spE4.f[1];
        sp138_tank_as_ObjectRecord->runtime_pos.f[2] = sp138_tank_as_ObjectRecord->prop->pos.f[2] = spE4.f[2];

        setupUpdateObjectRoomPosition(sp138_tank_as_ObjectRecord);
        chrobjCollisionRelated(sp138_tank_as_ObjectRecord);
        bondviewGetTankCollisionBounds(&spB4_tank_collision_bounds, &g_CurrentPlayer->field_488.collision_position, g_TankOrientationAngle);
        chraiGetPropRoomIds(sp138_tank_as_ObjectRecord->prop, &sp94);
        
        // update num_obj_position_data_entries
        roomGetProps(&sp94);

        for (lookup_index=ptr_list_object_lookup_indices; *lookup_index>=0; lookup_index++)
        {
            prop = &pos_data_entry[*lookup_index];
            if (prop != sp138_tank_as_ObjectRecord->prop)
            {
                if (prop->type == PROP_TYPE_CHR)
                {
                    s32 sp88_collision_bound_height;
                    s32 sp84_collision_bound_z;
                    f32 sp80_collision_radius;
                    s32 sp7C;
                    struct coord3d sp70;
                    struct ChrRecord *sp6C;
                    f32 stack_padding_28;
                    
                    sp7C = 1;
                    sp6C = prop->chr;
                    chrpropGetCollisionBounds(prop, &sp80_collision_radius, &sp88_collision_bound_height, &sp84_collision_bound_z);
                    
                    if (chrpropTestPointInPolygon(&prop->pos, &spB4_tank_collision_bounds, 4))
                    {
                        sp7C = 0;

                        if (sp6C->actiontype == ACT_DIE)
                        {
#if defined(VERSION_US)
                            if ((sp6C->chrflags << 7) >= 0)
#endif
#if defined(VERSION_JP) || defined(VERSION_EU)
                            if ((sp6C->chrflags << 7) >= 0 && lvlGetControlsLockedFlag() == 0)
#endif
                            {
                                sp6C->chrflags |= CHRFLAG_01000000;
                                if ((D_80048380 % 3) < 2)
                                {
                                    chrobjSndCreatePostEventDefault(sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, CRUSHED_YELL_SFX, NULL), &prop->pos);
                                }
                                if ((D_80048380 % 3) > 0)
                                {
                                    chrobjSndCreatePostEventDefault(sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, TANK_CRUSH_MAN_SFX, NULL), &prop->pos);
                                }
                            }
                        }
                    }

                    if (sp7C && (chrobjTestPointPolygonCollision(&prop->pos, sp80_collision_radius, &spB4_tank_collision_bounds, 4)))
                    {
                        sp7C = 0;
                    }

                    if (sp7C == 0)
                    {
                        sp70.f[0] = sp138_tank_as_ObjectRecord->runtime_pos.f[0];
                        sp70.f[1] = prop->pos.f[1];
                        sp70.f[2] = sp138_tank_as_ObjectRecord->runtime_pos.f[2];
                        
                        chrlvExplosionDamage(prop->chr, &sp70, 3.0f, 1);
                    }                    
                }
                else if (prop->type == PROP_TYPE_OBJ)
                {
                    struct rect4f *sp64;
                    s32 sp60;
                    
                    chraiGetCollisionBoundsWithoutY(prop, &sp64, &sp60);
                    if ((sp60 > 0) && sub_GAME_7F0446B8(sp64, sp60, &spB4_tank_collision_bounds, 4))
                    {
                        // Explode destroyable props when the tank touches them
                        maybe_detonate_object_and_its_children(prop, 10000.0f, &prop->obj->runtime_pos, 0x20, get_cur_playernum());
                        g_TankDamagePenaltyTicks = TANK_DAMAGE_PENTALTY_TICKS;
                    }
                }
            }
        }
    }

    bondviewUpdatePlayerY(use_stanHeight, sp390);
    bondviewUpdatePlayerCollisionPositionFields();
    bondviewUpdatePlayerCollisionBounds();

    if (get_debug_man_pos_flag() != 0)
    {
        f32 sp5C_out_unused;

        copy_tile_RGB_as_24bit(
            g_CurrentPlayer->field_488.current_tile_ptr,
            g_CurrentPlayer->field_488.collision_position.f[0],
            g_CurrentPlayer->field_488.collision_position.f[2],
            &sp5C_out_unused);
    }
}




/**
 * US address 7F086990.
 * EU address 7F086AB0.
*/
void bondviewFrozenMoveBond(s8 stick_x, s8 stick_y, u16 buttons, u16 oldbuttons)
{
    struct coord3d property_pos;
    struct coord3d property_pos2;
    struct coord3d property_offset;
    struct coord3d offset;
    struct StandTile *room_pointer_tile;
    struct coord3d stan_walk_start;

    property_pos = g_DefaultFrozenPlayerPos;
    property_pos2 = g_DefaultFrozenPlayerPos2;
    property_offset = g_DefaultFrozenPlayerOffset;
    offset = g_DefaultFrozenMoveOffset;
    
    bondviewPlayerTickDamageAndHealth();
    bondviewPlayerTickExplode();
    bondviewProcessInput(0, 0, 0, 0);
    bondviewApplyVertaTheta();
    bondviewMoveAnimationTick(0, 0, 0);
    
    if ((g_ForceBondMoveOffset.f[0] != 0.0f) || (g_ForceBondMoveOffset.f[2] != 0.0f))
    {
        offset.f[0] += g_ForceBondMoveOffset.f[0] * g_GlobalTimerDelta;
        offset.f[2] += g_ForceBondMoveOffset.f[2] * g_GlobalTimerDelta;
    }
    
    offset.f[0] += ((g_CurrentPlayer->headpos.f[2] * g_CurrentPlayer->field_488.theta_transform.f[0]) - (g_CurrentPlayer->headpos.f[0] * g_CurrentPlayer->field_488.theta_transform.f[2])) * g_GlobalTimerDelta;
    offset.f[2] += ((g_CurrentPlayer->headpos.f[2] * g_CurrentPlayer->field_488.theta_transform.f[2]) + (g_CurrentPlayer->headpos.f[0] * g_CurrentPlayer->field_488.theta_transform.f[0])) * g_GlobalTimerDelta;
    
    bondviewCalcUpdatePlayerCollision(&offset, 1);
    bondviewUpdatePlayerY(0, 0.0f);
    bondviewUpdatePlayerCollisionPositionFields();
    
    if ((g_CameraMode == CAMERAMODE_FP_NOINPUT) || (g_CameraMode == CAMERAMODE_FP) || (g_CameraMode == CAMERAMODE_UNK10))
    {
        currentPlayerSetField00(0);
        return;
    }
    
    bondviewFrozenCameraTick(buttons, oldbuttons, &property_pos, &property_pos2, &property_offset, &room_pointer_tile, &stan_walk_start);
    currentPlayerSetField00(1);
    bondviewSetCurrentPlayerPosition(&property_pos, &property_pos2, &property_offset, room_pointer_tile, &stan_walk_start);
}



s16 getWidth320or440(void)
{
    if (camera_8003642C != 0)
    {
        return SCREEN_WIDTH_440;
    }

    return SCREEN_WIDTH_320;
}

s16 getHeight330or240(void)
{
    if (camera_8003642C != 0)
    {
        return SCREEN_HEIGHT_330;
    }

    return SCREEN_HEIGHT;
}

s16 bondviewGetCurrentPlayerViewportWidth(void)
{
    if (getPlayerCount() >= 3)
    {
        return VIEWPORT_WIDTH_4P;
    }

    if (camera_8003642C != 0)
    {
        return SCREEN_WIDTH_440;
    }

    if (cur_player_get_screen_setting() == SCREEN_SIZE_WIDESCREEN)
    {
        return VIEWPORT_WIDTH_WIDESCREEN;
    }

    if (cur_player_get_screen_setting() == SCREEN_SIZE_CINEMA)
    {
        return VIEWPORT_WIDTH_CINEMA;
    }

    return VIEWPORT_WIDTH_FULLSCREEN;
}

s16 get_curplayer_viewport_ulx(void)
{
    if (2 < getPlayerCount())
    {
        if ((get_cur_playernum() == 1) || (get_cur_playernum() == 3))
        {
                return 0xa1;
        }
    }

    return 0;
}




/**
 * Address 0x7F086D24.
 */
s16 bondviewGetCurrentPlayerViewportHeight(void)
{
    f32 t;

    if (getPlayerCount() >= 2)
    {
        return VIEWPORT_HEIGHT_4P;
    }

    if (camera_8003642C != 0)
    {
        if (cur_player_get_screen_setting() == SCREEN_SIZE_WIDESCREEN)
        {
            return VIEWPORT_HEIGHT_WIDESCREEN;
        }
        else if (cur_player_get_screen_setting() == SCREEN_SIZE_CINEMA)
        {
            return VIEWPORT_HEIGHT_CINEMA;
        }
        else
        {
            return VIEWPORT_HEIGHT_FULLSCREEN;
        }
    }

    if (cur_player_get_screen_setting() == SCREEN_SIZE_WIDESCREEN)
    {
        t = bondviewGetPauseAnimationPercent();
        return (s16) ((s32) (WIDESCREEN_SCALE_FACTOR * t) + VIEWPORT_OFFSET_HEIGHT_WIDESCREEN);
    }
    else if (cur_player_get_screen_setting() == SCREEN_SIZE_CINEMA)
    {
        t = bondviewGetPauseAnimationPercent();
        return (s16) ((s32) (CINEMA_SCALE_FACTOR * t) + VIEWPORT_OFFSET_HEIGHT_CINEMA);
    }
    else
    {
        return VIEWPORT_HEIGHT_DEFAULT;
    }
}



/**
 * Address 0x7F086E38.
 */
s16 bondviewGetCurrentPlayerViewportUly(void)
{
    f32 t;

    if (getPlayerCount() == 2)
    {
        if (get_cur_playernum() == 0)
        {
#ifdef VERSION_EU
            return 0;
#else
            return VIEWPORT_ULY_2P_PLAYER_1;
#endif
        }

        return VIEWPORT_ULY_2P_PLAYER_2;
    }

    if (getPlayerCount() >= 3)
    {
        if (get_cur_playernum() < 2)
        {
#ifdef VERSION_EU
            return 0;
#else
            return VIEWPORT_ULY_4P_PLAYER_12;
#endif
        }

        return VIEWPORT_ULY_4P_PLAYER_34;
    }

    if (camera_8003642C != 0)
    {
        if (cur_player_get_screen_setting() == SCREEN_SIZE_WIDESCREEN)
        {
            return VIEWPORT_ULY_CAM_WIDESCREEN;
        }
        else if (cur_player_get_screen_setting() == SCREEN_SIZE_CINEMA)
        {
            return VIEWPORT_ULY_CAM_CINEMA;
        }
        else
        {
            return VIEWPORT_ULY_CAM_FULLSCREEN;
        }
    }

    if (cur_player_get_screen_setting() == SCREEN_SIZE_WIDESCREEN)
    {
        t = bondviewGetPauseAnimationPercent();
        return (s16) ((s32) (WIDESCREEN_ULY_SCALE_FACTOR * t) + VIEWPORT_ULY_WIDESCREEN_OFFSET);
    }
    else if (cur_player_get_screen_setting() == SCREEN_SIZE_CINEMA)
    {
        t = bondviewGetPauseAnimationPercent();
        return (s16) ((s32) (CINEMA_ULY_SCALE_FACTOR * t) + VIEWPORT_ULY_CINEMA_OFFSET);
    }
    else
    {
#ifdef VERSION_EU
            return 0;
#else
            return VIEWPORT_ULY_DEFAULT;
#endif
    }
}

/**
 * Sets/updates viewport for player.
 * Refreshes autoaim setting.
 * Arguments are passed into MoveBond or bondviewFrozenMoveBond.
 * Checks if necessary to call bossReturnTitleStage.
 * Set player->buttons_pressed to arg2.
 * 
 * Address 0x7F086F9C (VERSION_US).
 * Address 0x7F0870BC (VERSION_EU).
 * Address 0x7F087668 (VERSION_JP).
 */
void bondviewMovePlayerUpdateViewport(s8 arg0, s8 arg1, u16 arg2)
{
#ifdef VERSION_EU
    f32 faspect;
#endif

    set_cur_player_fovy(FOV_Y_F);

    // This call doesn't do anything, the call viSetFovY(g_CurrentPlayer->fovy); in lvlRender
    // will actually change the field of view.
    // The call above should set g_CurrentPlayer->fovy, but it doesn't seem to affect
    // the fov....
    viSetFovY(FOV_Y_F);

    if (camera_80036430 != 0)
    {
        if ((camera_80036430 >= 4) && (resolution != 0) && (viGetFrameBuf2() == (u8*)(cfb_16[1])))
        {
            camera_8003642C = 1;
            camera_80036430 = 0;
        }
        else
        {
            camera_80036430 += 1;
        }
    }
    else
    {
        if (camera_80036434 != 0)
        {
            if ((camera_80036434 >= 4) && (viGetFrameBuf2() == (u8*)(cfb_16[0])))
            {
                camera_8003642C = 0;
                camera_80036434 = 0;
            }
            else
            {
                camera_80036434 += 1;
            }
        }
    }

    if ((camera_8003642C != 0) && (viGetFrameBuf2() == (u8*)(cfb_16[1])))
    {
        viSetFrameBuf2((u8 *) resolution);
    }

#ifdef VERSION_EU
    if (get_screen_ratio() == SCREEN_RATIO_16_9)
    {
        faspect = ((f32) bondviewGetCurrentPlayerViewportWidth() / (f32) bondviewGetCurrentPlayerViewportHeight()) * 0.75f * WIDESCREEN_ASPECT;
    }
    else
    {
        faspect = (f32) bondviewGetCurrentPlayerViewportWidth() / (f32) bondviewGetCurrentPlayerViewportHeight();
    }
    
    if (camera_8003642C == 0)
    {
        faspect *= EU_CAMERA_8003642C_ASPECT;
    }
    
    set_cur_player_aspect(faspect);
    viSetAspect(faspect);

#else

    if (get_screen_ratio() == SCREEN_RATIO_16_9)
    {
        set_cur_player_aspect(((f32) bondviewGetCurrentPlayerViewportWidth() / (f32) bondviewGetCurrentPlayerViewportHeight()) * 0.75f * WIDESCREEN_ASPECT);
        viSetAspect(((f32) bondviewGetCurrentPlayerViewportWidth() / (f32) bondviewGetCurrentPlayerViewportHeight()) * 0.75f * WIDESCREEN_ASPECT);
    }
    else
    {
        set_cur_player_aspect((f32) bondviewGetCurrentPlayerViewportWidth() / (f32) bondviewGetCurrentPlayerViewportHeight());
        viSetAspect((f32) bondviewGetCurrentPlayerViewportWidth() / (f32) bondviewGetCurrentPlayerViewportHeight());
    }
#endif

    set_cur_player_screen_size( bondviewGetCurrentPlayerViewportWidth(), bondviewGetCurrentPlayerViewportHeight());
    set_cur_player_viewport_size( get_curplayer_viewport_ulx(), bondviewGetCurrentPlayerViewportUly());
    viSetXY(getWidth320or440(), getHeight330or240());
    viSetBuf(getWidth320or440(), getHeight330or240());
    viSetViewSize(bondviewGetCurrentPlayerViewportWidth(), bondviewGetCurrentPlayerViewportHeight());
    viSetViewPosition(get_curplayer_viewport_ulx(), bondviewGetCurrentPlayerViewportUly());
    currentPlayerUpdateColourScreenProperties();
    currentPlayerTickChrFade();
    set_BONDdata_autoaim_y(cur_player_get_autoaim());
    set_BONDdata_autoaim_x(cur_player_get_autoaim());
    set_BONDdata_lookahead_setting(cur_player_get_lookahead());
    gunSetGunAmmoVisible(GUNAMMOREASON_OPTION, cur_player_get_ammo_onscreen_setting());

    gunSetSightVisible(
        GUNSIGHTREASON_1,
        (getPlayerCount() == 1 && cur_player_get_sight_onscreen_control())
            || (getPlayerCount() >= 2 && g_playerPerm->sight)
    );

#if defined(VERSION_EU)
    if (1);
#endif

    if ((g_CameraMode == CAMERAMODE_NONE) || ((g_CameraMode == CAMERAMODE_FP) && (D_800364B0 != 0)) || (g_CameraMode == CAMERAMODE_UNK10))
    {
        if (get_cur_playernum() == 0)
        {
            mission_timer += g_ClockTimer;
        }

        MoveBond(arg0, arg1, arg2, (u16) g_CurrentPlayer->buttons_pressed);
    }
    else
    {
        bondviewFrozenMoveBond(arg0, arg1, arg2, (u16) g_CurrentPlayer->buttons_pressed);
    }
    
#if defined(BUGFIX_R1)
    watch_time_0 += jpD_800484D0;
#else
    // VERSION_US
    watch_time_0 += speedgraphframes;
#endif
    
    if (stop_time_flag != 0)
    {
        if ((lvlGetControlsLockedFlag() == 0) && ((arg2 & ~(g_CurrentPlayer->buttons_pressed) & (CONT_A | B_BUTTON | Z_TRIG | START_BUTTON | CONT_R | CONT_L))))
        {
            stop_time_flag = 2;

            if (currentPlayerIsFadeComplete())
            {
                if (g_CurrentPlayer->colourscreenfrac == 0.0f)
                {
                    currentPlayerSetFadeColour(0, 0, 0, 0.0f);
                    currentPlayerSetFadeFrac(60.0f, 1.0f);
                }
            }
            else
            {
                if (g_CurrentPlayer->colourfadefracnew == 0.0f)
                {
                    currentPlayerSetFadeFrac(g_CurrentPlayer->colourfadetime60, 1.0f);
                }
            }
        }

        if ((stop_time_flag == 2) && currentPlayerIsFadeComplete() && (g_CurrentPlayer->colourscreenfrac == 1.0f))
        {
            bossReturnTitleStage();
        }
    }
    
    if (g_CameraAfterCinema)
    {
        sub_GAME_7F07B1A4();
    }
    
    if (g_CurrentPlayer->bonddead)
    {
        if (g_CurrentPlayer->redbloodfinished == 0)
        {
            currentPlayerEquipWeaponWrapper(GUNLEFT, 0);
            currentPlayerEquipWeaponWrapper(GUNRIGHT, 0);

            if (0)
            {
                // removed?
            };
        }

        if (g_CurrentPlayer->redbloodfinished && g_CurrentPlayer->deathanimfinished && (D_80036510 >= CAMERAMODE_SWIRL))
        {
            bossRunTitleStage();
        }
    }

    if ((g_CameraMode == CAMERAMODE_UNK10) && currentPlayerIsFadeComplete())
    {
        bossRunTitleStage();
    }

    g_CurrentPlayer->buttons_pressed = arg2;
}


/**
 * Address 0x7F0875E4.
 */
void bondviewUpdateCurrentRoomPosition(s32 arg0)
{
    sub_GAME_7F0BCA34(arg0, &g_CurrentPlayer->current_model_pos);
    g_CurrentPlayer->current_room_pos.f[0] = g_CurrentPlayer->current_model_pos.f[0] * get_room_data_float1();
    g_CurrentPlayer->current_room_pos.f[1] = g_CurrentPlayer->current_model_pos.f[1] * get_room_data_float1();
    g_CurrentPlayer->current_room_pos.f[2] = g_CurrentPlayer->current_model_pos.f[2] * get_room_data_float1();
    sub_GAME_7F0BC624(arg0);
}


void store_BONDdata_curpos_to_previous(void) {
    g_CurrentPlayer->previous_model_pos.f[0] = g_CurrentPlayer->current_model_pos.f[0];
    g_CurrentPlayer->previous_model_pos.f[1] = g_CurrentPlayer->current_model_pos.f[1];
    g_CurrentPlayer->previous_model_pos.f[2] = g_CurrentPlayer->current_model_pos.f[2];
    mtx4RotateVecInPlace(camGetWorldToScreenMtxf(), &g_CurrentPlayer->previous_model_pos);
}

void sub_GAME_7F0876C4(coord3d* cam_pos, coord3d* cam_look, coord3d* cam_up)
{
    Mtx sp108;
    LookAt *lookat;
    Mtxf spC4;
    coord3d clpos;
    coord3d scaledpos;
    f32 scale;
    Mtx *temp_s0;
    Mtxf *projmtx;
    Mtxf sp60;
    s32 j;
    s32 i;

    i = bondviewGetCurrentPlayersRoom();
    bondviewUpdateCurrentRoomPosition(i);

    g_CurrentPlayer->field_5C = dynAllocateMatrix();
    g_CurrentPlayer->field_60 = dynAllocateMatrix();
    g_CurrentPlayer->field_64 = dynAllocateMatrix();
    g_CurrentPlayer->field_68 = dynAllocateMatrix();

    lookat = dynAllocate7F0BD6F8(2);

    scale = D_800364CC;

    scaledpos.x = (cam_pos->x - g_CurrentPlayer->current_model_pos.x) * scale;
    scaledpos.y = (cam_pos->y - g_CurrentPlayer->current_model_pos.y) * scale;
    scaledpos.z = (cam_pos->z - g_CurrentPlayer->current_model_pos.z) * scale;

    clpos.f[0] = scaledpos.f[0] + cam_look->f[0];
    clpos.f[1] = scaledpos.f[1] + cam_look->f[1];
    clpos.f[2] = scaledpos.f[2] + cam_look->f[2];

    matrix_4x4_7F059424(&spC4,
        scaledpos.x, scaledpos.y, scaledpos.z,
        cam_look->x, cam_look->y, cam_look->z,
        cam_up->x, cam_up->y, cam_up->z);

    guLookAtReflect(&sp108, lookat,
        scaledpos.x, scaledpos.y, scaledpos.z,
        clpos.x, clpos.y, clpos.z,
        cam_up->x, cam_up->y, cam_up->z);

    matrix_4x4_7F059424((Mtxf*) g_CurrentPlayer->field_64,
        cam_pos->x, cam_pos->y, cam_pos->z,
        cam_look->x, cam_look->y, cam_look->z,
        cam_up->x, cam_up->y, cam_up->z);

    matrix_4x4_7F059708((Mtxf*) g_CurrentPlayer->field_68,
        cam_pos->x, cam_pos->y, cam_pos->z,
        cam_look->x, cam_look->y, cam_look->z,
        cam_up->x, cam_up->y, cam_up->z);

    temp_s0 = dynAllocateMatrix();

    projmtx = currentPlayerGetProjectionMatrixF();
    matrix_4x4_multiply(projmtx, &spC4, &sp60);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (sp60.m[i][j] > 32000.0f) {
				sp60.m[i][j] = 32000.0f;
			} else if (sp60.m[i][j] < -32000.0f) {
				sp60.m[i][j] = -32000.0f;
			}
		}
	}

    guMtxF2L((f32 (*)[4]) &sp60, temp_s0);
    set_BONDdata_field_10E0((s32) temp_s0);
    scale = bgGetLevelVisibilityScale();
    matrix_scalar_multiply(scale, spC4.m[0]);
    guMtxF2L((f32 (*)[4]) &spC4, (Mtx* ) g_CurrentPlayer->field_5C);
    sub_GAME_7F059334((s32* ) g_CurrentPlayer->field_5C, (s32* ) g_CurrentPlayer->field_60);
    currentPlayerSetMatrix10C8((Mtx* ) g_CurrentPlayer->field_5C);
    currentPlayerSetMatrix10C4((Mtx* ) g_CurrentPlayer->field_60);
    currentPlayerSetMatrix10CC((Mtxf* ) g_CurrentPlayer->field_64);
    currentPlayerSetMatrix10D4((Mtxf* ) g_CurrentPlayer->field_68);
    sub_GAME_7F078464((s32) lookat);
    sub_GAME_7F0785DC();
    store_BONDdata_curpos_to_previous();
}





#ifdef NONMATCHING
s32 sub_GAME_7F087A08(s32 arg0) {
    f32 sp20;
    f32 sp2C;
    f32 sp30;
    ? sp34;
    f32 sp40;
    ? sp4C;
    void *sp58;
    f32 sp5C;
    f32 sp60;
    f32 sp64;
    f32 sp68;
    f32 sp6C;
    f32 sp70;
    f32 sp74;
    f32 sp78;
    f32 sp7C;
    void *temp_v1;
    s32 temp_a0;
    s32 temp_a1;
    f32 temp_f2;
    ? temp_ret;
    f32 phi_f16;
    f32 phi_f2;

    // Node 0
    if (*g_CurrentPlayer == 1)
    {
        // Node 1
        sp74 = (f32) g_CurrentPlayer->xpos;
        sp78 = (f32) g_CurrentPlayer->ypos;
        sp7C = (f32) g_CurrentPlayer->zpos;
        sp68 = (f32) (g_CurrentPlayer->xpos2 - g_CurrentPlayer->xpos);
        sp6C = (f32) (g_CurrentPlayer->ypos2 - g_CurrentPlayer->ypos);
        sp70 = (f32) (g_CurrentPlayer->zpos2 - g_CurrentPlayer->zpos);
        sp5C = (f32) g_CurrentPlayer->xoffset;
        sp60 = (f32) g_CurrentPlayer->yoffset;
        sp64 = (f32) g_CurrentPlayer->zoffset;
    }
    else
    {
        // Node 2
        temp_v1 = (g_CurrentPlayer + 0x488);
        sp4C = (?32) D_80036830;
        temp_a0 = (temp_v1 + 0x2c);
        temp_a1 = (temp_v1 + 0x38);
        sp4C.unk4 = (?32) D_80036830.unk4;
        sp4C.unk8 = (?32) D_80036830.unk8;
        if (g_CurrentPlayer->bonddead == 0)
        {
            // Node 3
            sp58 = temp_v1;
            sub_GAME_7F09C7C4(temp_a0, temp_a1, &sp4C);
        }
        else
        {
            // Node 4
            sp58 = temp_v1;
            viShake(0, temp_a0, temp_a1, &sp4C);
        }
        // Node 5
        sp74 = (f32) temp_v1->unk2C;
        sp78 = (f32) temp_v1->unk30;
        sp7C = (f32) temp_v1->unk34;
        sp68 = (f32) temp_v1->unk38;
        sp6C = (f32) temp_v1->unk3C;
        sp70 = (f32) temp_v1->unk40;
        sp5C = (f32) temp_v1->unk44;
        sp60 = (f32) temp_v1->unk48;
        sp64 = (f32) temp_v1->unk4C;
    }
    // Node 6
    sub_GAME_7F0876C4(&sp74, &sp68, &sp5C);
    sub_GAME_7F068190(&sp34, &sp40);
    sp30 = sp44;
    sp2C = sqrtf(((sp48 * sp48) + (sp40 * sp40)));
    sp20 = get_curplay_vertical_rotation_in_degrees();
    temp_f2 = (atan2f(sp30, sp2C) + sp20);
    phi_f16 = temp_f2;
    if (D_8005526C <= temp_f2)
    {
        // Node 7
        phi_f16 = (temp_f2 - D_80055270);
    }
    // Node 8
    g_CurrentPlayer->field_2A08 = (f32) phi_f16;
    temp_ret = atan2f(-sp40, -sp48);
    phi_f2 = temp_ret;
    if (D_80055274 <= temp_ret)
    {
        // Node 9
        phi_f2 = (temp_ret - D_80055278);
    }
    // Node 10
    g_CurrentPlayer->field_2A0C = (f32) phi_f2;
    return arg0;
}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_8005526C
.word 0x40490fdb /*3.1415927*/
glabel D_80055270
.word 0x40c90fdb /*6.2831855*/
glabel D_80055274
.word 0x40490fdb /*3.1415927*/
glabel D_80055278
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F087A08
/* 0BC538 7F087A08 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BC53C 7F087A0C 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC540 7F087A10 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0BC544 7F087A14 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0BC548 7F087A18 AFA40080 */  sw    $a0, 0x80($sp)
/* 0BC54C 7F087A1C 8C4E0000 */  lw    $t6, ($v0)
/* 0BC550 7F087A20 24010001 */  li    $at, 1
/* 0BC554 7F087A24 3C0F8003 */  lui   $t7, %hi(D_80036830)
/* 0BC558 7F087A28 15C1001A */  bne   $t6, $at, .L7F087A94
/* 0BC55C 7F087A2C 25EF6830 */   addiu $t7, %lo(D_80036830) # addiu $t7, $t7, 0x6830
/* 0BC560 7F087A30 C4440004 */  lwc1  $f4, 4($v0)
/* 0BC564 7F087A34 E7A40074 */  swc1  $f4, 0x74($sp)
/* 0BC568 7F087A38 C4460008 */  lwc1  $f6, 8($v0)
/* 0BC56C 7F087A3C E7A60078 */  swc1  $f6, 0x78($sp)
/* 0BC570 7F087A40 C448000C */  lwc1  $f8, 0xc($v0)
/* 0BC574 7F087A44 E7A8007C */  swc1  $f8, 0x7c($sp)
/* 0BC578 7F087A48 C4520004 */  lwc1  $f18, 4($v0)
/* 0BC57C 7F087A4C C44A0010 */  lwc1  $f10, 0x10($v0)
/* 0BC580 7F087A50 46125101 */  sub.s $f4, $f10, $f18
/* 0BC584 7F087A54 E7A40068 */  swc1  $f4, 0x68($sp)
/* 0BC588 7F087A58 C4480008 */  lwc1  $f8, 8($v0)
/* 0BC58C 7F087A5C C4460014 */  lwc1  $f6, 0x14($v0)
/* 0BC590 7F087A60 46083281 */  sub.s $f10, $f6, $f8
/* 0BC594 7F087A64 E7AA006C */  swc1  $f10, 0x6c($sp)
/* 0BC598 7F087A68 C444000C */  lwc1  $f4, 0xc($v0)
/* 0BC59C 7F087A6C C4520018 */  lwc1  $f18, 0x18($v0)
/* 0BC5A0 7F087A70 46049181 */  sub.s $f6, $f18, $f4
/* 0BC5A4 7F087A74 E7A60070 */  swc1  $f6, 0x70($sp)
/* 0BC5A8 7F087A78 C448001C */  lwc1  $f8, 0x1c($v0)
/* 0BC5AC 7F087A7C E7A8005C */  swc1  $f8, 0x5c($sp)
/* 0BC5B0 7F087A80 C44A0020 */  lwc1  $f10, 0x20($v0)
/* 0BC5B4 7F087A84 E7AA0060 */  swc1  $f10, 0x60($sp)
/* 0BC5B8 7F087A88 C4520024 */  lwc1  $f18, 0x24($v0)
/* 0BC5BC 7F087A8C 10000028 */  b     .L7F087B30
/* 0BC5C0 7F087A90 E7B20064 */   swc1  $f18, 0x64($sp)
.L7F087A94:
/* 0BC5C4 7F087A94 8DE10000 */  lw    $at, ($t7)
/* 0BC5C8 7F087A98 27A6004C */  addiu $a2, $sp, 0x4c
/* 0BC5CC 7F087A9C 24430488 */  addiu $v1, $v0, 0x488
/* 0BC5D0 7F087AA0 ACC10000 */  sw    $at, ($a2)
/* 0BC5D4 7F087AA4 8DE80004 */  lw    $t0, 4($t7)
/* 0BC5D8 7F087AA8 2464002C */  addiu $a0, $v1, 0x2c
/* 0BC5DC 7F087AAC 24650038 */  addiu $a1, $v1, 0x38
/* 0BC5E0 7F087AB0 ACC80004 */  sw    $t0, 4($a2)
/* 0BC5E4 7F087AB4 8DE10008 */  lw    $at, 8($t7)
/* 0BC5E8 7F087AB8 ACC10008 */  sw    $at, 8($a2)
/* 0BC5EC 7F087ABC 8C4900D8 */  lw    $t1, 0xd8($v0)
/* 0BC5F0 7F087AC0 55200006 */  bnezl $t1, .L7F087ADC
/* 0BC5F4 7F087AC4 44806000 */   mtc1  $zero, $f12
/* 0BC5F8 7F087AC8 0FC271F1 */  jal   sub_GAME_7F09C7C4
/* 0BC5FC 7F087ACC AFA30058 */   sw    $v1, 0x58($sp)
/* 0BC600 7F087AD0 10000005 */  b     .L7F087AE8
/* 0BC604 7F087AD4 8FA30058 */   lw    $v1, 0x58($sp)
/* 0BC608 7F087AD8 44806000 */  mtc1  $zero, $f12
.L7F087ADC:
/* 0BC60C 7F087ADC 0C000EC1 */  jal   viShake
/* 0BC610 7F087AE0 AFA30058 */   sw    $v1, 0x58($sp)
/* 0BC614 7F087AE4 8FA30058 */  lw    $v1, 0x58($sp)
.L7F087AE8:
/* 0BC618 7F087AE8 C464002C */  lwc1  $f4, 0x2c($v1)
/* 0BC61C 7F087AEC E7A40074 */  swc1  $f4, 0x74($sp)
/* 0BC620 7F087AF0 C4660030 */  lwc1  $f6, 0x30($v1)
/* 0BC624 7F087AF4 E7A60078 */  swc1  $f6, 0x78($sp)
/* 0BC628 7F087AF8 C4680034 */  lwc1  $f8, 0x34($v1)
/* 0BC62C 7F087AFC E7A8007C */  swc1  $f8, 0x7c($sp)
/* 0BC630 7F087B00 C46A0038 */  lwc1  $f10, 0x38($v1)
/* 0BC634 7F087B04 E7AA0068 */  swc1  $f10, 0x68($sp)
/* 0BC638 7F087B08 C472003C */  lwc1  $f18, 0x3c($v1)
/* 0BC63C 7F087B0C E7B2006C */  swc1  $f18, 0x6c($sp)
/* 0BC640 7F087B10 C4640040 */  lwc1  $f4, 0x40($v1)
/* 0BC644 7F087B14 E7A40070 */  swc1  $f4, 0x70($sp)
/* 0BC648 7F087B18 C4660044 */  lwc1  $f6, 0x44($v1)
/* 0BC64C 7F087B1C E7A6005C */  swc1  $f6, 0x5c($sp)
/* 0BC650 7F087B20 C4680048 */  lwc1  $f8, 0x48($v1)
/* 0BC654 7F087B24 E7A80060 */  swc1  $f8, 0x60($sp)
/* 0BC658 7F087B28 C46A004C */  lwc1  $f10, 0x4c($v1)
/* 0BC65C 7F087B2C E7AA0064 */  swc1  $f10, 0x64($sp)
.L7F087B30:
/* 0BC660 7F087B30 27A40074 */  addiu $a0, $sp, 0x74
/* 0BC664 7F087B34 27A50068 */  addiu $a1, $sp, 0x68
/* 0BC668 7F087B38 0FC21DB1 */  jal   sub_GAME_7F0876C4
/* 0BC66C 7F087B3C 27A6005C */   addiu $a2, $sp, 0x5c
/* 0BC670 7F087B40 27A40034 */  addiu $a0, $sp, 0x34
/* 0BC674 7F087B44 0FC1A064 */  jal   sub_GAME_7F068190
/* 0BC678 7F087B48 27A50040 */   addiu $a1, $sp, 0x40
/* 0BC67C 7F087B4C C7A00048 */  lwc1  $f0, 0x48($sp)
/* 0BC680 7F087B50 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 0BC684 7F087B54 C7B20044 */  lwc1  $f18, 0x44($sp)
/* 0BC688 7F087B58 46000102 */  mul.s $f4, $f0, $f0
/* 0BC68C 7F087B5C E7B20030 */  swc1  $f18, 0x30($sp)
/* 0BC690 7F087B60 46021182 */  mul.s $f6, $f2, $f2
/* 0BC694 7F087B64 0C007DF8 */  jal   sqrtf
/* 0BC698 7F087B68 46062300 */   add.s $f12, $f4, $f6
/* 0BC69C 7F087B6C 0FC227C4 */  jal   get_curplay_vertical_rotation_in_degrees
/* 0BC6A0 7F087B70 E7A0002C */   swc1  $f0, 0x2c($sp)
/* 0BC6A4 7F087B74 E7A00020 */  swc1  $f0, 0x20($sp)
/* 0BC6A8 7F087B78 C7AC0030 */  lwc1  $f12, 0x30($sp)
/* 0BC6AC 7F087B7C 0FC16A8C */  jal   atan2f
/* 0BC6B0 7F087B80 C7AE002C */   lwc1  $f14, 0x2c($sp)
/* 0BC6B4 7F087B84 C7A80020 */  lwc1  $f8, 0x20($sp)
/* 0BC6B8 7F087B88 3C018005 */  lui   $at, %hi(D_8005526C)
/* 0BC6BC 7F087B8C C42A526C */  lwc1  $f10, %lo(D_8005526C)($at)
/* 0BC6C0 7F087B90 46080080 */  add.s $f2, $f0, $f8
/* 0BC6C4 7F087B94 3C018005 */  lui   $at, %hi(D_80055270)
/* 0BC6C8 7F087B98 3C0A8008 */  lui   $t2, %hi(g_CurrentPlayer)
/* 0BC6CC 7F087B9C 4602503E */  c.le.s $f10, $f2
/* 0BC6D0 7F087BA0 46001406 */  mov.s $f16, $f2
/* 0BC6D4 7F087BA4 45000003 */  bc1f  .L7F087BB4
/* 0BC6D8 7F087BA8 00000000 */   nop
/* 0BC6DC 7F087BAC C4325270 */  lwc1  $f18, %lo(D_80055270)($at)
/* 0BC6E0 7F087BB0 46121401 */  sub.s $f16, $f2, $f18
.L7F087BB4:
/* 0BC6E4 7F087BB4 8D4AA0B0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0BC6E8 7F087BB8 E5502A08 */  swc1  $f16, 0x2a08($t2)
/* 0BC6EC 7F087BBC C7AE0048 */  lwc1  $f14, 0x48($sp)
/* 0BC6F0 7F087BC0 C7AC0040 */  lwc1  $f12, 0x40($sp)
/* 0BC6F4 7F087BC4 46007387 */  neg.s $f14, $f14
/* 0BC6F8 7F087BC8 0FC16A8C */  jal   atan2f
/* 0BC6FC 7F087BCC 46006307 */   neg.s $f12, $f12
/* 0BC700 7F087BD0 3C018005 */  lui   $at, %hi(D_80055274)
/* 0BC704 7F087BD4 C4245274 */  lwc1  $f4, %lo(D_80055274)($at)
/* 0BC708 7F087BD8 46000086 */  mov.s $f2, $f0
/* 0BC70C 7F087BDC 3C018005 */  lui   $at, %hi(D_80055278)
/* 0BC710 7F087BE0 4600203E */  c.le.s $f4, $f0
/* 0BC714 7F087BE4 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer)
/* 0BC718 7F087BE8 45000003 */  bc1f  .L7F087BF8
/* 0BC71C 7F087BEC 00000000 */   nop
/* 0BC720 7F087BF0 C4265278 */  lwc1  $f6, %lo(D_80055278)($at)
/* 0BC724 7F087BF4 46060081 */  sub.s $f2, $f0, $f6
.L7F087BF8:
/* 0BC728 7F087BF8 8D6BA0B0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0BC72C 7F087BFC E5622A0C */  swc1  $f2, 0x2a0c($t3)
/* 0BC730 7F087C00 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0BC734 7F087C04 8FA20080 */  lw    $v0, 0x80($sp)
/* 0BC738 7F087C08 27BD0080 */  addiu $sp, $sp, 0x80
/* 0BC73C 7F087C0C 03E00008 */  jr    $ra
/* 0BC740 7F087C10 00000000 */   nop
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_8005526C
.word 0x40490fdb /*3.1415927*/
glabel D_80055270
.word 0x40c90fdb /*6.2831855*/
glabel D_80055274
.word 0x40490fdb /*3.1415927*/
glabel D_80055278
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F087A08
/* 0BA4C0 7F087AD0 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0BA4C4 7F087AD4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0BA4C8 7F087AD8 0C001769 */  jal   bossGetStageNum
/* 0BA4CC 7F087ADC AFA40080 */   sw    $a0, 0x80($sp)
/* 0BA4D0 7F087AE0 24010036 */  li    $at, 54
/* 0BA4D4 7F087AE4 14410022 */  bne   $v0, $at, .L7F087B70
/* 0BA4D8 7F087AE8 00000000 */   nop
/* 0BA4DC 7F087AEC 0FC2907A */  jal   cur_player_get_screen_setting
/* 0BA4E0 7F087AF0 00000000 */   nop
/* 0BA4E4 7F087AF4 24010002 */  li    $at, 2
/* 0BA4E8 7F087AF8 1441000B */  bne   $v0, $at, .L7F087B28
/* 0BA4EC 7F087AFC 00000000 */   nop
/* 0BA4F0 7F087B00 0FC06FCC */  jal   insert_imageDL
/* 0BA4F4 7F087B04 8FA40080 */   lw    $a0, 0x80($sp)
/* 0BA4F8 7F087B08 0FC06FCC */  jal   insert_imageDL
/* 0BA4FC 7F087B0C 00402025 */   move  $a0, $v0
/* 0BA500 7F087B10 0FC06FCC */  jal   insert_imageDL
/* 0BA504 7F087B14 00402025 */   move  $a0, $v0
/* 0BA508 7F087B18 0FC06FCC */  jal   insert_imageDL
/* 0BA50C 7F087B1C 00402025 */   move  $a0, $v0
/* 0BA510 7F087B20 10000013 */  b     .L7F087B70
/* 0BA514 7F087B24 AFA20080 */   sw    $v0, 0x80($sp)
.L7F087B28:
/* 0BA518 7F087B28 0FC2907A */  jal   cur_player_get_screen_setting
/* 0BA51C 7F087B2C 00000000 */   nop
/* 0BA520 7F087B30 24010001 */  li    $at, 1
/* 0BA524 7F087B34 14410009 */  bne   $v0, $at, .L7F087B5C
/* 0BA528 7F087B38 00000000 */   nop
/* 0BA52C 7F087B3C 0FC06FCC */  jal   insert_imageDL
/* 0BA530 7F087B40 8FA40080 */   lw    $a0, 0x80($sp)
/* 0BA534 7F087B44 0FC06FCC */  jal   insert_imageDL
/* 0BA538 7F087B48 00402025 */   move  $a0, $v0
/* 0BA53C 7F087B4C 0FC06FCC */  jal   insert_imageDL
/* 0BA540 7F087B50 00402025 */   move  $a0, $v0
/* 0BA544 7F087B54 10000006 */  b     .L7F087B70
/* 0BA548 7F087B58 AFA20080 */   sw    $v0, 0x80($sp)
.L7F087B5C:
/* 0BA54C 7F087B5C 0FC06FCC */  jal   insert_imageDL
/* 0BA550 7F087B60 8FA40080 */   lw    $a0, 0x80($sp)
/* 0BA554 7F087B64 0FC06FCC */  jal   insert_imageDL
/* 0BA558 7F087B68 00402025 */   move  $a0, $v0
/* 0BA55C 7F087B6C AFA20080 */  sw    $v0, 0x80($sp)
.L7F087B70:
/* 0BA560 7F087B70 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BA564 7F087B74 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BA568 7F087B78 24010001 */  li    $at, 1
/* 0BA56C 7F087B7C 3C0F8003 */  lui   $t7, %hi(D_80036830) # $t7, 0x8003
/* 0BA570 7F087B80 8C4E0000 */  lw    $t6, ($v0)
/* 0BA574 7F087B84 25EF1D80 */  addiu $t7, %lo(D_80036830) # addiu $t7, $t7, 0x1d80
/* 0BA578 7F087B88 55C1001B */  bnel  $t6, $at, .L7F087BF8
/* 0BA57C 7F087B8C 8DE10000 */   lw    $at, ($t7)
/* 0BA580 7F087B90 C4440004 */  lwc1  $f4, 4($v0)
/* 0BA584 7F087B94 E7A40074 */  swc1  $f4, 0x74($sp)
/* 0BA588 7F087B98 C4460008 */  lwc1  $f6, 8($v0)
/* 0BA58C 7F087B9C E7A60078 */  swc1  $f6, 0x78($sp)
/* 0BA590 7F087BA0 C448000C */  lwc1  $f8, 0xc($v0)
/* 0BA594 7F087BA4 E7A8007C */  swc1  $f8, 0x7c($sp)
/* 0BA598 7F087BA8 C4520004 */  lwc1  $f18, 4($v0)
/* 0BA59C 7F087BAC C44A0010 */  lwc1  $f10, 0x10($v0)
/* 0BA5A0 7F087BB0 46125101 */  sub.s $f4, $f10, $f18
/* 0BA5A4 7F087BB4 E7A40068 */  swc1  $f4, 0x68($sp)
/* 0BA5A8 7F087BB8 C4480008 */  lwc1  $f8, 8($v0)
/* 0BA5AC 7F087BBC C4460014 */  lwc1  $f6, 0x14($v0)
/* 0BA5B0 7F087BC0 46083281 */  sub.s $f10, $f6, $f8
/* 0BA5B4 7F087BC4 E7AA006C */  swc1  $f10, 0x6c($sp)
/* 0BA5B8 7F087BC8 C444000C */  lwc1  $f4, 0xc($v0)
/* 0BA5BC 7F087BCC C4520018 */  lwc1  $f18, 0x18($v0)
/* 0BA5C0 7F087BD0 46049181 */  sub.s $f6, $f18, $f4
/* 0BA5C4 7F087BD4 E7A60070 */  swc1  $f6, 0x70($sp)
/* 0BA5C8 7F087BD8 C448001C */  lwc1  $f8, 0x1c($v0)
/* 0BA5CC 7F087BDC E7A8005C */  swc1  $f8, 0x5c($sp)
/* 0BA5D0 7F087BE0 C44A0020 */  lwc1  $f10, 0x20($v0)
/* 0BA5D4 7F087BE4 E7AA0060 */  swc1  $f10, 0x60($sp)
/* 0BA5D8 7F087BE8 C4520024 */  lwc1  $f18, 0x24($v0)
/* 0BA5DC 7F087BEC 10000028 */  b     .L7F087C90
/* 0BA5E0 7F087BF0 E7B20064 */   swc1  $f18, 0x64($sp)
/* 0BA5E4 7F087BF4 8DE10000 */  lw    $at, ($t7)
.L7F087BF8:
/* 0BA5E8 7F087BF8 27A6004C */  addiu $a2, $sp, 0x4c
/* 0BA5EC 7F087BFC 24430488 */  addiu $v1, $v0, 0x488
/* 0BA5F0 7F087C00 ACC10000 */  sw    $at, ($a2)
/* 0BA5F4 7F087C04 8DE80004 */  lw    $t0, 4($t7)
/* 0BA5F8 7F087C08 2464002C */  addiu $a0, $v1, 0x2c
/* 0BA5FC 7F087C0C 24650038 */  addiu $a1, $v1, 0x38
/* 0BA600 7F087C10 ACC80004 */  sw    $t0, 4($a2)
/* 0BA604 7F087C14 8DE10008 */  lw    $at, 8($t7)
/* 0BA608 7F087C18 ACC10008 */  sw    $at, 8($a2)
/* 0BA60C 7F087C1C 8C4900D8 */  lw    $t1, 0xd8($v0)
/* 0BA610 7F087C20 55200006 */  bnezl $t1, .L7F087C3C
/* 0BA614 7F087C24 44806000 */   mtc1  $zero, $f12
/* 0BA618 7F087C28 0FC26F36 */  jal   sub_GAME_7F09C7C4
/* 0BA61C 7F087C2C AFA30058 */   sw    $v1, 0x58($sp)
/* 0BA620 7F087C30 10000005 */  b     .L7F087C48
/* 0BA624 7F087C34 8FA30058 */   lw    $v1, 0x58($sp)
/* 0BA628 7F087C38 44806000 */  mtc1  $zero, $f12
.L7F087C3C:
/* 0BA62C 7F087C3C 0C000D55 */  jal   viShake
/* 0BA630 7F087C40 AFA30058 */   sw    $v1, 0x58($sp)
/* 0BA634 7F087C44 8FA30058 */  lw    $v1, 0x58($sp)
.L7F087C48:
/* 0BA638 7F087C48 C464002C */  lwc1  $f4, 0x2c($v1)
/* 0BA63C 7F087C4C E7A40074 */  swc1  $f4, 0x74($sp)
/* 0BA640 7F087C50 C4660030 */  lwc1  $f6, 0x30($v1)
/* 0BA644 7F087C54 E7A60078 */  swc1  $f6, 0x78($sp)
/* 0BA648 7F087C58 C4680034 */  lwc1  $f8, 0x34($v1)
/* 0BA64C 7F087C5C E7A8007C */  swc1  $f8, 0x7c($sp)
/* 0BA650 7F087C60 C46A0038 */  lwc1  $f10, 0x38($v1)
/* 0BA654 7F087C64 E7AA0068 */  swc1  $f10, 0x68($sp)
/* 0BA658 7F087C68 C472003C */  lwc1  $f18, 0x3c($v1)
/* 0BA65C 7F087C6C E7B2006C */  swc1  $f18, 0x6c($sp)
/* 0BA660 7F087C70 C4640040 */  lwc1  $f4, 0x40($v1)
/* 0BA664 7F087C74 E7A40070 */  swc1  $f4, 0x70($sp)
/* 0BA668 7F087C78 C4660044 */  lwc1  $f6, 0x44($v1)
/* 0BA66C 7F087C7C E7A6005C */  swc1  $f6, 0x5c($sp)
/* 0BA670 7F087C80 C4680048 */  lwc1  $f8, 0x48($v1)
/* 0BA674 7F087C84 E7A80060 */  swc1  $f8, 0x60($sp)
/* 0BA678 7F087C88 C46A004C */  lwc1  $f10, 0x4c($v1)
/* 0BA67C 7F087C8C E7AA0064 */  swc1  $f10, 0x64($sp)
.L7F087C90:
/* 0BA680 7F087C90 27A40074 */  addiu $a0, $sp, 0x74
/* 0BA684 7F087C94 27A50068 */  addiu $a1, $sp, 0x68
/* 0BA688 7F087C98 0FC21DE3 */  jal   sub_GAME_7F0876C4
/* 0BA68C 7F087C9C 27A6005C */   addiu $a2, $sp, 0x5c
/* 0BA690 7F087CA0 27A40034 */  addiu $a0, $sp, 0x34
/* 0BA694 7F087CA4 0FC1A24E */  jal   sub_GAME_7F068190
/* 0BA698 7F087CA8 27A50040 */   addiu $a1, $sp, 0x40
/* 0BA69C 7F087CAC C7A00048 */  lwc1  $f0, 0x48($sp)
/* 0BA6A0 7F087CB0 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 0BA6A4 7F087CB4 C7B20044 */  lwc1  $f18, 0x44($sp)
/* 0BA6A8 7F087CB8 46000102 */  mul.s $f4, $f0, $f0
/* 0BA6AC 7F087CBC E7B20030 */  swc1  $f18, 0x30($sp)
/* 0BA6B0 7F087CC0 46021182 */  mul.s $f6, $f2, $f2
/* 0BA6B4 7F087CC4 0C007614 */  jal   sqrtf
/* 0BA6B8 7F087CC8 46062300 */   add.s $f12, $f4, $f6
/* 0BA6BC 7F087CCC 0FC22837 */  jal   get_curplay_vertical_rotation_in_degrees
/* 0BA6C0 7F087CD0 E7A0002C */   swc1  $f0, 0x2c($sp)
/* 0BA6C4 7F087CD4 E7A00020 */  swc1  $f0, 0x20($sp)
/* 0BA6C8 7F087CD8 C7AC0030 */  lwc1  $f12, 0x30($sp)
/* 0BA6CC 7F087CDC 0FC16BB8 */  jal   atan2f
/* 0BA6D0 7F087CE0 C7AE002C */   lwc1  $f14, 0x2c($sp)
/* 0BA6D4 7F087CE4 C7A80020 */  lwc1  $f8, 0x20($sp)
/* 0BA6D8 7F087CE8 3C018005 */  lui   $at, %hi(D_8005526C) # $at, 0x8005
/* 0BA6DC 7F087CEC C42AAE40 */  lwc1  $f10, %lo(D_8005526C)($at)
/* 0BA6E0 7F087CF0 46080080 */  add.s $f2, $f0, $f8
/* 0BA6E4 7F087CF4 3C018005 */  lui   $at, %hi(D_80055270) # $at, 0x8005
/* 0BA6E8 7F087CF8 3C0A8007 */  lui   $t2, %hi(g_CurrentPlayer) # $t2, 0x8007
/* 0BA6EC 7F087CFC 4602503E */  c.le.s $f10, $f2
/* 0BA6F0 7F087D00 46001406 */  mov.s $f16, $f2
/* 0BA6F4 7F087D04 45000003 */  bc1f  .L7F087D14
/* 0BA6F8 7F087D08 00000000 */   nop
/* 0BA6FC 7F087D0C C432AE44 */  lwc1  $f18, %lo(D_80055270)($at)
/* 0BA700 7F087D10 46121401 */  sub.s $f16, $f2, $f18
.L7F087D14:
/* 0BA704 7F087D14 8D4A8BC0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0BA708 7F087D18 E5502A00 */  swc1  $f16, 0x2a00($t2)
/* 0BA70C 7F087D1C C7AE0048 */  lwc1  $f14, 0x48($sp)
/* 0BA710 7F087D20 C7AC0040 */  lwc1  $f12, 0x40($sp)
/* 0BA714 7F087D24 46007387 */  neg.s $f14, $f14
/* 0BA718 7F087D28 0FC16BB8 */  jal   atan2f
/* 0BA71C 7F087D2C 46006307 */   neg.s $f12, $f12
/* 0BA720 7F087D30 3C018005 */  lui   $at, %hi(D_80055274) # $at, 0x8005
/* 0BA724 7F087D34 C424AE48 */  lwc1  $f4, %lo(D_80055274)($at)
/* 0BA728 7F087D38 46000086 */  mov.s $f2, $f0
/* 0BA72C 7F087D3C 3C018005 */  lui   $at, %hi(D_80055278) # $at, 0x8005
/* 0BA730 7F087D40 4600203E */  c.le.s $f4, $f0
/* 0BA734 7F087D44 3C0B8007 */  lui   $t3, %hi(g_CurrentPlayer) # $t3, 0x8007
/* 0BA738 7F087D48 45000003 */  bc1f  .L7F087D58
/* 0BA73C 7F087D4C 00000000 */   nop
/* 0BA740 7F087D50 C426AE4C */  lwc1  $f6, %lo(D_80055278)($at)
/* 0BA744 7F087D54 46060081 */  sub.s $f2, $f0, $f6
.L7F087D58:
/* 0BA748 7F087D58 8D6B8BC0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0BA74C 7F087D5C E5622A04 */  swc1  $f2, 0x2a04($t3)
/* 0BA750 7F087D60 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0BA754 7F087D64 8FA20080 */  lw    $v0, 0x80($sp)
/* 0BA758 7F087D68 27BD0080 */  addiu $sp, $sp, 0x80
/* 0BA75C 7F087D6C 03E00008 */  jr    $ra
/* 0BA760 7F087D70 00000000 */   nop
)
#endif
#endif




#ifdef NONMATCHING
s32 seems_to_load_cuff_microcode(s32 arg0, void *arg1, s32 arg2) {
    s32 sp40;
    s32 temp_a3;
    void *temp_a0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v0;
    s32 temp_ret;
    void *phi_a0;
    s32 phi_a3;
    s32 phi_v1;
    void *phi_a0_2;
    s32 phi_a2;
    s32 phi_v1_2;
    s32 phi_a3_2;
    s32 phi_v1_3;
    void *phi_a0_3;
    s32 phi_a2_2;
    s32 phi_v1_4;
    s32 phi_a3_3;
    void *phi_a0_4;
    s32 phi_a2_3;
    s32 phi_v1_5;
    s32 phi_a3_4;
    void *phi_a0_5;
    s32 phi_a2_4;
    s32 phi_v1_6;
    s32 phi_a3_5;
    s32 phi_return;

    // Node 0
    sp40 = getSelectedFolderBond();
    temp_a3 = (arg2 * 4);
    temp_a0 = (arg1->unk8 + temp_a3);
    phi_a0 = temp_a0;
    phi_a3 = temp_a3;
    if (*temp_a0 != 0)
    {
        // Node 1
        *modelGetNodeRwData(arg0, *temp_a0, arg1->unk8, temp_a3) = (s32) ((u32) (g_CurrentPlayer->field_41C ^ 3) < 1U);
        phi_a0 = (arg1->unk8 + sp1C);
        phi_a3 = sp1C;
    }
    // Node 2
    phi_a0_2 = phi_a0;
    phi_a2 = arg1->unk8;
    phi_v1_2 = arg2;
    phi_a3_2 = phi_a3;
    if (phi_a0->unk4 != 0)
    {
        // Node 3
        temp_v1 = ((u32) (g_CurrentPlayer->field_41C ^ 1) < 1U);
        phi_v1 = temp_v1;
        if (temp_v1 == 0)
        {
            // Node 4
            temp_v1_2 = ((u32) (g_CurrentPlayer->field_41C ^ 6) < 1U);
            phi_v1 = temp_v1_2;
            if (temp_v1_2 == 0)
            {
                // Node 5
                temp_v1_3 = ((u32) (g_CurrentPlayer->field_41C ^ 7) < 1U);
                phi_v1 = temp_v1_3;
                if (temp_v1_3 == 0)
                {
                    // Node 6
                    temp_v1_4 = ((u32) (g_CurrentPlayer->field_41C ^ 8) < 1U);
                    phi_v1 = temp_v1_4;
                    if (temp_v1_4 != 0)
                    {
                        // Node 7
                        phi_v1 = (0U < (u32) (sp40 ^ 1));
                    }
                }
            }
        }
        // Node 8
        *modelGetNodeRwData(arg0, *(arg1->unk8 + ((arg2 + 1) * 4)), arg1->unk8, phi_a3) = (s32) phi_v1;
        phi_a0_2 = (arg1->unk8 + sp1C);
        phi_a2 = arg1->unk8;
        phi_v1_2 = arg2;
        phi_a3_2 = sp1C;
    }
    // Node 9
    phi_a0_3 = phi_a0_2;
    phi_a2_2 = phi_a2;
    phi_v1_4 = phi_v1_2;
    phi_a3_3 = phi_a3_2;
    if (phi_a0_2->unk8 != 0)
    {
        // Node 10
        temp_v1_5 = ((u32) (g_CurrentPlayer->field_41C ^ 5) < 1U);
        phi_v1_3 = temp_v1_5;
        if (temp_v1_5 == 0)
        {
            // Node 11
            temp_v1_6 = ((u32) (g_CurrentPlayer->field_41C ^ 8) < 1U);
            phi_v1_3 = temp_v1_6;
            if (temp_v1_6 != 0)
            {
                // Node 12
                phi_v1_3 = ((u32) (sp40 ^ 1) < 1U);
            }
        }
        // Node 13
        *modelGetNodeRwData(arg0, *(phi_a2 + ((phi_v1_2 + 2) * 4)), phi_a2, phi_a3_2) = (s32) phi_v1_3;
        phi_a0_3 = (arg1->unk8 + sp1C);
        phi_a2_2 = arg1->unk8;
        phi_v1_4 = arg2;
        phi_a3_3 = sp1C;
    }
    // Node 14
    phi_a0_4 = phi_a0_3;
    phi_a2_3 = phi_a2_2;
    phi_v1_5 = phi_v1_4;
    phi_a3_4 = phi_a3_3;
    if (phi_a0_3->unkC != 0)
    {
        // Node 15
        *modelGetNodeRwData(arg0, *(phi_a2_2 + ((phi_v1_4 + 3) * 4)), phi_a2_2, phi_a3_3) = (s32) ((u32) g_CurrentPlayer->field_41C < 1U);
        phi_a0_4 = (arg1->unk8 + sp1C);
        phi_a2_3 = arg1->unk8;
        phi_v1_5 = arg2;
        phi_a3_4 = sp1C;
    }
    // Node 16
    phi_a0_5 = phi_a0_4;
    phi_a2_4 = phi_a2_3;
    phi_v1_6 = phi_v1_5;
    phi_a3_5 = phi_a3_4;
    if (phi_a0_4->unk10 != 0)
    {
        // Node 17
        *modelGetNodeRwData(arg0, *(phi_a2_3 + ((phi_v1_5 + 4) * 4)), phi_a2_3, phi_a3_4) = (s32) ((u32) (g_CurrentPlayer->field_41C ^ 2) < 1U);
        phi_a0_5 = (arg1->unk8 + sp1C);
        phi_a2_4 = arg1->unk8;
        phi_v1_6 = arg2;
        phi_a3_5 = sp1C;
    }
    // Node 18
    temp_v0 = (phi_v1_6 + 5);
    phi_return = temp_v0;
    if (phi_a0_5->unk14 != 0)
    {
        // Node 19
        temp_ret = modelGetNodeRwData(arg0, *(phi_a2_4 + (temp_v0 * 4)), phi_a2_4, phi_a3_5);
        *temp_ret = (s32) ((u32) (g_CurrentPlayer->field_41C ^ 4) < 1U);
        phi_return = temp_ret;
    }
    // Node 20
    return phi_return;
}
#else
GLOBAL_ASM(
.text
glabel seems_to_load_cuff_microcode
/* 0BC744 7F087C14 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0BC748 7F087C18 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0BC74C 7F087C1C AFA40048 */  sw    $a0, 0x48($sp)
/* 0BC750 7F087C20 AFA5004C */  sw    $a1, 0x4c($sp)
/* 0BC754 7F087C24 0FC0755B */  jal   getSelectedFolderBond
/* 0BC758 7F087C28 AFA60050 */   sw    $a2, 0x50($sp)
/* 0BC75C 7F087C2C 8FAE004C */  lw    $t6, 0x4c($sp)
/* 0BC760 7F087C30 8FA30050 */  lw    $v1, 0x50($sp)
/* 0BC764 7F087C34 AFA20040 */  sw    $v0, 0x40($sp)
/* 0BC768 7F087C38 8DC60008 */  lw    $a2, 8($t6)
/* 0BC76C 7F087C3C 00033880 */  sll   $a3, $v1, 2
/* 0BC770 7F087C40 00C72021 */  addu  $a0, $a2, $a3
/* 0BC774 7F087C44 8C850000 */  lw    $a1, ($a0)
/* 0BC778 7F087C48 50A00010 */  beql  $a1, $zero, .L7F087C8C
/* 0BC77C 7F087C4C 8C890004 */   lw    $t1, 4($a0)
/* 0BC780 7F087C50 8FA40048 */  lw    $a0, 0x48($sp)
/* 0BC784 7F087C54 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0BC788 7F087C58 AFA7001C */   sw    $a3, 0x1c($sp)
/* 0BC78C 7F087C5C 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer)
/* 0BC790 7F087C60 8DEFA0B0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0BC794 7F087C64 8FA7001C */  lw    $a3, 0x1c($sp)
/* 0BC798 7F087C68 8DF8041C */  lw    $t8, 0x41c($t7)
/* 0BC79C 7F087C6C 3B190003 */  xori  $t9, $t8, 3
/* 0BC7A0 7F087C70 2F390001 */  sltiu $t9, $t9, 1
/* 0BC7A4 7F087C74 AC590000 */  sw    $t9, ($v0)
/* 0BC7A8 7F087C78 8FA8004C */  lw    $t0, 0x4c($sp)
/* 0BC7AC 7F087C7C 8FA30050 */  lw    $v1, 0x50($sp)
/* 0BC7B0 7F087C80 8D060008 */  lw    $a2, 8($t0)
/* 0BC7B4 7F087C84 00C72021 */  addu  $a0, $a2, $a3
/* 0BC7B8 7F087C88 8C890004 */  lw    $t1, 4($a0)
.L7F087C8C:
/* 0BC7BC 7F087C8C 24620001 */  addiu $v0, $v1, 1
/* 0BC7C0 7F087C90 00025080 */  sll   $t2, $v0, 2
/* 0BC7C4 7F087C94 11200021 */  beqz  $t1, .L7F087D1C
/* 0BC7C8 7F087C98 00CA5821 */   addu  $t3, $a2, $t2
/* 0BC7CC 7F087C9C 8D650000 */  lw    $a1, ($t3)
/* 0BC7D0 7F087CA0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 0BC7D4 7F087CA4 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0BC7D8 7F087CA8 8FA40048 */   lw    $a0, 0x48($sp)
/* 0BC7DC 7F087CAC 3C0C8008 */  lui   $t4, %hi(g_CurrentPlayer)
/* 0BC7E0 7F087CB0 8D8CA0B0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0BC7E4 7F087CB4 8FA7001C */  lw    $a3, 0x1c($sp)
/* 0BC7E8 7F087CB8 8D84041C */  lw    $a0, 0x41c($t4)
/* 0BC7EC 7F087CBC 38830001 */  xori  $v1, $a0, 1
/* 0BC7F0 7F087CC0 2C630001 */  sltiu $v1, $v1, 1
/* 0BC7F4 7F087CC4 54600011 */  bnezl $v1, .L7F087D0C
/* 0BC7F8 7F087CC8 AC430000 */   sw    $v1, ($v0)
/* 0BC7FC 7F087CCC 38830006 */  xori  $v1, $a0, 6
/* 0BC800 7F087CD0 2C630001 */  sltiu $v1, $v1, 1
/* 0BC804 7F087CD4 5460000D */  bnezl $v1, .L7F087D0C
/* 0BC808 7F087CD8 AC430000 */   sw    $v1, ($v0)
/* 0BC80C 7F087CDC 38830007 */  xori  $v1, $a0, 7
/* 0BC810 7F087CE0 2C630001 */  sltiu $v1, $v1, 1
/* 0BC814 7F087CE4 54600009 */  bnezl $v1, .L7F087D0C
/* 0BC818 7F087CE8 AC430000 */   sw    $v1, ($v0)
/* 0BC81C 7F087CEC 38830008 */  xori  $v1, $a0, 8
/* 0BC820 7F087CF0 2C630001 */  sltiu $v1, $v1, 1
/* 0BC824 7F087CF4 50600005 */  beql  $v1, $zero, .L7F087D0C
/* 0BC828 7F087CF8 AC430000 */   sw    $v1, ($v0)
/* 0BC82C 7F087CFC 8FA30040 */  lw    $v1, 0x40($sp)
/* 0BC830 7F087D00 386D0001 */  xori  $t5, $v1, 1
/* 0BC834 7F087D04 000D182B */  sltu  $v1, $zero, $t5
/* 0BC838 7F087D08 AC430000 */  sw    $v1, ($v0)
.L7F087D0C:
/* 0BC83C 7F087D0C 8FAE004C */  lw    $t6, 0x4c($sp)
/* 0BC840 7F087D10 8FA30050 */  lw    $v1, 0x50($sp)
/* 0BC844 7F087D14 8DC60008 */  lw    $a2, 8($t6)
/* 0BC848 7F087D18 00C72021 */  addu  $a0, $a2, $a3
.L7F087D1C:
/* 0BC84C 7F087D1C 8C8F0008 */  lw    $t7, 8($a0)
/* 0BC850 7F087D20 24620002 */  addiu $v0, $v1, 2
/* 0BC854 7F087D24 0002C080 */  sll   $t8, $v0, 2
/* 0BC858 7F087D28 11E00019 */  beqz  $t7, .L7F087D90
/* 0BC85C 7F087D2C 00D8C821 */   addu  $t9, $a2, $t8
/* 0BC860 7F087D30 8F250000 */  lw    $a1, ($t9)
/* 0BC864 7F087D34 AFA7001C */  sw    $a3, 0x1c($sp)
/* 0BC868 7F087D38 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0BC86C 7F087D3C 8FA40048 */   lw    $a0, 0x48($sp)
/* 0BC870 7F087D40 3C088008 */  lui   $t0, %hi(g_CurrentPlayer)
/* 0BC874 7F087D44 8D08A0B0 */  lw    $t0, %lo(g_CurrentPlayer)($t0)
/* 0BC878 7F087D48 8FA7001C */  lw    $a3, 0x1c($sp)
/* 0BC87C 7F087D4C 8D04041C */  lw    $a0, 0x41c($t0)
/* 0BC880 7F087D50 38830005 */  xori  $v1, $a0, 5
/* 0BC884 7F087D54 2C630001 */  sltiu $v1, $v1, 1
/* 0BC888 7F087D58 54600009 */  bnezl $v1, .L7F087D80
/* 0BC88C 7F087D5C AC430000 */   sw    $v1, ($v0)
/* 0BC890 7F087D60 38830008 */  xori  $v1, $a0, 8
/* 0BC894 7F087D64 2C630001 */  sltiu $v1, $v1, 1
/* 0BC898 7F087D68 50600005 */  beql  $v1, $zero, .L7F087D80
/* 0BC89C 7F087D6C AC430000 */   sw    $v1, ($v0)
/* 0BC8A0 7F087D70 8FA30040 */  lw    $v1, 0x40($sp)
/* 0BC8A4 7F087D74 38690001 */  xori  $t1, $v1, 1
/* 0BC8A8 7F087D78 2D230001 */  sltiu $v1, $t1, 1
/* 0BC8AC 7F087D7C AC430000 */  sw    $v1, ($v0)
.L7F087D80:
/* 0BC8B0 7F087D80 8FAA004C */  lw    $t2, 0x4c($sp)
/* 0BC8B4 7F087D84 8FA30050 */  lw    $v1, 0x50($sp)
/* 0BC8B8 7F087D88 8D460008 */  lw    $a2, 8($t2)
/* 0BC8BC 7F087D8C 00C72021 */  addu  $a0, $a2, $a3
.L7F087D90:
/* 0BC8C0 7F087D90 8C8B000C */  lw    $t3, 0xc($a0)
/* 0BC8C4 7F087D94 24620003 */  addiu $v0, $v1, 3
/* 0BC8C8 7F087D98 00026080 */  sll   $t4, $v0, 2
/* 0BC8CC 7F087D9C 1160000F */  beqz  $t3, .L7F087DDC
/* 0BC8D0 7F087DA0 00CC6821 */   addu  $t5, $a2, $t4
/* 0BC8D4 7F087DA4 8DA50000 */  lw    $a1, ($t5)
/* 0BC8D8 7F087DA8 AFA7001C */  sw    $a3, 0x1c($sp)
/* 0BC8DC 7F087DAC 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0BC8E0 7F087DB0 8FA40048 */   lw    $a0, 0x48($sp)
/* 0BC8E4 7F087DB4 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0BC8E8 7F087DB8 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BC8EC 7F087DBC 8FA7001C */  lw    $a3, 0x1c($sp)
/* 0BC8F0 7F087DC0 8DCF041C */  lw    $t7, 0x41c($t6)
/* 0BC8F4 7F087DC4 2DF80001 */  sltiu $t8, $t7, 1
/* 0BC8F8 7F087DC8 AC580000 */  sw    $t8, ($v0)
/* 0BC8FC 7F087DCC 8FB9004C */  lw    $t9, 0x4c($sp)
/* 0BC900 7F087DD0 8FA30050 */  lw    $v1, 0x50($sp)
/* 0BC904 7F087DD4 8F260008 */  lw    $a2, 8($t9)
/* 0BC908 7F087DD8 00C72021 */  addu  $a0, $a2, $a3
.L7F087DDC:
/* 0BC90C 7F087DDC 8C880010 */  lw    $t0, 0x10($a0)
/* 0BC910 7F087DE0 24620004 */  addiu $v0, $v1, 4
/* 0BC914 7F087DE4 00024880 */  sll   $t1, $v0, 2
/* 0BC918 7F087DE8 11000010 */  beqz  $t0, .L7F087E2C
/* 0BC91C 7F087DEC 00C95021 */   addu  $t2, $a2, $t1
/* 0BC920 7F087DF0 8D450000 */  lw    $a1, ($t2)
/* 0BC924 7F087DF4 AFA7001C */  sw    $a3, 0x1c($sp)
/* 0BC928 7F087DF8 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0BC92C 7F087DFC 8FA40048 */   lw    $a0, 0x48($sp)
/* 0BC930 7F087E00 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer)
/* 0BC934 7F087E04 8D6BA0B0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0BC938 7F087E08 8FA7001C */  lw    $a3, 0x1c($sp)
/* 0BC93C 7F087E0C 8D6C041C */  lw    $t4, 0x41c($t3)
/* 0BC940 7F087E10 398D0002 */  xori  $t5, $t4, 2
/* 0BC944 7F087E14 2DAD0001 */  sltiu $t5, $t5, 1
/* 0BC948 7F087E18 AC4D0000 */  sw    $t5, ($v0)
/* 0BC94C 7F087E1C 8FAE004C */  lw    $t6, 0x4c($sp)
/* 0BC950 7F087E20 8FA30050 */  lw    $v1, 0x50($sp)
/* 0BC954 7F087E24 8DC60008 */  lw    $a2, 8($t6)
/* 0BC958 7F087E28 00C72021 */  addu  $a0, $a2, $a3
.L7F087E2C:
/* 0BC95C 7F087E2C 8C8F0014 */  lw    $t7, 0x14($a0)
/* 0BC960 7F087E30 24620005 */  addiu $v0, $v1, 5
/* 0BC964 7F087E34 0002C080 */  sll   $t8, $v0, 2
/* 0BC968 7F087E38 11E0000A */  beqz  $t7, .L7F087E64
/* 0BC96C 7F087E3C 8FA40048 */   lw    $a0, 0x48($sp)
/* 0BC970 7F087E40 00D8C821 */  addu  $t9, $a2, $t8
/* 0BC974 7F087E44 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0BC978 7F087E48 8F250000 */   lw    $a1, ($t9)
/* 0BC97C 7F087E4C 3C088008 */  lui   $t0, %hi(g_CurrentPlayer)
/* 0BC980 7F087E50 8D08A0B0 */  lw    $t0, %lo(g_CurrentPlayer)($t0)
/* 0BC984 7F087E54 8D09041C */  lw    $t1, 0x41c($t0)
/* 0BC988 7F087E58 392A0004 */  xori  $t2, $t1, 4
/* 0BC98C 7F087E5C 2D4A0001 */  sltiu $t2, $t2, 1
/* 0BC990 7F087E60 AC4A0000 */  sw    $t2, ($v0)
.L7F087E64:
/* 0BC994 7F087E64 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0BC998 7F087E68 27BD0048 */  addiu $sp, $sp, 0x48
/* 0BC99C 7F087E6C 03E00008 */  jr    $ra
/* 0BC9A0 7F087E70 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F087E74(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_8005527C
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055280
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F087E74
/* 0BC9A4 7F087E74 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BC9A8 7F087E78 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC9AC 7F087E7C 27BDFE08 */  addiu $sp, $sp, -0x1f8
/* 0BC9B0 7F087E80 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0BC9B4 7F087E84 AFA401F8 */  sw    $a0, 0x1f8($sp)
/* 0BC9B8 7F087E88 8C4E01C8 */  lw    $t6, 0x1c8($v0)
/* 0BC9BC 7F087E8C 51C001DE */  beql  $t6, $zero, .L7F088608
/* 0BC9C0 7F087E90 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0BC9C4 7F087E94 8C4F0200 */  lw    $t7, 0x200($v0)
/* 0BC9C8 7F087E98 3C198003 */  lui   $t9, %hi(D_8003683C)
/* 0BC9CC 7F087E9C 2739683C */  addiu $t9, %lo(D_8003683C) # addiu $t9, $t9, 0x683c
/* 0BC9D0 7F087EA0 11E001D8 */  beqz  $t7, .L7F088604
/* 0BC9D4 7F087EA4 27B801B8 */   addiu $t8, $sp, 0x1b8
/* 0BC9D8 7F087EA8 272B003C */  addiu $t3, $t9, 0x3c
.L7F087EAC:
/* 0BC9DC 7F087EAC 8F210000 */  lw    $at, ($t9)
/* 0BC9E0 7F087EB0 2739000C */  addiu $t9, $t9, 0xc
/* 0BC9E4 7F087EB4 2718000C */  addiu $t8, $t8, 0xc
/* 0BC9E8 7F087EB8 AF01FFF4 */  sw    $at, -0xc($t8)
/* 0BC9EC 7F087EBC 8F21FFF8 */  lw    $at, -8($t9)
/* 0BC9F0 7F087EC0 AF01FFF8 */  sw    $at, -8($t8)
/* 0BC9F4 7F087EC4 8F21FFFC */  lw    $at, -4($t9)
/* 0BC9F8 7F087EC8 172BFFF8 */  bne   $t9, $t3, .L7F087EAC
/* 0BC9FC 7F087ECC AF01FFFC */   sw    $at, -4($t8)
/* 0BCA00 7F087ED0 8F210000 */  lw    $at, ($t9)
/* 0BCA04 7F087ED4 3C0D8003 */  lui   $t5, %hi(D_8003687C)
/* 0BCA08 7F087ED8 25AD687C */  addiu $t5, %lo(D_8003687C) # addiu $t5, $t5, 0x687c
/* 0BCA0C 7F087EDC AF010000 */  sw    $at, ($t8)
/* 0BCA10 7F087EE0 8DA10000 */  lw    $at, ($t5)
/* 0BCA14 7F087EE4 27AC016C */  addiu $t4, $sp, 0x16c
/* 0BCA18 7F087EE8 8DAF0004 */  lw    $t7, 4($t5)
/* 0BCA1C 7F087EEC AD810000 */  sw    $at, ($t4)
/* 0BCA20 7F087EF0 8DA10008 */  lw    $at, 8($t5)
/* 0BCA24 7F087EF4 24040001 */  li    $a0, 1
/* 0BCA28 7F087EF8 AD8F0004 */  sw    $t7, 4($t4)
/* 0BCA2C 7F087EFC 0FC173C6 */  jal   get_ptr_itemheader_in_hand
/* 0BCA30 7F087F00 AD810008 */   sw    $at, 8($t4)
/* 0BCA34 7F087F04 AFA20160 */  sw    $v0, 0x160($sp)
/* 0BCA38 7F087F08 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0BCA3C 7F087F0C 8C4A0008 */  lw    $t2, 8($v0)
/* 0BCA40 7F087F10 8C84A0B0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BCA44 7F087F14 8D45000C */  lw    $a1, 0xc($t2)
/* 0BCA48 7F087F18 0FC1B1E7 */  jal   modelGetNodeRwData
/* 0BCA4C 7F087F1C 24840230 */   addiu $a0, $a0, 0x230
/* 0BCA50 7F087F20 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0BCA54 7F087F24 AFA20158 */   sw    $v0, 0x158($sp)
/* 0BCA58 7F087F28 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0BCA5C 7F087F2C 44812000 */  mtc1  $at, $f4
/* 0BCA60 7F087F30 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer)
/* 0BCA64 7F087F34 8D6BA0B0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0BCA68 7F087F38 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0BCA6C 7F087F3C 44813000 */  mtc1  $at, $f6
/* 0BCA70 7F087F40 AFA20154 */  sw    $v0, 0x154($sp)
/* 0BCA74 7F087F44 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BCA78 7F087F48 44814000 */  mtc1  $at, $f8
/* 0BCA7C 7F087F4C 8D6611C4 */  lw    $a2, 0x11c4($t3)
/* 0BCA80 7F087F50 3C073FBA */  lui   $a3, (0x3FBA2E8C >> 16) # lui $a3, 0x3fba
/* 0BCA84 7F087F54 34E72E8C */  ori   $a3, (0x3FBA2E8C & 0xFFFF) # ori $a3, $a3, 0x2e8c
/* 0BCA88 7F087F58 00402025 */  move  $a0, $v0
/* 0BCA8C 7F087F5C 27A50152 */  addiu $a1, $sp, 0x152
/* 0BCA90 7F087F60 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0BCA94 7F087F64 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0BCA98 7F087F68 0C003FAC */  jal   guPerspective
/* 0BCA9C 7F087F6C E7A80018 */   swc1  $f8, 0x18($sp)
/* 0BCAA0 7F087F70 8FA301F8 */  lw    $v1, 0x1f8($sp)
/* 0BCAA4 7F087F74 3C190103 */  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
/* 0BCAA8 7F087F78 37390040 */  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 0BCAAC 7F087F7C AC790000 */  sw    $t9, ($v1)
/* 0BCAB0 7F087F80 8FB80154 */  lw    $t8, 0x154($sp)
/* 0BCAB4 7F087F84 3C01C140 */  li    $at, 0xC1400000 # -12.000000
/* 0BCAB8 7F087F88 44810000 */  mtc1  $at, $f0
/* 0BCABC 7F087F8C 3C018000 */  lui   $at, 0x8000
/* 0BCAC0 7F087F90 3C0CBC00 */  lui   $t4, (0xBC00000E >> 16) # lui $t4, 0xbc00
/* 0BCAC4 7F087F94 03017021 */  addu  $t6, $t8, $at
/* 0BCAC8 7F087F98 358C000E */  ori   $t4, (0xBC00000E & 0xFFFF) # ori $t4, $t4, 0xe
/* 0BCACC 7F087F9C AC6E0004 */  sw    $t6, 4($v1)
/* 0BCAD0 7F087FA0 24670008 */  addiu $a3, $v1, 8
/* 0BCAD4 7F087FA4 ACEC0000 */  sw    $t4, ($a3)
/* 0BCAD8 7F087FA8 97AD0152 */  lhu   $t5, 0x152($sp)
/* 0BCADC 7F087FAC 3C088008 */  lui   $t0, %hi(g_CurrentPlayer)
/* 0BCAE0 7F087FB0 2508A0B0 */  addiu $t0, %lo(g_CurrentPlayer) # addiu $t0, $t0, -0x5f50
/* 0BCAE4 7F087FB4 ACED0004 */  sw    $t5, 4($a3)
/* 0BCAE8 7F087FB8 8D0F0000 */  lw    $t7, ($t0)
/* 0BCAEC 7F087FBC 8FAB0158 */  lw    $t3, 0x158($sp)
/* 0BCAF0 7F087FC0 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0BCAF4 7F087FC4 8DEA01CC */  lw    $t2, 0x1cc($t7)
/* 0BCAF8 7F087FC8 24E90008 */  addiu $t1, $a3, 8
/* 0BCAFC 7F087FCC 27A4016C */  addiu $a0, $sp, 0x16c
/* 0BCB00 7F087FD0 AD6A0000 */  sw    $t2, ($t3)
/* 0BCB04 7F087FD4 8D020000 */  lw    $v0, ($t0)
/* 0BCB08 7F087FD8 27A60178 */  addiu $a2, $sp, 0x178
/* 0BCB0C 7F087FDC C444054C */  lwc1  $f4, 0x54c($v0)
/* 0BCB10 7F087FE0 C44A0498 */  lwc1  $f10, 0x498($v0)
/* 0BCB14 7F087FE4 46002180 */  add.s $f6, $f4, $f0
/* 0BCB18 7F087FE8 C4440544 */  lwc1  $f4, 0x544($v0)
/* 0BCB1C 7F087FEC 46065202 */  mul.s $f8, $f10, $f6
/* 0BCB20 7F087FF0 C44A04A0 */  lwc1  $f10, 0x4a0($v0)
/* 0BCB24 7F087FF4 46005187 */  neg.s $f6, $f10
/* 0BCB28 7F087FF8 46062282 */  mul.s $f10, $f4, $f6
/* 0BCB2C 7F087FFC C444048C */  lwc1  $f4, 0x48c($v0)
/* 0BCB30 7F088000 460A2180 */  add.s $f6, $f4, $f10
/* 0BCB34 7F088004 46064100 */  add.s $f4, $f8, $f6
/* 0BCB38 7F088008 E7A4016C */  swc1  $f4, 0x16c($sp)
/* 0BCB3C 7F08800C C4480490 */  lwc1  $f8, 0x490($v0)
/* 0BCB40 7F088010 C44A0548 */  lwc1  $f10, 0x548($v0)
/* 0BCB44 7F088014 46085180 */  add.s $f6, $f10, $f8
/* 0BCB48 7F088018 E7A60170 */  swc1  $f6, 0x170($sp)
/* 0BCB4C 7F08801C C44A054C */  lwc1  $f10, 0x54c($v0)
/* 0BCB50 7F088020 C44404A0 */  lwc1  $f4, 0x4a0($v0)
/* 0BCB54 7F088024 46005200 */  add.s $f8, $f10, $f0
/* 0BCB58 7F088028 C44A0544 */  lwc1  $f10, 0x544($v0)
/* 0BCB5C 7F08802C 46082182 */  mul.s $f6, $f4, $f8
/* 0BCB60 7F088030 C4440498 */  lwc1  $f4, 0x498($v0)
/* 0BCB64 7F088034 46045202 */  mul.s $f8, $f10, $f4
/* 0BCB68 7F088038 C44A0494 */  lwc1  $f10, 0x494($v0)
/* 0BCB6C 7F08803C 46085100 */  add.s $f4, $f10, $f8
/* 0BCB70 7F088040 44814000 */  mtc1  $at, $f8
/* 0BCB74 7F088044 3C018005 */  lui   $at, %hi(D_8005527C)
/* 0BCB78 7F088048 46043280 */  add.s $f10, $f6, $f4
/* 0BCB7C 7F08804C E7AA0174 */  swc1  $f10, 0x174($sp)
/* 0BCB80 7F088050 C4460148 */  lwc1  $f6, 0x148($v0)
/* 0BCB84 7F088054 C42A527C */  lwc1  $f10, %lo(D_8005527C)($at)
/* 0BCB88 7F088058 AFA901F8 */  sw    $t1, 0x1f8($sp)
/* 0BCB8C 7F08805C 46064101 */  sub.s $f4, $f8, $f6
/* 0BCB90 7F088060 460A2202 */  mul.s $f8, $f4, $f10
/* 0BCB94 7F088064 44054000 */  mfc1  $a1, $f8
/* 0BCB98 7F088068 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BCB9C 7F08806C 00000000 */   nop
/* 0BCBA0 7F088070 0FC1E0F1 */  jal   camGetWorldToScreenMtxf
/* 0BCBA4 7F088074 00000000 */   nop
/* 0BCBA8 7F088078 00402025 */  move  $a0, $v0
/* 0BCBAC 7F08807C 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0BCBB0 7F088080 27A50178 */   addiu $a1, $sp, 0x178
/* 0BCBB4 7F088084 8FB90160 */  lw    $t9, 0x160($sp)
/* 0BCBB8 7F088088 8724000E */  lh    $a0, 0xe($t9)
/* 0BCBBC 7F08808C 0004C180 */  sll   $t8, $a0, 6
/* 0BCBC0 7F088090 0FC2F5C5 */  jal   dynAllocate
/* 0BCBC4 7F088094 03002025 */   move  $a0, $t8
/* 0BCBC8 7F088098 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0BCBCC 7F08809C 8C84A0B0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BCBD0 7F0880A0 AFA20164 */  sw    $v0, 0x164($sp)
/* 0BCBD4 7F0880A4 8FA50160 */  lw    $a1, 0x160($sp)
/* 0BCBD8 7F0880A8 24060004 */  li    $a2, 4
/* 0BCBDC 7F0880AC 0FC21F05 */  jal   seems_to_load_cuff_microcode
/* 0BCBE0 7F0880B0 24840230 */   addiu $a0, $a0, 0x230
/* 0BCBE4 7F0880B4 3C058008 */  lui   $a1, %hi(g_CurrentPlayer)
/* 0BCBE8 7F0880B8 8FAC0164 */  lw    $t4, 0x164($sp)
/* 0BCBEC 7F0880BC 8CA5A0B0 */  lw    $a1, %lo(g_CurrentPlayer)($a1)
/* 0BCBF0 7F0880C0 27AE0178 */  addiu $t6, $sp, 0x178
/* 0BCBF4 7F0880C4 AFAE01B8 */  sw    $t6, 0x1b8($sp)
/* 0BCBF8 7F0880C8 27A401B8 */  addiu $a0, $sp, 0x1b8
/* 0BCBFC 7F0880CC AFAC01C8 */  sw    $t4, 0x1c8($sp)
/* 0BCC00 7F0880D0 0FC1BCBE */  jal   subcalcmatrices
/* 0BCC04 7F0880D4 24A50230 */   addiu $a1, $a1, 0x230
/* 0BCC08 7F0880D8 8FAD0160 */  lw    $t5, 0x160($sp)
/* 0BCC0C 7F0880DC 3C0B8008 */  lui   $t3, %hi(watch_time_0)
/* 0BCC10 7F0880E0 8D6B9A24 */  lw    $t3, %lo(watch_time_0)($t3)
/* 0BCC14 7F0880E4 8DAF0008 */  lw    $t7, 8($t5)
/* 0BCC18 7F0880E8 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BCC1C 7F0880EC 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BCC20 7F0880F0 8DEA0000 */  lw    $t2, ($t7)
/* 0BCC24 7F0880F4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BCC28 7F0880F8 44810000 */  mtc1  $at, $f0
/* 0BCC2C 7F0880FC 8D430004 */  lw    $v1, 4($t2)
/* 0BCC30 7F088100 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 0BCC34 7F088104 AFAB0090 */  sw    $t3, 0x90($sp)
/* 0BCC38 7F088108 44812000 */  mtc1  $at, $f4
/* 0BCC3C 7F08810C C4460258 */  lwc1  $f6, 0x258($v0)
/* 0BCC40 7F088110 46043383 */  div.s $f14, $f6, $f4
/* 0BCC44 7F088114 460E003C */  c.lt.s $f0, $f14
/* 0BCC48 7F088118 00000000 */  nop
/* 0BCC4C 7F08811C 45020003 */  bc1fl .L7F08812C
/* 0BCC50 7F088120 C46A0000 */   lwc1  $f10, ($v1)
/* 0BCC54 7F088124 46000386 */  mov.s $f14, $f0
/* 0BCC58 7F088128 C46A0000 */  lwc1  $f10, ($v1)
.L7F08812C:
/* 0BCC5C 7F08812C C4480244 */  lwc1  $f8, 0x244($v0)
/* 0BCC60 7F088130 C44401D4 */  lwc1  $f4, 0x1d4($v0)
/* 0BCC64 7F088134 8FA80164 */  lw    $t0, 0x164($sp)
/* 0BCC68 7F088138 46085182 */  mul.s $f6, $f10, $f8
/* 0BCC6C 7F08813C 44808000 */  mtc1  $zero, $f16
/* 0BCC70 7F088140 C5000030 */  lwc1  $f0, 0x30($t0)
/* 0BCC74 7F088144 27A40108 */  addiu $a0, $sp, 0x108
/* 0BCC78 7F088148 44058000 */  mfc1  $a1, $f16
/* 0BCC7C 7F08814C 44068000 */  mfc1  $a2, $f16
/* 0BCC80 7F088150 44078000 */  mfc1  $a3, $f16
/* 0BCC84 7F088154 46062281 */  sub.s $f10, $f4, $f6
/* 0BCC88 7F088158 46005201 */  sub.s $f8, $f10, $f0
/* 0BCC8C 7F08815C 460E4102 */  mul.s $f4, $f8, $f14
/* 0BCC90 7F088160 46002180 */  add.s $f6, $f4, $f0
/* 0BCC94 7F088164 E7A600B4 */  swc1  $f6, 0xb4($sp)
/* 0BCC98 7F088168 C4480244 */  lwc1  $f8, 0x244($v0)
/* 0BCC9C 7F08816C C46A0008 */  lwc1  $f10, 8($v1)
/* 0BCCA0 7F088170 C44601D8 */  lwc1  $f6, 0x1d8($v0)
/* 0BCCA4 7F088174 C5020034 */  lwc1  $f2, 0x34($t0)
/* 0BCCA8 7F088178 46085102 */  mul.s $f4, $f10, $f8
/* 0BCCAC 7F08817C 46043280 */  add.s $f10, $f6, $f4
/* 0BCCB0 7F088180 46025201 */  sub.s $f8, $f10, $f2
/* 0BCCB4 7F088184 460E4182 */  mul.s $f6, $f8, $f14
/* 0BCCB8 7F088188 46023100 */  add.s $f4, $f6, $f2
/* 0BCCBC 7F08818C E7A400B8 */  swc1  $f4, 0xb8($sp)
/* 0BCCC0 7F088190 C4480244 */  lwc1  $f8, 0x244($v0)
/* 0BCCC4 7F088194 C46A0004 */  lwc1  $f10, 4($v1)
/* 0BCCC8 7F088198 C44401DC */  lwc1  $f4, 0x1dc($v0)
/* 0BCCCC 7F08819C C50C0038 */  lwc1  $f12, 0x38($t0)
/* 0BCCD0 7F0881A0 46085182 */  mul.s $f6, $f10, $f8
/* 0BCCD4 7F0881A4 46062281 */  sub.s $f10, $f4, $f6
/* 0BCCD8 7F0881A8 460C5201 */  sub.s $f8, $f10, $f12
/* 0BCCDC 7F0881AC 460E4102 */  mul.s $f4, $f8, $f14
/* 0BCCE0 7F0881B0 460C2180 */  add.s $f6, $f4, $f12
/* 0BCCE4 7F0881B4 E7A600BC */  swc1  $f6, 0xbc($sp)
/* 0BCCE8 7F0881B8 C44A01E0 */  lwc1  $f10, 0x1e0($v0)
/* 0BCCEC 7F0881BC E7AA0010 */  swc1  $f10, 0x10($sp)
/* 0BCCF0 7F0881C0 C44801E4 */  lwc1  $f8, 0x1e4($v0)
/* 0BCCF4 7F0881C4 E7A80014 */  swc1  $f8, 0x14($sp)
/* 0BCCF8 7F0881C8 C44401E8 */  lwc1  $f4, 0x1e8($v0)
/* 0BCCFC 7F0881CC E7A40018 */  swc1  $f4, 0x18($sp)
/* 0BCD00 7F0881D0 C44601EC */  lwc1  $f6, 0x1ec($v0)
/* 0BCD04 7F0881D4 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 0BCD08 7F0881D8 C44A01F0 */  lwc1  $f10, 0x1f0($v0)
/* 0BCD0C 7F0881DC E7AA0020 */  swc1  $f10, 0x20($sp)
/* 0BCD10 7F0881E0 C44801F4 */  lwc1  $f8, 0x1f4($v0)
/* 0BCD14 7F0881E4 E7AE0168 */  swc1  $f14, 0x168($sp)
/* 0BCD18 7F0881E8 0FC16642 */  jal   matrix_4x4_7F059908
/* 0BCD1C 7F0881EC E7A80024 */   swc1  $f8, 0x24($sp)
/* 0BCD20 7F0881F0 8FA40164 */  lw    $a0, 0x164($sp)
/* 0BCD24 7F0881F4 0FC16218 */  jal   matrix_4x4_get_rotation_around_xyz
/* 0BCD28 7F0881F8 27A500FC */   addiu $a1, $sp, 0xfc
/* 0BCD2C 7F0881FC 27A40108 */  addiu $a0, $sp, 0x108
/* 0BCD30 7F088200 0FC16218 */  jal   matrix_4x4_get_rotation_around_xyz
/* 0BCD34 7F088204 27A500F0 */   addiu $a1, $sp, 0xf0
/* 0BCD38 7F088208 27A400FC */  addiu $a0, $sp, 0xfc
/* 0BCD3C 7F08820C 0FC16CFD */  jal   quaternion_set_rotation_around_xyzf
/* 0BCD40 7F088210 27A500E0 */   addiu $a1, $sp, 0xe0
/* 0BCD44 7F088214 27A400F0 */  addiu $a0, $sp, 0xf0
/* 0BCD48 7F088218 0FC16CFD */  jal   quaternion_set_rotation_around_xyzf
/* 0BCD4C 7F08821C 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0BCD50 7F088220 27A400E0 */  addiu $a0, $sp, 0xe0
/* 0BCD54 7F088224 0FC16F84 */  jal   quaternion_ensure_shortest_path
/* 0BCD58 7F088228 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0BCD5C 7F08822C 27A400E0 */  addiu $a0, $sp, 0xe0
/* 0BCD60 7F088230 27A500D0 */  addiu $a1, $sp, 0xd0
/* 0BCD64 7F088234 8FA60168 */  lw    $a2, 0x168($sp)
/* 0BCD68 7F088238 0FC16E82 */  jal   quaternion_slerp
/* 0BCD6C 7F08823C 27A700C0 */   addiu $a3, $sp, 0xc0
/* 0BCD70 7F088240 27A400C0 */  addiu $a0, $sp, 0xc0
/* 0BCD74 7F088244 0FC16D8A */  jal   quaternion_to_matrix
/* 0BCD78 7F088248 8FA50164 */   lw    $a1, 0x164($sp)
/* 0BCD7C 7F08824C 27A400B4 */  addiu $a0, $sp, 0xb4
/* 0BCD80 7F088250 0FC16266 */  jal   matrix_4x4_set_position
/* 0BCD84 7F088254 8FA50164 */   lw    $a1, 0x164($sp)
/* 0BCD88 7F088258 3C198008 */  lui   $t9, %hi(g_CurrentPlayer)
/* 0BCD8C 7F08825C 8F39A0B0 */  lw    $t9, %lo(g_CurrentPlayer)($t9)
/* 0BCD90 7F088260 8FA50164 */  lw    $a1, 0x164($sp)
/* 0BCD94 7F088264 0FC1629F */  jal   matrix_scalar_multiply
/* 0BCD98 7F088268 C72C0244 */   lwc1  $f12, 0x244($t9)
/* 0BCD9C 7F08826C 2403003C */  li    $v1, 60
/* 0BCDA0 7F088270 8FA40090 */  lw    $a0, 0x90($sp)
/* 0BCDA4 7F088274 3C018005 */  lui   $at, %hi(D_80055280)
/* 0BCDA8 7F088278 C4225280 */  lwc1  $f2, %lo(D_80055280)($at)
/* 0BCDAC 7F08827C 0083001A */  div   $zero, $a0, $v1
/* 0BCDB0 7F088280 0000C010 */  mfhi  $t8
/* 0BCDB4 7F088284 00001012 */  mflo  $v0
/* 0BCDB8 7F088288 44982000 */  mtc1  $t8, $f4
/* 0BCDBC 7F08828C 44808000 */  mtc1  $zero, $f16
/* 0BCDC0 7F088290 0043001A */  div   $zero, $v0, $v1
/* 0BCDC4 7F088294 00007010 */  mfhi  $t6
/* 0BCDC8 7F088298 00006012 */  mflo  $t4
/* 0BCDCC 7F08829C 468021A0 */  cvt.s.w $f6, $f4
/* 0BCDD0 7F0882A0 14600002 */  bnez  $v1, .L7F0882AC
/* 0BCDD4 7F0882A4 00000000 */   nop
/* 0BCDD8 7F0882A8 0007000D */  break 7
.L7F0882AC:
/* 0BCDDC 7F0882AC 2401FFFF */  li    $at, -1
/* 0BCDE0 7F0882B0 14610004 */  bne   $v1, $at, .L7F0882C4
/* 0BCDE4 7F0882B4 3C018000 */   lui   $at, 0x8000
/* 0BCDE8 7F0882B8 14810002 */  bne   $a0, $at, .L7F0882C4
/* 0BCDEC 7F0882BC 00000000 */   nop
/* 0BCDF0 7F0882C0 0006000D */  break 6
.L7F0882C4:
/* 0BCDF4 7F0882C4 0183001A */  div   $zero, $t4, $v1
/* 0BCDF8 7F0882C8 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BCDFC 7F0882CC 44815000 */  mtc1  $at, $f10
/* 0BCE00 7F0882D0 448E2000 */  mtc1  $t6, $f4
/* 0BCE04 7F0882D4 00006810 */  mfhi  $t5
/* 0BCE08 7F0882D8 460A3203 */  div.s $f8, $f6, $f10
/* 0BCE0C 7F0882DC 14600002 */  bnez  $v1, .L7F0882E8
/* 0BCE10 7F0882E0 00000000 */   nop
/* 0BCE14 7F0882E4 0007000D */  break 7
.L7F0882E8:
/* 0BCE18 7F0882E8 2401FFFF */  li    $at, -1
/* 0BCE1C 7F0882EC 14610004 */  bne   $v1, $at, .L7F088300
/* 0BCE20 7F0882F0 3C018000 */   li    $at, 0x80000000 # -0.000000
/* 0BCE24 7F0882F4 14410002 */  bne   $v0, $at, .L7F088300
/* 0BCE28 7F0882F8 00000000 */   nop
/* 0BCE2C 7F0882FC 0006000D */  break 6
.L7F088300:
/* 0BCE30 7F088300 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BCE34 7F088304 8FAB0160 */  lw    $t3, 0x160($sp)
/* 0BCE38 7F088308 468021A0 */  cvt.s.w $f6, $f4
/* 0BCE3C 7F08830C 46083280 */  add.s $f10, $f6, $f8
/* 0BCE40 7F088310 44814000 */  mtc1  $at, $f8
/* 0BCE44 7F088314 46005107 */  neg.s $f4, $f10
/* 0BCE48 7F088318 448D5000 */  mtc1  $t5, $f10
/* 0BCE4C 7F08831C 46022182 */  mul.s $f6, $f4, $f2
/* 0BCE50 7F088320 46805120 */  cvt.s.w $f4, $f10
/* 0BCE54 7F088324 46083483 */  div.s $f18, $f6, $f8
/* 0BCE58 7F088328 46002187 */  neg.s $f6, $f4
/* 0BCE5C 7F08832C 46023202 */  mul.s $f8, $f6, $f2
/* 0BCE60 7F088330 4610903C */  c.lt.s $f18, $f16
/* 0BCE64 7F088334 46009306 */  mov.s $f12, $f18
/* 0BCE68 7F088338 14600002 */  bnez  $v1, .L7F088344
/* 0BCE6C 7F08833C 00000000 */   nop
/* 0BCE70 7F088340 0007000D */  break 7
.L7F088344:
/* 0BCE74 7F088344 2401FFFF */  li    $at, -1
/* 0BCE78 7F088348 14610004 */  bne   $v1, $at, .L7F08835C
/* 0BCE7C 7F08834C 3C018000 */   li    $at, 0x80000000 # -0.000000
/* 0BCE80 7F088350 15810002 */  bne   $t4, $at, .L7F08835C
/* 0BCE84 7F088354 00000000 */   nop
/* 0BCE88 7F088358 0006000D */  break 6
.L7F08835C:
/* 0BCE8C 7F08835C 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BCE90 7F088360 44815000 */  mtc1  $at, $f10
/* 0BCE94 7F088364 44813000 */  mtc1  $at, $f6
/* 0BCE98 7F088368 24010E10 */  li    $at, 3600
/* 0BCE9C 7F08836C 0041001A */  div   $zero, $v0, $at
/* 0BCEA0 7F088370 00007812 */  mflo  $t7
/* 0BCEA4 7F088374 2401000C */  li    $at, 12
/* 0BCEA8 7F088378 460A4103 */  div.s $f4, $f8, $f10
/* 0BCEAC 7F08837C 01E1001A */  div   $zero, $t7, $at
/* 0BCEB0 7F088380 46069203 */  div.s $f8, $f18, $f6
/* 0BCEB4 7F088384 00005010 */  mfhi  $t2
/* 0BCEB8 7F088388 448A3000 */  mtc1  $t2, $f6
/* 0BCEBC 7F08838C 3C014140 */  li    $at, 0x41400000 # 12.000000
/* 0BCEC0 7F088390 46082280 */  add.s $f10, $f4, $f8
/* 0BCEC4 7F088394 46803120 */  cvt.s.w $f4, $f6
/* 0BCEC8 7F088398 E7AA0040 */  swc1  $f10, 0x40($sp)
/* 0BCECC 7F08839C 46005386 */  mov.s $f14, $f10
/* 0BCED0 7F0883A0 46002207 */  neg.s $f8, $f4
/* 0BCED4 7F0883A4 44812000 */  mtc1  $at, $f4
/* 0BCED8 7F0883A8 46024182 */  mul.s $f6, $f8, $f2
/* 0BCEDC 7F0883AC 46043203 */  div.s $f8, $f6, $f4
/* 0BCEE0 7F0883B0 44813000 */  mtc1  $at, $f6
/* 0BCEE4 7F0883B4 3C014434 */  li    $at, 0x44340000 # 720.000000
/* 0BCEE8 7F0883B8 46065103 */  div.s $f4, $f10, $f6
/* 0BCEEC 7F0883BC 44813000 */  mtc1  $at, $f6
/* 0BCEF0 7F0883C0 46044280 */  add.s $f10, $f8, $f4
/* 0BCEF4 7F0883C4 46069203 */  div.s $f8, $f18, $f6
/* 0BCEF8 7F0883C8 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 0BCEFC 7F0883CC 46085100 */  add.s $f4, $f10, $f8
/* 0BCF00 7F0883D0 E7A4003C */  swc1  $f4, 0x3c($sp)
/* 0BCF04 7F0883D4 46002006 */  mov.s $f0, $f4
/* 0BCF08 7F0883D8 45000006 */  bc1f  .L7F0883F4
/* 0BCF0C 7F0883DC C7AA003C */   lwc1  $f10, 0x3c($sp)
/* 0BCF10 7F0883E0 46026300 */  add.s $f12, $f12, $f2
.L7F0883E4:
/* 0BCF14 7F0883E4 4610603C */  c.lt.s $f12, $f16
/* 0BCF18 7F0883E8 00000000 */  nop
/* 0BCF1C 7F0883EC 4503FFFD */  bc1tl .L7F0883E4
/* 0BCF20 7F0883F0 46026300 */   add.s $f12, $f12, $f2
.L7F0883F4:
/* 0BCF24 7F0883F4 4610303C */  c.lt.s $f6, $f16
/* 0BCF28 7F0883F8 00000000 */  nop
/* 0BCF2C 7F0883FC 45020007 */  bc1fl .L7F08841C
/* 0BCF30 7F088400 4610503C */   c.lt.s $f10, $f16
/* 0BCF34 7F088404 46027380 */  add.s $f14, $f14, $f2
.L7F088408:
/* 0BCF38 7F088408 4610703C */  c.lt.s $f14, $f16
/* 0BCF3C 7F08840C 00000000 */  nop
/* 0BCF40 7F088410 4503FFFD */  bc1tl .L7F088408
/* 0BCF44 7F088414 46027380 */   add.s $f14, $f14, $f2
/* 0BCF48 7F088418 4610503C */  c.lt.s $f10, $f16
.L7F08841C:
/* 0BCF4C 7F08841C 00000000 */  nop
/* 0BCF50 7F088420 45020007 */  bc1fl .L7F088440
/* 0BCF54 7F088424 8D790008 */   lw    $t9, 8($t3)
/* 0BCF58 7F088428 46020000 */  add.s $f0, $f0, $f2
.L7F08842C:
/* 0BCF5C 7F08842C 4610003C */  c.lt.s $f0, $f16
/* 0BCF60 7F088430 00000000 */  nop
/* 0BCF64 7F088434 4503FFFD */  bc1tl .L7F08842C
/* 0BCF68 7F088438 46020000 */   add.s $f0, $f0, $f2
/* 0BCF6C 7F08843C 8D790008 */  lw    $t9, 8($t3)
.L7F088440:
/* 0BCF70 7F088440 8FA60164 */  lw    $a2, 0x164($sp)
/* 0BCF74 7F088444 44050000 */  mfc1  $a1, $f0
/* 0BCF78 7F088448 8F380000 */  lw    $t8, ($t9)
/* 0BCF7C 7F08844C 24C60040 */  addiu $a2, $a2, 0x40
/* 0BCF80 7F088450 8F040004 */  lw    $a0, 4($t8)
/* 0BCF84 7F088454 E7AE0098 */  swc1  $f14, 0x98($sp)
/* 0BCF88 7F088458 E7AC009C */  swc1  $f12, 0x9c($sp)
/* 0BCF8C 7F08845C 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BCF90 7F088460 AFA60040 */   sw    $a2, 0x40($sp)
/* 0BCF94 7F088464 8FA50040 */  lw    $a1, 0x40($sp)
/* 0BCF98 7F088468 0FC1601A */  jal   matrix_4x4_multiply_in_place
/* 0BCF9C 7F08846C 8FA40164 */   lw    $a0, 0x164($sp)
/* 0BCFA0 7F088470 8FAE0160 */  lw    $t6, 0x160($sp)
/* 0BCFA4 7F088474 C7AE0098 */  lwc1  $f14, 0x98($sp)
/* 0BCFA8 7F088478 8FA60164 */  lw    $a2, 0x164($sp)
/* 0BCFAC 7F08847C 8DCC0008 */  lw    $t4, 8($t6)
/* 0BCFB0 7F088480 44057000 */  mfc1  $a1, $f14
/* 0BCFB4 7F088484 24C60080 */  addiu $a2, $a2, 0x80
/* 0BCFB8 7F088488 8D8D0004 */  lw    $t5, 4($t4)
/* 0BCFBC 7F08848C 8DA40004 */  lw    $a0, 4($t5)
/* 0BCFC0 7F088490 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BCFC4 7F088494 AFA60040 */   sw    $a2, 0x40($sp)
/* 0BCFC8 7F088498 8FA50040 */  lw    $a1, 0x40($sp)
/* 0BCFCC 7F08849C 0FC1601A */  jal   matrix_4x4_multiply_in_place
/* 0BCFD0 7F0884A0 8FA40164 */   lw    $a0, 0x164($sp)
/* 0BCFD4 7F0884A4 8FAF0160 */  lw    $t7, 0x160($sp)
/* 0BCFD8 7F0884A8 C7AC009C */  lwc1  $f12, 0x9c($sp)
/* 0BCFDC 7F0884AC 8FA60164 */  lw    $a2, 0x164($sp)
/* 0BCFE0 7F0884B0 8DEA0008 */  lw    $t2, 8($t7)
/* 0BCFE4 7F0884B4 44056000 */  mfc1  $a1, $f12
/* 0BCFE8 7F0884B8 24C600C0 */  addiu $a2, $a2, 0xc0
/* 0BCFEC 7F0884BC 8D4B0008 */  lw    $t3, 8($t2)
/* 0BCFF0 7F0884C0 8D640004 */  lw    $a0, 4($t3)
/* 0BCFF4 7F0884C4 0FC16134 */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BCFF8 7F0884C8 AFA60040 */   sw    $a2, 0x40($sp)
/* 0BCFFC 7F0884CC 8FA50040 */  lw    $a1, 0x40($sp)
/* 0BD000 7F0884D0 0FC1601A */  jal   matrix_4x4_multiply_in_place
/* 0BD004 7F0884D4 8FA40164 */   lw    $a0, 0x164($sp)
/* 0BD008 7F0884D8 8FB801F8 */  lw    $t8, 0x1f8($sp)
/* 0BD00C 7F0884DC 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BD010 7F0884E0 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BD014 7F0884E4 24190003 */  li    $t9, 3
/* 0BD018 7F0884E8 240E0004 */  li    $t6, 4
/* 0BD01C 7F0884EC AFB901C0 */  sw    $t9, 0x1c0($sp)
/* 0BD020 7F0884F0 AFA001BC */  sw    $zero, 0x1bc($sp)
/* 0BD024 7F0884F4 AFAE01E8 */  sw    $t6, 0x1e8($sp)
/* 0BD028 7F0884F8 AFB801C4 */  sw    $t8, 0x1c4($sp)
/* 0BD02C 7F0884FC 8C4301C8 */  lw    $v1, 0x1c8($v0)
/* 0BD030 7F088500 24010005 */  li    $at, 5
/* 0BD034 7F088504 27A401B8 */  addiu $a0, $sp, 0x1b8
/* 0BD038 7F088508 10610002 */  beq   $v1, $at, .L7F088514
/* 0BD03C 7F08850C 2401000C */   li    $at, 12
/* 0BD040 7F088510 14610003 */  bne   $v1, $at, .L7F088520
.L7F088514:
/* 0BD044 7F088514 240C00CD */   li    $t4, 205
/* 0BD048 7F088518 1000000C */  b     .L7F08854C
/* 0BD04C 7F08851C AFAC01EC */   sw    $t4, 0x1ec($sp)
.L7F088520:
/* 0BD050 7F088520 904F0FDC */  lbu   $t7, 0xfdc($v0)
/* 0BD054 7F088524 904D0FDF */  lbu   $t5, 0xfdf($v0)
/* 0BD058 7F088528 90590FDD */  lbu   $t9, 0xfdd($v0)
/* 0BD05C 7F08852C 904C0FDE */  lbu   $t4, 0xfde($v0)
/* 0BD060 7F088530 000F5600 */  sll   $t2, $t7, 0x18
/* 0BD064 7F088534 01AA5825 */  or    $t3, $t5, $t2
/* 0BD068 7F088538 0019C400 */  sll   $t8, $t9, 0x10
/* 0BD06C 7F08853C 01787025 */  or    $t6, $t3, $t8
/* 0BD070 7F088540 000C7A00 */  sll   $t7, $t4, 8
/* 0BD074 7F088544 01CF6825 */  or    $t5, $t6, $t7
/* 0BD078 7F088548 AFAD01EC */  sw    $t5, 0x1ec($sp)
.L7F08854C:
/* 0BD07C 7F08854C 0FC1D1A1 */  jal   subdraw
/* 0BD080 7F088550 24450230 */   addiu $a1, $v0, 0x230
/* 0BD084 7F088554 8FAA01C4 */  lw    $t2, 0x1c4($sp)
/* 0BD088 7F088558 8FB90160 */  lw    $t9, 0x160($sp)
/* 0BD08C 7F08855C AFAA01F8 */  sw    $t2, 0x1f8($sp)
/* 0BD090 7F088560 8F2B0008 */  lw    $t3, 8($t9)
/* 0BD094 7F088564 8D780008 */  lw    $t8, 8($t3)
/* 0BD098 7F088568 8F0C0004 */  lw    $t4, 4($t8)
/* 0BD09C 7F08856C 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0BD0A0 7F088570 AFAC008C */   sw    $t4, 0x8c($sp)
/* 0BD0A4 7F088574 AFA20048 */  sw    $v0, 0x48($sp)
/* 0BD0A8 7F088578 8FA4008C */  lw    $a0, 0x8c($sp)
/* 0BD0AC 7F08857C 0FC16259 */  jal   matrix_4x4_set_identity_and_position
/* 0BD0B0 7F088580 27A5004C */   addiu $a1, $sp, 0x4c
/* 0BD0B4 7F088584 8FA40164 */  lw    $a0, 0x164($sp)
/* 0BD0B8 7F088588 0FC1601A */  jal   matrix_4x4_multiply_in_place
/* 0BD0BC 7F08858C 27A5004C */   addiu $a1, $sp, 0x4c
/* 0BD0C0 7F088590 0FC16319 */  jal   matrix_4x4_7F058C64
/* 0BD0C4 7F088594 00000000 */   nop
/* 0BD0C8 7F088598 27A4004C */  addiu $a0, $sp, 0x4c
/* 0BD0CC 7F08859C 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 0BD0D0 7F0885A0 8FA50048 */   lw    $a1, 0x48($sp)
/* 0BD0D4 7F0885A4 0FC16322 */  jal   matrix_4x4_7F058C88
/* 0BD0D8 7F0885A8 00000000 */   nop
/* 0BD0DC 7F0885AC 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0BD0E0 7F0885B0 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BD0E4 7F0885B4 8FA401F8 */  lw    $a0, 0x1f8($sp)
/* 0BD0E8 7F0885B8 8DC301C8 */  lw    $v1, 0x1c8($t6)
/* 0BD0EC 7F0885BC 38660005 */  xori  $a2, $v1, 5
/* 0BD0F0 7F0885C0 2CC60001 */  sltiu $a2, $a2, 1
/* 0BD0F4 7F0885C4 14C00003 */  bnez  $a2, .L7F0885D4
/* 0BD0F8 7F0885C8 00000000 */   nop
/* 0BD0FC 7F0885CC 3866000C */  xori  $a2, $v1, 0xc
/* 0BD100 7F0885D0 2CC60001 */  sltiu $a2, $a2, 1
.L7F0885D4:
/* 0BD104 7F0885D4 0FC2B28A */  jal   sub_GAME_7F0ACA28
/* 0BD108 7F0885D8 8FA50048 */   lw    $a1, 0x48($sp)
/* 0BD10C 7F0885DC 0FC16319 */  jal   matrix_4x4_7F058C64
/* 0BD110 7F0885E0 AFA201F8 */   sw    $v0, 0x1f8($sp)
/* 0BD114 7F0885E4 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer)
/* 0BD118 7F0885E8 8DEFA0B0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0BD11C 7F0885EC 8FAD0160 */  lw    $t5, 0x160($sp)
/* 0BD120 7F0885F0 8DE4023C */  lw    $a0, 0x23c($t7)
/* 0BD124 7F0885F4 0FC22F52 */  jal   bondviewTransformManyPosToViewMatrix
/* 0BD128 7F0885F8 85A5000E */   lh    $a1, 0xe($t5)
/* 0BD12C 7F0885FC 0FC16322 */  jal   matrix_4x4_7F058C88
/* 0BD130 7F088600 00000000 */   nop
.L7F088604:
/* 0BD134 7F088604 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F088608:
/* 0BD138 7F088608 8FA201F8 */  lw    $v0, 0x1f8($sp)
/* 0BD13C 7F08860C 27BD01F8 */  addiu $sp, $sp, 0x1f8
/* 0BD140 7F088610 03E00008 */  jr    $ra
/* 0BD144 7F088614 00000000 */   nop
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_8005527C
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055280
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F087E74
/* 0BD0B0 7F088540 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BD0B4 7F088544 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BD0B8 7F088548 27BDFE08 */  addiu $sp, $sp, -0x1f8
/* 0BD0BC 7F08854C AFBF002C */  sw    $ra, 0x2c($sp)
/* 0BD0C0 7F088550 AFA401F8 */  sw    $a0, 0x1f8($sp)
/* 0BD0C4 7F088554 8C4E01C8 */  lw    $t6, 0x1c8($v0)
/* 0BD0C8 7F088558 51C001E0 */  beql  $t6, $zero, .Ljp7F088CDC
/* 0BD0CC 7F08855C 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0BD0D0 7F088560 8C4F0200 */  lw    $t7, 0x200($v0)
/* 0BD0D4 7F088564 3C198003 */  lui   $t9, %hi(D_8003683C) # $t9, 0x8003
/* 0BD0D8 7F088568 2739687C */  addiu $t9, %lo(D_8003683C) # addiu $t9, $t9, 0x687c
/* 0BD0DC 7F08856C 11E001DA */  beqz  $t7, .Ljp7F088CD8
/* 0BD0E0 7F088570 27B801B8 */   addiu $t8, $sp, 0x1b8
/* 0BD0E4 7F088574 272B003C */  addiu $t3, $t9, 0x3c
.Ljp7F088578:
/* 0BD0E8 7F088578 8F210000 */  lw    $at, ($t9)
/* 0BD0EC 7F08857C 2739000C */  addiu $t9, $t9, 0xc
/* 0BD0F0 7F088580 2718000C */  addiu $t8, $t8, 0xc
/* 0BD0F4 7F088584 AF01FFF4 */  sw    $at, -0xc($t8)
/* 0BD0F8 7F088588 8F21FFF8 */  lw    $at, -8($t9)
/* 0BD0FC 7F08858C AF01FFF8 */  sw    $at, -8($t8)
/* 0BD100 7F088590 8F21FFFC */  lw    $at, -4($t9)
/* 0BD104 7F088594 172BFFF8 */  bne   $t9, $t3, .Ljp7F088578
/* 0BD108 7F088598 AF01FFFC */   sw    $at, -4($t8)
/* 0BD10C 7F08859C 8F210000 */  lw    $at, ($t9)
/* 0BD110 7F0885A0 3C0D8003 */  lui   $t5, %hi(D_8003687C) # $t5, 0x8003
/* 0BD114 7F0885A4 25AD68BC */  addiu $t5, %lo(D_8003687C) # addiu $t5, $t5, 0x68bc
/* 0BD118 7F0885A8 AF010000 */  sw    $at, ($t8)
/* 0BD11C 7F0885AC 8DA10000 */  lw    $at, ($t5)
/* 0BD120 7F0885B0 27AC016C */  addiu $t4, $sp, 0x16c
/* 0BD124 7F0885B4 8DAF0004 */  lw    $t7, 4($t5)
/* 0BD128 7F0885B8 AD810000 */  sw    $at, ($t4)
/* 0BD12C 7F0885BC 8DA10008 */  lw    $at, 8($t5)
/* 0BD130 7F0885C0 24040001 */  li    $a0, 1
/* 0BD134 7F0885C4 AD8F0004 */  sw    $t7, 4($t4)
/* 0BD138 7F0885C8 0FC1750E */  jal   get_ptr_itemheader_in_hand
/* 0BD13C 7F0885CC AD810008 */   sw    $at, 8($t4)
/* 0BD140 7F0885D0 AFA20160 */  sw    $v0, 0x160($sp)
/* 0BD144 7F0885D4 3C048008 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8008
/* 0BD148 7F0885D8 8C4A0008 */  lw    $t2, 8($v0)
/* 0BD14C 7F0885DC 8C84A120 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BD150 7F0885E0 8D45000C */  lw    $a1, 0xc($t2)
/* 0BD154 7F0885E4 0FC1B363 */  jal   modelGetNodeRwData
/* 0BD158 7F0885E8 24840230 */   addiu $a0, $a0, 0x230
/* 0BD15C 7F0885EC 0FC2F8A4 */  jal   dynAllocateMatrix
/* 0BD160 7F0885F0 AFA20158 */   sw    $v0, 0x158($sp)
/* 0BD164 7F0885F4 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0BD168 7F0885F8 44812000 */  mtc1  $at, $f4
/* 0BD16C 7F0885FC 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer) # $t3, 0x8008
/* 0BD170 7F088600 8D6BA120 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0BD174 7F088604 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0BD178 7F088608 44813000 */  mtc1  $at, $f6
/* 0BD17C 7F08860C AFA20154 */  sw    $v0, 0x154($sp)
/* 0BD180 7F088610 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BD184 7F088614 44814000 */  mtc1  $at, $f8
/* 0BD188 7F088618 8D6611C4 */  lw    $a2, 0x11c4($t3)
/* 0BD18C 7F08861C 3C073FBA */  lui   $a3, (0x3FBA2E8C >> 16) # lui $a3, 0x3fba
/* 0BD190 7F088620 34E72E8C */  ori   $a3, (0x3FBA2E8C & 0xFFFF) # ori $a3, $a3, 0x2e8c
/* 0BD194 7F088624 00402025 */  move  $a0, $v0
/* 0BD198 7F088628 27A50152 */  addiu $a1, $sp, 0x152
/* 0BD19C 7F08862C E7A40010 */  swc1  $f4, 0x10($sp)
/* 0BD1A0 7F088630 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0BD1A4 7F088634 0C003FBC */  jal   guPerspective
/* 0BD1A8 7F088638 E7A80018 */   swc1  $f8, 0x18($sp)
/* 0BD1AC 7F08863C 8FA301F8 */  lw    $v1, 0x1f8($sp)
/* 0BD1B0 7F088640 3C190103 */  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
/* 0BD1B4 7F088644 37390040 */  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 0BD1B8 7F088648 AC790000 */  sw    $t9, ($v1)
/* 0BD1BC 7F08864C 8FB80154 */  lw    $t8, 0x154($sp)
/* 0BD1C0 7F088650 3C01C140 */  li    $at, 0xC1400000 # -12.000000
/* 0BD1C4 7F088654 44810000 */  mtc1  $at, $f0
/* 0BD1C8 7F088658 3C018000 */  lui   $at, 0x8000
/* 0BD1CC 7F08865C 3C0CBC00 */  lui   $t4, (0xBC00000E >> 16) # lui $t4, 0xbc00
/* 0BD1D0 7F088660 03017021 */  addu  $t6, $t8, $at
/* 0BD1D4 7F088664 358C000E */  ori   $t4, (0xBC00000E & 0xFFFF) # ori $t4, $t4, 0xe
/* 0BD1D8 7F088668 AC6E0004 */  sw    $t6, 4($v1)
/* 0BD1DC 7F08866C 24670008 */  addiu $a3, $v1, 8
/* 0BD1E0 7F088670 ACEC0000 */  sw    $t4, ($a3)
/* 0BD1E4 7F088674 97AD0152 */  lhu   $t5, 0x152($sp)
/* 0BD1E8 7F088678 3C088008 */  lui   $t0, %hi(g_CurrentPlayer) # $t0, 0x8008
/* 0BD1EC 7F08867C 2508A120 */  addiu $t0, %lo(g_CurrentPlayer) # addiu $t0, $t0, -0x5ee0
/* 0BD1F0 7F088680 ACED0004 */  sw    $t5, 4($a3)
/* 0BD1F4 7F088684 8D0F0000 */  lw    $t7, ($t0)
/* 0BD1F8 7F088688 8FAB0158 */  lw    $t3, 0x158($sp)
/* 0BD1FC 7F08868C 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0BD200 7F088690 8DEA01CC */  lw    $t2, 0x1cc($t7)
/* 0BD204 7F088694 24E90008 */  addiu $t1, $a3, 8
/* 0BD208 7F088698 27A4016C */  addiu $a0, $sp, 0x16c
/* 0BD20C 7F08869C AD6A0000 */  sw    $t2, ($t3)
/* 0BD210 7F0886A0 8D020000 */  lw    $v0, ($t0)
/* 0BD214 7F0886A4 27A60178 */  addiu $a2, $sp, 0x178
/* 0BD218 7F0886A8 C444054C */  lwc1  $f4, 0x54c($v0)
/* 0BD21C 7F0886AC C44A0498 */  lwc1  $f10, 0x498($v0)
/* 0BD220 7F0886B0 46002180 */  add.s $f6, $f4, $f0
/* 0BD224 7F0886B4 C4440544 */  lwc1  $f4, 0x544($v0)
/* 0BD228 7F0886B8 46065202 */  mul.s $f8, $f10, $f6
/* 0BD22C 7F0886BC C44A04A0 */  lwc1  $f10, 0x4a0($v0)
/* 0BD230 7F0886C0 46005187 */  neg.s $f6, $f10
/* 0BD234 7F0886C4 46062282 */  mul.s $f10, $f4, $f6
/* 0BD238 7F0886C8 C444048C */  lwc1  $f4, 0x48c($v0)
/* 0BD23C 7F0886CC 460A2180 */  add.s $f6, $f4, $f10
/* 0BD240 7F0886D0 46064100 */  add.s $f4, $f8, $f6
/* 0BD244 7F0886D4 E7A4016C */  swc1  $f4, 0x16c($sp)
/* 0BD248 7F0886D8 C4480490 */  lwc1  $f8, 0x490($v0)
/* 0BD24C 7F0886DC C44A0548 */  lwc1  $f10, 0x548($v0)
/* 0BD250 7F0886E0 46085180 */  add.s $f6, $f10, $f8
/* 0BD254 7F0886E4 E7A60170 */  swc1  $f6, 0x170($sp)
/* 0BD258 7F0886E8 C44A054C */  lwc1  $f10, 0x54c($v0)
/* 0BD25C 7F0886EC C44404A0 */  lwc1  $f4, 0x4a0($v0)
/* 0BD260 7F0886F0 46005200 */  add.s $f8, $f10, $f0
/* 0BD264 7F0886F4 C44A0544 */  lwc1  $f10, 0x544($v0)
/* 0BD268 7F0886F8 46082182 */  mul.s $f6, $f4, $f8
/* 0BD26C 7F0886FC C4440498 */  lwc1  $f4, 0x498($v0)
/* 0BD270 7F088700 46045202 */  mul.s $f8, $f10, $f4
/* 0BD274 7F088704 C44A0494 */  lwc1  $f10, 0x494($v0)
/* 0BD278 7F088708 46085100 */  add.s $f4, $f10, $f8
/* 0BD27C 7F08870C 44814000 */  mtc1  $at, $f8
/* 0BD280 7F088710 3C018005 */  lui   $at, %hi(D_8005527C) # $at, 0x8005
/* 0BD284 7F088714 46043280 */  add.s $f10, $f6, $f4
/* 0BD288 7F088718 E7AA0174 */  swc1  $f10, 0x174($sp)
/* 0BD28C 7F08871C C4460148 */  lwc1  $f6, 0x148($v0)
/* 0BD290 7F088720 C42A52AC */  lwc1  $f10, %lo(D_8005527C)($at)
/* 0BD294 7F088724 AFA901F8 */  sw    $t1, 0x1f8($sp)
/* 0BD298 7F088728 46064101 */  sub.s $f4, $f8, $f6
/* 0BD29C 7F08872C 460A2202 */  mul.s $f8, $f4, $f10
/* 0BD2A0 7F088730 44054000 */  mfc1  $a1, $f8
/* 0BD2A4 7F088734 0FC1627C */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BD2A8 7F088738 00000000 */   nop
/* 0BD2AC 7F08873C 0FC1E26D */  jal   camGetWorldToScreenMtxf
/* 0BD2B0 7F088740 00000000 */   nop
/* 0BD2B4 7F088744 00402025 */  move  $a0, $v0
/* 0BD2B8 7F088748 0FC1616E */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0BD2BC 7F08874C 27A50178 */   addiu $a1, $sp, 0x178
/* 0BD2C0 7F088750 8FB90160 */  lw    $t9, 0x160($sp)
/* 0BD2C4 7F088754 8724000E */  lh    $a0, 0xe($t9)
/* 0BD2C8 7F088758 0004C180 */  sll   $t8, $a0, 6
/* 0BD2CC 7F08875C 0FC2F8B1 */  jal   dynAllocate
/* 0BD2D0 7F088760 03002025 */   move  $a0, $t8
/* 0BD2D4 7F088764 3C048008 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8008
/* 0BD2D8 7F088768 8C84A120 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BD2DC 7F08876C AFA20164 */  sw    $v0, 0x164($sp)
/* 0BD2E0 7F088770 8FA50160 */  lw    $a1, 0x160($sp)
/* 0BD2E4 7F088774 24060004 */  li    $a2, 4
/* 0BD2E8 7F088778 0FC220B8 */  jal   seems_to_load_cuff_microcode
/* 0BD2EC 7F08877C 24840230 */   addiu $a0, $a0, 0x230
/* 0BD2F0 7F088780 3C058008 */  lui   $a1, %hi(g_CurrentPlayer) # $a1, 0x8008
/* 0BD2F4 7F088784 8FAC0164 */  lw    $t4, 0x164($sp)
/* 0BD2F8 7F088788 8CA5A120 */  lw    $a1, %lo(g_CurrentPlayer)($a1)
/* 0BD2FC 7F08878C 27AE0178 */  addiu $t6, $sp, 0x178
/* 0BD300 7F088790 AFAE01B8 */  sw    $t6, 0x1b8($sp)
/* 0BD304 7F088794 27A401B8 */  addiu $a0, $sp, 0x1b8
/* 0BD308 7F088798 AFAC01C8 */  sw    $t4, 0x1c8($sp)
/* 0BD30C 7F08879C 0FC1BE3A */  jal   subcalcmatrices
/* 0BD310 7F0887A0 24A50230 */   addiu $a1, $a1, 0x230
/* 0BD314 7F0887A4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BD318 7F0887A8 44810000 */  mtc1  $at, $f0
/* 0BD31C 7F0887AC 3C018008 */  lui   $at, %hi(watch_time_0) # $at, 0x8008
/* 0BD320 7F0887B0 8FAD0160 */  lw    $t5, 0x160($sp)
/* 0BD324 7F0887B4 C4269A64 */  lwc1  $f6, %lo(watch_time_0)($at)
/* 0BD328 7F0887B8 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BD32C 7F0887BC 8DAF0008 */  lw    $t7, 8($t5)
/* 0BD330 7F0887C0 4600310D */  trunc.w.s $f4, $f6
/* 0BD334 7F0887C4 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BD338 7F0887C8 8DEA0000 */  lw    $t2, ($t7)
/* 0BD33C 7F0887CC 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 0BD340 7F0887D0 44192000 */  mfc1  $t9, $f4
/* 0BD344 7F0887D4 8D430004 */  lw    $v1, 4($t2)
/* 0BD348 7F0887D8 44814000 */  mtc1  $at, $f8
/* 0BD34C 7F0887DC AFB90090 */  sw    $t9, 0x90($sp)
/* 0BD350 7F0887E0 C44A0258 */  lwc1  $f10, 0x258($v0)
/* 0BD354 7F0887E4 46085383 */  div.s $f14, $f10, $f8
/* 0BD358 7F0887E8 460E003C */  c.lt.s $f0, $f14
/* 0BD35C 7F0887EC 00000000 */  nop
/* 0BD360 7F0887F0 45020003 */  bc1fl .Ljp7F088800
/* 0BD364 7F0887F4 C4660000 */   lwc1  $f6, ($v1)
/* 0BD368 7F0887F8 46000386 */  mov.s $f14, $f0
/* 0BD36C 7F0887FC C4660000 */  lwc1  $f6, ($v1)
.Ljp7F088800:
/* 0BD370 7F088800 C4440244 */  lwc1  $f4, 0x244($v0)
/* 0BD374 7F088804 C44801D4 */  lwc1  $f8, 0x1d4($v0)
/* 0BD378 7F088808 8FA80164 */  lw    $t0, 0x164($sp)
/* 0BD37C 7F08880C 46043282 */  mul.s $f10, $f6, $f4
/* 0BD380 7F088810 44808000 */  mtc1  $zero, $f16
/* 0BD384 7F088814 C5000030 */  lwc1  $f0, 0x30($t0)
/* 0BD388 7F088818 27A40108 */  addiu $a0, $sp, 0x108
/* 0BD38C 7F08881C 44058000 */  mfc1  $a1, $f16
/* 0BD390 7F088820 44068000 */  mfc1  $a2, $f16
/* 0BD394 7F088824 44078000 */  mfc1  $a3, $f16
/* 0BD398 7F088828 460A4181 */  sub.s $f6, $f8, $f10
/* 0BD39C 7F08882C 46003101 */  sub.s $f4, $f6, $f0
/* 0BD3A0 7F088830 460E2202 */  mul.s $f8, $f4, $f14
/* 0BD3A4 7F088834 46004280 */  add.s $f10, $f8, $f0
/* 0BD3A8 7F088838 E7AA00B4 */  swc1  $f10, 0xb4($sp)
/* 0BD3AC 7F08883C C4440244 */  lwc1  $f4, 0x244($v0)
/* 0BD3B0 7F088840 C4660008 */  lwc1  $f6, 8($v1)
/* 0BD3B4 7F088844 C44A01D8 */  lwc1  $f10, 0x1d8($v0)
/* 0BD3B8 7F088848 C5020034 */  lwc1  $f2, 0x34($t0)
/* 0BD3BC 7F08884C 46043202 */  mul.s $f8, $f6, $f4
/* 0BD3C0 7F088850 46085180 */  add.s $f6, $f10, $f8
/* 0BD3C4 7F088854 46023101 */  sub.s $f4, $f6, $f2
/* 0BD3C8 7F088858 460E2282 */  mul.s $f10, $f4, $f14
/* 0BD3CC 7F08885C 46025200 */  add.s $f8, $f10, $f2
/* 0BD3D0 7F088860 E7A800B8 */  swc1  $f8, 0xb8($sp)
/* 0BD3D4 7F088864 C4440244 */  lwc1  $f4, 0x244($v0)
/* 0BD3D8 7F088868 C4660004 */  lwc1  $f6, 4($v1)
/* 0BD3DC 7F08886C C44801DC */  lwc1  $f8, 0x1dc($v0)
/* 0BD3E0 7F088870 C50C0038 */  lwc1  $f12, 0x38($t0)
/* 0BD3E4 7F088874 46043282 */  mul.s $f10, $f6, $f4
/* 0BD3E8 7F088878 460A4181 */  sub.s $f6, $f8, $f10
/* 0BD3EC 7F08887C 460C3101 */  sub.s $f4, $f6, $f12
/* 0BD3F0 7F088880 460E2202 */  mul.s $f8, $f4, $f14
/* 0BD3F4 7F088884 460C4280 */  add.s $f10, $f8, $f12
/* 0BD3F8 7F088888 E7AA00BC */  swc1  $f10, 0xbc($sp)
/* 0BD3FC 7F08888C C44601E0 */  lwc1  $f6, 0x1e0($v0)
/* 0BD400 7F088890 E7A60010 */  swc1  $f6, 0x10($sp)
/* 0BD404 7F088894 C44401E4 */  lwc1  $f4, 0x1e4($v0)
/* 0BD408 7F088898 E7A40014 */  swc1  $f4, 0x14($sp)
/* 0BD40C 7F08889C C44801E8 */  lwc1  $f8, 0x1e8($v0)
/* 0BD410 7F0888A0 E7A80018 */  swc1  $f8, 0x18($sp)
/* 0BD414 7F0888A4 C44A01EC */  lwc1  $f10, 0x1ec($v0)
/* 0BD418 7F0888A8 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 0BD41C 7F0888AC C44601F0 */  lwc1  $f6, 0x1f0($v0)
/* 0BD420 7F0888B0 E7A60020 */  swc1  $f6, 0x20($sp)
/* 0BD424 7F0888B4 C44401F4 */  lwc1  $f4, 0x1f4($v0)
/* 0BD428 7F0888B8 E7AE0168 */  swc1  $f14, 0x168($sp)
/* 0BD42C 7F0888BC 0FC1678A */  jal   matrix_4x4_7F059908
/* 0BD430 7F0888C0 E7A40024 */   swc1  $f4, 0x24($sp)
/* 0BD434 7F0888C4 8FA40164 */  lw    $a0, 0x164($sp)
/* 0BD438 7F0888C8 0FC16360 */  jal   matrix_4x4_get_rotation_around_xyz
/* 0BD43C 7F0888CC 27A500FC */   addiu $a1, $sp, 0xfc
/* 0BD440 7F0888D0 27A40108 */  addiu $a0, $sp, 0x108
/* 0BD444 7F0888D4 0FC16360 */  jal   matrix_4x4_get_rotation_around_xyz
/* 0BD448 7F0888D8 27A500F0 */   addiu $a1, $sp, 0xf0
/* 0BD44C 7F0888DC 27A400FC */  addiu $a0, $sp, 0xfc
/* 0BD450 7F0888E0 0FC16E45 */  jal   quaternion_set_rotation_around_xyzf
/* 0BD454 7F0888E4 27A500E0 */   addiu $a1, $sp, 0xe0
/* 0BD458 7F0888E8 27A400F0 */  addiu $a0, $sp, 0xf0
/* 0BD45C 7F0888EC 0FC16E45 */  jal   quaternion_set_rotation_around_xyzf
/* 0BD460 7F0888F0 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0BD464 7F0888F4 27A400E0 */  addiu $a0, $sp, 0xe0
/* 0BD468 7F0888F8 0FC170CC */  jal   quaternion_ensure_shortest_path
/* 0BD46C 7F0888FC 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0BD470 7F088900 27A400E0 */  addiu $a0, $sp, 0xe0
/* 0BD474 7F088904 27A500D0 */  addiu $a1, $sp, 0xd0
/* 0BD478 7F088908 8FA60168 */  lw    $a2, 0x168($sp)
/* 0BD47C 7F08890C 0FC16FCA */  jal   quaternion_slerp
/* 0BD480 7F088910 27A700C0 */   addiu $a3, $sp, 0xc0
/* 0BD484 7F088914 27A400C0 */  addiu $a0, $sp, 0xc0
/* 0BD488 7F088918 0FC16ED2 */  jal   quaternion_to_matrix
/* 0BD48C 7F08891C 8FA50164 */   lw    $a1, 0x164($sp)
/* 0BD490 7F088920 27A400B4 */  addiu $a0, $sp, 0xb4
/* 0BD494 7F088924 0FC163AE */  jal   matrix_4x4_set_position
/* 0BD498 7F088928 8FA50164 */   lw    $a1, 0x164($sp)
/* 0BD49C 7F08892C 3C188008 */  lui   $t8, %hi(g_CurrentPlayer) # $t8, 0x8008
/* 0BD4A0 7F088930 8F18A120 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0BD4A4 7F088934 8FA50164 */  lw    $a1, 0x164($sp)
/* 0BD4A8 7F088938 0FC163E7 */  jal   matrix_scalar_multiply
/* 0BD4AC 7F08893C C70C0244 */   lwc1  $f12, 0x244($t8)
/* 0BD4B0 7F088940 2403003C */  li    $v1, 60
/* 0BD4B4 7F088944 8FA40090 */  lw    $a0, 0x90($sp)
/* 0BD4B8 7F088948 3C018005 */  lui   $at, %hi(D_80055280) # $at, 0x8005
/* 0BD4BC 7F08894C C42252B0 */  lwc1  $f2, %lo(D_80055280)($at)
/* 0BD4C0 7F088950 0083001A */  div   $zero, $a0, $v1
/* 0BD4C4 7F088954 00007010 */  mfhi  $t6
/* 0BD4C8 7F088958 00001012 */  mflo  $v0
/* 0BD4CC 7F08895C 448E4000 */  mtc1  $t6, $f8
/* 0BD4D0 7F088960 44808000 */  mtc1  $zero, $f16
/* 0BD4D4 7F088964 0043001A */  div   $zero, $v0, $v1
/* 0BD4D8 7F088968 00006010 */  mfhi  $t4
/* 0BD4DC 7F08896C 00006812 */  mflo  $t5
/* 0BD4E0 7F088970 468042A0 */  cvt.s.w $f10, $f8
/* 0BD4E4 7F088974 14600002 */  bnez  $v1, .Ljp7F088980
/* 0BD4E8 7F088978 00000000 */   nop
/* 0BD4EC 7F08897C 0007000D */  break 7
.Ljp7F088980:
/* 0BD4F0 7F088980 2401FFFF */  li    $at, -1
/* 0BD4F4 7F088984 14610004 */  bne   $v1, $at, .Ljp7F088998
/* 0BD4F8 7F088988 3C018000 */   lui   $at, 0x8000
/* 0BD4FC 7F08898C 14810002 */  bne   $a0, $at, .Ljp7F088998
/* 0BD500 7F088990 00000000 */   nop
/* 0BD504 7F088994 0006000D */  break 6
.Ljp7F088998:
/* 0BD508 7F088998 01A3001A */  div   $zero, $t5, $v1
/* 0BD50C 7F08899C 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BD510 7F0889A0 44813000 */  mtc1  $at, $f6
/* 0BD514 7F0889A4 448C4000 */  mtc1  $t4, $f8
/* 0BD518 7F0889A8 00007810 */  mfhi  $t7
/* 0BD51C 7F0889AC 46065103 */  div.s $f4, $f10, $f6
/* 0BD520 7F0889B0 14600002 */  bnez  $v1, .Ljp7F0889BC
/* 0BD524 7F0889B4 00000000 */   nop
/* 0BD528 7F0889B8 0007000D */  break 7
.Ljp7F0889BC:
/* 0BD52C 7F0889BC 2401FFFF */  li    $at, -1
/* 0BD530 7F0889C0 14610004 */  bne   $v1, $at, .Ljp7F0889D4
/* 0BD534 7F0889C4 3C018000 */   li    $at, 0x80000000 # -0.000000
/* 0BD538 7F0889C8 14410002 */  bne   $v0, $at, .Ljp7F0889D4
/* 0BD53C 7F0889CC 00000000 */   nop
/* 0BD540 7F0889D0 0006000D */  break 6
.Ljp7F0889D4:
/* 0BD544 7F0889D4 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BD548 7F0889D8 8FB90160 */  lw    $t9, 0x160($sp)
/* 0BD54C 7F0889DC 468042A0 */  cvt.s.w $f10, $f8
/* 0BD550 7F0889E0 46045180 */  add.s $f6, $f10, $f4
/* 0BD554 7F0889E4 44812000 */  mtc1  $at, $f4
/* 0BD558 7F0889E8 46003207 */  neg.s $f8, $f6
/* 0BD55C 7F0889EC 448F3000 */  mtc1  $t7, $f6
/* 0BD560 7F0889F0 46024282 */  mul.s $f10, $f8, $f2
/* 0BD564 7F0889F4 46803220 */  cvt.s.w $f8, $f6
/* 0BD568 7F0889F8 46045483 */  div.s $f18, $f10, $f4
/* 0BD56C 7F0889FC 46004287 */  neg.s $f10, $f8
/* 0BD570 7F088A00 46025102 */  mul.s $f4, $f10, $f2
/* 0BD574 7F088A04 4610903C */  c.lt.s $f18, $f16
/* 0BD578 7F088A08 46009306 */  mov.s $f12, $f18
/* 0BD57C 7F088A0C 14600002 */  bnez  $v1, .Ljp7F088A18
/* 0BD580 7F088A10 00000000 */   nop
/* 0BD584 7F088A14 0007000D */  break 7
.Ljp7F088A18:
/* 0BD588 7F088A18 2401FFFF */  li    $at, -1
/* 0BD58C 7F088A1C 14610004 */  bne   $v1, $at, .Ljp7F088A30
/* 0BD590 7F088A20 3C018000 */   li    $at, 0x80000000 # -0.000000
/* 0BD594 7F088A24 15A10002 */  bne   $t5, $at, .Ljp7F088A30
/* 0BD598 7F088A28 00000000 */   nop
/* 0BD59C 7F088A2C 0006000D */  break 6
.Ljp7F088A30:
/* 0BD5A0 7F088A30 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BD5A4 7F088A34 44813000 */  mtc1  $at, $f6
/* 0BD5A8 7F088A38 44815000 */  mtc1  $at, $f10
/* 0BD5AC 7F088A3C 24010E10 */  li    $at, 3600
/* 0BD5B0 7F088A40 0041001A */  div   $zero, $v0, $at
/* 0BD5B4 7F088A44 00005012 */  mflo  $t2
/* 0BD5B8 7F088A48 2401000C */  li    $at, 12
/* 0BD5BC 7F088A4C 46062203 */  div.s $f8, $f4, $f6
/* 0BD5C0 7F088A50 0141001A */  div   $zero, $t2, $at
/* 0BD5C4 7F088A54 460A9103 */  div.s $f4, $f18, $f10
/* 0BD5C8 7F088A58 00005810 */  mfhi  $t3
/* 0BD5CC 7F088A5C 448B5000 */  mtc1  $t3, $f10
/* 0BD5D0 7F088A60 3C014140 */  li    $at, 0x41400000 # 12.000000
/* 0BD5D4 7F088A64 46044180 */  add.s $f6, $f8, $f4
/* 0BD5D8 7F088A68 46805220 */  cvt.s.w $f8, $f10
/* 0BD5DC 7F088A6C E7A60040 */  swc1  $f6, 0x40($sp)
/* 0BD5E0 7F088A70 46003386 */  mov.s $f14, $f6
/* 0BD5E4 7F088A74 46004107 */  neg.s $f4, $f8
/* 0BD5E8 7F088A78 44814000 */  mtc1  $at, $f8
/* 0BD5EC 7F088A7C 46022282 */  mul.s $f10, $f4, $f2
/* 0BD5F0 7F088A80 46085103 */  div.s $f4, $f10, $f8
/* 0BD5F4 7F088A84 44815000 */  mtc1  $at, $f10
/* 0BD5F8 7F088A88 3C014434 */  li    $at, 0x44340000 # 720.000000
/* 0BD5FC 7F088A8C 460A3203 */  div.s $f8, $f6, $f10
/* 0BD600 7F088A90 44815000 */  mtc1  $at, $f10
/* 0BD604 7F088A94 46082180 */  add.s $f6, $f4, $f8
/* 0BD608 7F088A98 460A9103 */  div.s $f4, $f18, $f10
/* 0BD60C 7F088A9C C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 0BD610 7F088AA0 46043200 */  add.s $f8, $f6, $f4
/* 0BD614 7F088AA4 E7A8003C */  swc1  $f8, 0x3c($sp)
/* 0BD618 7F088AA8 46004006 */  mov.s $f0, $f8
/* 0BD61C 7F088AAC 45000006 */  bc1f  .Ljp7F088AC8
/* 0BD620 7F088AB0 C7A6003C */   lwc1  $f6, 0x3c($sp)
/* 0BD624 7F088AB4 46026300 */  add.s $f12, $f12, $f2
.Ljp7F088AB8:
/* 0BD628 7F088AB8 4610603C */  c.lt.s $f12, $f16
/* 0BD62C 7F088ABC 00000000 */  nop
/* 0BD630 7F088AC0 4503FFFD */  bc1tl .Ljp7F088AB8
/* 0BD634 7F088AC4 46026300 */   add.s $f12, $f12, $f2
.Ljp7F088AC8:
/* 0BD638 7F088AC8 4610503C */  c.lt.s $f10, $f16
/* 0BD63C 7F088ACC 00000000 */  nop
/* 0BD640 7F088AD0 45020007 */  bc1fl .Ljp7F088AF0
/* 0BD644 7F088AD4 4610303C */   c.lt.s $f6, $f16
/* 0BD648 7F088AD8 46027380 */  add.s $f14, $f14, $f2
.Ljp7F088ADC:
/* 0BD64C 7F088ADC 4610703C */  c.lt.s $f14, $f16
/* 0BD650 7F088AE0 00000000 */  nop
/* 0BD654 7F088AE4 4503FFFD */  bc1tl .Ljp7F088ADC
/* 0BD658 7F088AE8 46027380 */   add.s $f14, $f14, $f2
/* 0BD65C 7F088AEC 4610303C */  c.lt.s $f6, $f16
.Ljp7F088AF0:
/* 0BD660 7F088AF0 00000000 */  nop
/* 0BD664 7F088AF4 45020007 */  bc1fl .Ljp7F088B14
/* 0BD668 7F088AF8 8F380008 */   lw    $t8, 8($t9)
/* 0BD66C 7F088AFC 46020000 */  add.s $f0, $f0, $f2
.Ljp7F088B00:
/* 0BD670 7F088B00 4610003C */  c.lt.s $f0, $f16
/* 0BD674 7F088B04 00000000 */  nop
/* 0BD678 7F088B08 4503FFFD */  bc1tl .Ljp7F088B00
/* 0BD67C 7F088B0C 46020000 */   add.s $f0, $f0, $f2
/* 0BD680 7F088B10 8F380008 */  lw    $t8, 8($t9)
.Ljp7F088B14:
/* 0BD684 7F088B14 8FA60164 */  lw    $a2, 0x164($sp)
/* 0BD688 7F088B18 44050000 */  mfc1  $a1, $f0
/* 0BD68C 7F088B1C 8F0E0000 */  lw    $t6, ($t8)
/* 0BD690 7F088B20 24C60040 */  addiu $a2, $a2, 0x40
/* 0BD694 7F088B24 8DC40004 */  lw    $a0, 4($t6)
/* 0BD698 7F088B28 E7AE0098 */  swc1  $f14, 0x98($sp)
/* 0BD69C 7F088B2C E7AC009C */  swc1  $f12, 0x9c($sp)
/* 0BD6A0 7F088B30 0FC1627C */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BD6A4 7F088B34 AFA60040 */   sw    $a2, 0x40($sp)
/* 0BD6A8 7F088B38 8FA50040 */  lw    $a1, 0x40($sp)
/* 0BD6AC 7F088B3C 0FC16162 */  jal   matrix_4x4_multiply_in_place
/* 0BD6B0 7F088B40 8FA40164 */   lw    $a0, 0x164($sp)
/* 0BD6B4 7F088B44 8FAC0160 */  lw    $t4, 0x160($sp)
/* 0BD6B8 7F088B48 C7AE0098 */  lwc1  $f14, 0x98($sp)
/* 0BD6BC 7F088B4C 8FA60164 */  lw    $a2, 0x164($sp)
/* 0BD6C0 7F088B50 8D8D0008 */  lw    $t5, 8($t4)
/* 0BD6C4 7F088B54 44057000 */  mfc1  $a1, $f14
/* 0BD6C8 7F088B58 24C60080 */  addiu $a2, $a2, 0x80
/* 0BD6CC 7F088B5C 8DAF0004 */  lw    $t7, 4($t5)
/* 0BD6D0 7F088B60 8DE40004 */  lw    $a0, 4($t7)
/* 0BD6D4 7F088B64 0FC1627C */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BD6D8 7F088B68 AFA60040 */   sw    $a2, 0x40($sp)
/* 0BD6DC 7F088B6C 8FA50040 */  lw    $a1, 0x40($sp)
/* 0BD6E0 7F088B70 0FC16162 */  jal   matrix_4x4_multiply_in_place
/* 0BD6E4 7F088B74 8FA40164 */   lw    $a0, 0x164($sp)
/* 0BD6E8 7F088B78 8FAA0160 */  lw    $t2, 0x160($sp)
/* 0BD6EC 7F088B7C C7AC009C */  lwc1  $f12, 0x9c($sp)
/* 0BD6F0 7F088B80 8FA60164 */  lw    $a2, 0x164($sp)
/* 0BD6F4 7F088B84 8D4B0008 */  lw    $t3, 8($t2)
/* 0BD6F8 7F088B88 44056000 */  mfc1  $a1, $f12
/* 0BD6FC 7F088B8C 24C600C0 */  addiu $a2, $a2, 0xc0
/* 0BD700 7F088B90 8D790008 */  lw    $t9, 8($t3)
/* 0BD704 7F088B94 8F240004 */  lw    $a0, 4($t9)
/* 0BD708 7F088B98 0FC1627C */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BD70C 7F088B9C AFA60040 */   sw    $a2, 0x40($sp)
/* 0BD710 7F088BA0 8FA50040 */  lw    $a1, 0x40($sp)
/* 0BD714 7F088BA4 0FC16162 */  jal   matrix_4x4_multiply_in_place
/* 0BD718 7F088BA8 8FA40164 */   lw    $a0, 0x164($sp)
/* 0BD71C 7F088BAC 8FAE01F8 */  lw    $t6, 0x1f8($sp)
/* 0BD720 7F088BB0 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BD724 7F088BB4 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BD728 7F088BB8 24180003 */  li    $t8, 3
/* 0BD72C 7F088BBC 240C0004 */  li    $t4, 4
/* 0BD730 7F088BC0 AFB801C0 */  sw    $t8, 0x1c0($sp)
/* 0BD734 7F088BC4 AFA001BC */  sw    $zero, 0x1bc($sp)
/* 0BD738 7F088BC8 AFAC01E8 */  sw    $t4, 0x1e8($sp)
/* 0BD73C 7F088BCC AFAE01C4 */  sw    $t6, 0x1c4($sp)
/* 0BD740 7F088BD0 8C4301C8 */  lw    $v1, 0x1c8($v0)
/* 0BD744 7F088BD4 24010005 */  li    $at, 5
/* 0BD748 7F088BD8 27A401B8 */  addiu $a0, $sp, 0x1b8
/* 0BD74C 7F088BDC 10610002 */  beq   $v1, $at, .Ljp7F088BE8
/* 0BD750 7F088BE0 2401000C */   li    $at, 12
/* 0BD754 7F088BE4 14610003 */  bne   $v1, $at, .Ljp7F088BF4
.Ljp7F088BE8:
/* 0BD758 7F088BE8 240D00CD */   li    $t5, 205
/* 0BD75C 7F088BEC 1000000C */  b     .Ljp7F088C20
/* 0BD760 7F088BF0 AFAD01EC */   sw    $t5, 0x1ec($sp)
.Ljp7F088BF4:
/* 0BD764 7F088BF4 904A0FDC */  lbu   $t2, 0xfdc($v0)
/* 0BD768 7F088BF8 904F0FDF */  lbu   $t7, 0xfdf($v0)
/* 0BD76C 7F088BFC 90580FDD */  lbu   $t8, 0xfdd($v0)
/* 0BD770 7F088C00 904D0FDE */  lbu   $t5, 0xfde($v0)
/* 0BD774 7F088C04 000A5E00 */  sll   $t3, $t2, 0x18
/* 0BD778 7F088C08 01EBC825 */  or    $t9, $t7, $t3
/* 0BD77C 7F088C0C 00187400 */  sll   $t6, $t8, 0x10
/* 0BD780 7F088C10 032E6025 */  or    $t4, $t9, $t6
/* 0BD784 7F088C14 000D5200 */  sll   $t2, $t5, 8
/* 0BD788 7F088C18 018A7825 */  or    $t7, $t4, $t2
/* 0BD78C 7F088C1C AFAF01EC */  sw    $t7, 0x1ec($sp)
.Ljp7F088C20:
/* 0BD790 7F088C20 0FC1D31D */  jal   subdraw
/* 0BD794 7F088C24 24450230 */   addiu $a1, $v0, 0x230
/* 0BD798 7F088C28 8FAB01C4 */  lw    $t3, 0x1c4($sp)
/* 0BD79C 7F088C2C 8FB80160 */  lw    $t8, 0x160($sp)
/* 0BD7A0 7F088C30 AFAB01F8 */  sw    $t3, 0x1f8($sp)
/* 0BD7A4 7F088C34 8F190008 */  lw    $t9, 8($t8)
/* 0BD7A8 7F088C38 8F2E0008 */  lw    $t6, 8($t9)
/* 0BD7AC 7F088C3C 8DCD0004 */  lw    $t5, 4($t6)
/* 0BD7B0 7F088C40 0FC2F8A4 */  jal   dynAllocateMatrix
/* 0BD7B4 7F088C44 AFAD008C */   sw    $t5, 0x8c($sp)
/* 0BD7B8 7F088C48 AFA20048 */  sw    $v0, 0x48($sp)
/* 0BD7BC 7F088C4C 8FA4008C */  lw    $a0, 0x8c($sp)
/* 0BD7C0 7F088C50 0FC163A1 */  jal   matrix_4x4_set_identity_and_position
/* 0BD7C4 7F088C54 27A5004C */   addiu $a1, $sp, 0x4c
/* 0BD7C8 7F088C58 8FA40164 */  lw    $a0, 0x164($sp)
/* 0BD7CC 7F088C5C 0FC16162 */  jal   matrix_4x4_multiply_in_place
/* 0BD7D0 7F088C60 27A5004C */   addiu $a1, $sp, 0x4c
/* 0BD7D4 7F088C64 0FC16461 */  jal   matrix_4x4_7F058C64
/* 0BD7D8 7F088C68 00000000 */   nop
/* 0BD7DC 7F088C6C 27A4004C */  addiu $a0, $sp, 0x4c
/* 0BD7E0 7F088C70 0FC1646F */  jal   matrix_4x4_f32_to_s32
/* 0BD7E4 7F088C74 8FA50048 */   lw    $a1, 0x48($sp)
/* 0BD7E8 7F088C78 0FC1646A */  jal   matrix_4x4_7F058C88
/* 0BD7EC 7F088C7C 00000000 */   nop
/* 0BD7F0 7F088C80 3C0C8008 */  lui   $t4, %hi(g_CurrentPlayer) # $t4, 0x8008
/* 0BD7F4 7F088C84 8D8CA120 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0BD7F8 7F088C88 8FA401F8 */  lw    $a0, 0x1f8($sp)
/* 0BD7FC 7F088C8C 8D8301C8 */  lw    $v1, 0x1c8($t4)
/* 0BD800 7F088C90 38660005 */  xori  $a2, $v1, 5
/* 0BD804 7F088C94 2CC60001 */  sltiu $a2, $a2, 1
/* 0BD808 7F088C98 14C00003 */  bnez  $a2, .Ljp7F088CA8
/* 0BD80C 7F088C9C 00000000 */   nop
/* 0BD810 7F088CA0 3866000C */  xori  $a2, $v1, 0xc
/* 0BD814 7F088CA4 2CC60001 */  sltiu $a2, $a2, 1
.Ljp7F088CA8:
/* 0BD818 7F088CA8 0FC2B574 */  jal   sub_GAME_7F0ACA28
/* 0BD81C 7F088CAC 8FA50048 */   lw    $a1, 0x48($sp)
/* 0BD820 7F088CB0 0FC16461 */  jal   matrix_4x4_7F058C64
/* 0BD824 7F088CB4 AFA201F8 */   sw    $v0, 0x1f8($sp)
/* 0BD828 7F088CB8 3C0A8008 */  lui   $t2, %hi(g_CurrentPlayer) # $t2, 0x8008
/* 0BD82C 7F088CBC 8D4AA120 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0BD830 7F088CC0 8FAF0160 */  lw    $t7, 0x160($sp)
/* 0BD834 7F088CC4 8D44023C */  lw    $a0, 0x23c($t2)
/* 0BD838 7F088CC8 0FC23174 */  jal   bondviewTransformManyPosToViewMatrix
/* 0BD83C 7F088CCC 85E5000E */   lh    $a1, 0xe($t7)
/* 0BD840 7F088CD0 0FC1646A */  jal   matrix_4x4_7F058C88
/* 0BD844 7F088CD4 00000000 */   nop
.Ljp7F088CD8:
/* 0BD848 7F088CD8 8FBF002C */  lw    $ra, 0x2c($sp)
.Ljp7F088CDC:
/* 0BD84C 7F088CDC 8FA201F8 */  lw    $v0, 0x1f8($sp)
/* 0BD850 7F088CE0 27BD01F8 */  addiu $sp, $sp, 0x1f8
/* 0BD854 7F088CE4 03E00008 */  jr    $ra
/* 0BD858 7F088CE8 00000000 */   nop
)
#endif

#if defined(VERSION_EU)
GLOBAL_ASM(
.late_rodata
glabel D_8005527C
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055280
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F087E74
/* 0BA9C4 7F087FD4 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BA9C8 7F087FD8 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BA9CC 7F087FDC 27BDFE08 */  addiu $sp, $sp, -0x1f8
/* 0BA9D0 7F087FE0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0BA9D4 7F087FE4 AFA401F8 */  sw    $a0, 0x1f8($sp)
/* 0BA9D8 7F087FE8 8C4E01C8 */  lw    $t6, 0x1c8($v0)
/* 0BA9DC 7F087FEC 51C001E0 */  beql  $t6, $zero, .L7F088770
/* 0BA9E0 7F087FF0 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0BA9E4 7F087FF4 8C4F0200 */  lw    $t7, 0x200($v0)
/* 0BA9E8 7F087FF8 3C198003 */  lui   $t9, %hi(D_8003683C) # $t9, 0x8003
/* 0BA9EC 7F087FFC 27391D8C */  addiu $t9, %lo(D_8003683C) # addiu $t9, $t9, 0x1d8c
/* 0BA9F0 7F088000 11E001DA */  beqz  $t7, .L7F08876C
/* 0BA9F4 7F088004 27B801B8 */   addiu $t8, $sp, 0x1b8
/* 0BA9F8 7F088008 272B003C */  addiu $t3, $t9, 0x3c
.L7F08800C:
/* 0BA9FC 7F08800C 8F210000 */  lw    $at, ($t9)
/* 0BAA00 7F088010 2739000C */  addiu $t9, $t9, 0xc
/* 0BAA04 7F088014 2718000C */  addiu $t8, $t8, 0xc
/* 0BAA08 7F088018 AF01FFF4 */  sw    $at, -0xc($t8)
/* 0BAA0C 7F08801C 8F21FFF8 */  lw    $at, -8($t9)
/* 0BAA10 7F088020 AF01FFF8 */  sw    $at, -8($t8)
/* 0BAA14 7F088024 8F21FFFC */  lw    $at, -4($t9)
/* 0BAA18 7F088028 172BFFF8 */  bne   $t9, $t3, .L7F08800C
/* 0BAA1C 7F08802C AF01FFFC */   sw    $at, -4($t8)
/* 0BAA20 7F088030 8F210000 */  lw    $at, ($t9)
/* 0BAA24 7F088034 3C0D8003 */  lui   $t5, %hi(D_8003687C) # $t5, 0x8003
/* 0BAA28 7F088038 25AD1DCC */  addiu $t5, %lo(D_8003687C) # addiu $t5, $t5, 0x1dcc
/* 0BAA2C 7F08803C AF010000 */  sw    $at, ($t8)
/* 0BAA30 7F088040 8DA10000 */  lw    $at, ($t5)
/* 0BAA34 7F088044 27AC016C */  addiu $t4, $sp, 0x16c
/* 0BAA38 7F088048 8DAF0004 */  lw    $t7, 4($t5)
/* 0BAA3C 7F08804C AD810000 */  sw    $at, ($t4)
/* 0BAA40 7F088050 8DA10008 */  lw    $at, 8($t5)
/* 0BAA44 7F088054 24040001 */  li    $a0, 1
/* 0BAA48 7F088058 AD8F0004 */  sw    $t7, 4($t4)
/* 0BAA4C 7F08805C 0FC174F2 */  jal   get_ptr_itemheader_in_hand
/* 0BAA50 7F088060 AD810008 */   sw    $at, 8($t4)
/* 0BAA54 7F088064 AFA20160 */  sw    $v0, 0x160($sp)
/* 0BAA58 7F088068 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0BAA5C 7F08806C 8C4A0008 */  lw    $t2, 8($v0)
/* 0BAA60 7F088070 8C848BC0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BAA64 7F088074 8D45000C */  lw    $a1, 0xc($t2)
/* 0BAA68 7F088078 0FC1B3A3 */  jal   modelGetNodeRwData
/* 0BAA6C 7F08807C 24840230 */   addiu $a0, $a0, 0x230
/* 0BAA70 7F088080 0FC2F2A4 */  jal   dynAllocateMatrix
/* 0BAA74 7F088084 AFA20158 */   sw    $v0, 0x158($sp)
/* 0BAA78 7F088088 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0BAA7C 7F08808C 44812000 */  mtc1  $at, $f4
/* 0BAA80 7F088090 3C0B8007 */  lui   $t3, %hi(g_CurrentPlayer) # $t3, 0x8007
/* 0BAA84 7F088094 8D6B8BC0 */  lw    $t3, %lo(g_CurrentPlayer)($t3)
/* 0BAA88 7F088098 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0BAA8C 7F08809C 44813000 */  mtc1  $at, $f6
/* 0BAA90 7F0880A0 AFA20154 */  sw    $v0, 0x154($sp)
/* 0BAA94 7F0880A4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BAA98 7F0880A8 44814000 */  mtc1  $at, $f8
/* 0BAA9C 7F0880AC 8D6611BC */  lw    $a2, 0x11bc($t3)
/* 0BAAA0 7F0880B0 3C073FB3 */  lui   $a3, (0x3FB3458F >> 16) # lui $a3, 0x3fb3
/* 0BAAA4 7F0880B4 34E7458F */  ori   $a3, (0x3FB3458F & 0xFFFF) # ori $a3, $a3, 0x458f
/* 0BAAA8 7F0880B8 00402025 */  move  $a0, $v0
/* 0BAAAC 7F0880BC 27A50152 */  addiu $a1, $sp, 0x152
/* 0BAAB0 7F0880C0 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0BAAB4 7F0880C4 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0BAAB8 7F0880C8 0C003DB8 */  jal   guPerspective
/* 0BAABC 7F0880CC E7A80018 */   swc1  $f8, 0x18($sp)
/* 0BAAC0 7F0880D0 8FA301F8 */  lw    $v1, 0x1f8($sp)
/* 0BAAC4 7F0880D4 3C190103 */  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
/* 0BAAC8 7F0880D8 37390040 */  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 0BAACC 7F0880DC AC790000 */  sw    $t9, ($v1)
/* 0BAAD0 7F0880E0 8FB80154 */  lw    $t8, 0x154($sp)
/* 0BAAD4 7F0880E4 3C01C140 */  li    $at, 0xC1400000 # -12.000000
/* 0BAAD8 7F0880E8 44810000 */  mtc1  $at, $f0
/* 0BAADC 7F0880EC 3C018000 */  lui   $at, 0x8000
/* 0BAAE0 7F0880F0 3C0CBC00 */  lui   $t4, (0xBC00000E >> 16) # lui $t4, 0xbc00
/* 0BAAE4 7F0880F4 03017021 */  addu  $t6, $t8, $at
/* 0BAAE8 7F0880F8 358C000E */  ori   $t4, (0xBC00000E & 0xFFFF) # ori $t4, $t4, 0xe
/* 0BAAEC 7F0880FC AC6E0004 */  sw    $t6, 4($v1)
/* 0BAAF0 7F088100 24670008 */  addiu $a3, $v1, 8
/* 0BAAF4 7F088104 ACEC0000 */  sw    $t4, ($a3)
/* 0BAAF8 7F088108 97AD0152 */  lhu   $t5, 0x152($sp)
/* 0BAAFC 7F08810C 3C088007 */  lui   $t0, %hi(g_CurrentPlayer) # $t0, 0x8007
/* 0BAB00 7F088110 25088BC0 */  addiu $t0, %lo(g_CurrentPlayer) # addiu $t0, $t0, -0x7440
/* 0BAB04 7F088114 ACED0004 */  sw    $t5, 4($a3)
/* 0BAB08 7F088118 8D0F0000 */  lw    $t7, ($t0)
/* 0BAB0C 7F08811C 8FAB0158 */  lw    $t3, 0x158($sp)
/* 0BAB10 7F088120 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0BAB14 7F088124 8DEA01CC */  lw    $t2, 0x1cc($t7)
/* 0BAB18 7F088128 24E90008 */  addiu $t1, $a3, 8
/* 0BAB1C 7F08812C 27A4016C */  addiu $a0, $sp, 0x16c
/* 0BAB20 7F088130 AD6A0000 */  sw    $t2, ($t3)
/* 0BAB24 7F088134 8D020000 */  lw    $v0, ($t0)
/* 0BAB28 7F088138 27A60178 */  addiu $a2, $sp, 0x178
/* 0BAB2C 7F08813C C444054C */  lwc1  $f4, 0x54c($v0)
/* 0BAB30 7F088140 C44A0498 */  lwc1  $f10, 0x498($v0)
/* 0BAB34 7F088144 46002180 */  add.s $f6, $f4, $f0
/* 0BAB38 7F088148 C4440544 */  lwc1  $f4, 0x544($v0)
/* 0BAB3C 7F08814C 46065202 */  mul.s $f8, $f10, $f6
/* 0BAB40 7F088150 C44A04A0 */  lwc1  $f10, 0x4a0($v0)
/* 0BAB44 7F088154 46005187 */  neg.s $f6, $f10
/* 0BAB48 7F088158 46062282 */  mul.s $f10, $f4, $f6
/* 0BAB4C 7F08815C C444048C */  lwc1  $f4, 0x48c($v0)
/* 0BAB50 7F088160 460A2180 */  add.s $f6, $f4, $f10
/* 0BAB54 7F088164 46064100 */  add.s $f4, $f8, $f6
/* 0BAB58 7F088168 E7A4016C */  swc1  $f4, 0x16c($sp)
/* 0BAB5C 7F08816C C4480490 */  lwc1  $f8, 0x490($v0)
/* 0BAB60 7F088170 C44A0548 */  lwc1  $f10, 0x548($v0)
/* 0BAB64 7F088174 46085180 */  add.s $f6, $f10, $f8
/* 0BAB68 7F088178 E7A60170 */  swc1  $f6, 0x170($sp)
/* 0BAB6C 7F08817C C44A054C */  lwc1  $f10, 0x54c($v0)
/* 0BAB70 7F088180 C44404A0 */  lwc1  $f4, 0x4a0($v0)
/* 0BAB74 7F088184 46005200 */  add.s $f8, $f10, $f0
/* 0BAB78 7F088188 C44A0544 */  lwc1  $f10, 0x544($v0)
/* 0BAB7C 7F08818C 46082182 */  mul.s $f6, $f4, $f8
/* 0BAB80 7F088190 C4440498 */  lwc1  $f4, 0x498($v0)
/* 0BAB84 7F088194 46045202 */  mul.s $f8, $f10, $f4
/* 0BAB88 7F088198 C44A0494 */  lwc1  $f10, 0x494($v0)
/* 0BAB8C 7F08819C 46085100 */  add.s $f4, $f10, $f8
/* 0BAB90 7F0881A0 44814000 */  mtc1  $at, $f8
/* 0BAB94 7F0881A4 3C018005 */  lui   $at, %hi(D_8005527C) # $at, 0x8005
/* 0BAB98 7F0881A8 46043280 */  add.s $f10, $f6, $f4
/* 0BAB9C 7F0881AC E7AA0174 */  swc1  $f10, 0x174($sp)
/* 0BABA0 7F0881B0 C4460148 */  lwc1  $f6, 0x148($v0)
/* 0BABA4 7F0881B4 C42AAE50 */  lwc1  $f10, %lo(D_8005527C)($at)
/* 0BABA8 7F0881B8 AFA901F8 */  sw    $t1, 0x1f8($sp)
/* 0BABAC 7F0881BC 46064101 */  sub.s $f4, $f8, $f6
/* 0BABB0 7F0881C0 460A2202 */  mul.s $f8, $f4, $f10
/* 0BABB4 7F0881C4 44054000 */  mfc1  $a1, $f8
/* 0BABB8 7F0881C8 0FC1625E */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BABBC 7F0881CC 00000000 */   nop   
/* 0BABC0 7F0881D0 0FC1E111 */  jal   camGetWorldToScreenMtxf
/* 0BABC4 7F0881D4 00000000 */   nop   
/* 0BABC8 7F0881D8 00402025 */  move  $a0, $v0
/* 0BABCC 7F0881DC 0FC16150 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0BABD0 7F0881E0 27A50178 */   addiu $a1, $sp, 0x178
/* 0BABD4 7F0881E4 8FB90160 */  lw    $t9, 0x160($sp)
/* 0BABD8 7F0881E8 8724000E */  lh    $a0, 0xe($t9)
/* 0BABDC 7F0881EC 0004C180 */  sll   $t8, $a0, 6
/* 0BABE0 7F0881F0 0FC2F2B1 */  jal   dynAllocate
/* 0BABE4 7F0881F4 03002025 */   move  $a0, $t8
/* 0BABE8 7F0881F8 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0BABEC 7F0881FC 8C848BC0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BABF0 7F088200 AFA20164 */  sw    $v0, 0x164($sp)
/* 0BABF4 7F088204 8FA50160 */  lw    $a1, 0x160($sp)
/* 0BABF8 7F088208 24060004 */  li    $a2, 4
/* 0BABFC 7F08820C 0FC21F5D */  jal   seems_to_load_cuff_microcode
/* 0BAC00 7F088210 24840230 */   addiu $a0, $a0, 0x230
/* 0BAC04 7F088214 3C058007 */  lui   $a1, %hi(g_CurrentPlayer) # $a1, 0x8007
/* 0BAC08 7F088218 8FAC0164 */  lw    $t4, 0x164($sp)
/* 0BAC0C 7F08821C 8CA58BC0 */  lw    $a1, %lo(g_CurrentPlayer)($a1)
/* 0BAC10 7F088220 27AE0178 */  addiu $t6, $sp, 0x178
/* 0BAC14 7F088224 AFAE01B8 */  sw    $t6, 0x1b8($sp)
/* 0BAC18 7F088228 27A401B8 */  addiu $a0, $sp, 0x1b8
/* 0BAC1C 7F08822C AFAC01C8 */  sw    $t4, 0x1c8($sp)
/* 0BAC20 7F088230 0FC1BD9C */  jal   subcalcmatrices
/* 0BAC24 7F088234 24A50230 */   addiu $a1, $a1, 0x230
/* 0BAC28 7F088238 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BAC2C 7F08823C 44810000 */  mtc1  $at, $f0
/* 0BAC30 7F088240 3C018007 */  lui   $at, %hi(watch_time_0) # $at, 0x8007
/* 0BAC34 7F088244 8FAD0160 */  lw    $t5, 0x160($sp)
/* 0BAC38 7F088248 C4268504 */  lwc1  $f6, %lo(watch_time_0)($at)
/* 0BAC3C 7F08824C 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BAC40 7F088250 8DAF0008 */  lw    $t7, 8($t5)
/* 0BAC44 7F088254 4600310D */  trunc.w.s $f4, $f6
/* 0BAC48 7F088258 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BAC4C 7F08825C 8DEA0000 */  lw    $t2, ($t7)
/* 0BAC50 7F088260 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 0BAC54 7F088264 44192000 */  mfc1  $t9, $f4
/* 0BAC58 7F088268 8D430004 */  lw    $v1, 4($t2)
/* 0BAC5C 7F08826C 44814000 */  mtc1  $at, $f8
/* 0BAC60 7F088270 AFB90090 */  sw    $t9, 0x90($sp)
/* 0BAC64 7F088274 C44A0258 */  lwc1  $f10, 0x258($v0)
/* 0BAC68 7F088278 46085383 */  div.s $f14, $f10, $f8
/* 0BAC6C 7F08827C 460E003C */  c.lt.s $f0, $f14
/* 0BAC70 7F088280 00000000 */  nop   
/* 0BAC74 7F088284 45020003 */  bc1fl .L7F088294
/* 0BAC78 7F088288 C4660000 */   lwc1  $f6, ($v1)
/* 0BAC7C 7F08828C 46000386 */  mov.s $f14, $f0
/* 0BAC80 7F088290 C4660000 */  lwc1  $f6, ($v1)
.L7F088294:
/* 0BAC84 7F088294 C4440244 */  lwc1  $f4, 0x244($v0)
/* 0BAC88 7F088298 C44801D4 */  lwc1  $f8, 0x1d4($v0)
/* 0BAC8C 7F08829C 8FA80164 */  lw    $t0, 0x164($sp)
/* 0BAC90 7F0882A0 46043282 */  mul.s $f10, $f6, $f4
/* 0BAC94 7F0882A4 44808000 */  mtc1  $zero, $f16
/* 0BAC98 7F0882A8 C5000030 */  lwc1  $f0, 0x30($t0)
/* 0BAC9C 7F0882AC 27A40108 */  addiu $a0, $sp, 0x108
/* 0BACA0 7F0882B0 44058000 */  mfc1  $a1, $f16
/* 0BACA4 7F0882B4 44068000 */  mfc1  $a2, $f16
/* 0BACA8 7F0882B8 44078000 */  mfc1  $a3, $f16
/* 0BACAC 7F0882BC 460A4181 */  sub.s $f6, $f8, $f10
/* 0BACB0 7F0882C0 46003101 */  sub.s $f4, $f6, $f0
/* 0BACB4 7F0882C4 460E2202 */  mul.s $f8, $f4, $f14
/* 0BACB8 7F0882C8 46004280 */  add.s $f10, $f8, $f0
/* 0BACBC 7F0882CC E7AA00B4 */  swc1  $f10, 0xb4($sp)
/* 0BACC0 7F0882D0 C4440244 */  lwc1  $f4, 0x244($v0)
/* 0BACC4 7F0882D4 C4660008 */  lwc1  $f6, 8($v1)
/* 0BACC8 7F0882D8 C44A01D8 */  lwc1  $f10, 0x1d8($v0)
/* 0BACCC 7F0882DC C5020034 */  lwc1  $f2, 0x34($t0)
/* 0BACD0 7F0882E0 46043202 */  mul.s $f8, $f6, $f4
/* 0BACD4 7F0882E4 46085180 */  add.s $f6, $f10, $f8
/* 0BACD8 7F0882E8 46023101 */  sub.s $f4, $f6, $f2
/* 0BACDC 7F0882EC 460E2282 */  mul.s $f10, $f4, $f14
/* 0BACE0 7F0882F0 46025200 */  add.s $f8, $f10, $f2
/* 0BACE4 7F0882F4 E7A800B8 */  swc1  $f8, 0xb8($sp)
/* 0BACE8 7F0882F8 C4440244 */  lwc1  $f4, 0x244($v0)
/* 0BACEC 7F0882FC C4660004 */  lwc1  $f6, 4($v1)
/* 0BACF0 7F088300 C44801DC */  lwc1  $f8, 0x1dc($v0)
/* 0BACF4 7F088304 C50C0038 */  lwc1  $f12, 0x38($t0)
/* 0BACF8 7F088308 46043282 */  mul.s $f10, $f6, $f4
/* 0BACFC 7F08830C 460A4181 */  sub.s $f6, $f8, $f10
/* 0BAD00 7F088310 460C3101 */  sub.s $f4, $f6, $f12
/* 0BAD04 7F088314 460E2202 */  mul.s $f8, $f4, $f14
/* 0BAD08 7F088318 460C4280 */  add.s $f10, $f8, $f12
/* 0BAD0C 7F08831C E7AA00BC */  swc1  $f10, 0xbc($sp)
/* 0BAD10 7F088320 C44601E0 */  lwc1  $f6, 0x1e0($v0)
/* 0BAD14 7F088324 E7A60010 */  swc1  $f6, 0x10($sp)
/* 0BAD18 7F088328 C44401E4 */  lwc1  $f4, 0x1e4($v0)
/* 0BAD1C 7F08832C E7A40014 */  swc1  $f4, 0x14($sp)
/* 0BAD20 7F088330 C44801E8 */  lwc1  $f8, 0x1e8($v0)
/* 0BAD24 7F088334 E7A80018 */  swc1  $f8, 0x18($sp)
/* 0BAD28 7F088338 C44A01EC */  lwc1  $f10, 0x1ec($v0)
/* 0BAD2C 7F08833C E7AA001C */  swc1  $f10, 0x1c($sp)
/* 0BAD30 7F088340 C44601F0 */  lwc1  $f6, 0x1f0($v0)
/* 0BAD34 7F088344 E7A60020 */  swc1  $f6, 0x20($sp)
/* 0BAD38 7F088348 C44401F4 */  lwc1  $f4, 0x1f4($v0)
/* 0BAD3C 7F08834C E7AE0168 */  swc1  $f14, 0x168($sp)
/* 0BAD40 7F088350 0FC1676C */  jal   matrix_4x4_7F059908
/* 0BAD44 7F088354 E7A40024 */   swc1  $f4, 0x24($sp)
/* 0BAD48 7F088358 8FA40164 */  lw    $a0, 0x164($sp)
/* 0BAD4C 7F08835C 0FC16342 */  jal   matrix_4x4_get_rotation_around_xyz
/* 0BAD50 7F088360 27A500FC */   addiu $a1, $sp, 0xfc
/* 0BAD54 7F088364 27A40108 */  addiu $a0, $sp, 0x108
/* 0BAD58 7F088368 0FC16342 */  jal   matrix_4x4_get_rotation_around_xyz
/* 0BAD5C 7F08836C 27A500F0 */   addiu $a1, $sp, 0xf0
/* 0BAD60 7F088370 27A400FC */  addiu $a0, $sp, 0xfc
/* 0BAD64 7F088374 0FC16E29 */  jal   quaternion_set_rotation_around_xyzf
/* 0BAD68 7F088378 27A500E0 */   addiu $a1, $sp, 0xe0
/* 0BAD6C 7F08837C 27A400F0 */  addiu $a0, $sp, 0xf0
/* 0BAD70 7F088380 0FC16E29 */  jal   quaternion_set_rotation_around_xyzf
/* 0BAD74 7F088384 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0BAD78 7F088388 27A400E0 */  addiu $a0, $sp, 0xe0
/* 0BAD7C 7F08838C 0FC170B0 */  jal   quaternion_ensure_shortest_path
/* 0BAD80 7F088390 27A500D0 */   addiu $a1, $sp, 0xd0
/* 0BAD84 7F088394 27A400E0 */  addiu $a0, $sp, 0xe0
/* 0BAD88 7F088398 27A500D0 */  addiu $a1, $sp, 0xd0
/* 0BAD8C 7F08839C 8FA60168 */  lw    $a2, 0x168($sp)
/* 0BAD90 7F0883A0 0FC16FAE */  jal   quaternion_slerp
/* 0BAD94 7F0883A4 27A700C0 */   addiu $a3, $sp, 0xc0
/* 0BAD98 7F0883A8 27A400C0 */  addiu $a0, $sp, 0xc0
/* 0BAD9C 7F0883AC 0FC16EB6 */  jal   quaternion_to_matrix
/* 0BADA0 7F0883B0 8FA50164 */   lw    $a1, 0x164($sp)
/* 0BADA4 7F0883B4 27A400B4 */  addiu $a0, $sp, 0xb4
/* 0BADA8 7F0883B8 0FC16390 */  jal   matrix_4x4_set_position
/* 0BADAC 7F0883BC 8FA50164 */   lw    $a1, 0x164($sp)
/* 0BADB0 7F0883C0 3C188007 */  lui   $t8, %hi(g_CurrentPlayer) # $t8, 0x8007
/* 0BADB4 7F0883C4 8F188BC0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0BADB8 7F0883C8 8FA50164 */  lw    $a1, 0x164($sp)
/* 0BADBC 7F0883CC 0FC163C9 */  jal   matrix_scalar_multiply
/* 0BADC0 7F0883D0 C70C0244 */   lwc1  $f12, 0x244($t8)
/* 0BADC4 7F0883D4 2403003C */  li    $v1, 60
/* 0BADC8 7F0883D8 8FA40090 */  lw    $a0, 0x90($sp)
/* 0BADCC 7F0883DC 3C018005 */  lui   $at, %hi(D_80055280) # $at, 0x8005
/* 0BADD0 7F0883E0 C422AE54 */  lwc1  $f2, %lo(D_80055280)($at)
/* 0BADD4 7F0883E4 0083001A */  div   $zero, $a0, $v1
/* 0BADD8 7F0883E8 00007010 */  mfhi  $t6
/* 0BADDC 7F0883EC 00001012 */  mflo  $v0
/* 0BADE0 7F0883F0 448E4000 */  mtc1  $t6, $f8
/* 0BADE4 7F0883F4 44808000 */  mtc1  $zero, $f16
/* 0BADE8 7F0883F8 0043001A */  div   $zero, $v0, $v1
/* 0BADEC 7F0883FC 00006010 */  mfhi  $t4
/* 0BADF0 7F088400 00006812 */  mflo  $t5
/* 0BADF4 7F088404 468042A0 */  cvt.s.w $f10, $f8
/* 0BADF8 7F088408 14600002 */  bnez  $v1, .L7F088414
/* 0BADFC 7F08840C 00000000 */   nop   
/* 0BAE00 7F088410 0007000D */  break 7
.L7F088414:
/* 0BAE04 7F088414 2401FFFF */  li    $at, -1
/* 0BAE08 7F088418 14610004 */  bne   $v1, $at, .L7F08842C
/* 0BAE0C 7F08841C 3C018000 */   lui   $at, 0x8000
/* 0BAE10 7F088420 14810002 */  bne   $a0, $at, .L7F08842C
/* 0BAE14 7F088424 00000000 */   nop   
/* 0BAE18 7F088428 0006000D */  break 6
.L7F08842C:
/* 0BAE1C 7F08842C 01A3001A */  div   $zero, $t5, $v1
/* 0BAE20 7F088430 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BAE24 7F088434 44813000 */  mtc1  $at, $f6
/* 0BAE28 7F088438 448C4000 */  mtc1  $t4, $f8
/* 0BAE2C 7F08843C 00007810 */  mfhi  $t7
/* 0BAE30 7F088440 46065103 */  div.s $f4, $f10, $f6
/* 0BAE34 7F088444 14600002 */  bnez  $v1, .L7F088450
/* 0BAE38 7F088448 00000000 */   nop   
/* 0BAE3C 7F08844C 0007000D */  break 7
.L7F088450:
/* 0BAE40 7F088450 2401FFFF */  li    $at, -1
/* 0BAE44 7F088454 14610004 */  bne   $v1, $at, .L7F088468
/* 0BAE48 7F088458 3C018000 */   li    $at, 0x80000000 # -0.000000
/* 0BAE4C 7F08845C 14410002 */  bne   $v0, $at, .L7F088468
/* 0BAE50 7F088460 00000000 */   nop   
/* 0BAE54 7F088464 0006000D */  break 6
.L7F088468:
/* 0BAE58 7F088468 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BAE5C 7F08846C 8FB90160 */  lw    $t9, 0x160($sp)
/* 0BAE60 7F088470 468042A0 */  cvt.s.w $f10, $f8
/* 0BAE64 7F088474 46045180 */  add.s $f6, $f10, $f4
/* 0BAE68 7F088478 44812000 */  mtc1  $at, $f4
/* 0BAE6C 7F08847C 46003207 */  neg.s $f8, $f6
/* 0BAE70 7F088480 448F3000 */  mtc1  $t7, $f6
/* 0BAE74 7F088484 46024282 */  mul.s $f10, $f8, $f2
/* 0BAE78 7F088488 46803220 */  cvt.s.w $f8, $f6
/* 0BAE7C 7F08848C 46045483 */  div.s $f18, $f10, $f4
/* 0BAE80 7F088490 46004287 */  neg.s $f10, $f8
/* 0BAE84 7F088494 46025102 */  mul.s $f4, $f10, $f2
/* 0BAE88 7F088498 4610903C */  c.lt.s $f18, $f16
/* 0BAE8C 7F08849C 46009306 */  mov.s $f12, $f18
/* 0BAE90 7F0884A0 14600002 */  bnez  $v1, .L7F0884AC
/* 0BAE94 7F0884A4 00000000 */   nop   
/* 0BAE98 7F0884A8 0007000D */  break 7
.L7F0884AC:
/* 0BAE9C 7F0884AC 2401FFFF */  li    $at, -1
/* 0BAEA0 7F0884B0 14610004 */  bne   $v1, $at, .L7F0884C4
/* 0BAEA4 7F0884B4 3C018000 */   li    $at, 0x80000000 # -0.000000
/* 0BAEA8 7F0884B8 15A10002 */  bne   $t5, $at, .L7F0884C4
/* 0BAEAC 7F0884BC 00000000 */   nop   
/* 0BAEB0 7F0884C0 0006000D */  break 6
.L7F0884C4:
/* 0BAEB4 7F0884C4 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BAEB8 7F0884C8 44813000 */  mtc1  $at, $f6
/* 0BAEBC 7F0884CC 44815000 */  mtc1  $at, $f10
/* 0BAEC0 7F0884D0 24010E10 */  li    $at, 3600
/* 0BAEC4 7F0884D4 0041001A */  div   $zero, $v0, $at
/* 0BAEC8 7F0884D8 00005012 */  mflo  $t2
/* 0BAECC 7F0884DC 2401000C */  li    $at, 12
/* 0BAED0 7F0884E0 46062203 */  div.s $f8, $f4, $f6
/* 0BAED4 7F0884E4 0141001A */  div   $zero, $t2, $at
/* 0BAED8 7F0884E8 460A9103 */  div.s $f4, $f18, $f10
/* 0BAEDC 7F0884EC 00005810 */  mfhi  $t3
/* 0BAEE0 7F0884F0 448B5000 */  mtc1  $t3, $f10
/* 0BAEE4 7F0884F4 3C014140 */  li    $at, 0x41400000 # 12.000000
/* 0BAEE8 7F0884F8 46044180 */  add.s $f6, $f8, $f4
/* 0BAEEC 7F0884FC 46805220 */  cvt.s.w $f8, $f10
/* 0BAEF0 7F088500 E7A60040 */  swc1  $f6, 0x40($sp)
/* 0BAEF4 7F088504 46003386 */  mov.s $f14, $f6
/* 0BAEF8 7F088508 46004107 */  neg.s $f4, $f8
/* 0BAEFC 7F08850C 44814000 */  mtc1  $at, $f8
/* 0BAF00 7F088510 46022282 */  mul.s $f10, $f4, $f2
/* 0BAF04 7F088514 46085103 */  div.s $f4, $f10, $f8
/* 0BAF08 7F088518 44815000 */  mtc1  $at, $f10
/* 0BAF0C 7F08851C 3C014434 */  li    $at, 0x44340000 # 720.000000
/* 0BAF10 7F088520 460A3203 */  div.s $f8, $f6, $f10
/* 0BAF14 7F088524 44815000 */  mtc1  $at, $f10
/* 0BAF18 7F088528 46082180 */  add.s $f6, $f4, $f8
/* 0BAF1C 7F08852C 460A9103 */  div.s $f4, $f18, $f10
/* 0BAF20 7F088530 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 0BAF24 7F088534 46043200 */  add.s $f8, $f6, $f4
/* 0BAF28 7F088538 E7A8003C */  swc1  $f8, 0x3c($sp)
/* 0BAF2C 7F08853C 46004006 */  mov.s $f0, $f8
/* 0BAF30 7F088540 45000006 */  bc1f  .L7F08855C
/* 0BAF34 7F088544 C7A6003C */   lwc1  $f6, 0x3c($sp)
/* 0BAF38 7F088548 46026300 */  add.s $f12, $f12, $f2
.L7F08854C:
/* 0BAF3C 7F08854C 4610603C */  c.lt.s $f12, $f16
/* 0BAF40 7F088550 00000000 */  nop   
/* 0BAF44 7F088554 4503FFFD */  bc1tl .L7F08854C
/* 0BAF48 7F088558 46026300 */   add.s $f12, $f12, $f2
.L7F08855C:
/* 0BAF4C 7F08855C 4610503C */  c.lt.s $f10, $f16
/* 0BAF50 7F088560 00000000 */  nop   
/* 0BAF54 7F088564 45020007 */  bc1fl .L7F088584
/* 0BAF58 7F088568 4610303C */   c.lt.s $f6, $f16
/* 0BAF5C 7F08856C 46027380 */  add.s $f14, $f14, $f2
.L7F088570:
/* 0BAF60 7F088570 4610703C */  c.lt.s $f14, $f16
/* 0BAF64 7F088574 00000000 */  nop   
/* 0BAF68 7F088578 4503FFFD */  bc1tl .L7F088570
/* 0BAF6C 7F08857C 46027380 */   add.s $f14, $f14, $f2
/* 0BAF70 7F088580 4610303C */  c.lt.s $f6, $f16
.L7F088584:
/* 0BAF74 7F088584 00000000 */  nop   
/* 0BAF78 7F088588 45020007 */  bc1fl .L7F0885A8
/* 0BAF7C 7F08858C 8F380008 */   lw    $t8, 8($t9)
/* 0BAF80 7F088590 46020000 */  add.s $f0, $f0, $f2
.L7F088594:
/* 0BAF84 7F088594 4610003C */  c.lt.s $f0, $f16
/* 0BAF88 7F088598 00000000 */  nop   
/* 0BAF8C 7F08859C 4503FFFD */  bc1tl .L7F088594
/* 0BAF90 7F0885A0 46020000 */   add.s $f0, $f0, $f2
/* 0BAF94 7F0885A4 8F380008 */  lw    $t8, 8($t9)
.L7F0885A8:
/* 0BAF98 7F0885A8 8FA60164 */  lw    $a2, 0x164($sp)
/* 0BAF9C 7F0885AC 44050000 */  mfc1  $a1, $f0
/* 0BAFA0 7F0885B0 8F0E0000 */  lw    $t6, ($t8)
/* 0BAFA4 7F0885B4 24C60040 */  addiu $a2, $a2, 0x40
/* 0BAFA8 7F0885B8 8DC40004 */  lw    $a0, 4($t6)
/* 0BAFAC 7F0885BC E7AE0098 */  swc1  $f14, 0x98($sp)
/* 0BAFB0 7F0885C0 E7AC009C */  swc1  $f12, 0x9c($sp)
/* 0BAFB4 7F0885C4 0FC1625E */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BAFB8 7F0885C8 AFA60040 */   sw    $a2, 0x40($sp)
/* 0BAFBC 7F0885CC 8FA50040 */  lw    $a1, 0x40($sp)
/* 0BAFC0 7F0885D0 0FC16144 */  jal   matrix_4x4_multiply_in_place
/* 0BAFC4 7F0885D4 8FA40164 */   lw    $a0, 0x164($sp)
/* 0BAFC8 7F0885D8 8FAC0160 */  lw    $t4, 0x160($sp)
/* 0BAFCC 7F0885DC C7AE0098 */  lwc1  $f14, 0x98($sp)
/* 0BAFD0 7F0885E0 8FA60164 */  lw    $a2, 0x164($sp)
/* 0BAFD4 7F0885E4 8D8D0008 */  lw    $t5, 8($t4)
/* 0BAFD8 7F0885E8 44057000 */  mfc1  $a1, $f14
/* 0BAFDC 7F0885EC 24C60080 */  addiu $a2, $a2, 0x80
/* 0BAFE0 7F0885F0 8DAF0004 */  lw    $t7, 4($t5)
/* 0BAFE4 7F0885F4 8DE40004 */  lw    $a0, 4($t7)
/* 0BAFE8 7F0885F8 0FC1625E */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BAFEC 7F0885FC AFA60040 */   sw    $a2, 0x40($sp)
/* 0BAFF0 7F088600 8FA50040 */  lw    $a1, 0x40($sp)
/* 0BAFF4 7F088604 0FC16144 */  jal   matrix_4x4_multiply_in_place
/* 0BAFF8 7F088608 8FA40164 */   lw    $a0, 0x164($sp)
/* 0BAFFC 7F08860C 8FAA0160 */  lw    $t2, 0x160($sp)
/* 0BB000 7F088610 C7AC009C */  lwc1  $f12, 0x9c($sp)
/* 0BB004 7F088614 8FA60164 */  lw    $a2, 0x164($sp)
/* 0BB008 7F088618 8D4B0008 */  lw    $t3, 8($t2)
/* 0BB00C 7F08861C 44056000 */  mfc1  $a1, $f12
/* 0BB010 7F088620 24C600C0 */  addiu $a2, $a2, 0xc0
/* 0BB014 7F088624 8D790008 */  lw    $t9, 8($t3)
/* 0BB018 7F088628 8F240004 */  lw    $a0, 4($t9)
/* 0BB01C 7F08862C 0FC1625E */  jal   matrix_4x4_set_position_and_rotation_around_y
/* 0BB020 7F088630 AFA60040 */   sw    $a2, 0x40($sp)
/* 0BB024 7F088634 8FA50040 */  lw    $a1, 0x40($sp)
/* 0BB028 7F088638 0FC16144 */  jal   matrix_4x4_multiply_in_place
/* 0BB02C 7F08863C 8FA40164 */   lw    $a0, 0x164($sp)
/* 0BB030 7F088640 8FAE01F8 */  lw    $t6, 0x1f8($sp)
/* 0BB034 7F088644 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BB038 7F088648 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BB03C 7F08864C 24180003 */  li    $t8, 3
/* 0BB040 7F088650 240C0004 */  li    $t4, 4
/* 0BB044 7F088654 AFB801C0 */  sw    $t8, 0x1c0($sp)
/* 0BB048 7F088658 AFA001BC */  sw    $zero, 0x1bc($sp)
/* 0BB04C 7F08865C AFAC01E8 */  sw    $t4, 0x1e8($sp)
/* 0BB050 7F088660 AFAE01C4 */  sw    $t6, 0x1c4($sp)
/* 0BB054 7F088664 8C4301C8 */  lw    $v1, 0x1c8($v0)
/* 0BB058 7F088668 24010005 */  li    $at, 5
/* 0BB05C 7F08866C 27A401B8 */  addiu $a0, $sp, 0x1b8
/* 0BB060 7F088670 10610002 */  beq   $v1, $at, .L7F08867C
/* 0BB064 7F088674 2401000C */   li    $at, 12
/* 0BB068 7F088678 14610003 */  bne   $v1, $at, .L7F088688
.L7F08867C:
/* 0BB06C 7F08867C 240D00CD */   li    $t5, 205
/* 0BB070 7F088680 1000000C */  b     .L7F0886B4
/* 0BB074 7F088684 AFAD01EC */   sw    $t5, 0x1ec($sp)
.L7F088688:
/* 0BB078 7F088688 904A0FD4 */  lbu   $t2, 0xfd4($v0)
/* 0BB07C 7F08868C 904F0FD7 */  lbu   $t7, 0xfd7($v0)
/* 0BB080 7F088690 90580FD5 */  lbu   $t8, 0xfd5($v0)
/* 0BB084 7F088694 904D0FD6 */  lbu   $t5, 0xfd6($v0)
/* 0BB088 7F088698 000A5E00 */  sll   $t3, $t2, 0x18
/* 0BB08C 7F08869C 01EBC825 */  or    $t9, $t7, $t3
/* 0BB090 7F0886A0 00187400 */  sll   $t6, $t8, 0x10
/* 0BB094 7F0886A4 032E6025 */  or    $t4, $t9, $t6
/* 0BB098 7F0886A8 000D5200 */  sll   $t2, $t5, 8
/* 0BB09C 7F0886AC 018A7825 */  or    $t7, $t4, $t2
/* 0BB0A0 7F0886B0 AFAF01EC */  sw    $t7, 0x1ec($sp)
.L7F0886B4:
/* 0BB0A4 7F0886B4 0FC1D1D6 */  jal   subdraw
/* 0BB0A8 7F0886B8 24450230 */   addiu $a1, $v0, 0x230
/* 0BB0AC 7F0886BC 8FAB01C4 */  lw    $t3, 0x1c4($sp)
/* 0BB0B0 7F0886C0 8FB80160 */  lw    $t8, 0x160($sp)
/* 0BB0B4 7F0886C4 AFAB01F8 */  sw    $t3, 0x1f8($sp)
/* 0BB0B8 7F0886C8 8F190008 */  lw    $t9, 8($t8)
/* 0BB0BC 7F0886CC 8F2E0008 */  lw    $t6, 8($t9)
/* 0BB0C0 7F0886D0 8DCD0004 */  lw    $t5, 4($t6)
/* 0BB0C4 7F0886D4 0FC2F2A4 */  jal   dynAllocateMatrix
/* 0BB0C8 7F0886D8 AFAD008C */   sw    $t5, 0x8c($sp)
/* 0BB0CC 7F0886DC AFA20048 */  sw    $v0, 0x48($sp)
/* 0BB0D0 7F0886E0 8FA4008C */  lw    $a0, 0x8c($sp)
/* 0BB0D4 7F0886E4 0FC16383 */  jal   matrix_4x4_set_identity_and_position
/* 0BB0D8 7F0886E8 27A5004C */   addiu $a1, $sp, 0x4c
/* 0BB0DC 7F0886EC 8FA40164 */  lw    $a0, 0x164($sp)
/* 0BB0E0 7F0886F0 0FC16144 */  jal   matrix_4x4_multiply_in_place
/* 0BB0E4 7F0886F4 27A5004C */   addiu $a1, $sp, 0x4c
/* 0BB0E8 7F0886F8 0FC16443 */  jal   matrix_4x4_7F058C64
/* 0BB0EC 7F0886FC 00000000 */   nop   
/* 0BB0F0 7F088700 27A4004C */  addiu $a0, $sp, 0x4c
/* 0BB0F4 7F088704 0FC16451 */  jal   matrix_4x4_f32_to_s32
/* 0BB0F8 7F088708 8FA50048 */   lw    $a1, 0x48($sp)
/* 0BB0FC 7F08870C 0FC1644C */  jal   matrix_4x4_7F058C88
/* 0BB100 7F088710 00000000 */   nop   
/* 0BB104 7F088714 3C0C8007 */  lui   $t4, %hi(g_CurrentPlayer) # $t4, 0x8007
/* 0BB108 7F088718 8D8C8BC0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0BB10C 7F08871C 8FA401F8 */  lw    $a0, 0x1f8($sp)
/* 0BB110 7F088720 8D8301C8 */  lw    $v1, 0x1c8($t4)
/* 0BB114 7F088724 38660005 */  xori  $a2, $v1, 5
/* 0BB118 7F088728 2CC60001 */  sltiu $a2, $a2, 1
/* 0BB11C 7F08872C 14C00003 */  bnez  $a2, .L7F08873C
/* 0BB120 7F088730 00000000 */   nop   
/* 0BB124 7F088734 3866000C */  xori  $a2, $v1, 0xc
/* 0BB128 7F088738 2CC60001 */  sltiu $a2, $a2, 1
.L7F08873C:
/* 0BB12C 7F08873C 0FC2AF3A */  jal   sub_GAME_7F0ACA28
/* 0BB130 7F088740 8FA50048 */   lw    $a1, 0x48($sp)
/* 0BB134 7F088744 0FC16443 */  jal   matrix_4x4_7F058C64
/* 0BB138 7F088748 AFA201F8 */   sw    $v0, 0x1f8($sp)
/* 0BB13C 7F08874C 3C0A8007 */  lui   $t2, %hi(g_CurrentPlayer) # $t2, 0x8007
/* 0BB140 7F088750 8D4A8BC0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0BB144 7F088754 8FAF0160 */  lw    $t7, 0x160($sp)
/* 0BB148 7F088758 8D44023C */  lw    $a0, 0x23c($t2)
/* 0BB14C 7F08875C 0FC2300F */  jal   bondviewTransformManyPosToViewMatrix
/* 0BB150 7F088760 85E5000E */   lh    $a1, 0xe($t7)
/* 0BB154 7F088764 0FC1644C */  jal   matrix_4x4_7F058C88
/* 0BB158 7F088768 00000000 */   nop   
.L7F08876C:
/* 0BB15C 7F08876C 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F088770:
/* 0BB160 7F088770 8FA201F8 */  lw    $v0, 0x1f8($sp)
/* 0BB164 7F088774 27BD01F8 */  addiu $sp, $sp, 0x1f8
/* 0BB168 7F088778 03E00008 */  jr    $ra
/* 0BB16C 7F08877C 00000000 */   nop   
)
#endif



#endif


#ifdef NONMATCHING
s32 sub_GAME_7F088618(void *arg0) {
    ? sp78;
    s32 spB8;
    s32 spBC;
    ? temp_ret;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s0_5;
    void *temp_s0_6;
    void *temp_s0_7;
    void *temp_s0_8;
    void *temp_s0_9;
    void *temp_s0_10;
    void *temp_s0_11;

    // Node 0
    sub_GAME_7F0A2F30((g_CurrentPlayer + 0x12b8), 0x2e, 1, g_CurrentPlayer->apparentarmour);
    sub_GAME_7F0A3330((g_CurrentPlayer + 0x19f8), (g_CurrentPlayer + 0x800012b8), 0x2e);
    sub_GAME_7F0A2F30((g_CurrentPlayer + 0x1598), 0x2e, -1, g_CurrentPlayer->apparenthealth);
    sub_GAME_7F0A3330((g_CurrentPlayer + 0x2128), (g_CurrentPlayer + 0x80001598), 0x2e);
    spBC = dynAllocateMatrix();
    temp_ret = dynAllocateMatrix();
    spB8 = temp_ret;
    guOrtho(temp_ret, (-800.0f * D_800364CC), (800.0f * D_800364CC), (-600.0f * D_800364CC), (f32) (600.0f * D_800364CC), -100.0f, 1000.0f, 1.0f);
    *arg0 = 0x1030040;
    temp_s0 = (arg0 + 8);
    arg0->unk4 = osVirtualToPhysical(spB8);
    matrix_4x4_7F059694(&sp78, 0.0f, &0x43FA0004, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f);
    matrix_4x4_f32_to_s32(&sp78, spBC);
    *temp_s0 = 0x1020040;
    temp_s0_2 = (temp_s0 + 8);
    temp_s0->unk4 = osVirtualToPhysical(spBC);
    temp_s0_3 = (temp_s0_2 + 8);
    *temp_s0_2 = 0xe7000000;//gDPPipeSync(glistp++);
    temp_s0_2->unk4 = 0;
    temp_s0_4 = (temp_s0_3 + 8);
    *temp_s0_3 = 0xba001402; //gDPSetCyceType(glistp++, G_CYC_1CYCLE);
    temp_s0_3->unk4 = 0;
    temp_s0_5 = (temp_s0_4 + 8);
    *temp_s0_4 = 0xb900031d; //gDPSetRenderMode(G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    temp_s0_4->unk4 = 0x5041c8;
    temp_s0_6 = (temp_s0_5 + 8);
    *temp_s0_5 = 0xb9000002;
    *temp_s0_5 = 0;
    temp_s0_7 = (temp_s0_6 + 8);
    *temp_s0_6 = 0xfcffffff;//gDPSetCombineMode(glistp++,SHADE, SHADE2);
    temp_s0_6->unk4 = 0xfffe793c;
    temp_s0_8 = (temp_s0_7 + 8);
    *temp_s0_7 = 0xfa000000;//gDPSetPrimColor(glistp++, 0, 0, 230, 230, 230, 0);
    temp_s0_7->unk4 = 0xe6e6e600;
    temp_s0_9 = (temp_s0_8 + 8);
    *temp_s0_8 = 0xb6000000;//gDPClearGeometryMode(glistp++, G_CULL_FRONT | G_CULL_BACK );
    temp_s0_8->unk4 = 0x3000;
    *temp_s0_9 = 0x6000000;
    temp_s0_10 = (temp_s0_9 + 8);
    temp_s0_9->unk4 = (s32) (g_CurrentPlayer + 0x800019f8);
    *temp_s0_10 = 0x6000000;
    temp_s0_11 = (temp_s0_10 + 8);
    temp_s0_10->unk4 = (s32) (g_CurrentPlayer + 0x80002128);
    *temp_s0_11 = 0x1030040;
    temp_s0_11->unk4 = osVirtualToPhysical(currentPlayerGetProjectionMatrix(temp_s0_9, temp_s0_10, 0x6000000, temp_s0_6));
    return (temp_s0_11 + 8);
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F088618
/* 0BD148 7F088618 27BDFF40 */  addiu $sp, $sp, -0xc0
/* 0BD14C 7F08861C AFB20038 */  sw    $s2, 0x38($sp)
/* 0BD150 7F088620 3C128008 */  lui   $s2, %hi(g_CurrentPlayer)
/* 0BD154 7F088624 2652A0B0 */  addiu $s2, %lo(g_CurrentPlayer) # addiu $s2, $s2, -0x5f50
/* 0BD158 7F088628 AFB10034 */  sw    $s1, 0x34($sp)
/* 0BD15C 7F08862C 8E510000 */  lw    $s1, ($s2)
/* 0BD160 7F088630 AFB00030 */  sw    $s0, 0x30($sp)
/* 0BD164 7F088634 00808025 */  move  $s0, $a0
/* 0BD168 7F088638 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0BD16C 7F08863C 2405002E */  li    $a1, 46
/* 0BD170 7F088640 24060001 */  li    $a2, 1
/* 0BD174 7F088644 8E2700F0 */  lw    $a3, 0xf0($s1)
/* 0BD178 7F088648 0FC28BCC */  jal   sub_GAME_7F0A2F30
/* 0BD17C 7F08864C 262412B8 */   addiu $a0, $s1, 0x12b8
/* 0BD180 7F088650 8E510000 */  lw    $s1, ($s2)
/* 0BD184 7F088654 3C018000 */  lui   $at, (0x800012B8 >> 16)
/* 0BD188 7F088658 342112B8 */  ori   $at, (0x800012B8 & 0xFFFF) # ori $at, $at, 0x12b8
/* 0BD18C 7F08865C 2406002E */  li    $a2, 46
/* 0BD190 7F088660 02212821 */  addu  $a1, $s1, $at
/* 0BD194 7F088664 0FC28CCC */  jal   sub_GAME_7F0A3330
/* 0BD198 7F088668 262419F8 */   addiu $a0, $s1, 0x19f8
/* 0BD19C 7F08866C 8E510000 */  lw    $s1, ($s2)
/* 0BD1A0 7F088670 2405002E */  li    $a1, 46
/* 0BD1A4 7F088674 2406FFFF */  li    $a2, -1
/* 0BD1A8 7F088678 26241598 */  addiu $a0, $s1, 0x1598
/* 0BD1AC 7F08867C 0FC28BCC */  jal   sub_GAME_7F0A2F30
/* 0BD1B0 7F088680 8E2700EC */   lw    $a3, 0xec($s1)
/* 0BD1B4 7F088684 8E510000 */  lw    $s1, ($s2)
/* 0BD1B8 7F088688 3C018000 */  lui   $at, (0x80001598 >> 16)
/* 0BD1BC 7F08868C 34211598 */  ori   $at, (0x80001598 & 0xFFFF) # ori $at, $at, 0x1598
/* 0BD1C0 7F088690 2406002E */  li    $a2, 46
/* 0BD1C4 7F088694 02212821 */  addu  $a1, $s1, $at
/* 0BD1C8 7F088698 0FC28CCC */  jal   sub_GAME_7F0A3330
/* 0BD1CC 7F08869C 26242128 */   addiu $a0, $s1, 0x2128
/* 0BD1D0 7F0886A0 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0BD1D4 7F0886A4 00000000 */   nop
/* 0BD1D8 7F0886A8 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0BD1DC 7F0886AC AFA200BC */   sw    $v0, 0xbc($sp)
/* 0BD1E0 7F0886B0 3C018003 */  lui   $at, %hi(D_800364CC)
/* 0BD1E4 7F0886B4 C42064CC */  lwc1  $f0, %lo(D_800364CC)($at)
/* 0BD1E8 7F0886B8 3C01C448 */  li    $at, 0xC4480000 # -800.000000
/* 0BD1EC 7F0886BC 44812000 */  mtc1  $at, $f4
/* 0BD1F0 7F0886C0 3C014448 */  li    $at, 0x44480000 # 800.000000
/* 0BD1F4 7F0886C4 44814000 */  mtc1  $at, $f8
/* 0BD1F8 7F0886C8 46002182 */  mul.s $f6, $f4, $f0
/* 0BD1FC 7F0886CC 3C01C416 */  li    $at, 0xC4160000 # -600.000000
/* 0BD200 7F0886D0 44818000 */  mtc1  $at, $f16
/* 0BD204 7F0886D4 46004282 */  mul.s $f10, $f8, $f0
/* 0BD208 7F0886D8 3C014416 */  li    $at, 0x44160000 # 600.000000
/* 0BD20C 7F0886DC 44812000 */  mtc1  $at, $f4
/* 0BD210 7F0886E0 46008482 */  mul.s $f18, $f16, $f0
/* 0BD214 7F0886E4 3C01C2C8 */  li    $at, 0xC2C80000 # -100.000000
/* 0BD218 7F0886E8 44053000 */  mfc1  $a1, $f6
/* 0BD21C 7F0886EC 46002182 */  mul.s $f6, $f4, $f0
/* 0BD220 7F0886F0 44814000 */  mtc1  $at, $f8
/* 0BD224 7F0886F4 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0BD228 7F0886F8 44065000 */  mfc1  $a2, $f10
/* 0BD22C 7F0886FC 44815000 */  mtc1  $at, $f10
/* 0BD230 7F088700 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BD234 7F088704 44818000 */  mtc1  $at, $f16
/* 0BD238 7F088708 44079000 */  mfc1  $a3, $f18
/* 0BD23C 7F08870C AFA200B8 */  sw    $v0, 0xb8($sp)
/* 0BD240 7F088710 E7A60010 */  swc1  $f6, 0x10($sp)
/* 0BD244 7F088714 00402025 */  move  $a0, $v0
/* 0BD248 7F088718 E7A80014 */  swc1  $f8, 0x14($sp)
/* 0BD24C 7F08871C E7AA0018 */  swc1  $f10, 0x18($sp)
/* 0BD250 7F088720 0C005AF1 */  jal   guOrtho
/* 0BD254 7F088724 E7B0001C */   swc1  $f16, 0x1c($sp)
/* 0BD258 7F088728 3C0E0103 */  lui   $t6, (0x01030040 >> 16) # lui $t6, 0x103
/* 0BD25C 7F08872C 35CE0040 */  ori   $t6, (0x01030040 & 0xFFFF) # ori $t6, $t6, 0x40
/* 0BD260 7F088730 02008825 */  move  $s1, $s0
/* 0BD264 7F088734 AE2E0000 */  sw    $t6, ($s1)
/* 0BD268 7F088738 8FA400B8 */  lw    $a0, 0xb8($sp)
/* 0BD26C 7F08873C 0C003A2C */  jal   osVirtualToPhysical
/* 0BD270 7F088740 26100008 */   addiu $s0, $s0, 8
/* 0BD274 7F088744 44800000 */  mtc1  $zero, $f0
/* 0BD278 7F088748 AE220004 */  sw    $v0, 4($s1)
/* 0BD27C 7F08874C 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0BD280 7F088750 44819000 */  mtc1  $at, $f18
/* 0BD284 7F088754 44050000 */  mfc1  $a1, $f0
/* 0BD288 7F088758 44070000 */  mfc1  $a3, $f0
/* 0BD28C 7F08875C 27A40078 */  addiu $a0, $sp, 0x78
/* 0BD290 7F088760 3C0643FA */  lui   $a2, %hi(0x43FA0004) # $a2, 0x43fa
/* 0BD294 7F088764 E7A00020 */  swc1  $f0, 0x20($sp)
/* 0BD298 7F088768 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 0BD29C 7F08876C E7A00018 */  swc1  $f0, 0x18($sp)
/* 0BD2A0 7F088770 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0BD2A4 7F088774 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0BD2A8 7F088778 0FC165A5 */  jal   matrix_4x4_7F059694
/* 0BD2AC 7F08877C E7B20024 */   swc1  $f18, 0x24($sp)
/* 0BD2B0 7F088780 27A40078 */  addiu $a0, $sp, 0x78
/* 0BD2B4 7F088784 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 0BD2B8 7F088788 8FA500BC */   lw    $a1, 0xbc($sp)
/* 0BD2BC 7F08878C 3C0F0102 */  lui   $t7, (0x01020040 >> 16) # lui $t7, 0x102
/* 0BD2C0 7F088790 35EF0040 */  ori   $t7, (0x01020040 & 0xFFFF) # ori $t7, $t7, 0x40
/* 0BD2C4 7F088794 02008825 */  move  $s1, $s0
/* 0BD2C8 7F088798 AE2F0000 */  sw    $t7, ($s1)
/* 0BD2CC 7F08879C 8FA400BC */  lw    $a0, 0xbc($sp)
/* 0BD2D0 7F0887A0 0C003A2C */  jal   osVirtualToPhysical
/* 0BD2D4 7F0887A4 26100008 */   addiu $s0, $s0, 8
/* 0BD2D8 7F0887A8 02001825 */  move  $v1, $s0
/* 0BD2DC 7F0887AC AE220004 */  sw    $v0, 4($s1)
/* 0BD2E0 7F0887B0 26100008 */  addiu $s0, $s0, 8
/* 0BD2E4 7F0887B4 3C18E700 */  lui   $t8, 0xe700
/* 0BD2E8 7F0887B8 02002025 */  move  $a0, $s0
/* 0BD2EC 7F0887BC AC780000 */  sw    $t8, ($v1)
/* 0BD2F0 7F0887C0 AC600004 */  sw    $zero, 4($v1)
/* 0BD2F4 7F0887C4 26100008 */  addiu $s0, $s0, 8
/* 0BD2F8 7F0887C8 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0BD2FC 7F0887CC 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0BD300 7F0887D0 02002825 */  move  $a1, $s0
/* 0BD304 7F0887D4 AC990000 */  sw    $t9, ($a0)
/* 0BD308 7F0887D8 AC800004 */  sw    $zero, 4($a0)
/* 0BD30C 7F0887DC 26100008 */  addiu $s0, $s0, 8
/* 0BD310 7F0887E0 3C08B900 */  lui   $t0, (0xB900031D >> 16) # lui $t0, 0xb900
/* 0BD314 7F0887E4 3C090050 */  lui   $t1, (0x005041C8 >> 16) # lui $t1, 0x50
/* 0BD318 7F0887E8 352941C8 */  ori   $t1, (0x005041C8 & 0xFFFF) # ori $t1, $t1, 0x41c8
/* 0BD31C 7F0887EC 3508031D */  ori   $t0, (0xB900031D & 0xFFFF) # ori $t0, $t0, 0x31d
/* 0BD320 7F0887F0 02003025 */  move  $a2, $s0
/* 0BD324 7F0887F4 ACA80000 */  sw    $t0, ($a1)
/* 0BD328 7F0887F8 ACA90004 */  sw    $t1, 4($a1)
/* 0BD32C 7F0887FC 3C0AB900 */  lui   $t2, (0xB9000002 >> 16) # lui $t2, 0xb900
/* 0BD330 7F088800 354A0002 */  ori   $t2, (0xB9000002 & 0xFFFF) # ori $t2, $t2, 2
/* 0BD334 7F088804 26100008 */  addiu $s0, $s0, 8
/* 0BD338 7F088808 ACCA0000 */  sw    $t2, ($a2)
/* 0BD33C 7F08880C ACC00004 */  sw    $zero, %lo(0x43FA0004)($a2)
/* 0BD340 7F088810 02003825 */  move  $a3, $s0
/* 0BD344 7F088814 26100008 */  addiu $s0, $s0, 8
/* 0BD348 7F088818 3C0BFCFF */  lui   $t3, (0xFCFFFFFF >> 16) # lui $t3, 0xfcff
/* 0BD34C 7F08881C 3C0CFFFE */  lui   $t4, (0xFFFE793C >> 16) # lui $t4, 0xfffe
/* 0BD350 7F088820 358C793C */  ori   $t4, (0xFFFE793C & 0xFFFF) # ori $t4, $t4, 0x793c
/* 0BD354 7F088824 356BFFFF */  ori   $t3, (0xFCFFFFFF & 0xFFFF) # ori $t3, $t3, 0xffff
/* 0BD358 7F088828 02001025 */  move  $v0, $s0
/* 0BD35C 7F08882C ACEB0000 */  sw    $t3, ($a3)
/* 0BD360 7F088830 ACEC0004 */  sw    $t4, 4($a3)
/* 0BD364 7F088834 26100008 */  addiu $s0, $s0, 8
/* 0BD368 7F088838 3C0EE6E6 */  lui   $t6, (0xE6E6E600 >> 16) # lui $t6, 0xe6e6
/* 0BD36C 7F08883C 35CEE600 */  ori   $t6, (0xE6E6E600 & 0xFFFF) # ori $t6, $t6, 0xe600
/* 0BD370 7F088840 3C0DFA00 */  lui   $t5, 0xfa00
/* 0BD374 7F088844 02001825 */  move  $v1, $s0
/* 0BD378 7F088848 AC4D0000 */  sw    $t5, ($v0)
/* 0BD37C 7F08884C AC4E0004 */  sw    $t6, 4($v0)
/* 0BD380 7F088850 26100008 */  addiu $s0, $s0, 8
/* 0BD384 7F088854 24183000 */  li    $t8, 12288
/* 0BD388 7F088858 3C0FB600 */  lui   $t7, 0xb600
/* 0BD38C 7F08885C 3C060600 */  lui   $a2, 0x600
/* 0BD390 7F088860 AC6F0000 */  sw    $t7, ($v1)
/* 0BD394 7F088864 AC780004 */  sw    $t8, 4($v1)
/* 0BD398 7F088868 02002025 */  move  $a0, $s0
/* 0BD39C 7F08886C AC860000 */  sw    $a2, ($a0)
/* 0BD3A0 7F088870 8E590000 */  lw    $t9, ($s2)
/* 0BD3A4 7F088874 3C018000 */  lui   $at, (0x800019F8 >> 16)
/* 0BD3A8 7F088878 342119F8 */  ori   $at, (0x800019F8 & 0xFFFF) # ori $at, $at, 0x19f8
/* 0BD3AC 7F08887C 26100008 */  addiu $s0, $s0, 8
/* 0BD3B0 7F088880 03214021 */  addu  $t0, $t9, $at
/* 0BD3B4 7F088884 AC880004 */  sw    $t0, 4($a0)
/* 0BD3B8 7F088888 02002825 */  move  $a1, $s0
/* 0BD3BC 7F08888C ACA60000 */  sw    $a2, ($a1)
/* 0BD3C0 7F088890 8E490000 */  lw    $t1, ($s2)
/* 0BD3C4 7F088894 3C018000 */  lui   $at, (0x80002128 >> 16)
/* 0BD3C8 7F088898 34212128 */  ori   $at, (0x80002128 & 0xFFFF) # ori $at, $at, 0x2128
/* 0BD3CC 7F08889C 26100008 */  addiu $s0, $s0, 8
/* 0BD3D0 7F0888A0 3C0B0103 */  lui   $t3, (0x01030040 >> 16) # lui $t3, 0x103
/* 0BD3D4 7F0888A4 01215021 */  addu  $t2, $t1, $at
/* 0BD3D8 7F0888A8 ACAA0004 */  sw    $t2, 4($a1)
/* 0BD3DC 7F0888AC 356B0040 */  ori   $t3, (0x01030040 & 0xFFFF) # ori $t3, $t3, 0x40
/* 0BD3E0 7F0888B0 02008825 */  move  $s1, $s0
/* 0BD3E4 7F0888B4 AE2B0000 */  sw    $t3, ($s1)
/* 0BD3E8 7F0888B8 0FC1E0DD */  jal   currentPlayerGetProjectionMatrix
/* 0BD3EC 7F0888BC 26100008 */   addiu $s0, $s0, 8
/* 0BD3F0 7F0888C0 0C003A2C */  jal   osVirtualToPhysical
/* 0BD3F4 7F0888C4 00402025 */   move  $a0, $v0
/* 0BD3F8 7F0888C8 AE220004 */  sw    $v0, 4($s1)
/* 0BD3FC 7F0888CC 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0BD400 7F0888D0 02001025 */  move  $v0, $s0
/* 0BD404 7F0888D4 8FB00030 */  lw    $s0, 0x30($sp)
/* 0BD408 7F0888D8 8FB20038 */  lw    $s2, 0x38($sp)
/* 0BD40C 7F0888DC 8FB10034 */  lw    $s1, 0x34($sp)
/* 0BD410 7F0888E0 03E00008 */  jr    $ra
/* 0BD414 7F0888E4 27BD00C0 */   addiu $sp, $sp, 0xc0
)
#endif

#if !defined(LEFTOVERDEBUG)

GLOBAL_ASM(
.text
glabel sub_GAME_7F088618
/* 0BB170 7F088780 27BDFF40 */  addiu $sp, $sp, -0xc0
/* 0BB174 7F088784 AFB20038 */  sw    $s2, 0x38($sp)
/* 0BB178 7F088788 3C128007 */  lui   $s2, %hi(g_CurrentPlayer) # $s2, 0x8007
/* 0BB17C 7F08878C 26528BC0 */  addiu $s2, %lo(g_CurrentPlayer) # addiu $s2, $s2, -0x7440
/* 0BB180 7F088790 AFB10034 */  sw    $s1, 0x34($sp)
/* 0BB184 7F088794 8E510000 */  lw    $s1, ($s2)
/* 0BB188 7F088798 AFB00030 */  sw    $s0, 0x30($sp)
/* 0BB18C 7F08879C 00808025 */  move  $s0, $a0
/* 0BB190 7F0887A0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0BB194 7F0887A4 2405002E */  li    $a1, 46
/* 0BB198 7F0887A8 24060001 */  li    $a2, 1
/* 0BB19C 7F0887AC 8E2700F0 */  lw    $a3, 0xf0($s1)
/* 0BB1A0 7F0887B0 0FC2891C */  jal   sub_GAME_7F0A2F30
/* 0BB1A4 7F0887B4 262412B0 */   addiu $a0, $s1, 0x12b0
/* 0BB1A8 7F0887B8 8E510000 */  lw    $s1, ($s2)
/* 0BB1AC 7F0887BC 3C018000 */  lui   $at, (0x800012B0 >> 16) # lui $at, 0x8000
/* 0BB1B0 7F0887C0 342112B0 */  ori   $at, (0x800012B0 & 0xFFFF) # ori $at, $at, 0x12b0
/* 0BB1B4 7F0887C4 2406002E */  li    $a2, 46
/* 0BB1B8 7F0887C8 02212821 */  addu  $a1, $s1, $at
/* 0BB1BC 7F0887CC 0FC28A1C */  jal   sub_GAME_7F0A3330
/* 0BB1C0 7F0887D0 262419F0 */   addiu $a0, $s1, 0x19f0
/* 0BB1C4 7F0887D4 8E510000 */  lw    $s1, ($s2)
/* 0BB1C8 7F0887D8 2405002E */  li    $a1, 46
/* 0BB1CC 7F0887DC 2406FFFF */  li    $a2, -1
/* 0BB1D0 7F0887E0 26241590 */  addiu $a0, $s1, 0x1590
/* 0BB1D4 7F0887E4 0FC2891C */  jal   sub_GAME_7F0A2F30
/* 0BB1D8 7F0887E8 8E2700EC */   lw    $a3, 0xec($s1)
/* 0BB1DC 7F0887EC 8E510000 */  lw    $s1, ($s2)
/* 0BB1E0 7F0887F0 3C018000 */  lui   $at, (0x80001590 >> 16) # lui $at, 0x8000
/* 0BB1E4 7F0887F4 34211590 */  ori   $at, (0x80001590 & 0xFFFF) # ori $at, $at, 0x1590
/* 0BB1E8 7F0887F8 2406002E */  li    $a2, 46
/* 0BB1EC 7F0887FC 02212821 */  addu  $a1, $s1, $at
/* 0BB1F0 7F088800 0FC28A1C */  jal   sub_GAME_7F0A3330
/* 0BB1F4 7F088804 26242120 */   addiu $a0, $s1, 0x2120
/* 0BB1F8 7F088808 0FC2F2A4 */  jal   dynAllocateMatrix
/* 0BB1FC 7F08880C 00000000 */   nop   
/* 0BB200 7F088810 0FC2F2A4 */  jal   dynAllocateMatrix
/* 0BB204 7F088814 AFA200BC */   sw    $v0, 0xbc($sp)
/* 0BB208 7F088818 3C018003 */  lui   $at, %hi(D_800364CC) # $at, 0x8003
/* 0BB20C 7F08881C C4201A1C */  lwc1  $f0, %lo(D_800364CC)($at)
/* 0BB210 7F088820 3C01C448 */  li    $at, 0xC4480000 # -800.000000
/* 0BB214 7F088824 44812000 */  mtc1  $at, $f4
/* 0BB218 7F088828 3C014448 */  li    $at, 0x44480000 # 800.000000
/* 0BB21C 7F08882C 44814000 */  mtc1  $at, $f8
/* 0BB220 7F088830 46002182 */  mul.s $f6, $f4, $f0
/* 0BB224 7F088834 3C01C416 */  li    $at, 0xC4160000 # -600.000000
/* 0BB228 7F088838 44818000 */  mtc1  $at, $f16
/* 0BB22C 7F08883C 46004282 */  mul.s $f10, $f8, $f0
/* 0BB230 7F088840 3C014416 */  li    $at, 0x44160000 # 600.000000
/* 0BB234 7F088844 44812000 */  mtc1  $at, $f4
/* 0BB238 7F088848 46008482 */  mul.s $f18, $f16, $f0
/* 0BB23C 7F08884C 3C01C2C8 */  li    $at, 0xC2C80000 # -100.000000
/* 0BB240 7F088850 44053000 */  mfc1  $a1, $f6
/* 0BB244 7F088854 46002182 */  mul.s $f6, $f4, $f0
/* 0BB248 7F088858 44814000 */  mtc1  $at, $f8
/* 0BB24C 7F08885C 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0BB250 7F088860 44065000 */  mfc1  $a2, $f10
/* 0BB254 7F088864 44815000 */  mtc1  $at, $f10
/* 0BB258 7F088868 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BB25C 7F08886C 44818000 */  mtc1  $at, $f16
/* 0BB260 7F088870 44079000 */  mfc1  $a3, $f18
/* 0BB264 7F088874 AFA200B8 */  sw    $v0, 0xb8($sp)
/* 0BB268 7F088878 E7A60010 */  swc1  $f6, 0x10($sp)
/* 0BB26C 7F08887C 00402025 */  move  $a0, $v0
/* 0BB270 7F088880 E7A80014 */  swc1  $f8, 0x14($sp)
/* 0BB274 7F088884 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 0BB278 7F088888 0C005899 */  jal   guOrtho
/* 0BB27C 7F08888C E7B0001C */   swc1  $f16, 0x1c($sp)
/* 0BB280 7F088890 3C0E0103 */  lui   $t6, (0x01030040 >> 16) # lui $t6, 0x103
/* 0BB284 7F088894 35CE0040 */  ori   $t6, (0x01030040 & 0xFFFF) # ori $t6, $t6, 0x40
/* 0BB288 7F088898 02008825 */  move  $s1, $s0
/* 0BB28C 7F08889C AE2E0000 */  sw    $t6, ($s1)
/* 0BB290 7F0888A0 8FA400B8 */  lw    $a0, 0xb8($sp)
/* 0BB294 7F0888A4 0C003838 */  jal   osVirtualToPhysical
/* 0BB298 7F0888A8 26100008 */   addiu $s0, $s0, 8
/* 0BB29C 7F0888AC 44800000 */  mtc1  $zero, $f0
/* 0BB2A0 7F0888B0 AE220004 */  sw    $v0, 4($s1)
/* 0BB2A4 7F0888B4 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0BB2A8 7F0888B8 44819000 */  mtc1  $at, $f18
/* 0BB2AC 7F0888BC 44050000 */  mfc1  $a1, $f0
/* 0BB2B0 7F0888C0 44070000 */  mfc1  $a3, $f0
/* 0BB2B4 7F0888C4 27A40078 */  addiu $a0, $sp, 0x78
/* 0BB2B8 7F0888C8 3C0643FA */  lui   $a2, %hi(0x43FA0004) # $a2, 0x43fa
/* 0BB2BC 7F0888CC E7A00020 */  swc1  $f0, 0x20($sp)
/* 0BB2C0 7F0888D0 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 0BB2C4 7F0888D4 E7A00018 */  swc1  $f0, 0x18($sp)
/* 0BB2C8 7F0888D8 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0BB2CC 7F0888DC E7A00010 */  swc1  $f0, 0x10($sp)
/* 0BB2D0 7F0888E0 0FC166CF */  jal   matrix_4x4_7F059694
/* 0BB2D4 7F0888E4 E7B20024 */   swc1  $f18, 0x24($sp)
/* 0BB2D8 7F0888E8 27A40078 */  addiu $a0, $sp, 0x78
/* 0BB2DC 7F0888EC 0FC16451 */  jal   matrix_4x4_f32_to_s32
/* 0BB2E0 7F0888F0 8FA500BC */   lw    $a1, 0xbc($sp)
/* 0BB2E4 7F0888F4 3C0F0102 */  lui   $t7, (0x01020040 >> 16) # lui $t7, 0x102
/* 0BB2E8 7F0888F8 35EF0040 */  ori   $t7, (0x01020040 & 0xFFFF) # ori $t7, $t7, 0x40
/* 0BB2EC 7F0888FC 02008825 */  move  $s1, $s0
/* 0BB2F0 7F088900 AE2F0000 */  sw    $t7, ($s1)
/* 0BB2F4 7F088904 8FA400BC */  lw    $a0, 0xbc($sp)
/* 0BB2F8 7F088908 0C003838 */  jal   osVirtualToPhysical
/* 0BB2FC 7F08890C 26100008 */   addiu $s0, $s0, 8
/* 0BB300 7F088910 02001825 */  move  $v1, $s0
/* 0BB304 7F088914 AE220004 */  sw    $v0, 4($s1)
/* 0BB308 7F088918 26100008 */  addiu $s0, $s0, 8
/* 0BB30C 7F08891C 3C18E700 */  lui   $t8, 0xe700
/* 0BB310 7F088920 02002025 */  move  $a0, $s0
/* 0BB314 7F088924 AC780000 */  sw    $t8, ($v1)
/* 0BB318 7F088928 AC600004 */  sw    $zero, 4($v1)
/* 0BB31C 7F08892C 26100008 */  addiu $s0, $s0, 8
/* 0BB320 7F088930 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0BB324 7F088934 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0BB328 7F088938 02002825 */  move  $a1, $s0
/* 0BB32C 7F08893C AC990000 */  sw    $t9, ($a0)
/* 0BB330 7F088940 AC800004 */  sw    $zero, 4($a0)
/* 0BB334 7F088944 26100008 */  addiu $s0, $s0, 8
/* 0BB338 7F088948 3C08B900 */  lui   $t0, (0xB900031D >> 16) # lui $t0, 0xb900
/* 0BB33C 7F08894C 3C090050 */  lui   $t1, (0x005041C8 >> 16) # lui $t1, 0x50
/* 0BB340 7F088950 352941C8 */  ori   $t1, (0x005041C8 & 0xFFFF) # ori $t1, $t1, 0x41c8
/* 0BB344 7F088954 3508031D */  ori   $t0, (0xB900031D & 0xFFFF) # ori $t0, $t0, 0x31d
/* 0BB348 7F088958 02003025 */  move  $a2, $s0
/* 0BB34C 7F08895C ACA80000 */  sw    $t0, ($a1)
/* 0BB350 7F088960 ACA90004 */  sw    $t1, 4($a1)
/* 0BB354 7F088964 3C0AB900 */  lui   $t2, (0xB9000002 >> 16) # lui $t2, 0xb900
/* 0BB358 7F088968 354A0002 */  ori   $t2, (0xB9000002 & 0xFFFF) # ori $t2, $t2, 2
/* 0BB35C 7F08896C 26100008 */  addiu $s0, $s0, 8
/* 0BB360 7F088970 ACCA0000 */  sw    $t2, ($a2)
/* 0BB364 7F088974 ACC00004 */  sw    $zero, %lo(0x43FA0004)($a2)
/* 0BB368 7F088978 02003825 */  move  $a3, $s0
/* 0BB36C 7F08897C 26100008 */  addiu $s0, $s0, 8
/* 0BB370 7F088980 3C0BFCFF */  lui   $t3, (0xFCFFFFFF >> 16) # lui $t3, 0xfcff
/* 0BB374 7F088984 3C0CFFFE */  lui   $t4, (0xFFFE793C >> 16) # lui $t4, 0xfffe
/* 0BB378 7F088988 358C793C */  ori   $t4, (0xFFFE793C & 0xFFFF) # ori $t4, $t4, 0x793c
/* 0BB37C 7F08898C 356BFFFF */  ori   $t3, (0xFCFFFFFF & 0xFFFF) # ori $t3, $t3, 0xffff
/* 0BB380 7F088990 02001025 */  move  $v0, $s0
/* 0BB384 7F088994 ACEB0000 */  sw    $t3, ($a3)
/* 0BB388 7F088998 ACEC0004 */  sw    $t4, 4($a3)
/* 0BB38C 7F08899C 26100008 */  addiu $s0, $s0, 8
/* 0BB390 7F0889A0 3C0EE6E6 */  lui   $t6, (0xE6E6E600 >> 16) # lui $t6, 0xe6e6
/* 0BB394 7F0889A4 35CEE600 */  ori   $t6, (0xE6E6E600 & 0xFFFF) # ori $t6, $t6, 0xe600
/* 0BB398 7F0889A8 3C0DFA00 */  lui   $t5, 0xfa00
/* 0BB39C 7F0889AC 02001825 */  move  $v1, $s0
/* 0BB3A0 7F0889B0 AC4D0000 */  sw    $t5, ($v0)
/* 0BB3A4 7F0889B4 AC4E0004 */  sw    $t6, 4($v0)
/* 0BB3A8 7F0889B8 26100008 */  addiu $s0, $s0, 8
/* 0BB3AC 7F0889BC 24183000 */  li    $t8, 12288
/* 0BB3B0 7F0889C0 3C0FB600 */  lui   $t7, 0xb600
/* 0BB3B4 7F0889C4 3C060600 */  lui   $a2, 0x600
/* 0BB3B8 7F0889C8 AC6F0000 */  sw    $t7, ($v1)
/* 0BB3BC 7F0889CC AC780004 */  sw    $t8, 4($v1)
/* 0BB3C0 7F0889D0 02002025 */  move  $a0, $s0
/* 0BB3C4 7F0889D4 AC860000 */  sw    $a2, ($a0)
/* 0BB3C8 7F0889D8 8E590000 */  lw    $t9, ($s2)
/* 0BB3CC 7F0889DC 3C018000 */  lui   $at, (0x800019F0 >> 16) # lui $at, 0x8000
/* 0BB3D0 7F0889E0 342119F0 */  ori   $at, (0x800019F0 & 0xFFFF) # ori $at, $at, 0x19f0
/* 0BB3D4 7F0889E4 26100008 */  addiu $s0, $s0, 8
/* 0BB3D8 7F0889E8 03214021 */  addu  $t0, $t9, $at
/* 0BB3DC 7F0889EC AC880004 */  sw    $t0, 4($a0)
/* 0BB3E0 7F0889F0 02002825 */  move  $a1, $s0
/* 0BB3E4 7F0889F4 ACA60000 */  sw    $a2, ($a1)
/* 0BB3E8 7F0889F8 8E490000 */  lw    $t1, ($s2)
/* 0BB3EC 7F0889FC 3C018000 */  lui   $at, (0x80002120 >> 16) # lui $at, 0x8000
/* 0BB3F0 7F088A00 34212120 */  ori   $at, (0x80002120 & 0xFFFF) # ori $at, $at, 0x2120
/* 0BB3F4 7F088A04 26100008 */  addiu $s0, $s0, 8
/* 0BB3F8 7F088A08 3C0B0103 */  lui   $t3, (0x01030040 >> 16) # lui $t3, 0x103
/* 0BB3FC 7F088A0C 01215021 */  addu  $t2, $t1, $at
/* 0BB400 7F088A10 ACAA0004 */  sw    $t2, 4($a1)
/* 0BB404 7F088A14 356B0040 */  ori   $t3, (0x01030040 & 0xFFFF) # ori $t3, $t3, 0x40
/* 0BB408 7F088A18 02008825 */  move  $s1, $s0
/* 0BB40C 7F088A1C AE2B0000 */  sw    $t3, ($s1)
/* 0BB410 7F088A20 0FC1E0FD */  jal   currentPlayerGetProjectionMatrix
/* 0BB414 7F088A24 26100008 */   addiu $s0, $s0, 8
/* 0BB418 7F088A28 0C003838 */  jal   osVirtualToPhysical
/* 0BB41C 7F088A2C 00402025 */   move  $a0, $v0
/* 0BB420 7F088A30 AE220004 */  sw    $v0, 4($s1)
/* 0BB424 7F088A34 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0BB428 7F088A38 02001025 */  move  $v0, $s0
/* 0BB42C 7F088A3C 8FB00030 */  lw    $s0, 0x30($sp)
/* 0BB430 7F088A40 8FB20038 */  lw    $s2, 0x38($sp)
/* 0BB434 7F088A44 8FB10034 */  lw    $s1, 0x34($sp)
/* 0BB438 7F088A48 03E00008 */  jr    $ra
/* 0BB43C 7F088A4C 27BD00C0 */   addiu $sp, $sp, 0xc0
)
#endif
#endif





#ifdef NONMATCHING
void mp_respawn_handler(void) {

}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_80055284
.word 0x40c90fdb /*6.2831855*/
glabel D_80055288
.word 0x3e2e147c /*0.17000002*/
glabel D_8005528C
.word 0x3dccccd0 /*0.10000002*/

/*D:80055290*/
glabel jpt_mpspawntype
.word mp_spawntype_spawn
.word mp_spawntype_weapon
.word mp_spawntype_ammo
.word mp_spawntype_intro_swirly
.word mp_spawntype_intro_anim
.word mp_spawntype_handcuff
.word mp_spawntype_intro_camera

glabel D_800552AC
.word 0xb8d1b717 /*-0.000099999997*/
.text
glabel mp_respawn_handler
/* 0BD418 7F0888E8 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0BD41C 7F0888EC 3C0F8003 */  lui   $t7, %hi(D_8003688C)
/* 0BD420 7F0888F0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0BD424 7F0888F4 AFB10018 */  sw    $s1, 0x18($sp)
/* 0BD428 7F0888F8 AFB00014 */  sw    $s0, 0x14($sp)
/* 0BD42C 7F0888FC 25EF688C */  addiu $t7, %lo(D_8003688C) # addiu $t7, $t7, 0x688c
/* 0BD430 7F088900 8DE10000 */  lw    $at, ($t7)
/* 0BD434 7F088904 27AE004C */  addiu $t6, $sp, 0x4c
/* 0BD438 7F088908 8DE80004 */  lw    $t0, 4($t7)
/* 0BD43C 7F08890C ADC10000 */  sw    $at, ($t6)
/* 0BD440 7F088910 8DE10008 */  lw    $at, 8($t7)
/* 0BD444 7F088914 3C108007 */  lui   $s0, %hi(g_CurrentSetup+8)
/* 0BD448 7F088918 ADC80004 */  sw    $t0, 4($t6)
/* 0BD44C 7F08891C ADC10008 */  sw    $at, 8($t6)
/* 0BD450 7F088920 0FC1E4FB */  jal   init_player_BONDdata
/* 0BD454 7F088924 8E105D08 */   lw    $s0, %lo(g_CurrentSetup+8)($s0)
/* 0BD458 7F088928 0FC1E62E */  jal   bondviewPlayerSpawnRelated
/* 0BD45C 7F08892C 00000000 */   nop
/* 0BD460 7F088930 3C118008 */  lui   $s1, %hi(g_CurrentPlayer)
/* 0BD464 7F088934 2631A0B0 */  addiu $s1, %lo(g_CurrentPlayer) # addiu $s1, $s1, -0x5f50
/* 0BD468 7F088938 8E290000 */  lw    $t1, ($s1)
/* 0BD46C 7F08893C 240C0001 */  li    $t4, 1
/* 0BD470 7F088940 24020007 */  li    $v0, 7
/* 0BD474 7F088944 AD2000D8 */  sw    $zero, 0xd8($t1)
/* 0BD478 7F088948 8E2A0000 */  lw    $t2, ($s1)
/* 0BD47C 7F08894C 240F0002 */  li    $t7, 2
/* 0BD480 7F088950 2404FFFF */  li    $a0, -1
/* 0BD484 7F088954 AD400428 */  sw    $zero, 0x428($t2)
/* 0BD488 7F088958 8E2B0000 */  lw    $t3, ($s1)
/* 0BD48C 7F08895C AD600424 */  sw    $zero, 0x424($t3)
/* 0BD490 7F088960 8E2D0000 */  lw    $t5, ($s1)
/* 0BD494 7F088964 ADAC0420 */  sw    $t4, 0x420($t5)
/* 0BD498 7F088968 8E390000 */  lw    $t9, ($s1)
/* 0BD49C 7F08896C AF2229B8 */  sw    $v0, 0x29b8($t9)
/* 0BD4A0 7F088970 8E380000 */  lw    $t8, ($s1)
/* 0BD4A4 7F088974 AF0229D4 */  sw    $v0, 0x29d4($t8)
/* 0BD4A8 7F088978 8E2E0000 */  lw    $t6, ($s1)
/* 0BD4AC 7F08897C ADC01064 */  sw    $zero, 0x1064($t6)
/* 0BD4B0 7F088980 8E280000 */  lw    $t0, ($s1)
/* 0BD4B4 7F088984 0FC228E0 */  jal   hudmsgsSetOn
/* 0BD4B8 7F088988 AD0F1128 */   sw    $t7, 0x1128($t0)
/* 0BD4BC 7F08898C 0FC22A4A */  jal   bondviewClearUpperTextDisplayFlag
/* 0BD4C0 7F088990 2404FFFF */   li    $a0, -1
/* 0BD4C4 7F088994 0FC26919 */  jal   getPlayerCount
/* 0BD4C8 7F088998 00000000 */   nop
/* 0BD4CC 7F08899C 28410002 */  slti  $at, $v0, 2
/* 0BD4D0 7F0889A0 14200008 */  bnez  $at, .L7F0889C4
/* 0BD4D4 7F0889A4 3C098008 */   lui   $t1, %hi(startpadcount)
/* 0BD4D8 7F0889A8 8D299C68 */  lw    $t1, %lo(startpadcount)($t1)
/* 0BD4DC 7F0889AC 59200006 */  blezl $t1, .L7F0889C8
/* 0BD4E0 7F0889B0 00001825 */   move  $v1, $zero
/* 0BD4E4 7F0889B4 0FC1E43C */  jal   bondviewGetRandomSpawnPadIndex
/* 0BD4E8 7F0889B8 00000000 */   nop
/* 0BD4EC 7F0889BC 10000002 */  b     .L7F0889C8
/* 0BD4F0 7F0889C0 00401825 */   move  $v1, $v0
.L7F0889C4:
/* 0BD4F4 7F0889C4 00001825 */  move  $v1, $zero
.L7F0889C8:
/* 0BD4F8 7F0889C8 00035080 */  sll   $t2, $v1, 2
/* 0BD4FC 7F0889CC 3C028008 */  lui   $v0, %hi(g_Startpad)
/* 0BD500 7F0889D0 004A1021 */  addu  $v0, $v0, $t2
/* 0BD504 7F0889D4 8C429C28 */  lw    $v0, %lo(g_Startpad)($v0)
/* 0BD508 7F0889D8 C4440000 */  lwc1  $f4, ($v0)
/* 0BD50C 7F0889DC E7A4004C */  swc1  $f4, 0x4c($sp)
/* 0BD510 7F0889E0 C4460008 */  lwc1  $f6, 8($v0)
/* 0BD514 7F0889E4 8FA5004C */  lw    $a1, 0x4c($sp)
/* 0BD518 7F0889E8 E7A60054 */  swc1  $f6, 0x54($sp)
/* 0BD51C 7F0889EC 8C440028 */  lw    $a0, 0x28($v0)
/* 0BD520 7F0889F0 8FA60054 */  lw    $a2, 0x54($sp)
/* 0BD524 7F0889F4 0FC20358 */  jal   bondviewYPositionRelated
/* 0BD528 7F0889F8 AFA40044 */   sw    $a0, 0x44($sp)
/* 0BD52C 7F0889FC 8E220000 */  lw    $v0, ($s1)
/* 0BD530 7F088A00 C44829BC */  lwc1  $f8, 0x29bc($v0)
/* 0BD534 7F088A04 46004280 */  add.s $f10, $f8, $f0
/* 0BD538 7F088A08 E7AA0050 */  swc1  $f10, 0x50($sp)
/* 0BD53C 7F088A0C E4400070 */  swc1  $f0, 0x70($v0)
/* 0BD540 7F088A10 0C002914 */  jal   randomGetNext
/* 0BD544 7F088A14 E7A0003C */   swc1  $f0, 0x3c($sp)
/* 0BD548 7F088A18 44828000 */  mtc1  $v0, $f16
/* 0BD54C 7F088A1C 3C018005 */  lui   $at, %hi(D_80055284)
/* 0BD550 7F088A20 C42C5284 */  lwc1  $f12, %lo(D_80055284)($at)
/* 0BD554 7F088A24 C7A2003C */  lwc1  $f2, 0x3c($sp)
/* 0BD558 7F088A28 04410005 */  bgez  $v0, .L7F088A40
/* 0BD55C 7F088A2C 468084A0 */   cvt.s.w $f18, $f16
/* 0BD560 7F088A30 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0BD564 7F088A34 44812000 */  mtc1  $at, $f4
/* 0BD568 7F088A38 00000000 */  nop
/* 0BD56C 7F088A3C 46049480 */  add.s $f18, $f18, $f4
.L7F088A40:
/* 0BD570 7F088A40 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0BD574 7F088A44 44813000 */  mtc1  $at, $f6
/* 0BD578 7F088A48 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0BD57C 7F088A4C 44815000 */  mtc1  $at, $f10
/* 0BD580 7F088A50 46069202 */  mul.s $f8, $f18, $f6
/* 0BD584 7F088A54 8E2B0000 */  lw    $t3, ($s1)
/* 0BD588 7F088A58 3C018005 */  lui   $at, %hi(D_80055288)
/* 0BD58C 7F088A5C 27A5004C */  addiu $a1, $sp, 0x4c
/* 0BD590 7F088A60 460C4002 */  mul.s $f0, $f8, $f12
/* 0BD594 7F088A64 00000000 */  nop
/* 0BD598 7F088A68 460A0402 */  mul.s $f16, $f0, $f10
/* 0BD59C 7F088A6C E7A00048 */  swc1  $f0, 0x48($sp)
/* 0BD5A0 7F088A70 460C8103 */  div.s $f4, $f16, $f12
/* 0BD5A4 7F088A74 E5640148 */  swc1  $f4, 0x148($t3)
/* 0BD5A8 7F088A78 8E2C0000 */  lw    $t4, ($s1)
/* 0BD5AC 7F088A7C E5820074 */  swc1  $f2, 0x74($t4)
/* 0BD5B0 7F088A80 C4325288 */  lwc1  $f18, %lo(D_80055288)($at)
/* 0BD5B4 7F088A84 8E2D0000 */  lw    $t5, ($s1)
/* 0BD5B8 7F088A88 46121183 */  div.s $f6, $f2, $f18
/* 0BD5BC 7F088A8C E5A6006C */  swc1  $f6, 0x6c($t5)
/* 0BD5C0 7F088A90 8E240000 */  lw    $a0, ($s1)
/* 0BD5C4 7F088A94 8FA60044 */  lw    $a2, 0x44($sp)
/* 0BD5C8 7F088A98 0FC1F1CC */  jal   change_player_pos_to_target
/* 0BD5CC 7F088A9C 24840488 */   addiu $a0, $a0, 0x488
/* 0BD5D0 7F088AA0 0FC15FAB */  jal   sinf
/* 0BD5D4 7F088AA4 C7AC0048 */   lwc1  $f12, 0x48($sp)
/* 0BD5D8 7F088AA8 8E390000 */  lw    $t9, ($s1)
/* 0BD5DC 7F088AAC 46000207 */  neg.s $f8, $f0
/* 0BD5E0 7F088AB0 44805000 */  mtc1  $zero, $f10
/* 0BD5E4 7F088AB4 E7280498 */  swc1  $f8, 0x498($t9)
/* 0BD5E8 7F088AB8 8E380000 */  lw    $t8, ($s1)
/* 0BD5EC 7F088ABC E70A049C */  swc1  $f10, 0x49c($t8)
/* 0BD5F0 7F088AC0 0FC15FA8 */  jal   cosf
/* 0BD5F4 7F088AC4 C7AC0048 */   lwc1  $f12, 0x48($sp)
/* 0BD5F8 7F088AC8 8E2E0000 */  lw    $t6, ($s1)
/* 0BD5FC 7F088ACC 3C018005 */  lui   $at, %hi(D_8005528C)
/* 0BD600 7F088AD0 C42C528C */  lwc1  $f12, %lo(D_8005528C)($at)
/* 0BD604 7F088AD4 E5C004A0 */  swc1  $f0, 0x4a0($t6)
/* 0BD608 7F088AD8 8E2F0000 */  lw    $t7, ($s1)
/* 0BD60C 7F088ADC C7A2004C */  lwc1  $f2, 0x4c($sp)
/* 0BD610 7F088AE0 E5E20408 */  swc1  $f2, 0x408($t7)
/* 0BD614 7F088AE4 8E280000 */  lw    $t0, ($s1)
/* 0BD618 7F088AE8 8D0900A8 */  lw    $t1, 0xa8($t0)
/* 0BD61C 7F088AEC E5220008 */  swc1  $f2, 8($t1)
/* 0BD620 7F088AF0 8E2A0000 */  lw    $t2, ($s1)
/* 0BD624 7F088AF4 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 0BD628 7F088AF8 E542040C */  swc1  $f2, 0x40c($t2)
/* 0BD62C 7F088AFC 8E2B0000 */  lw    $t3, ($s1)
/* 0BD630 7F088B00 8D6C00A8 */  lw    $t4, 0xa8($t3)
/* 0BD634 7F088B04 E582000C */  swc1  $f2, 0xc($t4)
/* 0BD638 7F088B08 8E2D0000 */  lw    $t5, ($s1)
/* 0BD63C 7F088B0C C7A20054 */  lwc1  $f2, 0x54($sp)
/* 0BD640 7F088B10 E5A20410 */  swc1  $f2, 0x410($t5)
/* 0BD644 7F088B14 8E390000 */  lw    $t9, ($s1)
/* 0BD648 7F088B18 8F3800A8 */  lw    $t8, 0xa8($t9)
/* 0BD64C 7F088B1C E7020010 */  swc1  $f2, 0x10($t8)
/* 0BD650 7F088B20 8E2F0000 */  lw    $t7, ($s1)
/* 0BD654 7F088B24 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0BD658 7F088B28 8DE800A8 */  lw    $t0, 0xa8($t7)
/* 0BD65C 7F088B2C AD0E0014 */  sw    $t6, 0x14($t0)
/* 0BD660 7F088B30 8E220000 */  lw    $v0, ($s1)
/* 0BD664 7F088B34 C45004B4 */  lwc1  $f16, 0x4b4($v0)
/* 0BD668 7F088B38 460C8103 */  div.s $f4, $f16, $f12
/* 0BD66C 7F088B3C E44403B8 */  swc1  $f4, 0x3b8($v0)
/* 0BD670 7F088B40 8E220000 */  lw    $v0, ($s1)
/* 0BD674 7F088B44 C45204B8 */  lwc1  $f18, 0x4b8($v0)
/* 0BD678 7F088B48 460C9183 */  div.s $f6, $f18, $f12
/* 0BD67C 7F088B4C E44603BC */  swc1  $f6, 0x3bc($v0)
/* 0BD680 7F088B50 8E220000 */  lw    $v0, ($s1)
/* 0BD684 7F088B54 C44804BC */  lwc1  $f8, 0x4bc($v0)
/* 0BD688 7F088B58 460C4283 */  div.s $f10, $f8, $f12
/* 0BD68C 7F088B5C 0FC22FFC */  jal   bondinvReinitInv
/* 0BD690 7F088B60 E44A03C0 */   swc1  $f10, 0x3c0($v0)
/* 0BD694 7F088B64 8E290000 */  lw    $t1, ($s1)
/* 0BD698 7F088B68 24020008 */  li    $v0, 8
/* 0BD69C 7F088B6C 24030078 */  li    $v1, 120
/* 0BD6A0 7F088B70 AD201130 */  sw    $zero, 0x1130($t1)
/* 0BD6A4 7F088B74 8E2A0000 */  lw    $t2, ($s1)
/* 0BD6A8 7F088B78 AD401134 */  sw    $zero, 0x1134($t2)
.L7F088B7C:
/* 0BD6AC 7F088B7C 8E2B0000 */  lw    $t3, ($s1)
/* 0BD6B0 7F088B80 01626021 */  addu  $t4, $t3, $v0
/* 0BD6B4 7F088B84 AD801130 */  sw    $zero, 0x1130($t4)
/* 0BD6B8 7F088B88 8E2D0000 */  lw    $t5, ($s1)
/* 0BD6BC 7F088B8C 01A2C821 */  addu  $t9, $t5, $v0
/* 0BD6C0 7F088B90 AF201134 */  sw    $zero, 0x1134($t9)
/* 0BD6C4 7F088B94 8E380000 */  lw    $t8, ($s1)
/* 0BD6C8 7F088B98 03027821 */  addu  $t7, $t8, $v0
/* 0BD6CC 7F088B9C ADE01138 */  sw    $zero, 0x1138($t7)
/* 0BD6D0 7F088BA0 8E2E0000 */  lw    $t6, ($s1)
/* 0BD6D4 7F088BA4 01C24021 */  addu  $t0, $t6, $v0
/* 0BD6D8 7F088BA8 24420010 */  addiu $v0, $v0, 0x10
/* 0BD6DC 7F088BAC 1443FFF3 */  bne   $v0, $v1, .L7F088B7C
/* 0BD6E0 7F088BB0 AD00113C */   sw    $zero, 0x113c($t0)
/* 0BD6E4 7F088BB4 52000036 */  beql  $s0, $zero, .L7F088C90
/* 0BD6E8 7F088BB8 44800000 */   mtc1  $zero, $f0
/* 0BD6EC 7F088BBC 8E020000 */  lw    $v0, ($s0)
/* 0BD6F0 7F088BC0 24010009 */  li    $at, 9
/* 0BD6F4 7F088BC4 10410031 */  beq   $v0, $at, .L7F088C8C
/* 0BD6F8 7F088BC8 2C410007 */   sltiu $at, $v0, 7
.L7F088BCC:
/* 0BD6FC 7F088BCC 1020002A */  beqz  $at, .L7F088C78
/* 0BD700 7F088BD0 00024880 */   sll   $t1, $v0, 2
/* 0BD704 7F088BD4 3C018005 */  lui   $at, %hi(jpt_mpspawntype)
/* 0BD708 7F088BD8 00290821 */  addu  $at, $at, $t1
/* 0BD70C 7F088BDC 8C295290 */  lw    $t1, %lo(jpt_mpspawntype)($at)
/* 0BD710 7F088BE0 01200008 */  jr    $t1
/* 0BD714 7F088BE4 00000000 */   nop
mp_spawntype_spawn:
/* 0BD718 7F088BE8 10000024 */  b     .L7F088C7C
/* 0BD71C 7F088BEC 2610000C */   addiu $s0, $s0, 0xc
mp_spawntype_weapon:
/* 0BD720 7F088BF0 0FC30288 */  jal   check_ramrom_flags
/* 0BD724 7F088BF4 00000000 */   nop
/* 0BD728 7F088BF8 8E0A000C */  lw    $t2, 0xc($s0)
/* 0BD72C 7F088BFC 144A000A */  bne   $v0, $t2, .L7F088C28
/* 0BD730 7F088C00 00000000 */   nop
/* 0BD734 7F088C04 8E050008 */  lw    $a1, 8($s0)
/* 0BD738 7F088C08 04A00005 */  bltz  $a1, .L7F088C20
/* 0BD73C 7F088C0C 00000000 */   nop
/* 0BD740 7F088C10 0FC23143 */  jal   bondinvAddDoublesInvItem
/* 0BD744 7F088C14 8E040004 */   lw    $a0, 4($s0)
/* 0BD748 7F088C18 10000018 */  b     .L7F088C7C
/* 0BD74C 7F088C1C 26100010 */   addiu $s0, $s0, 0x10
.L7F088C20:
/* 0BD750 7F088C20 0FC23122 */  jal   bondinvAddInvItem
/* 0BD754 7F088C24 8E040004 */   lw    $a0, 4($s0)
.L7F088C28:
/* 0BD758 7F088C28 10000014 */  b     .L7F088C7C
/* 0BD75C 7F088C2C 26100010 */   addiu $s0, $s0, 0x10
mp_spawntype_ammo:
/* 0BD760 7F088C30 0FC30288 */  jal   check_ramrom_flags
/* 0BD764 7F088C34 00000000 */   nop
/* 0BD768 7F088C38 8E0B000C */  lw    $t3, 0xc($s0)
/* 0BD76C 7F088C3C 144B0004 */  bne   $v0, $t3, .L7F088C50
/* 0BD770 7F088C40 00000000 */   nop
/* 0BD774 7F088C44 8E040004 */  lw    $a0, 4($s0)
/* 0BD778 7F088C48 0FC1A44C */  jal   give_cur_player_ammo
/* 0BD77C 7F088C4C 8E050008 */   lw    $a1, 8($s0)
.L7F088C50:
/* 0BD780 7F088C50 1000000A */  b     .L7F088C7C
/* 0BD784 7F088C54 26100010 */   addiu $s0, $s0, 0x10
mp_spawntype_intro_swirly:
/* 0BD788 7F088C58 10000008 */  b     .L7F088C7C
/* 0BD78C 7F088C5C 26100020 */   addiu $s0, $s0, 0x20
mp_spawntype_intro_anim:
/* 0BD790 7F088C60 10000006 */  b     .L7F088C7C
/* 0BD794 7F088C64 26100008 */   addiu $s0, $s0, 8
mp_spawntype_handcuff:
/* 0BD798 7F088C68 10000004 */  b     .L7F088C7C
/* 0BD79C 7F088C6C 26100008 */   addiu $s0, $s0, 8
mp_spawntype_intro_camera:
/* 0BD7A0 7F088C70 10000002 */  b     .L7F088C7C
/* 0BD7A4 7F088C74 26100028 */   addiu $s0, $s0, 0x28
mp_spawntype_default:
.L7F088C78:
/* 0BD7A8 7F088C78 26100004 */  addiu $s0, $s0, 4
.L7F088C7C:
/* 0BD7AC 7F088C7C 8E020000 */  lw    $v0, ($s0)
/* 0BD7B0 7F088C80 24010009 */  li    $at, 9
/* 0BD7B4 7F088C84 5441FFD1 */  bnel  $v0, $at, .L7F088BCC
/* 0BD7B8 7F088C88 2C410007 */   sltiu $at, $v0, 7
.L7F088C8C:
/* 0BD7BC 7F088C8C 44800000 */  mtc1  $zero, $f0
.L7F088C90:
/* 0BD7C0 7F088C90 8E2C0000 */  lw    $t4, ($s1)
/* 0BD7C4 7F088C94 3C018005 */  lui   $at, %hi(D_800552AC)
/* 0BD7C8 7F088C98 E5800078 */  swc1  $f0, 0x78($t4)
/* 0BD7CC 7F088C9C 8E2D0000 */  lw    $t5, ($s1)
/* 0BD7D0 7F088CA0 C43052AC */  lwc1  $f16, %lo(D_800552AC)($at)
/* 0BD7D4 7F088CA4 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 0BD7D8 7F088CA8 44816000 */  mtc1  $at, $f12
/* 0BD7DC 7F088CAC E5B0007C */  swc1  $f16, 0x7c($t5)
/* 0BD7E0 7F088CB0 8E390000 */  lw    $t9, ($s1)
/* 0BD7E4 7F088CB4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BD7E8 7F088CB8 44817000 */  mtc1  $at, $f14
/* 0BD7EC 7F088CBC 0FC20284 */  jal   currentPlayerStartChrFade
/* 0BD7F0 7F088CC0 E7200080 */   swc1  $f0, 0x80($t9)
/* 0BD7F4 7F088CC4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0BD7F8 7F088CC8 8FB00014 */  lw    $s0, 0x14($sp)
/* 0BD7FC 7F088CCC 8FB10018 */  lw    $s1, 0x18($sp)
/* 0BD800 7F088CD0 03E00008 */  jr    $ra
/* 0BD804 7F088CD4 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_80055284
.word 0x40c90fdb /*6.2831855*/
glabel D_80055288
.word 0x3e4d35a8
glabel D_8005528C
.word 0x3df34d68

/*D:80055290*/
glabel jpt_mpspawntype
.word mp_spawntype_spawn
.word mp_spawntype_weapon
.word mp_spawntype_ammo
.word mp_spawntype_intro_swirly
.word mp_spawntype_intro_anim
.word mp_spawntype_handcuff
.word mp_spawntype_intro_camera

glabel D_800552AC
.word 0xb8d1b717 /*-0.000099999997*/
.text
glabel mp_respawn_handler
/* 0BB440 7F088A50 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0BB444 7F088A54 3C0F8003 */  lui   $t7, %hi(D_8003688C) # $t7, 0x8003
/* 0BB448 7F088A58 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0BB44C 7F088A5C AFB10018 */  sw    $s1, 0x18($sp)
/* 0BB450 7F088A60 AFB00014 */  sw    $s0, 0x14($sp)
/* 0BB454 7F088A64 25EF1DDC */  addiu $t7, %lo(D_8003688C) # addiu $t7, $t7, 0x1ddc
/* 0BB458 7F088A68 8DE10000 */  lw    $at, ($t7)
/* 0BB45C 7F088A6C 27AE004C */  addiu $t6, $sp, 0x4c
/* 0BB460 7F088A70 8DE80004 */  lw    $t0, 4($t7)
/* 0BB464 7F088A74 ADC10000 */  sw    $at, ($t6)
/* 0BB468 7F088A78 8DE10008 */  lw    $at, 8($t7)
/* 0BB46C 7F088A7C 3C108006 */  lui   $s0, %hi(g_CurrentSetup+8) # $s0, 0x8006
/* 0BB470 7F088A80 ADC80004 */  sw    $t0, 4($t6)
/* 0BB474 7F088A84 ADC10008 */  sw    $at, 8($t6)
/* 0BB478 7F088A88 0FC1E51B */  jal   init_player_BONDdata
/* 0BB47C 7F088A8C 8E104C48 */   lw    $s0, %lo(g_CurrentSetup+8)($s0)
/* 0BB480 7F088A90 0FC1E64E */  jal   bondviewPlayerSpawnRelated
/* 0BB484 7F088A94 00000000 */   nop   
/* 0BB488 7F088A98 3C118007 */  lui   $s1, %hi(g_CurrentPlayer) # $s1, 0x8007
/* 0BB48C 7F088A9C 26318BC0 */  addiu $s1, %lo(g_CurrentPlayer) # addiu $s1, $s1, -0x7440
/* 0BB490 7F088AA0 8E290000 */  lw    $t1, ($s1)
/* 0BB494 7F088AA4 240C0001 */  li    $t4, 1
/* 0BB498 7F088AA8 24020007 */  li    $v0, 7
/* 0BB49C 7F088AAC AD2000D8 */  sw    $zero, 0xd8($t1)
/* 0BB4A0 7F088AB0 8E2A0000 */  lw    $t2, ($s1)
/* 0BB4A4 7F088AB4 240F0002 */  li    $t7, 2
/* 0BB4A8 7F088AB8 2404FFFF */  li    $a0, -1
/* 0BB4AC 7F088ABC AD400428 */  sw    $zero, 0x428($t2)
/* 0BB4B0 7F088AC0 8E2B0000 */  lw    $t3, ($s1)
/* 0BB4B4 7F088AC4 AD600424 */  sw    $zero, 0x424($t3)
/* 0BB4B8 7F088AC8 8E2D0000 */  lw    $t5, ($s1)
/* 0BB4BC 7F088ACC ADAC0420 */  sw    $t4, 0x420($t5)
/* 0BB4C0 7F088AD0 8E390000 */  lw    $t9, ($s1)
/* 0BB4C4 7F088AD4 AF2229B0 */  sw    $v0, 0x29b0($t9)
/* 0BB4C8 7F088AD8 8E380000 */  lw    $t8, ($s1)
/* 0BB4CC 7F088ADC AF0229CC */  sw    $v0, 0x29cc($t8)
/* 0BB4D0 7F088AE0 8E2E0000 */  lw    $t6, ($s1)
/* 0BB4D4 7F088AE4 ADC0105C */  sw    $zero, 0x105c($t6)
/* 0BB4D8 7F088AE8 8E280000 */  lw    $t0, ($s1)
/* 0BB4DC 7F088AEC 0FC2294B */  jal   hudmsgsSetOn
/* 0BB4E0 7F088AF0 AD0F1120 */   sw    $t7, 0x1120($t0)
/* 0BB4E4 7F088AF4 0FC22ADC */  jal   bondviewClearUpperTextDisplayFlag
/* 0BB4E8 7F088AF8 2404FFFF */   li    $a0, -1
/* 0BB4EC 7F088AFC 0FC26669 */  jal   getPlayerCount
/* 0BB4F0 7F088B00 00000000 */   nop   
/* 0BB4F4 7F088B04 28410002 */  slti  $at, $v0, 2
/* 0BB4F8 7F088B08 14200008 */  bnez  $at, .L7F088B2C
/* 0BB4FC 7F088B0C 3C098007 */   lui   $t1, %hi(startpadcount) # $t1, 0x8007
/* 0BB500 7F088B10 8D298778 */  lw    $t1, %lo(startpadcount)($t1)
/* 0BB504 7F088B14 59200006 */  blezl $t1, .L7F088B30
/* 0BB508 7F088B18 00001825 */   move  $v1, $zero
/* 0BB50C 7F088B1C 0FC1E45C */  jal   bondviewGetRandomSpawnPadIndex
/* 0BB510 7F088B20 00000000 */   nop   
/* 0BB514 7F088B24 10000002 */  b     .L7F088B30
/* 0BB518 7F088B28 00401825 */   move  $v1, $v0
.L7F088B2C:
/* 0BB51C 7F088B2C 00001825 */  move  $v1, $zero
.L7F088B30:
/* 0BB520 7F088B30 00035080 */  sll   $t2, $v1, 2
/* 0BB524 7F088B34 3C028007 */  lui   $v0, %hi(g_Startpad)
/* 0BB528 7F088B38 004A1021 */  addu  $v0, $v0, $t2
/* 0BB52C 7F088B3C 8C428738 */  lw    $v0, %lo(g_Startpad)($v0)
/* 0BB530 7F088B40 C4440000 */  lwc1  $f4, ($v0)
/* 0BB534 7F088B44 E7A4004C */  swc1  $f4, 0x4c($sp)
/* 0BB538 7F088B48 C4460008 */  lwc1  $f6, 8($v0)
/* 0BB53C 7F088B4C 8FA5004C */  lw    $a1, 0x4c($sp)
/* 0BB540 7F088B50 E7A60054 */  swc1  $f6, 0x54($sp)
/* 0BB544 7F088B54 8C440028 */  lw    $a0, 0x28($v0)
/* 0BB548 7F088B58 8FA60054 */  lw    $a2, 0x54($sp)
/* 0BB54C 7F088B5C 0FC20381 */  jal   bondviewYPositionRelated
/* 0BB550 7F088B60 AFA40044 */   sw    $a0, 0x44($sp)
/* 0BB554 7F088B64 8E220000 */  lw    $v0, ($s1)
/* 0BB558 7F088B68 C44829B4 */  lwc1  $f8, 0x29b4($v0)
/* 0BB55C 7F088B6C 46004280 */  add.s $f10, $f8, $f0
/* 0BB560 7F088B70 E7AA0050 */  swc1  $f10, 0x50($sp)
/* 0BB564 7F088B74 E4400070 */  swc1  $f0, 0x70($v0)
/* 0BB568 7F088B78 0C00262C */  jal   randomGetNext
/* 0BB56C 7F088B7C E7A0003C */   swc1  $f0, 0x3c($sp)
/* 0BB570 7F088B80 44828000 */  mtc1  $v0, $f16
/* 0BB574 7F088B84 3C018005 */  lui   $at, %hi(D_80055284) # $at, 0x8005
/* 0BB578 7F088B88 C42CAE58 */  lwc1  $f12, %lo(D_80055284)($at)
/* 0BB57C 7F088B8C C7A2003C */  lwc1  $f2, 0x3c($sp)
/* 0BB580 7F088B90 04410005 */  bgez  $v0, .L7F088BA8
/* 0BB584 7F088B94 468084A0 */   cvt.s.w $f18, $f16
/* 0BB588 7F088B98 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0BB58C 7F088B9C 44812000 */  mtc1  $at, $f4
/* 0BB590 7F088BA0 00000000 */  nop   
/* 0BB594 7F088BA4 46049480 */  add.s $f18, $f18, $f4
.L7F088BA8:
/* 0BB598 7F088BA8 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0BB59C 7F088BAC 44813000 */  mtc1  $at, $f6
/* 0BB5A0 7F088BB0 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0BB5A4 7F088BB4 44815000 */  mtc1  $at, $f10
/* 0BB5A8 7F088BB8 46069202 */  mul.s $f8, $f18, $f6
/* 0BB5AC 7F088BBC 8E2B0000 */  lw    $t3, ($s1)
/* 0BB5B0 7F088BC0 3C018005 */  lui   $at, %hi(D_80055288) # $at, 0x8005
/* 0BB5B4 7F088BC4 27A5004C */  addiu $a1, $sp, 0x4c
/* 0BB5B8 7F088BC8 460C4002 */  mul.s $f0, $f8, $f12
/* 0BB5BC 7F088BCC 00000000 */  nop   
/* 0BB5C0 7F088BD0 460A0402 */  mul.s $f16, $f0, $f10
/* 0BB5C4 7F088BD4 E7A00048 */  swc1  $f0, 0x48($sp)
/* 0BB5C8 7F088BD8 460C8103 */  div.s $f4, $f16, $f12
/* 0BB5CC 7F088BDC E5640148 */  swc1  $f4, 0x148($t3)
/* 0BB5D0 7F088BE0 8E2C0000 */  lw    $t4, ($s1)
/* 0BB5D4 7F088BE4 E5820074 */  swc1  $f2, 0x74($t4)
/* 0BB5D8 7F088BE8 C432AE5C */  lwc1  $f18, %lo(D_80055288)($at)
/* 0BB5DC 7F088BEC 8E2D0000 */  lw    $t5, ($s1)
/* 0BB5E0 7F088BF0 46121183 */  div.s $f6, $f2, $f18
/* 0BB5E4 7F088BF4 E5A6006C */  swc1  $f6, 0x6c($t5)
/* 0BB5E8 7F088BF8 8E240000 */  lw    $a0, ($s1)
/* 0BB5EC 7F088BFC 8FA60044 */  lw    $a2, 0x44($sp)
/* 0BB5F0 7F088C00 0FC1F201 */  jal   change_player_pos_to_target
/* 0BB5F4 7F088C04 24840488 */   addiu $a0, $a0, 0x488
/* 0BB5F8 7F088C08 0FC1606B */  jal   sinf
/* 0BB5FC 7F088C0C C7AC0048 */   lwc1  $f12, 0x48($sp)
/* 0BB600 7F088C10 8E390000 */  lw    $t9, ($s1)
/* 0BB604 7F088C14 46000207 */  neg.s $f8, $f0
/* 0BB608 7F088C18 44805000 */  mtc1  $zero, $f10
/* 0BB60C 7F088C1C E7280498 */  swc1  $f8, 0x498($t9)
/* 0BB610 7F088C20 8E380000 */  lw    $t8, ($s1)
/* 0BB614 7F088C24 E70A049C */  swc1  $f10, 0x49c($t8)
/* 0BB618 7F088C28 0FC16068 */  jal   cosf
/* 0BB61C 7F088C2C C7AC0048 */   lwc1  $f12, 0x48($sp)
/* 0BB620 7F088C30 8E2E0000 */  lw    $t6, ($s1)
/* 0BB624 7F088C34 3C018005 */  lui   $at, %hi(D_8005528C) # $at, 0x8005
/* 0BB628 7F088C38 C42CAE60 */  lwc1  $f12, %lo(D_8005528C)($at)
/* 0BB62C 7F088C3C E5C004A0 */  swc1  $f0, 0x4a0($t6)
/* 0BB630 7F088C40 8E2F0000 */  lw    $t7, ($s1)
/* 0BB634 7F088C44 C7A2004C */  lwc1  $f2, 0x4c($sp)
/* 0BB638 7F088C48 E5E20408 */  swc1  $f2, 0x408($t7)
/* 0BB63C 7F088C4C 8E280000 */  lw    $t0, ($s1)
/* 0BB640 7F088C50 8D0900A8 */  lw    $t1, 0xa8($t0)
/* 0BB644 7F088C54 E5220008 */  swc1  $f2, 8($t1)
/* 0BB648 7F088C58 8E2A0000 */  lw    $t2, ($s1)
/* 0BB64C 7F088C5C C7A20050 */  lwc1  $f2, 0x50($sp)
/* 0BB650 7F088C60 E542040C */  swc1  $f2, 0x40c($t2)
/* 0BB654 7F088C64 8E2B0000 */  lw    $t3, ($s1)
/* 0BB658 7F088C68 8D6C00A8 */  lw    $t4, 0xa8($t3)
/* 0BB65C 7F088C6C E582000C */  swc1  $f2, 0xc($t4)
/* 0BB660 7F088C70 8E2D0000 */  lw    $t5, ($s1)
/* 0BB664 7F088C74 C7A20054 */  lwc1  $f2, 0x54($sp)
/* 0BB668 7F088C78 E5A20410 */  swc1  $f2, 0x410($t5)
/* 0BB66C 7F088C7C 8E390000 */  lw    $t9, ($s1)
/* 0BB670 7F088C80 8F3800A8 */  lw    $t8, 0xa8($t9)
/* 0BB674 7F088C84 E7020010 */  swc1  $f2, 0x10($t8)
/* 0BB678 7F088C88 8E2F0000 */  lw    $t7, ($s1)
/* 0BB67C 7F088C8C 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0BB680 7F088C90 8DE800A8 */  lw    $t0, 0xa8($t7)
/* 0BB684 7F088C94 AD0E0014 */  sw    $t6, 0x14($t0)
/* 0BB688 7F088C98 8E220000 */  lw    $v0, ($s1)
/* 0BB68C 7F088C9C C45004B4 */  lwc1  $f16, 0x4b4($v0)
/* 0BB690 7F088CA0 460C8103 */  div.s $f4, $f16, $f12
/* 0BB694 7F088CA4 E44403B8 */  swc1  $f4, 0x3b8($v0)
/* 0BB698 7F088CA8 8E220000 */  lw    $v0, ($s1)
/* 0BB69C 7F088CAC C45204B8 */  lwc1  $f18, 0x4b8($v0)
/* 0BB6A0 7F088CB0 460C9183 */  div.s $f6, $f18, $f12
/* 0BB6A4 7F088CB4 E44603BC */  swc1  $f6, 0x3bc($v0)
/* 0BB6A8 7F088CB8 8E220000 */  lw    $v0, ($s1)
/* 0BB6AC 7F088CBC C44804BC */  lwc1  $f8, 0x4bc($v0)
/* 0BB6B0 7F088CC0 460C4283 */  div.s $f10, $f8, $f12
/* 0BB6B4 7F088CC4 0FC230C0 */  jal   bondinvReinitInv
/* 0BB6B8 7F088CC8 E44A03C0 */   swc1  $f10, 0x3c0($v0)
/* 0BB6BC 7F088CCC 8E290000 */  lw    $t1, ($s1)
/* 0BB6C0 7F088CD0 24020008 */  li    $v0, 8
/* 0BB6C4 7F088CD4 24030078 */  li    $v1, 120
/* 0BB6C8 7F088CD8 AD201128 */  sw    $zero, 0x1128($t1)
/* 0BB6CC 7F088CDC 8E2A0000 */  lw    $t2, ($s1)
/* 0BB6D0 7F088CE0 AD40112C */  sw    $zero, 0x112c($t2)
.L7F088CE4:
/* 0BB6D4 7F088CE4 8E2B0000 */  lw    $t3, ($s1)
/* 0BB6D8 7F088CE8 01626021 */  addu  $t4, $t3, $v0
/* 0BB6DC 7F088CEC AD801128 */  sw    $zero, 0x1128($t4)
/* 0BB6E0 7F088CF0 8E2D0000 */  lw    $t5, ($s1)
/* 0BB6E4 7F088CF4 01A2C821 */  addu  $t9, $t5, $v0
/* 0BB6E8 7F088CF8 AF20112C */  sw    $zero, 0x112c($t9)
/* 0BB6EC 7F088CFC 8E380000 */  lw    $t8, ($s1)
/* 0BB6F0 7F088D00 03027821 */  addu  $t7, $t8, $v0
/* 0BB6F4 7F088D04 ADE01130 */  sw    $zero, 0x1130($t7)
/* 0BB6F8 7F088D08 8E2E0000 */  lw    $t6, ($s1)
/* 0BB6FC 7F088D0C 01C24021 */  addu  $t0, $t6, $v0
/* 0BB700 7F088D10 24420010 */  addiu $v0, $v0, 0x10
/* 0BB704 7F088D14 1443FFF3 */  bne   $v0, $v1, .L7F088CE4
/* 0BB708 7F088D18 AD001134 */   sw    $zero, 0x1134($t0)
/* 0BB70C 7F088D1C 52000036 */  beql  $s0, $zero, .L7F088DF8
/* 0BB710 7F088D20 44800000 */   mtc1  $zero, $f0
/* 0BB714 7F088D24 8E020000 */  lw    $v0, ($s0)
/* 0BB718 7F088D28 24010009 */  li    $at, 9
/* 0BB71C 7F088D2C 10410031 */  beq   $v0, $at, .L7F088DF4
/* 0BB720 7F088D30 2C410007 */   sltiu $at, $v0, 7
.L7F088D34:
/* 0BB724 7F088D34 1020002A */  beqz  $at, .L7F088DE0
/* 0BB728 7F088D38 00024880 */   sll   $t1, $v0, 2
/* 0BB72C 7F088D3C 3C018005 */  lui   $at, %hi(jpt_mpspawntype)
/* 0BB730 7F088D40 00290821 */  addu  $at, $at, $t1
/* 0BB734 7F088D44 8C29AE64 */  lw    $t1, %lo(jpt_mpspawntype)($at)
/* 0BB738 7F088D48 01200008 */  jr    $t1
/* 0BB73C 7F088D4C 00000000 */   nop   
mp_spawntype_spawn:
/* 0BB740 7F088D50 10000024 */  b     .L7F088DE4
/* 0BB744 7F088D54 2610000C */   addiu $s0, $s0, 0xc
mp_spawntype_weapon:
/* 0BB748 7F088D58 0FC2FFA8 */  jal   check_ramrom_flags
/* 0BB74C 7F088D5C 00000000 */   nop   
/* 0BB750 7F088D60 8E0A000C */  lw    $t2, 0xc($s0)
/* 0BB754 7F088D64 144A000A */  bne   $v0, $t2, .L7F088D90
/* 0BB758 7F088D68 00000000 */   nop   
/* 0BB75C 7F088D6C 8E050008 */  lw    $a1, 8($s0)
/* 0BB760 7F088D70 04A00005 */  bltz  $a1, .L7F088D88
/* 0BB764 7F088D74 00000000 */   nop   
/* 0BB768 7F088D78 0FC23221 */  jal   bondinvAddDoublesInvItem
/* 0BB76C 7F088D7C 8E040004 */   lw    $a0, 4($s0)
/* 0BB770 7F088D80 10000018 */  b     .L7F088DE4
/* 0BB774 7F088D84 26100010 */   addiu $s0, $s0, 0x10
.L7F088D88:
/* 0BB778 7F088D88 0FC231FA */  jal   bondinvAddInvItem
/* 0BB77C 7F088D8C 8E040004 */   lw    $a0, 4($s0)
.L7F088D90:
/* 0BB780 7F088D90 10000014 */  b     .L7F088DE4
/* 0BB784 7F088D94 26100010 */   addiu $s0, $s0, 0x10
mp_spawntype_ammo:
/* 0BB788 7F088D98 0FC2FFA8 */  jal   check_ramrom_flags
/* 0BB78C 7F088D9C 00000000 */   nop   
/* 0BB790 7F088DA0 8E0B000C */  lw    $t3, 0xc($s0)
/* 0BB794 7F088DA4 144B0004 */  bne   $v0, $t3, .L7F088DB8
/* 0BB798 7F088DA8 00000000 */   nop   
/* 0BB79C 7F088DAC 8E040004 */  lw    $a0, 4($s0)
/* 0BB7A0 7F088DB0 0FC1A631 */  jal   give_cur_player_ammo
/* 0BB7A4 7F088DB4 8E050008 */   lw    $a1, 8($s0)
.L7F088DB8:
/* 0BB7A8 7F088DB8 1000000A */  b     .L7F088DE4
/* 0BB7AC 7F088DBC 26100010 */   addiu $s0, $s0, 0x10
mp_spawntype_intro_swirly:
/* 0BB7B0 7F088DC0 10000008 */  b     .L7F088DE4
/* 0BB7B4 7F088DC4 26100020 */   addiu $s0, $s0, 0x20
mp_spawntype_intro_anim:
/* 0BB7B8 7F088DC8 10000006 */  b     .L7F088DE4
/* 0BB7BC 7F088DCC 26100008 */   addiu $s0, $s0, 8
mp_spawntype_handcuff:
/* 0BB7C0 7F088DD0 10000004 */  b     .L7F088DE4
/* 0BB7C4 7F088DD4 26100008 */   addiu $s0, $s0, 8
mp_spawntype_intro_camera:
/* 0BB7C8 7F088DD8 10000002 */  b     .L7F088DE4
/* 0BB7CC 7F088DDC 26100028 */   addiu $s0, $s0, 0x28
mp_spawntype_default:
.L7F088DE0:
/* 0BB7D0 7F088DE0 26100004 */  addiu $s0, $s0, 4
.L7F088DE4:
/* 0BB7D4 7F088DE4 8E020000 */  lw    $v0, ($s0)
/* 0BB7D8 7F088DE8 24010009 */  li    $at, 9
/* 0BB7DC 7F088DEC 5441FFD1 */  bnel  $v0, $at, .L7F088D34
/* 0BB7E0 7F088DF0 2C410007 */   sltiu $at, $v0, 7
.L7F088DF4:
/* 0BB7E4 7F088DF4 44800000 */  mtc1  $zero, $f0
.L7F088DF8:
/* 0BB7E8 7F088DF8 8E2C0000 */  lw    $t4, ($s1)
/* 0BB7EC 7F088DFC 3C018005 */  lui   $at, %hi(D_800552AC) # $at, 0x8005
/* 0BB7F0 7F088E00 E5800078 */  swc1  $f0, 0x78($t4)
/* 0BB7F4 7F088E04 8E2D0000 */  lw    $t5, ($s1)
/* 0BB7F8 7F088E08 C430AE80 */  lwc1  $f16, %lo(D_800552AC)($at)
/* 0BB7FC 7F088E0C 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 0BB800 7F088E10 44816000 */  mtc1  $at, $f12
/* 0BB804 7F088E14 E5B0007C */  swc1  $f16, 0x7c($t5)
/* 0BB808 7F088E18 8E390000 */  lw    $t9, ($s1)
/* 0BB80C 7F088E1C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BB810 7F088E20 44817000 */  mtc1  $at, $f14
/* 0BB814 7F088E24 0FC202AD */  jal   currentPlayerStartChrFade
/* 0BB818 7F088E28 E7200080 */   swc1  $f0, 0x80($t9)
/* 0BB81C 7F088E2C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0BB820 7F088E30 8FB00014 */  lw    $s0, 0x14($sp)
/* 0BB824 7F088E34 8FB10018 */  lw    $s1, 0x18($sp)
/* 0BB828 7F088E38 03E00008 */  jr    $ra
/* 0BB82C 7F088E3C 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif

#endif





#ifdef NONMATCHING
void sub_GAME_7F088CD8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F088CD8
/* 0BD808 7F088CD8 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0BD80C 7F088CDC AFBF005C */  sw    $ra, 0x5c($sp)
/* 0BD810 7F088CE0 AFB5004C */  sw    $s5, 0x4c($sp)
/* 0BD814 7F088CE4 0080A825 */  move  $s5, $a0
/* 0BD818 7F088CE8 AFBE0058 */  sw    $fp, 0x58($sp)
/* 0BD81C 7F088CEC AFB70054 */  sw    $s7, 0x54($sp)
/* 0BD820 7F088CF0 AFB60050 */  sw    $s6, 0x50($sp)
/* 0BD824 7F088CF4 AFB40048 */  sw    $s4, 0x48($sp)
/* 0BD828 7F088CF8 AFB30044 */  sw    $s3, 0x44($sp)
/* 0BD82C 7F088CFC AFB20040 */  sw    $s2, 0x40($sp)
/* 0BD830 7F088D00 AFB1003C */  sw    $s1, 0x3c($sp)
/* 0BD834 7F088D04 0C001A57 */  jal   bossGetStageNum
/* 0BD838 7F088D08 AFB00038 */   sw    $s0, 0x38($sp)
/* 0BD83C 7F088D0C 24010036 */  li    $at, 54
/* 0BD840 7F088D10 14410130 */  bne   $v0, $at, .L7F0891D4
/* 0BD844 7F088D14 3C108003 */   lui   $s0, %hi(D_8003643C)
/* 0BD848 7F088D18 2610643C */  addiu $s0, %lo(D_8003643C) # addiu $s0, $s0, 0x643c
/* 0BD84C 7F088D1C 8E0E0000 */  lw    $t6, ($s0)
/* 0BD850 7F088D20 24010001 */  li    $at, 1
/* 0BD854 7F088D24 3C0F8003 */  lui   $t7, %hi(D_80036440)
/* 0BD858 7F088D28 55C1012B */  bnel  $t6, $at, .L7F0891D8
/* 0BD85C 7F088D2C 8FBF005C */   lw    $ra, 0x5c($sp)
/* 0BD860 7F088D30 8DEF6440 */  lw    $t7, %lo(D_80036440)($t7)
/* 0BD864 7F088D34 3C028003 */  lui   $v0, %hi(camera_80036438)
/* 0BD868 7F088D38 24426438 */  addiu $v0, %lo(camera_80036438) # addiu $v0, $v0, 0x6438
/* 0BD86C 7F088D3C 11E00125 */  beqz  $t7, .L7F0891D4
/* 0BD870 7F088D40 241600DC */   li    $s6, 220
/* 0BD874 7F088D44 8C580000 */  lw    $t8, ($v0)
/* 0BD878 7F088D48 241700DC */  li    $s7, 220
/* 0BD87C 7F088D4C AFA00084 */  sw    $zero, 0x84($sp)
/* 0BD880 7F088D50 27190001 */  addiu $t9, $t8, 1
/* 0BD884 7F088D54 AFA00080 */  sw    $zero, 0x80($sp)
/* 0BD888 7F088D58 AC590000 */  sw    $t9, ($v0)
/* 0BD88C 7F088D5C AFB900B4 */  sw    $t9, 0xb4($sp)
/* 0BD890 7F088D60 0FC2B366 */  jal   microcode_constructor
/* 0BD894 7F088D64 02A02025 */   move  $a0, $s5
/* 0BD898 7F088D68 0C00112B */  jal   viGetViewHeight
/* 0BD89C 7F088D6C 0040A825 */   move  $s5, $v0
/* 0BD8A0 7F088D70 8FAA00B4 */  lw    $t2, 0xb4($sp)
/* 0BD8A4 7F088D74 3C048003 */  lui   $a0, %hi(D_80036440)
/* 0BD8A8 7F088D78 01421823 */  subu  $v1, $t2, $v0
/* 0BD8AC 7F088D7C 04610003 */  bgez  $v1, .L7F088D8C
/* 0BD8B0 7F088D80 00035903 */   sra   $t3, $v1, 4
/* 0BD8B4 7F088D84 2461000F */  addiu $at, $v1, 0xf
/* 0BD8B8 7F088D88 00015903 */  sra   $t3, $at, 4
.L7F088D8C:
/* 0BD8BC 7F088D8C 01601825 */  move  $v1, $t3
/* 0BD8C0 7F088D90 01603025 */  move  $a2, $t3
/* 0BD8C4 7F088D94 05410003 */  bgez  $t2, .L7F088DA4
/* 0BD8C8 7F088D98 000A6103 */   sra   $t4, $t2, 4
/* 0BD8CC 7F088D9C 2541000F */  addiu $at, $t2, 0xf
/* 0BD8D0 7F088DA0 00016103 */  sra   $t4, $at, 4
.L7F088DA4:
/* 0BD8D4 7F088DA4 258D0001 */  addiu $t5, $t4, 1
/* 0BD8D8 7F088DA8 04610002 */  bgez  $v1, .L7F088DB4
/* 0BD8DC 7F088DAC AFAD0090 */   sw    $t5, 0x90($sp)
/* 0BD8E0 7F088DB0 00003025 */  move  $a2, $zero
.L7F088DB4:
/* 0BD8E4 7F088DB4 18C00024 */  blez  $a2, .L7F088E48
/* 0BD8E8 7F088DB8 00009825 */   move  $s3, $zero
/* 0BD8EC 7F088DBC 8C846440 */  lw    $a0, %lo(D_80036440)($a0)
.L7F088DC0:
/* 0BD8F0 7F088DC0 94820000 */  lhu   $v0, ($a0)
/* 0BD8F4 7F088DC4 24015011 */  li    $at, 20497
/* 0BD8F8 7F088DC8 14400008 */  bnez  $v0, .L7F088DEC
/* 0BD8FC 7F088DCC 00000000 */   nop
/* 0BD900 7F088DD0 948E0002 */  lhu   $t6, 2($a0)
/* 0BD904 7F088DD4 15C00005 */  bnez  $t6, .L7F088DEC
/* 0BD908 7F088DD8 240F0002 */   li    $t7, 2
/* 0BD90C 7F088DDC AFB30090 */  sw    $s3, 0x90($sp)
/* 0BD910 7F088DE0 02603025 */  move  $a2, $s3
/* 0BD914 7F088DE4 10000018 */  b     .L7F088E48
/* 0BD918 7F088DE8 AE0F0000 */   sw    $t7, ($s0)
.L7F088DEC:
/* 0BD91C 7F088DEC 10410009 */  beq   $v0, $at, .L7F088E14
/* 0BD920 7F088DF0 94850002 */   lhu   $a1, 2($a0)
/* 0BD924 7F088DF4 84830004 */  lh    $v1, 4($a0)
/* 0BD928 7F088DF8 04620003 */  bltzl $v1, .L7F088E08
/* 0BD92C 7F088DFC 84820006 */   lh    $v0, 6($a0)
/* 0BD930 7F088E00 0060B025 */  move  $s6, $v1
/* 0BD934 7F088E04 84820006 */  lh    $v0, 6($a0)
.L7F088E08:
/* 0BD938 7F088E08 04420003 */  bltzl $v0, .L7F088E18
/* 0BD93C 7F088E0C 24015011 */   li    $at, 20497
/* 0BD940 7F088E10 AFA20084 */  sw    $v0, 0x84($sp)
.L7F088E14:
/* 0BD944 7F088E14 24015011 */  li    $at, 20497
.L7F088E18:
/* 0BD948 7F088E18 10A10009 */  beq   $a1, $at, .L7F088E40
/* 0BD94C 7F088E1C 26730001 */   addiu $s3, $s3, 1
/* 0BD950 7F088E20 84830008 */  lh    $v1, 8($a0)
/* 0BD954 7F088E24 04620003 */  bltzl $v1, .L7F088E34
/* 0BD958 7F088E28 8482000A */   lh    $v0, 0xa($a0)
/* 0BD95C 7F088E2C 0060B825 */  move  $s7, $v1
/* 0BD960 7F088E30 8482000A */  lh    $v0, 0xa($a0)
.L7F088E34:
/* 0BD964 7F088E34 04400002 */  bltz  $v0, .L7F088E40
/* 0BD968 7F088E38 00000000 */   nop
/* 0BD96C 7F088E3C AFA20080 */  sw    $v0, 0x80($sp)
.L7F088E40:
/* 0BD970 7F088E40 1666FFDF */  bne   $s3, $a2, .L7F088DC0
/* 0BD974 7F088E44 2484000C */   addiu $a0, $a0, 0xc
.L7F088E48:
/* 0BD978 7F088E48 8FB80090 */  lw    $t8, 0x90($sp)
/* 0BD97C 7F088E4C 00C09825 */  move  $s3, $a2
/* 0BD980 7F088E50 2405000C */  li    $a1, 12
/* 0BD984 7F088E54 00D8082A */  slt   $at, $a2, $t8
/* 0BD988 7F088E58 102000DB */  beqz  $at, .L7F0891C8
/* 0BD98C 7F088E5C 00000000 */   nop
/* 0BD990 7F088E60 00C50019 */  multu $a2, $a1
/* 0BD994 7F088E64 3C038003 */  lui   $v1, %hi(D_80036440)
/* 0BD998 7F088E68 8C636440 */  lw    $v1, %lo(D_80036440)($v1)
/* 0BD99C 7F088E6C 0000A012 */  mflo  $s4
/* 0BD9A0 7F088E70 00742021 */  addu  $a0, $v1, $s4
/* 0BD9A4 7F088E74 94820000 */  lhu   $v0, ($a0)
/* 0BD9A8 7F088E78 14400007 */  bnez  $v0, .L7F088E98
/* 0BD9AC 7F088E7C 00000000 */   nop
/* 0BD9B0 7F088E80 00C50019 */  multu $a2, $a1
/* 0BD9B4 7F088E84 0000C812 */  mflo  $t9
/* 0BD9B8 7F088E88 00794821 */  addu  $t1, $v1, $t9
/* 0BD9BC 7F088E8C 952B0002 */  lhu   $t3, 2($t1)
/* 0BD9C0 7F088E90 116000CD */  beqz  $t3, .L7F0891C8
/* 0BD9C4 7F088E94 00000000 */   nop
.L7F088E98:
/* 0BD9C8 7F088E98 3C1E8004 */  lui   $fp, %hi(ptrFontZurichBoldChars)
/* 0BD9CC 7F088E9C 24015011 */  li    $at, 20497
/* 0BD9D0 7F088EA0 1041005E */  beq   $v0, $at, .L7F08901C
/* 0BD9D4 7F088EA4 27DE0EB8 */   addiu $fp, %lo(ptrFontZurichBoldChars) # addiu $fp, $fp, 0xeb8
/* 0BD9D8 7F088EA8 00402025 */  move  $a0, $v0
/* 0BD9DC 7F088EAC 0FC30776 */  jal   langGet
/* 0BD9E0 7F088EB0 00138900 */   sll   $s1, $s3, 4
/* 0BD9E4 7F088EB4 3C0A8003 */  lui   $t2, %hi(D_80036440)
/* 0BD9E8 7F088EB8 8D4A6440 */  lw    $t2, %lo(D_80036440)($t2)
/* 0BD9EC 7F088EBC 00409025 */  move  $s2, $v0
/* 0BD9F0 7F088EC0 01542021 */  addu  $a0, $t2, $s4
/* 0BD9F4 7F088EC4 84830004 */  lh    $v1, 4($a0)
/* 0BD9F8 7F088EC8 04620003 */  bltzl $v1, .L7F088ED8
/* 0BD9FC 7F088ECC 84820006 */   lh    $v0, 6($a0)
/* 0BDA00 7F088ED0 0060B025 */  move  $s6, $v1
/* 0BDA04 7F088ED4 84820006 */  lh    $v0, 6($a0)
.L7F088ED8:
/* 0BDA08 7F088ED8 04400002 */  bltz  $v0, .L7F088EE4
/* 0BDA0C 7F088EDC 00000000 */   nop
/* 0BDA10 7F088EE0 AFA20084 */  sw    $v0, 0x84($sp)
.L7F088EE4:
/* 0BDA14 7F088EE4 0C00112B */  jal   viGetViewHeight
/* 0BDA18 7F088EE8 00000000 */   nop
/* 0BDA1C 7F088EEC 00028400 */  sll   $s0, $v0, 0x10
/* 0BDA20 7F088EF0 00106403 */  sra   $t4, $s0, 0x10
/* 0BDA24 7F088EF4 0C001149 */  jal   viGetViewTop
/* 0BDA28 7F088EF8 01808025 */   move  $s0, $t4
/* 0BDA2C 7F088EFC 8FAE00B4 */  lw    $t6, 0xb4($sp)
/* 0BDA30 7F088F00 00516821 */  addu  $t5, $v0, $s1
/* 0BDA34 7F088F04 3C198004 */  lui   $t9, %hi(ptrFontZurichBold)
/* 0BDA38 7F088F08 8F390EB4 */  lw    $t9, %lo(ptrFontZurichBold)($t9)
/* 0BDA3C 7F088F0C 01AE7823 */  subu  $t7, $t5, $t6
/* 0BDA40 7F088F10 01F0C021 */  addu  $t8, $t7, $s0
/* 0BDA44 7F088F14 AFB800A8 */  sw    $t8, 0xa8($sp)
/* 0BDA48 7F088F18 AFA0009C */  sw    $zero, 0x9c($sp)
/* 0BDA4C 7F088F1C 27A4009C */  addiu $a0, $sp, 0x9c
/* 0BDA50 7F088F20 27A50098 */  addiu $a1, $sp, 0x98
/* 0BDA54 7F088F24 02403025 */  move  $a2, $s2
/* 0BDA58 7F088F28 8FC70000 */  lw    $a3, ($fp)
/* 0BDA5C 7F088F2C AFA00014 */  sw    $zero, 0x14($sp)
/* 0BDA60 7F088F30 AFA00098 */  sw    $zero, 0x98($sp)
/* 0BDA64 7F088F34 0FC2BA63 */  jal   textMeasure
/* 0BDA68 7F088F38 AFB90010 */   sw    $t9, 0x10($sp)
/* 0BDA6C 7F088F3C 8FAA0084 */  lw    $t2, 0x84($sp)
/* 0BDA70 7F088F40 8FA900A8 */  lw    $t1, 0xa8($sp)
/* 0BDA74 7F088F44 8FAB009C */  lw    $t3, 0x9c($sp)
/* 0BDA78 7F088F48 24010001 */  li    $at, 1
/* 0BDA7C 7F088F4C 15410005 */  bne   $t2, $at, .L7F088F64
/* 0BDA80 7F088F50 012B1821 */   addu  $v1, $t1, $t3
/* 0BDA84 7F088F54 8FA80098 */  lw    $t0, 0x98($sp)
/* 0BDA88 7F088F58 02C01025 */  move  $v0, $s6
/* 0BDA8C 7F088F5C 1000000C */  b     .L7F088F90
/* 0BDA90 7F088F60 02C82823 */   subu  $a1, $s6, $t0
.L7F088F64:
/* 0BDA94 7F088F64 8FAC0084 */  lw    $t4, 0x84($sp)
/* 0BDA98 7F088F68 24010002 */  li    $at, 2
/* 0BDA9C 7F088F6C 8FA80098 */  lw    $t0, 0x98($sp)
/* 0BDAA0 7F088F70 15810006 */  bne   $t4, $at, .L7F088F8C
/* 0BDAA4 7F088F74 02C02825 */   move  $a1, $s6
/* 0BDAA8 7F088F78 8FA80098 */  lw    $t0, 0x98($sp)
/* 0BDAAC 7F088F7C 00086843 */  sra   $t5, $t0, 1
/* 0BDAB0 7F088F80 02CD2823 */  subu  $a1, $s6, $t5
/* 0BDAB4 7F088F84 10000002 */  b     .L7F088F90
/* 0BDAB8 7F088F88 00A81021 */   addu  $v0, $a1, $t0
.L7F088F8C:
/* 0BDABC 7F088F8C 02C81021 */  addu  $v0, $s6, $t0
.L7F088F90:
/* 0BDAC0 7F088F90 8FA600A8 */  lw    $a2, 0xa8($sp)
/* 0BDAC4 7F088F94 246E0001 */  addiu $t6, $v1, 1
/* 0BDAC8 7F088F98 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0BDACC 7F088F9C 02A02025 */  move  $a0, $s5
/* 0BDAD0 7F088FA0 24470001 */  addiu $a3, $v0, 1
/* 0BDAD4 7F088FA4 AFA00014 */  sw    $zero, 0x14($sp)
/* 0BDAD8 7F088FA8 AFA500AC */  sw    $a1, 0xac($sp)
/* 0BDADC 7F088FAC 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0BDAE0 7F088FB0 24C6FFFF */   addiu $a2, $a2, -1
/* 0BDAE4 7F088FB4 0C001107 */  jal   viGetX
/* 0BDAE8 7F088FB8 0040A825 */   move  $s5, $v0
/* 0BDAEC 7F088FBC 00028400 */  sll   $s0, $v0, 0x10
/* 0BDAF0 7F088FC0 00107C03 */  sra   $t7, $s0, 0x10
/* 0BDAF4 7F088FC4 0C00110B */  jal   viGetY
/* 0BDAF8 7F088FC8 01E08025 */   move  $s0, $t7
/* 0BDAFC 7F088FCC 3C198004 */  lui   $t9, %hi(ptrFontZurichBold)
/* 0BDB00 7F088FD0 8F390EB4 */  lw    $t9, %lo(ptrFontZurichBold)($t9)
/* 0BDB04 7F088FD4 8FD80000 */  lw    $t8, ($fp)
/* 0BDB08 7F088FD8 2409FFFF */  li    $t1, -1
/* 0BDB0C 7F088FDC AFA90018 */  sw    $t1, 0x18($sp)
/* 0BDB10 7F088FE0 02A02025 */  move  $a0, $s5
/* 0BDB14 7F088FE4 27A500AC */  addiu $a1, $sp, 0xac
/* 0BDB18 7F088FE8 27A600A8 */  addiu $a2, $sp, 0xa8
/* 0BDB1C 7F088FEC 02403825 */  move  $a3, $s2
/* 0BDB20 7F088FF0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0BDB24 7F088FF4 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BDB28 7F088FF8 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BDB2C 7F088FFC AFA00028 */  sw    $zero, 0x28($sp)
/* 0BDB30 7F089000 AFB90014 */  sw    $t9, 0x14($sp)
/* 0BDB34 7F089004 0FC2B6AF */  jal   textRender
/* 0BDB38 7F089008 AFB80010 */   sw    $t8, 0x10($sp)
/* 0BDB3C 7F08900C 3C0B8003 */  lui   $t3, %hi(D_80036440)
/* 0BDB40 7F089010 8D6B6440 */  lw    $t3, %lo(D_80036440)($t3)
/* 0BDB44 7F089014 0040A825 */  move  $s5, $v0
/* 0BDB48 7F089018 01742021 */  addu  $a0, $t3, $s4
.L7F08901C:
/* 0BDB4C 7F08901C 94850002 */  lhu   $a1, 2($a0)
/* 0BDB50 7F089020 24015011 */  li    $at, 20497
/* 0BDB54 7F089024 10A1005A */  beq   $a1, $at, .L7F089190
/* 0BDB58 7F089028 00A02025 */   move  $a0, $a1
/* 0BDB5C 7F08902C 0FC30776 */  jal   langGet
/* 0BDB60 7F089030 00138900 */   sll   $s1, $s3, 4
/* 0BDB64 7F089034 3C0A8003 */  lui   $t2, %hi(D_80036440)
/* 0BDB68 7F089038 8D4A6440 */  lw    $t2, %lo(D_80036440)($t2)
/* 0BDB6C 7F08903C 00409025 */  move  $s2, $v0
/* 0BDB70 7F089040 01542021 */  addu  $a0, $t2, $s4
/* 0BDB74 7F089044 84830008 */  lh    $v1, 8($a0)
/* 0BDB78 7F089048 04620003 */  bltzl $v1, .L7F089058
/* 0BDB7C 7F08904C 8482000A */   lh    $v0, 0xa($a0)
/* 0BDB80 7F089050 0060B825 */  move  $s7, $v1
/* 0BDB84 7F089054 8482000A */  lh    $v0, 0xa($a0)
.L7F089058:
/* 0BDB88 7F089058 04400002 */  bltz  $v0, .L7F089064
/* 0BDB8C 7F08905C 00000000 */   nop
/* 0BDB90 7F089060 AFA20080 */  sw    $v0, 0x80($sp)
.L7F089064:
/* 0BDB94 7F089064 0C00112B */  jal   viGetViewHeight
/* 0BDB98 7F089068 00000000 */   nop
/* 0BDB9C 7F08906C 00028400 */  sll   $s0, $v0, 0x10
/* 0BDBA0 7F089070 00106403 */  sra   $t4, $s0, 0x10
/* 0BDBA4 7F089074 0C001149 */  jal   viGetViewTop
/* 0BDBA8 7F089078 01808025 */   move  $s0, $t4
/* 0BDBAC 7F08907C 8FAE00B4 */  lw    $t6, 0xb4($sp)
/* 0BDBB0 7F089080 00516821 */  addu  $t5, $v0, $s1
/* 0BDBB4 7F089084 3C198004 */  lui   $t9, %hi(ptrFontZurichBold)
/* 0BDBB8 7F089088 8F390EB4 */  lw    $t9, %lo(ptrFontZurichBold)($t9)
/* 0BDBBC 7F08908C 01AE7823 */  subu  $t7, $t5, $t6
/* 0BDBC0 7F089090 01F0C021 */  addu  $t8, $t7, $s0
/* 0BDBC4 7F089094 AFB800A8 */  sw    $t8, 0xa8($sp)
/* 0BDBC8 7F089098 AFA0009C */  sw    $zero, 0x9c($sp)
/* 0BDBCC 7F08909C 27A4009C */  addiu $a0, $sp, 0x9c
/* 0BDBD0 7F0890A0 27A50098 */  addiu $a1, $sp, 0x98
/* 0BDBD4 7F0890A4 02403025 */  move  $a2, $s2
/* 0BDBD8 7F0890A8 8FC70000 */  lw    $a3, ($fp)
/* 0BDBDC 7F0890AC AFA00014 */  sw    $zero, 0x14($sp)
/* 0BDBE0 7F0890B0 AFA00098 */  sw    $zero, 0x98($sp)
/* 0BDBE4 7F0890B4 0FC2BA63 */  jal   textMeasure
/* 0BDBE8 7F0890B8 AFB90010 */   sw    $t9, 0x10($sp)
/* 0BDBEC 7F0890BC 8FAA0080 */  lw    $t2, 0x80($sp)
/* 0BDBF0 7F0890C0 8FA900A8 */  lw    $t1, 0xa8($sp)
/* 0BDBF4 7F0890C4 8FAB009C */  lw    $t3, 0x9c($sp)
/* 0BDBF8 7F0890C8 24010001 */  li    $at, 1
/* 0BDBFC 7F0890CC 15410005 */  bne   $t2, $at, .L7F0890E4
/* 0BDC00 7F0890D0 012B1821 */   addu  $v1, $t1, $t3
/* 0BDC04 7F0890D4 8FA80098 */  lw    $t0, 0x98($sp)
/* 0BDC08 7F0890D8 02E01025 */  move  $v0, $s7
/* 0BDC0C 7F0890DC 1000000C */  b     .L7F089110
/* 0BDC10 7F0890E0 02E82823 */   subu  $a1, $s7, $t0
.L7F0890E4:
/* 0BDC14 7F0890E4 8FAC0080 */  lw    $t4, 0x80($sp)
/* 0BDC18 7F0890E8 24010002 */  li    $at, 2
/* 0BDC1C 7F0890EC 8FA80098 */  lw    $t0, 0x98($sp)
/* 0BDC20 7F0890F0 15810006 */  bne   $t4, $at, .L7F08910C
/* 0BDC24 7F0890F4 02E02825 */   move  $a1, $s7
/* 0BDC28 7F0890F8 8FA80098 */  lw    $t0, 0x98($sp)
/* 0BDC2C 7F0890FC 00086843 */  sra   $t5, $t0, 1
/* 0BDC30 7F089100 02ED2823 */  subu  $a1, $s7, $t5
/* 0BDC34 7F089104 10000002 */  b     .L7F089110
/* 0BDC38 7F089108 00A81021 */   addu  $v0, $a1, $t0
.L7F08910C:
/* 0BDC3C 7F08910C 02E81021 */  addu  $v0, $s7, $t0
.L7F089110:
/* 0BDC40 7F089110 8FA600A8 */  lw    $a2, 0xa8($sp)
/* 0BDC44 7F089114 246E0001 */  addiu $t6, $v1, 1
/* 0BDC48 7F089118 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0BDC4C 7F08911C 02A02025 */  move  $a0, $s5
/* 0BDC50 7F089120 24470001 */  addiu $a3, $v0, 1
/* 0BDC54 7F089124 AFA00014 */  sw    $zero, 0x14($sp)
/* 0BDC58 7F089128 AFA500AC */  sw    $a1, 0xac($sp)
/* 0BDC5C 7F08912C 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0BDC60 7F089130 24C6FFFF */   addiu $a2, $a2, -1
/* 0BDC64 7F089134 0C001107 */  jal   viGetX
/* 0BDC68 7F089138 0040A825 */   move  $s5, $v0
/* 0BDC6C 7F08913C 00028400 */  sll   $s0, $v0, 0x10
/* 0BDC70 7F089140 00107C03 */  sra   $t7, $s0, 0x10
/* 0BDC74 7F089144 0C00110B */  jal   viGetY
/* 0BDC78 7F089148 01E08025 */   move  $s0, $t7
/* 0BDC7C 7F08914C 3C198004 */  lui   $t9, %hi(ptrFontZurichBold)
/* 0BDC80 7F089150 8F390EB4 */  lw    $t9, %lo(ptrFontZurichBold)($t9)
/* 0BDC84 7F089154 8FD80000 */  lw    $t8, ($fp)
/* 0BDC88 7F089158 2409FFFF */  li    $t1, -1
/* 0BDC8C 7F08915C AFA90018 */  sw    $t1, 0x18($sp)
/* 0BDC90 7F089160 02A02025 */  move  $a0, $s5
/* 0BDC94 7F089164 27A500AC */  addiu $a1, $sp, 0xac
/* 0BDC98 7F089168 27A600A8 */  addiu $a2, $sp, 0xa8
/* 0BDC9C 7F08916C 02403825 */  move  $a3, $s2
/* 0BDCA0 7F089170 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0BDCA4 7F089174 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BDCA8 7F089178 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BDCAC 7F08917C AFA00028 */  sw    $zero, 0x28($sp)
/* 0BDCB0 7F089180 AFB90014 */  sw    $t9, 0x14($sp)
/* 0BDCB4 7F089184 0FC2B6AF */  jal   textRender
/* 0BDCB8 7F089188 AFB80010 */   sw    $t8, 0x10($sp)
/* 0BDCBC 7F08918C 0040A825 */  move  $s5, $v0
.L7F089190:
/* 0BDCC0 7F089190 8FAB0090 */  lw    $t3, 0x90($sp)
/* 0BDCC4 7F089194 26730001 */  addiu $s3, $s3, 1
/* 0BDCC8 7F089198 2694000C */  addiu $s4, $s4, 0xc
/* 0BDCCC 7F08919C 026B082A */  slt   $at, $s3, $t3
/* 0BDCD0 7F0891A0 10200009 */  beqz  $at, .L7F0891C8
/* 0BDCD4 7F0891A4 3C0A8003 */   lui   $t2, %hi(D_80036440)
/* 0BDCD8 7F0891A8 8D4A6440 */  lw    $t2, %lo(D_80036440)($t2)
/* 0BDCDC 7F0891AC 01542021 */  addu  $a0, $t2, $s4
/* 0BDCE0 7F0891B0 94820000 */  lhu   $v0, ($a0)
/* 0BDCE4 7F0891B4 1440FF38 */  bnez  $v0, .L7F088E98
/* 0BDCE8 7F0891B8 00000000 */   nop
/* 0BDCEC 7F0891BC 948C0002 */  lhu   $t4, 2($a0)
/* 0BDCF0 7F0891C0 1580FF35 */  bnez  $t4, .L7F088E98
/* 0BDCF4 7F0891C4 00000000 */   nop
.L7F0891C8:
/* 0BDCF8 7F0891C8 0FC2B3BC */  jal   combiner_bayer_lod_perspective
/* 0BDCFC 7F0891CC 02A02025 */   move  $a0, $s5
/* 0BDD00 7F0891D0 0040A825 */  move  $s5, $v0
.L7F0891D4:
/* 0BDD04 7F0891D4 8FBF005C */  lw    $ra, 0x5c($sp)
.L7F0891D8:
/* 0BDD08 7F0891D8 02A01025 */  move  $v0, $s5
/* 0BDD0C 7F0891DC 8FB5004C */  lw    $s5, 0x4c($sp)
/* 0BDD10 7F0891E0 8FB00038 */  lw    $s0, 0x38($sp)
/* 0BDD14 7F0891E4 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0BDD18 7F0891E8 8FB20040 */  lw    $s2, 0x40($sp)
/* 0BDD1C 7F0891EC 8FB30044 */  lw    $s3, 0x44($sp)
/* 0BDD20 7F0891F0 8FB40048 */  lw    $s4, 0x48($sp)
/* 0BDD24 7F0891F4 8FB60050 */  lw    $s6, 0x50($sp)
/* 0BDD28 7F0891F8 8FB70054 */  lw    $s7, 0x54($sp)
/* 0BDD2C 7F0891FC 8FBE0058 */  lw    $fp, 0x58($sp)
/* 0BDD30 7F089200 03E00008 */  jr    $ra
/* 0BDD34 7F089204 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif





#ifdef NONMATCHING
Gfx * maybe_mp_interface(Gfx *arg0) {

}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel maybe_mp_interface
/* 0BDD38 7F089208 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0BDD3C 7F08920C 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BDD40 7F089210 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0BDD44 7F089214 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0BDD48 7F089218 AFA40058 */  sw    $a0, 0x58($sp)
/* 0BDD4C 7F08921C 8DCF0000 */  lw    $t7, ($t6)
/* 0BDD50 7F089220 24010001 */  li    $at, 1
/* 0BDD54 7F089224 15E10014 */  bne   $t7, $at, .L7F089278
/* 0BDD58 7F089228 00000000 */   nop
/* 0BDD5C 7F08922C 0FC22939 */  jal   bondviewIntroCameraTextTick
/* 0BDD60 7F089230 00000000 */   nop
/* 0BDD64 7F089234 0FC2297F */  jal   sub_GAME_7F08A5FC
/* 0BDD68 7F089238 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BDD6C 7F08923C 0FC22A7E */  jal   bondviewUpperTextWindowTimerTick
/* 0BDD70 7F089240 AFA20058 */   sw    $v0, 0x58($sp)
/* 0BDD74 7F089244 0FC22ABA */  jal   sub_GAME_7F08AAE8
/* 0BDD78 7F089248 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BDD7C 7F08924C AFA20058 */  sw    $v0, 0x58($sp)
/* 0BDD80 7F089250 0FC15884 */  jal   countdownTimerRender
/* 0BDD84 7F089254 00402025 */   move  $a0, $v0
/* 0BDD88 7F089258 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BDD8C 7F08925C 0FC20138 */  jal   currentPlayerDrawFade
/* 0BDD90 7F089260 00402025 */   move  $a0, $v0
/* 0BDD94 7F089264 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BDD98 7F089268 0FC22336 */  jal   sub_GAME_7F088CD8
/* 0BDD9C 7F08926C 00402025 */   move  $a0, $v0
/* 0BDDA0 7F089270 10000110 */  b     .L7F0896B4
/* 0BDDA4 7F089274 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F089278:
/* 0BDDA8 7F089278 0FC18648 */  jal   bondwalkFireBothHands
/* 0BDDAC 7F08927C 00000000 */   nop
/* 0BDDB0 7F089280 0FC1A423 */  jal   sub_GAME_7F06908C
/* 0BDDB4 7F089284 27A40058 */   addiu $a0, $sp, 0x58
/* 0BDDB8 7F089288 0FC18AF9 */  jal   sub_GAME_7F062BE4
/* 0BDDBC 7F08928C 27A40058 */   addiu $a0, $sp, 0x58
/* 0BDDC0 7F089290 0FC21F9D */  jal   sub_GAME_7F087E74
/* 0BDDC4 7F089294 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BDDC8 7F089298 3C188008 */  lui   $t8, %hi(g_CurrentPlayer)
/* 0BDDCC 7F08929C 8F18A0B0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0BDDD0 7F0892A0 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BDDD4 7F0892A4 8F1929C4 */  lw    $t9, 0x29c4($t8)
/* 0BDDD8 7F0892A8 1320001F */  beqz  $t9, .L7F089328
/* 0BDDDC 7F0892AC 00000000 */   nop
/* 0BDDE0 7F0892B0 0C001145 */  jal   viGetViewLeft
/* 0BDDE4 7F0892B4 00000000 */   nop
/* 0BDDE8 7F0892B8 0C001149 */  jal   viGetViewTop
/* 0BDDEC 7F0892BC AFA20054 */   sw    $v0, 0x54($sp)
/* 0BDDF0 7F0892C0 0C001145 */  jal   viGetViewLeft
/* 0BDDF4 7F0892C4 AFA20050 */   sw    $v0, 0x50($sp)
/* 0BDDF8 7F0892C8 0C001127 */  jal   viGetViewWidth
/* 0BDDFC 7F0892CC A7A2002E */   sh    $v0, 0x2e($sp)
/* 0BDE00 7F0892D0 87A8002E */  lh    $t0, 0x2e($sp)
/* 0BDE04 7F0892D4 00484821 */  addu  $t1, $v0, $t0
/* 0BDE08 7F0892D8 0C001149 */  jal   viGetViewTop
/* 0BDE0C 7F0892DC AFA9004C */   sw    $t1, 0x4c($sp)
/* 0BDE10 7F0892E0 0C00112B */  jal   viGetViewHeight
/* 0BDE14 7F0892E4 A7A2002E */   sh    $v0, 0x2e($sp)
/* 0BDE18 7F0892E8 87AA002E */  lh    $t2, 0x2e($sp)
/* 0BDE1C 7F0892EC 8FA40058 */  lw    $a0, 0x58($sp)
/* 0BDE20 7F0892F0 004A5821 */  addu  $t3, $v0, $t2
/* 0BDE24 7F0892F4 0FC2B366 */  jal   microcode_constructor
/* 0BDE28 7F0892F8 AFAB0048 */   sw    $t3, 0x48($sp)
/* 0BDE2C 7F0892FC 8FAC0048 */  lw    $t4, 0x48($sp)
/* 0BDE30 7F089300 240D00A0 */  li    $t5, 160
/* 0BDE34 7F089304 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BDE38 7F089308 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0BDE3C 7F08930C 00402025 */  move  $a0, $v0
/* 0BDE40 7F089310 8FA50054 */  lw    $a1, 0x54($sp)
/* 0BDE44 7F089314 8FA60050 */  lw    $a2, 0x50($sp)
/* 0BDE48 7F089318 8FA7004C */  lw    $a3, 0x4c($sp)
/* 0BDE4C 7F08931C 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0BDE50 7F089320 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0BDE54 7F089324 AFA20058 */  sw    $v0, 0x58($sp)
.L7F089328:
/* 0BDE58 7F089328 0FC227AF */  jal   bondviewGetIfCurrentPlayerHealthShowTime
/* 0BDE5C 7F08932C 00000000 */   nop
/* 0BDE60 7F089330 10400009 */  beqz  $v0, .L7F089358
/* 0BDE64 7F089334 3C0E8008 */   lui   $t6, %hi(g_CurrentPlayer)
/* 0BDE68 7F089338 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BDE6C 7F08933C 8DCF01C8 */  lw    $t7, 0x1c8($t6)
/* 0BDE70 7F089340 15E00005 */  bnez  $t7, .L7F089358
/* 0BDE74 7F089344 00000000 */   nop
/* 0BDE78 7F089348 0FC22186 */  jal   sub_GAME_7F088618
/* 0BDE7C 7F08934C 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BDE80 7F089350 10000017 */  b     .L7F0893B0
/* 0BDE84 7F089354 AFA20058 */   sw    $v0, 0x58($sp)
.L7F089358:
/* 0BDE88 7F089358 0FC31812 */  jal   sub_GAME_7F0C6048
/* 0BDE8C 7F08935C 00000000 */   nop
/* 0BDE90 7F089360 10400013 */  beqz  $v0, .L7F0893B0
/* 0BDE94 7F089364 00000000 */   nop
/* 0BDE98 7F089368 0FC22186 */  jal   sub_GAME_7F088618
/* 0BDE9C 7F08936C 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BDEA0 7F089370 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0BDEA4 7F089374 8C63A0B0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BDEA8 7F089378 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BDEAC 7F08937C 3C188005 */  lui   $t8, %hi(g_ClockTimer)
/* 0BDEB0 7F089380 8C642A00 */  lw    $a0, 0x2a00($v1)
/* 0BDEB4 7F089384 18800007 */  blez  $a0, .L7F0893A4
/* 0BDEB8 7F089388 00000000 */   nop
/* 0BDEBC 7F08938C 8F188374 */  lw    $t8, %lo(g_ClockTimer)($t8)
/* 0BDEC0 7F089390 0098C823 */  subu  $t9, $a0, $t8
/* 0BDEC4 7F089394 AC792A00 */  sw    $t9, 0x2a00($v1)
/* 0BDEC8 7F089398 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0BDECC 7F08939C 8C63A0B0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BDED0 7F0893A0 8C642A00 */  lw    $a0, 0x2a00($v1)
.L7F0893A4:
/* 0BDED4 7F0893A4 04810002 */  bgez  $a0, .L7F0893B0
/* 0BDED8 7F0893A8 00000000 */   nop
/* 0BDEDC 7F0893AC AC602A00 */  sw    $zero, 0x2a00($v1)
.L7F0893B0:
/* 0BDEE0 7F0893B0 0FC26919 */  jal   getPlayerCount
/* 0BDEE4 7F0893B4 00000000 */   nop
/* 0BDEE8 7F0893B8 24010001 */  li    $at, 1
/* 0BDEEC 7F0893BC 14410003 */  bne   $v0, $at, .L7F0893CC
/* 0BDEF0 7F0893C0 00000000 */   nop
/* 0BDEF4 7F0893C4 0FC15D50 */  jal   display_objective_status_text_on_status_change
/* 0BDEF8 7F0893C8 00000000 */   nop
.L7F0893CC:
/* 0BDEFC 7F0893CC 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0BDF00 7F0893D0 8C63A0B0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BDF04 7F0893D4 8C6200D8 */  lw    $v0, 0xd8($v1)
/* 0BDF08 7F0893D8 1040009F */  beqz  $v0, .L7F089658
/* 0BDF0C 7F0893DC 00000000 */   nop
/* 0BDF10 7F0893E0 8C680428 */  lw    $t0, 0x428($v1)
/* 0BDF14 7F0893E4 24010001 */  li    $at, 1
/* 0BDF18 7F0893E8 15000045 */  bnez  $t0, .L7F089500
/* 0BDF1C 7F0893EC 00000000 */   nop
/* 0BDF20 7F0893F0 14410004 */  bne   $v0, $at, .L7F089404
/* 0BDF24 7F0893F4 00002025 */   move  $a0, $zero
/* 0BDF28 7F0893F8 24090002 */  li    $t1, 2
/* 0BDF2C 7F0893FC 24040001 */  li    $a0, 1
/* 0BDF30 7F089400 AC6900D8 */  sw    $t1, 0xd8($v1)
.L7F089404:
/* 0BDF34 7F089404 1080001F */  beqz  $a0, .L7F089484
/* 0BDF38 7F089408 3C0A8008 */   lui   $t2, %hi(g_CurrentPlayer)
/* 0BDF3C 7F08940C 0FC070A1 */  jal   die_blood_image_routine
/* 0BDF40 7F089410 00002025 */   move  $a0, $zero
/* 0BDF44 7F089414 0FC26919 */  jal   getPlayerCount
/* 0BDF48 7F089418 00000000 */   nop
/* 0BDF4C 7F08941C 24010001 */  li    $at, 1
/* 0BDF50 7F089420 14410013 */  bne   $v0, $at, .L7F089470
/* 0BDF54 7F089424 00000000 */   nop
/* 0BDF58 7F089428 0FC30556 */  jal   musicStopSlot
/* 0BDF5C 7F08942C 2404FFFF */   li    $a0, -1
/* 0BDF60 7F089430 0FC3030F */  jal   set_missionstate
/* 0BDF64 7F089434 00002025 */   move  $a0, $zero
/* 0BDF68 7F089438 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0BDF6C 7F08943C 00000000 */   nop
/* 0BDF70 7F089440 0C001C0F */  jal   musicTrack1ApplySeqpVol
/* 0BDF74 7F089444 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0BDF78 7F089448 3C018002 */  lui   $at, %hi(g_musicXTrack1Fade)
/* 0BDF7C 7F08944C AC20434C */  sw    $zero, %lo(g_musicXTrack1Fade)($at)
/* 0BDF80 7F089450 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0BDF84 7F089454 00002025 */   move  $a0, $zero
/* 0BDF88 7F089458 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0BDF8C 7F08945C AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0BDF90 7F089460 0C001B9F */  jal   musicTrack1Play
/* 0BDF94 7F089464 2404001B */   li    $a0, 27
/* 0BDF98 7F089468 10000003 */  b     .L7F089478
/* 0BDF9C 7F08946C 00000000 */   nop
.L7F089470:
/* 0BDFA0 7F089470 0FC3030F */  jal   set_missionstate
/* 0BDFA4 7F089474 24040006 */   li    $a0, 6
.L7F089478:
/* 0BDFA8 7F089478 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0BDFAC 7F08947C 10000020 */  b     .L7F089500
/* 0BDFB0 7F089480 8C63A0B0 */   lw    $v1, %lo(g_CurrentPlayer)($v1)
.L7F089484:
/* 0BDFB4 7F089484 8D4AA0B0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0BDFB8 7F089488 24040096 */  li    $a0, 150
/* 0BDFBC 7F08948C 00002825 */  move  $a1, $zero
/* 0BDFC0 7F089490 8D4B0424 */  lw    $t3, 0x424($t2)
/* 0BDFC4 7F089494 00003025 */  move  $a2, $zero
/* 0BDFC8 7F089498 3C073F34 */  lui   $a3, (0x3F34B4B5 >> 16) # lui $a3, 0x3f34
/* 0BDFCC 7F08949C 11600006 */  beqz  $t3, .L7F0894B8
/* 0BDFD0 7F0894A0 3C0C8005 */   lui   $t4, %hi(g_ClockTimer)
/* 0BDFD4 7F0894A4 0FC201EC */  jal   currentPlayerSetFadeColour
/* 0BDFD8 7F0894A8 34E7B4B5 */   ori   $a3, (0x3F34B4B5 & 0xFFFF) # ori $a3, $a3, 0xb4b5
/* 0BDFDC 7F0894AC 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0BDFE0 7F0894B0 10000013 */  b     .L7F089500
/* 0BDFE4 7F0894B4 8C63A0B0 */   lw    $v1, %lo(g_CurrentPlayer)($v1)
.L7F0894B8:
/* 0BDFE8 7F0894B8 8D8C8374 */  lw    $t4, %lo(g_ClockTimer)($t4)
/* 0BDFEC 7F0894BC 24040002 */  li    $a0, 2
/* 0BDFF0 7F0894C0 19800003 */  blez  $t4, .L7F0894D0
/* 0BDFF4 7F0894C4 00000000 */   nop
/* 0BDFF8 7F0894C8 10000001 */  b     .L7F0894D0
/* 0BDFFC 7F0894CC 24040001 */   li    $a0, 1
.L7F0894D0:
/* 0BE000 7F0894D0 0FC070A1 */  jal   die_blood_image_routine
/* 0BE004 7F0894D4 00000000 */   nop
/* 0BE008 7F0894D8 10400004 */  beqz  $v0, .L7F0894EC
/* 0BE00C 7F0894DC 3C0E8008 */   lui   $t6, %hi(g_CurrentPlayer)
/* 0BE010 7F0894E0 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BE014 7F0894E4 240D0001 */  li    $t5, 1
/* 0BE018 7F0894E8 ADCD0424 */  sw    $t5, 0x424($t6)
.L7F0894EC:
/* 0BE01C 7F0894EC 0FC0719C */  jal   gameplayBloodOverlayDL
/* 0BE020 7F0894F0 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BE024 7F0894F4 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0BE028 7F0894F8 8C63A0B0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BE02C 7F0894FC AFA20058 */  sw    $v0, 0x58($sp)
.L7F089500:
/* 0BE030 7F089500 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 0BE034 7F089504 24640598 */   addiu $a0, $v1, 0x598
/* 0BE038 7F089508 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0BE03C 7F08950C 8C84A0B0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BE040 7F089510 E7A00024 */  swc1  $f0, 0x24($sp)
/* 0BE044 7F089514 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 0BE048 7F089518 24840598 */   addiu $a0, $a0, 0x598
/* 0BE04C 7F08951C C7A40024 */  lwc1  $f4, 0x24($sp)
/* 0BE050 7F089520 3C038008 */  lui   $v1, %hi(g_CurrentPlayer)
/* 0BE054 7F089524 4604003E */  c.le.s $f0, $f4
/* 0BE058 7F089528 00000000 */  nop
/* 0BE05C 7F08952C 4500004A */  bc1f  .L7F089658
/* 0BE060 7F089530 00000000 */   nop
/* 0BE064 7F089534 8C63A0B0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BE068 7F089538 8C6F0424 */  lw    $t7, 0x424($v1)
/* 0BE06C 7F08953C 11E00046 */  beqz  $t7, .L7F089658
/* 0BE070 7F089540 00000000 */   nop
/* 0BE074 7F089544 8C780428 */  lw    $t8, 0x428($v1)
/* 0BE078 7F089548 24190001 */  li    $t9, 1
/* 0BE07C 7F08954C 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BE080 7F089550 1700000E */  bnez  $t8, .L7F08958C
/* 0BE084 7F089554 00002825 */   move  $a1, $zero
/* 0BE088 7F089558 44816000 */  mtc1  $at, $f12
/* 0BE08C 7F08955C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BE090 7F089560 44813000 */  mtc1  $at, $f6
/* 0BE094 7F089564 AC790428 */  sw    $t9, 0x428($v1)
/* 0BE098 7F089568 00003025 */  move  $a2, $zero
/* 0BE09C 7F08956C 00003825 */  move  $a3, $zero
/* 0BE0A0 7F089570 0FC201F8 */  jal   currentPlayerAdjustFade
/* 0BE0A4 7F089574 E7A60010 */   swc1  $f6, 0x10($sp)
/* 0BE0A8 7F089578 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 0BE0AC 7F08957C 44816000 */  mtc1  $at, $f12
/* 0BE0B0 7F089580 44807000 */  mtc1  $zero, $f14
/* 0BE0B4 7F089584 0FC20284 */  jal   currentPlayerStartChrFade
/* 0BE0B8 7F089588 00000000 */   nop
.L7F08958C:
/* 0BE0BC 7F08958C 0FC20223 */  jal   currentPlayerIsFadeComplete
/* 0BE0C0 7F089590 00000000 */   nop
/* 0BE0C4 7F089594 10400030 */  beqz  $v0, .L7F089658
/* 0BE0C8 7F089598 00000000 */   nop
/* 0BE0CC 7F08959C 0FC26919 */  jal   getPlayerCount
/* 0BE0D0 7F0895A0 00000000 */   nop
/* 0BE0D4 7F0895A4 24010001 */  li    $at, 1
/* 0BE0D8 7F0895A8 14410005 */  bne   $v0, $at, .L7F0895C0
/* 0BE0DC 7F0895AC 00000000 */   nop
/* 0BE0E0 7F0895B0 0FC1EA6E */  jal   set_camera_mode
/* 0BE0E4 7F0895B4 24040005 */   li    $a0, 5
/* 0BE0E8 7F0895B8 10000027 */  b     .L7F089658
/* 0BE0EC 7F0895BC 00000000 */   nop
.L7F0895C0:
/* 0BE0F0 7F0895C0 0FC051D6 */  jal   get_scenario
/* 0BE0F4 7F0895C4 00000000 */   nop
/* 0BE0F8 7F0895C8 0FC26C54 */  jal   get_cur_playernum
/* 0BE0FC 7F0895CC AFA20040 */   sw    $v0, 0x40($sp)
/* 0BE100 7F0895D0 0FC26919 */  jal   getPlayerCount
/* 0BE104 7F0895D4 AFA2003C */   sw    $v0, 0x3c($sp)
/* 0BE108 7F0895D8 00402825 */  move  $a1, $v0
/* 0BE10C 7F0895DC 00002025 */  move  $a0, $zero
/* 0BE110 7F0895E0 1840000C */  blez  $v0, .L7F089614
/* 0BE114 7F0895E4 00001825 */   move  $v1, $zero
/* 0BE118 7F0895E8 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0BE11C 7F0895EC 3C0A8008 */  lui   $t2, %hi(g_playerPlayerData)
/* 0BE120 7F0895F0 254A9EF0 */  addiu $t2, %lo(g_playerPlayerData) # addiu $t2, $t2, -0x6110
/* 0BE124 7F0895F4 00084880 */  sll   $t1, $t0, 2
/* 0BE128 7F0895F8 012A1021 */  addu  $v0, $t1, $t2
.L7F0895FC:
/* 0BE12C 7F0895FC 8C4B0024 */  lw    $t3, 0x24($v0)
/* 0BE130 7F089600 24630001 */  addiu $v1, $v1, 1
/* 0BE134 7F089604 0065082A */  slt   $at, $v1, $a1
/* 0BE138 7F089608 24420070 */  addiu $v0, $v0, 0x70
/* 0BE13C 7F08960C 1420FFFB */  bnez  $at, .L7F0895FC
/* 0BE140 7F089610 008B2021 */   addu  $a0, $a0, $t3
.L7F089614:
/* 0BE144 7F089614 8FAC0040 */  lw    $t4, 0x40($sp)
/* 0BE148 7F089618 24010001 */  li    $at, 1
/* 0BE14C 7F08961C 15810003 */  bne   $t4, $at, .L7F08962C
/* 0BE150 7F089620 28810002 */   slti  $at, $a0, 2
/* 0BE154 7F089624 1020000C */  beqz  $at, .L7F089658
/* 0BE158 7F089628 00000000 */   nop
.L7F08962C:
/* 0BE15C 7F08962C 0FC26C54 */  jal   get_cur_playernum
/* 0BE160 7F089630 00000000 */   nop
/* 0BE164 7F089634 00022600 */  sll   $a0, $v0, 0x18
/* 0BE168 7F089638 00046E03 */  sra   $t5, $a0, 0x18
/* 0BE16C 7F08963C 01A02025 */  move  $a0, $t5
/* 0BE170 7F089640 0C0030C3 */  jal   joyGetButtons
/* 0BE174 7F089644 3405B000 */   li    $a1, 45056
/* 0BE178 7F089648 10400003 */  beqz  $v0, .L7F089658
/* 0BE17C 7F08964C 00000000 */   nop
/* 0BE180 7F089650 0FC2223A */  jal   mp_respawn_handler
/* 0BE184 7F089654 00000000 */   nop
.L7F089658:
/* 0BE188 7F089658 0FC22939 */  jal   bondviewIntroCameraTextTick
/* 0BE18C 7F08965C 00000000 */   nop
/* 0BE190 7F089660 0FC2297F */  jal   sub_GAME_7F08A5FC
/* 0BE194 7F089664 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BE198 7F089668 0FC22A7E */  jal   bondviewUpperTextWindowTimerTick
/* 0BE19C 7F08966C AFA20058 */   sw    $v0, 0x58($sp)
/* 0BE1A0 7F089670 0FC22ABA */  jal   sub_GAME_7F08AAE8
/* 0BE1A4 7F089674 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BE1A8 7F089678 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BE1AC 7F08967C 0FC1A979 */  jal   gunDrawSight
/* 0BE1B0 7F089680 27A40058 */   addiu $a0, $sp, 0x58
/* 0BE1B4 7F089684 0FC1A73D */  jal   generate_ammo_total_microcode
/* 0BE1B8 7F089688 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BE1BC 7F08968C AFA20058 */  sw    $v0, 0x58($sp)
/* 0BE1C0 7F089690 0FC15884 */  jal   countdownTimerRender
/* 0BE1C4 7F089694 00402025 */   move  $a0, $v0
/* 0BE1C8 7F089698 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BE1CC 7F08969C 0FC31824 */  jal   display_red_blue_on_radar
/* 0BE1D0 7F0896A0 00402025 */   move  $a0, $v0
/* 0BE1D4 7F0896A4 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BE1D8 7F0896A8 0FC20138 */  jal   currentPlayerDrawFade
/* 0BE1DC 7F0896AC 00402025 */   move  $a0, $v0
/* 0BE1E0 7F0896B0 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0896B4:
/* 0BE1E4 7F0896B4 27BD0058 */  addiu $sp, $sp, 0x58
/* 0BE1E8 7F0896B8 03E00008 */  jr    $ra
/* 0BE1EC 7F0896BC 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel maybe_mp_interface
/* 0BBD60 7F089370 3C0E8007 */  lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8007
/* 0BBD64 7F089374 8DCE8BC0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BBD68 7F089378 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0BBD6C 7F08937C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0BBD70 7F089380 AFA40058 */  sw    $a0, 0x58($sp)
/* 0BBD74 7F089384 8DCF0000 */  lw    $t7, ($t6)
/* 0BBD78 7F089388 24010001 */  li    $at, 1
/* 0BBD7C 7F08938C 15E10014 */  bne   $t7, $at, .L7F0893E0
/* 0BBD80 7F089390 00000000 */   nop   
/* 0BBD84 7F089394 0FC229C0 */  jal   bondviewIntroCameraTextTick
/* 0BBD88 7F089398 00000000 */   nop   
/* 0BBD8C 7F08939C 0FC22A06 */  jal   sub_GAME_7F08A5FC
/* 0BBD90 7F0893A0 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BBD94 7F0893A4 0FC22B10 */  jal   bondviewUpperTextWindowTimerTick
/* 0BBD98 7F0893A8 AFA20058 */   sw    $v0, 0x58($sp)
/* 0BBD9C 7F0893AC 0FC22B4C */  jal   sub_GAME_7F08AAE8
/* 0BBDA0 7F0893B0 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BBDA4 7F0893B4 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BBDA8 7F0893B8 0FC1593C */  jal   countdownTimerRender
/* 0BBDAC 7F0893BC 00402025 */   move  $a0, $v0
/* 0BBDB0 7F0893C0 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BBDB4 7F0893C4 0FC20161 */  jal   currentPlayerDrawFade
/* 0BBDB8 7F0893C8 00402025 */   move  $a0, $v0
/* 0BBDBC 7F0893CC AFA20058 */  sw    $v0, 0x58($sp)
/* 0BBDC0 7F0893D0 0FC22390 */  jal   sub_GAME_7F088CD8
/* 0BBDC4 7F0893D4 00402025 */   move  $a0, $v0
/* 0BBDC8 7F0893D8 10000110 */  b     .L7F08981C
/* 0BBDCC 7F0893DC 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0893E0:
/* 0BBDD0 7F0893E0 0FC18779 */  jal   bondwalkFireBothHands
/* 0BBDD4 7F0893E4 00000000 */   nop   
/* 0BBDD8 7F0893E8 0FC1A608 */  jal   sub_GAME_7F06908C
/* 0BBDDC 7F0893EC 27A40058 */   addiu $a0, $sp, 0x58
/* 0BBDE0 7F0893F0 0FC18C2A */  jal   sub_GAME_7F062BE4
/* 0BBDE4 7F0893F4 27A40058 */   addiu $a0, $sp, 0x58
/* 0BBDE8 7F0893F8 0FC21FF5 */  jal   sub_GAME_7F087E74
/* 0BBDEC 7F0893FC 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BBDF0 7F089400 3C188007 */  lui   $t8, %hi(g_CurrentPlayer) # $t8, 0x8007
/* 0BBDF4 7F089404 8F188BC0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0BBDF8 7F089408 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BBDFC 7F08940C 8F1929BC */  lw    $t9, 0x29bc($t8)
/* 0BBE00 7F089410 1320001F */  beqz  $t9, .L7F089490
/* 0BBE04 7F089414 00000000 */   nop   
/* 0BBE08 7F089418 0C000FD9 */  jal   viGetViewLeft
/* 0BBE0C 7F08941C 00000000 */   nop   
/* 0BBE10 7F089420 0C000FDD */  jal   viGetViewTop
/* 0BBE14 7F089424 AFA20054 */   sw    $v0, 0x54($sp)
/* 0BBE18 7F089428 0C000FD9 */  jal   viGetViewLeft
/* 0BBE1C 7F08942C AFA20050 */   sw    $v0, 0x50($sp)
/* 0BBE20 7F089430 0C000FBB */  jal   viGetViewWidth
/* 0BBE24 7F089434 A7A2002E */   sh    $v0, 0x2e($sp)
/* 0BBE28 7F089438 87A8002E */  lh    $t0, 0x2e($sp)
/* 0BBE2C 7F08943C 00484821 */  addu  $t1, $v0, $t0
/* 0BBE30 7F089440 0C000FDD */  jal   viGetViewTop
/* 0BBE34 7F089444 AFA9004C */   sw    $t1, 0x4c($sp)
/* 0BBE38 7F089448 0C000FBF */  jal   viGetViewHeight
/* 0BBE3C 7F08944C A7A2002E */   sh    $v0, 0x2e($sp)
/* 0BBE40 7F089450 87AA002E */  lh    $t2, 0x2e($sp)
/* 0BBE44 7F089454 8FA40058 */  lw    $a0, 0x58($sp)
/* 0BBE48 7F089458 004A5821 */  addu  $t3, $v0, $t2
/* 0BBE4C 7F08945C 0FC2B016 */  jal   microcode_constructor
/* 0BBE50 7F089460 AFAB0048 */   sw    $t3, 0x48($sp)
/* 0BBE54 7F089464 8FAC0048 */  lw    $t4, 0x48($sp)
/* 0BBE58 7F089468 240D00A0 */  li    $t5, 160
/* 0BBE5C 7F08946C AFA20058 */  sw    $v0, 0x58($sp)
/* 0BBE60 7F089470 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0BBE64 7F089474 00402025 */  move  $a0, $v0
/* 0BBE68 7F089478 8FA50054 */  lw    $a1, 0x54($sp)
/* 0BBE6C 7F08947C 8FA60050 */  lw    $a2, 0x50($sp)
/* 0BBE70 7F089480 8FA7004C */  lw    $a3, 0x4c($sp)
/* 0BBE74 7F089484 0FC2B0B5 */  jal   microcode_constructor_related_to_menus
/* 0BBE78 7F089488 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0BBE7C 7F08948C AFA20058 */  sw    $v0, 0x58($sp)
.L7F089490:
/* 0BBE80 7F089490 0FC2281C */  jal   bondviewGetIfCurrentPlayerHealthShowTime
/* 0BBE84 7F089494 00000000 */   nop   
/* 0BBE88 7F089498 10400009 */  beqz  $v0, .L7F0894C0
/* 0BBE8C 7F08949C 3C0E8007 */   lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8007
/* 0BBE90 7F0894A0 8DCE8BC0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BBE94 7F0894A4 8DCF01C8 */  lw    $t7, 0x1c8($t6)
/* 0BBE98 7F0894A8 15E00005 */  bnez  $t7, .L7F0894C0
/* 0BBE9C 7F0894AC 00000000 */   nop   
/* 0BBEA0 7F0894B0 0FC221E0 */  jal   sub_GAME_7F088618
/* 0BBEA4 7F0894B4 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BBEA8 7F0894B8 10000017 */  b     .L7F089518
/* 0BBEAC 7F0894BC AFA20058 */   sw    $v0, 0x58($sp)
.L7F0894C0:
/* 0BBEB0 7F0894C0 0FC31557 */  jal   sub_GAME_7F0C6048
/* 0BBEB4 7F0894C4 00000000 */   nop   
/* 0BBEB8 7F0894C8 10400013 */  beqz  $v0, .L7F089518
/* 0BBEBC 7F0894CC 00000000 */   nop   
/* 0BBEC0 7F0894D0 0FC221E0 */  jal   sub_GAME_7F088618
/* 0BBEC4 7F0894D4 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BBEC8 7F0894D8 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0BBECC 7F0894DC 8C638BC0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BBED0 7F0894E0 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BBED4 7F0894E4 3C188004 */  lui   $t8, %hi(g_ClockTimer) # $t8, 0x8004
/* 0BBED8 7F0894E8 8C6429F8 */  lw    $a0, 0x29f8($v1)
/* 0BBEDC 7F0894EC 18800007 */  blez  $a0, .L7F08950C
/* 0BBEE0 7F0894F0 00000000 */   nop   
/* 0BBEE4 7F0894F4 8F180FF4 */  lw    $t8, %lo(g_ClockTimer)($t8)
/* 0BBEE8 7F0894F8 0098C823 */  subu  $t9, $a0, $t8
/* 0BBEEC 7F0894FC AC7929F8 */  sw    $t9, 0x29f8($v1)
/* 0BBEF0 7F089500 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0BBEF4 7F089504 8C638BC0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BBEF8 7F089508 8C6429F8 */  lw    $a0, 0x29f8($v1)
.L7F08950C:
/* 0BBEFC 7F08950C 04810002 */  bgez  $a0, .L7F089518
/* 0BBF00 7F089510 00000000 */   nop   
/* 0BBF04 7F089514 AC6029F8 */  sw    $zero, 0x29f8($v1)
.L7F089518:
/* 0BBF08 7F089518 0FC26669 */  jal   getPlayerCount
/* 0BBF0C 7F08951C 00000000 */   nop   
/* 0BBF10 7F089520 24010001 */  li    $at, 1
/* 0BBF14 7F089524 14410003 */  bne   $v0, $at, .L7F089534
/* 0BBF18 7F089528 00000000 */   nop   
/* 0BBF1C 7F08952C 0FC15E0C */  jal   display_objective_status_text_on_status_change
/* 0BBF20 7F089530 00000000 */   nop   
.L7F089534:
/* 0BBF24 7F089534 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0BBF28 7F089538 8C638BC0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BBF2C 7F08953C 8C6200D8 */  lw    $v0, 0xd8($v1)
/* 0BBF30 7F089540 1040009F */  beqz  $v0, .L7F0897C0
/* 0BBF34 7F089544 00000000 */   nop   
/* 0BBF38 7F089548 8C680428 */  lw    $t0, 0x428($v1)
/* 0BBF3C 7F08954C 24010001 */  li    $at, 1
/* 0BBF40 7F089550 15000045 */  bnez  $t0, .L7F089668
/* 0BBF44 7F089554 00000000 */   nop   
/* 0BBF48 7F089558 14410004 */  bne   $v0, $at, .L7F08956C
/* 0BBF4C 7F08955C 00002025 */   move  $a0, $zero
/* 0BBF50 7F089560 24090002 */  li    $t1, 2
/* 0BBF54 7F089564 24040001 */  li    $a0, 1
/* 0BBF58 7F089568 AC6900D8 */  sw    $t1, 0xd8($v1)
.L7F08956C:
/* 0BBF5C 7F08956C 1080001F */  beqz  $a0, .L7F0895EC
/* 0BBF60 7F089570 3C0A8007 */   lui   $t2, %hi(g_CurrentPlayer) # $t2, 0x8007
/* 0BBF64 7F089574 0FC07039 */  jal   die_blood_image_routine
/* 0BBF68 7F089578 00002025 */   move  $a0, $zero
/* 0BBF6C 7F08957C 0FC26669 */  jal   getPlayerCount
/* 0BBF70 7F089580 00000000 */   nop   
/* 0BBF74 7F089584 24010001 */  li    $at, 1
/* 0BBF78 7F089588 14410013 */  bne   $v0, $at, .L7F0895D8
/* 0BBF7C 7F08958C 00000000 */   nop   
/* 0BBF80 7F089590 0FC3028E */  jal   musicStopSlot
/* 0BBF84 7F089594 2404FFFF */   li    $a0, -1
/* 0BBF88 7F089598 0FC3003F */  jal   set_missionstate
/* 0BBF8C 7F08959C 00002025 */   move  $a0, $zero
/* 0BBF90 7F0895A0 0FC3002C */  jal   sub_GAME_7F0C0BF0
/* 0BBF94 7F0895A4 00000000 */   nop   
/* 0BBF98 7F0895A8 0C001927 */  jal   musicTrack1ApplySeqpVol
/* 0BBF9C 7F0895AC 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0BBFA0 7F0895B0 3C018002 */  lui   $at, %hi(g_musicXTrack1Fade) # $at, 0x8002
/* 0BBFA4 7F0895B4 AC2021DC */  sw    $zero, %lo(g_musicXTrack1Fade)($at)
/* 0BBFA8 7F0895B8 0C001A09 */  jal   musicTrack2ApplySeqpVol
/* 0BBFAC 7F0895BC 00002025 */   move  $a0, $zero
/* 0BBFB0 7F0895C0 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0BBFB4 7F0895C4 AC2021E0 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0BBFB8 7F0895C8 0C0018B7 */  jal   musicTrack1Play
/* 0BBFBC 7F0895CC 2404001B */   li    $a0, 27
/* 0BBFC0 7F0895D0 10000003 */  b     .L7F0895E0
/* 0BBFC4 7F0895D4 00000000 */   nop   
.L7F0895D8:
/* 0BBFC8 7F0895D8 0FC3003F */  jal   set_missionstate
/* 0BBFCC 7F0895DC 24040006 */   li    $a0, 6
.L7F0895E0:
/* 0BBFD0 7F0895E0 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0BBFD4 7F0895E4 10000020 */  b     .L7F089668
/* 0BBFD8 7F0895E8 8C638BC0 */   lw    $v1, %lo(g_CurrentPlayer)($v1)
.L7F0895EC:
/* 0BBFDC 7F0895EC 8D4A8BC0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0BBFE0 7F0895F0 24040096 */  li    $a0, 150
/* 0BBFE4 7F0895F4 00002825 */  move  $a1, $zero
/* 0BBFE8 7F0895F8 8D4B0424 */  lw    $t3, 0x424($t2)
/* 0BBFEC 7F0895FC 00003025 */  move  $a2, $zero
/* 0BBFF0 7F089600 3C073F34 */  lui   $a3, (0x3F34B4B5 >> 16) # lui $a3, 0x3f34
/* 0BBFF4 7F089604 11600006 */  beqz  $t3, .L7F089620
/* 0BBFF8 7F089608 3C0C8004 */   lui   $t4, %hi(g_ClockTimer) # $t4, 0x8004
/* 0BBFFC 7F08960C 0FC20215 */  jal   currentPlayerSetFadeColour
/* 0BC000 7F089610 34E7B4B5 */   ori   $a3, (0x3F34B4B5 & 0xFFFF) # ori $a3, $a3, 0xb4b5
/* 0BC004 7F089614 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0BC008 7F089618 10000013 */  b     .L7F089668
/* 0BC00C 7F08961C 8C638BC0 */   lw    $v1, %lo(g_CurrentPlayer)($v1)
.L7F089620:
/* 0BC010 7F089620 8D8C0FF4 */  lw    $t4, %lo(g_ClockTimer)($t4)
/* 0BC014 7F089624 24040002 */  li    $a0, 2
/* 0BC018 7F089628 19800003 */  blez  $t4, .L7F089638
/* 0BC01C 7F08962C 00000000 */   nop   
/* 0BC020 7F089630 10000001 */  b     .L7F089638
/* 0BC024 7F089634 24040001 */   li    $a0, 1
.L7F089638:
/* 0BC028 7F089638 0FC07039 */  jal   die_blood_image_routine
/* 0BC02C 7F08963C 00000000 */   nop   
/* 0BC030 7F089640 10400004 */  beqz  $v0, .L7F089654
/* 0BC034 7F089644 3C0E8007 */   lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8007
/* 0BC038 7F089648 8DCE8BC0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BC03C 7F08964C 240D0001 */  li    $t5, 1
/* 0BC040 7F089650 ADCD0424 */  sw    $t5, 0x424($t6)
.L7F089654:
/* 0BC044 7F089654 0FC07134 */  jal   gameplayBloodOverlayDL
/* 0BC048 7F089658 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BC04C 7F08965C 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0BC050 7F089660 8C638BC0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BC054 7F089664 AFA20058 */  sw    $v0, 0x58($sp)
.L7F089668:
/* 0BC058 7F089668 0FC1BDD7 */  jal   objecthandlerGetModelField28
/* 0BC05C 7F08966C 24640598 */   addiu $a0, $v1, 0x598
/* 0BC060 7F089670 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0BC064 7F089674 8C848BC0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BC068 7F089678 E7A00024 */  swc1  $f0, 0x24($sp)
/* 0BC06C 7F08967C 0FC1BDD9 */  jal   sub_GAME_7F06F5C4
/* 0BC070 7F089680 24840598 */   addiu $a0, $a0, 0x598
/* 0BC074 7F089684 C7A40024 */  lwc1  $f4, 0x24($sp)
/* 0BC078 7F089688 3C038007 */  lui   $v1, %hi(g_CurrentPlayer) # $v1, 0x8007
/* 0BC07C 7F08968C 4604003E */  c.le.s $f0, $f4
/* 0BC080 7F089690 00000000 */  nop   
/* 0BC084 7F089694 4500004A */  bc1f  .L7F0897C0
/* 0BC088 7F089698 00000000 */   nop   
/* 0BC08C 7F08969C 8C638BC0 */  lw    $v1, %lo(g_CurrentPlayer)($v1)
/* 0BC090 7F0896A0 8C6F0424 */  lw    $t7, 0x424($v1)
/* 0BC094 7F0896A4 11E00046 */  beqz  $t7, .L7F0897C0
/* 0BC098 7F0896A8 00000000 */   nop   
/* 0BC09C 7F0896AC 8C780428 */  lw    $t8, 0x428($v1)
/* 0BC0A0 7F0896B0 24190001 */  li    $t9, 1
/* 0BC0A4 7F0896B4 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0BC0A8 7F0896B8 1700000E */  bnez  $t8, .L7F0896F4
/* 0BC0AC 7F0896BC 00002825 */   move  $a1, $zero
/* 0BC0B0 7F0896C0 44816000 */  mtc1  $at, $f12
/* 0BC0B4 7F0896C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BC0B8 7F0896C8 44813000 */  mtc1  $at, $f6
/* 0BC0BC 7F0896CC AC790428 */  sw    $t9, 0x428($v1)
/* 0BC0C0 7F0896D0 00003025 */  move  $a2, $zero
/* 0BC0C4 7F0896D4 00003825 */  move  $a3, $zero
/* 0BC0C8 7F0896D8 0FC20221 */  jal   currentPlayerAdjustFade
/* 0BC0CC 7F0896DC E7A60010 */   swc1  $f6, 0x10($sp)
/* 0BC0D0 7F0896E0 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 0BC0D4 7F0896E4 44816000 */  mtc1  $at, $f12
/* 0BC0D8 7F0896E8 44807000 */  mtc1  $zero, $f14
/* 0BC0DC 7F0896EC 0FC202AD */  jal   currentPlayerStartChrFade
/* 0BC0E0 7F0896F0 00000000 */   nop   
.L7F0896F4:
/* 0BC0E4 7F0896F4 0FC2024C */  jal   currentPlayerIsFadeComplete
/* 0BC0E8 7F0896F8 00000000 */   nop   
/* 0BC0EC 7F0896FC 10400030 */  beqz  $v0, .L7F0897C0
/* 0BC0F0 7F089700 00000000 */   nop   
/* 0BC0F4 7F089704 0FC26669 */  jal   getPlayerCount
/* 0BC0F8 7F089708 00000000 */   nop   
/* 0BC0FC 7F08970C 24010001 */  li    $at, 1
/* 0BC100 7F089710 14410005 */  bne   $v0, $at, .L7F089728
/* 0BC104 7F089714 00000000 */   nop   
/* 0BC108 7F089718 0FC1EA94 */  jal   set_camera_mode
/* 0BC10C 7F08971C 24040005 */   li    $a0, 5
/* 0BC110 7F089720 10000027 */  b     .L7F0897C0
/* 0BC114 7F089724 00000000 */   nop   
.L7F089728:
/* 0BC118 7F089728 0FC051B2 */  jal   get_scenario
/* 0BC11C 7F08972C 00000000 */   nop   
/* 0BC120 7F089730 0FC269A4 */  jal   get_cur_playernum
/* 0BC124 7F089734 AFA20040 */   sw    $v0, 0x40($sp)
/* 0BC128 7F089738 0FC26669 */  jal   getPlayerCount
/* 0BC12C 7F08973C AFA2003C */   sw    $v0, 0x3c($sp)
/* 0BC130 7F089740 00402825 */  move  $a1, $v0
/* 0BC134 7F089744 00002025 */  move  $a0, $zero
/* 0BC138 7F089748 1840000C */  blez  $v0, .L7F08977C
/* 0BC13C 7F08974C 00001825 */   move  $v1, $zero
/* 0BC140 7F089750 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0BC144 7F089754 3C0A8007 */  lui   $t2, %hi(g_playerPlayerData) # $t2, 0x8007
/* 0BC148 7F089758 254A8A00 */  addiu $t2, %lo(g_playerPlayerData) # addiu $t2, $t2, -0x7600
/* 0BC14C 7F08975C 00084880 */  sll   $t1, $t0, 2
/* 0BC150 7F089760 012A1021 */  addu  $v0, $t1, $t2
.L7F089764:
/* 0BC154 7F089764 8C4B0024 */  lw    $t3, 0x24($v0)
/* 0BC158 7F089768 24630001 */  addiu $v1, $v1, 1
/* 0BC15C 7F08976C 0065082A */  slt   $at, $v1, $a1
/* 0BC160 7F089770 24420070 */  addiu $v0, $v0, 0x70
/* 0BC164 7F089774 1420FFFB */  bnez  $at, .L7F089764
/* 0BC168 7F089778 008B2021 */   addu  $a0, $a0, $t3
.L7F08977C:
/* 0BC16C 7F08977C 8FAC0040 */  lw    $t4, 0x40($sp)
/* 0BC170 7F089780 24010001 */  li    $at, 1
/* 0BC174 7F089784 15810003 */  bne   $t4, $at, .L7F089794
/* 0BC178 7F089788 28810002 */   slti  $at, $a0, 2
/* 0BC17C 7F08978C 1020000C */  beqz  $at, .L7F0897C0
/* 0BC180 7F089790 00000000 */   nop   
.L7F089794:
/* 0BC184 7F089794 0FC269A4 */  jal   get_cur_playernum
/* 0BC188 7F089798 00000000 */   nop   
/* 0BC18C 7F08979C 00022600 */  sll   $a0, $v0, 0x18
/* 0BC190 7F0897A0 00046E03 */  sra   $t5, $a0, 0x18
/* 0BC194 7F0897A4 01A02025 */  move  $a0, $t5
/* 0BC198 7F0897A8 0C002C20 */  jal   joyGetButtons
/* 0BC19C 7F0897AC 3405B000 */   li    $a1, 45056
/* 0BC1A0 7F0897B0 10400003 */  beqz  $v0, .L7F0897C0
/* 0BC1A4 7F0897B4 00000000 */   nop   
/* 0BC1A8 7F0897B8 0FC22294 */  jal   mp_respawn_handler
/* 0BC1AC 7F0897BC 00000000 */   nop   
.L7F0897C0:
/* 0BC1B0 7F0897C0 0FC229C0 */  jal   bondviewIntroCameraTextTick
/* 0BC1B4 7F0897C4 00000000 */   nop   
/* 0BC1B8 7F0897C8 0FC22A06 */  jal   sub_GAME_7F08A5FC
/* 0BC1BC 7F0897CC 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BC1C0 7F0897D0 0FC22B10 */  jal   bondviewUpperTextWindowTimerTick
/* 0BC1C4 7F0897D4 AFA20058 */   sw    $v0, 0x58($sp)
/* 0BC1C8 7F0897D8 0FC22B4C */  jal   sub_GAME_7F08AAE8
/* 0BC1CC 7F0897DC 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BC1D0 7F0897E0 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BC1D4 7F0897E4 0FC1AB5E */  jal   gunDrawSight
/* 0BC1D8 7F0897E8 27A40058 */   addiu $a0, $sp, 0x58
/* 0BC1DC 7F0897EC 0FC1A922 */  jal   generate_ammo_total_microcode
/* 0BC1E0 7F0897F0 8FA40058 */   lw    $a0, 0x58($sp)
/* 0BC1E4 7F0897F4 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BC1E8 7F0897F8 0FC1593C */  jal   countdownTimerRender
/* 0BC1EC 7F0897FC 00402025 */   move  $a0, $v0
/* 0BC1F0 7F089800 AFA20058 */  sw    $v0, 0x58($sp)
/* 0BC1F4 7F089804 0FC31568 */  jal   display_red_blue_on_radar
/* 0BC1F8 7F089808 00402025 */   move  $a0, $v0
/* 0BC1FC 7F08980C AFA20058 */  sw    $v0, 0x58($sp)
/* 0BC200 7F089810 0FC20161 */  jal   currentPlayerDrawFade
/* 0BC204 7F089814 00402025 */   move  $a0, $v0
/* 0BC208 7F089818 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F08981C:
/* 0BC20C 7F08981C 27BD0058 */  addiu $sp, $sp, 0x58
/* 0BC210 7F089820 03E00008 */  jr    $ra
/* 0BC214 7F089824 00000000 */   nop   
)
#endif
#endif





/**
 * Address 0x7F0896C0.
 */
Gfx *write_stan_tiles_in_yellow(Gfx *gdl)
{
    if (dword_CODE_bss_80079DA0 != NULL)
    {
        gdl = sub_GAME_7F0B3024(gdl, dword_CODE_bss_80079DA0, 0xFF00FF80U);
    }

    if (dword_CODE_bss_80079DA4 != NULL)
    {
        gdl = sub_GAME_7F0B3024(gdl, dword_CODE_bss_80079DA4, 0xFF00FF80U);
    }

    return gdl;
}


void sub_GAME_7F089718(f32 arg0)
{
    f32 scalar;
    struct collision434* col;

    scalar = D_800364D0 / arg0;

    col = &g_CurrentPlayer->field_488;
    col->collision_position.x *= scalar;
    col->collision_position.z *= scalar;

    D_800364D0 = arg0;
    D_800364D4 = 1.0f / arg0;
}


void sub_GAME_7F08976C(f32 param_1) {
  D_800364CC = param_1;
}






/**
 * Address 0x7F089778.
 */
f32 bondviewGetPlayerStanHeight(struct player *player)
{
    return player->stanHeight;
}





/**
 * Address 0x7F089780.
 */
f32 bondviewGetPlayerDuckingHeightRelated(struct player *player)
{
    return player->field_29BC + player->field_88 + player->ducking_height_offset;
}





PropRecord* get_curplayer_positiondata(void) {
    return g_CurrentPlayer->prop;
}





/**
 * Address 0x7F0897A8.
 */
void bondviewKillCurrentPlayer(void)
{
    if ((g_CurrentPlayer->bondinvincible == 0) && (g_CurrentPlayer->bonddead == 0))
    {
        if (g_CurrentPlayer->watch_animation_state != 0)
        {
            trigger_solo_watch_menu(1);
        }

        g_isBondKIA = 1;
        g_CurrentPlayer->bonddead = 1;

        g_CurrentPlayer->previous_collision_info = g_CurrentPlayer->field_488;

        g_CurrentPlayer->thetadie = g_CurrentPlayer->vv_theta;
        g_CurrentPlayer->vertadie = g_CurrentPlayer->vv_verta;

        if (g_PlayerTankProp != NULL)
        {
            g_ExplodeTankOnDeathFlag = 1;
        }

        currentPlayerEquipWeaponWrapper(GUNLEFT, 0);
        currentPlayerEquipWeaponWrapper(GUNRIGHT, 0);

        if ((getMissiontimer() - g_CurrentPlayer->field_29F4) < g_playerPerm->shortest_inning)
        {
            g_playerPerm->shortest_inning = getMissiontimer() - g_CurrentPlayer->field_29F4;
        }

        g_CurrentPlayer->field_29F4 = getMissiontimer();
    }
}




/**
 * Unreferenced.
 * 
 * Address 0x7F0898E8.
 */
s32 sub_GAME_7F0898E8(void)
{
    return (s32) ((joyGetStickY(0) * 8) + 0x280) / 0xA0;
}






#ifdef NONMATCHING
void record_damage_kills(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel pi_800552B0
.word 0x40490fdb /*3.1415927*/
.text
glabel record_damage_kills
/* 0BE44C 7F08991C 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0BE450 7F089920 3C0E8008 */  lui   $t6, %hi(g_playerPerm)
/* 0BE454 7F089924 8DCEA0B4 */  lw    $t6, %lo(g_playerPerm)($t6)
/* 0BE458 7F089928 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0BE45C 7F08992C E7AE0044 */  swc1  $f14, 0x44($sp)
/* 0BE460 7F089930 AFA60048 */  sw    $a2, 0x48($sp)
/* 0BE464 7F089934 AFA7004C */  sw    $a3, 0x4c($sp)
/* 0BE468 7F089938 C5C4005C */  lwc1  $f4, 0x5c($t6)
/* 0BE46C 7F08993C 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer)
/* 0BE470 7F089940 8DEFA0B0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0BE474 7F089944 460C2182 */  mul.s $f6, $f4, $f12
/* 0BE478 7F089948 E7A6003C */  swc1  $f6, 0x3c($sp)
/* 0BE47C 7F08994C 8DF801C8 */  lw    $t8, 0x1c8($t7)
/* 0BE480 7F089950 13000013 */  beqz  $t8, .L7F0899A0
/* 0BE484 7F089954 00000000 */   nop
/* 0BE488 7F089958 0FC228BF */  jal   get_BONDdata_watch_armor
/* 0BE48C 7F08995C 00000000 */   nop
/* 0BE490 7F089960 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0BE494 7F089964 8C84A0B0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BE498 7F089968 44070000 */  mfc1  $a3, $f0
/* 0BE49C 7F08996C 2405002E */  li    $a1, 46
/* 0BE4A0 7F089970 24060001 */  li    $a2, 1
/* 0BE4A4 7F089974 0FC28BCC */  jal   sub_GAME_7F0A2F30
/* 0BE4A8 7F089978 248412B8 */   addiu $a0, $a0, 0x12b8
/* 0BE4AC 7F08997C 0FC228BB */  jal   bondviewGetCurrentPlayerHealth
/* 0BE4B0 7F089980 00000000 */   nop
/* 0BE4B4 7F089984 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0BE4B8 7F089988 8C84A0B0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BE4BC 7F08998C 44070000 */  mfc1  $a3, $f0
/* 0BE4C0 7F089990 2405002E */  li    $a1, 46
/* 0BE4C4 7F089994 2406FFFF */  li    $a2, -1
/* 0BE4C8 7F089998 0FC28BCC */  jal   sub_GAME_7F0A2F30
/* 0BE4CC 7F08999C 24841598 */   addiu $a0, $a0, 0x1598
.L7F0899A0:
/* 0BE4D0 7F0899A0 0FC26919 */  jal   getPlayerCount
/* 0BE4D4 7F0899A4 00000000 */   nop
/* 0BE4D8 7F0899A8 28410002 */  slti  $at, $v0, 2
/* 0BE4DC 7F0899AC 14200007 */  bnez  $at, .L7F0899CC
/* 0BE4E0 7F0899B0 3C198009 */   lui   $t9, %hi(g_stopPlayFlag)
/* 0BE4E4 7F0899B4 8F39C700 */  lw    $t9, %lo(g_stopPlayFlag)($t9)
/* 0BE4E8 7F0899B8 3C088009 */  lui   $t0, %hi(g_gameOverFlag)
/* 0BE4EC 7F0899BC 57200120 */  bnezl $t9, .L7F089E40
/* 0BE4F0 7F0899C0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BE4F4 7F0899C4 8D08C704 */  lw    $t0, %lo(g_gameOverFlag)($t0)
/* 0BE4F8 7F0899C8 1500011C */  bnez  $t0, .L7F089E3C
.L7F0899CC:
/* 0BE4FC 7F0899CC 3C098003 */   lui   $t1, %hi(in_tank_flag)
/* 0BE500 7F0899D0 8D296448 */  lw    $t1, %lo(in_tank_flag)($t1)
/* 0BE504 7F0899D4 24010001 */  li    $at, 1
/* 0BE508 7F0899D8 C7A8003C */  lwc1  $f8, 0x3c($sp)
/* 0BE50C 7F0899DC 15210006 */  bne   $t1, $at, .L7F0899F8
/* 0BE510 7F0899E0 3C028008 */   lui   $v0, %hi(g_CurrentPlayer)
/* 0BE514 7F0899E4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0BE518 7F0899E8 44815000 */  mtc1  $at, $f10
/* 0BE51C 7F0899EC 00000000 */  nop
/* 0BE520 7F0899F0 460A4402 */  mul.s $f16, $f8, $f10
/* 0BE524 7F0899F4 E7B0003C */  swc1  $f16, 0x3c($sp)
.L7F0899F8:
/* 0BE528 7F0899F8 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BE52C 7F0899FC 8C4A00D8 */  lw    $t2, 0xd8($v0)
/* 0BE530 7F089A00 15400016 */  bnez  $t2, .L7F089A5C
/* 0BE534 7F089A04 00000000 */   nop
/* 0BE538 7F089A08 904B12B6 */  lbu   $t3, 0x12b6($v0)
/* 0BE53C 7F089A0C 15600013 */  bnez  $t3, .L7F089A5C
/* 0BE540 7F089A10 00000000 */   nop
/* 0BE544 7F089A14 0FC26C54 */  jal   get_cur_playernum
/* 0BE548 7F089A18 00000000 */   nop
/* 0BE54C 7F089A1C 00402025 */  move  $a0, $v0
/* 0BE550 7F089A20 0C003215 */  jal   joyRumblePakStart
/* 0BE554 7F089A24 3C053E80 */   lui   $a1, 0x3e80
/* 0BE558 7F089A28 0FC29370 */  jal   cur_player_get_control_type
/* 0BE55C 7F089A2C 00000000 */   nop
/* 0BE560 7F089A30 28410004 */  slti  $at, $v0, 4
/* 0BE564 7F089A34 14200009 */  bnez  $at, .L7F089A5C
/* 0BE568 7F089A38 00000000 */   nop
/* 0BE56C 7F089A3C 0FC26C54 */  jal   get_cur_playernum
/* 0BE570 7F089A40 00000000 */   nop
/* 0BE574 7F089A44 0FC26919 */  jal   getPlayerCount
/* 0BE578 7F089A48 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0BE57C 7F089A4C 8FAC001C */  lw    $t4, 0x1c($sp)
/* 0BE580 7F089A50 3C053E80 */  lui   $a1, 0x3e80
/* 0BE584 7F089A54 0C003215 */  jal   joyRumblePakStart
/* 0BE588 7F089A58 004C2021 */   addu  $a0, $v0, $t4
.L7F089A5C:
/* 0BE58C 7F089A5C 0FC26919 */  jal   getPlayerCount
/* 0BE590 7F089A60 00000000 */   nop
/* 0BE594 7F089A64 28410002 */  slti  $at, $v0, 2
/* 0BE598 7F089A68 14200010 */  bnez  $at, .L7F089AAC
/* 0BE59C 7F089A6C 00000000 */   nop
/* 0BE5A0 7F089A70 0FC051D6 */  jal   get_scenario
/* 0BE5A4 7F089A74 00000000 */   nop
/* 0BE5A8 7F089A78 24010004 */  li    $at, 4
/* 0BE5AC 7F089A7C 1441000B */  bne   $v0, $at, .L7F089AAC
/* 0BE5B0 7F089A80 3C028008 */   lui   $v0, %hi(g_CurrentPlayer)
/* 0BE5B4 7F089A84 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BE5B8 7F089A88 C45200DC */  lwc1  $f18, 0xdc($v0)
/* 0BE5BC 7F089A8C C4442A3C */  lwc1  $f4, 0x2a3c($v0)
/* 0BE5C0 7F089A90 C44800E0 */  lwc1  $f8, 0xe0($v0)
/* 0BE5C4 7F089A94 C44A2A40 */  lwc1  $f10, 0x2a40($v0)
/* 0BE5C8 7F089A98 46049182 */  mul.s $f6, $f18, $f4
/* 0BE5CC 7F089A9C 00000000 */  nop
/* 0BE5D0 7F089AA0 460A4402 */  mul.s $f16, $f8, $f10
/* 0BE5D4 7F089AA4 46103480 */  add.s $f18, $f6, $f16
/* 0BE5D8 7F089AA8 E7B2003C */  swc1  $f18, 0x3c($sp)
.L7F089AAC:
/* 0BE5DC 7F089AAC 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE5E0 7F089AB0 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BE5E4 7F089AB4 904D12B6 */  lbu   $t5, 0x12b6($v0)
/* 0BE5E8 7F089AB8 55A000E1 */  bnezl $t5, .L7F089E40
/* 0BE5EC 7F089ABC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BE5F0 7F089AC0 8C4E00D8 */  lw    $t6, 0xd8($v0)
/* 0BE5F4 7F089AC4 3C0F8003 */  lui   $t7, %hi(g_PlayerInvincible)
/* 0BE5F8 7F089AC8 55C000DD */  bnezl $t6, .L7F089E40
/* 0BE5FC 7F089ACC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BE600 7F089AD0 8DEF64B4 */  lw    $t7, %lo(g_PlayerInvincible)($t7)
/* 0BE604 7F089AD4 55E000DA */  bnezl $t7, .L7F089E40
/* 0BE608 7F089AD8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BE60C 7F089ADC 8C5800F4 */  lw    $t8, 0xf4($v0)
/* 0BE610 7F089AE0 0702000B */  bltzl $t8, .L7F089B10
/* 0BE614 7F089AE4 8C4301C8 */   lw    $v1, 0x1c8($v0)
/* 0BE618 7F089AE8 0FC26919 */  jal   getPlayerCount
/* 0BE61C 7F089AEC 00000000 */   nop
/* 0BE620 7F089AF0 28410002 */  slti  $at, $v0, 2
/* 0BE624 7F089AF4 142000D1 */  bnez  $at, .L7F089E3C
/* 0BE628 7F089AF8 3C028008 */   lui   $v0, %hi(g_CurrentPlayer)
/* 0BE62C 7F089AFC 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BE630 7F089B00 8C5900F4 */  lw    $t9, 0xf4($v0)
/* 0BE634 7F089B04 572000CE */  bnezl $t9, .L7F089E40
/* 0BE638 7F089B08 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BE63C 7F089B0C 8C4301C8 */  lw    $v1, 0x1c8($v0)
.L7F089B10:
/* 0BE640 7F089B10 24010005 */  li    $at, 5
/* 0BE644 7F089B14 106100C9 */  beq   $v1, $at, .L7F089E3C
/* 0BE648 7F089B18 2401000C */   li    $at, 12
/* 0BE64C 7F089B1C 506100C8 */  beql  $v1, $at, .L7F089E40
/* 0BE650 7F089B20 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BE654 7F089B24 C44400DC */  lwc1  $f4, 0xdc($v0)
/* 0BE658 7F089B28 E44400E4 */  swc1  $f4, 0xe4($v0)
/* 0BE65C 7F089B2C 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE660 7F089B30 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BE664 7F089B34 C44800E0 */  lwc1  $f8, 0xe0($v0)
/* 0BE668 7F089B38 0FC26919 */  jal   getPlayerCount
/* 0BE66C 7F089B3C E44800E8 */   swc1  $f8, 0xe8($v0)
/* 0BE670 7F089B40 28410002 */  slti  $at, $v0, 2
/* 0BE674 7F089B44 54200035 */  bnezl $at, .L7F089C1C
/* 0BE678 7F089B48 8FA30050 */   lw    $v1, 0x50($sp)
/* 0BE67C 7F089B4C 0FC26C54 */  jal   get_cur_playernum
/* 0BE680 7F089B50 00000000 */   nop
/* 0BE684 7F089B54 AFA20038 */  sw    $v0, 0x38($sp)
/* 0BE688 7F089B58 C7AC0044 */  lwc1  $f12, 0x44($sp)
/* 0BE68C 7F089B5C 0FC16A8C */  jal   atan2f
/* 0BE690 7F089B60 C7AE0048 */   lwc1  $f14, 0x48($sp)
/* 0BE694 7F089B64 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 0BE698 7F089B68 44815000 */  mtc1  $at, $f10
/* 0BE69C 7F089B6C 3C018005 */  lui   $at, %hi(pi_800552B0)
/* 0BE6A0 7F089B70 C43052B0 */  lwc1  $f16, %lo(pi_800552B0)($at)
/* 0BE6A4 7F089B74 460A0182 */  mul.s $f6, $f0, $f10
/* 0BE6A8 7F089B78 8FA80038 */  lw    $t0, 0x38($sp)
/* 0BE6AC 7F089B7C 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0BE6B0 7F089B80 3C0A8008 */  lui   $t2, %hi(g_playerPointers)
/* 0BE6B4 7F089B84 00084880 */  sll   $t1, $t0, 2
/* 0BE6B8 7F089B88 44812000 */  mtc1  $at, $f4
/* 0BE6BC 7F089B8C 01495021 */  addu  $t2, $t2, $t1
/* 0BE6C0 7F089B90 46103483 */  div.s $f18, $f6, $f16
/* 0BE6C4 7F089B94 8D4A9EE0 */  lw    $t2, %lo(g_playerPointers)($t2)
/* 0BE6C8 7F089B98 44806000 */  mtc1  $zero, $f12
/* 0BE6CC 7F089B9C 8FAB004C */  lw    $t3, 0x4c($sp)
/* 0BE6D0 7F089BA0 C54A0148 */  lwc1  $f10, 0x148($t2)
/* 0BE6D4 7F089BA4 3C0142B4 */  li    $at, 0x42B40000 # 90.000000
/* 0BE6D8 7F089BA8 000B60C0 */  sll   $t4, $t3, 3
/* 0BE6DC 7F089BAC 3C0D8008 */  lui   $t5, %hi(g_playerPlayerData)
/* 0BE6E0 7F089BB0 018B6023 */  subu  $t4, $t4, $t3
/* 0BE6E4 7F089BB4 44813000 */  mtc1  $at, $f6
/* 0BE6E8 7F089BB8 000C6100 */  sll   $t4, $t4, 4
/* 0BE6EC 7F089BBC 25AD9EF0 */  addiu $t5, %lo(g_playerPlayerData) # addiu $t5, $t5, -0x6110
/* 0BE6F0 7F089BC0 3C014387 */  li    $at, 0x43870000 # 270.000000
/* 0BE6F4 7F089BC4 018D1021 */  addu  $v0, $t4, $t5
/* 0BE6F8 7F089BC8 46122201 */  sub.s $f8, $f4, $f18
/* 0BE6FC 7F089BCC 46085081 */  sub.s $f2, $f10, $f8
/* 0BE700 7F089BD0 460C103C */  c.lt.s $f2, $f12
/* 0BE704 7F089BD4 00000000 */  nop
/* 0BE708 7F089BD8 45020003 */  bc1fl .L7F089BE8
/* 0BE70C 7F089BDC 4606103C */   c.lt.s $f2, $f6
/* 0BE710 7F089BE0 46001087 */  neg.s $f2, $f2
/* 0BE714 7F089BE4 4606103C */  c.lt.s $f2, $f6
.L7F089BE8:
/* 0BE718 7F089BE8 00000000 */  nop
/* 0BE71C 7F089BEC 45030008 */  bc1tl .L7F089C10
/* 0BE720 7F089BF0 8C4E003C */   lw    $t6, 0x3c($v0)
/* 0BE724 7F089BF4 44818000 */  mtc1  $at, $f16
/* 0BE728 7F089BF8 00000000 */  nop
/* 0BE72C 7F089BFC 4602803C */  c.lt.s $f16, $f2
/* 0BE730 7F089C00 00000000 */  nop
/* 0BE734 7F089C04 45020005 */  bc1fl .L7F089C1C
/* 0BE738 7F089C08 8FA30050 */   lw    $v1, 0x50($sp)
/* 0BE73C 7F089C0C 8C4E003C */  lw    $t6, 0x3c($v0)
.L7F089C10:
/* 0BE740 7F089C10 25CF0001 */  addiu $t7, $t6, 1
/* 0BE744 7F089C14 AC4F003C */  sw    $t7, 0x3c($v0)
/* 0BE748 7F089C18 8FA30050 */  lw    $v1, 0x50($sp)
.L7F089C1C:
/* 0BE74C 7F089C1C 44806000 */  mtc1  $zero, $f12
/* 0BE750 7F089C20 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE754 7F089C24 10600010 */  beqz  $v1, .L7F089C68
/* 0BE758 7F089C28 00000000 */   nop
/* 0BE75C 7F089C2C 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BE760 7F089C30 C7B2003C */  lwc1  $f18, 0x3c($sp)
/* 0BE764 7F089C34 C44000E0 */  lwc1  $f0, 0xe0($v0)
/* 0BE768 7F089C38 C4422A40 */  lwc1  $f2, 0x2a40($v0)
/* 0BE76C 7F089C3C 46020102 */  mul.s $f4, $f0, $f2
/* 0BE770 7F089C40 4604903E */  c.le.s $f18, $f4
/* 0BE774 7F089C44 00000000 */  nop
/* 0BE778 7F089C48 45000007 */  bc1f  .L7F089C68
/* 0BE77C 7F089C4C 00000000 */   nop
/* 0BE780 7F089C50 46029283 */  div.s $f10, $f18, $f2
/* 0BE784 7F089C54 460A0201 */  sub.s $f8, $f0, $f10
/* 0BE788 7F089C58 E44800E0 */  swc1  $f8, 0xe0($v0)
/* 0BE78C 7F089C5C 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE790 7F089C60 1000005D */  b     .L7F089DD8
/* 0BE794 7F089C64 8C42A0B0 */   lw    $v0, %lo(g_CurrentPlayer)($v0)
.L7F089C68:
/* 0BE798 7F089C68 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE79C 7F089C6C 1060000F */  beqz  $v1, .L7F089CAC
/* 0BE7A0 7F089C70 8C42A0B0 */   lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BE7A4 7F089C74 C44600E0 */  lwc1  $f6, 0xe0($v0)
/* 0BE7A8 7F089C78 C4502A40 */  lwc1  $f16, 0x2a40($v0)
/* 0BE7AC 7F089C7C C7B2003C */  lwc1  $f18, 0x3c($sp)
/* 0BE7B0 7F089C80 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BE7B4 7F089C84 46103103 */  div.s $f4, $f6, $f16
/* 0BE7B8 7F089C88 3C188008 */  lui   $t8, %hi(g_CurrentPlayer)
/* 0BE7BC 7F089C8C 44814000 */  mtc1  $at, $f8
/* 0BE7C0 7F089C90 46049281 */  sub.s $f10, $f18, $f4
/* 0BE7C4 7F089C94 E7AA003C */  swc1  $f10, 0x3c($sp)
/* 0BE7C8 7F089C98 E44C00E0 */  swc1  $f12, 0xe0($v0)
/* 0BE7CC 7F089C9C 8F18A0B0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0BE7D0 7F089CA0 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE7D4 7F089CA4 E7082A40 */  swc1  $f8, 0x2a40($t8)
/* 0BE7D8 7F089CA8 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
.L7F089CAC:
/* 0BE7DC 7F089CAC C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 0BE7E0 7F089CB0 C4502A3C */  lwc1  $f16, 0x2a3c($v0)
/* 0BE7E4 7F089CB4 C44400DC */  lwc1  $f4, 0xdc($v0)
/* 0BE7E8 7F089CB8 46103483 */  div.s $f18, $f6, $f16
/* 0BE7EC 7F089CBC 46122281 */  sub.s $f10, $f4, $f18
/* 0BE7F0 7F089CC0 E44A00DC */  swc1  $f10, 0xdc($v0)
/* 0BE7F4 7F089CC4 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE7F8 7F089CC8 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BE7FC 7F089CCC C44800DC */  lwc1  $f8, 0xdc($v0)
/* 0BE800 7F089CD0 460C403E */  c.le.s $f8, $f12
/* 0BE804 7F089CD4 00000000 */  nop
/* 0BE808 7F089CD8 45020040 */  bc1fl .L7F089DDC
/* 0BE80C 7F089CDC 8C4B00F4 */   lw    $t3, 0xf4($v0)
/* 0BE810 7F089CE0 0FC26919 */  jal   getPlayerCount
/* 0BE814 7F089CE4 00000000 */   nop
/* 0BE818 7F089CE8 28410002 */  slti  $at, $v0, 2
/* 0BE81C 7F089CEC 14200036 */  bnez  $at, .L7F089DC8
/* 0BE820 7F089CF0 00000000 */   nop
/* 0BE824 7F089CF4 0FC26C54 */  jal   get_cur_playernum
/* 0BE828 7F089CF8 00000000 */   nop
/* 0BE82C 7F089CFC AFA2002C */  sw    $v0, 0x2c($sp)
/* 0BE830 7F089D00 0FC051D6 */  jal   get_scenario
/* 0BE834 7F089D04 AFA00028 */   sw    $zero, 0x28($sp)
/* 0BE838 7F089D08 24010003 */  li    $at, 3
/* 0BE83C 7F089D0C 54410007 */  bnel  $v0, $at, .L7F089D2C
/* 0BE840 7F089D10 8FA8002C */   lw    $t0, 0x2c($sp)
/* 0BE844 7F089D14 0FC233F0 */  jal   bondinvHasGoldenGun
/* 0BE848 7F089D18 00000000 */   nop
/* 0BE84C 7F089D1C 10400002 */  beqz  $v0, .L7F089D28
/* 0BE850 7F089D20 24190001 */   li    $t9, 1
/* 0BE854 7F089D24 AFB90028 */  sw    $t9, 0x28($sp)
.L7F089D28:
/* 0BE858 7F089D28 8FA8002C */  lw    $t0, 0x2c($sp)
.L7F089D2C:
/* 0BE85C 7F089D2C 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0BE860 7F089D30 11090005 */  beq   $t0, $t1, .L7F089D48
/* 0BE864 7F089D34 00000000 */   nop
/* 0BE868 7F089D38 0FC159DF */  jal   drop_inventory
/* 0BE86C 7F089D3C 00000000 */   nop
/* 0BE870 7F089D40 0FC1AA57 */  jal   increment_num_deaths
/* 0BE874 7F089D44 00000000 */   nop
.L7F089D48:
/* 0BE878 7F089D48 0FC26C43 */  jal   set_cur_player
/* 0BE87C 7F089D4C 8FA4004C */   lw    $a0, 0x4c($sp)
/* 0BE880 7F089D50 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0BE884 7F089D54 8FAB004C */  lw    $t3, 0x4c($sp)
/* 0BE888 7F089D58 154B0005 */  bne   $t2, $t3, .L7F089D70
/* 0BE88C 7F089D5C 00000000 */   nop
/* 0BE890 7F089D60 0FC1AA86 */  jal   increment_num_suicides_display_MP
/* 0BE894 7F089D64 00000000 */   nop
/* 0BE898 7F089D68 10000008 */  b     .L7F089D8C
/* 0BE89C 7F089D6C 00000000 */   nop
.L7F089D70:
/* 0BE8A0 7F089D70 0FC1A9E0 */  jal   increment_num_kills_display_text_in_MP
/* 0BE8A4 7F089D74 00000000 */   nop
/* 0BE8A8 7F089D78 8FAC0028 */  lw    $t4, 0x28($sp)
/* 0BE8AC 7F089D7C 11800003 */  beqz  $t4, .L7F089D8C
/* 0BE8B0 7F089D80 00000000 */   nop
/* 0BE8B4 7F089D84 0FC1AA4D */  jal   increment_num_times_killed_MwtGC
/* 0BE8B8 7F089D88 00000000 */   nop
.L7F089D8C:
/* 0BE8BC 7F089D8C 0FC26C43 */  jal   set_cur_player
/* 0BE8C0 7F089D90 8FA4002C */   lw    $a0, 0x2c($sp)
/* 0BE8C4 7F089D94 8FAD004C */  lw    $t5, 0x4c($sp)
/* 0BE8C8 7F089D98 8FAF002C */  lw    $t7, 0x2c($sp)
/* 0BE8CC 7F089D9C 3C088008 */  lui   $t0, %hi(g_playerPlayerData)
/* 0BE8D0 7F089DA0 000D70C0 */  sll   $t6, $t5, 3
/* 0BE8D4 7F089DA4 01CD7023 */  subu  $t6, $t6, $t5
/* 0BE8D8 7F089DA8 000E7100 */  sll   $t6, $t6, 4
/* 0BE8DC 7F089DAC 000FC080 */  sll   $t8, $t7, 2
/* 0BE8E0 7F089DB0 01D8C821 */  addu  $t9, $t6, $t8
/* 0BE8E4 7F089DB4 25089EF0 */  addiu $t0, %lo(g_playerPlayerData) # addiu $t0, $t0, -0x6110
/* 0BE8E8 7F089DB8 03281021 */  addu  $v0, $t9, $t0
/* 0BE8EC 7F089DBC 8C490024 */  lw    $t1, 0x24($v0)
/* 0BE8F0 7F089DC0 252A0001 */  addiu $t2, $t1, 1
/* 0BE8F4 7F089DC4 AC4A0024 */  sw    $t2, 0x24($v0)
.L7F089DC8:
/* 0BE8F8 7F089DC8 0FC225EA */  jal   bondviewKillCurrentPlayer
/* 0BE8FC 7F089DCC 00000000 */   nop
/* 0BE900 7F089DD0 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE904 7F089DD4 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
.L7F089DD8:
/* 0BE908 7F089DD8 8C4B00F4 */  lw    $t3, 0xf4($v0)
.L7F089DDC:
/* 0BE90C 7F089DDC C7A60044 */  lwc1  $f6, 0x44($sp)
/* 0BE910 7F089DE0 3C0C8008 */  lui   $t4, %hi(g_CurrentPlayer)
/* 0BE914 7F089DE4 0561000E */  bgez  $t3, .L7F089E20
/* 0BE918 7F089DE8 3C048006 */   lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0BE91C 7F089DEC 46063400 */  add.s $f16, $f6, $f6
/* 0BE920 7F089DF0 C4440180 */  lwc1  $f4, 0x180($v0)
/* 0BE924 7F089DF4 46102480 */  add.s $f18, $f4, $f16
/* 0BE928 7F089DF8 E4520180 */  swc1  $f18, 0x180($v0)
/* 0BE92C 7F089DFC C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 0BE930 7F089E00 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE934 7F089E04 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BE938 7F089E08 460A5200 */  add.s $f8, $f10, $f10
/* 0BE93C 7F089E0C C4460188 */  lwc1  $f6, 0x188($v0)
/* 0BE940 7F089E10 46083100 */  add.s $f4, $f6, $f8
/* 0BE944 7F089E14 E4440188 */  swc1  $f4, 0x188($v0)
/* 0BE948 7F089E18 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0BE94C 7F089E1C 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
.L7F089E20:
/* 0BE950 7F089E20 AC4000F4 */  sw    $zero, 0xf4($v0)
/* 0BE954 7F089E24 8D8CA0B0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0BE958 7F089E28 24050044 */  li    $a1, 68
/* 0BE95C 7F089E2C 00003025 */  move  $a2, $zero
/* 0BE960 7F089E30 AD8000F8 */  sw    $zero, 0xf8($t4)
/* 0BE964 7F089E34 0C002382 */  jal   sndPlaySfx
/* 0BE968 7F089E38 8C843720 */   lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
.L7F089E3C:
/* 0BE96C 7F089E3C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F089E40:
/* 0BE970 7F089E40 27BD0040 */  addiu $sp, $sp, 0x40
/* 0BE974 7F089E44 03E00008 */  jr    $ra
/* 0BE978 7F089E48 00000000 */   nop
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel pi_800552B0
.word 0x40490fdb /*3.1415927*/
.text
glabel record_damage_kills
/* 0BEB60 7F089FF0 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0BEB64 7F089FF4 3C0E8008 */  lui   $t6, %hi(g_playerPerm) # $t6, 0x8008
/* 0BEB68 7F089FF8 8DCEA124 */  lw    $t6, %lo(g_playerPerm)($t6)
/* 0BEB6C 7F089FFC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0BEB70 7F08A000 E7AE0044 */  swc1  $f14, 0x44($sp)
/* 0BEB74 7F08A004 AFA60048 */  sw    $a2, 0x48($sp)
/* 0BEB78 7F08A008 AFA7004C */  sw    $a3, 0x4c($sp)
/* 0BEB7C 7F08A00C C5C4005C */  lwc1  $f4, 0x5c($t6)
/* 0BEB80 7F08A010 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8008
/* 0BEB84 7F08A014 8DEFA120 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0BEB88 7F08A018 460C2182 */  mul.s $f6, $f4, $f12
/* 0BEB8C 7F08A01C E7A6003C */  swc1  $f6, 0x3c($sp)
/* 0BEB90 7F08A020 8DF801C8 */  lw    $t8, 0x1c8($t7)
/* 0BEB94 7F08A024 13000013 */  beqz  $t8, .Ljp7F08A074
/* 0BEB98 7F08A028 00000000 */   nop
/* 0BEB9C 7F08A02C 0FC22A8D */  jal   get_BONDdata_watch_armor
/* 0BEBA0 7F08A030 00000000 */   nop
/* 0BEBA4 7F08A034 3C048008 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8008
/* 0BEBA8 7F08A038 8C84A120 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BEBAC 7F08A03C 44070000 */  mfc1  $a3, $f0
/* 0BEBB0 7F08A040 2405002E */  li    $a1, 46
/* 0BEBB4 7F08A044 24060001 */  li    $a2, 1
/* 0BEBB8 7F08A048 0FC28EB4 */  jal   sub_GAME_7F0A2F30
/* 0BEBBC 7F08A04C 248412B8 */   addiu $a0, $a0, 0x12b8
/* 0BEBC0 7F08A050 0FC22A89 */  jal   bondviewGetCurrentPlayerHealth
/* 0BEBC4 7F08A054 00000000 */   nop
/* 0BEBC8 7F08A058 3C048008 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8008
/* 0BEBCC 7F08A05C 8C84A120 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BEBD0 7F08A060 44070000 */  mfc1  $a3, $f0
/* 0BEBD4 7F08A064 2405002E */  li    $a1, 46
/* 0BEBD8 7F08A068 2406FFFF */  li    $a2, -1
/* 0BEBDC 7F08A06C 0FC28EB4 */  jal   sub_GAME_7F0A2F30
/* 0BEBE0 7F08A070 24841598 */   addiu $a0, $a0, 0x1598
.Ljp7F08A074:
/* 0BEBE4 7F08A074 0FC26C01 */  jal   getPlayerCount
/* 0BEBE8 7F08A078 00000000 */   nop
/* 0BEBEC 7F08A07C 28410002 */  slti  $at, $v0, 2
/* 0BEBF0 7F08A080 14200007 */  bnez  $at, .Ljp7F08A0A0
/* 0BEBF4 7F08A084 3C198009 */   lui   $t9, %hi(g_stopPlayFlag) # $t9, 0x8009
/* 0BEBF8 7F08A088 8F39C770 */  lw    $t9, %lo(g_stopPlayFlag)($t9)
/* 0BEBFC 7F08A08C 3C088009 */  lui   $t0, %hi(g_gameOverFlag) # $t0, 0x8009
/* 0BEC00 7F08A090 5720012D */  bnezl $t9, .Ljp7F08A548
/* 0BEC04 7F08A094 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BEC08 7F08A098 8D08C774 */  lw    $t0, %lo(g_gameOverFlag)($t0)
/* 0BEC0C 7F08A09C 15000129 */  bnez  $t0, .Ljp7F08A544
.Ljp7F08A0A0:
/* 0BEC10 7F08A0A0 3C098003 */   lui   $t1, %hi(in_tank_flag) # $t1, 0x8003
/* 0BEC14 7F08A0A4 8D296488 */  lw    $t1, %lo(in_tank_flag)($t1)
/* 0BEC18 7F08A0A8 24010001 */  li    $at, 1
/* 0BEC1C 7F08A0AC C7A8003C */  lwc1  $f8, 0x3c($sp)
/* 0BEC20 7F08A0B0 15210006 */  bne   $t1, $at, .Ljp7F08A0CC
/* 0BEC24 7F08A0B4 3C028008 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BEC28 7F08A0B8 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0BEC2C 7F08A0BC 44815000 */  mtc1  $at, $f10
/* 0BEC30 7F08A0C0 00000000 */  nop
/* 0BEC34 7F08A0C4 460A4402 */  mul.s $f16, $f8, $f10
/* 0BEC38 7F08A0C8 E7B0003C */  swc1  $f16, 0x3c($sp)
.Ljp7F08A0CC:
/* 0BEC3C 7F08A0CC 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BEC40 7F08A0D0 8C4A00D8 */  lw    $t2, 0xd8($v0)
/* 0BEC44 7F08A0D4 15400016 */  bnez  $t2, .Ljp7F08A130
/* 0BEC48 7F08A0D8 00000000 */   nop
/* 0BEC4C 7F08A0DC 904B12B6 */  lbu   $t3, 0x12b6($v0)
/* 0BEC50 7F08A0E0 15600013 */  bnez  $t3, .Ljp7F08A130
/* 0BEC54 7F08A0E4 00000000 */   nop
/* 0BEC58 7F08A0E8 0FC26F3C */  jal   get_cur_playernum
/* 0BEC5C 7F08A0EC 00000000 */   nop
/* 0BEC60 7F08A0F0 00402025 */  move  $a0, $v0
/* 0BEC64 7F08A0F4 0C00322E */  jal   joyRumblePakStart
/* 0BEC68 7F08A0F8 3C053E80 */   lui   $a1, 0x3e80
/* 0BEC6C 7F08A0FC 0FC29658 */  jal   cur_player_get_control_type
/* 0BEC70 7F08A100 00000000 */   nop
/* 0BEC74 7F08A104 28410004 */  slti  $at, $v0, 4
/* 0BEC78 7F08A108 14200009 */  bnez  $at, .Ljp7F08A130
/* 0BEC7C 7F08A10C 00000000 */   nop
/* 0BEC80 7F08A110 0FC26F3C */  jal   get_cur_playernum
/* 0BEC84 7F08A114 00000000 */   nop
/* 0BEC88 7F08A118 0FC26C01 */  jal   getPlayerCount
/* 0BEC8C 7F08A11C AFA2001C */   sw    $v0, 0x1c($sp)
/* 0BEC90 7F08A120 8FAC001C */  lw    $t4, 0x1c($sp)
/* 0BEC94 7F08A124 3C053E80 */  lui   $a1, 0x3e80
/* 0BEC98 7F08A128 0C00322E */  jal   joyRumblePakStart
/* 0BEC9C 7F08A12C 004C2021 */   addu  $a0, $v0, $t4
.Ljp7F08A130:
/* 0BECA0 7F08A130 0FC26C01 */  jal   getPlayerCount
/* 0BECA4 7F08A134 00000000 */   nop
/* 0BECA8 7F08A138 28410002 */  slti  $at, $v0, 2
/* 0BECAC 7F08A13C 14200010 */  bnez  $at, .Ljp7F08A180
/* 0BECB0 7F08A140 00000000 */   nop
/* 0BECB4 7F08A144 0FC05202 */  jal   get_scenario
/* 0BECB8 7F08A148 00000000 */   nop
/* 0BECBC 7F08A14C 24010004 */  li    $at, 4
/* 0BECC0 7F08A150 1441000B */  bne   $v0, $at, .Ljp7F08A180
/* 0BECC4 7F08A154 3C028008 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BECC8 7F08A158 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BECCC 7F08A15C C45200DC */  lwc1  $f18, 0xdc($v0)
/* 0BECD0 7F08A160 C4442A3C */  lwc1  $f4, 0x2a3c($v0)
/* 0BECD4 7F08A164 C44800E0 */  lwc1  $f8, 0xe0($v0)
/* 0BECD8 7F08A168 C44A2A40 */  lwc1  $f10, 0x2a40($v0)
/* 0BECDC 7F08A16C 46049182 */  mul.s $f6, $f18, $f4
/* 0BECE0 7F08A170 00000000 */  nop
/* 0BECE4 7F08A174 460A4402 */  mul.s $f16, $f8, $f10
/* 0BECE8 7F08A178 46103480 */  add.s $f18, $f6, $f16
/* 0BECEC 7F08A17C E7B2003C */  swc1  $f18, 0x3c($sp)
.Ljp7F08A180:
/* 0BECF0 7F08A180 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BECF4 7F08A184 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BECF8 7F08A188 904D12B6 */  lbu   $t5, 0x12b6($v0)
/* 0BECFC 7F08A18C 55A000EE */  bnezl $t5, .Ljp7F08A548
/* 0BED00 7F08A190 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BED04 7F08A194 8C4E00D8 */  lw    $t6, 0xd8($v0)
/* 0BED08 7F08A198 3C0F8003 */  lui   $t7, %hi(g_PlayerInvincible) # $t7, 0x8003
/* 0BED0C 7F08A19C 55C000EA */  bnezl $t6, .Ljp7F08A548
/* 0BED10 7F08A1A0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BED14 7F08A1A4 8DEF64F4 */  lw    $t7, %lo(g_PlayerInvincible)($t7)
/* 0BED18 7F08A1A8 55E000E7 */  bnezl $t7, .Ljp7F08A548
/* 0BED1C 7F08A1AC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BED20 7F08A1B0 C44400F4 */  lwc1  $f4, 0xf4($v0)
/* 0BED24 7F08A1B4 44804000 */  mtc1  $zero, $f8
/* 0BED28 7F08A1B8 00000000 */  nop
/* 0BED2C 7F08A1BC 4608203C */  c.lt.s $f4, $f8
/* 0BED30 7F08A1C0 00000000 */  nop
/* 0BED34 7F08A1C4 4503000E */  bc1tl .Ljp7F08A200
/* 0BED38 7F08A1C8 8C4301C8 */   lw    $v1, 0x1c8($v0)
/* 0BED3C 7F08A1CC 0FC26C01 */  jal   getPlayerCount
/* 0BED40 7F08A1D0 00000000 */   nop
/* 0BED44 7F08A1D4 28410002 */  slti  $at, $v0, 2
/* 0BED48 7F08A1D8 142000DA */  bnez  $at, .Ljp7F08A544
/* 0BED4C 7F08A1DC 3C028008 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BED50 7F08A1E0 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BED54 7F08A1E4 44805000 */  mtc1  $zero, $f10
/* 0BED58 7F08A1E8 C44600F4 */  lwc1  $f6, 0xf4($v0)
/* 0BED5C 7F08A1EC 46065032 */  c.eq.s $f10, $f6
/* 0BED60 7F08A1F0 00000000 */  nop
/* 0BED64 7F08A1F4 450200D4 */  bc1fl .Ljp7F08A548
/* 0BED68 7F08A1F8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BED6C 7F08A1FC 8C4301C8 */  lw    $v1, 0x1c8($v0)
.Ljp7F08A200:
/* 0BED70 7F08A200 24010005 */  li    $at, 5
/* 0BED74 7F08A204 106100CF */  beq   $v1, $at, .Ljp7F08A544
/* 0BED78 7F08A208 2401000C */   li    $at, 12
/* 0BED7C 7F08A20C 506100CE */  beql  $v1, $at, .Ljp7F08A548
/* 0BED80 7F08A210 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BED84 7F08A214 C45000DC */  lwc1  $f16, 0xdc($v0)
/* 0BED88 7F08A218 E45000E4 */  swc1  $f16, 0xe4($v0)
/* 0BED8C 7F08A21C 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BED90 7F08A220 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BED94 7F08A224 C45200E0 */  lwc1  $f18, 0xe0($v0)
/* 0BED98 7F08A228 0FC26C01 */  jal   getPlayerCount
/* 0BED9C 7F08A22C E45200E8 */   swc1  $f18, 0xe8($v0)
/* 0BEDA0 7F08A230 28410002 */  slti  $at, $v0, 2
/* 0BEDA4 7F08A234 54200035 */  bnezl $at, .Ljp7F08A30C
/* 0BEDA8 7F08A238 8FA30050 */   lw    $v1, 0x50($sp)
/* 0BEDAC 7F08A23C 0FC26F3C */  jal   get_cur_playernum
/* 0BEDB0 7F08A240 00000000 */   nop
/* 0BEDB4 7F08A244 AFA20038 */  sw    $v0, 0x38($sp)
/* 0BEDB8 7F08A248 C7AC0044 */  lwc1  $f12, 0x44($sp)
/* 0BEDBC 7F08A24C 0FC16BD4 */  jal   atan2f
/* 0BEDC0 7F08A250 C7AE0048 */   lwc1  $f14, 0x48($sp)
/* 0BEDC4 7F08A254 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 0BEDC8 7F08A258 44812000 */  mtc1  $at, $f4
/* 0BEDCC 7F08A25C 3C018005 */  lui   $at, %hi(pi_800552B0) # $at, 0x8005
/* 0BEDD0 7F08A260 C42A52E0 */  lwc1  $f10, %lo(pi_800552B0)($at)
/* 0BEDD4 7F08A264 46040202 */  mul.s $f8, $f0, $f4
/* 0BEDD8 7F08A268 8FB80038 */  lw    $t8, 0x38($sp)
/* 0BEDDC 7F08A26C 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0BEDE0 7F08A270 3C088008 */  lui   $t0, %hi(g_playerPointers)
/* 0BEDE4 7F08A274 0018C880 */  sll   $t9, $t8, 2
/* 0BEDE8 7F08A278 44818000 */  mtc1  $at, $f16
/* 0BEDEC 7F08A27C 01194021 */  addu  $t0, $t0, $t9
/* 0BEDF0 7F08A280 460A4183 */  div.s $f6, $f8, $f10
/* 0BEDF4 7F08A284 8D089F50 */  lw    $t0, %lo(g_playerPointers)($t0)
/* 0BEDF8 7F08A288 44806000 */  mtc1  $zero, $f12
/* 0BEDFC 7F08A28C 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0BEE00 7F08A290 C5040148 */  lwc1  $f4, 0x148($t0)
/* 0BEE04 7F08A294 3C0142B4 */  li    $at, 0x42B40000 # 90.000000
/* 0BEE08 7F08A298 000950C0 */  sll   $t2, $t1, 3
/* 0BEE0C 7F08A29C 3C0B8008 */  lui   $t3, %hi(g_playerPlayerData) # $t3, 0x8008
/* 0BEE10 7F08A2A0 01495023 */  subu  $t2, $t2, $t1
/* 0BEE14 7F08A2A4 44814000 */  mtc1  $at, $f8
/* 0BEE18 7F08A2A8 000A5100 */  sll   $t2, $t2, 4
/* 0BEE1C 7F08A2AC 256B9F60 */  addiu $t3, %lo(g_playerPlayerData) # addiu $t3, $t3, -0x60a0
/* 0BEE20 7F08A2B0 3C014387 */  li    $at, 0x43870000 # 270.000000
/* 0BEE24 7F08A2B4 014B1021 */  addu  $v0, $t2, $t3
/* 0BEE28 7F08A2B8 46068481 */  sub.s $f18, $f16, $f6
/* 0BEE2C 7F08A2BC 46122081 */  sub.s $f2, $f4, $f18
/* 0BEE30 7F08A2C0 460C103C */  c.lt.s $f2, $f12
/* 0BEE34 7F08A2C4 00000000 */  nop
/* 0BEE38 7F08A2C8 45020003 */  bc1fl .Ljp7F08A2D8
/* 0BEE3C 7F08A2CC 4608103C */   c.lt.s $f2, $f8
/* 0BEE40 7F08A2D0 46001087 */  neg.s $f2, $f2
/* 0BEE44 7F08A2D4 4608103C */  c.lt.s $f2, $f8
.Ljp7F08A2D8:
/* 0BEE48 7F08A2D8 00000000 */  nop
/* 0BEE4C 7F08A2DC 45030008 */  bc1tl .Ljp7F08A300
/* 0BEE50 7F08A2E0 8C4C003C */   lw    $t4, 0x3c($v0)
/* 0BEE54 7F08A2E4 44815000 */  mtc1  $at, $f10
/* 0BEE58 7F08A2E8 00000000 */  nop
/* 0BEE5C 7F08A2EC 4602503C */  c.lt.s $f10, $f2
/* 0BEE60 7F08A2F0 00000000 */  nop
/* 0BEE64 7F08A2F4 45020005 */  bc1fl .Ljp7F08A30C
/* 0BEE68 7F08A2F8 8FA30050 */   lw    $v1, 0x50($sp)
/* 0BEE6C 7F08A2FC 8C4C003C */  lw    $t4, 0x3c($v0)
.Ljp7F08A300:
/* 0BEE70 7F08A300 258D0001 */  addiu $t5, $t4, 1
/* 0BEE74 7F08A304 AC4D003C */  sw    $t5, 0x3c($v0)
/* 0BEE78 7F08A308 8FA30050 */  lw    $v1, 0x50($sp)
.Ljp7F08A30C:
/* 0BEE7C 7F08A30C 44806000 */  mtc1  $zero, $f12
/* 0BEE80 7F08A310 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BEE84 7F08A314 10600010 */  beqz  $v1, .Ljp7F08A358
/* 0BEE88 7F08A318 00000000 */   nop
/* 0BEE8C 7F08A31C 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BEE90 7F08A320 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 0BEE94 7F08A324 C44000E0 */  lwc1  $f0, 0xe0($v0)
/* 0BEE98 7F08A328 C4422A40 */  lwc1  $f2, 0x2a40($v0)
/* 0BEE9C 7F08A32C 46020402 */  mul.s $f16, $f0, $f2
/* 0BEEA0 7F08A330 4610303E */  c.le.s $f6, $f16
/* 0BEEA4 7F08A334 00000000 */  nop
/* 0BEEA8 7F08A338 45000007 */  bc1f  .Ljp7F08A358
/* 0BEEAC 7F08A33C 00000000 */   nop
/* 0BEEB0 7F08A340 46023103 */  div.s $f4, $f6, $f2
/* 0BEEB4 7F08A344 46040481 */  sub.s $f18, $f0, $f4
/* 0BEEB8 7F08A348 E45200E0 */  swc1  $f18, 0xe0($v0)
/* 0BEEBC 7F08A34C 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BEEC0 7F08A350 1000005E */  b     .Ljp7F08A4CC
/* 0BEEC4 7F08A354 8C42A120 */   lw    $v0, %lo(g_CurrentPlayer)($v0)
.Ljp7F08A358:
/* 0BEEC8 7F08A358 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BEECC 7F08A35C 1060000F */  beqz  $v1, .Ljp7F08A39C
/* 0BEED0 7F08A360 8C42A120 */   lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BEED4 7F08A364 C44800E0 */  lwc1  $f8, 0xe0($v0)
/* 0BEED8 7F08A368 C44A2A40 */  lwc1  $f10, 0x2a40($v0)
/* 0BEEDC 7F08A36C C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 0BEEE0 7F08A370 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BEEE4 7F08A374 460A4403 */  div.s $f16, $f8, $f10
/* 0BEEE8 7F08A378 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8008
/* 0BEEEC 7F08A37C 44819000 */  mtc1  $at, $f18
/* 0BEEF0 7F08A380 46103101 */  sub.s $f4, $f6, $f16
/* 0BEEF4 7F08A384 E7A4003C */  swc1  $f4, 0x3c($sp)
/* 0BEEF8 7F08A388 E44C00E0 */  swc1  $f12, 0xe0($v0)
/* 0BEEFC 7F08A38C 8DCEA120 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BEF00 7F08A390 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BEF04 7F08A394 E5D22A40 */  swc1  $f18, 0x2a40($t6)
/* 0BEF08 7F08A398 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
.Ljp7F08A39C:
/* 0BEF0C 7F08A39C C7A8003C */  lwc1  $f8, 0x3c($sp)
/* 0BEF10 7F08A3A0 C44A2A3C */  lwc1  $f10, 0x2a3c($v0)
/* 0BEF14 7F08A3A4 C45000DC */  lwc1  $f16, 0xdc($v0)
/* 0BEF18 7F08A3A8 460A4183 */  div.s $f6, $f8, $f10
/* 0BEF1C 7F08A3AC 46068101 */  sub.s $f4, $f16, $f6
/* 0BEF20 7F08A3B0 E44400DC */  swc1  $f4, 0xdc($v0)
/* 0BEF24 7F08A3B4 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BEF28 7F08A3B8 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BEF2C 7F08A3BC C45200DC */  lwc1  $f18, 0xdc($v0)
/* 0BEF30 7F08A3C0 460C903E */  c.le.s $f18, $f12
/* 0BEF34 7F08A3C4 00000000 */  nop
/* 0BEF38 7F08A3C8 45020041 */  bc1fl .Ljp7F08A4D0
/* 0BEF3C 7F08A3CC C44800F4 */   lwc1  $f8, 0xf4($v0)
/* 0BEF40 7F08A3D0 0FC26C01 */  jal   getPlayerCount
/* 0BEF44 7F08A3D4 00000000 */   nop
/* 0BEF48 7F08A3D8 28410002 */  slti  $at, $v0, 2
/* 0BEF4C 7F08A3DC 14200036 */  bnez  $at, .Ljp7F08A4B8
/* 0BEF50 7F08A3E0 00000000 */   nop
/* 0BEF54 7F08A3E4 0FC26F3C */  jal   get_cur_playernum
/* 0BEF58 7F08A3E8 00000000 */   nop
/* 0BEF5C 7F08A3EC AFA2002C */  sw    $v0, 0x2c($sp)
/* 0BEF60 7F08A3F0 0FC05202 */  jal   get_scenario
/* 0BEF64 7F08A3F4 AFA00028 */   sw    $zero, 0x28($sp)
/* 0BEF68 7F08A3F8 24010003 */  li    $at, 3
/* 0BEF6C 7F08A3FC 14410006 */  bne   $v0, $at, .Ljp7F08A418
/* 0BEF70 7F08A400 00000000 */   nop
/* 0BEF74 7F08A404 0FC23649 */  jal   bondinvHasGoldenGun
/* 0BEF78 7F08A408 00000000 */   nop
/* 0BEF7C 7F08A40C 10400002 */  beqz  $v0, .Ljp7F08A418
/* 0BEF80 7F08A410 240F0001 */   li    $t7, 1
/* 0BEF84 7F08A414 AFAF0028 */  sw    $t7, 0x28($sp)
.Ljp7F08A418:
/* 0BEF88 7F08A418 0FC15B1E */  jal   drop_inventory
/* 0BEF8C 7F08A41C 00000000 */   nop
/* 0BEF90 7F08A420 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0BEF94 7F08A424 8FB9004C */  lw    $t9, 0x4c($sp)
/* 0BEF98 7F08A428 13190003 */  beq   $t8, $t9, .Ljp7F08A438
/* 0BEF9C 7F08A42C 00000000 */   nop
/* 0BEFA0 7F08A430 0FC1ABD2 */  jal   increment_num_deaths
/* 0BEFA4 7F08A434 00000000 */   nop
.Ljp7F08A438:
/* 0BEFA8 7F08A438 0FC26F2B */  jal   set_cur_player
/* 0BEFAC 7F08A43C 8FA4004C */   lw    $a0, 0x4c($sp)
/* 0BEFB0 7F08A440 8FA8002C */  lw    $t0, 0x2c($sp)
/* 0BEFB4 7F08A444 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0BEFB8 7F08A448 15090005 */  bne   $t0, $t1, .Ljp7F08A460
/* 0BEFBC 7F08A44C 00000000 */   nop
/* 0BEFC0 7F08A450 0FC1AC01 */  jal   increment_num_suicides_display_MP
/* 0BEFC4 7F08A454 00000000 */   nop
/* 0BEFC8 7F08A458 10000008 */  b     .Ljp7F08A47C
/* 0BEFCC 7F08A45C 00000000 */   nop
.Ljp7F08A460:
/* 0BEFD0 7F08A460 0FC1AB5B */  jal   increment_num_kills_display_text_in_MP
/* 0BEFD4 7F08A464 00000000 */   nop
/* 0BEFD8 7F08A468 8FAA0028 */  lw    $t2, 0x28($sp)
/* 0BEFDC 7F08A46C 11400003 */  beqz  $t2, .Ljp7F08A47C
/* 0BEFE0 7F08A470 00000000 */   nop
/* 0BEFE4 7F08A474 0FC1ABC8 */  jal   increment_num_times_killed_MwtGC
/* 0BEFE8 7F08A478 00000000 */   nop
.Ljp7F08A47C:
/* 0BEFEC 7F08A47C 0FC26F2B */  jal   set_cur_player
/* 0BEFF0 7F08A480 8FA4002C */   lw    $a0, 0x2c($sp)
/* 0BEFF4 7F08A484 8FAB004C */  lw    $t3, 0x4c($sp)
/* 0BEFF8 7F08A488 8FAD002C */  lw    $t5, 0x2c($sp)
/* 0BEFFC 7F08A48C 3C188008 */  lui   $t8, %hi(g_playerPlayerData) # $t8, 0x8008
/* 0BF000 7F08A490 000B60C0 */  sll   $t4, $t3, 3
/* 0BF004 7F08A494 018B6023 */  subu  $t4, $t4, $t3
/* 0BF008 7F08A498 000C6100 */  sll   $t4, $t4, 4
/* 0BF00C 7F08A49C 000D7080 */  sll   $t6, $t5, 2
/* 0BF010 7F08A4A0 018E7821 */  addu  $t7, $t4, $t6
/* 0BF014 7F08A4A4 27189F60 */  addiu $t8, %lo(g_playerPlayerData) # addiu $t8, $t8, -0x60a0
/* 0BF018 7F08A4A8 01F81021 */  addu  $v0, $t7, $t8
/* 0BF01C 7F08A4AC 8C590024 */  lw    $t9, 0x24($v0)
/* 0BF020 7F08A4B0 27280001 */  addiu $t0, $t9, 1
/* 0BF024 7F08A4B4 AC480024 */  sw    $t0, 0x24($v0)
.Ljp7F08A4B8:
/* 0BF028 7F08A4B8 0FC2279F */  jal   bondviewKillCurrentPlayer
/* 0BF02C 7F08A4BC 00000000 */   nop
/* 0BF030 7F08A4C0 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BF034 7F08A4C4 44806000 */  mtc1  $zero, $f12
/* 0BF038 7F08A4C8 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
.Ljp7F08A4CC:
/* 0BF03C 7F08A4CC C44800F4 */  lwc1  $f8, 0xf4($v0)
.Ljp7F08A4D0:
/* 0BF040 7F08A4D0 C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 0BF044 7F08A4D4 3C098008 */  lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8008
/* 0BF048 7F08A4D8 460C403C */  c.lt.s $f8, $f12
/* 0BF04C 7F08A4DC 00000000 */  nop
/* 0BF050 7F08A4E0 4502000F */  bc1fl .Ljp7F08A520
/* 0BF054 7F08A4E4 E44C00F4 */   swc1  $f12, 0xf4($v0)
/* 0BF058 7F08A4E8 460A5400 */  add.s $f16, $f10, $f10
/* 0BF05C 7F08A4EC C4460180 */  lwc1  $f6, 0x180($v0)
/* 0BF060 7F08A4F0 46103100 */  add.s $f4, $f6, $f16
/* 0BF064 7F08A4F4 E4440180 */  swc1  $f4, 0x180($v0)
/* 0BF068 7F08A4F8 C7B20048 */  lwc1  $f18, 0x48($sp)
/* 0BF06C 7F08A4FC 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BF070 7F08A500 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BF074 7F08A504 46129200 */  add.s $f8, $f18, $f18
/* 0BF078 7F08A508 C44A0188 */  lwc1  $f10, 0x188($v0)
/* 0BF07C 7F08A50C 46085180 */  add.s $f6, $f10, $f8
/* 0BF080 7F08A510 E4460188 */  swc1  $f6, 0x188($v0)
/* 0BF084 7F08A514 3C028008 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0BF088 7F08A518 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BF08C 7F08A51C E44C00F4 */  swc1  $f12, 0xf4($v0)
.Ljp7F08A520:
/* 0BF090 7F08A520 8D29A120 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0BF094 7F08A524 0FC3021B */  jal   lvlGetControlsLockedFlag
/* 0BF098 7F08A528 E52C00F8 */   swc1  $f12, 0xf8($t1)
/* 0BF09C 7F08A52C 14400005 */  bnez  $v0, .Ljp7F08A544
/* 0BF0A0 7F08A530 3C048006 */   lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8006
/* 0BF0A4 7F08A534 8C843760 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0BF0A8 7F08A538 24050044 */  li    $a1, 68
/* 0BF0AC 7F08A53C 0C002386 */  jal   sndPlaySfx
/* 0BF0B0 7F08A540 00003025 */   move  $a2, $zero
.Ljp7F08A544:
/* 0BF0B4 7F08A544 8FBF0014 */  lw    $ra, 0x14($sp)
.Ljp7F08A548:
/* 0BF0B8 7F08A548 27BD0040 */  addiu $sp, $sp, 0x40
/* 0BF0BC 7F08A54C 03E00008 */  jr    $ra
/* 0BF0C0 7F08A550 00000000 */   nop
)
#endif

#if defined(VERSION_EU)
GLOBAL_ASM(
.late_rodata
glabel pi_800552B0
.word 0x40490fdb /*3.1415927*/
.text
glabel record_damage_kills
/* 0BC474 7F089A84 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0BC478 7F089A88 3C0E8007 */  lui   $t6, %hi(g_playerPerm) # $t6, 0x8007
/* 0BC47C 7F089A8C 8DCE8BC4 */  lw    $t6, %lo(g_playerPerm)($t6)
/* 0BC480 7F089A90 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0BC484 7F089A94 E7AE0044 */  swc1  $f14, 0x44($sp)
/* 0BC488 7F089A98 AFA60048 */  sw    $a2, 0x48($sp)
/* 0BC48C 7F089A9C AFA7004C */  sw    $a3, 0x4c($sp)
/* 0BC490 7F089AA0 C5C4005C */  lwc1  $f4, 0x5c($t6)
/* 0BC494 7F089AA4 3C0F8007 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8007
/* 0BC498 7F089AA8 8DEF8BC0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0BC49C 7F089AAC 460C2182 */  mul.s $f6, $f4, $f12
/* 0BC4A0 7F089AB0 E7A6003C */  swc1  $f6, 0x3c($sp)
/* 0BC4A4 7F089AB4 8DF801C8 */  lw    $t8, 0x1c8($t7)
/* 0BC4A8 7F089AB8 13000013 */  beqz  $t8, .L7F089B08
/* 0BC4AC 7F089ABC 00000000 */   nop   
/* 0BC4B0 7F089AC0 0FC22932 */  jal   get_BONDdata_watch_armor
/* 0BC4B4 7F089AC4 00000000 */   nop   
/* 0BC4B8 7F089AC8 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0BC4BC 7F089ACC 8C848BC0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BC4C0 7F089AD0 44070000 */  mfc1  $a3, $f0
/* 0BC4C4 7F089AD4 2405002E */  li    $a1, 46
/* 0BC4C8 7F089AD8 24060001 */  li    $a2, 1
/* 0BC4CC 7F089ADC 0FC2891C */  jal   sub_GAME_7F0A2F30
/* 0BC4D0 7F089AE0 248412B0 */   addiu $a0, $a0, 0x12b0
/* 0BC4D4 7F089AE4 0FC2292E */  jal   bondviewGetCurrentPlayerHealth
/* 0BC4D8 7F089AE8 00000000 */   nop   
/* 0BC4DC 7F089AEC 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0BC4E0 7F089AF0 8C848BC0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 0BC4E4 7F089AF4 44070000 */  mfc1  $a3, $f0
/* 0BC4E8 7F089AF8 2405002E */  li    $a1, 46
/* 0BC4EC 7F089AFC 2406FFFF */  li    $a2, -1
/* 0BC4F0 7F089B00 0FC2891C */  jal   sub_GAME_7F0A2F30
/* 0BC4F4 7F089B04 24841590 */   addiu $a0, $a0, 0x1590
.L7F089B08:
/* 0BC4F8 7F089B08 0FC26669 */  jal   getPlayerCount
/* 0BC4FC 7F089B0C 00000000 */   nop   
/* 0BC500 7F089B10 28410002 */  slti  $at, $v0, 2
/* 0BC504 7F089B14 14200007 */  bnez  $at, .L7F089B34
/* 0BC508 7F089B18 3C198007 */   lui   $t9, %hi(g_stopPlayFlag) # $t9, 0x8007
/* 0BC50C 7F089B1C 8F393AE0 */  lw    $t9, %lo(g_stopPlayFlag)($t9)
/* 0BC510 7F089B20 3C088007 */  lui   $t0, %hi(g_gameOverFlag) # $t0, 0x8007
/* 0BC514 7F089B24 5720012D */  bnezl $t9, .L7F089FDC
/* 0BC518 7F089B28 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BC51C 7F089B2C 8D083AE4 */  lw    $t0, %lo(g_gameOverFlag)($t0)
/* 0BC520 7F089B30 15000129 */  bnez  $t0, .L7F089FD8
.L7F089B34:
/* 0BC524 7F089B34 3C098003 */   lui   $t1, %hi(in_tank_flag) # $t1, 0x8003
/* 0BC528 7F089B38 8D291998 */  lw    $t1, %lo(in_tank_flag)($t1)
/* 0BC52C 7F089B3C 24010001 */  li    $at, 1
/* 0BC530 7F089B40 C7A8003C */  lwc1  $f8, 0x3c($sp)
/* 0BC534 7F089B44 15210006 */  bne   $t1, $at, .L7F089B60
/* 0BC538 7F089B48 3C028007 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC53C 7F089B4C 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0BC540 7F089B50 44815000 */  mtc1  $at, $f10
/* 0BC544 7F089B54 00000000 */  nop   
/* 0BC548 7F089B58 460A4402 */  mul.s $f16, $f8, $f10
/* 0BC54C 7F089B5C E7B0003C */  swc1  $f16, 0x3c($sp)
.L7F089B60:
/* 0BC550 7F089B60 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC554 7F089B64 8C4A00D8 */  lw    $t2, 0xd8($v0)
/* 0BC558 7F089B68 15400016 */  bnez  $t2, .L7F089BC4
/* 0BC55C 7F089B6C 00000000 */   nop   
/* 0BC560 7F089B70 904B12AE */  lbu   $t3, 0x12ae($v0)
/* 0BC564 7F089B74 15600013 */  bnez  $t3, .L7F089BC4
/* 0BC568 7F089B78 00000000 */   nop   
/* 0BC56C 7F089B7C 0FC269A4 */  jal   get_cur_playernum
/* 0BC570 7F089B80 00000000 */   nop   
/* 0BC574 7F089B84 00402025 */  move  $a0, $v0
/* 0BC578 7F089B88 0C002D72 */  jal   joyRumblePakStart
/* 0BC57C 7F089B8C 3C053E80 */   lui   $a1, 0x3e80
/* 0BC580 7F089B90 0FC29038 */  jal   cur_player_get_control_type
/* 0BC584 7F089B94 00000000 */   nop   
/* 0BC588 7F089B98 28410004 */  slti  $at, $v0, 4
/* 0BC58C 7F089B9C 14200009 */  bnez  $at, .L7F089BC4
/* 0BC590 7F089BA0 00000000 */   nop   
/* 0BC594 7F089BA4 0FC269A4 */  jal   get_cur_playernum
/* 0BC598 7F089BA8 00000000 */   nop   
/* 0BC59C 7F089BAC 0FC26669 */  jal   getPlayerCount
/* 0BC5A0 7F089BB0 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0BC5A4 7F089BB4 8FAC001C */  lw    $t4, 0x1c($sp)
/* 0BC5A8 7F089BB8 3C053E80 */  lui   $a1, 0x3e80
/* 0BC5AC 7F089BBC 0C002D72 */  jal   joyRumblePakStart
/* 0BC5B0 7F089BC0 004C2021 */   addu  $a0, $v0, $t4
.L7F089BC4:
/* 0BC5B4 7F089BC4 0FC26669 */  jal   getPlayerCount
/* 0BC5B8 7F089BC8 00000000 */   nop   
/* 0BC5BC 7F089BCC 28410002 */  slti  $at, $v0, 2
/* 0BC5C0 7F089BD0 14200010 */  bnez  $at, .L7F089C14
/* 0BC5C4 7F089BD4 00000000 */   nop   
/* 0BC5C8 7F089BD8 0FC051B2 */  jal   get_scenario
/* 0BC5CC 7F089BDC 00000000 */   nop   
/* 0BC5D0 7F089BE0 24010004 */  li    $at, 4
/* 0BC5D4 7F089BE4 1441000B */  bne   $v0, $at, .L7F089C14
/* 0BC5D8 7F089BE8 3C028007 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC5DC 7F089BEC 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC5E0 7F089BF0 C45200DC */  lwc1  $f18, 0xdc($v0)
/* 0BC5E4 7F089BF4 C4442A34 */  lwc1  $f4, 0x2a34($v0)
/* 0BC5E8 7F089BF8 C44800E0 */  lwc1  $f8, 0xe0($v0)
/* 0BC5EC 7F089BFC C44A2A38 */  lwc1  $f10, 0x2a38($v0)
/* 0BC5F0 7F089C00 46049182 */  mul.s $f6, $f18, $f4
/* 0BC5F4 7F089C04 00000000 */  nop   
/* 0BC5F8 7F089C08 460A4402 */  mul.s $f16, $f8, $f10
/* 0BC5FC 7F089C0C 46103480 */  add.s $f18, $f6, $f16
/* 0BC600 7F089C10 E7B2003C */  swc1  $f18, 0x3c($sp)
.L7F089C14:
/* 0BC604 7F089C14 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC608 7F089C18 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC60C 7F089C1C 904D12AE */  lbu   $t5, 0x12ae($v0)
/* 0BC610 7F089C20 55A000EE */  bnezl $t5, .L7F089FDC
/* 0BC614 7F089C24 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BC618 7F089C28 8C4E00D8 */  lw    $t6, 0xd8($v0)
/* 0BC61C 7F089C2C 3C0F8003 */  lui   $t7, %hi(g_PlayerInvincible) # $t7, 0x8003
/* 0BC620 7F089C30 55C000EA */  bnezl $t6, .L7F089FDC
/* 0BC624 7F089C34 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BC628 7F089C38 8DEF1A04 */  lw    $t7, %lo(g_PlayerInvincible)($t7)
/* 0BC62C 7F089C3C 55E000E7 */  bnezl $t7, .L7F089FDC
/* 0BC630 7F089C40 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BC634 7F089C44 C44400F4 */  lwc1  $f4, 0xf4($v0)
/* 0BC638 7F089C48 44804000 */  mtc1  $zero, $f8
/* 0BC63C 7F089C4C 00000000 */  nop   
/* 0BC640 7F089C50 4608203C */  c.lt.s $f4, $f8
/* 0BC644 7F089C54 00000000 */  nop   
/* 0BC648 7F089C58 4503000E */  bc1tl .L7F089C94
/* 0BC64C 7F089C5C 8C4301C8 */   lw    $v1, 0x1c8($v0)
/* 0BC650 7F089C60 0FC26669 */  jal   getPlayerCount
/* 0BC654 7F089C64 00000000 */   nop   
/* 0BC658 7F089C68 28410002 */  slti  $at, $v0, 2
/* 0BC65C 7F089C6C 142000DA */  bnez  $at, .L7F089FD8
/* 0BC660 7F089C70 3C028007 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC664 7F089C74 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC668 7F089C78 44805000 */  mtc1  $zero, $f10
/* 0BC66C 7F089C7C C44600F4 */  lwc1  $f6, 0xf4($v0)
/* 0BC670 7F089C80 46065032 */  c.eq.s $f10, $f6
/* 0BC674 7F089C84 00000000 */  nop   
/* 0BC678 7F089C88 450200D4 */  bc1fl .L7F089FDC
/* 0BC67C 7F089C8C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BC680 7F089C90 8C4301C8 */  lw    $v1, 0x1c8($v0)
.L7F089C94:
/* 0BC684 7F089C94 24010005 */  li    $at, 5
/* 0BC688 7F089C98 106100CF */  beq   $v1, $at, .L7F089FD8
/* 0BC68C 7F089C9C 2401000C */   li    $at, 12
/* 0BC690 7F089CA0 506100CE */  beql  $v1, $at, .L7F089FDC
/* 0BC694 7F089CA4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0BC698 7F089CA8 C45000DC */  lwc1  $f16, 0xdc($v0)
/* 0BC69C 7F089CAC E45000E4 */  swc1  $f16, 0xe4($v0)
/* 0BC6A0 7F089CB0 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC6A4 7F089CB4 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC6A8 7F089CB8 C45200E0 */  lwc1  $f18, 0xe0($v0)
/* 0BC6AC 7F089CBC 0FC26669 */  jal   getPlayerCount
/* 0BC6B0 7F089CC0 E45200E8 */   swc1  $f18, 0xe8($v0)
/* 0BC6B4 7F089CC4 28410002 */  slti  $at, $v0, 2
/* 0BC6B8 7F089CC8 54200035 */  bnezl $at, .L7F089DA0
/* 0BC6BC 7F089CCC 8FA30050 */   lw    $v1, 0x50($sp)
/* 0BC6C0 7F089CD0 0FC269A4 */  jal   get_cur_playernum
/* 0BC6C4 7F089CD4 00000000 */   nop   
/* 0BC6C8 7F089CD8 AFA20038 */  sw    $v0, 0x38($sp)
/* 0BC6CC 7F089CDC C7AC0044 */  lwc1  $f12, 0x44($sp)
/* 0BC6D0 7F089CE0 0FC16BB8 */  jal   atan2f
/* 0BC6D4 7F089CE4 C7AE0048 */   lwc1  $f14, 0x48($sp)
/* 0BC6D8 7F089CE8 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 0BC6DC 7F089CEC 44812000 */  mtc1  $at, $f4
/* 0BC6E0 7F089CF0 3C018005 */  lui   $at, %hi(pi_800552B0) # $at, 0x8005
/* 0BC6E4 7F089CF4 C42AAE84 */  lwc1  $f10, %lo(pi_800552B0)($at)
/* 0BC6E8 7F089CF8 46040202 */  mul.s $f8, $f0, $f4
/* 0BC6EC 7F089CFC 8FB80038 */  lw    $t8, 0x38($sp)
/* 0BC6F0 7F089D00 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0BC6F4 7F089D04 3C088007 */  lui   $t0, 0x8007
/* 0BC6F8 7F089D08 0018C880 */  sll   $t9, $t8, 2
/* 0BC6FC 7F089D0C 44818000 */  mtc1  $at, $f16
/* 0BC700 7F089D10 01194021 */  addu  $t0, $t0, $t9
/* 0BC704 7F089D14 460A4183 */  div.s $f6, $f8, $f10
/* 0BC708 7F089D18 8D0889F0 */  lw    $t0, -0x7610($t0)
/* 0BC70C 7F089D1C 44806000 */  mtc1  $zero, $f12
/* 0BC710 7F089D20 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0BC714 7F089D24 C5040148 */  lwc1  $f4, 0x148($t0)
/* 0BC718 7F089D28 3C0142B4 */  li    $at, 0x42B40000 # 90.000000
/* 0BC71C 7F089D2C 000950C0 */  sll   $t2, $t1, 3
/* 0BC720 7F089D30 3C0B8007 */  lui   $t3, %hi(g_playerPlayerData) # $t3, 0x8007
/* 0BC724 7F089D34 01495023 */  subu  $t2, $t2, $t1
/* 0BC728 7F089D38 44814000 */  mtc1  $at, $f8
/* 0BC72C 7F089D3C 000A5100 */  sll   $t2, $t2, 4
/* 0BC730 7F089D40 256B8A00 */  addiu $t3, %lo(g_playerPlayerData) # addiu $t3, $t3, -0x7600
/* 0BC734 7F089D44 3C014387 */  li    $at, 0x43870000 # 270.000000
/* 0BC738 7F089D48 014B1021 */  addu  $v0, $t2, $t3
/* 0BC73C 7F089D4C 46068481 */  sub.s $f18, $f16, $f6
/* 0BC740 7F089D50 46122081 */  sub.s $f2, $f4, $f18
/* 0BC744 7F089D54 460C103C */  c.lt.s $f2, $f12
/* 0BC748 7F089D58 00000000 */  nop   
/* 0BC74C 7F089D5C 45020003 */  bc1fl .L7F089D6C
/* 0BC750 7F089D60 4608103C */   c.lt.s $f2, $f8
/* 0BC754 7F089D64 46001087 */  neg.s $f2, $f2
/* 0BC758 7F089D68 4608103C */  c.lt.s $f2, $f8
.L7F089D6C:
/* 0BC75C 7F089D6C 00000000 */  nop   
/* 0BC760 7F089D70 45030008 */  bc1tl .L7F089D94
/* 0BC764 7F089D74 8C4C003C */   lw    $t4, 0x3c($v0)
/* 0BC768 7F089D78 44815000 */  mtc1  $at, $f10
/* 0BC76C 7F089D7C 00000000 */  nop   
/* 0BC770 7F089D80 4602503C */  c.lt.s $f10, $f2
/* 0BC774 7F089D84 00000000 */  nop   
/* 0BC778 7F089D88 45020005 */  bc1fl .L7F089DA0
/* 0BC77C 7F089D8C 8FA30050 */   lw    $v1, 0x50($sp)
/* 0BC780 7F089D90 8C4C003C */  lw    $t4, 0x3c($v0)
.L7F089D94:
/* 0BC784 7F089D94 258D0001 */  addiu $t5, $t4, 1
/* 0BC788 7F089D98 AC4D003C */  sw    $t5, 0x3c($v0)
/* 0BC78C 7F089D9C 8FA30050 */  lw    $v1, 0x50($sp)
.L7F089DA0:
/* 0BC790 7F089DA0 44806000 */  mtc1  $zero, $f12
/* 0BC794 7F089DA4 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC798 7F089DA8 10600010 */  beqz  $v1, .L7F089DEC
/* 0BC79C 7F089DAC 00000000 */   nop   
/* 0BC7A0 7F089DB0 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC7A4 7F089DB4 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 0BC7A8 7F089DB8 C44000E0 */  lwc1  $f0, 0xe0($v0)
/* 0BC7AC 7F089DBC C4422A38 */  lwc1  $f2, 0x2a38($v0)
/* 0BC7B0 7F089DC0 46020402 */  mul.s $f16, $f0, $f2
/* 0BC7B4 7F089DC4 4610303E */  c.le.s $f6, $f16
/* 0BC7B8 7F089DC8 00000000 */  nop   
/* 0BC7BC 7F089DCC 45000007 */  bc1f  .L7F089DEC
/* 0BC7C0 7F089DD0 00000000 */   nop   
/* 0BC7C4 7F089DD4 46023103 */  div.s $f4, $f6, $f2
/* 0BC7C8 7F089DD8 46040481 */  sub.s $f18, $f0, $f4
/* 0BC7CC 7F089DDC E45200E0 */  swc1  $f18, 0xe0($v0)
/* 0BC7D0 7F089DE0 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC7D4 7F089DE4 1000005E */  b     .L7F089F60
/* 0BC7D8 7F089DE8 8C428BC0 */   lw    $v0, %lo(g_CurrentPlayer)($v0)
.L7F089DEC:
/* 0BC7DC 7F089DEC 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC7E0 7F089DF0 1060000F */  beqz  $v1, .L7F089E30
/* 0BC7E4 7F089DF4 8C428BC0 */   lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC7E8 7F089DF8 C44800E0 */  lwc1  $f8, 0xe0($v0)
/* 0BC7EC 7F089DFC C44A2A38 */  lwc1  $f10, 0x2a38($v0)
/* 0BC7F0 7F089E00 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 0BC7F4 7F089E04 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BC7F8 7F089E08 460A4403 */  div.s $f16, $f8, $f10
/* 0BC7FC 7F089E0C 3C0E8007 */  lui   $t6, %hi(g_CurrentPlayer) # $t6, 0x8007
/* 0BC800 7F089E10 44819000 */  mtc1  $at, $f18
/* 0BC804 7F089E14 46103101 */  sub.s $f4, $f6, $f16
/* 0BC808 7F089E18 E7A4003C */  swc1  $f4, 0x3c($sp)
/* 0BC80C 7F089E1C E44C00E0 */  swc1  $f12, 0xe0($v0)
/* 0BC810 7F089E20 8DCE8BC0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0BC814 7F089E24 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC818 7F089E28 E5D22A38 */  swc1  $f18, 0x2a38($t6)
/* 0BC81C 7F089E2C 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
.L7F089E30:
/* 0BC820 7F089E30 C7A8003C */  lwc1  $f8, 0x3c($sp)
/* 0BC824 7F089E34 C44A2A34 */  lwc1  $f10, 0x2a34($v0)
/* 0BC828 7F089E38 C45000DC */  lwc1  $f16, 0xdc($v0)
/* 0BC82C 7F089E3C 460A4183 */  div.s $f6, $f8, $f10
/* 0BC830 7F089E40 46068101 */  sub.s $f4, $f16, $f6
/* 0BC834 7F089E44 E44400DC */  swc1  $f4, 0xdc($v0)
/* 0BC838 7F089E48 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC83C 7F089E4C 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC840 7F089E50 C45200DC */  lwc1  $f18, 0xdc($v0)
/* 0BC844 7F089E54 460C903E */  c.le.s $f18, $f12
/* 0BC848 7F089E58 00000000 */  nop   
/* 0BC84C 7F089E5C 45020041 */  bc1fl .L7F089F64
/* 0BC850 7F089E60 C44800F4 */   lwc1  $f8, 0xf4($v0)
/* 0BC854 7F089E64 0FC26669 */  jal   getPlayerCount
/* 0BC858 7F089E68 00000000 */   nop   
/* 0BC85C 7F089E6C 28410002 */  slti  $at, $v0, 2
/* 0BC860 7F089E70 14200036 */  bnez  $at, .L7F089F4C
/* 0BC864 7F089E74 00000000 */   nop   
/* 0BC868 7F089E78 0FC269A4 */  jal   get_cur_playernum
/* 0BC86C 7F089E7C 00000000 */   nop   
/* 0BC870 7F089E80 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0BC874 7F089E84 0FC051B2 */  jal   get_scenario
/* 0BC878 7F089E88 AFA00028 */   sw    $zero, 0x28($sp)
/* 0BC87C 7F089E8C 24010003 */  li    $at, 3
/* 0BC880 7F089E90 14410006 */  bne   $v0, $at, .L7F089EAC
/* 0BC884 7F089E94 00000000 */   nop   
/* 0BC888 7F089E98 0FC234E9 */  jal   bondinvHasGoldenGun
/* 0BC88C 7F089E9C 00000000 */   nop   
/* 0BC890 7F089EA0 10400002 */  beqz  $v0, .L7F089EAC
/* 0BC894 7F089EA4 240F0001 */   li    $t7, 1
/* 0BC898 7F089EA8 AFAF0028 */  sw    $t7, 0x28($sp)
.L7F089EAC:
/* 0BC89C 7F089EAC 0FC15A97 */  jal   drop_inventory
/* 0BC8A0 7F089EB0 00000000 */   nop   
/* 0BC8A4 7F089EB4 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0BC8A8 7F089EB8 8FB9004C */  lw    $t9, 0x4c($sp)
/* 0BC8AC 7F089EBC 13190003 */  beq   $t8, $t9, .L7F089ECC
/* 0BC8B0 7F089EC0 00000000 */   nop   
/* 0BC8B4 7F089EC4 0FC1AC41 */  jal   increment_num_deaths
/* 0BC8B8 7F089EC8 00000000 */   nop   
.L7F089ECC:
/* 0BC8BC 7F089ECC 0FC26993 */  jal   set_cur_player
/* 0BC8C0 7F089ED0 8FA4004C */   lw    $a0, 0x4c($sp)
/* 0BC8C4 7F089ED4 8FA8002C */  lw    $t0, 0x2c($sp)
/* 0BC8C8 7F089ED8 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0BC8CC 7F089EDC 15090005 */  bne   $t0, $t1, .L7F089EF4
/* 0BC8D0 7F089EE0 00000000 */   nop   
/* 0BC8D4 7F089EE4 0FC1AC70 */  jal   increment_num_suicides_display_MP
/* 0BC8D8 7F089EE8 00000000 */   nop   
/* 0BC8DC 7F089EEC 10000008 */  b     .L7F089F10
/* 0BC8E0 7F089EF0 00000000 */   nop   
.L7F089EF4:
/* 0BC8E4 7F089EF4 0FC1ABCA */  jal   increment_num_kills_display_text_in_MP
/* 0BC8E8 7F089EF8 00000000 */   nop   
/* 0BC8EC 7F089EFC 8FAA0028 */  lw    $t2, 0x28($sp)
/* 0BC8F0 7F089F00 11400003 */  beqz  $t2, .L7F089F10
/* 0BC8F4 7F089F04 00000000 */   nop   
/* 0BC8F8 7F089F08 0FC1AC37 */  jal   increment_num_times_killed_MwtGC
/* 0BC8FC 7F089F0C 00000000 */   nop   
.L7F089F10:
/* 0BC900 7F089F10 0FC26993 */  jal   set_cur_player
/* 0BC904 7F089F14 8FA4002C */   lw    $a0, 0x2c($sp)
/* 0BC908 7F089F18 8FAB004C */  lw    $t3, 0x4c($sp)
/* 0BC90C 7F089F1C 8FAD002C */  lw    $t5, 0x2c($sp)
/* 0BC910 7F089F20 3C188007 */  lui   $t8, %hi(g_playerPlayerData) # $t8, 0x8007
/* 0BC914 7F089F24 000B60C0 */  sll   $t4, $t3, 3
/* 0BC918 7F089F28 018B6023 */  subu  $t4, $t4, $t3
/* 0BC91C 7F089F2C 000C6100 */  sll   $t4, $t4, 4
/* 0BC920 7F089F30 000D7080 */  sll   $t6, $t5, 2
/* 0BC924 7F089F34 018E7821 */  addu  $t7, $t4, $t6
/* 0BC928 7F089F38 27188A00 */  addiu $t8, %lo(g_playerPlayerData) # addiu $t8, $t8, -0x7600
/* 0BC92C 7F089F3C 01F81021 */  addu  $v0, $t7, $t8
/* 0BC930 7F089F40 8C590024 */  lw    $t9, 0x24($v0)
/* 0BC934 7F089F44 27280001 */  addiu $t0, $t9, 1
/* 0BC938 7F089F48 AC480024 */  sw    $t0, 0x24($v0)
.L7F089F4C:
/* 0BC93C 7F089F4C 0FC22644 */  jal   bondviewKillCurrentPlayer
/* 0BC940 7F089F50 00000000 */   nop   
/* 0BC944 7F089F54 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC948 7F089F58 44806000 */  mtc1  $zero, $f12
/* 0BC94C 7F089F5C 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
.L7F089F60:
/* 0BC950 7F089F60 C44800F4 */  lwc1  $f8, 0xf4($v0)
.L7F089F64:
/* 0BC954 7F089F64 C7AA0044 */  lwc1  $f10, 0x44($sp)
/* 0BC958 7F089F68 3C098007 */  lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8007
/* 0BC95C 7F089F6C 460C403C */  c.lt.s $f8, $f12
/* 0BC960 7F089F70 00000000 */  nop   
/* 0BC964 7F089F74 4502000F */  bc1fl .L7F089FB4
/* 0BC968 7F089F78 E44C00F4 */   swc1  $f12, 0xf4($v0)
/* 0BC96C 7F089F7C 460A5400 */  add.s $f16, $f10, $f10
/* 0BC970 7F089F80 C4460180 */  lwc1  $f6, 0x180($v0)
/* 0BC974 7F089F84 46103100 */  add.s $f4, $f6, $f16
/* 0BC978 7F089F88 E4440180 */  swc1  $f4, 0x180($v0)
/* 0BC97C 7F089F8C C7B20048 */  lwc1  $f18, 0x48($sp)
/* 0BC980 7F089F90 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC984 7F089F94 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC988 7F089F98 46129200 */  add.s $f8, $f18, $f18
/* 0BC98C 7F089F9C C44A0188 */  lwc1  $f10, 0x188($v0)
/* 0BC990 7F089FA0 46085180 */  add.s $f6, $f10, $f8
/* 0BC994 7F089FA4 E4460188 */  swc1  $f6, 0x188($v0)
/* 0BC998 7F089FA8 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BC99C 7F089FAC 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BC9A0 7F089FB0 E44C00F4 */  swc1  $f12, 0xf4($v0)
.L7F089FB4:
/* 0BC9A4 7F089FB4 8D298BC0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0BC9A8 7F089FB8 0FC2FC1E */  jal   lvlGetControlsLockedFlag
/* 0BC9AC 7F089FBC E52C00F8 */   swc1  $f12, 0xf8($t1)
/* 0BC9B0 7F089FC0 14400005 */  bnez  $v0, .L7F089FD8
/* 0BC9B4 7F089FC4 3C048005 */   lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 0BC9B8 7F089FC8 8C846900 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0BC9BC 7F089FCC 24050044 */  li    $a1, 68
/* 0BC9C0 7F089FD0 0C00209A */  jal   sndPlaySfx
/* 0BC9C4 7F089FD4 00003025 */   move  $a2, $zero
.L7F089FD8:
/* 0BC9C8 7F089FD8 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F089FDC:
/* 0BC9CC 7F089FDC 27BD0040 */  addiu $sp, $sp, 0x40
/* 0BC9D0 7F089FE0 03E00008 */  jr    $ra
/* 0BC9D4 7F089FE4 00000000 */   nop   
)
#endif



#endif


/**
 * @param arg0: unknown
 * @param rad: value in radians
 * @param arg2: unknown
 * @param arg3: unknown
 * 
 * Address 0x7F089E4C.
 */
void bondviewCallRecordDamageKills(f32 arg0, f32 rad, s32 arg2, s32 arg3)
{
    record_damage_kills(arg0, sinf(rad), cosf(rad), arg2, arg3);
}





int bondviewGetIfCurrentPlayerDamageShowTime(void)
{
    return (g_CurrentPlayer->damageshowtime >= (s32)0);
}

int bondviewGetIfCurrentPlayerHealthShowTime(void)
{
    return (g_CurrentPlayer->healthshowtime > (s32)0);
}






f32 bondviewGetBondBreathing(void)
{
    return g_CurrentPlayer->bondbreathing;
}




/**
 * Get the Current Heading of Current Player in Radians
 * @return f32 Heading in Radians
*/
f32 get_curplay_horizontal_rotation_in_degrees(void)
{
    return DegToRad(360.0f - g_CurrentPlayer->vv_theta);
}



/**
 * Get the Current Pitch of Current Player in Radians
 * @return f32 Pitch in Radians
*/
f32 get_curplay_vertical_rotation_in_degrees(void)
{
    return DegToRad(g_CurrentPlayer->vv_verta);
}



s32 bond_pressed_reload_activate(void) {
    return g_CurrentPlayer->field_D0;
}






void set_bondata_invincible_flag(u32 arg0) {
    g_CurrentPlayer->bondinvincible = arg0;
}





u8 get_bondata_invincible_flag(void) {
    return g_CurrentPlayer->bondinvincible;
}


/**
 * Sets g_VisibleToGuardsFlag.
 * 1 = visible, 0 = not visible.
 */
void bondviewSetVisibleToGuardsFlag(s32 param_1)
{
  g_VisibleToGuardsFlag = param_1;
}

/**
 * Gets g_VisibleToGuardsFlag.
 * 1 = visible, 0 = not visible
 */
s32 bondviewGetVisibleToGuardsFlag(void)
{
    return g_VisibleToGuardsFlag;
}

void set_obj_collision_flag(s32 flag) {
  obj_collision_flag = flag;
}

s32 get_obj_collision_flag(void) {
    return obj_collision_flag;
}






/**
 * Address 0x7F089F98.
 */
u8 bondviewGetCurrentPlayersRoom(void)
{
    if ((g_CurrentPlayer->unknown == 1) && (g_CurrentPlayer->room_pointer != 0))
    {
        return g_CurrentPlayer->room_pointer->room;
    }

    return g_CurrentPlayer->field_488.current_tile_ptr_for_portals->room;
}




/**
 * Address 0x7F089FD4.
 */
coord3d *bondviewGetCurrentPlayersPosition(void)
{
    if (g_CurrentPlayer->unknown == 1)
    {
        return &g_CurrentPlayer->pos;
    }

    return &g_CurrentPlayer->field_488.pos;
}



coord3d * bondviewGetCurrentPlayersPosition3(void)
{

    if (g_CurrentPlayer->unknown == 1)
    {
        return &g_CurrentPlayer->pos3;
    }

    return &g_CurrentPlayer->field_488.pos3;
}

struct coord3d *get_BONDdata_field408(void)
{
    return &g_CurrentPlayer->bondprevpos;
}


/**
 * Address 0x7F08A03C.
 */
void bondviewUpdateGuardTankFlagsRelated(PropRecord *arg0, s32 flags)
{
    s32 sp1C;

    sp1C = getPlayerPointerIndex(arg0);

    if (arg0->chr != NULL)
    {
        chrSetMoving(arg0->chr, flags);
    }

    if (g_PlayerTankProp != NULL)
    {
        sub_GAME_7F04F218(g_PlayerTankProp, flags);
    }

    g_playerPointers[sp1C]->field_AC = flags;
}





/**
 * Address 0x7F08A0B0.
 */
void bondviewGetPropHeightRelatedValues(PropRecord *arg0, struct rect4f **field_B0, s32 *arg2, f32 *height_related, f32 *collision)
{
    s32 temp_v0;

    temp_v0 = getPlayerPointerIndex(arg0);
    if (g_playerPointers[temp_v0]->field_AC != 0)
    {
        if (getPlayerCount() == 1 || g_playerPointers[temp_v0]->bonddead == 0)
        {
            if (g_playerPointers[temp_v0]->unknown != 1)
            {
                *arg2 = 4;
                *field_B0 = &g_playerPointers[temp_v0]->collision_bounds;
                *collision = g_playerPointers[temp_v0]->field_70;
                *height_related = *collision + bondviewGetPlayerDuckingHeightRelated(g_playerPointers[temp_v0]) + 10.0f;

                return;
            }
        }
    }

    *arg2 = 0;
}




/**
 * Address 0x7F08A19C.
 */
void bondviewUpdatePlayerCollisionBounds(void)
{

    if (in_tank_flag == 1)
    {
        bondviewGetTankCollisionBounds(&g_CurrentPlayer->collision_bounds, &g_CurrentPlayer->field_488.collision_position, g_TankOrientationAngle);

        return;
    }

    g_CurrentPlayer->collision_bounds.f[0] = (g_CurrentPlayer->field_488.collision_position.f[0] + g_CurrentPlayer->field_488.collision_radius);
    g_CurrentPlayer->collision_bounds.f[1] = g_CurrentPlayer->field_488.collision_position.f[2];
    g_CurrentPlayer->collision_bounds.f[2] = g_CurrentPlayer->field_488.collision_position.f[0];
    g_CurrentPlayer->collision_bounds.f[3] = (g_CurrentPlayer->field_488.collision_position.f[2] + g_CurrentPlayer->field_488.collision_radius);
    g_CurrentPlayer->collision_bounds.f[4] = (g_CurrentPlayer->field_488.collision_position.f[0] - g_CurrentPlayer->field_488.collision_radius);
    g_CurrentPlayer->collision_bounds.f[5] = g_CurrentPlayer->field_488.collision_position.f[2];
    g_CurrentPlayer->collision_bounds.f[6] = g_CurrentPlayer->field_488.collision_position.f[0];
    g_CurrentPlayer->collision_bounds.f[7] = (g_CurrentPlayer->field_488.collision_position.f[2] - g_CurrentPlayer->field_488.collision_radius);
}





/**
 * @param arg0: prop
 * @param width: out parameter, will be set to field_488.collision_radius
 * @param height: out parameter, will be set to character height - 30
 * @param always_30: out parameter, will be set to 30
 * 
 * Address 0x7F08A274.
 */
void bondviewGetCollisionRadius(PropRecord* arg0, f32 *collision_radius, f32 *height, f32 *always_30)
{
    struct player **temp_v1;

    temp_v1 = &g_playerPointers[getPlayerPointerIndex(arg0)];
    *collision_radius = (*temp_v1)->field_488.collision_radius;
    *height = (bondviewGetPlayerDuckingHeightRelated(*temp_v1) + 10.0f) - 30.0f;
    *always_30 = 30.0f;
}





/**
 * Address 0x7F08A2EC.
 */
f32 bondviewGetCurrentPlayerHealth(void)
{
    return g_CurrentPlayer->bondhealth;
}


f32 get_BONDdata_watch_armor(void)
{
  return g_CurrentPlayer->bondarmour;
}





/**
 * Address 0x7F08A30C.
 */
void bondviewAddCurrentPlayerArmor(f32 arg0)
{
    g_playerPerm->body_armor_pickups += arg0;
    g_CurrentPlayer->bondarmour = arg0;
}





/**
 * Address 0x7F08A330.
 */
void bondviewResetIntroCameraMessageDialogs(void)
{
    g_CurrentPlayer->hudmessoff = 0;
    g_CurrentPlayer->bondmesscnt = -1;
    display_statusbar = 0;
    status_bar_text_buffer_index = 0;

#ifdef BUGFIX_R0
    copy_1stfonttable = ptrFontBankGothic;
    copy_2ndfonttable = ptrFontBankGothicChars;
#endif
}



void hudmsgsSetOn(s32 flag)
{
    g_CurrentPlayer->hudmessoff &= ~flag;
}





/**
 * Address 0x7F08A39C.
 */
void hudmsgsSetOff(s32 flags)
{
    g_CurrentPlayer->hudmessoff |= flags;
}


#ifdef VERSION_US
void setFontTables(s32 arg0, s32 arg1)
{
    copy_2ndfonttable = arg0;
    copy_1stfonttable = arg1;
}
#endif


#ifdef BUGFIX_R1
void hudmsgBottomShow(char *string, s32 arg1, s32 arg2)
{
    s32 abs_index;
    s32 index;
    if (getPlayerCount() == 1)
    {
        if (display_statusbar < 5)
        {
            abs_index = status_bar_text_buffer_index + display_statusbar;
            index = abs_index % 5;
            abs_index = index;
            strncpy(stringbuffer_lowerleft[abs_index], string, (BONDVIEW_HUD_MSG_BOTTOM_BUFFER_LENGTH-1));
            stringbuffer_lowerleft[abs_index][(BONDVIEW_HUD_MSG_BOTTOM_BUFFER_LENGTH-1)] = 0;
            dword_CODE_bss_jp80079CEC[abs_index] = arg1;
            dword_CODE_bss_jp80079Cd8[abs_index] = arg2;
            display_statusbar++;
        }
    }
    else
    {
        index = get_cur_playernum();
        strncpy(stringbuffer_lowerleft[index], string, (BONDVIEW_HUD_MSG_BOTTOM_BUFFER_LENGTH-1));
        stringbuffer_lowerleft[index][(BONDVIEW_HUD_MSG_BOTTOM_BUFFER_LENGTH-1)] = 0;
        dword_CODE_bss_jp80079CEC[index] = arg1;
        dword_CODE_bss_jp80079Cd8[index] = arg2;
#if defined(VERSION_EU)
        g_CurrentPlayer->bondmesscnt = 0x64;
#elif defined(VERSION_JP)
        g_CurrentPlayer->bondmesscnt = 0x78;
#endif
    }
}

#else

void hudmsgBottomShow(char *string)
{
    s32 abs_index;
    s32 index;
    if (getPlayerCount() == 1)
    {
        if (display_statusbar < 5)
        {
            abs_index = status_bar_text_buffer_index + display_statusbar;
            index = abs_index % 5;
            strncpy(stringbuffer_lowerleft[index], string, 0x64U);
            display_statusbar++;
            stringbuffer_lowerleft[index][0x64] = 0;
        }
    }
    else
    {
        index = get_cur_playernum();
        strncpy(stringbuffer_lowerleft[index], string, 0x64U);
        stringbuffer_lowerleft[index][0x64] = 0;
        g_CurrentPlayer->bondmesscnt = 0x78;
    }
}

#endif


#if defined(BUGFIX_R1)
void jp_hudmsgBottomShow(char *string)
{
    hudmsgBottomShow(string, ptrFontBankGothicChars, ptrFontBankGothic);
}
#endif


/**
 * Address 0x7F08A4E4.
 */
void bondviewIntroCameraTextTick(void)
{
    if ((g_CurrentPlayer->hudmessoff == 0) && (g_CurrentPlayer->mpmenuon == 0))
    {
        if (g_CurrentPlayer->bondmesscnt >= 0)
        {
            g_CurrentPlayer->bondmesscnt -= g_ClockTimer;

            if (getPlayerCount() == 1)
            {
                if (g_CurrentPlayer->bondmesscnt < 0)
                {
                    status_bar_text_buffer_index = (s32) (status_bar_text_buffer_index + 1) % 5;
                    display_statusbar = display_statusbar - 1;
                }
                else if ((display_statusbar >= 2) && (g_CurrentPlayer->bondmesscnt >= BONDVIEW_INTRO_CAMERA_BONDMESSCNT_A))
                {
                    g_CurrentPlayer->bondmesscnt = BONDVIEW_INTRO_CAMERA_BONDMESSCNT_B;
                }
            }
        }

        if ((getPlayerCount() == 1) && (g_CurrentPlayer->bondmesscnt < 0) && (display_statusbar > 0))
        {
            if (display_statusbar >= 2)
            {
                g_CurrentPlayer->bondmesscnt = BONDVIEW_INTRO_CAMERA_BONDMESSCNT_B;
            }
            else
            {
                g_CurrentPlayer->bondmesscnt = BONDVIEW_INTRO_CAMERA_BONDMESSCNT_C;
            }
        }
    }
}

Gfx* sub_GAME_7F08A5FC(Gfx* arg0)
{
    s32 var_v1;
    s32 view_left;
    s32 view_vert;
    s32 view_horiz;
    s32 view_top;
    s32 view_top_offset;
    s32 view_left_offset;

    if ((g_CurrentPlayer->hudmessoff == 0) && (g_CurrentPlayer->bondmesscnt >= 0) && (g_CurrentPlayer->mpmenuon == 0))
    {
        var_v1 = 0;
        if (getPlayerCount() == 1)
        {
            if ((u8) *stringbuffer_lowerleft[status_bar_text_buffer_index] != 0)
            {
                var_v1 = 1;
            }
        }
        else if (g_CurrentPlayer->bondmesscnt >= 0)
        {
            status_bar_text_buffer_index = get_cur_playernum();
            var_v1 = 1;
        }

        if (var_v1 != 0)
        {
            arg0 = microcode_constructor(arg0);
            view_left_offset = 0;
            view_top_offset = 0;
            textMeasure(&view_top_offset, &view_left_offset ,(u8* ) stringbuffer_lowerleft[status_bar_text_buffer_index], BONDVIEW_2ND_FONTTABLE(status_bar_text_buffer_index), BONDVIEW_1ST_FONTTABLE(status_bar_text_buffer_index), 0);

            if (getPlayerCount() < 3)
            {
                view_left = viGetViewLeft() + 0x1E;
            }
            else if (get_cur_playernum() & 1)
            {
                view_left = viGetViewLeft() + 0xA;
            }
            else
            {
                view_left = viGetViewLeft() + 0x1E;
            }

            view_horiz = view_left + view_left_offset;

            if (getPlayerCount() < 3)
            {
                if ((get_ammo_type_for_weapon(getCurrentPlayerWeaponId(GUNLEFT)) == 0) && (is_clock_drawn_onscreen() == 0))
                {
                    view_top = (viGetViewTop() + viGetViewHeight()) - BONDVIEW_VIEW_TOP_OFFSET_1;
                }
                else
                {
                    view_top = (viGetViewTop() + viGetViewHeight()) - BONDVIEW_VIEW_TOP_OFFSET_2;
                }
#if !defined(VERSION_EU)
                if (get_cur_playernum() == 1)
                {
                    view_top -= 8;
                }
#endif
            }
            else
            {
                view_top = viGetViewTop()
#if defined(VERSION_JP) || defined(VERSION_EU)
                         + (((j_text_trigger != 0) && (get_cur_playernum() < 2)) ? 8 : 0)
#endif
                         + BONDVIEW_VIEW_TOP_OFFSET_3;
            }

            view_vert = view_top - view_top_offset;
            arg0 = draw_blackbox_to_screen(arg0, (s32) &view_left, (s32) &view_vert, (s32) &view_horiz, (s32) &view_top);
            arg0 = combiner_bayer_lod_perspective(textRenderGlow(arg0, &view_left, &view_vert, stringbuffer_lowerleft[status_bar_text_buffer_index], BONDVIEW_2ND_FONTTABLE(status_bar_text_buffer_index), BONDVIEW_1ST_FONTTABLE(status_bar_text_buffer_index), -1, 0x646464FFU, (s16) (s32) viGetX(), (s16) viGetY(), 0, 0));
        }
    }

    return arg0;
}


void bondviewResetUpperTextDisplay(void)
{
    upper_text_window_timer = -1;
    display_upper_text_window = 0;
    upper_text_buffer_index = 0;
    g_UpperTextDisplayFlag = 0;
}


void bondviewClearUpperTextDisplayFlag(int param_1)
{
  int new_var;
  new_var = ~param_1;
  g_UpperTextDisplayFlag = g_UpperTextDisplayFlag & new_var;
}


void bondviewSetUpperTextDisplayFlag(PLAYERFLAG flag)
{
    g_UpperTextDisplayFlag |= flag;
}


void hudmsgTopShow(char* string)
{
    s32 index;

    if (display_upper_text_window >= 2) { return; }

    index = (upper_text_buffer_index + display_upper_text_window) % 2;
#if defined(LEFTOVERDEBUG)
    strncpy(stringbuffer_top[index], string, (BONDVIEW_HUD_MSG_TOP_BUFFER_LENGTH-1));
    display_upper_text_window += 1;
    stringbuffer_top[index][(BONDVIEW_HUD_MSG_TOP_BUFFER_LENGTH-1)] = 0;
#else
    strncpy(dword_CODE_bss_80079DC8[index], string, (BONDVIEW_HUD_MSG_TOP_BUFFER_LENGTH-1));
    display_upper_text_window += 1;
    dword_CODE_bss_80079DC8[index][(BONDVIEW_HUD_MSG_TOP_BUFFER_LENGTH-1)] = 0;
#endif
}


/**
 * Address 0x7F08A9F8.
 */
void bondviewUpperTextWindowTimerTick(void)
{
    if ((g_UpperTextDisplayFlag == 0) && (g_CurrentPlayer->mpmenuon == 0))
    {
        if (upper_text_window_timer >= 0)
        {
            upper_text_window_timer -= g_ClockTimer;

            if (upper_text_window_timer < 0)
            {
                upper_text_buffer_index = (s32) (upper_text_buffer_index + 1) % 2;
                display_upper_text_window += -1;
            }
            else if ((display_upper_text_window >= 2) && (upper_text_window_timer >= BONDVIEW_UPPER_TEXT_TIMER_A))
            {
                upper_text_window_timer = BONDVIEW_UPPER_TEXT_TIMER_B;
            }
        }

        if ((upper_text_window_timer < 0) && (display_upper_text_window > 0))
        {
            if (display_upper_text_window >= 2)
            {
                upper_text_window_timer = BONDVIEW_UPPER_TEXT_TIMER_B;
            }
            else
            {
                upper_text_window_timer = BONDVIEW_UPPER_TEXT_TIMER_C;
            }
        }
    }

}






#ifdef NONMATCHING
void sub_GAME_7F08AAE8(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_800552BC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F08AAE8
/* 0BF618 7F08AAE8 3C0E8003 */  lui   $t6, %hi(g_UpperTextDisplayFlag)
/* 0BF61C 7F08AAEC 8DCE68B4 */  lw    $t6, %lo(g_UpperTextDisplayFlag)($t6)
/* 0BF620 7F08AAF0 27BDFF18 */  addiu $sp, $sp, -0xe8
/* 0BF624 7F08AAF4 AFB00038 */  sw    $s0, 0x38($sp)
/* 0BF628 7F08AAF8 00808025 */  move  $s0, $a0
/* 0BF62C 7F08AAFC 15C00087 */  bnez  $t6, .L7F08AD1C
/* 0BF630 7F08AB00 AFBF003C */   sw    $ra, 0x3c($sp)
/* 0BF634 7F08AB04 3C0F8003 */  lui   $t7, %hi(upper_text_window_timer)
/* 0BF638 7F08AB08 8DEF68B0 */  lw    $t7, %lo(upper_text_window_timer)($t7)
/* 0BF63C 7F08AB0C 3C188003 */  lui   $t8, %hi(upper_text_buffer_index)
/* 0BF640 7F08AB10 05E00082 */  bltz  $t7, .L7F08AD1C
/* 0BF644 7F08AB14 00000000 */   nop
/* 0BF648 7F08AB18 8F1868A8 */  lw    $t8, %lo(upper_text_buffer_index)($t8)
/* 0BF64C 7F08AB1C 3C088008 */  lui   $t0, %hi(stringbuffer_top)
/* 0BF650 7F08AB20 3C098008 */  lui   $t1, %hi(g_CurrentPlayer)
/* 0BF654 7F08AB24 0018C880 */  sll   $t9, $t8, 2
/* 0BF658 7F08AB28 0338C821 */  addu  $t9, $t9, $t8
/* 0BF65C 7F08AB2C 0019C880 */  sll   $t9, $t9, 2
/* 0BF660 7F08AB30 0338C823 */  subu  $t9, $t9, $t8
/* 0BF664 7F08AB34 0019C8C0 */  sll   $t9, $t9, 3
/* 0BF668 7F08AB38 0338C823 */  subu  $t9, $t9, $t8
/* 0BF66C 7F08AB3C 01194021 */  addu  $t0, $t0, $t9
/* 0BF670 7F08AB40 91089C70 */  lbu   $t0, %lo(stringbuffer_top)($t0)
/* 0BF674 7F08AB44 11000075 */  beqz  $t0, .L7F08AD1C
/* 0BF678 7F08AB48 00000000 */   nop
/* 0BF67C 7F08AB4C 8D29A0B0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0BF680 7F08AB50 8D2A29C4 */  lw    $t2, 0x29c4($t1)
/* 0BF684 7F08AB54 15400071 */  bnez  $t2, .L7F08AD1C
/* 0BF688 7F08AB58 00000000 */   nop
/* 0BF68C 7F08AB5C 0FC2B366 */  jal   microcode_constructor
/* 0BF690 7F08AB60 00000000 */   nop
/* 0BF694 7F08AB64 3C0B8003 */  lui   $t3, %hi(upper_text_buffer_index)
/* 0BF698 7F08AB68 8D6B68A8 */  lw    $t3, %lo(upper_text_buffer_index)($t3)
/* 0BF69C 7F08AB6C 3C0E8004 */  lui   $t6, %hi(ptrFontZurichBold)
/* 0BF6A0 7F08AB70 8DCE0EB4 */  lw    $t6, %lo(ptrFontZurichBold)($t6)
/* 0BF6A4 7F08AB74 000B6080 */  sll   $t4, $t3, 2
/* 0BF6A8 7F08AB78 018B6021 */  addu  $t4, $t4, $t3
/* 0BF6AC 7F08AB7C 000C6080 */  sll   $t4, $t4, 2
/* 0BF6B0 7F08AB80 018B6023 */  subu  $t4, $t4, $t3
/* 0BF6B4 7F08AB84 000C60C0 */  sll   $t4, $t4, 3
/* 0BF6B8 7F08AB88 3C0D8008 */  lui   $t5, %hi(stringbuffer_top)
/* 0BF6BC 7F08AB8C 25AD9C70 */  addiu $t5, %lo(stringbuffer_top) # addiu $t5, $t5, -0x6390
/* 0BF6C0 7F08AB90 3C078004 */  lui   $a3, %hi(ptrFontZurichBoldChars)
/* 0BF6C4 7F08AB94 018B6023 */  subu  $t4, $t4, $t3
/* 0BF6C8 7F08AB98 00408025 */  move  $s0, $v0
/* 0BF6CC 7F08AB9C AFA000D4 */  sw    $zero, 0xd4($sp)
/* 0BF6D0 7F08ABA0 AFA000D8 */  sw    $zero, 0xd8($sp)
/* 0BF6D4 7F08ABA4 018D3021 */  addu  $a2, $t4, $t5
/* 0BF6D8 7F08ABA8 8CE70EB8 */  lw    $a3, %lo(ptrFontZurichBoldChars)($a3)
/* 0BF6DC 7F08ABAC 27A400D8 */  addiu $a0, $sp, 0xd8
/* 0BF6E0 7F08ABB0 27A500D4 */  addiu $a1, $sp, 0xd4
/* 0BF6E4 7F08ABB4 AFA00014 */  sw    $zero, 0x14($sp)
/* 0BF6E8 7F08ABB8 0FC2BA63 */  jal   textMeasure
/* 0BF6EC 7F08ABBC AFAE0010 */   sw    $t6, 0x10($sp)
/* 0BF6F0 7F08ABC0 3C0F8003 */  lui   $t7, %hi(camera_8003642C)
/* 0BF6F4 7F08ABC4 8DEF642C */  lw    $t7, %lo(camera_8003642C)($t7)
/* 0BF6F8 7F08ABC8 11E0001B */  beqz  $t7, .L7F08AC38
/* 0BF6FC 7F08ABCC 00000000 */   nop
/* 0BF700 7F08ABD0 0C001145 */  jal   viGetViewLeft
/* 0BF704 7F08ABD4 00000000 */   nop
/* 0BF708 7F08ABD8 24580046 */  addiu $t8, $v0, 0x46
/* 0BF70C 7F08ABDC 0C001149 */  jal   viGetViewTop
/* 0BF710 7F08ABE0 AFB800E4 */   sw    $t8, 0xe4($sp)
/* 0BF714 7F08ABE4 00401825 */  move  $v1, $v0
/* 0BF718 7F08ABE8 24630020 */  addiu $v1, $v1, 0x20
/* 0BF71C 7F08ABEC 2404000B */  li    $a0, 11
/* 0BF720 7F08ABF0 0064001A */  div   $zero, $v1, $a0
/* 0BF724 7F08ABF4 14800002 */  bnez  $a0, .L7F08AC00
/* 0BF728 7F08ABF8 00000000 */   nop
/* 0BF72C 7F08ABFC 0007000D */  break 7
.L7F08AC00:
/* 0BF730 7F08AC00 2401FFFF */  li    $at, -1
/* 0BF734 7F08AC04 14810004 */  bne   $a0, $at, .L7F08AC18
/* 0BF738 7F08AC08 3C018000 */   lui   $at, 0x8000
/* 0BF73C 7F08AC0C 14610002 */  bne   $v1, $at, .L7F08AC18
/* 0BF740 7F08AC10 00000000 */   nop
/* 0BF744 7F08AC14 0006000D */  break 6
.L7F08AC18:
/* 0BF748 7F08AC18 00001812 */  mflo  $v1
/* 0BF74C 7F08AC1C 00000000 */  nop
/* 0BF750 7F08AC20 00000000 */  nop
/* 0BF754 7F08AC24 00640019 */  multu $v1, $a0
/* 0BF758 7F08AC28 00001812 */  mflo  $v1
/* 0BF75C 7F08AC2C 2463FFFE */  addiu $v1, $v1, -2
/* 0BF760 7F08AC30 10000008 */  b     .L7F08AC54
/* 0BF764 7F08AC34 8FA800D8 */   lw    $t0, 0xd8($sp)
.L7F08AC38:
/* 0BF768 7F08AC38 0C001145 */  jal   viGetViewLeft
/* 0BF76C 7F08AC3C 00000000 */   nop
/* 0BF770 7F08AC40 2459001E */  addiu $t9, $v0, 0x1e
/* 0BF774 7F08AC44 0C001149 */  jal   viGetViewTop
/* 0BF778 7F08AC48 AFB900E4 */   sw    $t9, 0xe4($sp)
/* 0BF77C 7F08AC4C 2443000D */  addiu $v1, $v0, 0xd
/* 0BF780 7F08AC50 8FA800D8 */  lw    $t0, 0xd8($sp)
.L7F08AC54:
/* 0BF784 7F08AC54 AFA300E0 */  sw    $v1, 0xe0($sp)
/* 0BF788 7F08AC58 00684821 */  addu  $t1, $v1, $t0
/* 0BF78C 7F08AC5C 0C001107 */  jal   viGetX
/* 0BF790 7F08AC60 AFA900DC */   sw    $t1, 0xdc($sp)
/* 0BF794 7F08AC64 8FA300E0 */  lw    $v1, 0xe0($sp)
/* 0BF798 7F08AC68 8FAA00DC */  lw    $t2, 0xdc($sp)
/* 0BF79C 7F08AC6C 240B0064 */  li    $t3, 100
/* 0BF7A0 7F08AC70 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0BF7A4 7F08AC74 02002025 */  move  $a0, $s0
/* 0BF7A8 7F08AC78 00002825 */  move  $a1, $zero
/* 0BF7AC 7F08AC7C 00403825 */  move  $a3, $v0
/* 0BF7B0 7F08AC80 2466FFFE */  addiu $a2, $v1, -2
/* 0BF7B4 7F08AC84 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0BF7B8 7F08AC88 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0BF7BC 7F08AC8C 0C001107 */  jal   viGetX
/* 0BF7C0 7F08AC90 00408025 */   move  $s0, $v0
/* 0BF7C4 7F08AC94 0C00110B */  jal   viGetY
/* 0BF7C8 7F08AC98 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BF7CC 7F08AC9C 3C0C8003 */  lui   $t4, %hi(upper_text_buffer_index)
/* 0BF7D0 7F08ACA0 8D8C68A8 */  lw    $t4, %lo(upper_text_buffer_index)($t4)
/* 0BF7D4 7F08ACA4 3C0F8004 */  lui   $t7, %hi(ptrFontZurichBoldChars)
/* 0BF7D8 7F08ACA8 3C188004 */  lui   $t8, %hi(ptrFontZurichBold)
/* 0BF7DC 7F08ACAC 000C6880 */  sll   $t5, $t4, 2
/* 0BF7E0 7F08ACB0 01AC6821 */  addu  $t5, $t5, $t4
/* 0BF7E4 7F08ACB4 000D6880 */  sll   $t5, $t5, 2
/* 0BF7E8 7F08ACB8 01AC6823 */  subu  $t5, $t5, $t4
/* 0BF7EC 7F08ACBC 8F180EB4 */  lw    $t8, %lo(ptrFontZurichBold)($t8)
/* 0BF7F0 7F08ACC0 8DEF0EB8 */  lw    $t7, %lo(ptrFontZurichBoldChars)($t7)
/* 0BF7F4 7F08ACC4 87A80048 */  lh    $t0, 0x48($sp)
/* 0BF7F8 7F08ACC8 000D68C0 */  sll   $t5, $t5, 3
/* 0BF7FC 7F08ACCC 3C0E8008 */  lui   $t6, %hi(stringbuffer_top)
/* 0BF800 7F08ACD0 25CE9C70 */  addiu $t6, %lo(stringbuffer_top) # addiu $t6, $t6, -0x6390
/* 0BF804 7F08ACD4 2419FFFF */  li    $t9, -1
/* 0BF808 7F08ACD8 01AC6823 */  subu  $t5, $t5, $t4
/* 0BF80C 7F08ACDC 01AE3821 */  addu  $a3, $t5, $t6
/* 0BF810 7F08ACE0 AFB90018 */  sw    $t9, 0x18($sp)
/* 0BF814 7F08ACE4 02002025 */  move  $a0, $s0
/* 0BF818 7F08ACE8 27A500E4 */  addiu $a1, $sp, 0xe4
/* 0BF81C 7F08ACEC 27A600E0 */  addiu $a2, $sp, 0xe0
/* 0BF820 7F08ACF0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BF824 7F08ACF4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BF828 7F08ACF8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0BF82C 7F08ACFC AFB80014 */  sw    $t8, 0x14($sp)
/* 0BF830 7F08AD00 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0BF834 7F08AD04 0FC2B6AF */  jal   textRender
/* 0BF838 7F08AD08 AFA8001C */   sw    $t0, 0x1c($sp)
/* 0BF83C 7F08AD0C 0FC2B3BC */  jal   combiner_bayer_lod_perspective
/* 0BF840 7F08AD10 00402025 */   move  $a0, $v0
/* 0BF844 7F08AD14 100000F1 */  b     .L7F08B0DC
/* 0BF848 7F08AD18 00408025 */   move  $s0, $v0
.L7F08AD1C:
/* 0BF84C 7F08AD1C 0FC243E2 */  jal   get_debug_testingmanpos_flag
/* 0BF850 7F08AD20 00000000 */   nop
/* 0BF854 7F08AD24 104000ED */  beqz  $v0, .L7F08B0DC
/* 0BF858 7F08AD28 3C028008 */   lui   $v0, %hi(g_CurrentPlayer)
/* 0BF85C 7F08AD2C 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BF860 7F08AD30 C4400498 */  lwc1  $f0, 0x498($v0)
/* 0BF864 7F08AD34 C44E04A0 */  lwc1  $f14, 0x4a0($v0)
/* 0BF868 7F08AD38 0FC16A8C */  jal   atan2f
/* 0BF86C 7F08AD3C 46000307 */   neg.s $f12, $f0
/* 0BF870 7F08AD40 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 0BF874 7F08AD44 44812000 */  mtc1  $at, $f4
/* 0BF878 7F08AD48 3C018005 */  lui   $at, %hi(D_800552BC)
/* 0BF87C 7F08AD4C C42852BC */  lwc1  $f8, %lo(D_800552BC)($at)
/* 0BF880 7F08AD50 46040182 */  mul.s $f6, $f0, $f4
/* 0BF884 7F08AD54 3C0C8003 */  lui   $t4, %hi(D_800368B8)
/* 0BF888 7F08AD58 258C68B8 */  addiu $t4, %lo(D_800368B8) # addiu $t4, $t4, 0x68b8
/* 0BF88C 7F08AD5C 27AB004C */  addiu $t3, $sp, 0x4c
/* 0BF890 7F08AD60 3C188008 */  lui   $t8, %hi(g_CurrentPlayer)
/* 0BF894 7F08AD64 46083283 */  div.s $f10, $f6, $f8
/* 0BF898 7F08AD68 4600540D */  trunc.w.s $f16, $f10
/* 0BF89C 7F08AD6C 440A8000 */  mfc1  $t2, $f16
/* 0BF8A0 7F08AD70 00000000 */  nop
/* 0BF8A4 7F08AD74 AFAA0068 */  sw    $t2, 0x68($sp)
/* 0BF8A8 7F08AD78 8D810000 */  lw    $at, ($t4)
/* 0BF8AC 7F08AD7C 8D8F0004 */  lw    $t7, 4($t4)
/* 0BF8B0 7F08AD80 AD610000 */  sw    $at, ($t3)
/* 0BF8B4 7F08AD84 8D810008 */  lw    $at, 8($t4)
/* 0BF8B8 7F08AD88 AD6F0004 */  sw    $t7, 4($t3)
/* 0BF8BC 7F08AD8C 8D8F000C */  lw    $t7, 0xc($t4)
/* 0BF8C0 7F08AD90 AD610008 */  sw    $at, 8($t3)
/* 0BF8C4 7F08AD94 8D810010 */  lw    $at, 0x10($t4)
/* 0BF8C8 7F08AD98 AD6F000C */  sw    $t7, 0xc($t3)
/* 0BF8CC 7F08AD9C 8D8F0014 */  lw    $t7, 0x14($t4)
/* 0BF8D0 7F08ADA0 AD610010 */  sw    $at, 0x10($t3)
/* 0BF8D4 7F08ADA4 9981001A */  lwr   $at, 0x1a($t4)
/* 0BF8D8 7F08ADA8 AD6F0014 */  sw    $t7, 0x14($t3)
/* 0BF8DC 7F08ADAC B961001A */  swr   $at, 0x1a($t3)
/* 0BF8E0 7F08ADB0 8F18A0B0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0BF8E4 7F08ADB4 8F190488 */  lw    $t9, 0x488($t8)
/* 0BF8E8 7F08ADB8 0FC2D778 */  jal   bgDebPrintROOMID
/* 0BF8EC 7F08ADBC 93240003 */   lbu   $a0, 3($t9)
/* 0BF8F0 7F08ADC0 3C058005 */  lui   $a1, %hi(a8s)
/* 0BF8F4 7F08ADC4 24A54FC0 */  addiu $a1, %lo(a8s) # addiu $a1, $a1, 0x4fc0
/* 0BF8F8 7F08ADC8 27A400C4 */  addiu $a0, $sp, 0xc4
/* 0BF8FC 7F08ADCC 0C002B25 */  jal   sprintf
/* 0BF900 7F08ADD0 00403025 */   move  $a2, $v0
/* 0BF904 7F08ADD4 3C088008 */  lui   $t0, %hi(g_CurrentPlayer)
/* 0BF908 7F08ADD8 8D08A0B0 */  lw    $t0, %lo(g_CurrentPlayer)($t0)
/* 0BF90C 7F08ADDC 3C058005 */  lui   $a1, %hi(aX4_0f)
/* 0BF910 7F08ADE0 24A54FC4 */  addiu $a1, %lo(aX4_0f) # addiu $a1, $a1, 0x4fc4
/* 0BF914 7F08ADE4 C512048C */  lwc1  $f18, 0x48c($t0)
/* 0BF918 7F08ADE8 27A400B4 */  addiu $a0, $sp, 0xb4
/* 0BF91C 7F08ADEC 46009121 */  cvt.d.s $f4, $f18
/* 0BF920 7F08ADF0 44072000 */  mfc1  $a3, $f4
/* 0BF924 7F08ADF4 44062800 */  mfc1  $a2, $f5
/* 0BF928 7F08ADF8 0C002B25 */  jal   sprintf
/* 0BF92C 7F08ADFC 00000000 */   nop
/* 0BF930 7F08AE00 3C098008 */  lui   $t1, %hi(g_CurrentPlayer)
/* 0BF934 7F08AE04 8D29A0B0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0BF938 7F08AE08 3C058005 */  lui   $a1, %hi(aY4_0f)
/* 0BF93C 7F08AE0C 24A54FCC */  addiu $a1, %lo(aY4_0f) # addiu $a1, $a1, 0x4fcc
/* 0BF940 7F08AE10 C5260490 */  lwc1  $f6, 0x490($t1)
/* 0BF944 7F08AE14 27A400A4 */  addiu $a0, $sp, 0xa4
/* 0BF948 7F08AE18 46003221 */  cvt.d.s $f8, $f6
/* 0BF94C 7F08AE1C 44074000 */  mfc1  $a3, $f8
/* 0BF950 7F08AE20 44064800 */  mfc1  $a2, $f9
/* 0BF954 7F08AE24 0C002B25 */  jal   sprintf
/* 0BF958 7F08AE28 00000000 */   nop
/* 0BF95C 7F08AE2C 3C0A8008 */  lui   $t2, %hi(g_CurrentPlayer)
/* 0BF960 7F08AE30 8D4AA0B0 */  lw    $t2, %lo(g_CurrentPlayer)($t2)
/* 0BF964 7F08AE34 3C058005 */  lui   $a1, %hi(aZ4_0f)
/* 0BF968 7F08AE38 24A54FD4 */  addiu $a1, %lo(aZ4_0f) # addiu $a1, $a1, 0x4fd4
/* 0BF96C 7F08AE3C C54A0494 */  lwc1  $f10, 0x494($t2)
/* 0BF970 7F08AE40 27A40094 */  addiu $a0, $sp, 0x94
/* 0BF974 7F08AE44 46005421 */  cvt.d.s $f16, $f10
/* 0BF978 7F08AE48 44078000 */  mfc1  $a3, $f16
/* 0BF97C 7F08AE4C 44068800 */  mfc1  $a2, $f17
/* 0BF980 7F08AE50 0C002B25 */  jal   sprintf
/* 0BF984 7F08AE54 00000000 */   nop
/* 0BF988 7F08AE58 8FA70068 */  lw    $a3, 0x68($sp)
/* 0BF98C 7F08AE5C 2401002D */  li    $at, 45
/* 0BF990 7F08AE60 3C058005 */  lui   $a1, %hi(aS3d)
/* 0BF994 7F08AE64 24EE0016 */  addiu $t6, $a3, 0x16
/* 0BF998 7F08AE68 01C1001A */  div   $zero, $t6, $at
/* 0BF99C 7F08AE6C 00006812 */  mflo  $t5
/* 0BF9A0 7F08AE70 000D5880 */  sll   $t3, $t5, 2
/* 0BF9A4 7F08AE74 016D5823 */  subu  $t3, $t3, $t5
/* 0BF9A8 7F08AE78 27AC004C */  addiu $t4, $sp, 0x4c
/* 0BF9AC 7F08AE7C 016C3021 */  addu  $a2, $t3, $t4
/* 0BF9B0 7F08AE80 24A54FDC */  addiu $a1, %lo(aS3d) # addiu $a1, $a1, 0x4fdc
/* 0BF9B4 7F08AE84 0C002B25 */  jal   sprintf
/* 0BF9B8 7F08AE88 27A40084 */   addiu $a0, $sp, 0x84
/* 0BF9BC 7F08AE8C 0C001145 */  jal   viGetViewLeft
/* 0BF9C0 7F08AE90 00000000 */   nop
/* 0BF9C4 7F08AE94 244F0011 */  addiu $t7, $v0, 0x11
/* 0BF9C8 7F08AE98 0C001149 */  jal   viGetViewTop
/* 0BF9CC 7F08AE9C AFAF0080 */   sw    $t7, 0x80($sp)
/* 0BF9D0 7F08AEA0 24460011 */  addiu $a2, $v0, 0x11
/* 0BF9D4 7F08AEA4 24D8000A */  addiu $t8, $a2, 0xa
/* 0BF9D8 7F08AEA8 AFB80074 */  sw    $t8, 0x74($sp)
/* 0BF9DC 7F08AEAC AFA6007C */  sw    $a2, 0x7c($sp)
/* 0BF9E0 7F08AEB0 0FC2B366 */  jal   microcode_constructor
/* 0BF9E4 7F08AEB4 02002025 */   move  $a0, $s0
/* 0BF9E8 7F08AEB8 0C001107 */  jal   viGetX
/* 0BF9EC 7F08AEBC 00408025 */   move  $s0, $v0
/* 0BF9F0 7F08AEC0 8FB90074 */  lw    $t9, 0x74($sp)
/* 0BF9F4 7F08AEC4 24090064 */  li    $t1, 100
/* 0BF9F8 7F08AEC8 AFA90014 */  sw    $t1, 0x14($sp)
/* 0BF9FC 7F08AECC 27280001 */  addiu $t0, $t9, 1
/* 0BFA00 7F08AED0 AFA80010 */  sw    $t0, 0x10($sp)
/* 0BFA04 7F08AED4 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0BFA08 7F08AED8 02002025 */  move  $a0, $s0
/* 0BFA0C 7F08AEDC 00002825 */  move  $a1, $zero
/* 0BFA10 7F08AEE0 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0BFA14 7F08AEE4 00403825 */   move  $a3, $v0
/* 0BFA18 7F08AEE8 0C001107 */  jal   viGetX
/* 0BFA1C 7F08AEEC 00408025 */   move  $s0, $v0
/* 0BFA20 7F08AEF0 0C00110B */  jal   viGetY
/* 0BFA24 7F08AEF4 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BFA28 7F08AEF8 3C0A8004 */  lui   $t2, %hi(ptrFontBankGothicChars)
/* 0BFA2C 7F08AEFC 3C0E8004 */  lui   $t6, %hi(ptrFontBankGothic)
/* 0BFA30 7F08AF00 8DCE0EAC */  lw    $t6, %lo(ptrFontBankGothic)($t6)
/* 0BFA34 7F08AF04 8D4A0EB0 */  lw    $t2, %lo(ptrFontBankGothicChars)($t2)
/* 0BFA38 7F08AF08 87AB0048 */  lh    $t3, 0x48($sp)
/* 0BFA3C 7F08AF0C 240DFFFF */  li    $t5, -1
/* 0BFA40 7F08AF10 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0BFA44 7F08AF14 02002025 */  move  $a0, $s0
/* 0BFA48 7F08AF18 27A50080 */  addiu $a1, $sp, 0x80
/* 0BFA4C 7F08AF1C 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BFA50 7F08AF20 27A700C4 */  addiu $a3, $sp, 0xc4
/* 0BFA54 7F08AF24 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BFA58 7F08AF28 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BFA5C 7F08AF2C AFA00028 */  sw    $zero, 0x28($sp)
/* 0BFA60 7F08AF30 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0BFA64 7F08AF34 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0BFA68 7F08AF38 0FC2B6AF */  jal   textRender
/* 0BFA6C 7F08AF3C AFAB001C */   sw    $t3, 0x1c($sp)
/* 0BFA70 7F08AF40 0C001145 */  jal   viGetViewLeft
/* 0BFA74 7F08AF44 00408025 */   move  $s0, $v0
/* 0BFA78 7F08AF48 244C0057 */  addiu $t4, $v0, 0x57
/* 0BFA7C 7F08AF4C 0C001107 */  jal   viGetX
/* 0BFA80 7F08AF50 AFAC0080 */   sw    $t4, 0x80($sp)
/* 0BFA84 7F08AF54 0C00110B */  jal   viGetY
/* 0BFA88 7F08AF58 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BFA8C 7F08AF5C 3C0F8004 */  lui   $t7, %hi(ptrFontBankGothicChars)
/* 0BFA90 7F08AF60 3C188004 */  lui   $t8, %hi(ptrFontBankGothic)
/* 0BFA94 7F08AF64 8F180EAC */  lw    $t8, %lo(ptrFontBankGothic)($t8)
/* 0BFA98 7F08AF68 8DEF0EB0 */  lw    $t7, %lo(ptrFontBankGothicChars)($t7)
/* 0BFA9C 7F08AF6C 87A80048 */  lh    $t0, 0x48($sp)
/* 0BFAA0 7F08AF70 2419FFFF */  li    $t9, -1
/* 0BFAA4 7F08AF74 AFB90018 */  sw    $t9, 0x18($sp)
/* 0BFAA8 7F08AF78 02002025 */  move  $a0, $s0
/* 0BFAAC 7F08AF7C 27A50080 */  addiu $a1, $sp, 0x80
/* 0BFAB0 7F08AF80 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BFAB4 7F08AF84 27A700B4 */  addiu $a3, $sp, 0xb4
/* 0BFAB8 7F08AF88 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BFABC 7F08AF8C AFA00024 */  sw    $zero, 0x24($sp)
/* 0BFAC0 7F08AF90 AFA00028 */  sw    $zero, 0x28($sp)
/* 0BFAC4 7F08AF94 AFB80014 */  sw    $t8, 0x14($sp)
/* 0BFAC8 7F08AF98 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0BFACC 7F08AF9C 0FC2B6AF */  jal   textRender
/* 0BFAD0 7F08AFA0 AFA8001C */   sw    $t0, 0x1c($sp)
/* 0BFAD4 7F08AFA4 0C001145 */  jal   viGetViewLeft
/* 0BFAD8 7F08AFA8 00408025 */   move  $s0, $v0
/* 0BFADC 7F08AFAC 2449008D */  addiu $t1, $v0, 0x8d
/* 0BFAE0 7F08AFB0 0C001107 */  jal   viGetX
/* 0BFAE4 7F08AFB4 AFA90080 */   sw    $t1, 0x80($sp)
/* 0BFAE8 7F08AFB8 0C00110B */  jal   viGetY
/* 0BFAEC 7F08AFBC A7A20048 */   sh    $v0, 0x48($sp)
/* 0BFAF0 7F08AFC0 3C0A8004 */  lui   $t2, %hi(ptrFontBankGothicChars)
/* 0BFAF4 7F08AFC4 3C0E8004 */  lui   $t6, %hi(ptrFontBankGothic)
/* 0BFAF8 7F08AFC8 8DCE0EAC */  lw    $t6, %lo(ptrFontBankGothic)($t6)
/* 0BFAFC 7F08AFCC 8D4A0EB0 */  lw    $t2, %lo(ptrFontBankGothicChars)($t2)
/* 0BFB00 7F08AFD0 87AB0048 */  lh    $t3, 0x48($sp)
/* 0BFB04 7F08AFD4 240DFFFF */  li    $t5, -1
/* 0BFB08 7F08AFD8 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0BFB0C 7F08AFDC 02002025 */  move  $a0, $s0
/* 0BFB10 7F08AFE0 27A50080 */  addiu $a1, $sp, 0x80
/* 0BFB14 7F08AFE4 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BFB18 7F08AFE8 27A700A4 */  addiu $a3, $sp, 0xa4
/* 0BFB1C 7F08AFEC AFA20020 */  sw    $v0, 0x20($sp)
/* 0BFB20 7F08AFF0 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BFB24 7F08AFF4 AFA00028 */  sw    $zero, 0x28($sp)
/* 0BFB28 7F08AFF8 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0BFB2C 7F08AFFC AFAA0010 */  sw    $t2, 0x10($sp)
/* 0BFB30 7F08B000 0FC2B6AF */  jal   textRender
/* 0BFB34 7F08B004 AFAB001C */   sw    $t3, 0x1c($sp)
/* 0BFB38 7F08B008 0C001145 */  jal   viGetViewLeft
/* 0BFB3C 7F08B00C 00408025 */   move  $s0, $v0
/* 0BFB40 7F08B010 244C00C3 */  addiu $t4, $v0, 0xc3
/* 0BFB44 7F08B014 0C001107 */  jal   viGetX
/* 0BFB48 7F08B018 AFAC0080 */   sw    $t4, 0x80($sp)
/* 0BFB4C 7F08B01C 0C00110B */  jal   viGetY
/* 0BFB50 7F08B020 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BFB54 7F08B024 3C0F8004 */  lui   $t7, %hi(ptrFontBankGothicChars)
/* 0BFB58 7F08B028 3C188004 */  lui   $t8, %hi(ptrFontBankGothic)
/* 0BFB5C 7F08B02C 8F180EAC */  lw    $t8, %lo(ptrFontBankGothic)($t8)
/* 0BFB60 7F08B030 8DEF0EB0 */  lw    $t7, %lo(ptrFontBankGothicChars)($t7)
/* 0BFB64 7F08B034 87A80048 */  lh    $t0, 0x48($sp)
/* 0BFB68 7F08B038 2419FFFF */  li    $t9, -1
/* 0BFB6C 7F08B03C AFB90018 */  sw    $t9, 0x18($sp)
/* 0BFB70 7F08B040 02002025 */  move  $a0, $s0
/* 0BFB74 7F08B044 27A50080 */  addiu $a1, $sp, 0x80
/* 0BFB78 7F08B048 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BFB7C 7F08B04C 27A70094 */  addiu $a3, $sp, 0x94
/* 0BFB80 7F08B050 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BFB84 7F08B054 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BFB88 7F08B058 AFA00028 */  sw    $zero, 0x28($sp)
/* 0BFB8C 7F08B05C AFB80014 */  sw    $t8, 0x14($sp)
/* 0BFB90 7F08B060 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0BFB94 7F08B064 0FC2B6AF */  jal   textRender
/* 0BFB98 7F08B068 AFA8001C */   sw    $t0, 0x1c($sp)
/* 0BFB9C 7F08B06C 0C001145 */  jal   viGetViewLeft
/* 0BFBA0 7F08B070 00408025 */   move  $s0, $v0
/* 0BFBA4 7F08B074 244900F9 */  addiu $t1, $v0, 0xf9
/* 0BFBA8 7F08B078 0C001107 */  jal   viGetX
/* 0BFBAC 7F08B07C AFA90080 */   sw    $t1, 0x80($sp)
/* 0BFBB0 7F08B080 0C00110B */  jal   viGetY
/* 0BFBB4 7F08B084 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BFBB8 7F08B088 3C0A8004 */  lui   $t2, %hi(ptrFontBankGothicChars)
/* 0BFBBC 7F08B08C 3C0E8004 */  lui   $t6, %hi(ptrFontBankGothic)
/* 0BFBC0 7F08B090 8DCE0EAC */  lw    $t6, %lo(ptrFontBankGothic)($t6)
/* 0BFBC4 7F08B094 8D4A0EB0 */  lw    $t2, %lo(ptrFontBankGothicChars)($t2)
/* 0BFBC8 7F08B098 87AB0048 */  lh    $t3, 0x48($sp)
/* 0BFBCC 7F08B09C 240DFFFF */  li    $t5, -1
/* 0BFBD0 7F08B0A0 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0BFBD4 7F08B0A4 02002025 */  move  $a0, $s0
/* 0BFBD8 7F08B0A8 27A50080 */  addiu $a1, $sp, 0x80
/* 0BFBDC 7F08B0AC 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BFBE0 7F08B0B0 27A70084 */  addiu $a3, $sp, 0x84
/* 0BFBE4 7F08B0B4 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BFBE8 7F08B0B8 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BFBEC 7F08B0BC AFA00028 */  sw    $zero, 0x28($sp)
/* 0BFBF0 7F08B0C0 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0BFBF4 7F08B0C4 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0BFBF8 7F08B0C8 0FC2B6AF */  jal   textRender
/* 0BFBFC 7F08B0CC AFAB001C */   sw    $t3, 0x1c($sp)
/* 0BFC00 7F08B0D0 0FC2B3BC */  jal   combiner_bayer_lod_perspective
/* 0BFC04 7F08B0D4 00402025 */   move  $a0, $v0
/* 0BFC08 7F08B0D8 00408025 */  move  $s0, $v0
.L7F08B0DC:
/* 0BFC0C 7F08B0DC 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0BFC10 7F08B0E0 02001025 */  move  $v0, $s0
/* 0BFC14 7F08B0E4 8FB00038 */  lw    $s0, 0x38($sp)
/* 0BFC18 7F08B0E8 03E00008 */  jr    $ra
/* 0BFC1C 7F08B0EC 27BD00E8 */   addiu $sp, $sp, 0xe8
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_800552BC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F08AAE8
/* 0BFE34 7F08B2C4 3C0E8003 */  lui   $t6, %hi(g_UpperTextDisplayFlag) # $t6, 0x8003
/* 0BFE38 7F08B2C8 8DCE68EC */  lw    $t6, %lo(g_UpperTextDisplayFlag)($t6)
/* 0BFE3C 7F08B2CC 27BDFF18 */  addiu $sp, $sp, -0xe8
/* 0BFE40 7F08B2D0 AFB00038 */  sw    $s0, 0x38($sp)
/* 0BFE44 7F08B2D4 00808025 */  move  $s0, $a0
/* 0BFE48 7F08B2D8 15C000B2 */  bnez  $t6, .Ljp7F08B5A4
/* 0BFE4C 7F08B2DC AFBF003C */   sw    $ra, 0x3c($sp)
/* 0BFE50 7F08B2E0 3C0F8003 */  lui   $t7, %hi(upper_text_window_timer) # $t7, 0x8003
/* 0BFE54 7F08B2E4 8DEF68E8 */  lw    $t7, %lo(upper_text_window_timer)($t7)
/* 0BFE58 7F08B2E8 3C188003 */  lui   $t8, %hi(upper_text_buffer_index) # $t8, 0x8003
/* 0BFE5C 7F08B2EC 05E000AD */  bltz  $t7, .Ljp7F08B5A4
/* 0BFE60 7F08B2F0 00000000 */   nop
/* 0BFE64 7F08B2F4 8F1868E0 */  lw    $t8, %lo(upper_text_buffer_index)($t8)
/* 0BFE68 7F08B2F8 3C088008 */  lui   $t0, %hi(stringbuffer_top)
/* 0BFE6C 7F08B2FC 3C098008 */  lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8008
/* 0BFE70 7F08B300 0018C880 */  sll   $t9, $t8, 2
/* 0BFE74 7F08B304 0338C821 */  addu  $t9, $t9, $t8
/* 0BFE78 7F08B308 0019C880 */  sll   $t9, $t9, 2
/* 0BFE7C 7F08B30C 0338C823 */  subu  $t9, $t9, $t8
/* 0BFE80 7F08B310 0019C8C0 */  sll   $t9, $t9, 3
/* 0BFE84 7F08B314 0338C823 */  subu  $t9, $t9, $t8
/* 0BFE88 7F08B318 01194021 */  addu  $t0, $t0, $t9
/* 0BFE8C 7F08B31C 91089CE0 */  lbu   $t0, %lo(stringbuffer_top)($t0)
/* 0BFE90 7F08B320 110000A0 */  beqz  $t0, .Ljp7F08B5A4
/* 0BFE94 7F08B324 00000000 */   nop
/* 0BFE98 7F08B328 8D29A120 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0BFE9C 7F08B32C 8D2A29C4 */  lw    $t2, 0x29c4($t1)
/* 0BFEA0 7F08B330 1540009C */  bnez  $t2, .Ljp7F08B5A4
/* 0BFEA4 7F08B334 00000000 */   nop
/* 0BFEA8 7F08B338 0FC2B652 */  jal   microcode_constructor
/* 0BFEAC 7F08B33C 00000000 */   nop
/* 0BFEB0 7F08B340 3C0B8003 */  lui   $t3, %hi(upper_text_buffer_index) # $t3, 0x8003
/* 0BFEB4 7F08B344 8D6B68E0 */  lw    $t3, %lo(upper_text_buffer_index)($t3)
/* 0BFEB8 7F08B348 3C0E8004 */  lui   $t6, %hi(ptrFontZurichBold) # $t6, 0x8004
/* 0BFEBC 7F08B34C 8DCE0EE4 */  lw    $t6, %lo(ptrFontZurichBold)($t6)
/* 0BFEC0 7F08B350 000B6080 */  sll   $t4, $t3, 2
/* 0BFEC4 7F08B354 018B6021 */  addu  $t4, $t4, $t3
/* 0BFEC8 7F08B358 000C6080 */  sll   $t4, $t4, 2
/* 0BFECC 7F08B35C 018B6023 */  subu  $t4, $t4, $t3
/* 0BFED0 7F08B360 000C60C0 */  sll   $t4, $t4, 3
/* 0BFED4 7F08B364 3C0D8008 */  lui   $t5, %hi(stringbuffer_top) # $t5, 0x8008
/* 0BFED8 7F08B368 25AD9CE0 */  addiu $t5, %lo(stringbuffer_top) # addiu $t5, $t5, -0x6320
/* 0BFEDC 7F08B36C 3C078004 */  lui   $a3, %hi(ptrFontZurichBoldChars) # $a3, 0x8004
/* 0BFEE0 7F08B370 018B6023 */  subu  $t4, $t4, $t3
/* 0BFEE4 7F08B374 00408025 */  move  $s0, $v0
/* 0BFEE8 7F08B378 AFA000D4 */  sw    $zero, 0xd4($sp)
/* 0BFEEC 7F08B37C AFA000D8 */  sw    $zero, 0xd8($sp)
/* 0BFEF0 7F08B380 018D3021 */  addu  $a2, $t4, $t5
/* 0BFEF4 7F08B384 8CE70EE8 */  lw    $a3, %lo(ptrFontZurichBoldChars)($a3)
/* 0BFEF8 7F08B388 27A400D8 */  addiu $a0, $sp, 0xd8
/* 0BFEFC 7F08B38C 27A500D4 */  addiu $a1, $sp, 0xd4
/* 0BFF00 7F08B390 AFA00014 */  sw    $zero, 0x14($sp)
/* 0BFF04 7F08B394 0FC2BD4F */  jal   textMeasure
/* 0BFF08 7F08B398 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0BFF0C 7F08B39C 3C0F8003 */  lui   $t7, %hi(camera_8003642C) # $t7, 0x8003
/* 0BFF10 7F08B3A0 8DEF646C */  lw    $t7, %lo(camera_8003642C)($t7)
/* 0BFF14 7F08B3A4 11E0001B */  beqz  $t7, .Ljp7F08B414
/* 0BFF18 7F08B3A8 00000000 */   nop
/* 0BFF1C 7F08B3AC 0C001145 */  jal   viGetViewLeft
/* 0BFF20 7F08B3B0 00000000 */   nop
/* 0BFF24 7F08B3B4 24580046 */  addiu $t8, $v0, 0x46
/* 0BFF28 7F08B3B8 0C001149 */  jal   viGetViewTop
/* 0BFF2C 7F08B3BC AFB800E4 */   sw    $t8, 0xe4($sp)
/* 0BFF30 7F08B3C0 00401825 */  move  $v1, $v0
/* 0BFF34 7F08B3C4 24630020 */  addiu $v1, $v1, 0x20
/* 0BFF38 7F08B3C8 2404000B */  li    $a0, 11
/* 0BFF3C 7F08B3CC 0064001A */  div   $zero, $v1, $a0
/* 0BFF40 7F08B3D0 14800002 */  bnez  $a0, .Ljp7F08B3DC
/* 0BFF44 7F08B3D4 00000000 */   nop
/* 0BFF48 7F08B3D8 0007000D */  break 7
.Ljp7F08B3DC:
/* 0BFF4C 7F08B3DC 2401FFFF */  li    $at, -1
/* 0BFF50 7F08B3E0 14810004 */  bne   $a0, $at, .Ljp7F08B3F4
/* 0BFF54 7F08B3E4 3C018000 */   lui   $at, 0x8000
/* 0BFF58 7F08B3E8 14610002 */  bne   $v1, $at, .Ljp7F08B3F4
/* 0BFF5C 7F08B3EC 00000000 */   nop
/* 0BFF60 7F08B3F0 0006000D */  break 6
.Ljp7F08B3F4:
/* 0BFF64 7F08B3F4 00001812 */  mflo  $v1
/* 0BFF68 7F08B3F8 00000000 */  nop
/* 0BFF6C 7F08B3FC 00000000 */  nop
/* 0BFF70 7F08B400 00640019 */  multu $v1, $a0
/* 0BFF74 7F08B404 00001812 */  mflo  $v1
/* 0BFF78 7F08B408 2463FFFE */  addiu $v1, $v1, -2
/* 0BFF7C 7F08B40C 10000008 */  b     .Ljp7F08B430
/* 0BFF80 7F08B410 8FA800D8 */   lw    $t0, 0xd8($sp)
.Ljp7F08B414:
/* 0BFF84 7F08B414 0C001145 */  jal   viGetViewLeft
/* 0BFF88 7F08B418 00000000 */   nop
/* 0BFF8C 7F08B41C 2459001E */  addiu $t9, $v0, 0x1e
/* 0BFF90 7F08B420 0C001149 */  jal   viGetViewTop
/* 0BFF94 7F08B424 AFB900E4 */   sw    $t9, 0xe4($sp)
/* 0BFF98 7F08B428 2443000D */  addiu $v1, $v0, 0xd
/* 0BFF9C 7F08B42C 8FA800D8 */  lw    $t0, 0xd8($sp)
.Ljp7F08B430:
/* 0BFFA0 7F08B430 AFA300E0 */  sw    $v1, 0xe0($sp)
/* 0BFFA4 7F08B434 00684821 */  addu  $t1, $v1, $t0
/* 0BFFA8 7F08B438 0C001107 */  jal   viGetX
/* 0BFFAC 7F08B43C AFA900DC */   sw    $t1, 0xdc($sp)
/* 0BFFB0 7F08B440 8FA300E0 */  lw    $v1, 0xe0($sp)
/* 0BFFB4 7F08B444 8FAA00DC */  lw    $t2, 0xdc($sp)
/* 0BFFB8 7F08B448 240B0064 */  li    $t3, 100
/* 0BFFBC 7F08B44C AFAB0014 */  sw    $t3, 0x14($sp)
/* 0BFFC0 7F08B450 02002025 */  move  $a0, $s0
/* 0BFFC4 7F08B454 00002825 */  move  $a1, $zero
/* 0BFFC8 7F08B458 00403825 */  move  $a3, $v0
/* 0BFFCC 7F08B45C 2466FFFE */  addiu $a2, $v1, -2
/* 0BFFD0 7F08B460 0FC2B6F1 */  jal   microcode_constructor_related_to_menus
/* 0BFFD4 7F08B464 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0BFFD8 7F08B468 3C0C8005 */  lui   $t4, %hi(j_text_trigger) # $t4, 0x8005
/* 0BFFDC 7F08B46C 8D8C8500 */  lw    $t4, %lo(j_text_trigger)($t4)
/* 0BFFE0 7F08B470 00408025 */  move  $s0, $v0
/* 0BFFE4 7F08B474 11800026 */  beqz  $t4, .Ljp7F08B510
/* 0BFFE8 7F08B478 00000000 */   nop
/* 0BFFEC 7F08B47C 0C001107 */  jal   viGetX
/* 0BFFF0 7F08B480 00000000 */   nop
/* 0BFFF4 7F08B484 0C00110B */  jal   viGetY
/* 0BFFF8 7F08B488 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BFFFC 7F08B48C 3C0D8003 */  lui   $t5, %hi(upper_text_buffer_index) # $t5, 0x8003
/* 0C0000 7F08B490 8DAD68E0 */  lw    $t5, %lo(upper_text_buffer_index)($t5)
/* 0C0004 7F08B494 3C188004 */  lui   $t8, %hi(ptrFontZurichBoldChars) # $t8, 0x8004
/* 0C0008 7F08B498 3C198004 */  lui   $t9, %hi(ptrFontZurichBold) # $t9, 0x8004
/* 0C000C 7F08B49C 000D7080 */  sll   $t6, $t5, 2
/* 0C0010 7F08B4A0 01CD7021 */  addu  $t6, $t6, $t5
/* 0C0014 7F08B4A4 000E7080 */  sll   $t6, $t6, 2
/* 0C0018 7F08B4A8 01CD7023 */  subu  $t6, $t6, $t5
/* 0C001C 7F08B4AC 8F390EE4 */  lw    $t9, %lo(ptrFontZurichBold)($t9)
/* 0C0020 7F08B4B0 8F180EE8 */  lw    $t8, %lo(ptrFontZurichBoldChars)($t8)
/* 0C0024 7F08B4B4 87AA0048 */  lh    $t2, 0x48($sp)
/* 0C0028 7F08B4B8 000E70C0 */  sll   $t6, $t6, 3
/* 0C002C 7F08B4BC 3C0F8008 */  lui   $t7, %hi(stringbuffer_top) # $t7, 0x8008
/* 0C0030 7F08B4C0 3C096464 */  lui   $t1, (0x646464FF >> 16) # lui $t1, 0x6464
/* 0C0034 7F08B4C4 352964FF */  ori   $t1, (0x646464FF & 0xFFFF) # ori $t1, $t1, 0x64ff
/* 0C0038 7F08B4C8 25EF9CE0 */  addiu $t7, %lo(stringbuffer_top) # addiu $t7, $t7, -0x6320
/* 0C003C 7F08B4CC 2408FFFF */  li    $t0, -1
/* 0C0040 7F08B4D0 01CD7023 */  subu  $t6, $t6, $t5
/* 0C0044 7F08B4D4 01CF3821 */  addu  $a3, $t6, $t7
/* 0C0048 7F08B4D8 AFA80018 */  sw    $t0, 0x18($sp)
/* 0C004C 7F08B4DC AFA9001C */  sw    $t1, 0x1c($sp)
/* 0C0050 7F08B4E0 02002025 */  move  $a0, $s0
/* 0C0054 7F08B4E4 27A500E4 */  addiu $a1, $sp, 0xe4
/* 0C0058 7F08B4E8 27A600E0 */  addiu $a2, $sp, 0xe0
/* 0C005C 7F08B4EC AFA20024 */  sw    $v0, 0x24($sp)
/* 0C0060 7F08B4F0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0C0064 7F08B4F4 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0C0068 7F08B4F8 AFB90014 */  sw    $t9, 0x14($sp)
/* 0C006C 7F08B4FC AFB80010 */  sw    $t8, 0x10($sp)
/* 0C0070 7F08B500 0FC2BCA7 */  jal   textRenderGlow
/* 0C0074 7F08B504 AFAA0020 */   sw    $t2, 0x20($sp)
/* 0C0078 7F08B508 10000022 */  b     .Ljp7F08B594
/* 0C007C 7F08B50C 00408025 */   move  $s0, $v0
.Ljp7F08B510:
/* 0C0080 7F08B510 0C001107 */  jal   viGetX
/* 0C0084 7F08B514 00000000 */   nop
/* 0C0088 7F08B518 0C00110B */  jal   viGetY
/* 0C008C 7F08B51C A7A20048 */   sh    $v0, 0x48($sp)
/* 0C0090 7F08B520 3C0B8003 */  lui   $t3, %hi(upper_text_buffer_index) # $t3, 0x8003
/* 0C0094 7F08B524 8D6B68E0 */  lw    $t3, %lo(upper_text_buffer_index)($t3)
/* 0C0098 7F08B528 3C0E8004 */  lui   $t6, %hi(ptrFontZurichBoldChars) # $t6, 0x8004
/* 0C009C 7F08B52C 3C0F8004 */  lui   $t7, %hi(ptrFontZurichBold) # $t7, 0x8004
/* 0C00A0 7F08B530 000B6080 */  sll   $t4, $t3, 2
/* 0C00A4 7F08B534 018B6021 */  addu  $t4, $t4, $t3
/* 0C00A8 7F08B538 000C6080 */  sll   $t4, $t4, 2
/* 0C00AC 7F08B53C 018B6023 */  subu  $t4, $t4, $t3
/* 0C00B0 7F08B540 8DEF0EE4 */  lw    $t7, %lo(ptrFontZurichBold)($t7)
/* 0C00B4 7F08B544 8DCE0EE8 */  lw    $t6, %lo(ptrFontZurichBoldChars)($t6)
/* 0C00B8 7F08B548 87B90048 */  lh    $t9, 0x48($sp)
/* 0C00BC 7F08B54C 000C60C0 */  sll   $t4, $t4, 3
/* 0C00C0 7F08B550 3C0D8008 */  lui   $t5, %hi(stringbuffer_top) # $t5, 0x8008
/* 0C00C4 7F08B554 25AD9CE0 */  addiu $t5, %lo(stringbuffer_top) # addiu $t5, $t5, -0x6320
/* 0C00C8 7F08B558 2418FFFF */  li    $t8, -1
/* 0C00CC 7F08B55C 018B6023 */  subu  $t4, $t4, $t3
/* 0C00D0 7F08B560 018D3821 */  addu  $a3, $t4, $t5
/* 0C00D4 7F08B564 AFB80018 */  sw    $t8, 0x18($sp)
/* 0C00D8 7F08B568 02002025 */  move  $a0, $s0
/* 0C00DC 7F08B56C 27A500E4 */  addiu $a1, $sp, 0xe4
/* 0C00E0 7F08B570 27A600E0 */  addiu $a2, $sp, 0xe0
/* 0C00E4 7F08B574 AFA20020 */  sw    $v0, 0x20($sp)
/* 0C00E8 7F08B578 AFA00024 */  sw    $zero, 0x24($sp)
/* 0C00EC 7F08B57C AFA00028 */  sw    $zero, 0x28($sp)
/* 0C00F0 7F08B580 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0C00F4 7F08B584 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0C00F8 7F08B588 0FC2B99B */  jal   textRender
/* 0C00FC 7F08B58C AFB9001C */   sw    $t9, 0x1c($sp)
/* 0C0100 7F08B590 00408025 */  move  $s0, $v0
.Ljp7F08B594:
/* 0C0104 7F08B594 0FC2B6A8 */  jal   combiner_bayer_lod_perspective
/* 0C0108 7F08B598 02002025 */   move  $a0, $s0
/* 0C010C 7F08B59C 100000F1 */  b     .Ljp7F08B964
/* 0C0110 7F08B5A0 00408025 */   move  $s0, $v0
.Ljp7F08B5A4:
/* 0C0114 7F08B5A4 0FC2469A */  jal   get_debug_testingmanpos_flag
/* 0C0118 7F08B5A8 00000000 */   nop
/* 0C011C 7F08B5AC 104000ED */  beqz  $v0, .Ljp7F08B964
/* 0C0120 7F08B5B0 3C028008 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8008
/* 0C0124 7F08B5B4 8C42A120 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0C0128 7F08B5B8 C4400498 */  lwc1  $f0, 0x498($v0)
/* 0C012C 7F08B5BC C44E04A0 */  lwc1  $f14, 0x4a0($v0)
/* 0C0130 7F08B5C0 0FC16BD4 */  jal   atan2f
/* 0C0134 7F08B5C4 46000307 */   neg.s $f12, $f0
/* 0C0138 7F08B5C8 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 0C013C 7F08B5CC 44812000 */  mtc1  $at, $f4
/* 0C0140 7F08B5D0 3C018005 */  lui   $at, %hi(D_800552BC) # $at, 0x8005
/* 0C0144 7F08B5D4 C42852EC */  lwc1  $f8, %lo(D_800552BC)($at)
/* 0C0148 7F08B5D8 46040182 */  mul.s $f6, $f0, $f4
/* 0C014C 7F08B5DC 3C0B8003 */  lui   $t3, %hi(D_800368B8) # $t3, 0x8003
/* 0C0150 7F08B5E0 256B68F0 */  addiu $t3, %lo(D_800368B8) # addiu $t3, $t3, 0x68f0
/* 0C0154 7F08B5E4 27AA004C */  addiu $t2, $sp, 0x4c
/* 0C0158 7F08B5E8 3C0F8008 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8008
/* 0C015C 7F08B5EC 46083283 */  div.s $f10, $f6, $f8
/* 0C0160 7F08B5F0 4600540D */  trunc.w.s $f16, $f10
/* 0C0164 7F08B5F4 44098000 */  mfc1  $t1, $f16
/* 0C0168 7F08B5F8 00000000 */  nop
/* 0C016C 7F08B5FC AFA90068 */  sw    $t1, 0x68($sp)
/* 0C0170 7F08B600 8D610000 */  lw    $at, ($t3)
/* 0C0174 7F08B604 8D6E0004 */  lw    $t6, 4($t3)
/* 0C0178 7F08B608 AD410000 */  sw    $at, ($t2)
/* 0C017C 7F08B60C 8D610008 */  lw    $at, 8($t3)
/* 0C0180 7F08B610 AD4E0004 */  sw    $t6, 4($t2)
/* 0C0184 7F08B614 8D6E000C */  lw    $t6, 0xc($t3)
/* 0C0188 7F08B618 AD410008 */  sw    $at, 8($t2)
/* 0C018C 7F08B61C 8D610010 */  lw    $at, 0x10($t3)
/* 0C0190 7F08B620 AD4E000C */  sw    $t6, 0xc($t2)
/* 0C0194 7F08B624 8D6E0014 */  lw    $t6, 0x14($t3)
/* 0C0198 7F08B628 AD410010 */  sw    $at, 0x10($t2)
/* 0C019C 7F08B62C 9961001A */  lwr   $at, 0x1a($t3)
/* 0C01A0 7F08B630 AD4E0014 */  sw    $t6, 0x14($t2)
/* 0C01A4 7F08B634 B941001A */  swr   $at, 0x1a($t2)
/* 0C01A8 7F08B638 8DEFA120 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0C01AC 7F08B63C 8DF80488 */  lw    $t8, 0x488($t7)
/* 0C01B0 7F08B640 0FC2DA64 */  jal   bgDebPrintROOMID
/* 0C01B4 7F08B644 93040003 */   lbu   $a0, 3($t8)
/* 0C01B8 7F08B648 3C058005 */  lui   $a1, %hi(a8s) # $a1, 0x8005
/* 0C01BC 7F08B64C 24A54FF0 */  addiu $a1, %lo(a8s) # addiu $a1, $a1, 0x4ff0
/* 0C01C0 7F08B650 27A400C4 */  addiu $a0, $sp, 0xc4
/* 0C01C4 7F08B654 0C002B29 */  jal   sprintf
/* 0C01C8 7F08B658 00403025 */   move  $a2, $v0
/* 0C01CC 7F08B65C 3C198008 */  lui   $t9, %hi(g_CurrentPlayer) # $t9, 0x8008
/* 0C01D0 7F08B660 8F39A120 */  lw    $t9, %lo(g_CurrentPlayer)($t9)
/* 0C01D4 7F08B664 3C058005 */  lui   $a1, %hi(aX4_0f) # $a1, 0x8005
/* 0C01D8 7F08B668 24A54FF4 */  addiu $a1, %lo(aX4_0f) # addiu $a1, $a1, 0x4ff4
/* 0C01DC 7F08B66C C732048C */  lwc1  $f18, 0x48c($t9)
/* 0C01E0 7F08B670 27A400B4 */  addiu $a0, $sp, 0xb4
/* 0C01E4 7F08B674 46009121 */  cvt.d.s $f4, $f18
/* 0C01E8 7F08B678 44072000 */  mfc1  $a3, $f4
/* 0C01EC 7F08B67C 44062800 */  mfc1  $a2, $f5
/* 0C01F0 7F08B680 0C002B29 */  jal   sprintf
/* 0C01F4 7F08B684 00000000 */   nop
/* 0C01F8 7F08B688 3C088008 */  lui   $t0, %hi(g_CurrentPlayer) # $t0, 0x8008
/* 0C01FC 7F08B68C 8D08A120 */  lw    $t0, %lo(g_CurrentPlayer)($t0)
/* 0C0200 7F08B690 3C058005 */  lui   $a1, %hi(aY4_0f) # $a1, 0x8005
/* 0C0204 7F08B694 24A54FFC */  addiu $a1, %lo(aY4_0f) # addiu $a1, $a1, 0x4ffc
/* 0C0208 7F08B698 C5060490 */  lwc1  $f6, 0x490($t0)
/* 0C020C 7F08B69C 27A400A4 */  addiu $a0, $sp, 0xa4
/* 0C0210 7F08B6A0 46003221 */  cvt.d.s $f8, $f6
/* 0C0214 7F08B6A4 44074000 */  mfc1  $a3, $f8
/* 0C0218 7F08B6A8 44064800 */  mfc1  $a2, $f9
/* 0C021C 7F08B6AC 0C002B29 */  jal   sprintf
/* 0C0220 7F08B6B0 00000000 */   nop
/* 0C0224 7F08B6B4 3C098008 */  lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8008
/* 0C0228 7F08B6B8 8D29A120 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0C022C 7F08B6BC 3C058005 */  lui   $a1, %hi(aZ4_0f) # $a1, 0x8005
/* 0C0230 7F08B6C0 24A55004 */  addiu $a1, %lo(aZ4_0f) # addiu $a1, $a1, 0x5004
/* 0C0234 7F08B6C4 C52A0494 */  lwc1  $f10, 0x494($t1)
/* 0C0238 7F08B6C8 27A40094 */  addiu $a0, $sp, 0x94
/* 0C023C 7F08B6CC 46005421 */  cvt.d.s $f16, $f10
/* 0C0240 7F08B6D0 44078000 */  mfc1  $a3, $f16
/* 0C0244 7F08B6D4 44068800 */  mfc1  $a2, $f17
/* 0C0248 7F08B6D8 0C002B29 */  jal   sprintf
/* 0C024C 7F08B6DC 00000000 */   nop
/* 0C0250 7F08B6E0 8FA70068 */  lw    $a3, 0x68($sp)
/* 0C0254 7F08B6E4 2401002D */  li    $at, 45
/* 0C0258 7F08B6E8 3C058005 */  lui   $a1, %hi(aS3d) # $a1, 0x8005
/* 0C025C 7F08B6EC 24ED0016 */  addiu $t5, $a3, 0x16
/* 0C0260 7F08B6F0 01A1001A */  div   $zero, $t5, $at
/* 0C0264 7F08B6F4 00006012 */  mflo  $t4
/* 0C0268 7F08B6F8 000C5080 */  sll   $t2, $t4, 2
/* 0C026C 7F08B6FC 014C5023 */  subu  $t2, $t2, $t4
/* 0C0270 7F08B700 27AB004C */  addiu $t3, $sp, 0x4c
/* 0C0274 7F08B704 014B3021 */  addu  $a2, $t2, $t3
/* 0C0278 7F08B708 24A5500C */  addiu $a1, %lo(aS3d) # addiu $a1, $a1, 0x500c
/* 0C027C 7F08B70C 0C002B29 */  jal   sprintf
/* 0C0280 7F08B710 27A40084 */   addiu $a0, $sp, 0x84
/* 0C0284 7F08B714 0C001145 */  jal   viGetViewLeft
/* 0C0288 7F08B718 00000000 */   nop
/* 0C028C 7F08B71C 244E0011 */  addiu $t6, $v0, 0x11
/* 0C0290 7F08B720 0C001149 */  jal   viGetViewTop
/* 0C0294 7F08B724 AFAE0080 */   sw    $t6, 0x80($sp)
/* 0C0298 7F08B728 24460011 */  addiu $a2, $v0, 0x11
/* 0C029C 7F08B72C 24CF000A */  addiu $t7, $a2, 0xa
/* 0C02A0 7F08B730 AFAF0074 */  sw    $t7, 0x74($sp)
/* 0C02A4 7F08B734 AFA6007C */  sw    $a2, 0x7c($sp)
/* 0C02A8 7F08B738 0FC2B652 */  jal   microcode_constructor
/* 0C02AC 7F08B73C 02002025 */   move  $a0, $s0
/* 0C02B0 7F08B740 0C001107 */  jal   viGetX
/* 0C02B4 7F08B744 00408025 */   move  $s0, $v0
/* 0C02B8 7F08B748 8FB80074 */  lw    $t8, 0x74($sp)
/* 0C02BC 7F08B74C 24080064 */  li    $t0, 100
/* 0C02C0 7F08B750 AFA80014 */  sw    $t0, 0x14($sp)
/* 0C02C4 7F08B754 27190001 */  addiu $t9, $t8, 1
/* 0C02C8 7F08B758 AFB90010 */  sw    $t9, 0x10($sp)
/* 0C02CC 7F08B75C 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0C02D0 7F08B760 02002025 */  move  $a0, $s0
/* 0C02D4 7F08B764 00002825 */  move  $a1, $zero
/* 0C02D8 7F08B768 0FC2B6F1 */  jal   microcode_constructor_related_to_menus
/* 0C02DC 7F08B76C 00403825 */   move  $a3, $v0
/* 0C02E0 7F08B770 0C001107 */  jal   viGetX
/* 0C02E4 7F08B774 00408025 */   move  $s0, $v0
/* 0C02E8 7F08B778 0C00110B */  jal   viGetY
/* 0C02EC 7F08B77C A7A20048 */   sh    $v0, 0x48($sp)
/* 0C02F0 7F08B780 3C098004 */  lui   $t1, %hi(ptrFontBankGothicChars) # $t1, 0x8004
/* 0C02F4 7F08B784 3C0D8004 */  lui   $t5, %hi(ptrFontBankGothic) # $t5, 0x8004
/* 0C02F8 7F08B788 8DAD0EDC */  lw    $t5, %lo(ptrFontBankGothic)($t5)
/* 0C02FC 7F08B78C 8D290EE0 */  lw    $t1, %lo(ptrFontBankGothicChars)($t1)
/* 0C0300 7F08B790 87AA0048 */  lh    $t2, 0x48($sp)
/* 0C0304 7F08B794 240CFFFF */  li    $t4, -1
/* 0C0308 7F08B798 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0C030C 7F08B79C 02002025 */  move  $a0, $s0
/* 0C0310 7F08B7A0 27A50080 */  addiu $a1, $sp, 0x80
/* 0C0314 7F08B7A4 27A6007C */  addiu $a2, $sp, 0x7c
/* 0C0318 7F08B7A8 27A700C4 */  addiu $a3, $sp, 0xc4
/* 0C031C 7F08B7AC AFA20020 */  sw    $v0, 0x20($sp)
/* 0C0320 7F08B7B0 AFA00024 */  sw    $zero, 0x24($sp)
/* 0C0324 7F08B7B4 AFA00028 */  sw    $zero, 0x28($sp)
/* 0C0328 7F08B7B8 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0C032C 7F08B7BC AFA90010 */  sw    $t1, 0x10($sp)
/* 0C0330 7F08B7C0 0FC2B99B */  jal   textRender
/* 0C0334 7F08B7C4 AFAA001C */   sw    $t2, 0x1c($sp)
/* 0C0338 7F08B7C8 0C001145 */  jal   viGetViewLeft
/* 0C033C 7F08B7CC 00408025 */   move  $s0, $v0
/* 0C0340 7F08B7D0 244B0057 */  addiu $t3, $v0, 0x57
/* 0C0344 7F08B7D4 0C001107 */  jal   viGetX
/* 0C0348 7F08B7D8 AFAB0080 */   sw    $t3, 0x80($sp)
/* 0C034C 7F08B7DC 0C00110B */  jal   viGetY
/* 0C0350 7F08B7E0 A7A20048 */   sh    $v0, 0x48($sp)
/* 0C0354 7F08B7E4 3C0E8004 */  lui   $t6, %hi(ptrFontBankGothicChars) # $t6, 0x8004
/* 0C0358 7F08B7E8 3C0F8004 */  lui   $t7, %hi(ptrFontBankGothic) # $t7, 0x8004
/* 0C035C 7F08B7EC 8DEF0EDC */  lw    $t7, %lo(ptrFontBankGothic)($t7)
/* 0C0360 7F08B7F0 8DCE0EE0 */  lw    $t6, %lo(ptrFontBankGothicChars)($t6)
/* 0C0364 7F08B7F4 87B90048 */  lh    $t9, 0x48($sp)
/* 0C0368 7F08B7F8 2418FFFF */  li    $t8, -1
/* 0C036C 7F08B7FC AFB80018 */  sw    $t8, 0x18($sp)
/* 0C0370 7F08B800 02002025 */  move  $a0, $s0
/* 0C0374 7F08B804 27A50080 */  addiu $a1, $sp, 0x80
/* 0C0378 7F08B808 27A6007C */  addiu $a2, $sp, 0x7c
/* 0C037C 7F08B80C 27A700B4 */  addiu $a3, $sp, 0xb4
/* 0C0380 7F08B810 AFA20020 */  sw    $v0, 0x20($sp)
/* 0C0384 7F08B814 AFA00024 */  sw    $zero, 0x24($sp)
/* 0C0388 7F08B818 AFA00028 */  sw    $zero, 0x28($sp)
/* 0C038C 7F08B81C AFAF0014 */  sw    $t7, 0x14($sp)
/* 0C0390 7F08B820 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0C0394 7F08B824 0FC2B99B */  jal   textRender
/* 0C0398 7F08B828 AFB9001C */   sw    $t9, 0x1c($sp)
/* 0C039C 7F08B82C 0C001145 */  jal   viGetViewLeft
/* 0C03A0 7F08B830 00408025 */   move  $s0, $v0
/* 0C03A4 7F08B834 2448008D */  addiu $t0, $v0, 0x8d
/* 0C03A8 7F08B838 0C001107 */  jal   viGetX
/* 0C03AC 7F08B83C AFA80080 */   sw    $t0, 0x80($sp)
/* 0C03B0 7F08B840 0C00110B */  jal   viGetY
/* 0C03B4 7F08B844 A7A20048 */   sh    $v0, 0x48($sp)
/* 0C03B8 7F08B848 3C098004 */  lui   $t1, %hi(ptrFontBankGothicChars) # $t1, 0x8004
/* 0C03BC 7F08B84C 3C0D8004 */  lui   $t5, %hi(ptrFontBankGothic) # $t5, 0x8004
/* 0C03C0 7F08B850 8DAD0EDC */  lw    $t5, %lo(ptrFontBankGothic)($t5)
/* 0C03C4 7F08B854 8D290EE0 */  lw    $t1, %lo(ptrFontBankGothicChars)($t1)
/* 0C03C8 7F08B858 87AA0048 */  lh    $t2, 0x48($sp)
/* 0C03CC 7F08B85C 240CFFFF */  li    $t4, -1
/* 0C03D0 7F08B860 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0C03D4 7F08B864 02002025 */  move  $a0, $s0
/* 0C03D8 7F08B868 27A50080 */  addiu $a1, $sp, 0x80
/* 0C03DC 7F08B86C 27A6007C */  addiu $a2, $sp, 0x7c
/* 0C03E0 7F08B870 27A700A4 */  addiu $a3, $sp, 0xa4
/* 0C03E4 7F08B874 AFA20020 */  sw    $v0, 0x20($sp)
/* 0C03E8 7F08B878 AFA00024 */  sw    $zero, 0x24($sp)
/* 0C03EC 7F08B87C AFA00028 */  sw    $zero, 0x28($sp)
/* 0C03F0 7F08B880 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0C03F4 7F08B884 AFA90010 */  sw    $t1, 0x10($sp)
/* 0C03F8 7F08B888 0FC2B99B */  jal   textRender
/* 0C03FC 7F08B88C AFAA001C */   sw    $t2, 0x1c($sp)
/* 0C0400 7F08B890 0C001145 */  jal   viGetViewLeft
/* 0C0404 7F08B894 00408025 */   move  $s0, $v0
/* 0C0408 7F08B898 244B00C3 */  addiu $t3, $v0, 0xc3
/* 0C040C 7F08B89C 0C001107 */  jal   viGetX
/* 0C0410 7F08B8A0 AFAB0080 */   sw    $t3, 0x80($sp)
/* 0C0414 7F08B8A4 0C00110B */  jal   viGetY
/* 0C0418 7F08B8A8 A7A20048 */   sh    $v0, 0x48($sp)
/* 0C041C 7F08B8AC 3C0E8004 */  lui   $t6, %hi(ptrFontBankGothicChars) # $t6, 0x8004
/* 0C0420 7F08B8B0 3C0F8004 */  lui   $t7, %hi(ptrFontBankGothic) # $t7, 0x8004
/* 0C0424 7F08B8B4 8DEF0EDC */  lw    $t7, %lo(ptrFontBankGothic)($t7)
/* 0C0428 7F08B8B8 8DCE0EE0 */  lw    $t6, %lo(ptrFontBankGothicChars)($t6)
/* 0C042C 7F08B8BC 87B90048 */  lh    $t9, 0x48($sp)
/* 0C0430 7F08B8C0 2418FFFF */  li    $t8, -1
/* 0C0434 7F08B8C4 AFB80018 */  sw    $t8, 0x18($sp)
/* 0C0438 7F08B8C8 02002025 */  move  $a0, $s0
/* 0C043C 7F08B8CC 27A50080 */  addiu $a1, $sp, 0x80
/* 0C0440 7F08B8D0 27A6007C */  addiu $a2, $sp, 0x7c
/* 0C0444 7F08B8D4 27A70094 */  addiu $a3, $sp, 0x94
/* 0C0448 7F08B8D8 AFA20020 */  sw    $v0, 0x20($sp)
/* 0C044C 7F08B8DC AFA00024 */  sw    $zero, 0x24($sp)
/* 0C0450 7F08B8E0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0C0454 7F08B8E4 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0C0458 7F08B8E8 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0C045C 7F08B8EC 0FC2B99B */  jal   textRender
/* 0C0460 7F08B8F0 AFB9001C */   sw    $t9, 0x1c($sp)
/* 0C0464 7F08B8F4 0C001145 */  jal   viGetViewLeft
/* 0C0468 7F08B8F8 00408025 */   move  $s0, $v0
/* 0C046C 7F08B8FC 244800F9 */  addiu $t0, $v0, 0xf9
/* 0C0470 7F08B900 0C001107 */  jal   viGetX
/* 0C0474 7F08B904 AFA80080 */   sw    $t0, 0x80($sp)
/* 0C0478 7F08B908 0C00110B */  jal   viGetY
/* 0C047C 7F08B90C A7A20048 */   sh    $v0, 0x48($sp)
/* 0C0480 7F08B910 3C098004 */  lui   $t1, %hi(ptrFontBankGothicChars) # $t1, 0x8004
/* 0C0484 7F08B914 3C0D8004 */  lui   $t5, %hi(ptrFontBankGothic) # $t5, 0x8004
/* 0C0488 7F08B918 8DAD0EDC */  lw    $t5, %lo(ptrFontBankGothic)($t5)
/* 0C048C 7F08B91C 8D290EE0 */  lw    $t1, %lo(ptrFontBankGothicChars)($t1)
/* 0C0490 7F08B920 87AA0048 */  lh    $t2, 0x48($sp)
/* 0C0494 7F08B924 240CFFFF */  li    $t4, -1
/* 0C0498 7F08B928 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0C049C 7F08B92C 02002025 */  move  $a0, $s0
/* 0C04A0 7F08B930 27A50080 */  addiu $a1, $sp, 0x80
/* 0C04A4 7F08B934 27A6007C */  addiu $a2, $sp, 0x7c
/* 0C04A8 7F08B938 27A70084 */  addiu $a3, $sp, 0x84
/* 0C04AC 7F08B93C AFA20020 */  sw    $v0, 0x20($sp)
/* 0C04B0 7F08B940 AFA00024 */  sw    $zero, 0x24($sp)
/* 0C04B4 7F08B944 AFA00028 */  sw    $zero, 0x28($sp)
/* 0C04B8 7F08B948 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0C04BC 7F08B94C AFA90010 */  sw    $t1, 0x10($sp)
/* 0C04C0 7F08B950 0FC2B99B */  jal   textRender
/* 0C04C4 7F08B954 AFAA001C */   sw    $t2, 0x1c($sp)
/* 0C04C8 7F08B958 0FC2B6A8 */  jal   combiner_bayer_lod_perspective
/* 0C04CC 7F08B95C 00402025 */   move  $a0, $v0
/* 0C04D0 7F08B960 00408025 */  move  $s0, $v0
.Ljp7F08B964:
/* 0C04D4 7F08B964 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0C04D8 7F08B968 02001025 */  move  $v0, $s0
/* 0C04DC 7F08B96C 8FB00038 */  lw    $s0, 0x38($sp)
/* 0C04E0 7F08B970 03E00008 */  jr    $ra
/* 0C04E4 7F08B974 27BD00E8 */   addiu $sp, $sp, 0xe8
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_8004AE90
.word 0x40490fdb /*3.1415927*/

.text
glabel sub_GAME_7F08AAE8
/* 0BD720 7F08AD30 3C0E8003 */  lui   $t6, %hi(g_UpperTextDisplayFlag) # $t6, 0x8003
/* 0BD724 7F08AD34 8DCE1DFC */  lw    $t6, %lo(g_UpperTextDisplayFlag)($t6)
/* 0BD728 7F08AD38 27BDFF18 */  addiu $sp, $sp, -0xe8
/* 0BD72C 7F08AD3C AFB00038 */  sw    $s0, 0x38($sp)
/* 0BD730 7F08AD40 00808025 */  move  $s0, $a0
/* 0BD734 7F08AD44 15C000B2 */  bnez  $t6, .L7F08B010
/* 0BD738 7F08AD48 AFBF003C */   sw    $ra, 0x3c($sp)
/* 0BD73C 7F08AD4C 3C0F8003 */  lui   $t7, %hi(upper_text_window_timer) # $t7, 0x8003
/* 0BD740 7F08AD50 8DEF1DF8 */  lw    $t7, %lo(upper_text_window_timer)($t7)
/* 0BD744 7F08AD54 3C188003 */  lui   $t8, %hi(upper_text_buffer_index) # $t8, 0x8003
/* 0BD748 7F08AD58 05E000AD */  bltz  $t7, .L7F08B010
/* 0BD74C 7F08AD5C 00000000 */   nop   
/* 0BD750 7F08AD60 8F181DF0 */  lw    $t8, %lo(upper_text_buffer_index)($t8)
/* 0BD754 7F08AD64 3C088007 */  lui   $t0, %hi(dword_CODE_bss_80079DC8)
/* 0BD758 7F08AD68 3C098007 */  lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8007
/* 0BD75C 7F08AD6C 0018C880 */  sll   $t9, $t8, 2
/* 0BD760 7F08AD70 0338C821 */  addu  $t9, $t9, $t8
/* 0BD764 7F08AD74 0019C880 */  sll   $t9, $t9, 2
/* 0BD768 7F08AD78 0338C823 */  subu  $t9, $t9, $t8
/* 0BD76C 7F08AD7C 0019C8C0 */  sll   $t9, $t9, 3
/* 0BD770 7F08AD80 0338C823 */  subu  $t9, $t9, $t8
/* 0BD774 7F08AD84 01194021 */  addu  $t0, $t0, $t9
/* 0BD778 7F08AD88 910887A8 */  lbu   $t0, %lo(dword_CODE_bss_80079DC8)($t0)
/* 0BD77C 7F08AD8C 110000A0 */  beqz  $t0, .L7F08B010
/* 0BD780 7F08AD90 00000000 */   nop   
/* 0BD784 7F08AD94 8D298BC0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0BD788 7F08AD98 8D2A29BC */  lw    $t2, 0x29bc($t1)
/* 0BD78C 7F08AD9C 1540009C */  bnez  $t2, .L7F08B010
/* 0BD790 7F08ADA0 00000000 */   nop   
/* 0BD794 7F08ADA4 0FC2B016 */  jal   microcode_constructor
/* 0BD798 7F08ADA8 00000000 */   nop   
/* 0BD79C 7F08ADAC 3C0B8003 */  lui   $t3, %hi(upper_text_buffer_index) # $t3, 0x8003
/* 0BD7A0 7F08ADB0 8D6B1DF0 */  lw    $t3, %lo(upper_text_buffer_index)($t3)
/* 0BD7A4 7F08ADB4 3C0E8004 */  lui   $t6, %hi(ptrFontZurichBold) # $t6, 0x8004
/* 0BD7A8 7F08ADB8 8DCEAB04 */  lw    $t6, %lo(ptrFontZurichBold)($t6)
/* 0BD7AC 7F08ADBC 000B6080 */  sll   $t4, $t3, 2
/* 0BD7B0 7F08ADC0 018B6021 */  addu  $t4, $t4, $t3
/* 0BD7B4 7F08ADC4 000C6080 */  sll   $t4, $t4, 2
/* 0BD7B8 7F08ADC8 018B6023 */  subu  $t4, $t4, $t3
/* 0BD7BC 7F08ADCC 000C60C0 */  sll   $t4, $t4, 3
/* 0BD7C0 7F08ADD0 3C0D8007 */  lui   $t5, %hi(dword_CODE_bss_80079DC8) # $t5, 0x8007
/* 0BD7C4 7F08ADD4 25AD87A8 */  addiu $t5, %lo(dword_CODE_bss_80079DC8) # addiu $t5, $t5, -0x7858
/* 0BD7C8 7F08ADD8 3C078004 */  lui   $a3, %hi(ptrFontZurichBoldChars) # $a3, 0x8004
/* 0BD7CC 7F08ADDC 018B6023 */  subu  $t4, $t4, $t3
/* 0BD7D0 7F08ADE0 00408025 */  move  $s0, $v0
/* 0BD7D4 7F08ADE4 AFA000D4 */  sw    $zero, 0xd4($sp)
/* 0BD7D8 7F08ADE8 AFA000D8 */  sw    $zero, 0xd8($sp)
/* 0BD7DC 7F08ADEC 018D3021 */  addu  $a2, $t4, $t5
/* 0BD7E0 7F08ADF0 8CE7AB08 */  lw    $a3, %lo(ptrFontZurichBoldChars)($a3)
/* 0BD7E4 7F08ADF4 27A400D8 */  addiu $a0, $sp, 0xd8
/* 0BD7E8 7F08ADF8 27A500D4 */  addiu $a1, $sp, 0xd4
/* 0BD7EC 7F08ADFC AFA00014 */  sw    $zero, 0x14($sp)
/* 0BD7F0 7F08AE00 0FC2B713 */  jal   textMeasure
/* 0BD7F4 7F08AE04 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0BD7F8 7F08AE08 3C0F8003 */  lui   $t7, %hi(camera_8003642C) # $t7, 0x8003
/* 0BD7FC 7F08AE0C 8DEF197C */  lw    $t7, %lo(camera_8003642C)($t7)
/* 0BD800 7F08AE10 11E0001B */  beqz  $t7, .L7F08AE80
/* 0BD804 7F08AE14 00000000 */   nop   
/* 0BD808 7F08AE18 0C000FD9 */  jal   viGetViewLeft
/* 0BD80C 7F08AE1C 00000000 */   nop   
/* 0BD810 7F08AE20 24580046 */  addiu $t8, $v0, 0x46
/* 0BD814 7F08AE24 0C000FDD */  jal   viGetViewTop
/* 0BD818 7F08AE28 AFB800E4 */   sw    $t8, 0xe4($sp)
/* 0BD81C 7F08AE2C 00401825 */  move  $v1, $v0
/* 0BD820 7F08AE30 24630020 */  addiu $v1, $v1, 0x20
/* 0BD824 7F08AE34 2404000B */  li    $a0, 11
/* 0BD828 7F08AE38 0064001A */  div   $zero, $v1, $a0
/* 0BD82C 7F08AE3C 14800002 */  bnez  $a0, .L7F08AE48
/* 0BD830 7F08AE40 00000000 */   nop   
/* 0BD834 7F08AE44 0007000D */  break 7
.L7F08AE48:
/* 0BD838 7F08AE48 2401FFFF */  li    $at, -1
/* 0BD83C 7F08AE4C 14810004 */  bne   $a0, $at, .L7F08AE60
/* 0BD840 7F08AE50 3C018000 */   lui   $at, 0x8000
/* 0BD844 7F08AE54 14610002 */  bne   $v1, $at, .L7F08AE60
/* 0BD848 7F08AE58 00000000 */   nop   
/* 0BD84C 7F08AE5C 0006000D */  break 6
.L7F08AE60:
/* 0BD850 7F08AE60 00001812 */  mflo  $v1
/* 0BD854 7F08AE64 00000000 */  nop   
/* 0BD858 7F08AE68 00000000 */  nop   
/* 0BD85C 7F08AE6C 00640019 */  multu $v1, $a0
/* 0BD860 7F08AE70 00001812 */  mflo  $v1
/* 0BD864 7F08AE74 2463FFFE */  addiu $v1, $v1, -2
/* 0BD868 7F08AE78 10000008 */  b     .L7F08AE9C
/* 0BD86C 7F08AE7C 8FA800D8 */   lw    $t0, 0xd8($sp)
.L7F08AE80:
/* 0BD870 7F08AE80 0C000FD9 */  jal   viGetViewLeft
/* 0BD874 7F08AE84 00000000 */   nop   
/* 0BD878 7F08AE88 2459001E */  addiu $t9, $v0, 0x1e
/* 0BD87C 7F08AE8C 0C000FDD */  jal   viGetViewTop
/* 0BD880 7F08AE90 AFB900E4 */   sw    $t9, 0xe4($sp)
/* 0BD884 7F08AE94 24430010 */  addiu $v1, $v0, 0x10
/* 0BD888 7F08AE98 8FA800D8 */  lw    $t0, 0xd8($sp)
.L7F08AE9C:
/* 0BD88C 7F08AE9C AFA300E0 */  sw    $v1, 0xe0($sp)
/* 0BD890 7F08AEA0 00684821 */  addu  $t1, $v1, $t0
/* 0BD894 7F08AEA4 0C000F9B */  jal   viGetX
/* 0BD898 7F08AEA8 AFA900DC */   sw    $t1, 0xdc($sp)
/* 0BD89C 7F08AEAC 8FA300E0 */  lw    $v1, 0xe0($sp)
/* 0BD8A0 7F08AEB0 8FAA00DC */  lw    $t2, 0xdc($sp)
/* 0BD8A4 7F08AEB4 240B0064 */  li    $t3, 100
/* 0BD8A8 7F08AEB8 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0BD8AC 7F08AEBC 02002025 */  move  $a0, $s0
/* 0BD8B0 7F08AEC0 00002825 */  move  $a1, $zero
/* 0BD8B4 7F08AEC4 00403825 */  move  $a3, $v0
/* 0BD8B8 7F08AEC8 2466FFFE */  addiu $a2, $v1, -2
/* 0BD8BC 7F08AECC 0FC2B0B5 */  jal   microcode_constructor_related_to_menus
/* 0BD8C0 7F08AED0 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0BD8C4 7F08AED4 3C0C8004 */  lui   $t4, %hi(j_text_trigger) # $t4, 0x8004
/* 0BD8C8 7F08AED8 8D8C1150 */  lw    $t4, %lo(j_text_trigger)($t4)
/* 0BD8CC 7F08AEDC 00408025 */  move  $s0, $v0
/* 0BD8D0 7F08AEE0 11800026 */  beqz  $t4, .L7F08AF7C
/* 0BD8D4 7F08AEE4 00000000 */   nop   
/* 0BD8D8 7F08AEE8 0C000F9B */  jal   viGetX
/* 0BD8DC 7F08AEEC 00000000 */   nop   
/* 0BD8E0 7F08AEF0 0C000F9F */  jal   viGetY
/* 0BD8E4 7F08AEF4 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BD8E8 7F08AEF8 3C0D8003 */  lui   $t5, %hi(upper_text_buffer_index) # $t5, 0x8003
/* 0BD8EC 7F08AEFC 8DAD1DF0 */  lw    $t5, %lo(upper_text_buffer_index)($t5)
/* 0BD8F0 7F08AF00 3C188004 */  lui   $t8, %hi(ptrFontZurichBoldChars) # $t8, 0x8004
/* 0BD8F4 7F08AF04 3C198004 */  lui   $t9, %hi(ptrFontZurichBold) # $t9, 0x8004
/* 0BD8F8 7F08AF08 000D7080 */  sll   $t6, $t5, 2
/* 0BD8FC 7F08AF0C 01CD7021 */  addu  $t6, $t6, $t5
/* 0BD900 7F08AF10 000E7080 */  sll   $t6, $t6, 2
/* 0BD904 7F08AF14 01CD7023 */  subu  $t6, $t6, $t5
/* 0BD908 7F08AF18 8F39AB04 */  lw    $t9, %lo(ptrFontZurichBold)($t9)
/* 0BD90C 7F08AF1C 8F18AB08 */  lw    $t8, %lo(ptrFontZurichBoldChars)($t8)
/* 0BD910 7F08AF20 87AA0048 */  lh    $t2, 0x48($sp)
/* 0BD914 7F08AF24 000E70C0 */  sll   $t6, $t6, 3
/* 0BD918 7F08AF28 3C0F8007 */  lui   $t7, %hi(dword_CODE_bss_80079DC8) # $t7, 0x8007
/* 0BD91C 7F08AF2C 3C096464 */  lui   $t1, (0x646464FF >> 16) # lui $t1, 0x6464
/* 0BD920 7F08AF30 352964FF */  ori   $t1, (0x646464FF & 0xFFFF) # ori $t1, $t1, 0x64ff
/* 0BD924 7F08AF34 25EF87A8 */  addiu $t7, %lo(dword_CODE_bss_80079DC8) # addiu $t7, $t7, -0x7858
/* 0BD928 7F08AF38 2408FFFF */  li    $t0, -1
/* 0BD92C 7F08AF3C 01CD7023 */  subu  $t6, $t6, $t5
/* 0BD930 7F08AF40 01CF3821 */  addu  $a3, $t6, $t7
/* 0BD934 7F08AF44 AFA80018 */  sw    $t0, 0x18($sp)
/* 0BD938 7F08AF48 AFA9001C */  sw    $t1, 0x1c($sp)
/* 0BD93C 7F08AF4C 02002025 */  move  $a0, $s0
/* 0BD940 7F08AF50 27A500E4 */  addiu $a1, $sp, 0xe4
/* 0BD944 7F08AF54 27A600E0 */  addiu $a2, $sp, 0xe0
/* 0BD948 7F08AF58 AFA20024 */  sw    $v0, 0x24($sp)
/* 0BD94C 7F08AF5C AFA00028 */  sw    $zero, 0x28($sp)
/* 0BD950 7F08AF60 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0BD954 7F08AF64 AFB90014 */  sw    $t9, 0x14($sp)
/* 0BD958 7F08AF68 AFB80010 */  sw    $t8, 0x10($sp)
/* 0BD95C 7F08AF6C 0FC2B66B */  jal   textRenderGlow
/* 0BD960 7F08AF70 AFAA0020 */   sw    $t2, 0x20($sp)
/* 0BD964 7F08AF74 10000022 */  b     .L7F08B000
/* 0BD968 7F08AF78 00408025 */   move  $s0, $v0
.L7F08AF7C:
/* 0BD96C 7F08AF7C 0C000F9B */  jal   viGetX
/* 0BD970 7F08AF80 00000000 */   nop   
/* 0BD974 7F08AF84 0C000F9F */  jal   viGetY
/* 0BD978 7F08AF88 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BD97C 7F08AF8C 3C0B8003 */  lui   $t3, %hi(upper_text_buffer_index) # $t3, 0x8003
/* 0BD980 7F08AF90 8D6B1DF0 */  lw    $t3, %lo(upper_text_buffer_index)($t3)
/* 0BD984 7F08AF94 3C0E8004 */  lui   $t6, %hi(ptrFontZurichBoldChars) # $t6, 0x8004
/* 0BD988 7F08AF98 3C0F8004 */  lui   $t7, %hi(ptrFontZurichBold) # $t7, 0x8004
/* 0BD98C 7F08AF9C 000B6080 */  sll   $t4, $t3, 2
/* 0BD990 7F08AFA0 018B6021 */  addu  $t4, $t4, $t3
/* 0BD994 7F08AFA4 000C6080 */  sll   $t4, $t4, 2
/* 0BD998 7F08AFA8 018B6023 */  subu  $t4, $t4, $t3
/* 0BD99C 7F08AFAC 8DEFAB04 */  lw    $t7, %lo(ptrFontZurichBold)($t7)
/* 0BD9A0 7F08AFB0 8DCEAB08 */  lw    $t6, %lo(ptrFontZurichBoldChars)($t6)
/* 0BD9A4 7F08AFB4 87B90048 */  lh    $t9, 0x48($sp)
/* 0BD9A8 7F08AFB8 000C60C0 */  sll   $t4, $t4, 3
/* 0BD9AC 7F08AFBC 3C0D8007 */  lui   $t5, %hi(dword_CODE_bss_80079DC8) # $t5, 0x8007
/* 0BD9B0 7F08AFC0 25AD87A8 */  addiu $t5, %lo(dword_CODE_bss_80079DC8) # addiu $t5, $t5, -0x7858
/* 0BD9B4 7F08AFC4 2418FFFF */  li    $t8, -1
/* 0BD9B8 7F08AFC8 018B6023 */  subu  $t4, $t4, $t3
/* 0BD9BC 7F08AFCC 018D3821 */  addu  $a3, $t4, $t5
/* 0BD9C0 7F08AFD0 AFB80018 */  sw    $t8, 0x18($sp)
/* 0BD9C4 7F08AFD4 02002025 */  move  $a0, $s0
/* 0BD9C8 7F08AFD8 27A500E4 */  addiu $a1, $sp, 0xe4
/* 0BD9CC 7F08AFDC 27A600E0 */  addiu $a2, $sp, 0xe0
/* 0BD9D0 7F08AFE0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BD9D4 7F08AFE4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BD9D8 7F08AFE8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0BD9DC 7F08AFEC AFAF0014 */  sw    $t7, 0x14($sp)
/* 0BD9E0 7F08AFF0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0BD9E4 7F08AFF4 0FC2B35F */  jal   textRender
/* 0BD9E8 7F08AFF8 AFB9001C */   sw    $t9, 0x1c($sp)
/* 0BD9EC 7F08AFFC 00408025 */  move  $s0, $v0
.L7F08B000:
/* 0BD9F0 7F08B000 0FC2B06C */  jal   combiner_bayer_lod_perspective
/* 0BD9F4 7F08B004 02002025 */   move  $a0, $s0
/* 0BD9F8 7F08B008 100000F1 */  b     .L7F08B3D0
/* 0BD9FC 7F08B00C 00408025 */   move  $s0, $v0
.L7F08B010:
/* 0BDA00 7F08B010 0FC2410E */  jal   get_debug_testingmanpos_flag
/* 0BDA04 7F08B014 00000000 */   nop   
/* 0BDA08 7F08B018 104000ED */  beqz  $v0, .L7F08B3D0
/* 0BDA0C 7F08B01C 3C028007 */   lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0BDA10 7F08B020 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0BDA14 7F08B024 C4400498 */  lwc1  $f0, 0x498($v0)
/* 0BDA18 7F08B028 C44E04A0 */  lwc1  $f14, 0x4a0($v0)
/* 0BDA1C 7F08B02C 0FC16BB8 */  jal   atan2f
/* 0BDA20 7F08B030 46000307 */   neg.s $f12, $f0
/* 0BDA24 7F08B034 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 0BDA28 7F08B038 44812000 */  mtc1  $at, $f4
/* 0BDA2C 7F08B03C 3C018005 */  lui   $at, %hi(D_8004AE90) # $at, 0x8005
/* 0BDA30 7F08B040 C428AE90 */  lwc1  $f8, %lo(D_8004AE90)($at)
/* 0BDA34 7F08B044 46040182 */  mul.s $f6, $f0, $f4
/* 0BDA38 7F08B048 3C0B8003 */  lui   $t3, %hi(D_800368B8) # $t3, 0x8003
/* 0BDA3C 7F08B04C 256B1E00 */  addiu $t3, %lo(D_800368B8) # addiu $t3, $t3, 0x1e00
/* 0BDA40 7F08B050 27AA004C */  addiu $t2, $sp, 0x4c
/* 0BDA44 7F08B054 3C0F8007 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8007
/* 0BDA48 7F08B058 46083283 */  div.s $f10, $f6, $f8
/* 0BDA4C 7F08B05C 4600540D */  trunc.w.s $f16, $f10
/* 0BDA50 7F08B060 44098000 */  mfc1  $t1, $f16
/* 0BDA54 7F08B064 00000000 */  nop   
/* 0BDA58 7F08B068 AFA90068 */  sw    $t1, 0x68($sp)
/* 0BDA5C 7F08B06C 8D610000 */  lw    $at, ($t3)
/* 0BDA60 7F08B070 8D6E0004 */  lw    $t6, 4($t3)
/* 0BDA64 7F08B074 AD410000 */  sw    $at, ($t2)
/* 0BDA68 7F08B078 8D610008 */  lw    $at, 8($t3)
/* 0BDA6C 7F08B07C AD4E0004 */  sw    $t6, 4($t2)
/* 0BDA70 7F08B080 8D6E000C */  lw    $t6, 0xc($t3)
/* 0BDA74 7F08B084 AD410008 */  sw    $at, 8($t2)
/* 0BDA78 7F08B088 8D610010 */  lw    $at, 0x10($t3)
/* 0BDA7C 7F08B08C AD4E000C */  sw    $t6, 0xc($t2)
/* 0BDA80 7F08B090 8D6E0014 */  lw    $t6, 0x14($t3)
/* 0BDA84 7F08B094 AD410010 */  sw    $at, 0x10($t2)
/* 0BDA88 7F08B098 9961001A */  lwr   $at, 0x1a($t3)
/* 0BDA8C 7F08B09C AD4E0014 */  sw    $t6, 0x14($t2)
/* 0BDA90 7F08B0A0 B941001A */  swr   $at, 0x1a($t2)
/* 0BDA94 7F08B0A4 8DEF8BC0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0BDA98 7F08B0A8 8DF80488 */  lw    $t8, 0x488($t7)
/* 0BDA9C 7F08B0AC 0FC2D447 */  jal   bgDebPrintROOMID
/* 0BDAA0 7F08B0B0 93040003 */   lbu   $a0, 3($t8)
/* 0BDAA4 7F08B0B4 3C058005 */  lui   $a1, %hi(a8s) # $a1, 0x8005
/* 0BDAA8 7F08B0B8 24A5AB90 */  addiu $a1, %lo(a8s) # addiu $a1, $a1, -0x5470
/* 0BDAAC 7F08B0BC 27A400C4 */  addiu $a0, $sp, 0xc4
/* 0BDAB0 7F08B0C0 0C00283D */  jal   sprintf
/* 0BDAB4 7F08B0C4 00403025 */   move  $a2, $v0
/* 0BDAB8 7F08B0C8 3C198007 */  lui   $t9, %hi(g_CurrentPlayer) # $t9, 0x8007
/* 0BDABC 7F08B0CC 8F398BC0 */  lw    $t9, %lo(g_CurrentPlayer)($t9)
/* 0BDAC0 7F08B0D0 3C058005 */  lui   $a1, %hi(aX4_0f) # $a1, 0x8005
/* 0BDAC4 7F08B0D4 24A5AB94 */  addiu $a1, %lo(aX4_0f) # addiu $a1, $a1, -0x546c
/* 0BDAC8 7F08B0D8 C732048C */  lwc1  $f18, 0x48c($t9)
/* 0BDACC 7F08B0DC 27A400B4 */  addiu $a0, $sp, 0xb4
/* 0BDAD0 7F08B0E0 46009121 */  cvt.d.s $f4, $f18
/* 0BDAD4 7F08B0E4 44072000 */  mfc1  $a3, $f4
/* 0BDAD8 7F08B0E8 44062800 */  mfc1  $a2, $f5
/* 0BDADC 7F08B0EC 0C00283D */  jal   sprintf
/* 0BDAE0 7F08B0F0 00000000 */   nop   
/* 0BDAE4 7F08B0F4 3C088007 */  lui   $t0, %hi(g_CurrentPlayer) # $t0, 0x8007
/* 0BDAE8 7F08B0F8 8D088BC0 */  lw    $t0, %lo(g_CurrentPlayer)($t0)
/* 0BDAEC 7F08B0FC 3C058005 */  lui   $a1, %hi(aY4_0f) # $a1, 0x8005
/* 0BDAF0 7F08B100 24A5AB9C */  addiu $a1, %lo(aY4_0f) # addiu $a1, $a1, -0x5464
/* 0BDAF4 7F08B104 C5060490 */  lwc1  $f6, 0x490($t0)
/* 0BDAF8 7F08B108 27A400A4 */  addiu $a0, $sp, 0xa4
/* 0BDAFC 7F08B10C 46003221 */  cvt.d.s $f8, $f6
/* 0BDB00 7F08B110 44074000 */  mfc1  $a3, $f8
/* 0BDB04 7F08B114 44064800 */  mfc1  $a2, $f9
/* 0BDB08 7F08B118 0C00283D */  jal   sprintf
/* 0BDB0C 7F08B11C 00000000 */   nop   
/* 0BDB10 7F08B120 3C098007 */  lui   $t1, %hi(g_CurrentPlayer) # $t1, 0x8007
/* 0BDB14 7F08B124 8D298BC0 */  lw    $t1, %lo(g_CurrentPlayer)($t1)
/* 0BDB18 7F08B128 3C058005 */  lui   $a1, %hi(aZ4_0f) # $a1, 0x8005
/* 0BDB1C 7F08B12C 24A5ABA4 */  addiu $a1, %lo(aZ4_0f) # addiu $a1, $a1, -0x545c
/* 0BDB20 7F08B130 C52A0494 */  lwc1  $f10, 0x494($t1)
/* 0BDB24 7F08B134 27A40094 */  addiu $a0, $sp, 0x94
/* 0BDB28 7F08B138 46005421 */  cvt.d.s $f16, $f10
/* 0BDB2C 7F08B13C 44078000 */  mfc1  $a3, $f16
/* 0BDB30 7F08B140 44068800 */  mfc1  $a2, $f17
/* 0BDB34 7F08B144 0C00283D */  jal   sprintf
/* 0BDB38 7F08B148 00000000 */   nop   
/* 0BDB3C 7F08B14C 8FA70068 */  lw    $a3, 0x68($sp)
/* 0BDB40 7F08B150 2401002D */  li    $at, 45
/* 0BDB44 7F08B154 3C058005 */  lui   $a1, %hi(aS3d) # $a1, 0x8005
/* 0BDB48 7F08B158 24ED0016 */  addiu $t5, $a3, 0x16
/* 0BDB4C 7F08B15C 01A1001A */  div   $zero, $t5, $at
/* 0BDB50 7F08B160 00006012 */  mflo  $t4
/* 0BDB54 7F08B164 000C5080 */  sll   $t2, $t4, 2
/* 0BDB58 7F08B168 014C5023 */  subu  $t2, $t2, $t4
/* 0BDB5C 7F08B16C 27AB004C */  addiu $t3, $sp, 0x4c
/* 0BDB60 7F08B170 014B3021 */  addu  $a2, $t2, $t3
/* 0BDB64 7F08B174 24A5ABAC */  addiu $a1, %lo(aS3d) # addiu $a1, $a1, -0x5454
/* 0BDB68 7F08B178 0C00283D */  jal   sprintf
/* 0BDB6C 7F08B17C 27A40084 */   addiu $a0, $sp, 0x84
/* 0BDB70 7F08B180 0C000FD9 */  jal   viGetViewLeft
/* 0BDB74 7F08B184 00000000 */   nop   
/* 0BDB78 7F08B188 244E0011 */  addiu $t6, $v0, 0x11
/* 0BDB7C 7F08B18C 0C000FDD */  jal   viGetViewTop
/* 0BDB80 7F08B190 AFAE0080 */   sw    $t6, 0x80($sp)
/* 0BDB84 7F08B194 24460011 */  addiu $a2, $v0, 0x11
/* 0BDB88 7F08B198 24CF000A */  addiu $t7, $a2, 0xa
/* 0BDB8C 7F08B19C AFAF0074 */  sw    $t7, 0x74($sp)
/* 0BDB90 7F08B1A0 AFA6007C */  sw    $a2, 0x7c($sp)
/* 0BDB94 7F08B1A4 0FC2B016 */  jal   microcode_constructor
/* 0BDB98 7F08B1A8 02002025 */   move  $a0, $s0
/* 0BDB9C 7F08B1AC 0C000F9B */  jal   viGetX
/* 0BDBA0 7F08B1B0 00408025 */   move  $s0, $v0
/* 0BDBA4 7F08B1B4 8FB80074 */  lw    $t8, 0x74($sp)
/* 0BDBA8 7F08B1B8 24080064 */  li    $t0, 100
/* 0BDBAC 7F08B1BC AFA80014 */  sw    $t0, 0x14($sp)
/* 0BDBB0 7F08B1C0 27190001 */  addiu $t9, $t8, 1
/* 0BDBB4 7F08B1C4 AFB90010 */  sw    $t9, 0x10($sp)
/* 0BDBB8 7F08B1C8 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0BDBBC 7F08B1CC 02002025 */  move  $a0, $s0
/* 0BDBC0 7F08B1D0 00002825 */  move  $a1, $zero
/* 0BDBC4 7F08B1D4 0FC2B0B5 */  jal   microcode_constructor_related_to_menus
/* 0BDBC8 7F08B1D8 00403825 */   move  $a3, $v0
/* 0BDBCC 7F08B1DC 0C000F9B */  jal   viGetX
/* 0BDBD0 7F08B1E0 00408025 */   move  $s0, $v0
/* 0BDBD4 7F08B1E4 0C000F9F */  jal   viGetY
/* 0BDBD8 7F08B1E8 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BDBDC 7F08B1EC 3C098004 */  lui   $t1, %hi(ptrFontBankGothicChars) # $t1, 0x8004
/* 0BDBE0 7F08B1F0 3C0D8004 */  lui   $t5, %hi(ptrFontBankGothic) # $t5, 0x8004
/* 0BDBE4 7F08B1F4 8DADAAFC */  lw    $t5, %lo(ptrFontBankGothic)($t5)
/* 0BDBE8 7F08B1F8 8D29AB00 */  lw    $t1, %lo(ptrFontBankGothicChars)($t1)
/* 0BDBEC 7F08B1FC 87AA0048 */  lh    $t2, 0x48($sp)
/* 0BDBF0 7F08B200 240CFFFF */  li    $t4, -1
/* 0BDBF4 7F08B204 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0BDBF8 7F08B208 02002025 */  move  $a0, $s0
/* 0BDBFC 7F08B20C 27A50080 */  addiu $a1, $sp, 0x80
/* 0BDC00 7F08B210 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BDC04 7F08B214 27A700C4 */  addiu $a3, $sp, 0xc4
/* 0BDC08 7F08B218 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BDC0C 7F08B21C AFA00024 */  sw    $zero, 0x24($sp)
/* 0BDC10 7F08B220 AFA00028 */  sw    $zero, 0x28($sp)
/* 0BDC14 7F08B224 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0BDC18 7F08B228 AFA90010 */  sw    $t1, 0x10($sp)
/* 0BDC1C 7F08B22C 0FC2B35F */  jal   textRender
/* 0BDC20 7F08B230 AFAA001C */   sw    $t2, 0x1c($sp)
/* 0BDC24 7F08B234 0C000FD9 */  jal   viGetViewLeft
/* 0BDC28 7F08B238 00408025 */   move  $s0, $v0
/* 0BDC2C 7F08B23C 244B0057 */  addiu $t3, $v0, 0x57
/* 0BDC30 7F08B240 0C000F9B */  jal   viGetX
/* 0BDC34 7F08B244 AFAB0080 */   sw    $t3, 0x80($sp)
/* 0BDC38 7F08B248 0C000F9F */  jal   viGetY
/* 0BDC3C 7F08B24C A7A20048 */   sh    $v0, 0x48($sp)
/* 0BDC40 7F08B250 3C0E8004 */  lui   $t6, %hi(ptrFontBankGothicChars) # $t6, 0x8004
/* 0BDC44 7F08B254 3C0F8004 */  lui   $t7, %hi(ptrFontBankGothic) # $t7, 0x8004
/* 0BDC48 7F08B258 8DEFAAFC */  lw    $t7, %lo(ptrFontBankGothic)($t7)
/* 0BDC4C 7F08B25C 8DCEAB00 */  lw    $t6, %lo(ptrFontBankGothicChars)($t6)
/* 0BDC50 7F08B260 87B90048 */  lh    $t9, 0x48($sp)
/* 0BDC54 7F08B264 2418FFFF */  li    $t8, -1
/* 0BDC58 7F08B268 AFB80018 */  sw    $t8, 0x18($sp)
/* 0BDC5C 7F08B26C 02002025 */  move  $a0, $s0
/* 0BDC60 7F08B270 27A50080 */  addiu $a1, $sp, 0x80
/* 0BDC64 7F08B274 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BDC68 7F08B278 27A700B4 */  addiu $a3, $sp, 0xb4
/* 0BDC6C 7F08B27C AFA20020 */  sw    $v0, 0x20($sp)
/* 0BDC70 7F08B280 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BDC74 7F08B284 AFA00028 */  sw    $zero, 0x28($sp)
/* 0BDC78 7F08B288 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0BDC7C 7F08B28C AFAE0010 */  sw    $t6, 0x10($sp)
/* 0BDC80 7F08B290 0FC2B35F */  jal   textRender
/* 0BDC84 7F08B294 AFB9001C */   sw    $t9, 0x1c($sp)
/* 0BDC88 7F08B298 0C000FD9 */  jal   viGetViewLeft
/* 0BDC8C 7F08B29C 00408025 */   move  $s0, $v0
/* 0BDC90 7F08B2A0 2448008D */  addiu $t0, $v0, 0x8d
/* 0BDC94 7F08B2A4 0C000F9B */  jal   viGetX
/* 0BDC98 7F08B2A8 AFA80080 */   sw    $t0, 0x80($sp)
/* 0BDC9C 7F08B2AC 0C000F9F */  jal   viGetY
/* 0BDCA0 7F08B2B0 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BDCA4 7F08B2B4 3C098004 */  lui   $t1, %hi(ptrFontBankGothicChars) # $t1, 0x8004
/* 0BDCA8 7F08B2B8 3C0D8004 */  lui   $t5, %hi(ptrFontBankGothic) # $t5, 0x8004
/* 0BDCAC 7F08B2BC 8DADAAFC */  lw    $t5, %lo(ptrFontBankGothic)($t5)
/* 0BDCB0 7F08B2C0 8D29AB00 */  lw    $t1, %lo(ptrFontBankGothicChars)($t1)
/* 0BDCB4 7F08B2C4 87AA0048 */  lh    $t2, 0x48($sp)
/* 0BDCB8 7F08B2C8 240CFFFF */  li    $t4, -1
/* 0BDCBC 7F08B2CC AFAC0018 */  sw    $t4, 0x18($sp)
/* 0BDCC0 7F08B2D0 02002025 */  move  $a0, $s0
/* 0BDCC4 7F08B2D4 27A50080 */  addiu $a1, $sp, 0x80
/* 0BDCC8 7F08B2D8 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BDCCC 7F08B2DC 27A700A4 */  addiu $a3, $sp, 0xa4
/* 0BDCD0 7F08B2E0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BDCD4 7F08B2E4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BDCD8 7F08B2E8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0BDCDC 7F08B2EC AFAD0014 */  sw    $t5, 0x14($sp)
/* 0BDCE0 7F08B2F0 AFA90010 */  sw    $t1, 0x10($sp)
/* 0BDCE4 7F08B2F4 0FC2B35F */  jal   textRender
/* 0BDCE8 7F08B2F8 AFAA001C */   sw    $t2, 0x1c($sp)
/* 0BDCEC 7F08B2FC 0C000FD9 */  jal   viGetViewLeft
/* 0BDCF0 7F08B300 00408025 */   move  $s0, $v0
/* 0BDCF4 7F08B304 244B00C3 */  addiu $t3, $v0, 0xc3
/* 0BDCF8 7F08B308 0C000F9B */  jal   viGetX
/* 0BDCFC 7F08B30C AFAB0080 */   sw    $t3, 0x80($sp)
/* 0BDD00 7F08B310 0C000F9F */  jal   viGetY
/* 0BDD04 7F08B314 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BDD08 7F08B318 3C0E8004 */  lui   $t6, %hi(ptrFontBankGothicChars) # $t6, 0x8004
/* 0BDD0C 7F08B31C 3C0F8004 */  lui   $t7, %hi(ptrFontBankGothic) # $t7, 0x8004
/* 0BDD10 7F08B320 8DEFAAFC */  lw    $t7, %lo(ptrFontBankGothic)($t7)
/* 0BDD14 7F08B324 8DCEAB00 */  lw    $t6, %lo(ptrFontBankGothicChars)($t6)
/* 0BDD18 7F08B328 87B90048 */  lh    $t9, 0x48($sp)
/* 0BDD1C 7F08B32C 2418FFFF */  li    $t8, -1
/* 0BDD20 7F08B330 AFB80018 */  sw    $t8, 0x18($sp)
/* 0BDD24 7F08B334 02002025 */  move  $a0, $s0
/* 0BDD28 7F08B338 27A50080 */  addiu $a1, $sp, 0x80
/* 0BDD2C 7F08B33C 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BDD30 7F08B340 27A70094 */  addiu $a3, $sp, 0x94
/* 0BDD34 7F08B344 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BDD38 7F08B348 AFA00024 */  sw    $zero, 0x24($sp)
/* 0BDD3C 7F08B34C AFA00028 */  sw    $zero, 0x28($sp)
/* 0BDD40 7F08B350 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0BDD44 7F08B354 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0BDD48 7F08B358 0FC2B35F */  jal   textRender
/* 0BDD4C 7F08B35C AFB9001C */   sw    $t9, 0x1c($sp)
/* 0BDD50 7F08B360 0C000FD9 */  jal   viGetViewLeft
/* 0BDD54 7F08B364 00408025 */   move  $s0, $v0
/* 0BDD58 7F08B368 244800F9 */  addiu $t0, $v0, 0xf9
/* 0BDD5C 7F08B36C 0C000F9B */  jal   viGetX
/* 0BDD60 7F08B370 AFA80080 */   sw    $t0, 0x80($sp)
/* 0BDD64 7F08B374 0C000F9F */  jal   viGetY
/* 0BDD68 7F08B378 A7A20048 */   sh    $v0, 0x48($sp)
/* 0BDD6C 7F08B37C 3C098004 */  lui   $t1, %hi(ptrFontBankGothicChars) # $t1, 0x8004
/* 0BDD70 7F08B380 3C0D8004 */  lui   $t5, %hi(ptrFontBankGothic) # $t5, 0x8004
/* 0BDD74 7F08B384 8DADAAFC */  lw    $t5, %lo(ptrFontBankGothic)($t5)
/* 0BDD78 7F08B388 8D29AB00 */  lw    $t1, %lo(ptrFontBankGothicChars)($t1)
/* 0BDD7C 7F08B38C 87AA0048 */  lh    $t2, 0x48($sp)
/* 0BDD80 7F08B390 240CFFFF */  li    $t4, -1
/* 0BDD84 7F08B394 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0BDD88 7F08B398 02002025 */  move  $a0, $s0
/* 0BDD8C 7F08B39C 27A50080 */  addiu $a1, $sp, 0x80
/* 0BDD90 7F08B3A0 27A6007C */  addiu $a2, $sp, 0x7c
/* 0BDD94 7F08B3A4 27A70084 */  addiu $a3, $sp, 0x84
/* 0BDD98 7F08B3A8 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BDD9C 7F08B3AC AFA00024 */  sw    $zero, 0x24($sp)
/* 0BDDA0 7F08B3B0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0BDDA4 7F08B3B4 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0BDDA8 7F08B3B8 AFA90010 */  sw    $t1, 0x10($sp)
/* 0BDDAC 7F08B3BC 0FC2B35F */  jal   textRender
/* 0BDDB0 7F08B3C0 AFAA001C */   sw    $t2, 0x1c($sp)
/* 0BDDB4 7F08B3C4 0FC2B06C */  jal   combiner_bayer_lod_perspective
/* 0BDDB8 7F08B3C8 00402025 */   move  $a0, $v0
/* 0BDDBC 7F08B3CC 00408025 */  move  $s0, $v0
.L7F08B3D0:
/* 0BDDC0 7F08B3D0 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0BDDC4 7F08B3D4 02001025 */  move  $v0, $s0
/* 0BDDC8 7F08B3D8 8FB00038 */  lw    $s0, 0x38($sp)
/* 0BDDCC 7F08B3DC 03E00008 */  jr    $ra
/* 0BDDD0 7F08B3E0 27BD00E8 */   addiu $sp, $sp, 0xe8
)
#endif


#endif




#ifdef NONMATCHING
void sub_GAME_7F08B0F0(void) {

}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_800552C0
.word 0xbd4ccccd /*-0.050000001*/
glabel D_800552C4
.word 0xbecccccd /*-0.40000001*/
glabel D_800552C8
.word 0x3d4ccccd /*0.050000001*/
glabel D_800552CC
.word 0x3ecccccd /*0.40000001*/
glabel D_800552D0
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F08B0F0
/* 0BFC20 7F08B0F0 27BDFF08 */  addiu $sp, $sp, -0xf8
/* 0BFC24 7F08B0F4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0BFC28 7F08B0F8 AFB10020 */  sw    $s1, 0x20($sp)
/* 0BFC2C 7F08B0FC AFB0001C */  sw    $s0, 0x1c($sp)
/* 0BFC30 7F08B100 0FC26C57 */  jal   getPlayerPointerIndex
/* 0BFC34 7F08B104 AFA400F8 */   sw    $a0, 0xf8($sp)
/* 0BFC38 7F08B108 8FAE00F8 */  lw    $t6, 0xf8($sp)
/* 0BFC3C 7F08B10C AFA200F4 */  sw    $v0, 0xf4($sp)
/* 0BFC40 7F08B110 8DCF0004 */  lw    $t7, 4($t6)
/* 0BFC44 7F08B114 11E0000B */  beqz  $t7, .L7F08B144
/* 0BFC48 7F08B118 AFAF00F0 */   sw    $t7, 0xf0($sp)
/* 0BFC4C 7F08B11C 0FC26C54 */  jal   get_cur_playernum
/* 0BFC50 7F08B120 00000000 */   nop
/* 0BFC54 7F08B124 0FC26D36 */  jal   sub_GAME_7F09B4D8
/* 0BFC58 7F08B128 00402025 */   move  $a0, $v0
/* 0BFC5C 7F08B12C 54400006 */  bnezl $v0, .L7F08B148
/* 0BFC60 7F08B130 8FA900F0 */   lw    $t1, 0xf0($sp)
/* 0BFC64 7F08B134 8FA200F0 */  lw    $v0, 0xf0($sp)
/* 0BFC68 7F08B138 94580012 */  lhu   $t8, 0x12($v0)
/* 0BFC6C 7F08B13C 3319F7FF */  andi  $t9, $t8, 0xf7ff
/* 0BFC70 7F08B140 A4590012 */  sh    $t9, 0x12($v0)
.L7F08B144:
/* 0BFC74 7F08B144 8FA900F0 */  lw    $t1, 0xf0($sp)
.L7F08B148:
/* 0BFC78 7F08B148 8FAA00F4 */  lw    $t2, 0xf4($sp)
/* 0BFC7C 7F08B14C 3C0C8008 */  lui   $t4, %hi(g_playerPointers)
/* 0BFC80 7F08B150 1120004D */  beqz  $t1, .L7F08B288
/* 0BFC84 7F08B154 000A5880 */   sll   $t3, $t2, 2
/* 0BFC88 7F08B158 258C9EE0 */  addiu $t4, %lo(g_playerPointers) # addiu $t4, $t4, -0x6120
/* 0BFC8C 7F08B15C 016C8821 */  addu  $s1, $t3, $t4
/* 0BFC90 7F08B160 8E2D0000 */  lw    $t5, ($s1)
/* 0BFC94 7F08B164 8DAE00D4 */  lw    $t6, 0xd4($t5)
/* 0BFC98 7F08B168 51C00048 */  beql  $t6, $zero, .L7F08B28C
/* 0BFC9C 7F08B16C 8FAF00F0 */   lw    $t7, 0xf0($sp)
/* 0BFCA0 7F08B170 0FC243BF */  jal   get_debug_render_raster
/* 0BFCA4 7F08B174 00000000 */   nop
/* 0BFCA8 7F08B178 50400007 */  beql  $v0, $zero, .L7F08B198
/* 0BFCAC 7F08B17C 8E390000 */   lw    $t9, ($s1)
/* 0BFCB0 7F08B180 8E2F0000 */  lw    $t7, ($s1)
/* 0BFCB4 7F08B184 24010001 */  li    $at, 1
/* 0BFCB8 7F08B188 8DF80000 */  lw    $t8, ($t7)
/* 0BFCBC 7F08B18C 5701003F */  bnel  $t8, $at, .L7F08B28C
/* 0BFCC0 7F08B190 8FAF00F0 */   lw    $t7, 0xf0($sp)
/* 0BFCC4 7F08B194 8E390000 */  lw    $t9, ($s1)
.L7F08B198:
/* 0BFCC8 7F08B198 AF2000AC */  sw    $zero, 0xac($t9)
/* 0BFCCC 7F08B19C 0FC083BC */  jal   sub_GAME_7F020EF0
/* 0BFCD0 7F08B1A0 8FA400F8 */   lw    $a0, 0xf8($sp)
/* 0BFCD4 7F08B1A4 8E2A0000 */  lw    $t2, ($s1)
/* 0BFCD8 7F08B1A8 AFA200E8 */  sw    $v0, 0xe8($sp)
/* 0BFCDC 7F08B1AC 24090001 */  li    $t1, 1
/* 0BFCE0 7F08B1B0 AD4900AC */  sw    $t1, 0xac($t2)
/* 0BFCE4 7F08B1B4 8E280000 */  lw    $t0, ($s1)
/* 0BFCE8 7F08B1B8 8D0B00A8 */  lw    $t3, 0xa8($t0)
/* 0BFCEC 7F08B1BC C5640008 */  lwc1  $f4, 8($t3)
/* 0BFCF0 7F08B1C0 E504048C */  swc1  $f4, 0x48c($t0)
/* 0BFCF4 7F08B1C4 8E280000 */  lw    $t0, ($s1)
/* 0BFCF8 7F08B1C8 8D0C00A8 */  lw    $t4, 0xa8($t0)
/* 0BFCFC 7F08B1CC C586000C */  lwc1  $f6, 0xc($t4)
/* 0BFD00 7F08B1D0 E5060490 */  swc1  $f6, 0x490($t0)
/* 0BFD04 7F08B1D4 8E280000 */  lw    $t0, ($s1)
/* 0BFD08 7F08B1D8 8D0D00A8 */  lw    $t5, 0xa8($t0)
/* 0BFD0C 7F08B1DC C5A80010 */  lwc1  $f8, 0x10($t5)
/* 0BFD10 7F08B1E0 E5080494 */  swc1  $f8, 0x494($t0)
/* 0BFD14 7F08B1E4 8E280000 */  lw    $t0, ($s1)
/* 0BFD18 7F08B1E8 8D0E00A8 */  lw    $t6, 0xa8($t0)
/* 0BFD1C 7F08B1EC 8DCF0014 */  lw    $t7, 0x14($t6)
/* 0BFD20 7F08B1F0 AD0F0488 */  sw    $t7, 0x488($t0)
/* 0BFD24 7F08B1F4 0FC1F7A7 */  jal   sub_GAME_7F07DE9C
/* 0BFD28 7F08B1F8 8E240000 */   lw    $a0, ($s1)
/* 0BFD2C 7F08B1FC 8FB800F8 */  lw    $t8, 0xf8($sp)
/* 0BFD30 7F08B200 93190001 */  lbu   $t9, 1($t8)
/* 0BFD34 7F08B204 33290002 */  andi  $t1, $t9, 2
/* 0BFD38 7F08B208 1120001D */  beqz  $t1, .L7F08B280
/* 0BFD3C 7F08B20C 00000000 */   nop
/* 0BFD40 7F08B210 8E2A0000 */  lw    $t2, ($s1)
/* 0BFD44 7F08B214 8D4B00D4 */  lw    $t3, 0xd4($t2)
/* 0BFD48 7F08B218 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 0BFD4C 7F08B21C 8D70000C */   lw    $s0, 0xc($t3)
/* 0BFD50 7F08B220 00402025 */  move  $a0, $v0
/* 0BFD54 7F08B224 02002825 */  move  $a1, $s0
/* 0BFD58 7F08B228 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0BFD5C 7F08B22C 27A600A4 */   addiu $a2, $sp, 0xa4
/* 0BFD60 7F08B230 3C0140E0 */  li    $at, 0x40E00000 # 7.000000
/* 0BFD64 7F08B234 44810000 */  mtc1  $at, $f0
/* 0BFD68 7F08B238 C7AA00B4 */  lwc1  $f10, 0xb4($sp)
/* 0BFD6C 7F08B23C C7A400D4 */  lwc1  $f4, 0xd4($sp)
/* 0BFD70 7F08B240 8E2C0000 */  lw    $t4, ($s1)
/* 0BFD74 7F08B244 46005482 */  mul.s $f18, $f10, $f0
/* 0BFD78 7F08B248 46049180 */  add.s $f6, $f18, $f4
/* 0BFD7C 7F08B24C E58604B4 */  swc1  $f6, 0x4b4($t4)
/* 0BFD80 7F08B250 C7A800B8 */  lwc1  $f8, 0xb8($sp)
/* 0BFD84 7F08B254 C7B200D8 */  lwc1  $f18, 0xd8($sp)
/* 0BFD88 7F08B258 8E2D0000 */  lw    $t5, ($s1)
/* 0BFD8C 7F08B25C 46004282 */  mul.s $f10, $f8, $f0
/* 0BFD90 7F08B260 46125100 */  add.s $f4, $f10, $f18
/* 0BFD94 7F08B264 E5A404B8 */  swc1  $f4, 0x4b8($t5)
/* 0BFD98 7F08B268 C7A600BC */  lwc1  $f6, 0xbc($sp)
/* 0BFD9C 7F08B26C C7AA00DC */  lwc1  $f10, 0xdc($sp)
/* 0BFDA0 7F08B270 8E2E0000 */  lw    $t6, ($s1)
/* 0BFDA4 7F08B274 46003202 */  mul.s $f8, $f6, $f0
/* 0BFDA8 7F08B278 460A4480 */  add.s $f18, $f8, $f10
/* 0BFDAC 7F08B27C E5D204BC */  swc1  $f18, 0x4bc($t6)
.L7F08B280:
/* 0BFDB0 7F08B280 10000288 */  b     .L7F08BCA4
/* 0BFDB4 7F08B284 8FA200E8 */   lw    $v0, 0xe8($sp)
.L7F08B288:
/* 0BFDB8 7F08B288 8FAF00F0 */  lw    $t7, 0xf0($sp)
.L7F08B28C:
/* 0BFDBC 7F08B28C 8FB800F4 */  lw    $t8, 0xf4($sp)
/* 0BFDC0 7F08B290 3C098008 */  lui   $t1, %hi(g_playerPointers)
/* 0BFDC4 7F08B294 11E0027E */  beqz  $t7, .L7F08BC90
/* 0BFDC8 7F08B298 0018C880 */   sll   $t9, $t8, 2
/* 0BFDCC 7F08B29C 25299EE0 */  addiu $t1, %lo(g_playerPointers) # addiu $t1, $t1, -0x6120
/* 0BFDD0 7F08B2A0 03298821 */  addu  $s1, $t9, $t1
/* 0BFDD4 7F08B2A4 8E2A0000 */  lw    $t2, ($s1)
/* 0BFDD8 7F08B2A8 8D4B00D4 */  lw    $t3, 0xd4($t2)
/* 0BFDDC 7F08B2AC 51600279 */  beql  $t3, $zero, .L7F08BC94
/* 0BFDE0 7F08B2B0 8FAA00F8 */   lw    $t2, 0xf8($sp)
/* 0BFDE4 7F08B2B4 0FC26919 */  jal   getPlayerCount
/* 0BFDE8 7F08B2B8 00000000 */   nop
/* 0BFDEC 7F08B2BC 28410002 */  slti  $at, $v0, 2
/* 0BFDF0 7F08B2C0 54200274 */  bnezl $at, .L7F08BC94
/* 0BFDF4 7F08B2C4 8FAA00F8 */   lw    $t2, 0xf8($sp)
/* 0BFDF8 7F08B2C8 0FC26C54 */  jal   get_cur_playernum
/* 0BFDFC 7F08B2CC 00000000 */   nop
/* 0BFE00 7F08B2D0 8FAC00F4 */  lw    $t4, 0xf4($sp)
/* 0BFE04 7F08B2D4 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0BFE08 7F08B2D8 24050001 */  li    $a1, 1
/* 0BFE0C 7F08B2DC 504C026D */  beql  $v0, $t4, .L7F08BC94
/* 0BFE10 7F08B2E0 8FAA00F8 */   lw    $t2, 0xf8($sp)
/* 0BFE14 7F08B2E4 44811000 */  mtc1  $at, $f2
/* 0BFE18 7F08B2E8 AFA0009C */  sw    $zero, 0x9c($sp)
/* 0BFE1C 7F08B2EC AFA0007C */  sw    $zero, 0x7c($sp)
/* 0BFE20 7F08B2F0 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0BFE24 7F08B2F4 E7A20090 */  swc1  $f2, 0x90($sp)
/* 0BFE28 7F08B2F8 0FC08C0B */  jal   chrGetEquippedWeaponProp
/* 0BFE2C 7F08B2FC E7A20094 */   swc1  $f2, 0x94($sp)
/* 0BFE30 7F08B300 00408025 */  move  $s0, $v0
/* 0BFE34 7F08B304 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0BFE38 7F08B308 0FC08C0B */  jal   chrGetEquippedWeaponProp
/* 0BFE3C 7F08B30C 00002825 */   move  $a1, $zero
/* 0BFE40 7F08B310 C7A20094 */  lwc1  $f2, 0x94($sp)
/* 0BFE44 7F08B314 00402825 */  move  $a1, $v0
/* 0BFE48 7F08B318 00001825 */  move  $v1, $zero
/* 0BFE4C 7F08B31C 00002025 */  move  $a0, $zero
/* 0BFE50 7F08B320 12000002 */  beqz  $s0, .L7F08B32C
/* 0BFE54 7F08B324 AFA00054 */   sw    $zero, 0x54($sp)
/* 0BFE58 7F08B328 8E030004 */  lw    $v1, 4($s0)
.L7F08B32C:
/* 0BFE5C 7F08B32C 50400003 */  beql  $v0, $zero, .L7F08B33C
/* 0BFE60 7F08B330 AFA3005C */   sw    $v1, 0x5c($sp)
/* 0BFE64 7F08B334 8C440004 */  lw    $a0, 4($v0)
/* 0BFE68 7F08B338 AFA3005C */  sw    $v1, 0x5c($sp)
.L7F08B33C:
/* 0BFE6C 7F08B33C AFA40058 */  sw    $a0, 0x58($sp)
/* 0BFE70 7F08B340 AFA50060 */  sw    $a1, 0x60($sp)
/* 0BFE74 7F08B344 0FC26C54 */  jal   get_cur_playernum
/* 0BFE78 7F08B348 E7A20094 */   swc1  $f2, 0x94($sp)
/* 0BFE7C 7F08B34C 0FC26D36 */  jal   sub_GAME_7F09B4D8
/* 0BFE80 7F08B350 00402025 */   move  $a0, $v0
/* 0BFE84 7F08B354 8FA3005C */  lw    $v1, 0x5c($sp)
/* 0BFE88 7F08B358 8FA50060 */  lw    $a1, 0x60($sp)
/* 0BFE8C 7F08B35C 14400006 */  bnez  $v0, .L7F08B378
/* 0BFE90 7F08B360 C7A20094 */   lwc1  $f2, 0x94($sp)
/* 0BFE94 7F08B364 3C028003 */  lui   $v0, %hi(D_800368B8+0x1C)
/* 0BFE98 7F08B368 244268D4 */  addiu $v0, %lo(D_800368B8+0x1C) # addiu $v0, $v0, 0x68d4
/* 0BFE9C 7F08B36C 8C4D0000 */  lw    $t5, ($v0)
/* 0BFEA0 7F08B370 25AE0001 */  addiu $t6, $t5, 1
/* 0BFEA4 7F08B374 AC4E0000 */  sw    $t6, ($v0)
.L7F08B378:
/* 0BFEA8 7F08B378 3C028003 */  lui   $v0, %hi(D_800368B8+0x1C)
/* 0BFEAC 7F08B37C 244268D4 */  addiu $v0, %lo(D_800368B8+0x1C) # addiu $v0, $v0, 0x68d4
/* 0BFEB0 7F08B380 8C4F0000 */  lw    $t7, ($v0)
/* 0BFEB4 7F08B384 29E10002 */  slti  $at, $t7, 2
/* 0BFEB8 7F08B388 542001BB */  bnezl $at, .L7F08BA78
/* 0BFEBC 7F08B38C 8E2A0000 */   lw    $t2, ($s1)
/* 0BFEC0 7F08B390 8E280000 */  lw    $t0, ($s1)
/* 0BFEC4 7F08B394 C5042A08 */  lwc1  $f4, 0x2a08($t0)
/* 0BFEC8 7F08B398 E7A4008C */  swc1  $f4, 0x8c($sp)
/* 0BFECC 7F08B39C C5062A0C */  lwc1  $f6, 0x2a0c($t0)
/* 0BFED0 7F08B3A0 E7A60088 */  swc1  $f6, 0x88($sp)
/* 0BFED4 7F08B3A4 8D1800D8 */  lw    $t8, 0xd8($t0)
/* 0BFED8 7F08B3A8 13000036 */  beqz  $t8, .L7F08B484
/* 0BFEDC 7F08B3AC 3C078003 */   lui   $a3, %hi(g_bondviewBondDeathAnimationsCount)
/* 0BFEE0 7F08B3B0 8CE7650C */  lw    $a3, %lo(g_bondviewBondDeathAnimationsCount)($a3)
/* 0BFEE4 7F08B3B4 00002825 */  move  $a1, $zero
/* 0BFEE8 7F08B3B8 00008025 */  move  $s0, $zero
/* 0BFEEC 7F08B3BC 18E00010 */  blez  $a3, .L7F08B400
/* 0BFEF0 7F08B3C0 3C198003 */   lui   $t9, %hi(g_bondviewBondDeathAnimations)
/* 0BFEF4 7F08B3C4 272264D8 */  addiu $v0, $t9, %lo(g_bondviewBondDeathAnimations)
/* 0BFEF8 7F08B3C8 3C038007 */  lui   $v1, %hi(ptr_animation_table)
/* 0BFEFC 7F08B3CC 00074880 */  sll   $t1, $a3, 2
/* 0BFF00 7F08B3D0 01222021 */  addu  $a0, $t1, $v0
/* 0BFF04 7F08B3D4 8C639538 */  lw    $v1, %lo(ptr_animation_table)($v1)
/* 0BFF08 7F08B3D8 8D061284 */  lw    $a2, 0x1284($t0)
/* 0BFF0C 7F08B3DC 8C4A0000 */  lw    $t2, ($v0)
.L7F08B3E0:
/* 0BFF10 7F08B3E0 24420004 */  addiu $v0, $v0, 4
/* 0BFF14 7F08B3E4 0044082B */  sltu  $at, $v0, $a0
/* 0BFF18 7F08B3E8 01435821 */  addu  $t3, $t2, $v1
/* 0BFF1C 7F08B3EC 14CB0002 */  bne   $a2, $t3, .L7F08B3F8
/* 0BFF20 7F08B3F0 00000000 */   nop
/* 0BFF24 7F08B3F4 24050001 */  li    $a1, 1
.L7F08B3F8:
/* 0BFF28 7F08B3F8 5420FFF9 */  bnezl $at, .L7F08B3E0
/* 0BFF2C 7F08B3FC 8C4A0000 */   lw    $t2, ($v0)
.L7F08B400:
/* 0BFF30 7F08B400 10A00005 */  beqz  $a1, .L7F08B418
/* 0BFF34 7F08B404 3C013F00 */   li    $at, 0x3F000000 # 0.500000
/* 0BFF38 7F08B408 8D061284 */  lw    $a2, 0x1284($t0)
/* 0BFF3C 7F08B40C 44816000 */  mtc1  $at, $f12
/* 0BFF40 7F08B410 10000017 */  b     .L7F08B470
/* 0BFF44 7F08B414 AFA6009C */   sw    $a2, 0x9c($sp)
.L7F08B418:
/* 0BFF48 7F08B418 0C002914 */  jal   randomGetNext
/* 0BFF4C 7F08B41C E7A20094 */   swc1  $f2, 0x94($sp)
/* 0BFF50 7F08B420 3C0C8003 */  lui   $t4, %hi(g_bondviewBondDeathAnimationsCount)
/* 0BFF54 7F08B424 8D8C650C */  lw    $t4, %lo(g_bondviewBondDeathAnimationsCount)($t4)
/* 0BFF58 7F08B428 3C0F8003 */  lui   $t7, %hi(g_bondviewBondDeathAnimations)
/* 0BFF5C 7F08B42C 3C188007 */  lui   $t8, %hi(ptr_animation_table)
/* 0BFF60 7F08B430 004C001B */  divu  $zero, $v0, $t4
/* 0BFF64 7F08B434 00006810 */  mfhi  $t5
/* 0BFF68 7F08B438 000D7080 */  sll   $t6, $t5, 2
/* 0BFF6C 7F08B43C 01EE7821 */  addu  $t7, $t7, $t6
/* 0BFF70 7F08B440 8DEF64D8 */  lw    $t7, %lo(g_bondviewBondDeathAnimations)($t7)
/* 0BFF74 7F08B444 8F189538 */  lw    $t8, %lo(ptr_animation_table)($t8)
/* 0BFF78 7F08B448 8E280000 */  lw    $t0, ($s1)
/* 0BFF7C 7F08B44C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0BFF80 7F08B450 01F84821 */  addu  $t1, $t7, $t8
/* 0BFF84 7F08B454 AFA9009C */  sw    $t1, 0x9c($sp)
/* 0BFF88 7F08B458 44816000 */  mtc1  $at, $f12
/* 0BFF8C 7F08B45C C7A20094 */  lwc1  $f2, 0x94($sp)
/* 0BFF90 7F08B460 15800002 */  bnez  $t4, .L7F08B46C
/* 0BFF94 7F08B464 00000000 */   nop
/* 0BFF98 7F08B468 0007000D */  break 7
.L7F08B46C:
/* 0BFF9C 7F08B46C 8D061284 */  lw    $a2, 0x1284($t0)
.L7F08B470:
/* 0BFFA0 7F08B470 44807000 */  mtc1  $zero, $f14
/* 0BFFA4 7F08B474 00000000 */  nop
/* 0BFFA8 7F08B478 E7AE008C */  swc1  $f14, 0x8c($sp)
/* 0BFFAC 7F08B47C 100000F6 */  b     .L7F08B858
/* 0BFFB0 7F08B480 E7AE0088 */   swc1  $f14, 0x88($sp)
.L7F08B484:
/* 0BFFB4 7F08B484 12000005 */  beqz  $s0, .L7F08B49C
/* 0BFFB8 7F08B488 00000000 */   nop
/* 0BFFBC 7F08B48C 10A00003 */  beqz  $a1, .L7F08B49C
/* 0BFFC0 7F08B490 00000000 */   nop
/* 0BFFC4 7F08B494 1000002E */  b     .L7F08B550
/* 0BFFC8 7F08B498 24100003 */   li    $s0, 3
.L7F08B49C:
/* 0BFFCC 7F08B49C 16000005 */  bnez  $s0, .L7F08B4B4
/* 0BFFD0 7F08B4A0 00000000 */   nop
/* 0BFFD4 7F08B4A4 14A00003 */  bnez  $a1, .L7F08B4B4
/* 0BFFD8 7F08B4A8 00000000 */   nop
/* 0BFFDC 7F08B4AC 10000028 */  b     .L7F08B550
/* 0BFFE0 7F08B4B0 24100002 */   li    $s0, 2
.L7F08B4B4:
/* 0BFFE4 7F08B4B4 10600008 */  beqz  $v1, .L7F08B4D8
/* 0BFFE8 7F08B4B8 24050200 */   li    $a1, 512
/* 0BFFEC 7F08B4BC 80640080 */  lb    $a0, 0x80($v1)
/* 0BFFF0 7F08B4C0 0FC1782D */  jal   bondwalkItemCheckBitflags
/* 0BFFF4 7F08B4C4 AFA3005C */   sw    $v1, 0x5c($sp)
/* 0BFFF8 7F08B4C8 14400003 */  bnez  $v0, .L7F08B4D8
/* 0BFFFC 7F08B4CC 8FA3005C */   lw    $v1, 0x5c($sp)
/* 0C0000 7F08B4D0 1000001F */  b     .L7F08B550
/* 0C0004 7F08B4D4 24100002 */   li    $s0, 2
.L7F08B4D8:
/* 0C0008 7F08B4D8 8FA20058 */  lw    $v0, 0x58($sp)
/* 0C000C 7F08B4DC 24050200 */  li    $a1, 512
/* 0C0010 7F08B4E0 10400008 */  beqz  $v0, .L7F08B504
/* 0C0014 7F08B4E4 00000000 */   nop
/* 0C0018 7F08B4E8 80440080 */  lb    $a0, 0x80($v0)
/* 0C001C 7F08B4EC 0FC1782D */  jal   bondwalkItemCheckBitflags
/* 0C0020 7F08B4F0 AFA3005C */   sw    $v1, 0x5c($sp)
/* 0C0024 7F08B4F4 14400003 */  bnez  $v0, .L7F08B504
/* 0C0028 7F08B4F8 8FA3005C */   lw    $v1, 0x5c($sp)
/* 0C002C 7F08B4FC 10000014 */  b     .L7F08B550
/* 0C0030 7F08B500 24100002 */   li    $s0, 2
.L7F08B504:
/* 0C0034 7F08B504 10600007 */  beqz  $v1, .L7F08B524
/* 0C0038 7F08B508 24050100 */   li    $a1, 256
/* 0C003C 7F08B50C 0FC1782D */  jal   bondwalkItemCheckBitflags
/* 0C0040 7F08B510 80640080 */   lb    $a0, 0x80($v1)
/* 0C0044 7F08B514 50400004 */  beql  $v0, $zero, .L7F08B528
/* 0C0048 7F08B518 8FA20058 */   lw    $v0, 0x58($sp)
/* 0C004C 7F08B51C 1000000C */  b     .L7F08B550
/* 0C0050 7F08B520 00008025 */   move  $s0, $zero
.L7F08B524:
/* 0C0054 7F08B524 8FA20058 */  lw    $v0, 0x58($sp)
.L7F08B528:
/* 0C0058 7F08B528 24050100 */  li    $a1, 256
/* 0C005C 7F08B52C 50400008 */  beql  $v0, $zero, .L7F08B550
/* 0C0060 7F08B530 24100001 */   li    $s0, 1
/* 0C0064 7F08B534 0FC1782D */  jal   bondwalkItemCheckBitflags
/* 0C0068 7F08B538 80440080 */   lb    $a0, 0x80($v0)
/* 0C006C 7F08B53C 50400004 */  beql  $v0, $zero, .L7F08B550
/* 0C0070 7F08B540 24100001 */   li    $s0, 1
/* 0C0074 7F08B544 10000002 */  b     .L7F08B550
/* 0C0078 7F08B548 00008025 */   move  $s0, $zero
/* 0C007C 7F08B54C 24100001 */  li    $s0, 1
.L7F08B550:
/* 0C0080 7F08B550 0FC1E687 */  jal   playerGetCrouchPos
/* 0C0084 7F08B554 8FA400F4 */   lw    $a0, 0xf4($sp)
/* 0C0088 7F08B558 24010001 */  li    $at, 1
/* 0C008C 7F08B55C 50410005 */  beql  $v0, $at, .L7F08B574
/* 0C0090 7F08B560 3C013F80 */   lui   $at, 0x3f80
/* 0C0094 7F08B564 0FC1E687 */  jal   playerGetCrouchPos
/* 0C0098 7F08B568 8FA400F4 */   lw    $a0, 0xf4($sp)
/* 0C009C 7F08B56C 14400006 */  bnez  $v0, .L7F08B588
/* 0C00A0 7F08B570 3C013F80 */   li    $at, 0x3F800000 # 1.000000
.L7F08B574:
/* 0C00A4 7F08B574 44816000 */  mtc1  $at, $f12
/* 0C00A8 7F08B578 44807000 */  mtc1  $zero, $f14
/* 0C00AC 7F08B57C 24040005 */  li    $a0, 5
/* 0C00B0 7F08B580 1000009D */  b     .L7F08B7F8
/* 0C00B4 7F08B584 8E280000 */   lw    $t0, ($s1)
.L7F08B588:
/* 0C00B8 7F08B588 8E280000 */  lw    $t0, ($s1)
/* 0C00BC 7F08B58C 44807000 */  mtc1  $zero, $f14
/* 0C00C0 7F08B590 0010C900 */  sll   $t9, $s0, 4
/* 0C00C4 7F08B594 C502016C */  lwc1  $f2, 0x16c($t0)
/* 0C00C8 7F08B598 0330C823 */  subu  $t9, $t9, $s0
/* 0C00CC 7F08B59C 0019C8C0 */  sll   $t9, $t9, 3
/* 0C00D0 7F08B5A0 460E103C */  c.lt.s $f2, $f14
/* 0C00D4 7F08B5A4 3C0A8003 */  lui   $t2, %hi(firing_animation_groups+0x50) #firing_animation_groups[440]
/* 0C00D8 7F08B5A8 01595021 */  addu  $t2, $t2, $t9
/* 0C00DC 7F08B5AC 45020014 */  bc1fl .L7F08B600
/* 0C00E0 7F08B5B0 4602703C */   c.lt.s $f14, $f2
/* 0C00E4 7F08B5B4 8D4A6928 */  lw    $t2, %lo(firing_animation_groups+0x50)($t2) #firing_animation_groups[440]
/* 0C00E8 7F08B5B8 3C0142B4 */  li    $at, 0x42B40000 # 90.000000
/* 0C00EC 7F08B5BC 51400010 */  beql  $t2, $zero, .L7F08B600
/* 0C00F0 7F08B5C0 4602703C */   c.lt.s $f14, $f2
/* 0C00F4 7F08B5C4 C5001280 */  lwc1  $f0, 0x1280($t0)
/* 0C00F8 7F08B5C8 44814000 */  mtc1  $at, $f8
/* 0C00FC 7F08B5CC 24040004 */  li    $a0, 4
/* 0C0100 7F08B5D0 46001307 */  neg.s $f12, $f2
/* 0C0104 7F08B5D4 4608003C */  c.lt.s $f0, $f8
/* 0C0108 7F08B5D8 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0C010C 7F08B5DC 45020087 */  bc1fl .L7F08B7FC
/* 0C0110 7F08B5E0 00107900 */   sll   $t7, $s0, 4
/* 0C0114 7F08B5E4 44815000 */  mtc1  $at, $f10
/* 0C0118 7F08B5E8 00000000 */  nop
/* 0C011C 7F08B5EC 460A0480 */  add.s $f18, $f0, $f10
/* 0C0120 7F08B5F0 E5121280 */  swc1  $f18, 0x1280($t0)
/* 0C0124 7F08B5F4 10000080 */  b     .L7F08B7F8
/* 0C0128 7F08B5F8 8E280000 */   lw    $t0, ($s1)
/* 0C012C 7F08B5FC 4602703C */  c.lt.s $f14, $f2
.L7F08B600:
/* 0C0130 7F08B600 00105900 */  sll   $t3, $s0, 4
/* 0C0134 7F08B604 01705823 */  subu  $t3, $t3, $s0
/* 0C0138 7F08B608 000B58C0 */  sll   $t3, $t3, 3
/* 0C013C 7F08B60C 45000014 */  bc1f  .L7F08B660
/* 0C0140 7F08B610 3C0C8003 */   lui   $t4, %hi(firing_animation_groups+0x3C)
/* 0C0144 7F08B614 018B6021 */  addu  $t4, $t4, $t3
/* 0C0148 7F08B618 8D8C6914 */  lw    $t4, %lo(firing_animation_groups+0x3C)($t4)
/* 0C014C 7F08B61C 3C01C2B4 */  li    $at, 0xC2B40000 # -90.000000
/* 0C0150 7F08B620 51800010 */  beql  $t4, $zero, .L7F08B664
/* 0C0154 7F08B624 C502014C */   lwc1  $f2, 0x14c($t0)
/* 0C0158 7F08B628 C5001280 */  lwc1  $f0, 0x1280($t0)
/* 0C015C 7F08B62C 44812000 */  mtc1  $at, $f4
/* 0C0160 7F08B630 24040003 */  li    $a0, 3
/* 0C0164 7F08B634 46001306 */  mov.s $f12, $f2
/* 0C0168 7F08B638 4600203C */  c.lt.s $f4, $f0
/* 0C016C 7F08B63C 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0C0170 7F08B640 4502006E */  bc1fl .L7F08B7FC
/* 0C0174 7F08B644 00107900 */   sll   $t7, $s0, 4
/* 0C0178 7F08B648 44813000 */  mtc1  $at, $f6
/* 0C017C 7F08B64C 00000000 */  nop
/* 0C0180 7F08B650 46060201 */  sub.s $f8, $f0, $f6
/* 0C0184 7F08B654 E5081280 */  swc1  $f8, 0x1280($t0)
/* 0C0188 7F08B658 10000067 */  b     .L7F08B7F8
/* 0C018C 7F08B65C 8E280000 */   lw    $t0, ($s1)
.L7F08B660:
/* 0C0190 7F08B660 C502014C */  lwc1  $f2, 0x14c($t0)
.L7F08B664:
/* 0C0194 7F08B664 3C018005 */  lui   $at, %hi(D_800552C0)
/* 0C0198 7F08B668 460E103C */  c.lt.s $f2, $f14
/* 0C019C 7F08B66C 00000000 */  nop
/* 0C01A0 7F08B670 45020003 */  bc1fl .L7F08B680
/* 0C01A4 7F08B674 C5000174 */   lwc1  $f0, 0x174($t0)
/* 0C01A8 7F08B678 46001087 */  neg.s $f2, $f2
/* 0C01AC 7F08B67C C5000174 */  lwc1  $f0, 0x174($t0)
.L7F08B680:
/* 0C01B0 7F08B680 C42A52C0 */  lwc1  $f10, %lo(D_800552C0)($at)
/* 0C01B4 7F08B684 3C018005 */  lui   $at, %hi(D_800552C8)
/* 0C01B8 7F08B688 460A003C */  c.lt.s $f0, $f10
/* 0C01BC 7F08B68C 00000000 */  nop
/* 0C01C0 7F08B690 4500001D */  bc1f  .L7F08B708
/* 0C01C4 7F08B694 00000000 */   nop
/* 0C01C8 7F08B698 46001087 */  neg.s $f2, $f2
/* 0C01CC 7F08B69C 3C018005 */  lui   $at, %hi(D_800552C4)
/* 0C01D0 7F08B6A0 4602003C */  c.lt.s $f0, $f2
/* 0C01D4 7F08B6A4 00000000 */  nop
/* 0C01D8 7F08B6A8 45020003 */  bc1fl .L7F08B6B8
/* 0C01DC 7F08B6AC 8D0D04E8 */   lw    $t5, 0x4e8($t0)
/* 0C01E0 7F08B6B0 46000086 */  mov.s $f2, $f0
/* 0C01E4 7F08B6B4 8D0D04E8 */  lw    $t5, 0x4e8($t0)
.L7F08B6B8:
/* 0C01E8 7F08B6B8 51A00008 */  beql  $t5, $zero, .L7F08B6DC
/* 0C01EC 7F08B6BC 46021300 */   add.s $f12, $f2, $f2
/* 0C01F0 7F08B6C0 C43252C4 */  lwc1  $f18, %lo(D_800552C4)($at)
/* 0C01F4 7F08B6C4 24040002 */  li    $a0, 2
/* 0C01F8 7F08B6C8 4600903C */  c.lt.s $f18, $f0
/* 0C01FC 7F08B6CC 00000000 */  nop
/* 0C0200 7F08B6D0 4500000B */  bc1f  .L7F08B700
/* 0C0204 7F08B6D4 00000000 */   nop
/* 0C0208 7F08B6D8 46021300 */  add.s $f12, $f2, $f2
.L7F08B6DC:
/* 0C020C 7F08B6DC 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0C0210 7F08B6E0 44818000 */  mtc1  $at, $f16
/* 0C0214 7F08B6E4 24040001 */  li    $a0, 1
/* 0C0218 7F08B6E8 4610603C */  c.lt.s $f12, $f16
/* 0C021C 7F08B6EC 00000000 */  nop
/* 0C0220 7F08B6F0 4502002D */  bc1fl .L7F08B7A8
/* 0C0224 7F08B6F4 C5001280 */   lwc1  $f0, 0x1280($t0)
/* 0C0228 7F08B6F8 1000002A */  b     .L7F08B7A4
/* 0C022C 7F08B6FC 46008306 */   mov.s $f12, $f16
.L7F08B700:
/* 0C0230 7F08B700 10000028 */  b     .L7F08B7A4
/* 0C0234 7F08B704 46001306 */   mov.s $f12, $f2
.L7F08B708:
/* 0C0238 7F08B708 C42C52C8 */  lwc1  $f12, %lo(D_800552C8)($at)
/* 0C023C 7F08B70C 4600603C */  c.lt.s $f12, $f0
/* 0C0240 7F08B710 00000000 */  nop
/* 0C0244 7F08B714 45030006 */  bc1tl .L7F08B730
/* 0C0248 7F08B718 4600103C */   c.lt.s $f2, $f0
/* 0C024C 7F08B71C 4602603C */  c.lt.s $f12, $f2
/* 0C0250 7F08B720 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C0254 7F08B724 4502001E */  bc1fl .L7F08B7A0
/* 0C0258 7F08B728 44816000 */   mtc1  $at, $f12
/* 0C025C 7F08B72C 4600103C */  c.lt.s $f2, $f0
.L7F08B730:
/* 0C0260 7F08B730 3C018005 */  lui    $at, %hi(D_800552CC)
/* 0C0264 7F08B734 45020003 */  bc1fl .L7F08B744
/* 0C0268 7F08B738 8D0E04E8 */   lw    $t6, 0x4e8($t0)
/* 0C026C 7F08B73C 46000086 */  mov.s $f2, $f0
/* 0C0270 7F08B740 8D0E04E8 */  lw    $t6, 0x4e8($t0)
.L7F08B744:
/* 0C0274 7F08B744 51C00008 */  beql  $t6, $zero, .L7F08B768
/* 0C0278 7F08B748 46021300 */   add.s $f12, $f2, $f2
/* 0C027C 7F08B74C C42452CC */  lwc1  $f4, %lo(D_800552CC)($at)
/* 0C0280 7F08B750 24040002 */  li    $a0, 2
/* 0C0284 7F08B754 4604003C */  c.lt.s $f0, $f4
/* 0C0288 7F08B758 00000000 */  nop
/* 0C028C 7F08B75C 4500000D */  bc1f  .L7F08B794
/* 0C0290 7F08B760 00000000 */   nop
/* 0C0294 7F08B764 46021300 */  add.s $f12, $f2, $f2
.L7F08B768:
/* 0C0298 7F08B768 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C029C 7F08B76C 44813000 */  mtc1  $at, $f6
/* 0C02A0 7F08B770 24040001 */  li    $a0, 1
/* 0C02A4 7F08B774 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C02A8 7F08B778 460C303C */  c.lt.s $f6, $f12
/* 0C02AC 7F08B77C 00000000 */  nop
/* 0C02B0 7F08B780 45020009 */  bc1fl .L7F08B7A8
/* 0C02B4 7F08B784 C5001280 */   lwc1  $f0, 0x1280($t0)
/* 0C02B8 7F08B788 44816000 */  mtc1  $at, $f12
/* 0C02BC 7F08B78C 10000006 */  b     .L7F08B7A8
/* 0C02C0 7F08B790 C5001280 */   lwc1  $f0, 0x1280($t0)
.L7F08B794:
/* 0C02C4 7F08B794 10000003 */  b     .L7F08B7A4
/* 0C02C8 7F08B798 46001306 */   mov.s $f12, $f2
/* 0C02CC 7F08B79C 44816000 */  mtc1  $at, $f12
.L7F08B7A0:
/* 0C02D0 7F08B7A0 00002025 */  move  $a0, $zero
.L7F08B7A4:
/* 0C02D4 7F08B7A4 C5001280 */  lwc1  $f0, 0x1280($t0)
.L7F08B7A8:
/* 0C02D8 7F08B7A8 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0C02DC 7F08B7AC 4600703C */  c.lt.s $f14, $f0
/* 0C02E0 7F08B7B0 00000000 */  nop
/* 0C02E4 7F08B7B4 45020008 */  bc1fl .L7F08B7D8
/* 0C02E8 7F08B7B8 460E003C */   c.lt.s $f0, $f14
/* 0C02EC 7F08B7BC 44814000 */  mtc1  $at, $f8
/* 0C02F0 7F08B7C0 00000000 */  nop
/* 0C02F4 7F08B7C4 46080281 */  sub.s $f10, $f0, $f8
/* 0C02F8 7F08B7C8 E50A1280 */  swc1  $f10, 0x1280($t0)
/* 0C02FC 7F08B7CC 8E280000 */  lw    $t0, ($s1)
/* 0C0300 7F08B7D0 C5001280 */  lwc1  $f0, 0x1280($t0)
/* 0C0304 7F08B7D4 460E003C */  c.lt.s $f0, $f14
.L7F08B7D8:
/* 0C0308 7F08B7D8 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0C030C 7F08B7DC 45020007 */  bc1fl .L7F08B7FC
/* 0C0310 7F08B7E0 00107900 */   sll   $t7, $s0, 4
/* 0C0314 7F08B7E4 44819000 */  mtc1  $at, $f18
/* 0C0318 7F08B7E8 00000000 */  nop
/* 0C031C 7F08B7EC 46120100 */  add.s $f4, $f0, $f18
/* 0C0320 7F08B7F0 E5041280 */  swc1  $f4, 0x1280($t0)
/* 0C0324 7F08B7F4 8E280000 */  lw    $t0, ($s1)
.L7F08B7F8:
/* 0C0328 7F08B7F8 00107900 */  sll   $t7, $s0, 4
.L7F08B7FC:
/* 0C032C 7F08B7FC 0004C080 */  sll   $t8, $a0, 2
/* 0C0330 7F08B800 0304C021 */  addu  $t8, $t8, $a0
/* 0C0334 7F08B804 01F07823 */  subu  $t7, $t7, $s0
/* 0C0338 7F08B808 000F78C0 */  sll   $t7, $t7, 3
/* 0C033C 7F08B80C 0018C080 */  sll   $t8, $t8, 2
/* 0C0340 7F08B810 3C198003 */  lui   $t9, %hi(firing_animation_groups)
/* 0C0344 7F08B814 273968D8 */  addiu $t9, %lo(firing_animation_groups) # addiu $t9, $t9, 0x68d8
/* 0C0348 7F08B818 01F84821 */  addu  $t1, $t7, $t8
/* 0C034C 7F08B81C 01391021 */  addu  $v0, $t1, $t9
/* 0C0350 7F08B820 8C430004 */  lw    $v1, 4($v0)
/* 0C0354 7F08B824 8C4A0000 */  lw    $t2, ($v0)
/* 0C0358 7F08B828 3C0B8007 */  lui   $t3, %hi(ptr_animation_table)
/* 0C035C 7F08B82C 10600004 */  beqz  $v1, .L7F08B840
/* 0C0360 7F08B830 AFAA007C */   sw    $t2, 0x7c($sp)
/* 0C0364 7F08B834 8D6B9538 */  lw    $t3, %lo(ptr_animation_table)($t3)
/* 0C0368 7F08B838 006B6021 */  addu  $t4, $v1, $t3
/* 0C036C 7F08B83C AFAC009C */  sw    $t4, 0x9c($sp)
.L7F08B840:
/* 0C0370 7F08B840 C4460008 */  lwc1  $f6, 8($v0)
/* 0C0374 7F08B844 C4480010 */  lwc1  $f8, 0x10($v0)
/* 0C0378 7F08B848 C442000C */  lwc1  $f2, 0xc($v0)
/* 0C037C 7F08B84C 46066302 */  mul.s $f12, $f12, $f6
/* 0C0380 7F08B850 E7A80090 */  swc1  $f8, 0x90($sp)
/* 0C0384 7F08B854 8D061284 */  lw    $a2, 0x1284($t0)
.L7F08B858:
/* 0C0388 7F08B858 8FAD007C */  lw    $t5, 0x7c($sp)
/* 0C038C 7F08B85C 8FAE009C */  lw    $t6, 0x9c($sp)
/* 0C0390 7F08B860 24020001 */  li    $v0, 1
/* 0C0394 7F08B864 51A00006 */  beql  $t5, $zero, .L7F08B880
/* 0C0398 7F08B868 8FB8009C */   lw    $t8, 0x9c($sp)
/* 0C039C 7F08B86C 55C00004 */  bnezl $t6, .L7F08B880
/* 0C03A0 7F08B870 8FB8009C */   lw    $t8, 0x9c($sp)
/* 0C03A4 7F08B874 8DAF0000 */  lw    $t7, ($t5)
/* 0C03A8 7F08B878 AFAF009C */  sw    $t7, 0x9c($sp)
/* 0C03AC 7F08B87C 8FB8009C */  lw    $t8, 0x9c($sp)
.L7F08B880:
/* 0C03B0 7F08B880 53060003 */  beql  $t8, $a2, .L7F08B890
/* 0C03B4 7F08B884 4602703E */   c.le.s $f14, $f2
/* 0C03B8 7F08B888 AFA20054 */  sw    $v0, 0x54($sp)
/* 0C03BC 7F08B88C 4602703E */  c.le.s $f14, $f2
.L7F08B890:
/* 0C03C0 7F08B890 8FA20054 */  lw    $v0, 0x54($sp)
/* 0C03C4 7F08B894 4502000C */  bc1fl .L7F08B8C8
/* 0C03C8 7F08B898 460E103C */   c.lt.s $f2, $f14
/* 0C03CC 7F08B89C 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0C03D0 7F08B8A0 80890026 */  lb    $t1, 0x26($a0)
/* 0C03D4 7F08B8A4 51200007 */  beql  $t1, $zero, .L7F08B8C4
/* 0C03D8 7F08B8A8 24020001 */   li    $v0, 1
/* 0C03DC 7F08B8AC C48A0090 */  lwc1  $f10, 0x90($a0)
/* 0C03E0 7F08B8B0 460A1032 */  c.eq.s $f2, $f10
/* 0C03E4 7F08B8B4 00000000 */  nop
/* 0C03E8 7F08B8B8 45030003 */  bc1tl .L7F08B8C8
/* 0C03EC 7F08B8BC 460E103C */   c.lt.s $f2, $f14
/* 0C03F0 7F08B8C0 24020001 */  li    $v0, 1
.L7F08B8C4:
/* 0C03F4 7F08B8C4 460E103C */  c.lt.s $f2, $f14
.L7F08B8C8:
/* 0C03F8 7F08B8C8 00000000 */  nop
/* 0C03FC 7F08B8CC 45000006 */  bc1f  .L7F08B8E8
/* 0C0400 7F08B8D0 00000000 */   nop
/* 0C0404 7F08B8D4 8D1900D4 */  lw    $t9, 0xd4($t0)
/* 0C0408 7F08B8D8 832A0026 */  lb    $t2, 0x26($t9)
/* 0C040C 7F08B8DC 11400002 */  beqz  $t2, .L7F08B8E8
/* 0C0410 7F08B8E0 00000000 */   nop
/* 0C0414 7F08B8E4 24020001 */  li    $v0, 1
.L7F08B8E8:
/* 0C0418 7F08B8E8 50400035 */  beql  $v0, $zero, .L7F08B9C0
/* 0C041C 7F08B8EC C5061288 */   lwc1  $f6, 0x1288($t0)
/* 0C0420 7F08B8F0 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0C0424 7F08B8F4 8FA5009C */  lw    $a1, 0x9c($sp)
/* 0C0428 7F08B8F8 00003025 */  move  $a2, $zero
/* 0C042C 7F08B8FC 8C8B0054 */  lw    $t3, 0x54($a0)
/* 0C0430 7F08B900 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 0C0434 7F08B904 5560002B */  bnezl $t3, .L7F08B9B4
/* 0C0438 7F08B908 8E290000 */   lw    $t1, ($s1)
/* 0C043C 7F08B90C 4602703E */  c.le.s $f14, $f2
/* 0C0440 7F08B910 44819000 */  mtc1  $at, $f18
/* 0C0444 7F08B914 45020004 */  bc1fl .L7F08B928
/* 0C0448 7F08B918 46007006 */   mov.s $f0, $f14
/* 0C044C 7F08B91C 10000002 */  b     .L7F08B928
/* 0C0450 7F08B920 46001006 */   mov.s $f0, $f2
/* 0C0454 7F08B924 46007006 */  mov.s $f0, $f14
.L7F08B928:
/* 0C0458 7F08B928 44070000 */  mfc1  $a3, $f0
/* 0C045C 7F08B92C E7AC0010 */  swc1  $f12, 0x10($sp)
/* 0C0460 7F08B930 E7B20014 */  swc1  $f18, 0x14($sp)
/* 0C0464 7F08B934 E7A20094 */  swc1  $f2, 0x94($sp)
/* 0C0468 7F08B938 0FC1BF2A */  jal   modelSetAnimation
/* 0C046C 7F08B93C E7AC0098 */   swc1  $f12, 0x98($sp)
/* 0C0470 7F08B940 C7A20094 */  lwc1  $f2, 0x94($sp)
/* 0C0474 7F08B944 44807000 */  mtc1  $zero, $f14
/* 0C0478 7F08B948 8FAC009C */  lw    $t4, 0x9c($sp)
/* 0C047C 7F08B94C 8E2E0000 */  lw    $t6, ($s1)
/* 0C0480 7F08B950 4602703E */  c.le.s $f14, $f2
/* 0C0484 7F08B954 C7AC0098 */  lwc1  $f12, 0x98($sp)
/* 0C0488 7F08B958 ADCC1284 */  sw    $t4, 0x1284($t6)
/* 0C048C 7F08B95C 8E2D0000 */  lw    $t5, ($s1)
/* 0C0490 7F08B960 3C064180 */  lui   $a2, 0x4180
/* 0C0494 7F08B964 45000007 */  bc1f  .L7F08B984
/* 0C0498 7F08B968 E5AC1288 */   swc1  $f12, 0x1288($t5)
/* 0C049C 7F08B96C 8E2F0000 */  lw    $t7, ($s1)
/* 0C04A0 7F08B970 44051000 */  mfc1  $a1, $f2
/* 0C04A4 7F08B974 0FC1BF73 */  jal   modelSetAnimLooping
/* 0C04A8 7F08B978 8DE400D4 */   lw    $a0, 0xd4($t7)
/* 0C04AC 7F08B97C 44807000 */  mtc1  $zero, $f14
/* 0C04B0 7F08B980 00000000 */  nop
.L7F08B984:
/* 0C04B4 7F08B984 C7A40090 */  lwc1  $f4, 0x90($sp)
/* 0C04B8 7F08B988 4604703E */  c.le.s $f14, $f4
/* 0C04BC 7F08B98C 00000000 */  nop
/* 0C04C0 7F08B990 45020008 */  bc1fl .L7F08B9B4
/* 0C04C4 7F08B994 8E290000 */   lw    $t1, ($s1)
/* 0C04C8 7F08B998 8E380000 */  lw    $t8, ($s1)
/* 0C04CC 7F08B99C 44052000 */  mfc1  $a1, $f4
/* 0C04D0 7F08B9A0 0FC1BF7A */  jal   modelSetAnimEndFrame
/* 0C04D4 7F08B9A4 8F0400D4 */   lw    $a0, 0xd4($t8)
/* 0C04D8 7F08B9A8 44807000 */  mtc1  $zero, $f14
/* 0C04DC 7F08B9AC 00000000 */  nop
/* 0C04E0 7F08B9B0 8E290000 */  lw    $t1, ($s1)
.L7F08B9B4:
/* 0C04E4 7F08B9B4 10000011 */  b     .L7F08B9FC
/* 0C04E8 7F08B9B8 8D261284 */   lw    $a2, 0x1284($t1)
/* 0C04EC 7F08B9BC C5061288 */  lwc1  $f6, 0x1288($t0)
.L7F08B9C0:
/* 0C04F0 7F08B9C0 46066032 */  c.eq.s $f12, $f6
/* 0C04F4 7F08B9C4 00000000 */  nop
/* 0C04F8 7F08B9C8 4503000D */  bc1tl .L7F08BA00
/* 0C04FC 7F08B9CC 8FAB009C */   lw    $t3, 0x9c($sp)
/* 0C0500 7F08B9D0 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0C0504 7F08B9D4 44056000 */  mfc1  $a1, $f12
/* 0C0508 7F08B9D8 E7AC0098 */  swc1  $f12, 0x98($sp)
/* 0C050C 7F08B9DC 0FC1BF93 */  jal   modelSetAnimSpeed
/* 0C0510 7F08B9E0 3C063F80 */   lui   $a2, 0x3f80
/* 0C0514 7F08B9E4 C7AC0098 */  lwc1  $f12, 0x98($sp)
/* 0C0518 7F08B9E8 8E390000 */  lw    $t9, ($s1)
/* 0C051C 7F08B9EC 44807000 */  mtc1  $zero, $f14
/* 0C0520 7F08B9F0 E72C1288 */  swc1  $f12, 0x1288($t9)
/* 0C0524 7F08B9F4 8E2A0000 */  lw    $t2, ($s1)
/* 0C0528 7F08B9F8 8D461284 */  lw    $a2, 0x1284($t2)
.L7F08B9FC:
/* 0C052C 7F08B9FC 8FAB009C */  lw    $t3, 0x9c($sp)
.L7F08BA00:
/* 0C0530 7F08BA00 8FAC007C */  lw    $t4, 0x7c($sp)
/* 0C0534 7F08BA04 55660017 */  bnel  $t3, $a2, .L7F08BA64
/* 0C0538 7F08BA08 8FA200F0 */   lw    $v0, 0xf0($sp)
/* 0C053C 7F08BA0C 1180000D */  beqz  $t4, .L7F08BA44
/* 0C0540 7F08BA10 8FAF00F0 */   lw    $t7, 0xf0($sp)
/* 0C0544 7F08BA14 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0C0548 7F08BA18 00003025 */  move  $a2, $zero
/* 0C054C 7F08BA1C 24070001 */  li    $a3, 1
/* 0C0550 7F08BA20 948E0012 */  lhu   $t6, 0x12($a0)
/* 0C0554 7F08BA24 31CDFBFF */  andi  $t5, $t6, 0xfbff
/* 0C0558 7F08BA28 A48D0012 */  sh    $t5, 0x12($a0)
/* 0C055C 7F08BA2C C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 0C0560 7F08BA30 8FA5007C */  lw    $a1, 0x7c($sp)
/* 0C0564 7F08BA34 0FC0B412 */  jal   chrlvUpdateAimendbackShoulders
/* 0C0568 7F08BA38 E7A80010 */   swc1  $f8, 0x10($sp)
/* 0C056C 7F08BA3C 10000009 */  b     .L7F08BA64
/* 0C0570 7F08BA40 8FA200F0 */   lw    $v0, 0xf0($sp)
.L7F08BA44:
/* 0C0574 7F08BA44 95F80012 */  lhu   $t8, 0x12($t7)
/* 0C0578 7F08BA48 E5EE0154 */  swc1  $f14, 0x154($t7)
/* 0C057C 7F08BA4C E5EE0150 */  swc1  $f14, 0x150($t7)
/* 0C0580 7F08BA50 37090400 */  ori   $t1, $t8, 0x400
/* 0C0584 7F08BA54 A5E90012 */  sh    $t1, 0x12($t7)
/* 0C0588 7F08BA58 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 0C058C 7F08BA5C E5EA0158 */  swc1  $f10, 0x158($t7)
/* 0C0590 7F08BA60 8FA200F0 */  lw    $v0, 0xf0($sp)
.L7F08BA64:
/* 0C0594 7F08BA64 C7B20088 */  lwc1  $f18, 0x88($sp)
/* 0C0598 7F08BA68 2419000A */  li    $t9, 10
/* 0C059C 7F08BA6C A059000E */  sb    $t9, 0xe($v0)
/* 0C05A0 7F08BA70 E452015C */  swc1  $f18, 0x15c($v0)
/* 0C05A4 7F08BA74 8E2A0000 */  lw    $t2, ($s1)
.L7F08BA78:
/* 0C05A8 7F08BA78 8FA300F8 */  lw    $v1, 0xf8($sp)
/* 0C05AC 7F08BA7C 8FA200F0 */  lw    $v0, 0xf0($sp)
/* 0C05B0 7F08BA80 C544048C */  lwc1  $f4, 0x48c($t2)
/* 0C05B4 7F08BA84 27A50070 */  addiu $a1, $sp, 0x70
/* 0C05B8 7F08BA88 00008025 */  move  $s0, $zero
/* 0C05BC 7F08BA8C E4640008 */  swc1  $f4, 8($v1)
/* 0C05C0 7F08BA90 8E2B0000 */  lw    $t3, ($s1)
/* 0C05C4 7F08BA94 C5660490 */  lwc1  $f6, 0x490($t3)
/* 0C05C8 7F08BA98 E466000C */  swc1  $f6, 0xc($v1)
/* 0C05CC 7F08BA9C 8E2C0000 */  lw    $t4, ($s1)
/* 0C05D0 7F08BAA0 C5880494 */  lwc1  $f8, 0x494($t4)
/* 0C05D4 7F08BAA4 E4680010 */  swc1  $f8, 0x10($v1)
/* 0C05D8 7F08BAA8 8E2E0000 */  lw    $t6, ($s1)
/* 0C05DC 7F08BAAC 8DCD0488 */  lw    $t5, 0x488($t6)
/* 0C05E0 7F08BAB0 AC6D0014 */  sw    $t5, 0x14($v1)
/* 0C05E4 7F08BAB4 0FC1B2E6 */  jal   getsuboffset
/* 0C05E8 7F08BAB8 8C44001C */   lw    $a0, 0x1c($v0)
/* 0C05EC 7F08BABC 8FA200F8 */  lw    $v0, 0xf8($sp)
/* 0C05F0 7F08BAC0 8FB800F0 */  lw    $t8, 0xf0($sp)
/* 0C05F4 7F08BAC4 27A50070 */  addiu $a1, $sp, 0x70
/* 0C05F8 7F08BAC8 C44A0008 */  lwc1  $f10, 8($v0)
/* 0C05FC 7F08BACC E7AA0070 */  swc1  $f10, 0x70($sp)
/* 0C0600 7F08BAD0 C4520010 */  lwc1  $f18, 0x10($v0)
/* 0C0604 7F08BAD4 E7B20078 */  swc1  $f18, 0x78($sp)
/* 0C0608 7F08BAD8 0FC1B303 */  jal   setsuboffset
/* 0C060C 7F08BADC 8F04001C */   lw    $a0, 0x1c($t8)
/* 0C0610 7F08BAE0 8E280000 */  lw    $t0, ($s1)
/* 0C0614 7F08BAE4 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0C0618 7F08BAE8 44810000 */  mtc1  $at, $f0
/* 0C061C 7F08BAEC C5060148 */  lwc1  $f6, 0x148($t0)
/* 0C0620 7F08BAF0 C5041280 */  lwc1  $f4, 0x1280($t0)
/* 0C0624 7F08BAF4 3C018005 */  lui   $at, %hi(D_800552D0)
/* 0C0628 7F08BAF8 46060201 */  sub.s $f8, $f0, $f6
/* 0C062C 7F08BAFC C43252D0 */  lwc1  $f18, %lo(D_800552D0)($at)
/* 0C0630 7F08BB00 8FA900F0 */  lw    $t1, 0xf0($sp)
/* 0C0634 7F08BB04 46082280 */  add.s $f10, $f4, $f8
/* 0C0638 7F08BB08 8D24001C */  lw    $a0, 0x1c($t1)
/* 0C063C 7F08BB0C 46125182 */  mul.s $f6, $f10, $f18
/* 0C0640 7F08BB10 46003103 */  div.s $f4, $f6, $f0
/* 0C0644 7F08BB14 44052000 */  mfc1  $a1, $f4
/* 0C0648 7F08BB18 0FC1B34F */  jal   setsubroty
/* 0C064C 7F08BB1C 00000000 */   nop
/* 0C0650 7F08BB20 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0C0654 7F08BB24 240A0019 */  li    $t2, 25
/* 0C0658 7F08BB28 00002825 */  move  $a1, $zero
/* 0C065C 7F08BB2C 8C8F0014 */  lw    $t7, 0x14($a0)
/* 0C0660 7F08BB30 A08A0007 */  sb    $t2, 7($a0)
/* 0C0664 7F08BB34 35F90001 */  ori   $t9, $t7, 1
/* 0C0668 7F08BB38 AC990014 */  sw    $t9, 0x14($a0)
/* 0C066C 7F08BB3C 8FAB007C */  lw    $t3, 0x7c($sp)
/* 0C0670 7F08BB40 AC8B002C */  sw    $t3, 0x2c($a0)
/* 0C0674 7F08BB44 8E2C0000 */  lw    $t4, ($s1)
/* 0C0678 7F08BB48 0FC0B446 */  jal   chrSetFiring
/* 0C067C 7F08BB4C 8186087D */   lb    $a2, 0x87d($t4)
/* 0C0680 7F08BB50 8E2E0000 */  lw    $t6, ($s1)
/* 0C0684 7F08BB54 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0C0688 7F08BB58 24050001 */  li    $a1, 1
/* 0C068C 7F08BB5C 0FC0B446 */  jal   chrSetFiring
/* 0C0690 7F08BB60 81C60C25 */   lb    $a2, 0xc25($t6)
/* 0C0694 7F08BB64 0FC083BC */  jal   sub_GAME_7F020EF0
/* 0C0698 7F08BB68 8FA400F8 */   lw    $a0, 0xf8($sp)
/* 0C069C 7F08BB6C AFA200A0 */  sw    $v0, 0xa0($sp)
/* 0C06A0 7F08BB70 00003825 */  move  $a3, $zero
/* 0C06A4 7F08BB74 00001825 */  move  $v1, $zero
.L7F08BB78:
/* 0C06A8 7F08BB78 8E2D0000 */  lw    $t5, ($s1)
/* 0C06AC 7F08BB7C 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0C06B0 7F08BB80 02002825 */  move  $a1, $s0
/* 0C06B4 7F08BB84 01A33021 */  addu  $a2, $t5, $v1
/* 0C06B8 7F08BB88 24C62A18 */  addiu $a2, $a2, 0x2a18
/* 0C06BC 7F08BB8C AFA30034 */  sw    $v1, 0x34($sp)
/* 0C06C0 7F08BB90 0FC0B58C */  jal   sub_GAME_7F02D630
/* 0C06C4 7F08BB94 AFA70038 */   sw    $a3, 0x38($sp)
/* 0C06C8 7F08BB98 8FA30034 */  lw    $v1, 0x34($sp)
/* 0C06CC 7F08BB9C 10400007 */  beqz  $v0, .L7F08BBBC
/* 0C06D0 7F08BBA0 8FA70038 */   lw    $a3, 0x38($sp)
/* 0C06D4 7F08BBA4 8E290000 */  lw    $t1, ($s1)
/* 0C06D8 7F08BBA8 3C188005 */  lui   $t8, %hi(D_80048380)
/* 0C06DC 7F08BBAC 8F188380 */  lw    $t8, %lo(D_80048380)($t8)
/* 0C06E0 7F08BBB0 01277821 */  addu  $t7, $t1, $a3
/* 0C06E4 7F08BBB4 1000001E */  b     .L7F08BC30
/* 0C06E8 7F08BBB8 ADF82A30 */   sw    $t8, 0x2a30($t7)
.L7F08BBBC:
/* 0C06EC 7F08BBBC 8E280000 */  lw    $t0, ($s1)
/* 0C06F0 7F08BBC0 3C0B8005 */  lui   $t3, %hi(D_80048380)
/* 0C06F4 7F08BBC4 8D6B8380 */  lw    $t3, %lo(D_80048380)($t3)
/* 0C06F8 7F08BBC8 0107C821 */  addu  $t9, $t0, $a3
/* 0C06FC 7F08BBCC 8F2A2A30 */  lw    $t2, 0x2a30($t9)
/* 0C0700 7F08BBD0 256CFFFF */  addiu $t4, $t3, -1
/* 0C0704 7F08BBD4 001010C0 */  sll   $v0, $s0, 3
/* 0C0708 7F08BBD8 014C082A */  slt   $at, $t2, $t4
/* 0C070C 7F08BBDC 10200014 */  beqz  $at, .L7F08BC30
/* 0C0710 7F08BBE0 00501023 */   subu  $v0, $v0, $s0
/* 0C0714 7F08BBE4 00021080 */  sll   $v0, $v0, 2
/* 0C0718 7F08BBE8 00501021 */  addu  $v0, $v0, $s0
/* 0C071C 7F08BBEC 00021080 */  sll   $v0, $v0, 2
/* 0C0720 7F08BBF0 00501021 */  addu  $v0, $v0, $s0
/* 0C0724 7F08BBF4 000210C0 */  sll   $v0, $v0, 3
/* 0C0728 7F08BBF8 01027021 */  addu  $t6, $t0, $v0
/* 0C072C 7F08BBFC C5C80B58 */  lwc1  $f8, 0xb58($t6)
/* 0C0730 7F08BC00 01036821 */  addu  $t5, $t0, $v1
/* 0C0734 7F08BC04 E5A82A18 */  swc1  $f8, 0x2a18($t5)
/* 0C0738 7F08BC08 8E280000 */  lw    $t0, ($s1)
/* 0C073C 7F08BC0C 01024821 */  addu  $t1, $t0, $v0
/* 0C0740 7F08BC10 C52A0B5C */  lwc1  $f10, 0xb5c($t1)
/* 0C0744 7F08BC14 0103C021 */  addu  $t8, $t0, $v1
/* 0C0748 7F08BC18 E70A2A1C */  swc1  $f10, 0x2a1c($t8)
/* 0C074C 7F08BC1C 8E280000 */  lw    $t0, ($s1)
/* 0C0750 7F08BC20 01027821 */  addu  $t7, $t0, $v0
/* 0C0754 7F08BC24 C5F20B60 */  lwc1  $f18, 0xb60($t7)
/* 0C0758 7F08BC28 0103C821 */  addu  $t9, $t0, $v1
/* 0C075C 7F08BC2C E7322A20 */  swc1  $f18, 0x2a20($t9)
.L7F08BC30:
/* 0C0760 7F08BC30 26100001 */  addiu $s0, $s0, 1
/* 0C0764 7F08BC34 24010002 */  li    $at, 2
/* 0C0768 7F08BC38 24E70004 */  addiu $a3, $a3, 4
/* 0C076C 7F08BC3C 1601FFCE */  bne   $s0, $at, .L7F08BB78
/* 0C0770 7F08BC40 2463000C */   addiu $v1, $v1, 0xc
/* 0C0774 7F08BC44 8FAB00F0 */  lw    $t3, 0xf0($sp)
/* 0C0778 7F08BC48 956A0012 */  lhu   $t2, 0x12($t3)
/* 0C077C 7F08BC4C 354C0800 */  ori   $t4, $t2, 0x800
/* 0C0780 7F08BC50 A56C0012 */  sh    $t4, 0x12($t3)
/* 0C0784 7F08BC54 8E2E0000 */  lw    $t6, ($s1)
/* 0C0788 7F08BC58 8FAD00F8 */  lw    $t5, 0xf8($sp)
/* 0C078C 7F08BC5C C5C6048C */  lwc1  $f6, 0x48c($t6)
/* 0C0790 7F08BC60 E5A60008 */  swc1  $f6, 8($t5)
/* 0C0794 7F08BC64 8E290000 */  lw    $t1, ($s1)
/* 0C0798 7F08BC68 C5240490 */  lwc1  $f4, 0x490($t1)
/* 0C079C 7F08BC6C E5A4000C */  swc1  $f4, 0xc($t5)
/* 0C07A0 7F08BC70 8E380000 */  lw    $t8, ($s1)
/* 0C07A4 7F08BC74 C7080494 */  lwc1  $f8, 0x494($t8)
/* 0C07A8 7F08BC78 E5A80010 */  swc1  $f8, 0x10($t5)
/* 0C07AC 7F08BC7C 8E2F0000 */  lw    $t7, ($s1)
/* 0C07B0 7F08BC80 8DF90488 */  lw    $t9, 0x488($t7)
/* 0C07B4 7F08BC84 ADB90014 */  sw    $t9, 0x14($t5)
/* 0C07B8 7F08BC88 10000006 */  b     .L7F08BCA4
/* 0C07BC 7F08BC8C 8FA200A0 */   lw    $v0, 0xa0($sp)
.L7F08BC90:
/* 0C07C0 7F08BC90 8FAA00F8 */  lw    $t2, 0xf8($sp)
.L7F08BC94:
/* 0C07C4 7F08BC94 00001025 */  move  $v0, $zero
/* 0C07C8 7F08BC98 914C0001 */  lbu   $t4, 1($t2)
/* 0C07CC 7F08BC9C 318BFFFD */  andi  $t3, $t4, 0xfffd
/* 0C07D0 7F08BCA0 A14B0001 */  sb    $t3, 1($t2)
.L7F08BCA4:
/* 0C07D4 7F08BCA4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0C07D8 7F08BCA8 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0C07DC 7F08BCAC 8FB10020 */  lw    $s1, 0x20($sp)
/* 0C07E0 7F08BCB0 03E00008 */  jr    $ra
/* 0C07E4 7F08BCB4 27BD00F8 */   addiu $sp, $sp, 0xf8
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8004AE94
.word 0xbd4ccccd
glabel D_8004AE98
.word 0xbecccccd
glabel D_8004AE9C
.word 0x3d4ccccd
glabel D_8004AEA0
.word 0x3ecccccd
glabel D_8004AEA4
.word 0x40c90fdb

.text
glabel sub_GAME_7F08B0F0
/* 0BDDD4 7F08B3E4 27BDFF08 */  addiu $sp, $sp, -0xf8
/* 0BDDD8 7F08B3E8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0BDDDC 7F08B3EC AFB10020 */  sw    $s1, 0x20($sp)
/* 0BDDE0 7F08B3F0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0BDDE4 7F08B3F4 0FC269A7 */  jal   getPlayerPointerIndex
/* 0BDDE8 7F08B3F8 AFA400F8 */   sw    $a0, 0xf8($sp)
/* 0BDDEC 7F08B3FC 8FAE00F8 */  lw    $t6, 0xf8($sp)
/* 0BDDF0 7F08B400 AFA200F4 */  sw    $v0, 0xf4($sp)
/* 0BDDF4 7F08B404 8DCF0004 */  lw    $t7, 4($t6)
/* 0BDDF8 7F08B408 11E0000B */  beqz  $t7, .L7F08B438
/* 0BDDFC 7F08B40C AFAF00F0 */   sw    $t7, 0xf0($sp)
/* 0BDE00 7F08B410 0FC269A4 */  jal   get_cur_playernum
/* 0BDE04 7F08B414 00000000 */   nop   
/* 0BDE08 7F08B418 0FC26A86 */  jal   sub_GAME_7F09B4D8
/* 0BDE0C 7F08B41C 00402025 */   move  $a0, $v0
/* 0BDE10 7F08B420 54400006 */  bnezl $v0, .L7F08B43C
/* 0BDE14 7F08B424 8FA900F0 */   lw    $t1, 0xf0($sp)
/* 0BDE18 7F08B428 8FA200F0 */  lw    $v0, 0xf0($sp)
/* 0BDE1C 7F08B42C 94580012 */  lhu   $t8, 0x12($v0)
/* 0BDE20 7F08B430 3319F7FF */  andi  $t9, $t8, 0xf7ff
/* 0BDE24 7F08B434 A4590012 */  sh    $t9, 0x12($v0)
.L7F08B438:
/* 0BDE28 7F08B438 8FA900F0 */  lw    $t1, 0xf0($sp)
.L7F08B43C:
/* 0BDE2C 7F08B43C 8FAA00F4 */  lw    $t2, 0xf4($sp)
/* 0BDE30 7F08B440 3C0C8007 */  lui   $t4, %hi(g_playerPointers) # $t4, 0x8007
/* 0BDE34 7F08B444 1120004D */  beqz  $t1, .L7F08B57C
/* 0BDE38 7F08B448 000A5880 */   sll   $t3, $t2, 2
/* 0BDE3C 7F08B44C 258C89F0 */  addiu $t4, %lo(g_playerPointers) # addiu $t4, $t4, -0x7610
/* 0BDE40 7F08B450 016C8821 */  addu  $s1, $t3, $t4
/* 0BDE44 7F08B454 8E2D0000 */  lw    $t5, ($s1)
/* 0BDE48 7F08B458 8DAE00D4 */  lw    $t6, 0xd4($t5)
/* 0BDE4C 7F08B45C 51C00048 */  beql  $t6, $zero, .L7F08B580
/* 0BDE50 7F08B460 8FAF00F0 */   lw    $t7, 0xf0($sp)
/* 0BDE54 7F08B464 0FC240F8 */  jal   get_debug_render_raster
/* 0BDE58 7F08B468 00000000 */   nop   
/* 0BDE5C 7F08B46C 50400007 */  beql  $v0, $zero, .L7F08B48C
/* 0BDE60 7F08B470 8E390000 */   lw    $t9, ($s1)
/* 0BDE64 7F08B474 8E2F0000 */  lw    $t7, ($s1)
/* 0BDE68 7F08B478 24010001 */  li    $at, 1
/* 0BDE6C 7F08B47C 8DF80000 */  lw    $t8, ($t7)
/* 0BDE70 7F08B480 5701003F */  bnel  $t8, $at, .L7F08B580
/* 0BDE74 7F08B484 8FAF00F0 */   lw    $t7, 0xf0($sp)
/* 0BDE78 7F08B488 8E390000 */  lw    $t9, ($s1)
.L7F08B48C:
/* 0BDE7C 7F08B48C AF2000AC */  sw    $zero, 0xac($t9)
/* 0BDE80 7F08B490 0FC0839A */  jal   sub_GAME_7F020EF0
/* 0BDE84 7F08B494 8FA400F8 */   lw    $a0, 0xf8($sp)
/* 0BDE88 7F08B498 8E2A0000 */  lw    $t2, ($s1)
/* 0BDE8C 7F08B49C AFA200E8 */  sw    $v0, 0xe8($sp)
/* 0BDE90 7F08B4A0 24090001 */  li    $t1, 1
/* 0BDE94 7F08B4A4 AD4900AC */  sw    $t1, 0xac($t2)
/* 0BDE98 7F08B4A8 8E280000 */  lw    $t0, ($s1)
/* 0BDE9C 7F08B4AC 8D0B00A8 */  lw    $t3, 0xa8($t0)
/* 0BDEA0 7F08B4B0 C5640008 */  lwc1  $f4, 8($t3)
/* 0BDEA4 7F08B4B4 E504048C */  swc1  $f4, 0x48c($t0)
/* 0BDEA8 7F08B4B8 8E280000 */  lw    $t0, ($s1)
/* 0BDEAC 7F08B4BC 8D0C00A8 */  lw    $t4, 0xa8($t0)
/* 0BDEB0 7F08B4C0 C586000C */  lwc1  $f6, 0xc($t4)
/* 0BDEB4 7F08B4C4 E5060490 */  swc1  $f6, 0x490($t0)
/* 0BDEB8 7F08B4C8 8E280000 */  lw    $t0, ($s1)
/* 0BDEBC 7F08B4CC 8D0D00A8 */  lw    $t5, 0xa8($t0)
/* 0BDEC0 7F08B4D0 C5A80010 */  lwc1  $f8, 0x10($t5)
/* 0BDEC4 7F08B4D4 E5080494 */  swc1  $f8, 0x494($t0)
/* 0BDEC8 7F08B4D8 8E280000 */  lw    $t0, ($s1)
/* 0BDECC 7F08B4DC 8D0E00A8 */  lw    $t6, 0xa8($t0)
/* 0BDED0 7F08B4E0 8DCF0014 */  lw    $t7, 0x14($t6)
/* 0BDED4 7F08B4E4 AD0F0488 */  sw    $t7, 0x488($t0)
/* 0BDED8 7F08B4E8 0FC1F7DC */  jal   sub_GAME_7F07DE9C
/* 0BDEDC 7F08B4EC 8E240000 */   lw    $a0, ($s1)
/* 0BDEE0 7F08B4F0 8FB800F8 */  lw    $t8, 0xf8($sp)
/* 0BDEE4 7F08B4F4 93190001 */  lbu   $t9, 1($t8)
/* 0BDEE8 7F08B4F8 33290002 */  andi  $t1, $t9, 2
/* 0BDEEC 7F08B4FC 1120001D */  beqz  $t1, .L7F08B574
/* 0BDEF0 7F08B500 00000000 */   nop   
/* 0BDEF4 7F08B504 8E2A0000 */  lw    $t2, ($s1)
/* 0BDEF8 7F08B508 8D4B00D4 */  lw    $t3, 0xd4($t2)
/* 0BDEFC 7F08B50C 0FC1E131 */  jal   currentPlayerGetMatrix10D4
/* 0BDF00 7F08B510 8D70000C */   lw    $s0, 0xc($t3)
/* 0BDF04 7F08B514 00402025 */  move  $a0, $v0
/* 0BDF08 7F08B518 02002825 */  move  $a1, $s0
/* 0BDF0C 7F08B51C 0FC1618D */  jal   matrix_4x4_multiply_homogeneous
/* 0BDF10 7F08B520 27A600A4 */   addiu $a2, $sp, 0xa4
/* 0BDF14 7F08B524 3C0140E0 */  li    $at, 0x40E00000 # 7.000000
/* 0BDF18 7F08B528 44810000 */  mtc1  $at, $f0
/* 0BDF1C 7F08B52C C7AA00B4 */  lwc1  $f10, 0xb4($sp)
/* 0BDF20 7F08B530 C7A400D4 */  lwc1  $f4, 0xd4($sp)
/* 0BDF24 7F08B534 8E2C0000 */  lw    $t4, ($s1)
/* 0BDF28 7F08B538 46005482 */  mul.s $f18, $f10, $f0
/* 0BDF2C 7F08B53C 46049180 */  add.s $f6, $f18, $f4
/* 0BDF30 7F08B540 E58604B4 */  swc1  $f6, 0x4b4($t4)
/* 0BDF34 7F08B544 C7A800B8 */  lwc1  $f8, 0xb8($sp)
/* 0BDF38 7F08B548 C7B200D8 */  lwc1  $f18, 0xd8($sp)
/* 0BDF3C 7F08B54C 8E2D0000 */  lw    $t5, ($s1)
/* 0BDF40 7F08B550 46004282 */  mul.s $f10, $f8, $f0
/* 0BDF44 7F08B554 46125100 */  add.s $f4, $f10, $f18
/* 0BDF48 7F08B558 E5A404B8 */  swc1  $f4, 0x4b8($t5)
/* 0BDF4C 7F08B55C C7A600BC */  lwc1  $f6, 0xbc($sp)
/* 0BDF50 7F08B560 C7AA00DC */  lwc1  $f10, 0xdc($sp)
/* 0BDF54 7F08B564 8E2E0000 */  lw    $t6, ($s1)
/* 0BDF58 7F08B568 46003202 */  mul.s $f8, $f6, $f0
/* 0BDF5C 7F08B56C 460A4480 */  add.s $f18, $f8, $f10
/* 0BDF60 7F08B570 E5D204BC */  swc1  $f18, 0x4bc($t6)
.L7F08B574:
/* 0BDF64 7F08B574 10000288 */  b     .L7F08BF98
/* 0BDF68 7F08B578 8FA200E8 */   lw    $v0, 0xe8($sp)
.L7F08B57C:
/* 0BDF6C 7F08B57C 8FAF00F0 */  lw    $t7, 0xf0($sp)
.L7F08B580:
/* 0BDF70 7F08B580 8FB800F4 */  lw    $t8, 0xf4($sp)
/* 0BDF74 7F08B584 3C098007 */  lui   $t1, %hi(g_playerPointers) # $t1, 0x8007
/* 0BDF78 7F08B588 11E0027E */  beqz  $t7, .L7F08BF84
/* 0BDF7C 7F08B58C 0018C880 */   sll   $t9, $t8, 2
/* 0BDF80 7F08B590 252989F0 */  addiu $t1, %lo(g_playerPointers) # addiu $t1, $t1, -0x7610
/* 0BDF84 7F08B594 03298821 */  addu  $s1, $t9, $t1
/* 0BDF88 7F08B598 8E2A0000 */  lw    $t2, ($s1)
/* 0BDF8C 7F08B59C 8D4B00D4 */  lw    $t3, 0xd4($t2)
/* 0BDF90 7F08B5A0 51600279 */  beql  $t3, $zero, .L7F08BF88
/* 0BDF94 7F08B5A4 8FAA00F8 */   lw    $t2, 0xf8($sp)
/* 0BDF98 7F08B5A8 0FC26669 */  jal   getPlayerCount
/* 0BDF9C 7F08B5AC 00000000 */   nop   
/* 0BDFA0 7F08B5B0 28410002 */  slti  $at, $v0, 2
/* 0BDFA4 7F08B5B4 54200274 */  bnezl $at, .L7F08BF88
/* 0BDFA8 7F08B5B8 8FAA00F8 */   lw    $t2, 0xf8($sp)
/* 0BDFAC 7F08B5BC 0FC269A4 */  jal   get_cur_playernum
/* 0BDFB0 7F08B5C0 00000000 */   nop   
/* 0BDFB4 7F08B5C4 8FAC00F4 */  lw    $t4, 0xf4($sp)
/* 0BDFB8 7F08B5C8 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0BDFBC 7F08B5CC 24050001 */  li    $a1, 1
/* 0BDFC0 7F08B5D0 504C026D */  beql  $v0, $t4, .L7F08BF88
/* 0BDFC4 7F08B5D4 8FAA00F8 */   lw    $t2, 0xf8($sp)
/* 0BDFC8 7F08B5D8 44811000 */  mtc1  $at, $f2
/* 0BDFCC 7F08B5DC AFA0009C */  sw    $zero, 0x9c($sp)
/* 0BDFD0 7F08B5E0 AFA0007C */  sw    $zero, 0x7c($sp)
/* 0BDFD4 7F08B5E4 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0BDFD8 7F08B5E8 E7A20090 */  swc1  $f2, 0x90($sp)
/* 0BDFDC 7F08B5EC 0FC08BFD */  jal   chrGetEquippedWeaponProp
/* 0BDFE0 7F08B5F0 E7A20094 */   swc1  $f2, 0x94($sp)
/* 0BDFE4 7F08B5F4 00408025 */  move  $s0, $v0
/* 0BDFE8 7F08B5F8 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0BDFEC 7F08B5FC 0FC08BFD */  jal   chrGetEquippedWeaponProp
/* 0BDFF0 7F08B600 00002825 */   move  $a1, $zero
/* 0BDFF4 7F08B604 C7A20094 */  lwc1  $f2, 0x94($sp)
/* 0BDFF8 7F08B608 00402825 */  move  $a1, $v0
/* 0BDFFC 7F08B60C 00001825 */  move  $v1, $zero
/* 0BE000 7F08B610 00002025 */  move  $a0, $zero
/* 0BE004 7F08B614 12000002 */  beqz  $s0, .L7F08B620
/* 0BE008 7F08B618 AFA00054 */   sw    $zero, 0x54($sp)
/* 0BE00C 7F08B61C 8E030004 */  lw    $v1, 4($s0)
.L7F08B620:
/* 0BE010 7F08B620 50400003 */  beql  $v0, $zero, .L7F08B630
/* 0BE014 7F08B624 AFA3005C */   sw    $v1, 0x5c($sp)
/* 0BE018 7F08B628 8C440004 */  lw    $a0, 4($v0)
/* 0BE01C 7F08B62C AFA3005C */  sw    $v1, 0x5c($sp)
.L7F08B630:
/* 0BE020 7F08B630 AFA40058 */  sw    $a0, 0x58($sp)
/* 0BE024 7F08B634 AFA50060 */  sw    $a1, 0x60($sp)
/* 0BE028 7F08B638 0FC269A4 */  jal   get_cur_playernum
/* 0BE02C 7F08B63C E7A20094 */   swc1  $f2, 0x94($sp)
/* 0BE030 7F08B640 0FC26A86 */  jal   sub_GAME_7F09B4D8
/* 0BE034 7F08B644 00402025 */   move  $a0, $v0
/* 0BE038 7F08B648 8FA3005C */  lw    $v1, 0x5c($sp)
/* 0BE03C 7F08B64C 8FA50060 */  lw    $a1, 0x60($sp)
/* 0BE040 7F08B650 14400006 */  bnez  $v0, .L7F08B66C
/* 0BE044 7F08B654 C7A20094 */   lwc1  $f2, 0x94($sp)
/* 0BE048 7F08B658 3C028003 */  lui   $v0, %hi(D_800368B8+0x1C) # $v0, 0x8003
/* 0BE04C 7F08B65C 24421E1C */  addiu $v0, %lo(D_800368B8+0x1C) # addiu $v0, $v0, 0x1e1c
/* 0BE050 7F08B660 8C4D0000 */  lw    $t5, ($v0)
/* 0BE054 7F08B664 25AE0001 */  addiu $t6, $t5, 1
/* 0BE058 7F08B668 AC4E0000 */  sw    $t6, ($v0)
.L7F08B66C:
/* 0BE05C 7F08B66C 3C028003 */  lui   $v0, %hi(D_800368B8+0x1C) # $v0, 0x8003
/* 0BE060 7F08B670 24421E1C */  addiu $v0, %lo(D_800368B8+0x1C) # addiu $v0, $v0, 0x1e1c
/* 0BE064 7F08B674 8C4F0000 */  lw    $t7, ($v0)
/* 0BE068 7F08B678 29E10002 */  slti  $at, $t7, 2
/* 0BE06C 7F08B67C 542001BB */  bnezl $at, .L7F08BD6C
/* 0BE070 7F08B680 8E2A0000 */   lw    $t2, ($s1)
/* 0BE074 7F08B684 8E280000 */  lw    $t0, ($s1)
/* 0BE078 7F08B688 C5042A00 */  lwc1  $f4, 0x2a00($t0)
/* 0BE07C 7F08B68C E7A4008C */  swc1  $f4, 0x8c($sp)
/* 0BE080 7F08B690 C5062A04 */  lwc1  $f6, 0x2a04($t0)
/* 0BE084 7F08B694 E7A60088 */  swc1  $f6, 0x88($sp)
/* 0BE088 7F08B698 8D1800D8 */  lw    $t8, 0xd8($t0)
/* 0BE08C 7F08B69C 13000036 */  beqz  $t8, .L7F08B778
/* 0BE090 7F08B6A0 3C078003 */   lui   $a3, %hi(g_bondviewBondDeathAnimationsCount) # $a3, 0x8003
/* 0BE094 7F08B6A4 8CE71A5C */  lw    $a3, %lo(g_bondviewBondDeathAnimationsCount)($a3)
/* 0BE098 7F08B6A8 00002825 */  move  $a1, $zero
/* 0BE09C 7F08B6AC 00008025 */  move  $s0, $zero
/* 0BE0A0 7F08B6B0 18E00010 */  blez  $a3, .L7F08B6F4
/* 0BE0A4 7F08B6B4 3C198003 */   lui   $t9,  %hi(g_bondviewBondDeathAnimations)
/* 0BE0A8 7F08B6B8 27221A28 */  addiu $v0, $t9, %lo(g_bondviewBondDeathAnimations)
/* 0BE0AC 7F08B6BC 3C038006 */  lui   $v1, %hi(ptr_animation_table) # $v1, 0x8006
/* 0BE0B0 7F08B6C0 00074880 */  sll   $t1, $a3, 2
/* 0BE0B4 7F08B6C4 01222021 */  addu  $a0, $t1, $v0
/* 0BE0B8 7F08B6C8 8C638478 */  lw    $v1, %lo(ptr_animation_table)($v1)
/* 0BE0BC 7F08B6CC 8D06127C */  lw    $a2, 0x127c($t0)
/* 0BE0C0 7F08B6D0 8C4A0000 */  lw    $t2, ($v0)
.L7F08B6D4:
/* 0BE0C4 7F08B6D4 24420004 */  addiu $v0, $v0, 4
/* 0BE0C8 7F08B6D8 0044082B */  sltu  $at, $v0, $a0
/* 0BE0CC 7F08B6DC 01435821 */  addu  $t3, $t2, $v1
/* 0BE0D0 7F08B6E0 14CB0002 */  bne   $a2, $t3, .L7F08B6EC
/* 0BE0D4 7F08B6E4 00000000 */   nop   
/* 0BE0D8 7F08B6E8 24050001 */  li    $a1, 1
.L7F08B6EC:
/* 0BE0DC 7F08B6EC 5420FFF9 */  bnezl $at, .L7F08B6D4
/* 0BE0E0 7F08B6F0 8C4A0000 */   lw    $t2, ($v0)
.L7F08B6F4:
/* 0BE0E4 7F08B6F4 10A00005 */  beqz  $a1, .L7F08B70C
/* 0BE0E8 7F08B6F8 3C013F00 */   li    $at, 0x3F000000 # 0.500000
/* 0BE0EC 7F08B6FC 8D06127C */  lw    $a2, 0x127c($t0)
/* 0BE0F0 7F08B700 44816000 */  mtc1  $at, $f12
/* 0BE0F4 7F08B704 10000017 */  b     .L7F08B764
/* 0BE0F8 7F08B708 AFA6009C */   sw    $a2, 0x9c($sp)
.L7F08B70C:
/* 0BE0FC 7F08B70C 0C00262C */  jal   randomGetNext
/* 0BE100 7F08B710 E7A20094 */   swc1  $f2, 0x94($sp)
/* 0BE104 7F08B714 3C0C8003 */  lui   $t4, %hi(g_bondviewBondDeathAnimationsCount) # $t4, 0x8003
/* 0BE108 7F08B718 8D8C1A5C */  lw    $t4, %lo(g_bondviewBondDeathAnimationsCount)($t4)
/* 0BE10C 7F08B71C 3C0F8003 */  lui   $t7, %hi(g_bondviewBondDeathAnimations)
/* 0BE110 7F08B720 3C188006 */  lui   $t8, %hi(ptr_animation_table) # $t8, 0x8006
/* 0BE114 7F08B724 004C001B */  divu  $zero, $v0, $t4
/* 0BE118 7F08B728 00006810 */  mfhi  $t5
/* 0BE11C 7F08B72C 000D7080 */  sll   $t6, $t5, 2
/* 0BE120 7F08B730 01EE7821 */  addu  $t7, $t7, $t6
/* 0BE124 7F08B734 8DEF1A28 */  lw    $t7, %lo(g_bondviewBondDeathAnimations)($t7)
/* 0BE128 7F08B738 8F188478 */  lw    $t8, %lo(ptr_animation_table)($t8)
/* 0BE12C 7F08B73C 8E280000 */  lw    $t0, ($s1)
/* 0BE130 7F08B740 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0BE134 7F08B744 01F84821 */  addu  $t1, $t7, $t8
/* 0BE138 7F08B748 AFA9009C */  sw    $t1, 0x9c($sp)
/* 0BE13C 7F08B74C 44816000 */  mtc1  $at, $f12
/* 0BE140 7F08B750 C7A20094 */  lwc1  $f2, 0x94($sp)
/* 0BE144 7F08B754 15800002 */  bnez  $t4, .L7F08B760
/* 0BE148 7F08B758 00000000 */   nop   
/* 0BE14C 7F08B75C 0007000D */  break 7
.L7F08B760:
/* 0BE150 7F08B760 8D06127C */  lw    $a2, 0x127c($t0)
.L7F08B764:
/* 0BE154 7F08B764 44807000 */  mtc1  $zero, $f14
/* 0BE158 7F08B768 00000000 */  nop   
/* 0BE15C 7F08B76C E7AE008C */  swc1  $f14, 0x8c($sp)
/* 0BE160 7F08B770 100000F6 */  b     .L7F08BB4C
/* 0BE164 7F08B774 E7AE0088 */   swc1  $f14, 0x88($sp)
.L7F08B778:
/* 0BE168 7F08B778 12000005 */  beqz  $s0, .L7F08B790
/* 0BE16C 7F08B77C 00000000 */   nop   
/* 0BE170 7F08B780 10A00003 */  beqz  $a1, .L7F08B790
/* 0BE174 7F08B784 00000000 */   nop   
/* 0BE178 7F08B788 1000002E */  b     .L7F08B844
/* 0BE17C 7F08B78C 24100003 */   li    $s0, 3
.L7F08B790:
/* 0BE180 7F08B790 16000005 */  bnez  $s0, .L7F08B7A8
/* 0BE184 7F08B794 00000000 */   nop   
/* 0BE188 7F08B798 14A00003 */  bnez  $a1, .L7F08B7A8
/* 0BE18C 7F08B79C 00000000 */   nop   
/* 0BE190 7F08B7A0 10000028 */  b     .L7F08B844
/* 0BE194 7F08B7A4 24100002 */   li    $s0, 2
.L7F08B7A8:
/* 0BE198 7F08B7A8 10600008 */  beqz  $v1, .L7F08B7CC
/* 0BE19C 7F08B7AC 24050200 */   li    $a1, 512
/* 0BE1A0 7F08B7B0 80640080 */  lb    $a0, 0x80($v1)
/* 0BE1A4 7F08B7B4 0FC1795B */  jal   bondwalkItemCheckBitflags
/* 0BE1A8 7F08B7B8 AFA3005C */   sw    $v1, 0x5c($sp)
/* 0BE1AC 7F08B7BC 14400003 */  bnez  $v0, .L7F08B7CC
/* 0BE1B0 7F08B7C0 8FA3005C */   lw    $v1, 0x5c($sp)
/* 0BE1B4 7F08B7C4 1000001F */  b     .L7F08B844
/* 0BE1B8 7F08B7C8 24100002 */   li    $s0, 2
.L7F08B7CC:
/* 0BE1BC 7F08B7CC 8FA20058 */  lw    $v0, 0x58($sp)
/* 0BE1C0 7F08B7D0 24050200 */  li    $a1, 512
/* 0BE1C4 7F08B7D4 10400008 */  beqz  $v0, .L7F08B7F8
/* 0BE1C8 7F08B7D8 00000000 */   nop   
/* 0BE1CC 7F08B7DC 80440080 */  lb    $a0, 0x80($v0)
/* 0BE1D0 7F08B7E0 0FC1795B */  jal   bondwalkItemCheckBitflags
/* 0BE1D4 7F08B7E4 AFA3005C */   sw    $v1, 0x5c($sp)
/* 0BE1D8 7F08B7E8 14400003 */  bnez  $v0, .L7F08B7F8
/* 0BE1DC 7F08B7EC 8FA3005C */   lw    $v1, 0x5c($sp)
/* 0BE1E0 7F08B7F0 10000014 */  b     .L7F08B844
/* 0BE1E4 7F08B7F4 24100002 */   li    $s0, 2
.L7F08B7F8:
/* 0BE1E8 7F08B7F8 10600007 */  beqz  $v1, .L7F08B818
/* 0BE1EC 7F08B7FC 24050100 */   li    $a1, 256
/* 0BE1F0 7F08B800 0FC1795B */  jal   bondwalkItemCheckBitflags
/* 0BE1F4 7F08B804 80640080 */   lb    $a0, 0x80($v1)
/* 0BE1F8 7F08B808 50400004 */  beql  $v0, $zero, .L7F08B81C
/* 0BE1FC 7F08B80C 8FA20058 */   lw    $v0, 0x58($sp)
/* 0BE200 7F08B810 1000000C */  b     .L7F08B844
/* 0BE204 7F08B814 00008025 */   move  $s0, $zero
.L7F08B818:
/* 0BE208 7F08B818 8FA20058 */  lw    $v0, 0x58($sp)
.L7F08B81C:
/* 0BE20C 7F08B81C 24050100 */  li    $a1, 256
/* 0BE210 7F08B820 50400008 */  beql  $v0, $zero, .L7F08B844
/* 0BE214 7F08B824 24100001 */   li    $s0, 1
/* 0BE218 7F08B828 0FC1795B */  jal   bondwalkItemCheckBitflags
/* 0BE21C 7F08B82C 80440080 */   lb    $a0, 0x80($v0)
/* 0BE220 7F08B830 50400004 */  beql  $v0, $zero, .L7F08B844
/* 0BE224 7F08B834 24100001 */   li    $s0, 1
/* 0BE228 7F08B838 10000002 */  b     .L7F08B844
/* 0BE22C 7F08B83C 00008025 */   move  $s0, $zero
/* 0BE230 7F08B840 24100001 */  li    $s0, 1
.L7F08B844:
/* 0BE234 7F08B844 0FC1E6A7 */  jal   playerGetCrouchPos
/* 0BE238 7F08B848 8FA400F4 */   lw    $a0, 0xf4($sp)
/* 0BE23C 7F08B84C 24010001 */  li    $at, 1
/* 0BE240 7F08B850 50410005 */  beql  $v0, $at, .L7F08B868
/* 0BE244 7F08B854 3C013F80 */   lui   $at, 0x3f80
/* 0BE248 7F08B858 0FC1E6A7 */  jal   playerGetCrouchPos
/* 0BE24C 7F08B85C 8FA400F4 */   lw    $a0, 0xf4($sp)
/* 0BE250 7F08B860 14400006 */  bnez  $v0, .L7F08B87C
/* 0BE254 7F08B864 3C013F80 */   li    $at, 0x3F800000 # 1.000000
.L7F08B868:
/* 0BE258 7F08B868 44816000 */  mtc1  $at, $f12
/* 0BE25C 7F08B86C 44807000 */  mtc1  $zero, $f14
/* 0BE260 7F08B870 24040005 */  li    $a0, 5
/* 0BE264 7F08B874 1000009D */  b     .L7F08BAEC
/* 0BE268 7F08B878 8E280000 */   lw    $t0, ($s1)
.L7F08B87C:
/* 0BE26C 7F08B87C 8E280000 */  lw    $t0, ($s1)
/* 0BE270 7F08B880 44807000 */  mtc1  $zero, $f14
/* 0BE274 7F08B884 0010C900 */  sll   $t9, $s0, 4
/* 0BE278 7F08B888 C502016C */  lwc1  $f2, 0x16c($t0)
/* 0BE27C 7F08B88C 0330C823 */  subu  $t9, $t9, $s0
/* 0BE280 7F08B890 0019C8C0 */  sll   $t9, $t9, 3
/* 0BE284 7F08B894 460E103C */  c.lt.s $f2, $f14
/* 0BE288 7F08B898 3C0A8003 */  lui   $t2, %hi(firing_animation_groups+0x50)
/* 0BE28C 7F08B89C 01595021 */  addu  $t2, $t2, $t9
/* 0BE290 7F08B8A0 45020014 */  bc1fl .L7F08B8F4
/* 0BE294 7F08B8A4 4602703C */   c.lt.s $f14, $f2
/* 0BE298 7F08B8A8 8D4A1E70 */  lw    $t2, %lo(firing_animation_groups+0x50)($t2) #firing_animation_groups[440]
/* 0BE29C 7F08B8AC 3C0142B4 */  li    $at, 0x42B40000 # 90.000000
/* 0BE2A0 7F08B8B0 51400010 */  beql  $t2, $zero, .L7F08B8F4
/* 0BE2A4 7F08B8B4 4602703C */   c.lt.s $f14, $f2
/* 0BE2A8 7F08B8B8 C5001278 */  lwc1  $f0, 0x1278($t0)
/* 0BE2AC 7F08B8BC 44814000 */  mtc1  $at, $f8
/* 0BE2B0 7F08B8C0 24040004 */  li    $a0, 4
/* 0BE2B4 7F08B8C4 46001307 */  neg.s $f12, $f2
/* 0BE2B8 7F08B8C8 4608003C */  c.lt.s $f0, $f8
/* 0BE2BC 7F08B8CC 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0BE2C0 7F08B8D0 45020087 */  bc1fl .L7F08BAF0
/* 0BE2C4 7F08B8D4 00107900 */   sll   $t7, $s0, 4
/* 0BE2C8 7F08B8D8 44815000 */  mtc1  $at, $f10
/* 0BE2CC 7F08B8DC 00000000 */  nop   
/* 0BE2D0 7F08B8E0 460A0480 */  add.s $f18, $f0, $f10
/* 0BE2D4 7F08B8E4 E5121278 */  swc1  $f18, 0x1278($t0)
/* 0BE2D8 7F08B8E8 10000080 */  b     .L7F08BAEC
/* 0BE2DC 7F08B8EC 8E280000 */   lw    $t0, ($s1)
/* 0BE2E0 7F08B8F0 4602703C */  c.lt.s $f14, $f2
.L7F08B8F4:
/* 0BE2E4 7F08B8F4 00105900 */  sll   $t3, $s0, 4
/* 0BE2E8 7F08B8F8 01705823 */  subu  $t3, $t3, $s0
/* 0BE2EC 7F08B8FC 000B58C0 */  sll   $t3, $t3, 3
/* 0BE2F0 7F08B900 45000014 */  bc1f  .L7F08B954
/* 0BE2F4 7F08B904 3C0C8003 */   lui   $t4, %hi(firing_animation_groups+0x3C)
/* 0BE2F8 7F08B908 018B6021 */  addu  $t4, $t4, $t3
/* 0BE2FC 7F08B90C 8D8C1E5C */  lw    $t4, %lo(firing_animation_groups+0x3C)($t4)
/* 0BE300 7F08B910 3C01C2B4 */  li    $at, 0xC2B40000 # -90.000000
/* 0BE304 7F08B914 51800010 */  beql  $t4, $zero, .L7F08B958
/* 0BE308 7F08B918 C502014C */   lwc1  $f2, 0x14c($t0)
/* 0BE30C 7F08B91C C5001278 */  lwc1  $f0, 0x1278($t0)
/* 0BE310 7F08B920 44812000 */  mtc1  $at, $f4
/* 0BE314 7F08B924 24040003 */  li    $a0, 3
/* 0BE318 7F08B928 46001306 */  mov.s $f12, $f2
/* 0BE31C 7F08B92C 4600203C */  c.lt.s $f4, $f0
/* 0BE320 7F08B930 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0BE324 7F08B934 4502006E */  bc1fl .L7F08BAF0
/* 0BE328 7F08B938 00107900 */   sll   $t7, $s0, 4
/* 0BE32C 7F08B93C 44813000 */  mtc1  $at, $f6
/* 0BE330 7F08B940 00000000 */  nop   
/* 0BE334 7F08B944 46060201 */  sub.s $f8, $f0, $f6
/* 0BE338 7F08B948 E5081278 */  swc1  $f8, 0x1278($t0)
/* 0BE33C 7F08B94C 10000067 */  b     .L7F08BAEC
/* 0BE340 7F08B950 8E280000 */   lw    $t0, ($s1)
.L7F08B954:
/* 0BE344 7F08B954 C502014C */  lwc1  $f2, 0x14c($t0)
.L7F08B958:
/* 0BE348 7F08B958 3C018005 */  lui   $at, %hi(D_8004AE94) # $at, 0x8005
/* 0BE34C 7F08B95C 460E103C */  c.lt.s $f2, $f14
/* 0BE350 7F08B960 00000000 */  nop   
/* 0BE354 7F08B964 45020003 */  bc1fl .L7F08B974
/* 0BE358 7F08B968 C5000174 */   lwc1  $f0, 0x174($t0)
/* 0BE35C 7F08B96C 46001087 */  neg.s $f2, $f2
/* 0BE360 7F08B970 C5000174 */  lwc1  $f0, 0x174($t0)
.L7F08B974:
/* 0BE364 7F08B974 C42AAE94 */  lwc1  $f10, %lo(D_8004AE94)($at)
/* 0BE368 7F08B978 3C018005 */  lui   $at, %hi(D_8004AE9C)
/* 0BE36C 7F08B97C 460A003C */  c.lt.s $f0, $f10
/* 0BE370 7F08B980 00000000 */  nop   
/* 0BE374 7F08B984 4500001D */  bc1f  .L7F08B9FC
/* 0BE378 7F08B988 00000000 */   nop   
/* 0BE37C 7F08B98C 46001087 */  neg.s $f2, $f2
/* 0BE380 7F08B990 3C018005 */  lui   $at, %hi(D_8004AE9C) # $at, 0x8005
/* 0BE384 7F08B994 4602003C */  c.lt.s $f0, $f2
/* 0BE388 7F08B998 00000000 */  nop   
/* 0BE38C 7F08B99C 45020003 */  bc1fl .L7F08B9AC
/* 0BE390 7F08B9A0 8D0D04E8 */   lw    $t5, 0x4e8($t0)
/* 0BE394 7F08B9A4 46000086 */  mov.s $f2, $f0
/* 0BE398 7F08B9A8 8D0D04E8 */  lw    $t5, 0x4e8($t0)
.L7F08B9AC:
/* 0BE39C 7F08B9AC 51A00008 */  beql  $t5, $zero, .L7F08B9D0
/* 0BE3A0 7F08B9B0 46021300 */   add.s $f12, $f2, $f2
/* 0BE3A4 7F08B9B4 C432AE98 */  lwc1  $f18, %lo(D_8004AE98)($at)
/* 0BE3A8 7F08B9B8 24040002 */  li    $a0, 2
/* 0BE3AC 7F08B9BC 4600903C */  c.lt.s $f18, $f0
/* 0BE3B0 7F08B9C0 00000000 */  nop   
/* 0BE3B4 7F08B9C4 4500000B */  bc1f  .L7F08B9F4
/* 0BE3B8 7F08B9C8 00000000 */   nop   
/* 0BE3BC 7F08B9CC 46021300 */  add.s $f12, $f2, $f2
.L7F08B9D0:
/* 0BE3C0 7F08B9D0 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0BE3C4 7F08B9D4 44818000 */  mtc1  $at, $f16
/* 0BE3C8 7F08B9D8 24040001 */  li    $a0, 1
/* 0BE3CC 7F08B9DC 4610603C */  c.lt.s $f12, $f16
/* 0BE3D0 7F08B9E0 00000000 */  nop   
/* 0BE3D4 7F08B9E4 4502002D */  bc1fl .L7F08BA9C
/* 0BE3D8 7F08B9E8 C5001278 */   lwc1  $f0, 0x1278($t0)
/* 0BE3DC 7F08B9EC 1000002A */  b     .L7F08BA98
/* 0BE3E0 7F08B9F0 46008306 */   mov.s $f12, $f16
.L7F08B9F4:
/* 0BE3E4 7F08B9F4 10000028 */  b     .L7F08BA98
/* 0BE3E8 7F08B9F8 46001306 */   mov.s $f12, $f2
.L7F08B9FC:
/* 0BE3EC 7F08B9FC C42CAE9C */  lwc1  $f12, %lo(D_8004AE9C)($at)
/* 0BE3F0 7F08BA00 4600603C */  c.lt.s $f12, $f0
/* 0BE3F4 7F08BA04 00000000 */  nop   
/* 0BE3F8 7F08BA08 45030006 */  bc1tl .L7F08BA24
/* 0BE3FC 7F08BA0C 4600103C */   c.lt.s $f2, $f0
/* 0BE400 7F08BA10 4602603C */  c.lt.s $f12, $f2
/* 0BE404 7F08BA14 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BE408 7F08BA18 4502001E */  bc1fl .L7F08BA94
/* 0BE40C 7F08BA1C 44816000 */   mtc1  $at, $f12
/* 0BE410 7F08BA20 4600103C */  c.lt.s $f2, $f0
.L7F08BA24:
/* 0BE414 7F08BA24 3C018005 */  li    $at, 0x80050000 # -0.000000
/* 0BE418 7F08BA28 45020003 */  bc1fl .L7F08BA38
/* 0BE41C 7F08BA2C 8D0E04E8 */   lw    $t6, 0x4e8($t0)
/* 0BE420 7F08BA30 46000086 */  mov.s $f2, $f0
/* 0BE424 7F08BA34 8D0E04E8 */  lw    $t6, 0x4e8($t0)
.L7F08BA38:
/* 0BE428 7F08BA38 51C00008 */  beql  $t6, $zero, .L7F08BA5C
/* 0BE42C 7F08BA3C 46021300 */   add.s $f12, $f2, $f2
/* 0BE430 7F08BA40 C424AEA0 */  lwc1  $f4, %lo(D_8004AEA0)($at)
/* 0BE434 7F08BA44 24040002 */  li    $a0, 2
/* 0BE438 7F08BA48 4604003C */  c.lt.s $f0, $f4
/* 0BE43C 7F08BA4C 00000000 */  nop   
/* 0BE440 7F08BA50 4500000D */  bc1f  .L7F08BA88
/* 0BE444 7F08BA54 00000000 */   nop   
/* 0BE448 7F08BA58 46021300 */  add.s $f12, $f2, $f2
.L7F08BA5C:
/* 0BE44C 7F08BA5C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BE450 7F08BA60 44813000 */  mtc1  $at, $f6
/* 0BE454 7F08BA64 24040001 */  li    $a0, 1
/* 0BE458 7F08BA68 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0BE45C 7F08BA6C 460C303C */  c.lt.s $f6, $f12
/* 0BE460 7F08BA70 00000000 */  nop   
/* 0BE464 7F08BA74 45020009 */  bc1fl .L7F08BA9C
/* 0BE468 7F08BA78 C5001278 */   lwc1  $f0, 0x1278($t0)
/* 0BE46C 7F08BA7C 44816000 */  mtc1  $at, $f12
/* 0BE470 7F08BA80 10000006 */  b     .L7F08BA9C
/* 0BE474 7F08BA84 C5001278 */   lwc1  $f0, 0x1278($t0)
.L7F08BA88:
/* 0BE478 7F08BA88 10000003 */  b     .L7F08BA98
/* 0BE47C 7F08BA8C 46001306 */   mov.s $f12, $f2
/* 0BE480 7F08BA90 44816000 */  mtc1  $at, $f12
.L7F08BA94:
/* 0BE484 7F08BA94 00002025 */  move  $a0, $zero
.L7F08BA98:
/* 0BE488 7F08BA98 C5001278 */  lwc1  $f0, 0x1278($t0)
.L7F08BA9C:
/* 0BE48C 7F08BA9C 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0BE490 7F08BAA0 4600703C */  c.lt.s $f14, $f0
/* 0BE494 7F08BAA4 00000000 */  nop   
/* 0BE498 7F08BAA8 45020008 */  bc1fl .L7F08BACC
/* 0BE49C 7F08BAAC 460E003C */   c.lt.s $f0, $f14
/* 0BE4A0 7F08BAB0 44814000 */  mtc1  $at, $f8
/* 0BE4A4 7F08BAB4 00000000 */  nop   
/* 0BE4A8 7F08BAB8 46080281 */  sub.s $f10, $f0, $f8
/* 0BE4AC 7F08BABC E50A1278 */  swc1  $f10, 0x1278($t0)
/* 0BE4B0 7F08BAC0 8E280000 */  lw    $t0, ($s1)
/* 0BE4B4 7F08BAC4 C5001278 */  lwc1  $f0, 0x1278($t0)
/* 0BE4B8 7F08BAC8 460E003C */  c.lt.s $f0, $f14
.L7F08BACC:
/* 0BE4BC 7F08BACC 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0BE4C0 7F08BAD0 45020007 */  bc1fl .L7F08BAF0
/* 0BE4C4 7F08BAD4 00107900 */   sll   $t7, $s0, 4
/* 0BE4C8 7F08BAD8 44819000 */  mtc1  $at, $f18
/* 0BE4CC 7F08BADC 00000000 */  nop   
/* 0BE4D0 7F08BAE0 46120100 */  add.s $f4, $f0, $f18
/* 0BE4D4 7F08BAE4 E5041278 */  swc1  $f4, 0x1278($t0)
/* 0BE4D8 7F08BAE8 8E280000 */  lw    $t0, ($s1)
.L7F08BAEC:
/* 0BE4DC 7F08BAEC 00107900 */  sll   $t7, $s0, 4
.L7F08BAF0:
/* 0BE4E0 7F08BAF0 0004C080 */  sll   $t8, $a0, 2
/* 0BE4E4 7F08BAF4 0304C021 */  addu  $t8, $t8, $a0
/* 0BE4E8 7F08BAF8 01F07823 */  subu  $t7, $t7, $s0
/* 0BE4EC 7F08BAFC 000F78C0 */  sll   $t7, $t7, 3
/* 0BE4F0 7F08BB00 0018C080 */  sll   $t8, $t8, 2
/* 0BE4F4 7F08BB04 3C198003 */  lui   $t9, %hi(firing_animation_groups) # $t9, 0x8003
/* 0BE4F8 7F08BB08 27391E20 */  addiu $t9, %lo(firing_animation_groups) # addiu $t9, $t9, 0x1e20
/* 0BE4FC 7F08BB0C 01F84821 */  addu  $t1, $t7, $t8
/* 0BE500 7F08BB10 01391021 */  addu  $v0, $t1, $t9
/* 0BE504 7F08BB14 8C430004 */  lw    $v1, 4($v0)
/* 0BE508 7F08BB18 8C4A0000 */  lw    $t2, ($v0)
/* 0BE50C 7F08BB1C 3C0B8006 */  lui   $t3, %hi(ptr_animation_table) # $t3, 0x8006
/* 0BE510 7F08BB20 10600004 */  beqz  $v1, .L7F08BB34
/* 0BE514 7F08BB24 AFAA007C */   sw    $t2, 0x7c($sp)
/* 0BE518 7F08BB28 8D6B8478 */  lw    $t3, %lo(ptr_animation_table)($t3)
/* 0BE51C 7F08BB2C 006B6021 */  addu  $t4, $v1, $t3
/* 0BE520 7F08BB30 AFAC009C */  sw    $t4, 0x9c($sp)
.L7F08BB34:
/* 0BE524 7F08BB34 C4460008 */  lwc1  $f6, 8($v0)
/* 0BE528 7F08BB38 C4480010 */  lwc1  $f8, 0x10($v0)
/* 0BE52C 7F08BB3C C442000C */  lwc1  $f2, 0xc($v0)
/* 0BE530 7F08BB40 46066302 */  mul.s $f12, $f12, $f6
/* 0BE534 7F08BB44 E7A80090 */  swc1  $f8, 0x90($sp)
/* 0BE538 7F08BB48 8D06127C */  lw    $a2, 0x127c($t0)
.L7F08BB4C:
/* 0BE53C 7F08BB4C 8FAD007C */  lw    $t5, 0x7c($sp)
/* 0BE540 7F08BB50 8FAE009C */  lw    $t6, 0x9c($sp)
/* 0BE544 7F08BB54 24020001 */  li    $v0, 1
/* 0BE548 7F08BB58 51A00006 */  beql  $t5, $zero, .L7F08BB74
/* 0BE54C 7F08BB5C 8FB8009C */   lw    $t8, 0x9c($sp)
/* 0BE550 7F08BB60 55C00004 */  bnezl $t6, .L7F08BB74
/* 0BE554 7F08BB64 8FB8009C */   lw    $t8, 0x9c($sp)
/* 0BE558 7F08BB68 8DAF0000 */  lw    $t7, ($t5)
/* 0BE55C 7F08BB6C AFAF009C */  sw    $t7, 0x9c($sp)
/* 0BE560 7F08BB70 8FB8009C */  lw    $t8, 0x9c($sp)
.L7F08BB74:
/* 0BE564 7F08BB74 53060003 */  beql  $t8, $a2, .L7F08BB84
/* 0BE568 7F08BB78 4602703E */   c.le.s $f14, $f2
/* 0BE56C 7F08BB7C AFA20054 */  sw    $v0, 0x54($sp)
/* 0BE570 7F08BB80 4602703E */  c.le.s $f14, $f2
.L7F08BB84:
/* 0BE574 7F08BB84 8FA20054 */  lw    $v0, 0x54($sp)
/* 0BE578 7F08BB88 4502000C */  bc1fl .L7F08BBBC
/* 0BE57C 7F08BB8C 460E103C */   c.lt.s $f2, $f14
/* 0BE580 7F08BB90 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0BE584 7F08BB94 80890026 */  lb    $t1, 0x26($a0)
/* 0BE588 7F08BB98 51200007 */  beql  $t1, $zero, .L7F08BBB8
/* 0BE58C 7F08BB9C 24020001 */   li    $v0, 1
/* 0BE590 7F08BBA0 C48A0090 */  lwc1  $f10, 0x90($a0)
/* 0BE594 7F08BBA4 460A1032 */  c.eq.s $f2, $f10
/* 0BE598 7F08BBA8 00000000 */  nop   
/* 0BE59C 7F08BBAC 45030003 */  bc1tl .L7F08BBBC
/* 0BE5A0 7F08BBB0 460E103C */   c.lt.s $f2, $f14
/* 0BE5A4 7F08BBB4 24020001 */  li    $v0, 1
.L7F08BBB8:
/* 0BE5A8 7F08BBB8 460E103C */  c.lt.s $f2, $f14
.L7F08BBBC:
/* 0BE5AC 7F08BBBC 00000000 */  nop   
/* 0BE5B0 7F08BBC0 45000006 */  bc1f  .L7F08BBDC
/* 0BE5B4 7F08BBC4 00000000 */   nop   
/* 0BE5B8 7F08BBC8 8D1900D4 */  lw    $t9, 0xd4($t0)
/* 0BE5BC 7F08BBCC 832A0026 */  lb    $t2, 0x26($t9)
/* 0BE5C0 7F08BBD0 11400002 */  beqz  $t2, .L7F08BBDC
/* 0BE5C4 7F08BBD4 00000000 */   nop   
/* 0BE5C8 7F08BBD8 24020001 */  li    $v0, 1
.L7F08BBDC:
/* 0BE5CC 7F08BBDC 50400035 */  beql  $v0, $zero, .L7F08BCB4
/* 0BE5D0 7F08BBE0 C5061280 */   lwc1  $f6, 0x1280($t0)
/* 0BE5D4 7F08BBE4 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0BE5D8 7F08BBE8 8FA5009C */  lw    $a1, 0x9c($sp)
/* 0BE5DC 7F08BBEC 00003025 */  move  $a2, $zero
/* 0BE5E0 7F08BBF0 8C8B0054 */  lw    $t3, 0x54($a0)
/* 0BE5E4 7F08BBF4 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 0BE5E8 7F08BBF8 5560002B */  bnezl $t3, .L7F08BCA8
/* 0BE5EC 7F08BBFC 8E290000 */   lw    $t1, ($s1)
/* 0BE5F0 7F08BC00 4602703E */  c.le.s $f14, $f2
/* 0BE5F4 7F08BC04 44819000 */  mtc1  $at, $f18
/* 0BE5F8 7F08BC08 45020004 */  bc1fl .L7F08BC1C
/* 0BE5FC 7F08BC0C 46007006 */   mov.s $f0, $f14
/* 0BE600 7F08BC10 10000002 */  b     .L7F08BC1C
/* 0BE604 7F08BC14 46001006 */   mov.s $f0, $f2
/* 0BE608 7F08BC18 46007006 */  mov.s $f0, $f14
.L7F08BC1C:
/* 0BE60C 7F08BC1C 44070000 */  mfc1  $a3, $f0
/* 0BE610 7F08BC20 E7AC0010 */  swc1  $f12, 0x10($sp)
/* 0BE614 7F08BC24 E7B20014 */  swc1  $f18, 0x14($sp)
/* 0BE618 7F08BC28 E7A20094 */  swc1  $f2, 0x94($sp)
/* 0BE61C 7F08BC2C 0FC1BF92 */  jal   modelSetAnimation
/* 0BE620 7F08BC30 E7AC0098 */   swc1  $f12, 0x98($sp)
/* 0BE624 7F08BC34 C7A20094 */  lwc1  $f2, 0x94($sp)
/* 0BE628 7F08BC38 44807000 */  mtc1  $zero, $f14
/* 0BE62C 7F08BC3C 8FAC009C */  lw    $t4, 0x9c($sp)
/* 0BE630 7F08BC40 8E2E0000 */  lw    $t6, ($s1)
/* 0BE634 7F08BC44 4602703E */  c.le.s $f14, $f2
/* 0BE638 7F08BC48 C7AC0098 */  lwc1  $f12, 0x98($sp)
/* 0BE63C 7F08BC4C ADCC127C */  sw    $t4, 0x127c($t6)
/* 0BE640 7F08BC50 8E2D0000 */  lw    $t5, ($s1)
/* 0BE644 7F08BC54 3C064180 */  lui   $a2, 0x4180
/* 0BE648 7F08BC58 45000007 */  bc1f  .L7F08BC78
/* 0BE64C 7F08BC5C E5AC1280 */   swc1  $f12, 0x1280($t5)
/* 0BE650 7F08BC60 8E2F0000 */  lw    $t7, ($s1)
/* 0BE654 7F08BC64 44051000 */  mfc1  $a1, $f2
/* 0BE658 7F08BC68 0FC1BFDB */  jal   modelSetAnimLooping
/* 0BE65C 7F08BC6C 8DE400D4 */   lw    $a0, 0xd4($t7)
/* 0BE660 7F08BC70 44807000 */  mtc1  $zero, $f14
/* 0BE664 7F08BC74 00000000 */  nop   
.L7F08BC78:
/* 0BE668 7F08BC78 C7A40090 */  lwc1  $f4, 0x90($sp)
/* 0BE66C 7F08BC7C 4604703E */  c.le.s $f14, $f4
/* 0BE670 7F08BC80 00000000 */  nop   
/* 0BE674 7F08BC84 45020008 */  bc1fl .L7F08BCA8
/* 0BE678 7F08BC88 8E290000 */   lw    $t1, ($s1)
/* 0BE67C 7F08BC8C 8E380000 */  lw    $t8, ($s1)
/* 0BE680 7F08BC90 44052000 */  mfc1  $a1, $f4
/* 0BE684 7F08BC94 0FC1BFE2 */  jal   modelSetAnimEndFrame
/* 0BE688 7F08BC98 8F0400D4 */   lw    $a0, 0xd4($t8)
/* 0BE68C 7F08BC9C 44807000 */  mtc1  $zero, $f14
/* 0BE690 7F08BCA0 00000000 */  nop   
/* 0BE694 7F08BCA4 8E290000 */  lw    $t1, ($s1)
.L7F08BCA8:
/* 0BE698 7F08BCA8 10000011 */  b     .L7F08BCF0
/* 0BE69C 7F08BCAC 8D26127C */   lw    $a2, 0x127c($t1)
/* 0BE6A0 7F08BCB0 C5061280 */  lwc1  $f6, 0x1280($t0)
.L7F08BCB4:
/* 0BE6A4 7F08BCB4 46066032 */  c.eq.s $f12, $f6
/* 0BE6A8 7F08BCB8 00000000 */  nop   
/* 0BE6AC 7F08BCBC 4503000D */  bc1tl .L7F08BCF4
/* 0BE6B0 7F08BCC0 8FAB009C */   lw    $t3, 0x9c($sp)
/* 0BE6B4 7F08BCC4 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0BE6B8 7F08BCC8 44056000 */  mfc1  $a1, $f12
/* 0BE6BC 7F08BCCC E7AC0098 */  swc1  $f12, 0x98($sp)
/* 0BE6C0 7F08BCD0 0FC1BFFB */  jal   modelSetAnimSpeed
/* 0BE6C4 7F08BCD4 3C063F80 */   lui   $a2, 0x3f80
/* 0BE6C8 7F08BCD8 C7AC0098 */  lwc1  $f12, 0x98($sp)
/* 0BE6CC 7F08BCDC 8E390000 */  lw    $t9, ($s1)
/* 0BE6D0 7F08BCE0 44807000 */  mtc1  $zero, $f14
/* 0BE6D4 7F08BCE4 E72C1280 */  swc1  $f12, 0x1280($t9)
/* 0BE6D8 7F08BCE8 8E2A0000 */  lw    $t2, ($s1)
/* 0BE6DC 7F08BCEC 8D46127C */  lw    $a2, 0x127c($t2)
.L7F08BCF0:
/* 0BE6E0 7F08BCF0 8FAB009C */  lw    $t3, 0x9c($sp)
.L7F08BCF4:
/* 0BE6E4 7F08BCF4 8FAC007C */  lw    $t4, 0x7c($sp)
/* 0BE6E8 7F08BCF8 55660017 */  bnel  $t3, $a2, .L7F08BD58
/* 0BE6EC 7F08BCFC 8FA200F0 */   lw    $v0, 0xf0($sp)
/* 0BE6F0 7F08BD00 1180000D */  beqz  $t4, .L7F08BD38
/* 0BE6F4 7F08BD04 8FAF00F0 */   lw    $t7, 0xf0($sp)
/* 0BE6F8 7F08BD08 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0BE6FC 7F08BD0C 00003025 */  move  $a2, $zero
/* 0BE700 7F08BD10 24070001 */  li    $a3, 1
/* 0BE704 7F08BD14 948E0012 */  lhu   $t6, 0x12($a0)
/* 0BE708 7F08BD18 31CDFBFF */  andi  $t5, $t6, 0xfbff
/* 0BE70C 7F08BD1C A48D0012 */  sh    $t5, 0x12($a0)
/* 0BE710 7F08BD20 C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 0BE714 7F08BD24 8FA5007C */  lw    $a1, 0x7c($sp)
/* 0BE718 7F08BD28 0FC0B41F */  jal   chrlvUpdateAimendbackShoulders
/* 0BE71C 7F08BD2C E7A80010 */   swc1  $f8, 0x10($sp)
/* 0BE720 7F08BD30 10000009 */  b     .L7F08BD58
/* 0BE724 7F08BD34 8FA200F0 */   lw    $v0, 0xf0($sp)
.L7F08BD38:
/* 0BE728 7F08BD38 95F80012 */  lhu   $t8, 0x12($t7)
/* 0BE72C 7F08BD3C E5EE0154 */  swc1  $f14, 0x154($t7)
/* 0BE730 7F08BD40 E5EE0150 */  swc1  $f14, 0x150($t7)
/* 0BE734 7F08BD44 37090400 */  ori   $t1, $t8, 0x400
/* 0BE738 7F08BD48 A5E90012 */  sh    $t1, 0x12($t7)
/* 0BE73C 7F08BD4C C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 0BE740 7F08BD50 E5EA0158 */  swc1  $f10, 0x158($t7)
/* 0BE744 7F08BD54 8FA200F0 */  lw    $v0, 0xf0($sp)
.L7F08BD58:
/* 0BE748 7F08BD58 C7B20088 */  lwc1  $f18, 0x88($sp)
/* 0BE74C 7F08BD5C 2419000A */  li    $t9, 10
/* 0BE750 7F08BD60 A059000E */  sb    $t9, 0xe($v0)
/* 0BE754 7F08BD64 E452015C */  swc1  $f18, 0x15c($v0)
/* 0BE758 7F08BD68 8E2A0000 */  lw    $t2, ($s1)
.L7F08BD6C:
/* 0BE75C 7F08BD6C 8FA300F8 */  lw    $v1, 0xf8($sp)
/* 0BE760 7F08BD70 8FA200F0 */  lw    $v0, 0xf0($sp)
/* 0BE764 7F08BD74 C544048C */  lwc1  $f4, 0x48c($t2)
/* 0BE768 7F08BD78 27A50070 */  addiu $a1, $sp, 0x70
/* 0BE76C 7F08BD7C 00008025 */  move  $s0, $zero
/* 0BE770 7F08BD80 E4640008 */  swc1  $f4, 8($v1)
/* 0BE774 7F08BD84 8E2B0000 */  lw    $t3, ($s1)
/* 0BE778 7F08BD88 C5660490 */  lwc1  $f6, 0x490($t3)
/* 0BE77C 7F08BD8C E466000C */  swc1  $f6, 0xc($v1)
/* 0BE780 7F08BD90 8E2C0000 */  lw    $t4, ($s1)
/* 0BE784 7F08BD94 C5880494 */  lwc1  $f8, 0x494($t4)
/* 0BE788 7F08BD98 E4680010 */  swc1  $f8, 0x10($v1)
/* 0BE78C 7F08BD9C 8E2E0000 */  lw    $t6, ($s1)
/* 0BE790 7F08BDA0 8DCD0488 */  lw    $t5, 0x488($t6)
/* 0BE794 7F08BDA4 AC6D0014 */  sw    $t5, 0x14($v1)
/* 0BE798 7F08BDA8 0FC1B476 */  jal   getsuboffset
/* 0BE79C 7F08BDAC 8C44001C */   lw    $a0, 0x1c($v0)
/* 0BE7A0 7F08BDB0 8FA200F8 */  lw    $v0, 0xf8($sp)
/* 0BE7A4 7F08BDB4 8FB800F0 */  lw    $t8, 0xf0($sp)
/* 0BE7A8 7F08BDB8 27A50070 */  addiu $a1, $sp, 0x70
/* 0BE7AC 7F08BDBC C44A0008 */  lwc1  $f10, 8($v0)
/* 0BE7B0 7F08BDC0 E7AA0070 */  swc1  $f10, 0x70($sp)
/* 0BE7B4 7F08BDC4 C4520010 */  lwc1  $f18, 0x10($v0)
/* 0BE7B8 7F08BDC8 E7B20078 */  swc1  $f18, 0x78($sp)
/* 0BE7BC 7F08BDCC 0FC1B480 */  jal   setsuboffset
/* 0BE7C0 7F08BDD0 8F04001C */   lw    $a0, 0x1c($t8)
/* 0BE7C4 7F08BDD4 8E280000 */  lw    $t0, ($s1)
/* 0BE7C8 7F08BDD8 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0BE7CC 7F08BDDC 44810000 */  mtc1  $at, $f0
/* 0BE7D0 7F08BDE0 C5060148 */  lwc1  $f6, 0x148($t0)
/* 0BE7D4 7F08BDE4 C5041278 */  lwc1  $f4, 0x1278($t0)
/* 0BE7D8 7F08BDE8 3C018005 */  lui   $at, %hi(D_8004AEA4) # $at, 0x8005
/* 0BE7DC 7F08BDEC 46060201 */  sub.s $f8, $f0, $f6
/* 0BE7E0 7F08BDF0 C432AEA4 */  lwc1  $f18, %lo(D_8004AEA4)($at)
/* 0BE7E4 7F08BDF4 8FA900F0 */  lw    $t1, 0xf0($sp)
/* 0BE7E8 7F08BDF8 46082280 */  add.s $f10, $f4, $f8
/* 0BE7EC 7F08BDFC 8D24001C */  lw    $a0, 0x1c($t1)
/* 0BE7F0 7F08BE00 46125182 */  mul.s $f6, $f10, $f18
/* 0BE7F4 7F08BE04 46003103 */  div.s $f4, $f6, $f0
/* 0BE7F8 7F08BE08 44052000 */  mfc1  $a1, $f4
/* 0BE7FC 7F08BE0C 0FC1B49D */  jal   setsubroty
/* 0BE800 7F08BE10 00000000 */   nop   
/* 0BE804 7F08BE14 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0BE808 7F08BE18 240A0019 */  li    $t2, 25
/* 0BE80C 7F08BE1C 00002825 */  move  $a1, $zero
/* 0BE810 7F08BE20 8C8F0014 */  lw    $t7, 0x14($a0)
/* 0BE814 7F08BE24 A08A0007 */  sb    $t2, 7($a0)
/* 0BE818 7F08BE28 35F90001 */  ori   $t9, $t7, 1
/* 0BE81C 7F08BE2C AC990014 */  sw    $t9, 0x14($a0)
/* 0BE820 7F08BE30 8FAB007C */  lw    $t3, 0x7c($sp)
/* 0BE824 7F08BE34 AC8B002C */  sw    $t3, 0x2c($a0)
/* 0BE828 7F08BE38 8E2C0000 */  lw    $t4, ($s1)
/* 0BE82C 7F08BE3C 0FC0B453 */  jal   chrSetFiring
/* 0BE830 7F08BE40 81860875 */   lb    $a2, 0x875($t4)
/* 0BE834 7F08BE44 8E2E0000 */  lw    $t6, ($s1)
/* 0BE838 7F08BE48 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0BE83C 7F08BE4C 24050001 */  li    $a1, 1
/* 0BE840 7F08BE50 0FC0B453 */  jal   chrSetFiring
/* 0BE844 7F08BE54 81C60C1D */   lb    $a2, 0xc1d($t6)
/* 0BE848 7F08BE58 0FC0839A */  jal   sub_GAME_7F020EF0
/* 0BE84C 7F08BE5C 8FA400F8 */   lw    $a0, 0xf8($sp)
/* 0BE850 7F08BE60 AFA200A0 */  sw    $v0, 0xa0($sp)
/* 0BE854 7F08BE64 00003825 */  move  $a3, $zero
/* 0BE858 7F08BE68 00001825 */  move  $v1, $zero
.Leu7F08BE6C:
/* 0BE85C 7F08BE6C 8E2D0000 */  lw    $t5, ($s1)
/* 0BE860 7F08BE70 8FA400F0 */  lw    $a0, 0xf0($sp)
/* 0BE864 7F08BE74 02002825 */  move  $a1, $s0
/* 0BE868 7F08BE78 01A33021 */  addu  $a2, $t5, $v1
/* 0BE86C 7F08BE7C 24C62A10 */  addiu $a2, $a2, 0x2a10
/* 0BE870 7F08BE80 AFA30034 */  sw    $v1, 0x34($sp)
/* 0BE874 7F08BE84 0FC0B599 */  jal   sub_GAME_7F02D630
/* 0BE878 7F08BE88 AFA70038 */   sw    $a3, 0x38($sp)
/* 0BE87C 7F08BE8C 8FA30034 */  lw    $v1, 0x34($sp)
/* 0BE880 7F08BE90 10400007 */  beqz  $v0, .L7F08BEB0
/* 0BE884 7F08BE94 8FA70038 */   lw    $a3, 0x38($sp)
/* 0BE888 7F08BE98 8E290000 */  lw    $t1, ($s1)
/* 0BE88C 7F08BE9C 3C188004 */  lui   $t8, %hi(D_80048380) # $t8, 0x8004
/* 0BE890 7F08BEA0 8F181000 */  lw    $t8, %lo(D_80048380)($t8)
/* 0BE894 7F08BEA4 01277821 */  addu  $t7, $t1, $a3
/* 0BE898 7F08BEA8 1000001E */  b     .L7F08BF24
/* 0BE89C 7F08BEAC ADF82A28 */   sw    $t8, 0x2a28($t7)
.L7F08BEB0:
/* 0BE8A0 7F08BEB0 8E280000 */  lw    $t0, ($s1)
/* 0BE8A4 7F08BEB4 3C0B8004 */  lui   $t3, %hi(D_80048380) # $t3, 0x8004
/* 0BE8A8 7F08BEB8 8D6B1000 */  lw    $t3, %lo(D_80048380)($t3)
/* 0BE8AC 7F08BEBC 0107C821 */  addu  $t9, $t0, $a3
/* 0BE8B0 7F08BEC0 8F2A2A28 */  lw    $t2, 0x2a28($t9)
/* 0BE8B4 7F08BEC4 256CFFFF */  addiu $t4, $t3, -1
/* 0BE8B8 7F08BEC8 001010C0 */  sll   $v0, $s0, 3
/* 0BE8BC 7F08BECC 014C082A */  slt   $at, $t2, $t4
/* 0BE8C0 7F08BED0 10200014 */  beqz  $at, .L7F08BF24
/* 0BE8C4 7F08BED4 00501023 */   subu  $v0, $v0, $s0
/* 0BE8C8 7F08BED8 00021080 */  sll   $v0, $v0, 2
/* 0BE8CC 7F08BEDC 00501021 */  addu  $v0, $v0, $s0
/* 0BE8D0 7F08BEE0 00021080 */  sll   $v0, $v0, 2
/* 0BE8D4 7F08BEE4 00501021 */  addu  $v0, $v0, $s0
/* 0BE8D8 7F08BEE8 000210C0 */  sll   $v0, $v0, 3
/* 0BE8DC 7F08BEEC 01027021 */  addu  $t6, $t0, $v0
/* 0BE8E0 7F08BEF0 C5C80B50 */  lwc1  $f8, 0xb50($t6)
/* 0BE8E4 7F08BEF4 01036821 */  addu  $t5, $t0, $v1
/* 0BE8E8 7F08BEF8 E5A82A10 */  swc1  $f8, 0x2a10($t5)
/* 0BE8EC 7F08BEFC 8E280000 */  lw    $t0, ($s1)
/* 0BE8F0 7F08BF00 01024821 */  addu  $t1, $t0, $v0
/* 0BE8F4 7F08BF04 C52A0B54 */  lwc1  $f10, 0xb54($t1)
/* 0BE8F8 7F08BF08 0103C021 */  addu  $t8, $t0, $v1
/* 0BE8FC 7F08BF0C E70A2A14 */  swc1  $f10, 0x2a14($t8)
/* 0BE900 7F08BF10 8E280000 */  lw    $t0, ($s1)
/* 0BE904 7F08BF14 01027821 */  addu  $t7, $t0, $v0
/* 0BE908 7F08BF18 C5F20B58 */  lwc1  $f18, 0xb58($t7)
/* 0BE90C 7F08BF1C 0103C821 */  addu  $t9, $t0, $v1
/* 0BE910 7F08BF20 E7322A18 */  swc1  $f18, 0x2a18($t9)
.L7F08BF24:
/* 0BE914 7F08BF24 26100001 */  addiu $s0, $s0, 1
/* 0BE918 7F08BF28 24010002 */  li    $at, 2
/* 0BE91C 7F08BF2C 24E70004 */  addiu $a3, $a3, 4
/* 0BE920 7F08BF30 1601FFCE */  bne   $s0, $at, .Leu7F08BE6C
/* 0BE924 7F08BF34 2463000C */   addiu $v1, $v1, 0xc
/* 0BE928 7F08BF38 8FAB00F0 */  lw    $t3, 0xf0($sp)
/* 0BE92C 7F08BF3C 956A0012 */  lhu   $t2, 0x12($t3)
/* 0BE930 7F08BF40 354C0800 */  ori   $t4, $t2, 0x800
/* 0BE934 7F08BF44 A56C0012 */  sh    $t4, 0x12($t3)
/* 0BE938 7F08BF48 8E2E0000 */  lw    $t6, ($s1)
/* 0BE93C 7F08BF4C 8FAD00F8 */  lw    $t5, 0xf8($sp)
/* 0BE940 7F08BF50 C5C6048C */  lwc1  $f6, 0x48c($t6)
/* 0BE944 7F08BF54 E5A60008 */  swc1  $f6, 8($t5)
/* 0BE948 7F08BF58 8E290000 */  lw    $t1, ($s1)
/* 0BE94C 7F08BF5C C5240490 */  lwc1  $f4, 0x490($t1)
/* 0BE950 7F08BF60 E5A4000C */  swc1  $f4, 0xc($t5)
/* 0BE954 7F08BF64 8E380000 */  lw    $t8, ($s1)
/* 0BE958 7F08BF68 C7080494 */  lwc1  $f8, 0x494($t8)
/* 0BE95C 7F08BF6C E5A80010 */  swc1  $f8, 0x10($t5)
/* 0BE960 7F08BF70 8E2F0000 */  lw    $t7, ($s1)
/* 0BE964 7F08BF74 8DF90488 */  lw    $t9, 0x488($t7)
/* 0BE968 7F08BF78 ADB90014 */  sw    $t9, 0x14($t5)
/* 0BE96C 7F08BF7C 10000006 */  b     .L7F08BF98
/* 0BE970 7F08BF80 8FA200A0 */   lw    $v0, 0xa0($sp)
.L7F08BF84:
/* 0BE974 7F08BF84 8FAA00F8 */  lw    $t2, 0xf8($sp)
.L7F08BF88:
/* 0BE978 7F08BF88 00001025 */  move  $v0, $zero
/* 0BE97C 7F08BF8C 914C0001 */  lbu   $t4, 1($t2)
/* 0BE980 7F08BF90 318BFFFD */  andi  $t3, $t4, 0xfffd
/* 0BE984 7F08BF94 A14B0001 */  sb    $t3, 1($t2)
.L7F08BF98:
/* 0BE988 7F08BF98 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0BE98C 7F08BF9C 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0BE990 7F08BFA0 8FB10020 */  lw    $s1, 0x20($sp)
/* 0BE994 7F08BFA4 03E00008 */  jr    $ra
/* 0BE998 7F08BFA8 27BD00F8 */   addiu $sp, $sp, 0xf8
)
#endif


#endif





/**
 * Address 0x7F08BCB8.
 */
Gfx * bondviewRemoved7F08BCB8(Gfx *arg0)
{
    #ifdef DEBUG
    // removed
    #endif

    return arg0;
}





/**
 * Address 0x7F08BCC0.
 */
Gfx *bondviewRenderProp(PropRecord *arg0, Gfx *arg1, s32 arg2)
{
    if (arg0->chr != NULL)
    {
        arg1 = chrRenderProp(arg0, arg1, arg2);
    }

    return arg1;
}





/**
 * Address 0x7F08BCF4.
 */
Gfx* bondviewGfxPlayerField5cMatrix(Gfx* gdl)
{
    gSPMatrix(gdl++, g_CurrentPlayer->field_5C, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return gdl;
}





/**
 * Unreferenced.
 * 
 * Address 0x7F08BD18.
 */
void bondviewTransformPosToViewMatrix(RenderPosView *arg0)
{
    Mtxf sp18;

    matrix_4x4_copy(&arg0->pos, (Mtxf *) &sp18);
    matrix_4x4_f32_to_s32((Mtxf *) &sp18, &arg0->view);
}



/**
 * Address 0x7F08BD48.
 * 
 * Notes: Similar to sub_GAME_7F08BE2C.
 * 
 */
void bondviewTransformManyPosToViewMatrix(RenderPosView * arg0, s32 arg1)
{
    Mtxf mtx;
    RenderPosView* rpv_entry;
    s32 i;

    i = 0;
    if (arg1 <= 0) { return; }

    // Couldn't find a better matching loop
    rpv_entry = arg0;
    do
    {
        matrix_4x4_copy(&rpv_entry->pos, &mtx);
        matrix_4x4_f32_to_s32(&mtx, &arg0[i].pos);
        i++;
        rpv_entry++;
    } while (i != arg1);
}



/**
 * Unreferenced.
 * 
 * Address 0x7F08BDC4.
 */
void sub_GAME_7F08BDC4(Mtxf *arg0)
{
    Mtxf sp20;

    matrix_4x4_copy(arg0, (Mtxf *) &sp20);
    sp20.m[3][0] -= g_CurrentPlayer->previous_model_pos.f[0];
    sp20.m[3][1] -= g_CurrentPlayer->previous_model_pos.f[1];
    sp20.m[3][2] -= g_CurrentPlayer->previous_model_pos.f[2];
    matrix_4x4_f32_to_s32((Mtxf *) &sp20, arg0);
}


void sub_GAME_7F08BE2C(Mtxf *matrices, s32 count)
{
    Mtxf copy;
    s32 i;

    for (i = 0; i < count; i++)
    {
        matrix_4x4_copy((Mtxf *)((uintptr_t)matrices + i * sizeof(Mtxf)), &copy);

        copy.m[3][0] -= g_CurrentPlayer->previous_model_pos.x;
        copy.m[3][1] -= g_CurrentPlayer->previous_model_pos.y;
        copy.m[3][2] -= g_CurrentPlayer->previous_model_pos.z;

        matrix_4x4_f32_to_s32(&copy, matrices + i);
    }
}


void sub_GAME_7F08BEEC(Mtxf *matrices, s32 count)
{
    Mtxf sp40;
    s32 i;
    s32 j;

    for (i = 0, j = 0; i < count; i++, j += sizeof(Mtxf))
    {
        matrix_4x4_multiply_homogeneous(currentPlayerGetMatrix10D4(), (Mtxf *)((u32)matrices + j), &sp40);

        sp40.m[3][0] -= g_CurrentPlayer->current_model_pos.f[0];
        sp40.m[3][1] -= g_CurrentPlayer->current_model_pos.f[1];
        sp40.m[3][2] -= g_CurrentPlayer->current_model_pos.f[2];

        matrix_4x4_f32_to_s32(&sp40, matrices + i);
    }
}


s32 getMissiontimer(void) {
#ifdef VERSION_EU
    return (mission_timer * 60) / 50;
#else
    return mission_timer;
#endif
}


void SurroundWithExplosions(int delay)
{
    g_SurroundBondWithExplosionsFlag = 1;
    g_SurroundBondWithExplosionsTicks = delay + g_GlobalTimer;
    g_PlayerTickExplodeCreatePosition = 0;
}




