/*************************************************************************
 *
 *  File: bondconstants.h
 *
 *  Declares the bondconstants.
 *
 *  $Revision: $
 *  $Date: 2021/12/28 {HOUR}:{MINUTE}:{SECOND} $
 *  $Source: /bondconstants.h,v $
 *
 **************************************************************************/


#ifndef _BONDCONSTANTS_H_
#  define _BONDCONSTANTS_H_
#include <ultra64.h>
#include <CPPLib.h>

#pragma region Tools
#ifdef __INTELLISENSE__
/* This is only a helper for VS as the IF macro is a little complex for it to work out */

#    define IF(a) IF1
#    define IF1(a)     TRY_EXPAND(a)
#    define IF_ELSE(a) _IF_E1
#    define _IF_E1(a)  TRY_EXPAND(a) EAT
#    define COMMA_IF_I(a) COMMA()
#endif

/**
 *  A single list can be made into an enum and string array for debug.
 *  Also Known as X-Macros
 *
 *  Usage: `CREATE_TYPES(ENUM, ACT, ACT_TYPES)`
 *
 *  @param type: ENUM or STRINGS
 *  @param prefix: Prefix to be applied to Enum, eg ACT for ACT_INIT
 *  @param name: Name of list to use for Enum or String  Array
 *  @return The list from name in form of type
 */
#define CREATE_TYPES(type, prefix, name)            \
            EVAL2(DEFER(EMPTY)(name(DEFER(RPAREN)() \
                CREATE_##type DEFER(LPAREN)()       \
                prefix DEFER(COMMA)()))             \
                )
#define CREATE_STRINGS(prefix, name) IF_ELSE(prefix) \
(#prefix "_" #name)(#name),
#define CREATE_ENUM(prefix, name)    IF_ELSE(prefix) \
(prefix##_##name)(name),
#define CREATE_SIZES(prefix, name, size)    IF_ELSE(prefix) \
(prefix##_##name##_size = size)(name = size),


/**
 *  A single list can be made into an enum and string array for debug.
 *  Also Known as X-Macros
 *
 *  Usage: `CREATE_TYPES1(ACT, ACT_TYPES)`
 *
 *  @param prefix: Prefix to be applied to Enum, eg ACT for ACT_INIT
 *  @param name: Name of list to use for Enum or String  Array
 *  @return an enum and (if debug) a toString list.
 */
#define CREATE_TYPES1(prefix, name)                                                      \
typedef enum prefix                                                                      \
{                                                                                        \
            EVAL2(DEFER(EMPTY)(name(DEFER(RPAREN)()                                      \
                CREATE_ENUM DEFER(LPAREN)()                                              \
                prefix DEFER(COMMA)()))                                                  \
                )                                                                        \
    prefix ##_TYPE_MAX};                                                                 \
            IF(DEFINED(DEBUG))(                                                          \
           char *prefix ## _TYPE_ToString[] = {) EVAL2(DEFER(EMPTY)(name(DEFER(RPAREN)() \
                CREATE_STRINGS1 DEFER(LPAREN)()                                          \
                prefix DEFER(COMMA)()))                                                  \
                )IF(DEFINED(DEBUG))(};)
#define CREATE_STRINGS1(prefix, name) IF_VA(DEFINED(DEBUG))(IF_ELSE(prefix)              \
(#prefix "_" #name)(#name)COMMA())

#ifdef __sgi
/**
 * Auto Generate Bitflag enums. (up to 32bit) - Unfortunatly we loose intellisense comments
 * @param NAME: Name of bitflag
 * @param a-af: bitfield names (will be appended to bitflag name for every field)
 * @return Enum of bitflags
 */
#define BITFLAG(NAME,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad,ae,af)\
typedef enum NAME \
{ /*\
  */NAME ## _NONE,/*\
  */IF(NOT(IS_EMPTY(a)))(NAME ## _ ## a = 1 << 0) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(b))))/*\
  */IF(NOT(IS_EMPTY(b)))(NAME ## _ ## b = 1 << 1) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(c))))/*\
  */IF(NOT(IS_EMPTY(c)))(NAME ## _ ## c = 1 << 2) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(d))))/*\
  */IF(NOT(IS_EMPTY(d)))(NAME ## _ ## d = 1 << 3) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(e))))/*\
  */IF(NOT(IS_EMPTY(e)))(NAME ## _ ## e = 1 << 4) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(f))))/*\
  */IF(NOT(IS_EMPTY(f)))(NAME ## _ ## f = 1 << 5) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(g))))/*\
  */IF(NOT(IS_EMPTY(g)))(NAME ## _ ## g = 1 << 6) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(h))))/*\
  */IF(NOT(IS_EMPTY(h)))(NAME ## _ ## h = 1 << 7) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(i))))/*\
  */IF(NOT(IS_EMPTY(i)))(NAME ## _ ## i = 1 << 8) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(j))))/*\
  */IF(NOT(IS_EMPTY(j)))(NAME ## _ ## j = 1 << 9) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(k))))/*\
  */IF(NOT(IS_EMPTY(k)))(NAME ## _ ## k = 1 << 10) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(l))))/*\
  */IF(NOT(IS_EMPTY(l)))(NAME ## _ ## l = 1 << 11) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(m))))/*\
  */IF(NOT(IS_EMPTY(m)))(NAME ## _ ## m = 1 << 12) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(n))))/*\
  */IF(NOT(IS_EMPTY(n)))(NAME ## _ ## n = 1 << 13) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(o))))/*\
  */IF(NOT(IS_EMPTY(o)))(NAME ## _ ## o = 1 << 14) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(p))))/*\
  */IF(NOT(IS_EMPTY(p)))(NAME ## _ ## p = 1 << 15) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(q))))/*\
  */IF(NOT(IS_EMPTY(q)))(NAME ## _ ## q = 1 << 16) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(r))))/*\
  */IF(NOT(IS_EMPTY(r)))(NAME ## _ ## r = 1 << 17) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(s))))/*\
  */IF(NOT(IS_EMPTY(s)))(NAME ## _ ## s = 1 << 18) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(t))))/*\
  */IF(NOT(IS_EMPTY(t)))(NAME ## _ ## t = 1 << 19) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(u))))/*\
  */IF(NOT(IS_EMPTY(u)))(NAME ## _ ## u = 1 << 20) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(v))))/*\
  */IF(NOT(IS_EMPTY(v)))(NAME ## _ ## v = 1 << 21) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(w))))/*\
  */IF(NOT(IS_EMPTY(w)))(NAME ## _ ## w = 1 << 22) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(x))))/*\
  */IF(NOT(IS_EMPTY(x)))(NAME ## _ ## x = 1 << 23) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(y))))/*\
  */IF(NOT(IS_EMPTY(y)))(NAME ## _ ## y = 1 << 24) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(z))))/*\
  */IF(NOT(IS_EMPTY(z)))(NAME ## _ ## z = 1 << 25) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(aa))))/*\
  */IF(NOT(IS_EMPTY(aa)))(NAME ## _ ## aa = 1 << 26) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(ab))))/*\
  */IF(NOT(IS_EMPTY(ab)))(NAME ## _ ## ab = 1 << 27) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(ac))))/*\
  */IF(NOT(IS_EMPTY(ac)))(NAME ## _ ## ac = 1 << 28) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(ad))))/*\
  */IF(NOT(IS_EMPTY(ad)))(NAME ## _ ## ad = 1 << 29) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(ae))))/*\
  */IF(NOT(IS_EMPTY(ae)))(NAME ## _ ## ae = 1 << 30) EVAL1(COMMA_IF_I(NOT(IS_EMPTY(af))))/*\
  */IF(NOT(IS_EMPTY(af)))(NAME ## _ ## af = 1 << 31)                   /*\
*/} NAME;
#else
#    define BITFLAG(...)
#endif

#pragma endregion

#pragma region Bitflags

/**
 * Reverted to manual Enums for intellisense descriptions (comments)
 * Advantage of BITFLAG macro is auto-numbering but with loss of comments
 * if the Auto numbering sounds better or I find a way to keep comments then I can revert.
 */

typedef enum ATTACKTYPE
{
    ATTACKTYPE_NONE,
    ATTACKTYPE_BOND      = 1 << 0, // aim/shoot at Bond
    ATTACKTYPE_FORWARD   = 1 << 1, // aim/shoot in front of self
    ATTACKTYPE_CHR       = 1 << 2, // aim/shoot at chr (ID should be given in entity_id)
    ATTACKTYPE_PAD       = 1 << 3, // aim/shoot at pad (ID should be given in entity_id)
    ATTACKTYPE_DIRECTION = 1 << 4, // aim/shoot in compass direction (0000, 4000, 8000, c000)
    ATTACKTYPE_AIMONLY   = 1 << 5, // aim only - do not shoot
    ATTACKTYPE_DONTTURN  = 1 << 6, // dont do a shooting animation that would change the chrs direction
    ATTACKTYPE_TARGET    = 1 << 7  // aim/shoot at whatever is in the chrs `target` field
}ATTACKTYPE;
#if 0
BITFLAG(ATTACKTYPE,
        BOND,      /* aim/shoot at Bond                                                */
        FORWARD,   /* aim/shoot in front of self                                       */
        CHR,       /* aim/shoot at chr (ID should be given in entity_id)               */
        PAD,       /* aim/shoot at pad (ID should be given in entity_id)               */
        DIRECTION, /* aim/shoot in compass direction (0000, 4000, 8000, c000)          */
        AIMONLY,   /* aim only - do not shoot                                          */
        DONTTURN,  /* dont do a shooting animation that would change the chrs direction*/
        TARGET     /* aim/shoot at whatever is in the chrs `target` field              */
)
#endif

// character flags
typedef enum CHRHIDDEN
{
    CHRHIDDEN_NONE,
    CHRHIDDEN_DROP_HELD_ITEMS       = 0x0001, // drop held items/weapons
    CHRHIDDEN_ALERT_GUARD_RELATED   = 0x0002, // Alert Guard
    CHRHIDDEN_FIRE_WEAPON_LEFT      = 0x0004, // firing left weapon
    CHRHIDDEN_FIRE_WEAPON_RIGHT     = 0x0008, // firing right weapon
                                              /*
                                                 The only time 0x10 flag is kept is when the enemy is standing.
                                                 Moving, patrolling or going to pad always clears 0x10.
                                                 A guard can keep the 0x10 flag when moving, but only if it's been
                                                 off screen and using the cheap movement logic where it doesn't
                                                 calculate collision. It'll keep the 0x10 flag until the guard
                                                 appears on screen.
                                              */
    CHRHIDDEN_OFFSCREEN_PATROL      = 0x0010,
    CHRHIDDEN_REMOVE                = 0x0020, // remove character
    CHRHIDDEN_TIMER_ACTIVE          = 0x0040, // chr timer is active
    CHRHIDDEN_FIRE_TRACER           = 0x0080, // spawn a tracer
    CHRHIDDEN_MOVING                = 0x0100, // moving
    CHRHIDDEN_BACKGROUND_AI         = 0x0200, // chr has an AI script currently running
    CHRHIDDEN_0400                  = 0x0400, // unknown
    CHRHIDDEN_FREEZE                = 0x0800, // freeze current animation state
    CHRHIDDEN_RAND_FLINCH_1         = 0x1000, // unknown
    CHRHIDDEN_RAND_FLINCH_2         = 0x2000, // unknown
    CHRHIDDEN_RAND_FLINCH_4         = 0x4000, // unknown
    CHRHIDDEN_RAND_FLINCH_8         = 0x8000  // unknown
}CHRHIDDEN;

#define CHRHIDDEN_RAND_FLINCH_MASK (CHRHIDDEN_RAND_FLINCH_1 | CHRHIDDEN_RAND_FLINCH_2 | CHRHIDDEN_RAND_FLINCH_4 | CHRHIDDEN_RAND_FLINCH_8)

typedef enum CHRFLAG
{
    CHRFLAG_NONE,
    CHRFLAG_INIT                         = 0x00000001 , // initialize chr
    CHRFLAG_CLONE                        = 0x00000002 , // clone on heard gunfire (used by GAILIST_STANDARD_GUARD)
    CHRFLAG_NEAR_MISS                    = 0x00000004 , // chr was just nearly shot (sometimes set on direct hit) - resets every tick
    CHRFLAG_HAS_BEEN_ON_SCREEN           = 0x00000008 , // chr has been on screen before
    CHRFLAG_INVINCIBLE                   = 0x00000010 , // invincible
    CHRSTART_FORCENOBLOOD                = 0x00000020,  // canonical name
    CHRFLAG_CAN_SHOOT_CHRS               = 0x00000040 , // can shoot other guards
    CHRFLAG_00000080                     = 0x00000080 , // unknown
    CHRFLAG_WAS_DAMAGED                  = 0x00000100 , // chr has taken damage (not invincible)
    CHRFLAG_00000200                     = 0x00000200 , // Possibly isBGAI
    CHRFLAG_HIDDEN                       = 0x00000400 , // hidden
    CHRFLAG_NO_AUTOAIM                   = 0x00000800 , // no autoaim
    CHRFLAG_LOCK_Y_POS                   = 0x00001000 , // lock y position (no gravity, used for dam/cradle jump)
    CHRFLAG_NO_SHADOW                    = 0x00002000 , // no shadow
    CHRFLAG_IGNORE_ANIM_TRANSLATION      = 0x00004000 , // ignore animation translation
    CHRFLAG_IMPACT_ALWAYS                = 0x00008000 , // Trev on cradle sets this flag so he can be shot off the platform
    CHRFLAG_00010000                     = 0x00010000 , // unknown
    CHRFLAG_00020000                     = 0x00020000 , // unknown
    CHRFLAG_00040000                     = 0x00040000 , // maybe: update guard ACTION ?
    CHRFLAG_INCREASE_RUNNING_SPEED       = 0x00080000 , // increase sprinting speed (used by trevelyan)
    CHRFLAG_COUNT_DEATH_AS_CIVILIAN      = 0x00100000 , // count death as civilian killed
    CHRFLAG_WAS_HIT                      = 0x00200000 , // chr has been hit (even if invincible)
    CHRFLAG_00400000                     = 0x00400000 , // unknown
    CHRFLAG_CULL_USING_HITBOX            = 0x00800000 , // cull chr using hitbox instead of tile/clipping (useful with lock y pos flag)
    CHRFLAG_01000000                     = 0x01000000 , // unknown
    CHRFLAG_02000000                     = 0x02000000 , // unknown
    CHRFLAG_04000000                     = 0x04000000 , // unknown NoFade
    CHRFLAG_08000000                     = 0x08000000 , // unknown
    CHRFLAG_10000000                     = 0x10000000 , // unknown
    CHRFLAG_20000000                     = 0x20000000 , // unknown
    CHRFLAG_40000000                     = 0x40000000 , // unknown
    CHRFLAG_80000000                     = 0x80000000   // unknown
}CHRFLAG;

// collision detection types
typedef enum CDTYPE
{
    CDTYPE_OBJS                   = 0x0001,
    CDTYPE_DOORS                  = 0x0002,
    CDTYPE_PLAYERS                = 0x0004,
    CDTYPE_CHRS                   = 0x0008,
    CDTYPE_PATHBLOCKER            = 0x0010, // glass and scenery with OBJFLAG_PATHBLOCKER
    CDTYPE_BG                     = 0x0020,
    CDTYPE_OBJSIMMUNETOGUNFIRE    = 0x0080,
    CDTYPE_AIOPAQUE               = 0x0100, // exclude objects with OBJFLAG_AISEETHROUGH
    CDTYPE_OBJSIMMUNETOEXPLOSIONS = 0x0200,
    CDTYPE_OBJSNOTSAFEORHELI      = 0x0400,
    CDTYPE_DOORSWITHOUTFLAG       = 0x0800,
    CDTYPE_CLOSEDDOORS            = 0x1000,
    CDTYPE_OPENDOORS              = 0x2000,
    CDTYPE_AJARDOORS              = 0x4000,
    CDTYPE_DOORSLOCKEDTOAI        = 0x8000,
    CDTYPE_ALL                    = 0x003f
} CDTYPE;

typedef enum GUARD_SETUP_FLAG // u16
{
    GUARD_SETUP_FLAG_NONE                = 0,
    GUARD_SETUP_FLAG_SUNGLASSES          = 0x0001,
    GUARD_SETUP_FLAG_SUNGLASSES_50       = 0x0002, // 50% chance of sunglasses
    GUARD_SETUP_FLAG_CHR_CLONE           = 0x0004, // set CHRFLAG_CLONE
    GUARD_SETUP_FLAG_CHR_INVINCIBLE      = 0x0008, // set CHRFLAG_INVINCIBLE
    GUARD_SETUP_FLAG_0010                = 0x0010, // unused
    GUARD_SETUP_FLAG_0020                = 0x0020, // unused
    GUARD_SETUP_FLAG_0040                = 0x0040, // unknown, used in train
    GUARD_SETUP_FLAG_0080                = 0x0080, // unused
    GUARD_SETUP_FLAG_0100                = 0x0100, // unused
    GUARD_SETUP_FLAG_0200                = 0x0200, // unused
    GUARD_SETUP_FLAG_0400                = 0x0400, // unused
    GUARD_SETUP_FLAG_0800                = 0x0800, // unused
    GUARD_SETUP_FLAG_1000                = 0x1000, // unused
    GUARD_SETUP_FLAG_2000                = 0x2000, // unused
    GUARD_SETUP_FLAG_4000                = 0x4000, // unused
    GUARD_SETUP_FLAG_8000                = 0x8000 // unused
} GUARD_SETUP_FLAG;

//chr flags2
BITFLAG(FLAGS2,
        DONT_POINT_AT_BOND,
        02,
        04
)

//PROP SOUND (Unknown values, only name known)
BITFLAG(PS_FLAGS2,
        NO_DISTANCEQ
)

// prop definition flags
typedef enum PROPFLAG
{
    PROPFLAG_RENDERPOSTBG                = 0x00000001, // Fall to Ground
    PROPFLAG_ONSCREEN                    = 0x00000002, //  In Air Rotated 90 Deg Upside-Down
    PROPFLAG_ENABLED                     = 0x00000004, // In Air Upside-Down
    PROPFLAG_00000008                    = 0x00000008, // In Air
    PROPFLAG_00000010                    = 0x00000010, // Scale to Pad Bounds
    PROPFLAG_00000020                    = 0x00000020, // Scale X to Pad Bounds
    PROPFLAG_00000040                    = 0x00000040, // Scale Y to Pad Bounds
    PROPFLAG_00000080                    = 0x00000080, // Scale Z to Pad Bounds
    PROPFLAG_00000100                    = 0x00000100, // Force Collisions
    PROPFLAG_00000200                    = 0x00000200, // Glass Env Mapping Style
    PROPFLAG_ILLUMINATED                 = 0x00000400, /* ignore Stan Colour?*/
    PROPFLAG_00000800                    = 0x00000800, // Free Standing Glass
    PROPFLAG_00001000                    = 0x00001000, // Absolute Position
    PROPFLAG_AIUNDROPPABLE               = 0x00002000, /* Item Not Droppedz*/
    PROPFLAG_ASSIGNEDTOCHR               = 0x00004000, // Assigned to Actor
    PROPFLAG_INSIDEANOTHEROBJ            = 0x00008000, // Embedded Object
    PROPFLAG_FORCEMORTAL                 = 0x00010000, // unknown
    PROPFLAG_INVINCIBLE                  = 0x00020000, // Invincible
    PROPFLAG_00040000                    = 0x00040000, // Allow Pickup (chr_type)
    PROPFLAG_00080000                    = 0x00080000, // Collect Object by Interaction Button Only
    PROPFLAG_UNCOLLECTABLE               = 0x00100000, /* Item Not Collectable*/
    PROPFLAG_00200000                    = 0x00200000, // Bounce and Destroy If Shot
    PROPFLAG_00400000                    = 0x00400000, // unknown
    PROPFLAG_00800000                    = 0x00800000, // unknown
    PROPFLAG_01000000                    = 0x01000000, // Embedded Object
    PROPFLAG_CANNOT_ACTIVATE             = 0x02000000, // Cannot Activate Door/Object
    PROPFLAG_04000000                    = 0x04000000, // AI Sees Through Door/Object
    PROPFLAG_DOOR_TWOWAY                 = 0x08000000, // Open Away From Player
    PROPFLAG_WEAPON_LEFTHANDED           = 0x10000000, /* Left-Handed weapon*/
    PROPFLAG_GLASS_HASPORTAL             = 0x10000000, /* Glass Has Portal*/
    PROPFLAG_CULL_BEHIND_DOOR            = 0x10000000, // Area Behind Door Invisible
    PROPFLAG_FIXED_MONITOR               = 0x10000000, // Monitor Fixed
    PROPFLAG_CCTV_DISABLED               = 0x10000000, // Disable security camera
    PROPFLAG_IS_DRONE_GUN                = 0x10000000, // drone gun
    PROPFLAG_DOOR_OPENTOFRONT            = 0x20000000, /* Open Backwards*/
    PROPFLAG_SPECIAL_FUNC                = 0x20000000, //Special Function
    PROPFLAG_CONCEAL_GUN                 = 0x20000000, //Conceal Weapon
    PROPFLAG_MONITOR_RENDERPOSTBG        = 0x40000000,
    PROPFLAG_NO_PORTAL_CLOSE             = 0x40000000, // Area Behind Door Visible
    PROPFLAG_NO_AMMO                     = 0x40000000,/* No Ammo on pickup */
    PROPFLAG_80000000                    = 0x80000000, // Open By Default/Weapon Paired for Player
    PROPFLAG_IS_DOUBLE                   = 0x80000000
}PROPFLAG;
// prop definition flags
typedef enum PROPFLAG2
{
    PROPFLAG2_00000001            = 0x00000001, // Activate Drone Gun
    PROPFLAG2_00000002            = 0x00000002, // lightweight (move when shot)
    PROPFLAG2_00000004            = 0x00000004, // Interaction Text Not Shown for Doors
    PROPFLAG2_00000008            = 0x00000008, // Don't Load in Multiplayer
    PROPFLAG2_00000010            = 0x00000010, // Don't Load on Agent Mode
    PROPFLAG2_00000020            = 0x00000020, // Don't Load on Secret Agent Mode
    PROPFLAG2_00000040            = 0x00000040, // Don't Load on 00 Agent Mode
    PROPFLAG2_00000080            = 0x00000080, // Don't Load on 007 Mode
    PROPFLAG2_NOFALL              = 0x00000100, // immobile
    PROPFLAG2_FALLWITHOUTROTATION = 0x00000200, // used with mines
    PROPFLAG2_LINKEDTOSAFE        = 0x00000400, // unknown
    PROPFLAG2_INTERACTCHECKLOS    = 0x00000800, // Don't activate if stan gap Bond/Object
    PROPFLAG2_00001000            = 0x00001000, // Watch Magnet Attract through Walls/Objects
    PROPFLAG2_00002000            = 0x00002000, // Remove When Destroyed
    PROPFLAG2_00004000            = 0x00004000, // Immune to Gunfire
    PROPFLAG2_SHOOTTHROUGH        = 0x00008000, // Can Shoot Through Object
    PROPFLAG2_00010000            = 0x00010000, // Always Visible (in front)
    PROPFLAG2_00020000            = 0x00020000, // unknown
    PROPFLAG2_00040000            = 0x00040000, // Hide inventory item (for tagged armor/ammo/magazine)
    PROPFLAG2_00080000            = 0x00080000, // Invincible Except to Explosions
    PROPFLAG2_00100000            = 0x00100000, // Bulletproof Glass
    PROPFLAG2_00200000            = 0x00200000, // Immune to Explosions
    PROPFLAG2_00400000            = 0x00400000, // Don't load on 2P
    PROPFLAG2_00800000            = 0x00800000, // Don't load on 3P
    PROPFLAG2_01000000            = 0x01000000, // Don't load on 4P
    PROPFLAG2_THROWTHROUGH        = 0x02000000, // Rockets/Mines/Grenades Pass Through
    PROPFLAG2_04000000            = 0x04000000, // unknown
    PROPFLAG2_08000000            = 0x08000000, // One-Way Lock (Front)
    PROPFLAG2_10000000            = 0x10000000, // One-Way Lock (Back)
    PROPFLAG2_20000000            = 0x20000000, // Character AI Cannot Operate
    PROPFLAG2_40000000            = 0x40000000, // Deactivate Special Feature
    PROPFLAG2_DOOR_ALTCOORDSYSTEM = 0x80000000  // Massive Explosion (08 Type)/Rotating Disabled Drone Gun (0D Type)
} PROPFLAG2;

typedef enum DOORFLAG
{
    DOORFLAG_0001            = 0x00000001,
    DOORFLAG_WINDOWED        = 0x00000002,
    DOORFLAG_0004            = 0x00000004,
    DOORFLAG_FLIP            = 0x00000008,
    DOORFLAG_AUTOMATIC       = 0x00000010,
    DOORFLAG_0020            = 0x00000020,
    DOORFLAG_ROTATEDPAD      = 0x00000040,
    DOORFLAG_080             = 0x00000080,
    DOORFLAG_100             = 0x00000100,
    DOORFLAG_LONGRANGE       = 0x00000200,
    DOORFLAG_DAMAGEONCONTACT = 0x00000400, // Lasers
    DOORFLAG_UNBLOCKABLEOPEN = 0x00000800, // Skip collision checks when opening
    DOORFLAG_4000            = 0x00004000, // Two Investigation vertical doors after lasers
    DOORFLAG_CANNOT_ACTIVATE = 0x02000000,
    DOORFLAG_KEEPOPEN        = 0x80000000

} DOORFLAG;

typedef enum DOORMODE
{
    DOORMODE_IDLE,
    DOORMODE_OPENING,
    DOORMODE_CLOSING,
    // Waiting for sibling door to close. Eg. Dam gates in GE
    DOORMODE_WAITING
} DOORMODE;

typedef enum DOORSTATE
{
    DOORSTATE_STATIONARY,
    DOORSTATE_OPENING,// also OPEN but NOT AIlist compatible (02)
    DOORSTATE_CLOSING, // also CLOSE but NOT AIlist compatible (01)
    DOORSTATE_WAITING
} DOORSTATE;

#define DOORTYPE_SLIDING    0
// GE only - Bunker flexi door
#define DOORTYPE_FLEXI1     1
#define DOORTYPE_FLEXI2     2
#define DOORTYPE_FLEXI3     3
#define DOORTYPE_VERTICAL   4
#define DOORTYPE_SWINGING   5
// GE only - Caverns
#define DOORTYPE_EYE        6
// GE only - Caverns
#define DOORTYPE_IRIS       7
// GE only - Surface grate and Train floor panel
#define DOORTYPE_FALLAWAY   8
// GE only
#define DOORTYPE_AZTECCHAIR 9
// Attack Ship windows
#define DOORTYPE_HULL       10
#define DOORTYPE_LASER      11

typedef enum DOOR_OPEN_SOUND
{
    DOOR_OPEN_SOUND_NONE = 0,
    DOOR_OPEN_SOUND_01,
    DOOR_OPEN_SOUND_02,
    DOOR_OPEN_SOUND_METAL,
    DOOR_OPEN_SOUND_04,
    DOOR_OPEN_SOUND_WOOD,
    DOOR_OPEN_SOUND_06,
    DOOR_OPEN_SOUND_WOOD_2,
    DOOR_OPEN_SOUND_WOOD_3,
    DOOR_OPEN_SOUND_09,
    DOOR_OPEN_SOUND_METAL_2,
    DOOR_OPEN_SOUND_11,
    DOOR_OPEN_SOUND_METAL_3,
    DOOR_OPEN_SOUND_13,
    DOOR_OPEN_SOUND_HYDROLIC,
    DOOR_OPEN_SOUND_STONE,
    DOOR_OPEN_SOUND_16,
    DOOR_OPEN_SOUND_METAL_4,
    DOOR_OPEN_SOUND_18
} DOOR_OPEN_SOUND;

typedef enum DROPTYPE
{
    DROPTYPE_DEFAULT      = 1,
    DROPTYPE_SURRENDER    = 2,
    DROPTYPE_THROWGRENADE = 3,
    DROPTYPE_HAT          = 4
} DROPTYPE;

typedef enum PROJECTILEFLAG
{
    PROJECTILEFLAG_AIRBORNE    = 0x00000001,
    PROJECTILEFLAG_00000002    = 0x00000002,
    PROJECTILEFLAG_STICKY      = 0x00000004,
    PROJECTILEFLAG_POWERED     = 0x00000010,
    PROJECTILEFLAG_00000020    = 0x00000020,
    PROJECTILEFLAG_LAUNCHING   = 0x00000080,
    PROJECTILEFLAG_00000100    = 0x00000100,
    PROJECTILEFLAG_FALLING     = 0x00000400,
    PROJECTILEFLAG_SLIDING     = 0x00000800,
    PROJECTILEFLAG_00001000    = 0x00001000,
    PROJECTILEFLAG_00002000    = 0x00002000,
    PROJECTILEFLAG_NOTIMELIMIT = 0x00004000,
    PROJECTILEFLAG_INROOM      = 0x00008000,
    PROJECTILEFLAG_00010000    = 0x00010000,
    PROJECTILEFLAG_LIGHTWEIGHT = 0x40000000,
    PROJECTILEFLAG_FREE        = 0x80000000
} PROJECTILE_FLAG;

// Might be the same flags as PROJECTILEFLAG
#define EMBEDMENTFLAG_FREE 0x00000001

/* door lock flags*/
BITFLAG(DOOR_LOCK,
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7
)

/** PropDefHeaderRecord->state only u8 */
typedef enum PROPSTATE {
    PROPSTATE_NONE = 0x00,
    PROPSTATE_DAMAGED = 0x01,
    PROPSTATE_2 = 0x02, // maybe "double damaged"
    PROPSTATE_RESPAWN = 0x04,
    PROPSTATE_EXT_COLISION_BLOCK = 0x08,
    PROPSTATE_10 = 0x10,
    PROPSTATE_20 = 0x20,
    PROPSTATE_ACTIVATED = 0x40,
    PROPSTATE_DESTROYED = 0x80
} PROPSTATE;

#define PROPSTATE_NORMAL PROPSTATE_NONE

BITFLAG(PLAYERFLAG,
        LOCKCONTROLS,
        NOCONTROL,
        NOTIMER
)
//PropDef bitflag canonically PROPHID_
BITFLAG(RUNTIMEBITFLAG,
        00000001,
        00000002,
        REMOVE, /* removes object when set                                     */
        ISRETICK,
        TAGGED,
        THROWING_KNIFE_RELATED,
        EMBEDDED,
        DEPOSIT, /* depositted (thrown/launching)                               */
        00000100,
        BEENOPENED,
        DESTROYED, /* only set with disabled or destroyed doors                   */
        00000800,
        00001000,
        PADLOCKEDDOOR,
        ACTIVATED, /* activated                                                   */
        00008000,
        00010000,
        00020000, /* owner 2bit (0-3) used to                                    */
        00040000, /* attribute kills to players                                  */
        HASOWNER,
        00100000,
        00200000,
        00400000,
        00800000,
        01000000,
        02000000,
        04000000,
        08000000,
        10000000,
        20000000,
        40000000,
        80000000
)

#define RUNTIMEBITFLAG_OWNER    0x60000
#define RUNTIMEBITSHIFT_OWNER   0x11
#define RUNTIMEBITFLAG_00000001   0x1

BITFLAG(WEAPONSTATBITFLAG,
        00000001,
        SINGLE_USE_RELOAD, /* skip from fire to reload animation; item "disappears" after use, redrawn from off-screen like knives" */
        BURST_FIRE, /* fire three round burst*/
        HAS_AUTO_AIM, /* auto aim capable*/
        CLICKY, /* if holding trigger, click if empty */
        00000020,
        00000040,
        00000080,
        ONLY_1_HANDED, /* requires HOLD_AS_GUN as well */
        HOLD_AS_GUN, /* default 2 handed*/
        MIRROR_DUAL, /* mirror double weapon, not copy */
        SHOW_FIRST_PERSON, /* display 1st person model */
        FIRST_SHOT_ACCURACY, /* for a single first shot, inaccuracy multiplied by 0.25 */
        HIDE_FIRST_PERSON_HAND, /* hide first person model in hand */
        HIDE_FIRST_PERSON_MENU, /* hide first person model in menu */
        DISABLE_CROUCH, /* can not crouch */
        PLAYER_STAT_HIT, /* count hits in player statistics */
        USE_HOLD_TIME, /* increment hold time when used, to consider as weapon of choice */
        HAS_AMMO,
        HIDE_AMMO_DISPLAY, /* do not display ammo on screen */
        CAN_DUAL_WIELD, /* capable of doubles */
        AMMO_CLIP_LIMIT, /* limit ammo to assigned value on clip */
        NO_CLIP_RELOADS, /* no ammo clip/reloads - draw straight from ammo supply (right of icon) */
        00800000,
        01000000,
        02000000,
        04000000,
        08000000,
        10000000,
        20000000,
        40000000,
        80000000
)


#define OBJECTTYPE_00 0x00
#define OBJECTTYPE_01 0x01
#define OBJECTTYPE_02 0x02
#define OBJECTTYPE_03 0x03
#define OBJECTTYPE_04 0x04
#define OBJECTTYPE_05 0x05
#define OBJECTTYPE_06 0x06
#define OBJECTTYPE_07 0x07
#define OBJECTTYPE_WEAPON 0x08
#define OBJECTTYPE_09 0x09
#define OBJECTTYPE_10 0x10
#define OBJECTTYPE_11 0x11
#define OBJECTTYPE_12 0x12
#define OBJECTTYPE_13 0x13
#define OBJECTTYPE_14 0x14
#define OBJECTTYPE_15 0x15
#define OBJECTTYPE_16 0x16
#define OBJECTTYPE_17 0x17
#define OBJECTTYPE_18 0x18
#define OBJECTTYPE_19 0x19
#define OBJECTTYPE_20 0x20
#define OBJECTTYPE_21 0x21
#define OBJECTTYPE_22 0x22
#define OBJECTTYPE_23 0x23
#define OBJECTTYPE_24 0x24
#define OBJECTTYPE_25 0x25
#define OBJECTTYPE_26 0x26
#define OBJECTTYPE_27 0x27
#define OBJECTTYPE_28 0x28
#define OBJECTTYPE_29 0x29
#define OBJECTTYPE_30 0x30
#define OBJECTTYPE_31 0x31
#define OBJECTTYPE_32 0x32
#define OBJECTTYPE_33 0x33
#define OBJECTTYPE_34 0x34
#define OBJECTTYPE_35 0x35
#define OBJECTTYPE_36 0x36

#define QUADRANT_BACK          0x01
#define QUADRANT_SIDE1         0x02
#define QUADRANT_SIDE2         0x04
#define QUADRANT_FRONT         0x08
#define QUADRANT_2NDWPTOTARGET 0x10 // second waypoint on route to target
#define QUADRANT_20            0x20 // second waypoint on route to target

#define CULLMODE_BOTH  0
#define CULLMODE_NONE  1
#define CULLMODE_FRONT 2
#define CULLMODE_BACK  3

#pragma endregion

#pragma region Constants

#define SP_BOOT_SZ 0x10
#define SP_RMON_SZ 0x300
#define SP_IDLE_SZ 0x40
#define SP_SHED_SZ 0x200
#define SP_MAIN_SZ 0x8000
#define SP_AUDI_SZ 0x1000
#define SP_DEBUG_SZ 0x6B0

/*
Enums Index by adding 1 to the list from the first value, unless this value
is not 0, it should not be set for every item
Enums with -1 in them should be declaired first allowing subsequent values to
once again be 0 based indices.
I have replaced below except where non-linear values are used.
RegEx for hex matching \b = 0x(?:[0-9A-Fa-f]{1}|[0-9A-Fa-f]{2})\b
RegEx for enum cleanup (enums define a sequential list without having to specify
each and every value) \b *= (?:[0-9])*\b
Regex Tabulisation (,[^,]*?){n}\}.$ where n is a number (from end)
Typed enums only apply to C++ as E_RGBA var = BRIEF_M is valid in C,
however its good practice to type them.
For C though, manual Typing info must be embedded in the enum
eg BRIEF_M is C equivelant to C++ MISSION_BRIEFING var = M
    or C#/VB var = BRIEF.M
COUNT does not cause allocation of storage or change resulting
      asm, just a nice helper if one wanted to loop through an
      enum
      Note: Count also serves as a nice debug tool verifying auto-enums
*/

//typedef u16 PAD;
//typedef u16 PAD3D;

typedef enum AI_CMD
{
#ifndef _SYNHILITE

// makes enum list
#    ifdef __sgi
#        define _AI_CMD(C) CAT(AI_, CMDNAME),
#        define _AI_DEBUG(C) CAT(AI_, CMDNAME),
#        define _AI_CMD_POLYMORPH(CMD, A, P, Q, D)
#        define DEFINE(x)
#    else
#        define _AI_CMD(...)   CAT(AI_, CMDNAME),
#        define _AI_DEBUG(...) CAT(AI_, CMDNAME),
#        define _AI_CMD_POLYMORPH(...)
#        define DEFINE(...)
#    endif


#    include "aicommands.def"
#endif /* !_SYNHILITE */

    AI_CMD_COUNT
} AI_CMD;

// Number of bytes for AI cmds, GE 1, PD 2
#define AICMDSIZE ((u8)(AI_CMD_COUNT / 255) + 1)


/* Motion capture actor:      Duncan Botwood
 * Motion capture assistance: B Jones
 * Recorded using 'flock of birds' system by Ascension Technology Corporation,
 * in a freezing metal barn in the depths of winter
 * Note: Animations are double handed weapon (KF7) unless specified (unarmed,
 * one_handed_weapon, dual_wield)
 */
typedef enum ANIMATIONS
{
    ANIM_idle,
    ANIM_fire_standing,
    ANIM_fire_standing_fast,
    ANIM_fire_hip,
    ANIM_fire_shoulder_left,
    ANIM_fire_turn_right1,
    ANIM_fire_turn_right2,
    ANIM_fire_kneel_right_leg,
    ANIM_fire_kneel_left_leg,
    ANIM_fire_kneel_left,
    ANIM_fire_kneel_right,
    ANIM_fire_roll_left,
    ANIM_fire_roll_right1,
    ANIM_fire_roll_left_fast,
    ANIM_hit_left_shoulder,
    ANIM_hit_right_shoulder,
    ANIM_hit_left_arm,
    ANIM_hit_right_arm,
    ANIM_hit_left_hand,
    ANIM_hit_right_hand,
    ANIM_hit_left_leg,
    ANIM_hit_right_leg,
    ANIM_death_genitalia,                                  /* Thank you Mr. Botwood, here is your award */
    ANIM_hit_neck,
    ANIM_death_neck,
    ANIM_death_stagger_back_to_wall,
    ANIM_death_forward_face_down,
    ANIM_death_forward_spin_face_up,
    ANIM_death_backward_fall_face_up1,
    ANIM_death_backward_spin_face_down_right,
    ANIM_death_backward_spin_face_up_right,
    ANIM_death_backward_spin_face_down_left,
    ANIM_death_backward_spin_face_up_left,
    ANIM_death_forward_face_down_hard,
    ANIM_death_forward_face_down_soft,
    ANIM_death_fetal_position_right,
    ANIM_death_fetal_position_left,
    ANIM_death_backward_fall_face_up2,
    ANIM_side_step_left,
    ANIM_fire_roll_right2,
    ANIM_walking,
    ANIM_sprinting,
    ANIM_running,
    ANIM_bond_eye_walk,
    ANIM_bond_eye_fire,
    ANIM_bond_watch,
    ANIM_surrendering_armed,
    ANIM_surrendering_armed_drop_weapon,
    ANIM_fire_walking,
    ANIM_fire_running,
    ANIM_null50,                                           /* invalid slot */
    ANIM_null51,                                           /* invalid slot */
    ANIM_fire_jump_to_side_left,
    ANIM_fire_jump_to_side_right,
    ANIM_hit_butt_long,
    ANIM_hit_butt_short,
    ANIM_death_head,
    ANIM_death_left_leg,
    ANIM_slide_right,
    ANIM_slide_left,
    ANIM_jump_backwards,
    ANIM_extending_left_hand,
    ANIM_fire_throw_grenade,
    ANIM_spotting_bond,                                    /* used by chr ai command guard_points_at_bond */
    ANIM_look_around,                                      /* used by chr ai command GUARD_ANIM_LOOKS_AROUND_SELF  */
    ANIM_fire_standing_one_handed_weapon,
    ANIM_fire_standing_draw_one_handed_weapon_fast,
    ANIM_fire_standing_draw_one_handed_weapon_slow,
    ANIM_fire_hip_one_handed_weapon_fast,
    ANIM_fire_hip_one_handed_weapon_slow,
    ANIM_fire_hip_forward_one_handed_weapon,
    ANIM_fire_standing_right_one_handed_weapon,
    ANIM_fire_step_right_one_handed_weapon,
    ANIM_fire_standing_left_one_handed_weapon_slow,
    ANIM_fire_standing_left_one_handed_weapon_fast,
    ANIM_fire_kneel_forward_one_handed_weapon_slow,
    ANIM_fire_kneel_forward_one_handed_weapon_fast,
    ANIM_fire_kneel_right_one_handed_weapon_slow,
    ANIM_fire_kneel_right_one_handed_weapon_fast,
    ANIM_fire_kneel_left_one_handed_weapon_slow,
    ANIM_fire_kneel_left_one_handed_weapon_fast,
    ANIM_fire_kneel_left_one_handed_weapon,
    ANIM_aim_walking_one_handed_weapon,
    ANIM_aim_walking_left_one_handed_weapon,
    ANIM_aim_walking_right_one_handed_weapon,
    ANIM_aim_running_one_handed_weapon,
    ANIM_aim_running_right_one_handed_weapon,
    ANIM_aim_running_left_one_handed_weapon,
    ANIM_aim_sprinting_one_handed_weapon,
    ANIM_running_one_handed_weapon,
    ANIM_sprinting_one_handed_weapon,
    ANIM_null91,                                           /* invalid slot */
    ANIM_null92,                                           /* invalid slot */
    ANIM_null93,                                           /* invalid slot */
    ANIM_null94,                                           /* invalid slot */
    ANIM_null95,                                           /* invalid slot */
    ANIM_null96,                                           /* invalid slot */
    ANIM_draw_one_handed_weapon_and_look_around,
    ANIM_draw_one_handed_weapon_and_stand_up,
    ANIM_aim_one_handed_weapon_left_right,
    ANIM_cock_one_handed_weapon_and_turn_around,
    ANIM_holster_one_handed_weapon_and_cross_arms,
    ANIM_cock_one_handed_weapon_turn_around_and_stand_up,
    ANIM_draw_one_handed_weapon_and_turn_around,
    ANIM_step_foward_and_hold_one_handed_weapon,
    ANIM_holster_one_handed_weapon_and_adjust_suit,
    ANIM_idle_unarmed,
    ANIM_walking_unarmed,
    ANIM_fire_walking_dual_wield,
    ANIM_fire_walking_dual_wield_hands_crossed,
    ANIM_fire_running_dual_wield,
    ANIM_fire_running_dual_wield_hands_crossed,
    ANIM_fire_sprinting_dual_wield,
    ANIM_fire_sprinting_dual_wield_hands_crossed,
    ANIM_walking_female,
    ANIM_running_female,
    ANIM_fire_kneel_dual_wield,
    ANIM_fire_kneel_dual_wield_left,
    ANIM_fire_kneel_dual_wield_right,
    ANIM_fire_kneel_dual_wield_hands_crossed,
    ANIM_fire_kneel_dual_wield_hands_crossed_left,
    ANIM_fire_kneel_dual_wield_hands_crossed_right,
    ANIM_fire_standing_dual_wield,
    ANIM_fire_standing_dual_wield_left,
    ANIM_fire_standing_dual_wield_right,
    ANIM_fire_standing_dual_wield_hands_crossed_left,
    ANIM_fire_standing_dual_wield_hands_crossed_right,
    ANIM_fire_standing_aiming_down_sights,
    ANIM_fire_kneel_aiming_down_sights,
    ANIM_hit_taser,                                        /* unused tazer boy hit reaction */
    ANIM_death_explosion_forward,
    ANIM_death_explosion_left1,
    ANIM_death_explosion_back_left,
    ANIM_death_explosion_back1,
    ANIM_death_explosion_right,
    ANIM_death_explosion_forward_right1,
    ANIM_death_explosion_back2,
    ANIM_death_explosion_forward_roll,
    ANIM_death_explosion_forward_face_down,
    ANIM_death_explosion_left2,
    ANIM_death_explosion_forward_right2,
    ANIM_death_explosion_forward_right2_alt,               /* copy of right2 with different fall */
    ANIM_death_explosion_forward_right3,
    ANIM_null143,                                          /* invalid slot */
    ANIM_null144,                                          /* invalid slot */
    ANIM_null145,                                          /* invalid slot */
    ANIM_null146,                                          /* invalid slot */
    ANIM_running_hands_up,
    ANIM_sprinting_hands_up,
    ANIM_aim_and_blow_one_handed_weapon,
    ANIM_aim_one_handed_weapon_left,
    ANIM_aim_one_handed_weapon_right,
    ANIM_conversation,
    ANIM_drop_weapon_and_show_fight_stance,                /* orthodox stance woo */
    ANIM_yawning,
    ANIM_swatting_flies,
    ANIM_scratching_leg,
    ANIM_scratching_butt,
    ANIM_adjusting_crotch,
    ANIM_sneeze,
    ANIM_conversation_cleaned,                             /* cleaned up copy of ANIM_conversation (compare left wrist) */
    ANIM_conversation_listener,
    ANIM_startled_and_looking_around,
    ANIM_laughing_in_disbelief,
    ANIM_surrendering_unarmed,
    ANIM_coughing_standing,
    ANIM_coughing_kneel1,
    ANIM_coughing_kneel2,
    ANIM_standing_up,
    ANIM_null169,                                          /* invalid slot */
    ANIM_dancing,
    ANIM_dancing_one_handed_weapon,
    ANIM_keyboard_right_hand1,
    ANIM_keyboard_right_hand2,
    ANIM_keyboard_left_hand,
    ANIM_keyboard_right_hand_tapping,
    ANIM_bond_eye_fire_alt,                                /* unused */
    ANIM_dam_jump,
    ANIM_surface_vent_jump,
    ANIM_cradle_jump,
    ANIM_cradle_fall,
    ANIM_credits_bond_kissing,
    ANIM_credits_natalya_kissing,
    ANIM_MAX
} ANIMATIONS;

typedef enum AIRCRAFT_ANIMATION
{
    AIRCRAFT_ANIMATION_helicopter_cradle,
    AIRCRAFT_ANIMATION_plane_runway,
    AIRCRAFT_ANIMATION_helicopter_takeoff,
    AIRCRAFT_ANIMATION_MAX
} AIRCRAFT_ANIMATION;


/*
values need to be verified against cheat_buttons.c : void cheatButtonHandleCheatsTurnedOn(CHEAT_ID cheat)
*/
typedef enum CHEAT_IDS
{

    CHEAT_UNUSED,
    CHEAT_EXTRA_MP_CHARS,
    CHEAT_INVINCIBILITY,
    CHEAT_ALLGUNS,
    CHEAT_MAXAMMO,
    CHEAT_DEBUG_UNK5, /* unverified */
    CHEAT_DEACTIVATE_INVINCIBILITY,
    CHEAT_LINEMODE,
    CHEAT_2X_HEALTH,
    CHEAT_2X_ARMOR,
    CHEAT_INVISIBILITY,
    CHEAT_INFINITE_AMMO,
    CHEAT_DK_MODE,
    CHEAT_EXTRA_WEAPONS,
    CHEAT_TINY_BOND,
    CHEAT_PAINTBALL,
    CHEAT_10X_HEALTH,
    CHEAT_MAGNUM,
    CHEAT_LASER,
    CHEAT_GOLDEN_GUN,
    CHEAT_SILVER_PP7,
    CHEAT_GOLD_PP7,
    CHEAT_BONDPHASE,
    CHEAT_NO_RADAR_MP,
    CHEAT_TURBO_MODE,
    CHEAT_DEBUG_POS,
    CHEAT_FAST_ANIMATION,
    CHEAT_SLOW_ANIMATION,
    CHEAT_ENEMY_ROCKETS,
    CHEAT_2X_ROCKET_LAUNCHER,
    CHEAT_2X_GRENADE_LAUNCHER,
    CHEAT_2X_RCP90,
    CHEAT_2X_THROWING_KNIFE,
    CHEAT_2X_HUNTING_KNIFE,
    CHEAT_2X_LASER,

    CHEAT_UNLOCK_PAINTBALL,
    CHEAT_UNLOCK_INVINCIBLE,
    CHEAT_UNLOCK_DKMODE,
    CHEAT_UNLOCK_2XGL,
    CHEAT_UNLOCK_2XRL,
    CHEAT_UNLOCK_TURBO,
    CHEAT_UNLOCK_NORADAR,
    CHEAT_UNLOCK_TINY,
    CHEAT_UNLOCK_2XTKNIFE,
    CHEAT_UNLOCK_FAST,
    CHEAT_UNLOCK_INVIS,
    CHEAT_UNLOCK_ENEMYRL,
    CHEAT_UNLOCK_SLOW,
    CHEAT_UNLOCK_SILVERPPK,
    CHEAT_UNLOCK_2XHKNIFE,
    CHEAT_UNLOCK_INFAMMO,
    CHEAT_UNLOCK_2XFNP0,
    CHEAT_UNLOCK_GOLDPPK,
    CHEAT_UNLOCK_2XLASER,
    CHEAT_UNLOCK_ALLGUNS,

    CHEAT_UNLOCK_DAM,
    CHEAT_UNLOCK_FACILITY,
    CHEAT_UNLOCK_RUNWAY,
    CHEAT_UNLOCK_SURFACE,
    CHEAT_UNLOCK_BUNKER,
    CHEAT_UNLOCK_SILO,
    CHEAT_UNLOCK_FRIGATE,
    CHEAT_UNLOCK_SURFACE2,
    CHEAT_UNLOCK_BUNKER2,
    CHEAT_UNLOCK_STATUE,
    CHEAT_UNLOCK_ARCHIVES,
    CHEAT_UNLOCK_STREETS,
    CHEAT_UNLOCK_DEPOT,
    CHEAT_UNLOCK_TRAIN,
    CHEAT_UNLOCK_JUNGLE,
    CHEAT_UNLOCK_CONTROL,
    CHEAT_UNLOCK_CAVERNS,
    CHEAT_UNLOCK_CRADLE,
    CHEAT_UNLOCK_AZTEK,
    CHEAT_UNLOCK_EGYPT,

    CHEAT_INVALID,

    CHEAT_MAX = CHEAT_INVALID+5
} CHEAT_ID;

//Controller stuff including Rumble Pak are in joy.c

typedef enum CONTROLLER_CONFIG
{
    /* 1.1 */
    CONTROLLER_CONFIG_HONEY,

    /* 1.2 */
    CONTROLLER_CONFIG_SOLITARE,

    /* 1.3 */
    CONTROLLER_CONFIG_KISSY,

    /* 1.4 */
    CONTROLLER_CONFIG_GOODNIGHT,

    /* 2.1 */
    CONTROLLER_CONFIG_PLENTY,

    /* 2.2 */
    CONTROLLER_CONFIG_GALORE,

    /* 2.3 */
    CONTROLLER_CONFIG_DOMINO,

    /* 2.4 */
    CONTROLLER_CONFIG_GOODHEAD,

    CONTROLLER_CONFIG_CINEMA
} CONTROLLER_CONFIG;

enum WALLETBOND_SWITCHNAMES
{
    SW_TABS,
    SW_PAPER,
    SW_EYESONLY,
    SW_OHMSS,
    SW_CONFIDENTIAL,
    SW_CONFIDENTIAL2,
    SW_CLASSIFIED,
    SW_PHOTOBOND,
    SW_BROSNAN,
    SW_CONNERY,
    SW_DALTON,
    SW_MOORE,
    SW_PHOTOBRIEF,
    SW_COVER,
    SW_PHOTOCOVER,
    SW_BROSNANCOVER,
    SW_CONNERYCOVER,
    SW_DALTONCOVER,
    SW_MOORECOVER,
    SW_SLIDES,
    SW_PICS,
    GFXHIT0_PICS,
    SW_BRIEF1,
    SW_BRIEF2,
    SW_BRIEF3,
    SW_BRIEF4,
    SW_BRIEF5,
    SW_BRIEF6,
    SW_BRIEF7,
    SW_BRIEF8,
    SW_BRIEF9,
    SW_BRIEF10,
    SW_BRIEF11,
    SW_BRIEF12,
    SW_BRIEF13,
    SW_BRIEF14,
    SW_BRIEF15,
    SW_BRIEF16,
    SW_BRIEF17,
    SW_BRIEF18,
    SW_BRIEF19,
    SW_BRIEF20,
    SW_BLANK
} ;

typedef enum GAMELENGTH
{
    LEN_UNLIMITED,
    LEN_5MIN,
    LEN_10MIN,
    LEN_20MIN,
    LEN_5PT,
    LEN_10PT,
    LEN_20PT,
    LEN_LAST
} GAMELENGTH;

typedef enum CUFF_TYPES
{
    CUFF_BLUE,
    CUFF_BROSNAN,
    CUFF_JUNGLE,
    CUFF_BOILER,
    CUFF_SNOW,
    CUFF_CONNERY,
    CUFF_DALTON,
    CUFF_MOORE,
    CUFF_FOLDER
} CUFF_TYPES;

typedef enum CREDITS_ALIGNMENT
{
    CREDITS_ALIGN_PREVIOUS = -1,
    CREDITS_ALIGN_RIGHT,
    CREDITS_ALIGN_LEFT,
    CREDITS_ALIGN_CENTER
} CREDITS_ALIGNMENT;

typedef enum CROUCH
{
    CROUCH_SQUAT,
    CROUCH_HALF,
    CROUCH_STAND
}CROUCH;

typedef enum DEBUG_OPTIONS
{
    DEB_MOVE_VIEW,
    DEB_STAN_VIEW,
    DEB_BOND_VIEW,
    DEB_LEVEL,
    DEB_REGION,
    DEB_SCALE,
    DEB_PLAYTITLE,
    DEB_BONDDIE,
    DEB_SELANIM,
    DEB_GUNPOS,
    DEB_FLASHCOLOR,
    DEB_HITCOLOR,
    DEB_MUSIC,
    DEB_SFX,
    DEB_INVINCIBLE,
    DEB_VISIBILE,
    DEB_COLLISIONS,
    DEB_ALLGUNS,
    DEB_MAXAMMO,
    DEB_DISPSPEED,
    DEB_BG,
    DEB_PROPS,
    DEB_STANHIT,
    DEB_STANREGION,
    DEB_STANPROBLEMS,
    DEB_PRTMANPOS,
    DEB_PORTCLOSE,
    DEB_PORT_INF,
    DEB_PORT_APPROX,
    DEB_PRROOMLOADS,
    DEB_SHOWMEMUSE,
    DEB_SHOWMEMBARS,
    DEB_GRABRGB,
    DEB_GRABJPG,
    DEB_TASKGRAB,
    DEB_RNDWALK,
    DEB_RECRAMROM,
    DEB_RECORD1,
    DEB_RECORD2,
    DEB_RECORD3,
    DEB_REPLAYRAMROM,
    DEB_SAVERAMROM,
    DEB_LOADRAMROM,
    DEB_AUTOAIMY,
    DEB_AUTOAIMX,
    DEB_007,
    DEB_AGENT,
    DEB_ALL,
    DEB_FAST,
    DEB_OBJECTIVES,
    DEB_MARGTOP,
    DEB_MARGBOT,
    DEB_MARGLEFT,
    DEB_MARGRIGHT,
    DEB_MARGRESET,
    DEB_SCREENSIZE,
    DEB_SCREENPOS,
    DEB_SHOWPATROLS,
    DEB_INTRO,
    DEB_INTRO_EDIT,
    DEB_INTRO_POS,
    DEB_WORLD_POS,
    DEB_GUNKEYPOS,
    DEB_VISCVG,
    DEB_CHRNUM,
    DEB_ROOMBLOCKS,
    DEB_PROFILE,
    DEB_OBJLOAD,
    DEB_WEAPONLOAD,
    DEB_JOY2SKYEDIT,
    DEB_JOY2HITSEDIT,
    DEB_JOY2DETAILEDIT,
    DEB_EXPLOSIONINFO,
    DEB_MAGICFOG,
    DEB_GUNWATCHPOS,
    DEB_TESTINGMANPOS,
    DEB_FOG
} DEBUG_MODES;


typedef enum DIFFICULTY
{
    DIFFICULTY_MULTI = -1,
    DIFFICULTY_AGENT,
    DIFFICULTY_SECRET,
    DIFFICULTY_00,
    DIFFICULTY_007,
    DIFFICULTY_MAX
} DIFFICULTY;

typedef enum ENVIRONMENTDATA_IDS
{
    ENVIRONMENTDATA_PLAYERS_1,
    ENVIRONMENTDATA_ALT       = 100,
    ENVIRONMENTDATA_PLAYERS_2 = 200,
    ENVIRONMENTDATA_PLAYERS_3 = 300,
    ENVIRONMENTDATA_PLAYERS_4 = 400,
    ENVIRONMENTDATA_CINEMA    = 900

} ENVIRONMENTDATA_IDS;

#define ENVIRONMENTDATA_END 0

typedef enum E_EXPLOSIONTYPE
{
    EXPLOSION_BREAK_OBJECT,
    EXPLOSION_BREAK_OBJECT2,
    EXPLOSION_MEDIUM,
    EXPLOSION_MEDIUM2,
    EXPLOSION_LARGE,
    EXPLOSION_LARGE2,
    EXPLOSION_SMALL,
    EXPLOSION_SMALL2,
    EXPLOSION_MEDUIM_SMALLFIRE,
    EXPLOSION_MULTIFIRE,
    EXPLOSION_MEDIUM3,
    EXPLOSION_MEDIUM4,
    EXPLOSION_EXTINGUISHER,
    EXPLOSION_LARGE4,
    EXPLOSION_MUSHROOM,
    EXPLOSION_BITS,
    E_EXPLOSIONTYPE_COUNT
} E_EXPLOSIONTYPE;

/* index into g_ExplosionTypes.
* Is this the same as E_EXPLOSIONTYPE ?
* Some names are based on logic in chrobjWeaponTick method.
*/
typedef enum EXPLOSION_DEF
{
    EXPLOSION_DEF_00,
    EXPLOSION_DEF_01,
    EXPLOSION_DEF_02,
    EXPLOSION_DEF_03,
    EXPLOSION_DEF_04,
    EXPLOSION_DEF_05,
    EXPLOSION_DEF_06,
    EXPLOSION_DEF_07,
    EXPLOSION_DEF_08,
    EXPLOSION_DEF_09,
    EXPLOSION_DEF_10,
    EXPLOSION_DEF_11,
    EXPLOSION_DEF_DRONE,
    // used with grenades and mines
    EXPLOSION_DEF_STANDARD,
    EXPLOSION_DEF_14,
    EXPLOSION_DEF_15,
    EXPLOSION_DEF_16,
    EXPLOSION_DEF_MASSIVE,
    EXPLOSION_DEF_PLAYER,
    EXPLOSION_DEF_FACILITY_REMOTE,
    EXPLOSION_DEF_20,
    EXPLOSION_DEF_21
} EXPLOSION_DEF;

typedef enum GAMEMODE
{
    GAMEMODE_INTRO = -1,
    GAMEMODE_SOLO,
    GAMEMODE_MULTI,
    GAMEMODE_CHEATS
} GAMEMODE;

typedef enum GUNHAND //Canonical name
{
    GUNRIGHT,
    GUNLEFT,
    GUNHANDS
} GUNHAND;


/*Hit Type for triangle (Canonical name)*/
typedef enum HIT_TYPE
{
    HIT_DEFAULT,
    HIT_STONE,
    HIT_WOOD,
    HIT_METAL,
    HIT_GLASS,
    HIT_WATER,
    HIT_SNOW,
    HIT_DIRT,
    HIT_MUD,
    HIT_TILE,
    HIT_METALOBJ,
    HIT_CHR,
    HIT_GLASS_XLU,
    HIT_TYPE_COUNT
}HIT_TYPE;
#ifdef DEBUG
    char *HIT_TYPE_ToString[] = {
         "HIT_DEFAULT",
        "HIT_STONE",
        "HIT_WOOD",
        "HIT_METAL",
        "HIT_GLASS",
        "HIT_WATER",
        "HIT_SNOW",
        "HIT_DIRT",
        "HIT_MUD",
        "HIT_TILE",
        "HIT_METALOBJ",
        "HIT_CHR",
        "HIT_GLASS_XLU"};
#endif

#define IMAGE(NAME, SZ, HS, HT, F3, F4, F5, F6) IMAGE_ ## NAME,
typedef enum IMAGEIDS
{
#include <assets/images.def>
    IMAGEIDS_COUNT
} IMAGEIDS;
#undef IMAGE

#define IMAGE(NAME, SZ, HS, HT, F3, F4, F5, F6) IMAGE_ ## NAME ## _SIZE = SZ,
typedef enum IMGAGESIZES
{
#include <assets/images.def>
    IMGAGESIZES_COUNT
} IMGAGESIZES;
#undef IMAGE


typedef enum LEVELID
{ // skyID since only used by Sky and does not reflect levelID, rather in past
  // SkyID has been confused with Sky[Index].
    LEVELID_NONE    = -1,
    LEVELID_DEFAULT,

    LEVELID_BUNKER1 = 9,

    LEVELID_SILO    = 20,

    LEVELID_STATUE  = 22,
    LEVELID_CONTROL,
    LEVELID_ARCHIVES,
    LEVELID_TRAIN,
    LEVELID_FRIGATE,
    LEVELID_BUNKER2,
    LEVELID_AZTEC,
    LEVELID_STREETS,
    LEVELID_DEPOT,
    LEVELID_COMPLEX,
    LEVELID_EGYPT,
    LEVELID_DAM,
    LEVELID_FACILITY,
    LEVELID_RUNWAY,
    LEVELID_SURFACE,
    LEVELID_JUNGLE,
    LEVELID_TEMPLE,
    LEVELID_CAVERNS,
    LEVELID_CITADEL,
    LEVELID_CRADLE,
    LEVELID_SHO,
    LEVELID_SURFACE2,
    LEVELID_ELD,
    LEVELID_BASEMENT,
    LEVELID_STACK,
    LEVELID_LUE,
    LEVELID_LIBRARY,
    LEVELID_RIT,
    LEVELID_CAVES,
    LEVELID_EAR,
    LEVELID_LEE,
    LEVELID_LIP,
    LEVELID_CUBA,
    LEVELID_WAX,
    LEVELID_PAM,
    LEVELID_MAX,
    LEVELID_TITLE = 90,
    LEVELID_BUNKER2_MP  = LEVELID_BUNKER2 + ENVIRONMENTDATA_PLAYERS_4,
    LEVELID_ARCHIVES_MP = LEVELID_ARCHIVES + ENVIRONMENTDATA_PLAYERS_4,
    LEVELID_CAVERNS_MP  = LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_4,
    LEVELID_FACILITY_MP = LEVELID_FACILITY + ENVIRONMENTDATA_PLAYERS_4,
    LEVELID_EGYPT_MP    = LEVELID_EGYPT + ENVIRONMENTDATA_PLAYERS_4
} LEVELID;

typedef enum LEVEL_SOLO_SEQUENCE
{
    SP_LEVEL_DAM,
    SP_LEVEL_FACILITY,
    SP_LEVEL_RUNWAY,
    SP_LEVEL_SURFACE1,
    SP_LEVEL_BUNKER1,
    SP_LEVEL_SILO,     // 5
    SP_LEVEL_FRIGATE,
    SP_LEVEL_SURFACE2,
    SP_LEVEL_BUNKER2,
    SP_LEVEL_STATUE,
    SP_LEVEL_ARCHIVES, // 10
    SP_LEVEL_STREETS,
    SP_LEVEL_DEPOT,
    SP_LEVEL_TRAIN,
    SP_LEVEL_JUNGLE,
    SP_LEVEL_CONTROL,  // 15
    SP_LEVEL_CAVERNS,
    SP_LEVEL_CRADLE,
    SP_LEVEL_AZTEC,
    SP_LEVEL_EGYPT,    // 19
    SP_LEVEL_MAX       // 20
} LEVEL_SOLO_SEQUENCE;

typedef enum LEVEL_INDEX
{
    LEVEL_INDEX_SEVBUNKER,
    LEVEL_INDEX_SILO,
    LEVEL_INDEX_STATUE,
    LEVEL_INDEX_CONTROL,
    LEVEL_INDEX_ARCH,
    LEVEL_INDEX_TRA,
    LEVEL_INDEX_DEST,
    LEVEL_INDEX_SEVB,
    LEVEL_INDEX_AZT,
    LEVEL_INDEX_PETE,
    LEVEL_INDEX_DEPO,
    LEVEL_INDEX_REF,
    LEVEL_INDEX_CRYP,
    LEVEL_INDEX_DAM,
    LEVEL_INDEX_ARK,
    LEVEL_INDEX_RUN,
    LEVEL_INDEX_SEVX,
    LEVEL_INDEX_JUN,
    LEVEL_INDEX_DISH,
    LEVEL_INDEX_CAVE,
    LEVEL_INDEX_CAT,
    LEVEL_INDEX_CRAD,
    LEVEL_INDEX_SHO,
    LEVEL_INDEX_SEVXB,
    LEVEL_INDEX_ELD,
    LEVEL_INDEX_IMP,
    LEVEL_INDEX_ASH,
    LEVEL_INDEX_LUE,
    LEVEL_INDEX_AME,
    LEVEL_INDEX_RIT,
    LEVEL_INDEX_OAT,
    LEVEL_INDEX_EAR,
    LEVEL_INDEX_LEE,
    LEVEL_INDEX_LIP,
    LEVEL_INDEX_LEN,
    LEVEL_INDEX_WAX,
    LEVEL_INDEX_PAM,
    LEVEL_INDEX_X,
    LEVEL_INDEX_MAX = LEVEL_INDEX_X
} LEVEL_INDEX;

typedef enum TEXT_ALIGNMENT
{
    LEFT_ALIGN,
    CENTER_ALIGN,
    RIGHT_ALIGN,
    TOP_ALIGN = LEFT_ALIGN,
    BOTTOM_ALIGN = RIGHT_ALIGN
} TEXT_ALIGNMENT;



typedef enum MENU
{
    MENU_INVALID = -1,
    MENU_LEGAL_SCREEN,
    MENU_NINTENDO_LOGO,
    MENU_RAREWARE_LOGO,
    MENU_EYE_INTRO,
    MENU_GOLDENEYE_LOGO,
    MENU_FILE_SELECT,
    MENU_MODE_SELECT,
    MENU_MISSION_SELECT,
    MENU_DIFFICULTY,
    MENU_007_OPTIONS,
    MENU_BRIEFING,
    MENU_RUN_STAGE,
    MENU_MISSION_FAILED,
    MENU_MISSION_COMPLETE,
    MENU_MP_OPTIONS,
    MENU_MP_CHAR_SELECT,
    MENU_MP_HANDICAP,
    MENU_MP_CONTROL_STYLE,
    MENU_MP_STAGE_SELECT,
    MENU_MP_SCENARIO_SELECT,
    MENU_MP_TEAMS,
    MENU_CHEAT,
    MENU_NO_CONTROLLERS,
    MENU_SWITCH_SCREENS,
    MENU_DISPLAY_CAST,
    MENU_SPECTRUM_EMU,
    MENU_MAX
} MENU;

typedef enum mission_setup_type
{
    MISSION_PART,
    MISSION_HEADER
} mission_setup_type;

typedef enum MISSION_BRIEFING
{
    BRIEF_OVERVIEW,
    BRIEF_M,
    BRIEF_Q,
    BRIEF_MONEYPENNY
} MISSION_BRIEFING;

typedef enum MODELNODE_OPCODE
{
    MODELNODE_OPCODE_NULL,
    MODELNODE_OPCODE_HEADER,
    MODELNODE_OPCODE_GROUP,
    MODELNODE_OPCODE_OP03,
    MODELNODE_OPCODE_DL,
    MODELNODE_OPCODE_OP05,
    MODELNODE_OPCODE_OP06,
    MODELNODE_OPCODE_OP07,
    MODELNODE_OPCODE_LOD,
    MODELNODE_OPCODE_BSP,
    MODELNODE_OPCODE_BBOX,
    MODELNODE_OPCODE_OP11,
    MODELNODE_OPCODE_GUNFIRE,
    MODELNODE_OPCODE_SHADOW,
    MODELNODE_OPCODE_OP14,
    MODELNODE_OPCODE_INTERLINK,
    MODELNODE_OPCODE_OP16,
    MODELNODE_OPCODE_OP17,
    MODELNODE_OPCODE_SWITCH,
    MODELNODE_OPCODE_OP19,
    MODELNODE_OPCODE_OP20,
    MODELNODE_OPCODE_GROUPSIMPLE,
    MODELNODE_OPCODE_DLPRIMARY,
    MODELNODE_OPCODE_HEAD,
    MODELNODE_OPCODE_DLCOLLISION,
    MODELNODE_OPCODE_MAX
} MODELNODE_OPCODE;

typedef enum MODELNODE_CHILD
{
    MODELNODE_CHILD_NULL,
    MODELNODE_CHILD_VTX,
    MODELNODE_CHILD_IMAGE,
    MODELNODE_CHILD_TRI,
    MODELNODE_CHILD_MAX
} MODELNODE_CHILD;

typedef enum BOND
{
    BOND_BROSNAN,
    BOND_CONNERY,
    BOND_DALTON,
    BOND_MOORE
} BOND;

typedef enum MP_STAGE_SELECTED
{
    MP_STAGE_RANDOM,
    MP_STAGE_TEMPLE,
    MP_STAGE_COMPLEX,
    MP_STAGE_CAVES,
    MP_STAGE_LIBRARY,
    MP_STAGE_BASEMENT,
    MP_STAGE_STACK,
    MP_STAGE_FACILITY,
    MP_STAGE_BUNKER,
    MP_STAGE_ARCHIVES,
    MP_STAGE_CAVERNS,
    MP_STAGE_EGYPT,
    MP_STAGE_SELECTED_MAX
} MP_STAGE_SELECTED;

typedef enum MPMENU
{
    MENU_GOWOC,
    MENU_LOSSES,
    MENU_KILLS,
    MENU_SCORES,
    MENU_PAUSE,
    MENU_EXIT,
    MENU_6,
    MENU_7
} MPMENU;

typedef enum MPSCENARIOS
{
    SCENARIO_NORMAL,
    SCENARIO_YOLT,     // you only live twice
    SCENARIO_TLD,      // The Living Daylights [Flag Tag]
    SCENARIO_MWTGG,    // The Man With the Golden Gun
    SCENARIO_LTK,      // License to Kill
    SCENARIO_2v2,
    SCENARIO_3v1,
    SCENARIO_2v1,
    MPSCENARIOS_MAX
} MPSCENARIOS;

typedef enum MUSIC_TRACKS
{
    M_NONE,
    M_SHORT_SOLO_DEATH,
    M_INTRO,
    M_TRAIN,
    M_DEPOT,
    M_MPTHEME,
    M_CITADEL,
    M_FACILITY,
    M_CONTROL,
    M_DAM,
    M_FRIGATE,
    M_ARCHIVES,
    M_SILO,
    M_MPTHEME2,
    M_STREETS,
    M_BUNKER1,
    M_BUNKER2,
    M_STATUE,
    M_ELEVATOR_CONTROL,
    M_CRADLE,
    M_UNK,
    M_ELEVATOR_WC,
    M_EGYPTIAN,
    M_FOLDERS,
    M_WATCH,
    M_AZTEC,
    M_WATERCAVERNS,
    M_DEATHSOLO,
    M_SURFACE2,
    M_TRAINX,
    M_UNK2,
    M_FACILITYX,
    M_DEPOTX,
    M_CONTROLX,
    M_WATERCAVERNSX,
    M_DAMX,
    M_FRIGATEX,
    M_ARCHIVESX,
    M_SILOX,
    M_EGYPTIANX,
    M_STREETSX,
    M_BUNKER1X,
    M_BUNKER2X,
    M_JUNGLEX,
    M_INTROSWOOSH,
    M_STATUEX,
    M_AZTECX,
    M_EGYPTX,
    M_CRADLEX,
    M_CUBA,
    M_RUNWAY,
    M_RUNWAYPLANE,
    M_MPTHEME3,
    M_WIND,
    M_GUITARGLISS,
    M_JUNGLE,
    M_RUNWAYX,
    M_SURFACE1,
    M_MPDEATH,
    M_SURFACE2X,
    M_SURFACE2END,
    M_STATUEPART,
    M_END_SOMETHING
} MUSIC_TRACKS;

#if 0
//these dont match the listing at all, however they imply a listing was used
    char *MUSIC_TRACK_ToString[] = {
        "01Goldeneye 64 - James Bond Theme",
        "02Goldeneye 64 - Train",
        "03Goldeneye 64 - Depot",
        "04Goldeneye 64 - Citadel",
        "05Goldeneye 64 - _Unsquare Water Dance_",
        "06Goldeneye 64 - Facility",
        "07Goldeneye 64 - Control",
        "08Goldeneye 64 - Dam",
        "09Goldeneye 64 - Frigate",
        "10Goldeneye 64 - Archives",
        "11Goldeneye 64 - Silo",
        "12Goldeneye 64 - Surface 2 X",
        "13Goldeneye 64 - Streets",
        "14Goldeneye 64 - Bunker 1",
        "15Goldeneye 64 - Bunker 2",
        "16Goldeneye 64 - Statue",
        "17Goldeneye 64 - Elevator (control)",
        "18Goldeneye 64 - Cradle",
        "19Goldeneye 64 - Elevator (caverns)",
        "20Goldeneye 64 - Egypt",
        "56Goldeneye 64 - Mission Select",
        "21Goldeneye 64 - 007 Watch Theme",
        "22Goldeneye 64 - Aztec",
        "23Goldeneye 64 - Caverns",
        "24Goldeneye 64 - Mission Death",
        "25Goldeneye 64 - Surface 2",
        "26Goldeneye 64 - Train X",
        "27Goldeneye 64 - Facility X",
        "28Goldeneye 64 - Depot X",
        "29Goldeneye 64 - Control X",
        "30Goldeneye 64 - Caverns X",
        "31Goldeneye 64 - Dam X",
        "32Goldeneye 64 - Frigate X",
        "33Goldeneye 64 - Archives X",
        "34Goldeneye 64 - Silo X",
        "35Goldeneye 64 - Streets X",
        "36Goldeneye 64 - Bunker 1 X",
        "37Goldeneye 64 - Bunker 2 X",
        "38Goldeneye 64 - Jungle X",
        "39Goldeneye 64 - Nintendo and Rareware",
        "40Goldeneye 64 - Statue X",
        "41Goldeneye 64 - Aztec X",
        "42Goldeneye 64 - Egypt X",
        "43Goldeneye 64 - Cradle X",
        "44Goldeneye 64 - Ending Theme",
        "45Goldeneye 64 - Runway",
        "46Goldeneye 64 - Runway Plane",
        "47Goldeneye 64 - The Basement",
        "48Goldeneye 64 - Bungeee!",
        "49Goldeneye 64 - Jungle",
        "50Goldeneye 64 - Runway X",
        "51Goldeneye 64 - Surface 1",
        "52Goldeneye 64 - Multiplayer Death",
        "53Goldeneye 64 - Captured! (surface)",
        "54Goldeneye 64 - Captured! (statue)",
        "55Goldeneye 64 - Frigate (beta)" };
#endif

typedef enum OPTIONS
{
    PLAYER_OPTION_LOOK,
    PLAYER_OPTION_AUTOAIM,
    PLAYER_OPTION_AIM,
    PLAYER_OPTION_SIGHT,
    PLAYER_OPTION_LOOKAHEAD,
    PLAYER_OPTION_AMMODISPLAY,
    PLAYER_OPTION_SCREEN,
    PLAYER_OPTION_RATIO
} OPTIONS;

typedef enum PLAYER_ID
{
    PLAYER_1,
    PLAYER_2,
    PLAYER_3,
    PLAYER_4
} PLAYER_ID;

#define SAVESLOT1 0x0
#define SAVESLOT2 0x1
#define SAVESLOT3 0x2
#define SAVESLOT4 0x3
#define SAVESLOTRAMROM 0x5
#define SAVESLOTMAX 0x6

#define SAVEFLAG_FOLDER 0x7
#define SAVEFLAG_SLOT 0x18
#define SAVEFLAG_BOND 0x60
#define SAVEFLAG_DORESET 0x80

#define SAVEFLAGS_SET(folder, slot, bond, reset) (((folder << 5) & 0xE0) | ((slot * 8) & 0x18) | ((bond << 1) & 0x6) | (reset & 1 ? SAVEFLAG_DORESET : 0))

#define BLANKSAVEDATA {0, 0, SAVEFLAGS_SET(0,0,BOND_BROSNAN,1), 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS, 0x00, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define MAX_PLAYER_COUNT 4

#define FOLDER_INVALID -1
#define FOLDER1 0x0
#define FOLDER2 0x1
#define FOLDER3 0x2
#define FOLDER4 0x3
#define MAX_FOLDER_COUNT 4
#define RAMROM_FOLDERNUM 0x64

typedef enum RGBA_ENUM
{
    RED,
    GREEN,
    BLUE,
    ALPHA
} RGBA_ENUM;


typedef enum SFX_ID
{
    NOTHING_SFX,
    ROCKET_LAUNCH_SFX,
    GLASS_SHATTERING_SFX,
    KNIFE_HIT_WALL_SFX,
    GRENADE_THROW_SFX,          //Grenade/Mine or in fact Any object thrown.
    GRENADE_THROW_QUIET_SFX,
    GRENADE_THROW_FAINT_SFX,
    TRAIN_SLIDE_DOOR_SLIDE_SFX, //Ding used on elevator
    TRAIN_RAILS_SFX,
    TRAIN_RAILS2_SFX,
    WATCH_INTERFERENCE_SFX,
    GUN_TANK2BIG_1_SFX,         //Used for Tank rounds
    GUN_TANK2BIGBIG_1_SFX,      //used for Grenade Launcher
    GET_HIT_GIRL1_SFX,
    GET_HIT_GIRL2_SFX,
    GET_HIT_GIRL3_SFX,
    BEEP_SFX,
    BEEP_QUIET_SFX,
    OPTION_CLICK2_SFX,
    RICO_12_GBU_A_SFX,
    RICO_12_GBU_B_SFX,
    RICO_12_GBU_C_SFX,
    RICO_12_GBU_D_SFX,
    RICO_6_TAJ_A_SFX,
    RICO_6_TAJ_B_SFX,
    RICO_6_TAJ_C_SFX,
    RICO_6_TAJ_D_SFX,
    RICO_8_AFDM_A_SFX,
    RICO_8_AFDM_B_SFX,
    RICO_8_AFDM_C_SFX,
    RICO_8_AFDM_D_SFX,
    RICO_4_A_SFX,
    RICO_4_B_SFX,
    RICO_4_C_SFX,
    RICO_4_D_SFX,
    RICO_5_A_SFX,
    RICO_5_B_SFX,
    RICO_5_C_SFX,
    RICO_5_D_SFX,
    RICO_6_HBBA_A_SFX,
    RICO_6_HBBA_B_SFX,
    RICO_6_HBBA_C_SFX,
    RICO_6_HBBA_D_SFX,
    OPTION_CHOOSE_SFX,
    UNKNOWN1_SFX,
    DROP_GUN_SFX,
    GUN_SILPPK_A_SFX,
    PUNCH1_SFX,
    PUNCH2_SFX,
    PUNCH3_SFX,
    GUN_RIFLECOCK_SFX,
    TRAIN_CLUTTER3_SFX,
    TRAIN_CLUTTER3B_SFX,
    TRAIN_CLUTTER3C_SFX,
    EVIL_LAUGH_SFX,
    EVIL_LAUGH_QUIET_SFX,
    EVIL_LAUGH_FAINT_SFX,
    EVIL_LAUGH_HUSH_SFX,
    HELI_RUN_SFX,
    HELI_FLY_SFX,
    ENGINE_ROOM_SFX,
    TRAIN_STOP_STILL_SFX,
    TANK_SFX,
    TRAIN_STOP_SFX,
    TRAIN_GO_SFX,
    TRUCK_RUN_SFX,
    TRUCK_START_SFX,
    TRUCK_ENGINE_SFX,
    BOND_GET_HIT1_SFX,
    HIT_BULLET_FLESH_SFX,
    HIT_BULLET_GLASS_SFX,
    HIT_GLASS_SMASH_SFX,
    HIT_BULLET_METAL_A_SFX,
    HIT_BULLET_METAL_B_SFX,
    HIT_BULLET_SNOW_SFX,        //Also used for knife hit
    HIT_BULLET_WOOD_SFX,
    HIT_BULLET_WATER_SFX,
    PAPER_TURN_SFX,
    PAPER_TURN_2_SFX,
    COPY_FILE_SFX,
    RADIO_MESSAGE_SFX,
    ARMOUR_COLLECT_SFX,
    OBJ_REGEN_SFX,
    DOOR_DECODER_SFX,
    GIRL_GET_HIT1_SFX,
    CONSOLE_OFF_SFX,
    CONSOLE_OFF2_SFX,
    CONSOLE_ON2_SFX,
    CONSOLE_ON3_SFX,
    EMPTY_GUN_FIRE_SFX,
    SHELL_CASE_SFX,
    RICO_LASER1_SFX,
    RICO_LASER2_SFX,
    RICO_LASER3_SFX,
    RADIO_SFX,
    KNIFE_THROW1_SFX,
    KNIFE_THROW2_SFX,
    KNIFE_THROW3_SFX,
    COUGH_SFX,
    COUGH2_SFX,
    GUN_TASER_SFX,
    GUN_TASER_LOOP_SFX,
    GAS_HISS_SFX,
    UNKNOWN2_SFX,
    UNKNOWN3_SFX,
    PUNCHING_AIR_SFX,
    GUN_B1_MGUN3_3_SFX,         //Used for Skorpion (Klobb)
    GUN_B2_HEAVY_SFX,           //Used for PPK
    GUN_UNKNOWN_SFX,
    GUN_B4_BOLTACTION_SFX,      //used for AK47
    GUN_B5_WINC44_SFX,
    GUN_RIFLE7BIG_1_SFX,        //used for Rugar
    GUN_B8_ANOTHER_SFX,         //used for TT33
    GUN_B9_CANNON_SFX,          //used for M16
    GUN_GRENADE_LAUNCHER_SFX,
    GUN_UNKNOWN2_SFX,
    GUN_B12_FULLAMRIFLE_SFX,    //used for Auto Shotgun
    GUN_B13_M60AMMGUN_SFX,      //used for Golden Gun
    GUN_M60AMMGUN_3_SFX,
    GUN_UNKNOWN3_SFX,
    HIT_METAL_OBJECT1_SFX,
    GUN_B17_RIFLE_SFX,          //used for Shotgun
    CART_SPENT_SFX,
    BODY_FALL_C1_SFX,
    BODY_FALL_C2_SFX,
    BODY_FALL_C3_SFX,
    BODY_FALL_D1_SFX,
    BODY_FALL_D2_SFX,
    BODY_FALL_D3_SFX,
    BODY_FALL_D4_SFX,
    BODY_FALL_E1_SFX,
    BODY_FALL_E2_SFX,
    BODY_FALL_E3_SFX,
    BODY_ROLLOVER_SFX,
    GET_HIT_MALE0_SFX,
    GET_HIT_MALE1_SFX,
    GET_HIT_MALE2_SFX,
    GET_HIT_MALE3_SFX,
    GET_HIT_MALE4_SFX,
    GET_HIT_MALE5_SFX,
    GET_HIT_MALE6_SFX,
    GET_HIT_MALE7_SFX,
    GET_HIT_MALE8_SFX,
    GET_HIT_MALE9_SFX,
    GET_HIT_MALE10_SFX,
    GET_HIT_MALE11_SFX,
    GET_HIT_MALE12_SFX,
    GET_HIT_MALE13_SFX,
    GET_HIT_MALE14_SFX,
    GET_HIT_MALE15_SFX,
    GET_HIT_MALE16_SFX,
    GET_HIT_MALE17_SFX,
    GET_HIT_MALE18_SFX,
    GET_HIT_MALE19_SFX,
    GET_HIT_MALE20_SFX,
    GET_HIT_MALE21_SFX,
    GET_HIT_MALE22_SFX,
    GET_HIT_MALE23_SFX,
    GET_HIT_MALE24_SFX,
    CAMERA_BEEP1_SFX,           //Used for Watch Beeping
    BING_SFX,
    ALARM1_SFX,
    ALARM2_SFX,
    ALARM3_SFX,
    RICO_EAR_WHISTLE1_SFX,
    RICO_EAR_WHISTLE2_SFX,
    RICO_EAR_WHISTLE3_SFX,
    RICO_EAR_WHISTLE4_SFX,
    RICO_EAR_WHISTLE5_SFX,
    EXPLOSION_2A_SFX,
    EXPLOSION_2B_SFX,
    EXPLOSION_3_SFX,
    EXPLOSION_4A_SFX,
    EXPLOSION_4B_SFX,
    EXPLOSION_5A_SFX,
    EXPLOSION_5B_SFX,
    EXPLOSION_5C_SFX,
    EXPLOSION_6_SFX,
    EXPLOSION_7_SFX,
    EXPLOSION_8_SFX,
    EXPLOSION_9_SFX,
    EXPLOSION_1B_SFX,
    EXPLOSION_1C_SFX,
    CRUSHED_YELL_SFX,
    KEY_SEQUENCE_SFX,
    HIT_BULLET_DIRT2_SFX,
    ALARM_SWITCH_SFX,
    DOOR_WOOD_CLOSE_SFX,
    DOOR_WOOD_OPEN_SFX,
    ATOMIC_BOMB_SFX,
    KEY_ANALYSER2_SFX,
    DOOR_WOOD_SLIDE_SFX,
    TRAIN_SLIDE_DOOR_CATCH_SFX,
    GAS_LEAK_SFX,
    DOOR_SHUTTER_OPEN_SFX,
    DOOR_SHUTTER_CLOSE_SFX,
    DOOR_METAL_OPEN_SFX,
    DOOR_METAL_CLOSE_SFX,
    CONSOLE_ON_SFX,
    DOOR_METAL_CLOSE2_SFX,
    DOOR_METAL_OPEN3_SFX,
    DOOR_METAL_CLOSE3_SFX,
    METAL_SLIDE_OPEN_SFX,
    METAL_SLIDE_CLOSE_SFX,
    METAL_SLIDE_LOOP_SFX,
    UNKNOWN4_SFX,
    UNKNOWN5_SFX,
    UNKNOWN6_SFX,
    HIT_BULLET_STONE1_SFX,
    HIT_BULLET_STONE2_SFX,
    DOOR_SMART_CATCH1_SFX,
    DOOR_SMART_SLIDE1_SFX,
    HIT_BULLET_TILE_SFX,
    TANK_CRUSH_MAN_SFX,
    HEAVY_SLIDE_OPEN_SFX,
    HEAVY_SLIDE_CLOSE_SFX,
    HEAVY_SINGLE_LOOP_SFX,
    HIT_BULLET_WOOD2_SFX,
    DOOR_HYDRAL_CLOSE_SFX,      // Main Hydrolic Door loop
    DOOR_HYDRAL_OPEN_SFX,       // Hudrolic Door Stop sound
    HIT_BULLET_DIRT1_SFX,
    HIT_METAL_OBJECT2_SFX,
    DOOR_LOCK_SFX,              //Also used for button Presses
    TRAIN_CLUTTER2_SFX,
    HIT_BULLET_MUD3_SFX,
    DOOR_SLIDE_STONE_OPEN_SFX,  //Main Stone Door Loop
    DOOR_SLIDE_STONE_CLOSE_SFX, //Stone Door Stop
    DATA_DOWNLOAD_SFX,
    LASER_GUN_SFX,
    KEYCARD_SFX,
    HIT_BULLET_MUD2_SFX,
    HIT_BULLET_MUD1_SFX,
    PICKUP_GUN_SFX,
    PICKUP_KNIFE_SFX,
    PICKUP_AMMO_SFX,
    PICKUP_MINE_SFX,
    WATCH_STATIC_SFX,
    WATCH_ON_SFX,
    WATCH_OFF_SFX,
    HIT_BULLET_METAL_A3_SFX,
    HIT_BULLET_METAL_A4_SFX,
    ATTACH_MINE_SFX,
    PICKUP_LASER_SFX,
    WATCH_DETONATE_MINE_SFX,    //Watch Trigger
    CAMERA_CLICK_SFX,           //Camera Shutter
    KEY_ANALYSER_SFX,
    MAGNETIC_HUM_SFX,
    BOMB_DEFUSE_SFX,
    BI_PLANE_SFX,
    TRAIN_CLUTTER_SFX,
    TRAIN_CLUTTERB_SFX,
    TRAIN_CLUTTERC_SFX,
    TRAIN_CLUTTERD_SFX,
    GUN_B9_CANNON_SHORT_SFX,
    UNKNOWN_QUIET_SFX,
    CAMERA_ZOOM_LOOP_SFX,
    CAMERA_ZOOM_STOP_SFX,
    SNEEZE_SFX,
    RARELOGO_SFX,
    RARELOGO_QUIET_SFX,
    RARELOGO_FAINT_SFX,
    BIG_CLANK_SFX
} SFX_ID;

#ifdef DEBUG
    char *SFX_ID_ToString[] = {
    "0_NOTHING_SFX",
    "1_ROCKET_LAUNCH_SFX",
    "2_GLASS_SHATTERING_SFX",
    "3_KNIFE_HIT_WALL_SFX",
    "4_GRENADE_THROW_SFX",            //Grenade/Mine or in fact Any object thrown.
    "5_GRENADE_THROW_QUIET_SFX",
    "6_GRENADE_THROW_FAINT_SFX",
    "7_TRAIN_SLIDE_DOOR_SLIDE_SFX",   //Ding used on elevator
    "8_TRAIN_RAILS_SFX",
    "9_TRAIN_RAILS2_SFX",
    "10_WATCH_INTERFERENCE_SFX",
    "11_GUN_TANK2BIG_1_SFX",          //Used for Tank rounds
    "12_GUN_TANK2BIGBIG_1_SFX",       //used for Grenade Launcher
    "13_GET_HIT_GIRL1_SFX",
    "14_GET_HIT_GIRL2_SFX",
    "15_GET_HIT_GIRL3_SFX",
    "16_BEEP_SFX",
    "17_BEEP_QUIET_SFX",
    "18_OPTION_CLICK2_SFX",
    "19_RICO_12_GBU_A_SFX",
    "20_RICO_12_GBU_B_SFX",
    "21_RICO_12_GBU_C_SFX",
    "22_RICO_12_GBU_D_SFX",
    "23_RICO_6_TAJ_A_SFX",
    "24_RICO_6_TAJ_B_SFX",
    "25_RICO_6_TAJ_C_SFX",
    "26_RICO_6_TAJ_D_SFX",
    "27_RICO_8_AFDM_A_SFX",
    "28_RICO_8_AFDM_B_SFX",
    "29_RICO_8_AFDM_C_SFX",
    "30_RICO_8_AFDM_D_SFX",
    "31_RICO_4_A_SFX",
    "32_RICO_4_B_SFX",
    "33_RICO_4_C_SFX",
    "34_RICO_4_D_SFX",
    "35_RICO_5_A_SFX",
    "36_RICO_5_B_SFX",
    "37_RICO_5_C_SFX",
    "38_RICO_5_D_SFX",
    "39_RICO_6_HBBA_A_SFX",
    "40_RICO_6_HBBA_B_SFX",
    "41_RICO_6_HBBA_C_SFX",
    "42_RICO_6_HBBA_D_SFX",
    "43_OPTION_CHOOSE_SFX",
    "44_UNKNOWN1_SFX",
    "45_DROP_GUN_SFX",
    "46_GUN_SILPPK_A_SFX",
    "47_PUNCH1_SFX",
    "48_PUNCH2_SFX",
    "49_PUNCH3_SFX",
    "50_GUN_RIFLECOCK_SFX",
    "51_TRAIN_CLUTTER3_SFX",
    "52_TRAIN_CLUTTER3B_SFX",
    "53_TRAIN_CLUTTER3C_SFX",
    "54_EVIL_LAUGH_SFX",
    "55_EVIL_LAUGH_QUIET_SFX",
    "56_EVIL_LAUGH_FAINT_SFX",
    "57_EVIL_LAUGH_HUSH_SFX",
    "58_HELI_RUN_SFX",
    "59_HELI_FLY_SFX",
    "60_ENGINE_ROOM_SFX",
    "61_TRAIN_STOP_STILL_SFX",
    "62_TANK_SFX",
    "63_TRAIN_STOP_SFX",
    "64_TRAIN_GO_SFX",
    "65_TRUCK_RUN_SFX",
    "66_TRUCK_START_SFX",
    "67_TRUCK_ENGINE_SFX",
    "68_BOND_GET_HIT1_SFX",
    "69_HIT_BULLET_FLESH_SFX",
    "70_HIT_BULLET_GLASS_SFX",
    "71_HIT_GLASS_SMASH_SFX",
    "72_HIT_BULLET_METAL_A_SFX",
    "73_HIT_BULLET_METAL_B_SFX",
    "74_HIT_BULLET_SNOW_SFX",         //Also used for knife hit
    "75_HIT_BULLET_WOOD_SFX",
    "76_HIT_BULLET_WATER_SFX",
    "77_PAPER_TURN_SFX",
    "78_PAPER_TURN_2_SFX",
    "79_COPY_FILE_SFX",
    "80_RADIO_MESSAGE_SFX",
    "81_ARMOUR_COLLECT_SFX",
    "82_OBJ_REGEN_SFX",
    "83_DOOR_DECODER_SFX",
    "84_GIRL_GET_HIT1_SFX",
    "85_CONSOLE_OFF_SFX",
    "86_CONSOLE_OFF2_SFX",
    "87_CONSOLE_ON2_SFX",
    "88_CONSOLE_ON3_SFX",
    "89_EMPTY_GUN_FIRE_SFX",
    "90_SHELL_CASE_SFX",
    "91_RICO_LASER1_SFX",
    "92_RICO_LASER2_SFX",
    "93_RICO_LASER3_SFX",
    "94_RADIO_SFX",
    "95_KNIFE_THROW1_SFX",
    "96_KNIFE_THROW2_SFX",
    "97_KNIFE_THROW3_SFX",
    "98_COUGH_SFX",
    "99_COUGH2_SFX",
    "100_GUN_TASER_SFX",
    "101_GUN_TASER_LOOP_SFX",
    "102_GAS_HISS_SFX",
    "103_UNKNOWN2_SFX",
    "104_UNKNOWN3_SFX",
    "105_PUNCHING_AIR_SFX",
    "106_GUN_B1_MGUN3_3_SFX",         //Used for Spyder (Klobb)
    "107_GUN_B2_HEAVY_SFX",           //Used for PPK
    "108_GUN_UNKNOWN_SFX",
    "109_GUN_B4_BOLTACTION_SFX",      //used for AK47
    "110_GUN_B5_WINC44_SFX",
    "111_GUN_RIFLE7BIG_1_SFX",        //used for Rugar
    "112_GUN_B8_ANOTHER_SFX",         //used for TT33
    "113_GUN_B9_CANNON_SFX",          //used for M16
    "114_GUN_GRENADE_LAUNCHER_SFX",
    "115_GUN_UNKNOWN2_SFX",
    "116_GUN_B12_FULLAMRIFLE_SFX",    //used for Auto Shotgun
    "117_GUN_B13_M60AMMGUN_SFX",      //used for Golden Gun
    "118_GUN_M60AMMGUN_3_SFX",
    "119_GUN_UNKNOWN3_SFX",
    "120_HIT_METAL_OBJECT1_SFX",
    "121_GUN_B17_RIFLE_SFX",          //used for Shotgun
    "122_CART_SPENT_SFX",
    "123_BODY_FALL_C1_SFX",
    "124_BODY_FALL_C2_SFX",
    "125_BODY_FALL_C3_SFX",
    "126_BODY_FALL_D1_SFX",
    "127_BODY_FALL_D2_SFX",
    "128_BODY_FALL_D3_SFX",
    "129_BODY_FALL_D4_SFX",
    "130_BODY_FALL_E1_SFX",
    "131_BODY_FALL_E2_SFX",
    "132_BODY_FALL_E3_SFX",
    "133_BODY_ROLLOVER_SFX",
    "134_GET_HIT_MALE0_SFX",
    "135_GET_HIT_MALE1_SFX",
    "136_GET_HIT_MALE2_SFX",
    "137_GET_HIT_MALE3_SFX",
    "138_GET_HIT_MALE4_SFX",
    "139_GET_HIT_MALE5_SFX",
    "140_GET_HIT_MALE6_SFX",
    "141_GET_HIT_MALE7_SFX",
    "142_GET_HIT_MALE8_SFX",
    "143_GET_HIT_MALE9_SFX",
    "144_GET_HIT_MALE10_SFX",
    "145_GET_HIT_MALE11_SFX",
    "146_GET_HIT_MALE12_SFX",
    "147_GET_HIT_MALE13_SFX",
    "148_GET_HIT_MALE14_SFX",
    "149_GET_HIT_MALE15_SFX",
    "150_GET_HIT_MALE16_SFX",
    "151_GET_HIT_MALE17_SFX",
    "152_GET_HIT_MALE18_SFX",
    "153_GET_HIT_MALE19_SFX",
    "154_GET_HIT_MALE20_SFX",
    "155_GET_HIT_MALE21_SFX",
    "156_GET_HIT_MALE22_SFX",
    "157_GET_HIT_MALE23_SFX",
    "158_GET_HIT_MALE24_SFX",
    "159_CAMERA_BEEP1_SFX",           //Used for Watch Beeping
    "160_BING_SFX",
    "161_ALARM1_SFX",
    "162_ALARM2_SFX",
    "163_ALARM3_SFX",
    "164_RICO_EAR_WHISTLE1_SFX",
    "165_RICO_EAR_WHISTLE2_SFX",
    "166_RICO_EAR_WHISTLE3_SFX",
    "167_RICO_EAR_WHISTLE4_SFX",
    "168_RICO_EAR_WHISTLE5_SFX",
    "169_EXPLOSION_2A_SFX",
    "170_EXPLOSION_2B_SFX",
    "171_EXPLOSION_3_SFX",
    "172_EXPLOSION_4A_SFX",
    "173_EXPLOSION_4B_SFX",
    "174_EXPLOSION_5A_SFX",
    "175_EXPLOSION_5B_SFX",
    "176_EXPLOSION_5C_SFX",
    "177_EXPLOSION_6_SFX",
    "178_EXPLOSION_7_SFX",
    "178_EXPLOSION_8_SFX",
    "178_EXPLOSION_9_SFX",
    "181_EXPLOSION_1B_SFX",
    "182_EXPLOSION_1C_SFX",
    "183_CRUSHED_YELL_SFX",
    "184_KEY_SEQUENCE_SFX",
    "185_HIT_BULLET_DIRT2_SFX",
    "186_ALARM_SWITCH_SFX",
    "187_DOOR_WOOD_CLOSE_SFX",
    "188_DOOR_WOOD_OPEN_SFX",
    "189_ATOMIC_BOMB_SFX",
    "190_KEY_ANALYSER2_SFX",
    "191_DOOR_WOOD_SLIDE_SFX",
    "192_TRAIN_SLIDE_DOOR_CATCH_SFX",
    "193_GAS_LEAK_SFX",
    "194_DOOR_SHUTTER_OPEN_SFX",
    "195_DOOR_SHUTTER_CLOSE_SFX",
    "196_DOOR_METAL_OPEN_SFX",
    "197_DOOR_METAL_CLOSE_SFX",
    "198_CONSOLE_ON_SFX",
    "199_DOOR_METAL_CLOSE2_SFX",
    "200_DOOR_METAL_OPEN3_SFX",
    "201_DOOR_METAL_CLOSE3_SFX",
    "202_METAL_SLIDE_OPEN_SFX",
    "203_METAL_SLIDE_CLOSE_SFX",
    "204_METAL_SLIDE_LOOP_SFX",
    "205_UNKNOWN4_SFX",
    "206_UNKNOWN5_SFX",
    "207_UNKNOWN6_SFX",
    "208_HIT_BULLET_STONE1_SFX",
    "209_HIT_BULLET_STONE2_SFX",
    "210_DOOR_SMART_CATCH1_SFX",
    "211_DOOR_SMART_SLIDE1_SFX",
    "212_HIT_BULLET_TILE_SFX",
    "213_TANK_CRUSH_MAN_SFX",
    "214_HEAVY_SLIDE_OPEN_SFX",
    "215_HEAVY_SLIDE_CLOSE_SFX",
    "216_HEAVY_SINGLE_LOOP_SFX",
    "217_HIT_BULLET_WOOD2_SFX",
    "218_DOOR_HYDRAL_CLOSE_SFX",      // Main Hydrolic Door loop
    "219_DOOR_HYDRAL_OPEN_SFX",       // Hudrolic Door Stop sound
    "220_HIT_BULLET_DIRT1_SFX",
    "221_HIT_METAL_OBJECT2_SFX",
    "222_DOOR_LOCK_SFX",              //Also used for button Presses
    "223_TRAIN_CLUTTER2_SFX",
    "224_HIT_BULLET_MUD3_SFX",
    "225_DOOR_SLIDE_STONE_OPEN_SFX",  //Main Stone Door Loop
    "226_DOOR_SLIDE_STONE_CLOSE_SFX", //Stone Door Stop
    "227_DATA_DOWNLOAD_SFX",
    "228_LASER_GUN_SFX",
    "229_KEYCARD_SFX",
    "230_HIT_BULLET_MUD2_SFX",
    "231_HIT_BULLET_MUD1_SFX",
    "232_PICKUP_GUN_SFX",
    "233_PICKUP_KNIFE_SFX",
    "234_PICKUP_AMMO_SFX",
    "235_PICKUP_MINE_SFX",
    "236_WATCH_STATIC_SFX",
    "237_WATCH_ON_SFX",
    "238_WATCH_OFF_SFX",
    "239_HIT_BULLET_METAL_A3_SFX",
    "240_HIT_BULLET_METAL_A4_SFX",
    "241_ATTACH_MINE_SFX",
    "242_PICKUP_LASER_SFX",
    "243_WATCH_DETONATE_MINE_SFX",    //Watch Trigger
    "244_CAMERA_CLICK_SFX",           //Camera Shutter
    "245_KEY_ANALYSER_SFX",
    "246_MAGNETIC_HUM_SFX",
    "247_BOMB_DEFUSE_SFX",
    "248_BI_PLANE_SFX",
    "249_TRAIN_CLUTTER_SFX",
    "250_TRAIN_CLUTTERB_SFX",
    "251_TRAIN_CLUTTERC_SFX",
    "252_TRAIN_CLUTTERD_SFX",
    "253_GUN_B9_CANNON_SHORT_SFX",
    "254_UNKNOWN_QUIET_SFX",
    "255_CAMERA_ZOOM_LOOP_SFX",
    "256_CAMERA_ZOOM_STOP_SFX",
    "257_SNEEZE_SFX",
    "258_RARELOGO_SFX",
    "259_RARELOGO_QUIET_SFX",
    "260_RARELOGO_FAINT_SFX",
    "261_BIG_CLANK_SFX"
};
#endif

typedef enum SHOT_REGISTER
{
    SHOT_REGISTER_TOTAL,
    SHOT_REGISTER_HEAD,
    SHOT_REGISTER_BODY,
    SHOT_REGISTER_LIMB,
    SHOT_REGISTER_GUN,
    SHOT_REGISTER_HAT,
    SHOT_REGISTER_OBJECT
} SHOT_REGISTER;

typedef enum SPEED
{
    SPEED_WALK,
    SPEED_RUN,
    SPEED_SPRINT
} SPEED;

typedef enum STAGESTATUS
{
    STAGESTATUS_LOCKED,
    STAGESTATUS_UNLOCKED,
    STAGESTATUS_NOTCOMPLETED,
    STAGESTATUS_COMPLETED
} STAGESTATUS;

typedef enum TEXTBANK_LEVEL_INDEX
{
    LNULL,       /* Null (unused) */
    LAME,        /* Library (multi) */
    LARCH,       /* Archives */
    LARK,        /* Facility */
    LASH,        /* Stack (multi) */
    LAZT,        /* Aztec */
    LCAT,        /* Citadel (multi) */
    LCAVE,       /* Caverns */
    LAREC,       /* Control */
    LCRAD,       /* Cradle */
    LCRYP,       /* Egypt */
    LDAM,        /* Dam */
    LDEPO,       /* Depot */
    LDEST,       /* Frigate */
    LDISH,       /* Temple (multi) */
    LEAR,        /* Ear (unused) */
    LELD,        /* Eld (unused) */
    LIMP,        /* Basement (multi) */
    LJUN,        /* Jungle */
    LLEE,        /* Lee (unused) */
    LLEN,        /* Cuba */
    LLIP,        /* Lip (unused) */
    LLUE,        /* Lue (unused) */
    LOAT,        /* Cave (multi) */
    LPAM,        /* Pam (unused) */
    LPETE,       /* Streets */
    LREF,        /* Complex (multi) */
    LRIT,        /* Rit (unused) */
    LRUN,        /* Runway */
    LSEVB,       /* Bunker 2 */
    LSEV,        /* Bunker 1 */
    LSEVX,       /* Surface 1 */
    LSEVXB,      /* Surface 2 */
    LSHO,        /* Sho (unused) */
    LSILO,       /* Silo */
    LSTAT,       /* Statue */
    LTRA,        /* Train */
    LWAX,        /* Wax (unused) */
    LGUN,        /* Guns */
    LTITLE,      /* Stage and menu titles */
    LMPMENU,     /* Multi menus */
    LPROPOBJ,    /* In-game pickups */
    LMPWEAPONS,  /* Multi weapon select */
    LOPTIONS,    /* Solo in-game menus */
    LMISC        /* Cheat options */
} TEXTBANK_LEVEL_INDEX;

#define GUNSIGHTREASON_1         0x01
#define GUNSIGHTREASON_NOTAIMING 0x02
#define GUNSIGHTREASON_NOCONTROL 0x04
#define GUNSIGHTREASON_DAMAGE    0x10

#define GUNAMMOREASON_OPTION     0x01
#define GUNAMMOREASON_NOCONTROL  0x02
#define GUNAMMOREASON_DAMAGE     0x08

typedef enum WATCH_ANIMATION_STATE_IDS {
    WATCH_ANIMATION_0x0 = 0,
    WATCH_ANIMATION_0x1,
    WATCH_ANIMATION_0x2,
    WATCH_ANIMATION_0x3,
    WATCH_ANIMATION_0x4,
    WATCH_ANIMATION_0x5,
    WATCH_ANIMATION_0x6,
    WATCH_ANIMATION_0x7,
    WATCH_ANIMATION_0x8,
    WATCH_ANIMATION_0x9,
    WATCH_ANIMATION_0xa,
    WATCH_ANIMATION_0xb,
    WATCH_ANIMATION_0xc,
    WATCH_ANIMATION_0xd
} WATCH_ANIMATION_STATE;

typedef enum WATCH_BRIEFING_PAGE
{
    BRIEFING_INVALID = -1,
    BRIEFING_TITLE,
    BRIEFING_OVERVIEW,
    BRIEFING_M,
    BRIEFING_Q,
    BRIEFING_MONEYPENNY
} WATCH_BRIEFING_PAGE;


typedef enum AWARD {

    AWARD_MOSTSUICIDAL     = 0x00001,
    AWARD_WHONEEDSAMMO     = 0x00002,
    AWARD_WHERESTHEARMOUR  = 0x00004,
    AWARD_ACNEGATIVE10     = 0x00008,
    AWARD_MARKSMANSHIP     = 0x00010,
    AWARD_MOSTPROFESSIONAL = 0x00020,
    AWARD_MOSTDEADLY       = 0x00040,
    AWARD_MOSTHARMLESS     = 0x00080,
    AWARD_MOSTCOWARDLY     = 0x00100,
    AWARD_MOSTFRANTIC      = 0x00200,
    AWARD_MOSTHONORABLE    = 0x00400,
    AWARD_MOSTDISHONORABLE = 0x00800,
    AWARD_SHORTESTINNINGS  = 0x01000,
    AWARD_LONGESTINNINGS   = 0x02000,
    AWARD_DOUBLEKILL       = 0x04000,
    AWARD_TRIPLEKILL       = 0x08000,
    AWARD_QUADKILL         = 0x10000
} AWARD;


typedef enum WAYMODE
{
    WAYMODE_0,
    WAYMODE_1,
    WAYMODE_2,
    WAYMODE_3,
    WAYMODE_4,
    WAYMODE_5,
    WAYMODE_MAGIC
} WAYMODE;

typedef enum SPSEGMENT
{
    SPSEGMENT_PHYSICAL   = 0,
    SPSEGMENT_UNKNOWN    = 1,
    SPSEGMENT_GETITLE    = 2,
    SPSEGMENT_MODEL_MTX  = 3,
    SPSEGMENT_MODEL_VTX  = 4,
    SPSEGMENT_MODEL_COL1 = 5,
    SPSEGMENT_MODEL_COL2 = 6,
    SPSEGMENT_BG_COL     = 13,
    SPSEGMENT_BG_VTX     = 14,
    SPSEGMENT_BG_DL      = 15
} SPSEGMENT;

typedef enum TVCMD
{
    TVCMD_STOPSCROLL     = 0x00,
    TVCMD_SCROLLRELX     = 0x01,
    TVCMD_SCROLLRELY     = 0x02,
    TVCMD_SCROLLABSX     = 0x03,
    TVCMD_SCROLLABSY     = 0x04,
    TVCMD_SCALEABSX      = 0x05,
    TVCMD_SCALEABSY      = 0x06,
    TVCMD_SETTEXTURE     = 0x07,
    TVCMD_PAUSE          = 0x08,
    TVCMD_SETCMDLIST     = 0x09,
    TVCMD_RANDSETCMDLIST = 0x0a,
    TVCMD_RESTART        = 0x0b,
    TVCMD_YIELD          = 0x0c,
    TVCMD_SETCOLOUR      = 0x0d,
    TVCMD_ROTATEABS      = 0x0e,
    TVCMD_ROTATEREL      = 0x0f
} TVCMD;

enum CCRMLUT
{
    CCRMLUT_UNKNOWN,
    CCRMLUT_PRIMARY_ADDFOG,
    CCRMLUT_BILLBOARD,
    CCRMLUT_WATER,
    CCRMLUT_CLOUD,
    CCRMLUT_SECONDARY_ADDFOG,
    CCRMLUT_PRIMARY,
    CCRMLUT_SECONDARY,
    CCRMLUT_WALLETBOND,
    CCRMLUT_FIXFOGALPHA3
};

#pragma region Object Instance Stuff
    typedef enum BODIES
    {
        BODY_Jungle_Commando,
        BODY_St_Petersburg_Guard,
        BODY_Russian_Soldier,
        BODY_Russian_Infantry,
        BODY_Janus_Special_Forces,
        BODY_Brosnan_Tuxedo,
        #ifdef ALL_BONDS
        BODY_Connery_Tuxedo,
        BODY_Dalton_Tuxedo,
        BODY_Moore_Tuxedo,
        #endif
        BODY_Boris,
        BODY_Ourumov,
        BODY_Trevelyan_Janus,
        BODY_Trevelyan_006,
        BODY_Valentin_,
        BODY_Xenia,
        BODY_Baron_Samedi,
        BODY_Jaws,
        BODY_Mayday,
        BODY_Oddjob,
        BODY_Natalya_Skirt,
        BODY_Janus_Marine,
        BODY_Russian_Commandant,
        BODY_Siberian_Guard_1_Mishkin,
        BODY_Naval_Officer,
        BODY_Siberian_Special_Forces,
        BODY_Special_Operations_Uniform,
        BODY_Formal_Wear,
        BODY_Jungle_Fatigues,
        BODY_Parka,
        BODY_Unused_Female,
        BODY_Rosika,
        BODY_Scientist_2_Female,
        BODY_Civilian_1_Female,
        BODY_Unused_Male_1,
        BODY_Unused_Male_2,
        BODY_Civilian_4,
        BODY_Civilian_2,
        BODY_Civilian_3,
        BODY_Scientist_1_Male,
        BODY_Helicopter_Pilot,
        BODY_Siberian_Guard_2,
        BODY_Arctic_Commando,
        BODY_Moonraker_Elite_1_Male,
        BODY_Moonraker_Elite_2_Female,
        BODY_Left_Suit_Hand_Floating_Arm,
        HEAD_START,
        BODY_Male_Karl = HEAD_START,
        BODY_Male_Alan,
        BODY_Male_Pete,
        BODY_Male_Martin,
        BODY_Male_Mark,
        BODY_Male_Duncan,
        BODY_Male_Shaun,
        BODY_Male_Dwayne,
        BODY_Male_B,
        BODY_Male_Dave_Dr_Doak,
        BODY_Male_Grant,
        BODY_Male_Des,
        BODY_Male_Chris,
        BODY_Male_Lee,
        BODY_Male_Neil,
        BODY_Male_Jim,
        BODY_Male_Robin,
        BODY_Male_Steve_H,
        BODY_Male_Terrorist,
        BODY_Male_Biker,
        BODY_Male_Graeme,
        BODY_Male_Steve_Ellis,
        BODY_Male_Joel,
        BODY_Male_Scott,
        BODY_Male_Joe_Altered,
        BODY_Male_Ken,
        BODY_Male_Joe,
        BODY_Male_Mishkin,
        BODY_Female_Sally,
        BODY_Female_Marion_Rosika,
        BODY_Female_Mandy,
        BODY_Female_Vivien,
        BODY_Male_Pierce_Bond_1,
        BODY_Male_Pierce_Bond_2,
        BODY_Male_Pierce_Bond_3,
        BODY_Male_Pierce_Bond_Parka,
        BODY_Male_Pierce_Bond_Tuxedo,
        BODY_Natalya_Jungle_Fatigues,
        BODIES_MAX
    } BODIES;
    typedef enum GENDER
    {
        FEMALE,
        MALE
    } GENDER;

    typedef enum HEADS
    {
        HEAD_Male_Karl = HEAD_START,
        HEAD_Male_Alan,
        HEAD_Male_Pete,
        HEAD_Male_Martin,
        HEAD_Male_Mark,
        HEAD_Male_Duncan,
        HEAD_Male_Shaun,
        HEAD_Male_Dwayne,
        HEAD_Male_B,
        HEAD_Male_Dave_Dr_Doak,
        HEAD_Male_Grant,
        HEAD_Male_Des,
        HEAD_Male_Chris,
        HEAD_Male_Lee,
        HEAD_Male_Neil,
        HEAD_Male_Jim,
        HEAD_Male_Robin,
        HEAD_Male_Steve_H,
        HEAD_Male_Terrorist,
        HEAD_Male_Biker,
        HEAD_Male_Graeme,
        HEAD_Male_Steve_Ellis,
        HEAD_Male_Joel,
        HEAD_Male_Scott,
        HEAD_Male_Joe_Altered,
        HEAD_Male_Ken,
        HEAD_Male_Joe,
        HEAD_Male_Mishkin,
        HEAD_F_START,
        HEAD_Female_Sally = HEAD_F_START,
        HEAD_Female_Marion_Rosika,
        HEAD_Female_Mandy,
        HEAD_Female_Vivien,
        HEAD_BOND_START,
        HEAD_Male_Brosnan_Boiler = HEAD_BOND_START,
        HEAD_Male_Brosnan_Default,
        HEAD_Male_Brosnan_Jungle,
        HEAD_Male_Brosnan_Parka,
        HEAD_Male_Brosnan_Tuxedo,
        #ifdef ALL_BONDS
        HEAD_Male_Connery_Tuxedo,
        HEAD_Male_Dalton_Tuxedo,
        HEAD_Male_Moore_Tuxedo,
        #endif
        HEAD_Natalya_Jungle_Fatigues,
        HEAD_END,
        /*The following are some maybe helpfull counts (maybe GE doesnt need them, but thought Id ad while here)*/
        HEAD_COUNT        = HEAD_END - HEAD_START,         // Total number of heads
        HEAD_MALE_COUNT   = HEAD_F_START - HEAD_START,     // Total number of usable randon male heads
        HEAD_FEMALE_COUNT = HEAD_BOND_START - HEAD_F_START // Total number of usable randon female heads
    } HEADS;

    //Canonical name and style "ai_destroyobj 2 : (def->obj == PROP_ELVIS_SAUCER)\n"
    typedef enum PROP
    {
        PROP_ALARM1,              /* Beta Alarm / Default Multi Weapon                                  */
        PROP_ALARM2,              /* Alarm                                                              */
        PROP_EXPLOSIONBIT,        /* White Pyramid (Explosion Bit)                                      */
        PROP_AMMO_CRATE1,         /* Ammo Crate (Brown w/ Edge Brace, 6x240 Black)                      */
        PROP_AMMO_CRATE2,         /* Ammo Crate (Brown w/ Center Brace, 12x8 Black)                     */
        PROP_AMMO_CRATE3,         /* Ammo Crate (Green w/ Center Brace, 12x8 Brown)                     */
        PROP_AMMO_CRATE4,         /* Ammo Crate (Green w/ Edge Brace, 6x8 White)                        */
        PROP_AMMO_CRATE5,         /* Ammo Crate (Green w/ Double Brace, 24x60 Black)                    */
        PROP_BIN1,                /* Rusted Trash Bin                                                   */
        PROP_BLOTTER1,            /* Desk Blotter                                                       */
        PROP_BOOK1,               /* Red Book                                                           */
        PROP_BOOKSHELF1,          /* Bookshelf                                                          */
        PROP_BRIDGE_CONSOLE1A,    /* Bridge Console w/ Monitor, Navigation + Keyboard 1A                */
        PROP_BRIDGE_CONSOLE1B,    /* Bridge Console w/ Navigation 1B                                    */
        PROP_BRIDGE_CONSOLE2A,    /* Bridge Console w/ Navigation, Monitor + Keyboard 2A                */
        PROP_BRIDGE_CONSOLE2B,    /* Bridge Console w/ Various Controls 2B                              */
        PROP_BRIDGE_CONSOLE3A,    /* Bridge Console w/ Monitor, Navigation + Keyboard 3A                */
        PROP_BRIDGE_CONSOLE3B,    /* Bridge Console w/ Monitor, Keyboard + Navigation 3B                */
        PROP_CARD_BOX1,           /* Cardboard Box, Kapto|Enb                                           */
        PROP_CARD_BOX2,           /* Cardboard Box, Red Arrow, Bahko                                    */
        PROP_CARD_BOX3,           /* Cardboard Box, Scrawled Text, Bahah                                */
        PROP_CARD_BOX4_LG,        /* Cardboard Box, Three Seams                                         */
        PROP_CARD_BOX5_LG,        /* Cardboard Box, Two Seams, Bahah                                    */
        PROP_CARD_BOX6_LG,        /* Cardboard Box, Bahko                                               */
        PROP_CCTV,                /* Surveillance Camera                                                */
        PROP_CONSOLE1,            /* Double Screen Consoles w/ Keyboards                                */
        PROP_CONSOLE2,            /* Double Screen Consoles w/ Left Keyboard                            */
        PROP_CONSOLE3,            /* Double Screen Consoles w/ Right Keyboard                           */
        PROP_CONSOLE_SEVA,        /* Console w/ Keyboard                                                */
        PROP_CONSOLE_SEVB,        /* Console w/ Monitor + Keyboard                                      */
        PROP_CONSOLE_SEVC,        /* Console w/ Switches                                                */
        PROP_CONSOLE_SEVD,        /* Console w/ Five Gauges                                             */
        PROP_CONSOLE_SEV2A,       /* Console w/ Four Faders                                             */
        PROP_CONSOLE_SEV2B,       /* Console w/ Monitor, Keyboard + Switches                            */
        PROP_CONSOLE_SEV2C,       /* Console w/ Three Gauges                                            */
        PROP_CONSOLE_SEV2D,       /* Console w/ Pressure Gauge                                          */
        PROP_CONSOLE_SEV_GEA,     /* Console w/ GoldenEye Key Slot                                      */
        PROP_CONSOLE_SEV_GEB,     /* Console w/ Faders + Pressure Gauge                                 */
        PROP_DESK1,               /* Desk w/ Kickplate                                                  */
        PROP_DESK2,               /* Desk                                                               */
        PROP_DESK_LAMP2,          /* Desk Lamp                                                          */
        PROP_DISC_READER,         /* External Hard Drive                                                */
        PROP_DISK_DRIVE1,         /* Floppy Disc Drive                                                  */
        PROP_FILING_CABINET1,     /* Filing Cabinet                                                     */
        PROP_JERRY_CAN1,          /* Jerrycan (Fuel Container)                                          */
        PROP_KEYBOARD1,           /* Computer Keyboard                                                  */
        PROP_KIT_UNITS1,          /* Kitchen Cabinets                                                   */
        PROP_LETTER_TRAY1,        /* Letter Tray                                                        */
        PROP_MAINFRAME1,          /* Mainframe, Basic                                                   */
        PROP_MAINFRAME2,          /* Mainframe, Advanced                                                */
        PROP_METAL_CHAIR1,        /* Chair (Metal)                                                      */
        PROP_METAL_CRATE1,        /* Metal Crate, 6 Top Corner                                          */
        PROP_METAL_CRATE2,        /* Metal Crate, 6 Bottom Corner                                       */
        PROP_METAL_CRATE3,        /* Metal Crate, Toxic Materials                                       */
        PROP_METAL_CRATE4,        /* Metal Crate, Double Stripe - Class D1 Hazard                       */
        PROP_MISSILE_RACK,        /* Naval Harpoon Missile in Containment Rack                          */
        PROP_MISSILE_RACK2,       /* Naval Harpoon Missiles in Containment Racks x4                     */
        PROP_OIL_DRUM1,           /* Oil Drum, Single Stripe, Ribbed                                    */
        PROP_OIL_DRUM2,           /* Oil Drum, Single Stripe, Ribbed - Class D1 Hazard                  */
        PROP_OIL_DRUM3,           /* Oil Drum, Single Stripe, Ribbed - Toxic Materials                  */
        PROP_OIL_DRUM5,           /* Oil Drum, Double Stripe - Toxic Materials                          */
        PROP_OIL_DRUM6,           /* Oil Drum - Toxic Materials                                         */
        PROP_OIL_DRUM7,           /* Oil Drum, Double Dashes - Class D1 Hazard                          */
        PROP_PADLOCK,             /* Padlock                                                            */
        PROP_PHONE1,              /* Telephone                                                          */
        PROP_RADIO_UNIT1,         /* Radio Tuner w/ 1 Knob + 2 Gauges                                   */
        PROP_RADIO_UNIT2,         /* Radio Tuner w/ 1 Knob + 5 Gauges                                   */
        PROP_RADIO_UNIT3,         /* Radio Tuner w/ 3 Knobs + 5 Gauges                                  */
        PROP_RADIO_UNIT4,         /* Radio Tuner w/ 3 Knobs + 2 Gauges                                  */
        PROP_SAT1_REFLECT,        /* GoldenEye Satellite                                                */
        PROP_SATDISH,             /* Satellite Dish (Arkangelsk)                                        */
        PROP_SATBOX,              /* Uplink Box                                                         */
        PROP_STOOL1,              /* Wooden Stool                                                       */
        PROP_SWIVEL_CHAIR1,       /* Swivel Chair                                                       */
        PROP_TORPEDO_RACK,        /* Naval Torpedo Rack x3                                              */
        PROP_TV1,                 /* Television Monitor                                                 */
        PROP_TV_HOLDER,           /* Hanging Monitor Rack                                               */
        PROP_TVSCREEN,            /* Wall Monitor Screen                                                */
        PROP_TV4SCREEN,           /* Wall Monitor Screens, 4-in-1                                       */
        PROP_WOOD_LG_CRATE1,      /* Wooden Crate w/ #4 Label, Bahah                                    */
        PROP_WOOD_LG_CRATE2,      /* Wooden Crate, Darker Shading, Kapto|Enb                            */
        PROP_WOOD_MD_CRATE3,      /* Wooden Crates x8, Bahko                                            */
        PROP_WOOD_SM_CRATE4,      /* Wooden Crate w/ #2 Label, Bahko                                    */
        PROP_WOOD_SM_CRATE5,      /* Wooden Crate w/ #4 Label, Darker Shading, Bahah                    */
        PROP_WOOD_SM_CRATE6,      /* Wooden Crate w/ UP Arrow, Kapto|Enb                                */
        PROP_WOODEN_TABLE1,       /* Wooden Table                                                       */
        PROP_SWIPE_CARD2,         /* Keycard                                                            */
        PROP_BORG_CRATE,          /* Blue and Gold Printed Circuit Cube (Borg Crate)                    */
        PROP_BOXES4X4,            /* Metal Crate Stack, 4x4                                             */
        PROP_BOXES3X4,            /* Metal Crate Stack, 3x4                                             */
        PROP_BOXES2X4,            /* Metal Crate Stack, 2x4                                             */
        PROP_SEC_PANEL,           /* Security Card Panel                                                */
        PROP_ICBM_NOSE,           /* Silo Missile (ICBM), Nose Cone Only                                */
        PROP_ICBM,                /* Silo Missile (ICBM)                                                */
        PROP_TUNING_CONSOLE1,     /* Dual Consoles on Castors                                           */
        PROP_DESK_ARECIBO1,       /* Computer Work Desk                                                 */
        PROP_LOCKER3,             /* Lockers, Single Venting                                            */
        PROP_LOCKER4,             /* Lockers, Double Venting                                            */
        PROP_ROOFGUN,             /* Ceiling Mounted Drone Gun                                          */
        PROP_DEST_ENGINE,         /* Frigate Engine                                                     */
        PROP_DEST_EXOCET,         /* Naval MK 29 Missile Launcher (Exocet)                              */
        PROP_DEST_GUN,            /* Naval 100 mm Gun Turret (TR 100)                                   */
        PROP_DEST_HARPOON,        /* Naval MK 141 Launch Canisters (Harpoon)                            */
        PROP_DEST_SEAWOLF,        /* Naval MK 26 Dual Missile Launcher (Seawolf)                        */
        PROP_WINDOW,              /* Window Glass                                                       */
        PROP_WINDOW_LIB_LG1,      /* Window Glass, Lattice Frame, 4x10 (single-sided)                   */
        PROP_WINDOW_LIB_SM1,      /* Window Glass, Lattice Frame, 4x3 (double-sided)                    */
        PROP_WINDOW_COR11,        /* Window Glass, Lattice Frame, 4x4 (single-sided)                    */
        PROP_JUNGLE3_TREE,        /* Jungle Large Tree                                                  */
        PROP_PALM,                /* Jungle Palm Tree                                                   */
        PROP_PALMTREE,            /* Jungle Palm Tree, Resprouting After Loss of Fronds                 */
        PROP_PLANT2B,             /* Jungle Plant, Low Shrub                                            */
        PROP_LABBENCH,            /* Laboratory Table w/ Sink Drains                                    */
        PROP_GASBARREL,           /* White Bin                                                          */
        PROP_GASBARRELS,          /* White Bins x4                                                      */
        PROP_BODYARMOUR,          /* Body Armor                                                         */
        PROP_BODYARMOURVEST,      /* Body Armor (Vest)                                                  */
        PROP_GASTANK,             /* Bottling Tank                                                      */
        PROP_GLASSWARE1,          /* Glass Cup                                                          */
        PROP_HATCHBOLT,           /* Metallic Securing Strip (Hatch Bolt)                               */
        PROP_BRAKEUNIT,           /* Train Brake Controller                                             */
        PROP_AK47MAG,             /* Gun Magazine (KF7 Soviet)                                          */
        PROP_M16MAG,              /* Gun Magazine (AR33 Assault Rifle)                                  */
        PROP_MP5KMAG,             /* Gun Magazine (D5K Deutsche)                                        */
        PROP_SKORPIONMAG,         /* Gun Magazine (Klobb)                                               */
        PROP_SPECTREMAG,          /* Gun Magazine (Phantom)                                             */
        PROP_UZIMAG,              /* Gun Magazine (ZMG (9mm))                                           */
        PROP_SILENCER,            /* Silencer                                                           */
        PROP_CHREXTINGUISHER,     /* Fire Extinguisher                                                  */
        PROP_BOXCARTRIDGES,       /* Box of Shells (Shotgun Cartridges)                                 */
        PROP_FNP90MAG,            /* Gun Magazine (RC-P90)                                              */
        PROP_GOLDENSHELLS,        /* Box of Shells (Golden Gun Bullets)                                 */
        PROP_MAGNUMSHELLS,        /* Box of Shells (Magnum Rounds)                                      */
        PROP_WPPKMAG,             /* Gun Magazine (PP7)                                                 */
        PROP_TT33MAG,             /* Gun Magazine (DD44 Dostovei)                                       */
        PROP_SEV_DOOR,            /* Grey Containment Door w/ Caution Stripes and Window                */
        PROP_SEV_DOOR3,           /* Grey Electronic Door w/ LEFT Arrow                                 */
        PROP_SEV_DOOR3_WIND,      /* BETA Electronic Door w/ LEFT Arrow and Fake Window                 */
        PROP_SEV_DOOR4_WIND,      /* Grey Electronic Door w/ LEFT Arrow and Window                      */
        PROP_SEV_TRISLIDE,        /* Glass Door w/ Stone Frame                                          */
        PROP_SEV_DOOR_V1,         /* Grey Electronic Door w/ UP Arrow                                   */
        PROP_STEEL_DOOR1,         /* Silver Corrugated Door w/ Caution Stripes                          */
        PROP_STEEL_DOOR2,         /* Rusty Door w/ Handle                                               */
        PROP_STEEL_DOOR3,         /* Double Cross Brace Door                                            */
        PROP_SILO_LIFT_DOOR,      /* Elevator Door                                                      */
        PROP_STEEL_DOOR2B,        /* Rusty Door w/o Handle                                              */
        PROP_DOOR_ROLLER1,        /* Blue Bay Door w/ Caution Stripes                                   */
        PROP_DOOR_ROLLER2,        /* Blue Bay Door w/ Venting and Caution Stripes                       */
        PROP_DOOR_ROLLER3,        /* Blue Bay Door w/ Venting and Caution Stripes                       */
        PROP_DOOR_ROLLER4,        /* Cargo Bay Door w/ UP Arrow and Transportation Stripes              */
        PROP_DOOR_ST_AREC1,       /* Blue Corrugated Door w/ Transportation Stripes                     */
        PROP_DOOR_ST_AREC2,       /* Blue Reversed Corrugated Door w/ Transportation Stripes            */
        PROP_DOOR_DEST1,          /* Grey Frigate Door w/ Indents and Caution Stripes                   */
        PROP_DOOR_DEST2,          /* Grey Frigate Door w/ Indents, Caution Stripes and KEEP CLEAR Label */
        PROP_GAS_PLANT_SW_DO1,    /* Grey Swinging Door w/ Blue Stripe                                  */
        PROP_GAS_PLANT_SW2_DO1,   /* Grey Swinging Door, Darker                                         */
        PROP_GAS_PLANT_SW3_DO1,   /* Grey Swinging Door, Lighter                                        */
        PROP_GAS_PLANT_SW4_DO1,   /* Light Wooden Door (Looks Like Sand)                                */
        PROP_GAS_PLANT_MET1_DO1,  /* Brown Electronic Door                                              */
        PROP_GAS_PLANT_WC_CUB1,   /* Bathroom Stall Door                                                */
        PROP_GASPLANT_CLEAR_DOOR, /* Laboratory Glass Door                                              */
        PROP_TRAIN_DOOR,          /* Dark Wooden Door                                                   */
        PROP_TRAIN_DOOR2,         /* Dark Wooden Door w/ Window                                         */
        PROP_TRAIN_DOOR3,         /* Dark Wooden Door w/ Window + Shutter                               */
        PROP_DOOR_EYELID,         /* Eyelid Door                                                        */
        PROP_DOOR_IRIS,           /* Iris Door                                                          */
        PROP_SEVDOORWOOD,         /* Cabin Door                                                         */
        PROP_SEVDOORWIND,         /* Weathered Swinging Door w/ Window                                  */
        PROP_SEVDOORNOWIND,       /* Weathered Swinging Door                                            */
        PROP_SEVDOORMETSLIDE,     /* Brown Corrugated Electronic Door                                   */
        PROP_CRYPTDOOR1A,         /* Stone Door w/ Prints (Set A)                                       */
        PROP_CRYPTDOOR1B,         /* Sand Door w/ Damage (Set A)                                        */
        PROP_CRYPTDOOR2A,         /* Stone Door w/ Prints, Darker (Set B)                               */
        PROP_CRYPTDOOR2B,         /* Sand Door w/ Damage, Darker (Set B)                                */
        PROP_CRYPTDOOR3,          /* Egyptian Moving Wall                                               */
        PROP_CRYPTDOOR4,          /* Brown Sand Door (Temple)                                           */
        PROP_VERTDOOR,            /* Blast Door (Control)                                               */
        PROP_HATCHDOOR,           /* Train Floor Hatch                                                  */
        PROP_DAMGATEDOOR,         /* Security Gate (Dam)                                                */
        PROP_DAMTUNDOOR,          /* Tunnel Flood Door (Dam)                                            */
        PROP_DAMCHAINDOOR,        /* Mesh Gate                                                          */
        PROP_SILOTOPDOOR,         /* Launch Tube Ceiling Shutter (Silo)                                 */
        PROP_DOORPRISON1,         /* Cell Door                                                          */
        PROP_DOORSTATGATE,        /* Park Gate                                                          */
        PROP_CHRKALASH,           /* KF7 Soviet                                                         */
        PROP_CHRGRENADELAUNCH,    /* Grenade Launcher                                                   */
        PROP_CHRKNIFE,            /* Hunting Knife                                                      */
        PROP_CHRLASER,            /* Moonraker Laser                                                    */
        PROP_CHRM16,              /* AR33 Assault Rifle                                                 */
        PROP_CHRMP5K,             /* D5K Deutsche                                                       */
        PROP_CHRRUGER,            /* Cougar Magnum                                                      */
        PROP_CHRWPPK,             /* PP7 Special Issue                                                  */
        PROP_CHRSHOTGUN,          /* Shotgun                                                            */
        PROP_CHRSKORPION,         /* Klobb                                                              */
        PROP_CHRSPECTRE,          /* Phantom                                                            */
        PROP_CHRUZI,              /* ZMG (9mm)                                                          */
        PROP_CHRGRENADE,          /* Hand Grenade                                                       */
        PROP_CHRFNP90,            /* RC-P90                                                             */
        PROP_CHRBRIEFCASE,        /* Briefcase                                                          */
        PROP_CHRREMOTEMINE,       /* Remote Mine                                                        */
        PROP_CHRPROXIMITYMINE,    /* Proximity Mine                                                     */
        PROP_CHRTIMEDMINE,        /* Timed Mine                                                         */
        PROP_CHRROCKET,           /* Rocket                                                             */
        PROP_CHRGRENADEROUND,     /* Grenade Round                                                      */
        PROP_CHRWPPKSIL,          /* PP7 (Silenced)                                                     */
        PROP_CHRTT33,             /* DD44 Dostovei                                                      */
        PROP_CHRMP5KSIL,          /* D5K (Silenced)                                                     */
        PROP_CHRAUTOSHOT,         /* Automatic Shotgun                                                  */
        PROP_CHRGOLDEN,           /* Golden Gun                                                         */
        PROP_CHRTHROWKNIFE,       /* Throwing Knife                                                     */
        PROP_CHRSNIPERRIFLE,      /* Sniper Rifle                                                       */
        PROP_CHRROCKETLAUNCH,     /* Rocket Launcher                                                    */
        PROP_HATFURRY,            /* Fur Hat, Blue                                                      */
        PROP_HATFURRYBROWN,       /* Fur Hat, Brown                                                     */
        PROP_HATFURRYBLACK,       /* Fur Hat, Black                                                     */
        PROP_HATTBIRD,            /* Side Cap, Light Green                                              */
        PROP_HATTBIRDBROWN,       /* Side Cap, Dark Green                                               */
        PROP_HATHELMET,           /* Combat Helmet, Green                                               */
        PROP_HATHELMETGREY,       /* Combat Helmet, Grey                                                */
        PROP_HATMOON,             /* Elite Headgear                                                     */
        PROP_HATBERET,            /* Special Forces Beret, Black                                        */
        PROP_HATBERETBLUE,        /* Special Forces Beret, Navy                                         */
        PROP_HATBERETRED,         /* Special Forces Beret, Burgundy                                     */
        PROP_HATPEAKED,           /* Officer's Peaked Visor Cap                                         */
        PROP_CHRWRISTDART,        /* Pchrwristdart (BETA)                                               */
        PROP_CHREXPLOSIVEPEN,     /* Pchrexplosivepen (BETA)                                            */
        PROP_CHRBOMBCASE,         /* Bomb Case (Briefcase Laying Down)                                  */
        PROP_CHRFLAREPISTOL,      /* Pchrflarepistol (BETA Pickup)                                      */
        PROP_CHRPITONGUN,         /* Pchrpitongun (BETA Pickup)                                         */
        PROP_CHRFINGERGUN,        /* Pchrfingergun (BETA Pickup)                                        */
        PROP_CHRSILVERWPPK,       /* Pchrsilverwppk (BETA Pickup)                                       */
        PROP_CHRGOLDWPPK,         /* Pchrgoldwppk (BETA Pickup)                                         */
        PROP_CHRDYNAMITE,         /* Pchrdynamite (BETA Pickup)                                         */
        PROP_CHRBUNGEE,           /* Pchrbungee (BETA Pickup)                                           */
        PROP_CHRDOORDECODER,      /* Door Decoder                                                       */
        PROP_CHRBOMBDEFUSER,      /* Bomb Defuser                                                       */
        PROP_CHRBUGDETECTOR,      /* Pchrbugdetector (BETA Pickup)                                      */
        PROP_CHRSAFECRACKERCASE,  /* Safe Cracker Case (Briefcase Laying Down)                          */
        PROP_CHRCAMERA,           /* Photo Camera (007)                                                 */
        PROP_CHRLOCKEXPLODER,     /* Pchrlockexploder (BETA Pickup)                                     */
        PROP_CHRDOOREXPLODER,     /* Pchrdoorexploder (BETA Pickup)                                     */
        PROP_CHRKEYANALYSERCASE,  /* Key Analyzer Case (Briefcase Laying Down)                          */
        PROP_CHRWEAPONCASE,       /* Weapon Case (Briefcase Standing Up)                                */
        PROP_CHRKEYYALE,          /* Yale Key                                                           */
        PROP_CHRKEYBOLT,          /* Bolt Key                                                           */
        PROP_CHRBUG,              /* Covert Modem / Tracker Bug                                         */
        PROP_CHRMICROCAMERA,      /* Micro Camera                                                       */
        PROP_FLOPPY,              /* Floppy Disc                                                        */
        PROP_CHRGOLDENEYEKEY,     /* GoldenEye Key                                                      */
        PROP_CHRPOLARIZEDGLASSES, /* Polarized Glasses                                                  */
        PROP_CHRCREDITCARD,       /* Pchrcreditcard (BETA Pickup)                                       */
        PROP_CHRDARKGLASSES,      /* Pchrdarkglasses (BETA Pickup)                                      */
        PROP_CHRGASKEYRING,       /* Gas Keyring                                                        */
        PROP_CHRDATATHIEF,        /* Datathief                                                          */
        PROP_SAFE,                /* Safe Body                                                          */
        PROP_BOMB,                /* Pbomb (BETA Pickup)                                                */
        PROP_CHRPLANS,            /* Plans (Briefing Folder)                                            */
        PROP_CHRSPYFILE,          /* Pchrspyfile (BETA Pickup)                                          */
        PROP_CHRBLUEPRINTS,       /* Pirate Blueprints                                                  */
        PROP_CHRCIRCUITBOARD,     /* Circuitboard                                                       */
        PROP_CHRMAP,              /* Bunker Expansion Plans                                             */
        PROP_CHRSPOOLTAPE,        /* Pchrspooltape (BETA Pickup)                                        */
        PROP_CHRAUDIOTAPE,        /* Audiotape                                                          */
        PROP_CHRMICROFILM,        /* Pchrmicrofilm (BETA Pickup)                                        */
        PROP_CHRMICROCODE,        /* Pchrmicrocode (BETA Pickup)                                        */
        PROP_CHRLECTRE,           /* Pchrlectre (BETA Pickup)                                           */
        PROP_CHRMONEY,            /* Pchrmoney (BETA Pickup)                                            */
        PROP_CHRGOLDBAR,          /* Pchrgoldbar (BETA Pickup)                                          */
        PROP_CHRHEROIN,           /* Pchrheroin (BETA Pickup)                                           */
        PROP_CHRCLIPBOARD,        /* Clipboard                                                          */
        PROP_CHRDOSSIERRED,       /* Red Dossier                                                        */
        PROP_CHRSTAFFLIST,        /* Staff List                                                         */
        PROP_CHRDATTAPE,          /* DAT                                                                */
        PROP_CHRPLASTIQUE,        /* Plastique                                                          */
        PROP_CHRBLACKBOX,         /* Black Box (Orange Flight Recorder)                                 */
        PROP_CHRVIDEOTAPE,        /* CCTV Tape (GoldenEye VHS)                                          */
        PROP_NINTENDOLOGO,        /* Nintendo Logo                                                      */
        PROP_GOLDENEYELOGO,       /* GoldenEye Logo                                                     */
        PROP_WALLETBOND,          /* Classified Folder w/ Royal Crest (Folder Menus)                    */
        PROP_MILTRUCK,            /* Supply Truck                                                       */
        PROP_JEEP,                /* Military Jeep                                                      */
        PROP_ARTIC,               /* Red Prime Mover                                                    */
        PROP_HELICOPTER,          /* Transport Helicopter w/ Natalya                                    */
        PROP_TIGER,               /* Pirate Euro Chopper                                                */
        PROP_MILCOPTER,           /* Hound Helicopter                                                   */
        PROP_HIND,                /* Soviet Camouflage Chopper                                          */
        PROP_ARTICTRAILER,        /* Black Trailer                                                      */
        PROP_MOTORBIKE,           /* Motorbike                                                          */
        PROP_TANK,                /* Tank                                                               */
        PROP_APC,                 /* Armored Personnel Carrier                                          */
        PROP_SPEEDBOAT,           /* Speedboat                                                          */
        PROP_PLANE,               /* Aeroplane                                                          */
        PROP_GUN_RUNWAY1,         /* Heavy Gun Emplacement                                              */
        PROP_SAFEDOOR,            /* Safe Door                                                          */
        PROP_KEY_HOLDER,          /* Key Rack                                                           */
        PROP_HATCHSEVX,           /* Grating (Ventshaft Hatch)                                          */
        PROP_SEVDISH,             /* Satellite Dish (Severnaya)                                         */
        PROP_ARCHSECDOOR1,        /* Archives Moving Wall (Dark)                                        */
        PROP_ARCHSECDOOR2,        /* Archives Moving Wall (Light)                                       */
        PROP_GROUNDGUN,           /* Free Standing Drone Gun                                            */
        PROP_TRAINEXTDOOR,        /* Train Exterior Door                                                */
        PROP_CARBMW,              /* White Car #1 (BMW)                                                 */
        PROP_CARESCORT,           /* White Car #2 (Escort)                                              */
        PROP_CARGOLF,             /* White Car #3 (Golf)                                                */
        PROP_CARWEIRD,            /* Red Car (Cadillac)                                                 */
        PROP_CARZIL,              /* Ourumov's Car (ZIL)                                                */
        PROP_SHUTTLE_DOOR_L,      /* Exhaust Bay Doors, Left Side                                       */
        PROP_SHUTTLE_DOOR_R,      /* Exhaust Bay Doors, Right Side                                      */
        PROP_DEPOT_GATE_ENTRY,    /* Metallic Gate w/ Red Star                                          */
        PROP_DEPOT_DOOR_STEEL,    /* Rusty Door w/ Handle (Lo-Res)                                      */
        PROP_GLASSWARE2,          /* Beaker w/ Blue Topper                                              */
        PROP_GLASSWARE3,          /* Erlenmeyer Flask                                                   */
        PROP_GLASSWARE4,          /* Set of Five Beakers                                                */
        PROP_LANDMINE,            /* Land Mine                                                          */
        PROP_PLANT1,              /* Jungle Plant, Withered and Dying                                   */
        PROP_PLANT11,             /* Jungle Plant, Turning Colour                                       */
        PROP_PLANT2,              /* Jungle Plant, Healthy and Thick                                    */
        PROP_PLANT3,              /* Jungle Plant, Tall Leaves                                          */
        PROP_JUNGLE5_TREE,        /* Jungle Tree, Moss Covered                                          */
        PROP_LEGALPAGE,           /* GoldenEye Certification Screen                                     */
        PROP_ST_PETE_ROOM_1I,     /* Roads and Buildings #1 (stretch of road)                           */
        PROP_ST_PETE_ROOM_2I,     /* Roads and Buildings #2 (stretch of road)                           */
        PROP_ST_PETE_ROOM_3T,     /* Roads and Buildings #3 (intersection)                              */
        PROP_ST_PETE_ROOM_5C,     /* Roads and Buildings #4 (street corner)                             */
        PROP_ST_PETE_ROOM_6C,     /* Roads and Buildings #5 (street corner)                             */
        PROP_DOOR_ROLLERTRAIN,    /* Roller Door                                                        */
        PROP_DOOR_WIN,            /* Glass Sliding Door (Aztec)                                         */
        PROP_DOOR_AZTEC,          /* Stone Sliding Door (Aztec)                                         */
        PROP_SHUTTLE,             /* Moonraker Shuttle                                                  */
        PROP_DOOR_AZT_DESK,       /* Boardroom Table (Aztec Exhaust Bay)                                */
        PROP_DOOR_AZT_DESK_TOP,   /* Boardroom Table Extension (Aztec Exhaust Bay)                      */
        PROP_DOOR_AZT_CHAIR,      /* Boardroom Chair (Aztec Exhaust Bay)                                */
        PROP_DOOR_MF,             /* Mainframe Door                                                     */
        PROP_FLAG,                /* Flag Tag Token                                                     */
        PROP_BARRICADE,           /* Road Barricade                                                     */
        PROP_MODEMBOX,            /* Covert Modem Connection Screen                                     */
        PROP_DOORPANEL,           /* Sliding Door Activation Switch                                     */
        PROP_DOORCONSOLE,         /* Console w/ Activation Light                                        */
        PROP_CHRTESTTUBE,         /* Glass Test Tube                                                    */
        PROP_BOLLARD,             /* Bollard                                                            */
        PROP_MAX
    } PROP;

        #define MAX_MULTI_PROP_IDS 600
    #define MAX_DROPPED_PROP_IDS 1000
#define DROPPED_PROP_ID_NUMBIT 0x1fff
#define GUNTYPE_NUMBITS 127

typedef enum PROJECTILES
    {
        PROJECTILES_MAX                = 0x2E,
        PROJECTILES_TYPE_KNIFE         = PROP_CHRKNIFE,
        PROJECTILES_TYPE_GRENADE       = PROP_CHRGRENADE,
        PROJECTILES_TYPE_REMOTE_MINE   = PROP_CHRREMOTEMINE,
        PROJECTILES_TYPE_PROX_MINE     = PROP_CHRPROXIMITYMINE,
        PROJECTILES_TYPE_TIMED_MINE    = PROP_CHRTIMEDMINE,
        PROJECTILES_TYPE_ROCKET_ROUND  = PROP_CHRROCKET,
        PROJECTILES_TYPE_ROCKET_ROUND2 = PROP_CHRROCKET,
        PROJECTILES_TYPE_GLAUNCH_ROUND = PROP_CHRGRENADEROUND,
        PROJECTILES_TYPE_BOMBCASE      = PROP_CHRBOMBCASE,
        PROJECTILES_TYPE_BUG           = PROP_CHRBUG,
        PROJECTILES_TYPE_MICROCAMERA   = PROP_CHRMICROCAMERA,
        PROJECTILES_TYPE_GE_KEY        = PROP_CHRGOLDENEYEKEY,
        PROJECTILES_TYPE_PLASTIQUE     = PROP_CHRPLASTIQUE
    } PROJECTILES;

    /** For use in Prop Records (Not to be confused with Object (canonical - Prop Definition) Records  which use PROPDEF (canonical Name)) */
    typedef enum PROP_TYPE
    {
        PROP_TYPE_NUL,
        PROP_TYPE_OBJ,
        PROP_TYPE_DOOR,
        PROP_TYPE_CHR,
        PROP_TYPE_WEAPON,
        PROP_TYPE_PLAYER,
        PROP_TYPE_VIEWER,
        PROP_TYPE_EXPLOSION,
        PROP_TYPE_SMOKE,
        PROP_TYPE_MAX
    } PROP_TYPE;

#ifdef DEBUG
    char *PROP_TYPE_ToString[] = {
        "PROP_TYPE_NUL",
        "PROP_TYPE_OBJ",
        "PROP_TYPE_DOOR",
        "PROP_TYPE_CHR",
        "PROP_TYPE_WEAPON",
        "PROP_TYPE_PLAYER",
        "PROP_TYPE_VIEWER",
        "PROP_TYPE_EXPLOSION",
        "PROP_TYPE_SMOKE" };
    #endif

#pragma endregion

#pragma region  PropDef stuff
    // used by characters

    /*Action Type to be performed by chr (canonical names)*/
    typedef enum ACT_STATUS
    {
        ACT_STATUS_NONE,
        ACT_STATUS_NORMAL,
        ACT_STATUS_COVERWAIT,
        ACT_STATUS_GRENADEWAIT,
        ACT_STATUS_WAITING,
        ACT_STATUS_COVERGOTO,
        ACT_STATUS_COVERBREAK,
        ACT_STATUS_COVERSEEN,
        ACT_STATUS_FLANKLEFT,
        ACT_STATUS_FLANKRIGHT,
        ACT_STATUS_DODGE,
        ACT_STATUS_GRENADE,
        ACT_STATUS_WAITSEEN,
        ACT_STATUS_WITHDRAW,
        ACT_STATUS_SHOOTING,
        ACT_STATUS_SYNCSHOOT,
        ACT_STATUS_WAITTIMEOUT,
        ACT_STATUS_COVERTIMEOUT,
        ACT_STATUS_TRACKING,
        ACT_STATUS_RETREAT,
        ACT_STATUS_SURRENDER,
        ACT_STATUS_TALKING,
        ACT_STATUS_LISTENING,
        ACT_STATUS_GOTOALARM,
        ACT_STATUS_BOTFRIENDFOLLOW,
        ACT_STATUS_BOTHIDE,
        ACT_STATUS_BOTPATH,
        ACT_STATUS_BOTINJURED,
        ACT_STATUS_BOTNORMAL,
        ACT_STATUS_BOTSHOOTING,
        ACT_STATUS_DRUGGED,
        ACT_STATUS_PANIC,
        ACT_STATUS_RUNFROMGRENADE,
        ACT_STATUS_UNARMEDATTACK,
        ACT_STATUS_MAX
    } ACT_STATUS;
    #ifdef DEBUG
    char *ACT_STATUS_ToString[] = {
    "NONE",
        "NORMAL",
        "COVERWAIT",
        "GRENADEWAIT",
        "WAITING",
        "COVERGOTO",
        "COVERBREAK",
        "COVERSEEN",
        "FLANKLEFT",
        "FLANKRIGHT",
        "DODGE",
        "GRENADE",
        "WAITSEEN",
        "WITHDRAW",
        "SHOOTING",
        "SYNCSHOOT",
        "WAITTIMEOUT",
        "COVERTIMEOUT",
        "TRACKING",
        "RETREAT",
        "SURRENDER",
        "TALKING",
        "LISTENING",
        "GOTOALARM",
        "BOTFRIENDFOLLOW",
        "BOTHIDE",
        "BOTPATH",
        "BOTINJURED",
        "BOTNORMAL",
        "BOTSHOOTING",
        "DRUGGED",
        "PANIC",
        "RUNFROMGRENADE",
        "UNARMEDATTACK"};
    #endif
    /*Action Type to be performed by chr (canonical names)*/
    typedef enum ACT_TYPE
    {
        ACT_INIT,
        ACT_STAND,
        ACT_KNEEL,
        ACT_ANIM,
        ACT_DIE,
        ACT_DEAD,
        ACT_ARGH,
        ACT_PREARGH,
        ACT_ATTACK,
        ACT_ATTACKWALK,
        ACT_ATTACKROLL, // 10
        ACT_SIDESTEP,
        ACT_JUMPOUT,
        ACT_RUNPOS,
        ACT_PATROL,
        ACT_GOPOS,
        ACT_SURRENDER,
        ACT_LOOKATTARGET,
        ACT_SURPRISED,
        ACT_STARTALARM,
        ACT_THROWGRENADE, // 20
        ACT_TURNDIR,
        ACT_TEST,
        ACT_BONDINTRO,
        ACT_BONDDIE,
        ACT_BONDMULTI,
        /*	PD ONLY
        ACT_BOT_ATTACKSTAND
        ACT_BOT_ATTACKKNEEL
        ACT_BOT_ATTACKSTRAFE
        ACT_DRUGGEDDROP
        ACT_DRUGGEDKO
        ACT_DRUGGEDCOMINGUP
        ACT_ATTACKAMOUNT
        ACT_ROBOTATTACK
        ACT_SKJUMP*
        */
        ACT_NULL,
        ACT_TYPE_MAX
    } ACT_TYPE;

        #ifdef DEBUG
    char *ACT_TYPE_ToString[] = {
        "ACT_INIT",
        "ACT_STAND",
        "ACT_KNEEL",
        "ACT_ANIM",
        "ACT_DIE",
        "ACT_DEAD",
        "ACT_ARGH",
        "ACT_PREARGH",
        "ACT_ATTACK",
        "ACT_ATTACKWALK",
        "ACT_ATTACKROLL", // 10
        "ACT_SIDESTEP",
        "ACT_JUMPOUT",
        "ACT_RUNPOS",
        "ACT_PATROL",
        "ACT_GOPOS",
        "ACT_SURRENDER",
        "ACT_LOOKATTARGET",
        "ACT_SURPRISED",
        "ACT_STARTALARM",
        "ACT_THROWGRENADE", // 20
        "ACT_TURNDIR",
        "ACT_TEST",
        "ACT_BONDINTRO",
        "ACT_BONDDIE",
        "ACT_BONDMULTI",
        "ACT_NULL"};
    #endif


    typedef enum AMMOTYPE
    {
        AMMO_NONE,
        AMMO_9MM,
        AMMO_9MM_2,
        AMMO_RIFLE,
        AMMO_SHOTGUN,
        AMMO_GRENADE,
        AMMO_ROCKETS,
        AMMO_REMOTEMINE,
        AMMO_PROXMINE,
        AMMO_TIMEDMINE,
        AMMO_KNIFE,
        AMMO_GRENADEROUND,
        AMMO_MAGNUM,
        AMMO_GGUN,
        AMMOTYPE_GLOBAL_MAX = AMMO_GGUN,
        // Ammo available in both SP and MP must be listed above this line.
        AMMO_DARTS,
        AMMO_EXPLOSIVEPEN,
        AMMO_BOMBCASE,
        AMMO_FLARE,
        AMMO_PITON,
        AMMO_DYNAMITE,
        AMMO_BUG,
        AMMO_MICRO_CAMERA,
        AMMO_GEKEY,
        AMMO_PLASTIQUE,
        AMMO_WATCH_LASER,
        AMMO_WATCH_MAGNET,
        AMMO_UNK,
        AMMO_CAMERA,
        AMMO_TANK,
        AMMO_TOKEN,
        AMMOTYPE_MAX
    } AMMOTYPE;

    typedef enum HATTYPE
    {
        HATTYPE_OTHER = -1,
        HATTYPE_BERRET,
        HATTYPE_BIRD, //pilotka/Side cap
        HATTYPE_PEAKED,
        HATTYPE_HELMATE,
        HATTYPE_FURRY,
        HATTYPE_MOON
    } HATTYPE;
    typedef enum INV_ITEM_TYPE
    {
        INV_ITEM_NONE,
        INV_ITEM_WEAPON,
        INV_ITEM_PROP,
        INV_ITEM_DUAL,
        INV_ITEM_PICKUP
    } INV_ITEM_TYPE;

    typedef enum ITEM_IDS
    {
        ITEM_UNARMED,
        ITEM_FIST,
        ITEM_KNIFE,
        ITEM_THROWKNIFE,
        ITEM_WPPK,
        ITEM_WPPKSIL,
        ITEM_TT33,
        ITEM_SKORPION,
        ITEM_AK47,
        ITEM_UZI,
        ITEM_MP5K,
        ITEM_MP5KSIL,
        ITEM_SPECTRE,
        ITEM_M16,
        ITEM_FNP90,
        ITEM_SHOTGUN,
        ITEM_AUTOSHOT,
        ITEM_SNIPERRIFLE,
        ITEM_RUGER,
        ITEM_GOLDENGUN,
        ITEM_SILVERWPPK,
        ITEM_GOLDWPPK,
        ITEM_LASER,
        ITEM_WATCHLASER,
        ITEM_GRENADELAUNCH,
        ITEM_ROCKETLAUNCH,
        ITEM_GRENADE,
        ITEM_TIMEDMINE,
        ITEM_PROXIMITYMINE,
        ITEM_REMOTEMINE,
        ITEM_TRIGGER,
        ITEM_TASER,
        ITEM_TANKSHELLS,
        ITEM_BOMBCASE,
        ITEM_PLASTIQUE,
        ITEM_FLAREPISTOL,
        ITEM_PITONGUN,
        ITEM_BUNGEE,
        ITEM_DOORDECODER,
        ITEM_BOMBDEFUSER,
        ITEM_CAMERA,
        ITEM_LOCKEXPLODER,
        ITEM_DOOREXPLODER,
        ITEM_BRIEFCASE,
        ITEM_WEAPONCASE,
        ITEM_SAFECRACKERCASE,
        ITEM_KEYANALYSERCASE,
        ITEM_BUG,
        ITEM_MICROCAMERA,
        ITEM_BUGDETECTOR,
        ITEM_EXPLOSIVEFLOPPY,
        ITEM_POLARIZEDGLASSES,
        ITEM_DARKGLASSES,
        ITEM_CREDITCARD,
        ITEM_GASKEYRING,
        ITEM_DATATHIEF,
        ITEM_WATCHIDENTIFIER,
        ITEM_WATCHCOMMUNICATOR,
        ITEM_WATCHGEIGERCOUNTER,
        ITEM_WATCHMAGNETREPEL,
        ITEM_WATCHMAGNETATTRACT,
        ITEM_GOLDENEYEKEY,
        ITEM_BLACKBOX,
        ITEM_CIRCUITBOARD,
        ITEM_CLIPBOARD,
        ITEM_STAFFLIST,
        ITEM_DOSSIERRED,
        ITEM_PLANS,
        ITEM_SPYFILE,
        ITEM_BLUEPRINTS,
        ITEM_MAP,
        ITEM_AUDIOTAPE,
        ITEM_VIDEOTAPE,
        ITEM_DATTAPE,
        ITEM_SPOOLTAPE,
        ITEM_MICROFILM,
        ITEM_MICROCODE,
        ITEM_LECTRE,
        ITEM_MONEY,
        ITEM_GOLDBAR,
        ITEM_HEROIN,
        ITEM_KEYCARD,
        ITEM_KEYYALE,
        ITEM_KEYBOLT,
        ITEM_SUIT_LF_HAND,
        ITEM_JOYPAD,
        ITEM_NULL86,
        ITEM_NULL87,
        ITEM_TOKEN,
        ITEM_IDS_MAX
    } ITEM_IDS;

    typedef enum PROPDEF_TYPE
    {
        PROPDEF_NOTHING,
        PROPDEF_DOOR,
        PROPDEF_DOOR_SCALE,
        PROPDEF_PROP,
        PROPDEF_KEY,
        PROPDEF_ALARM,
        PROPDEF_CCTV,
        PROPDEF_MAGAZINE,
        PROPDEF_COLLECTABLE,
        PROPDEF_GUARD,
        PROPDEF_MONITOR,
        PROPDEF_MULTI_MONITOR,
        PROPDEF_RACK,
        PROPDEF_AUTOGUN,
        PROPDEF_LINK,
        PROPDEF_DEBRIS,
        PROPDEF_UNK16,
        PROPDEF_HAT,
        PROPDEF_GUARD_ATTRIBUTE,
        PROPDEF_SWITCH,
        PROPDEF_AMMO,
        PROPDEF_ARMOUR,
        PROPDEF_TAG,
        PROPDEF_OBJECTIVE_START,
        PROPDEF_OBJECTIVE_END,
        PROPDEF_OBJECTIVE_DESTROY_OBJECT,
        PROPDEF_OBJECTIVE_COMPLETE_CONDITION,
        PROPDEF_OBJECTIVE_FAIL_CONDITION,
        PROPDEF_OBJECTIVE_COLLECT_OBJECT,
        PROPDEF_OBJECTIVE_DEPOSIT_OBJECT,
        PROPDEF_OBJECTIVE_PHOTOGRAPH,
        PROPDEF_OBJECTIVE_NULL,
        PROPDEF_OBJECTIVE_ENTER_ROOM,
        PROPDEF_OBJECTIVE_DEPOSIT_OBJECT_IN_ROOM,
        PROPDEF_OBJECTIVE_COPY_ITEM,
        PROPDEF_WATCH_MENU_OBJECTIVE_TEXT,
        PROPDEF_GAS_RELEASING,
        PROPDEF_RENAME,
        PROPDEF_LOCK_DOOR,
        PROPDEF_VEHICHLE,
        PROPDEF_AIRCRAFT,
        PROPDEF_UNK41,
        PROPDEF_GLASS,
        PROPDEF_SAFE,
        PROPDEF_SAFE_ITEM,
        PROPDEF_TANK,
        PROPDEF_CAMERAPOS, //canonical name
        PROPDEF_TINTED_GLASS,
        PROPDEF_END,
        PROPDEF_MAX
    } PROPDEF_TYPE;


#pragma endregion

#pragma region Setup

    /**
     * enums were listed in a particular order, it appears the first few are associated with the start/intro
     * of a level:
     *     if (g_CurrentPlayer->redbloodfinished && g_CurrentPlayer->deathanimfinished && (camera_mode >= CAMERAMODE_SWIRL))
    */
   typedef enum CAMERAMODE
    {
        CAMERAMODE_NONE,
        CAMERAMODE_INTRO,
        CAMERAMODE_FADESWIRL,
        CAMERAMODE_SWIRL,
        CAMERAMODE_FP,
        CAMERAMODE_DEATH_CAM_SP,
        CAMERAMODE_DEATH_CAM_MP,
        CAMERAMODE_POSEND,
        CAMERAMODE_FP_NOINPUT,
        CAMERAMODE_MP,
        CAMERAMODE_FADE_TO_TITLE,
        CAMERAMODE_COUNT
    } CAMERAMODE;

    typedef enum INTRO_TYPE
    {
        INTROTYPE_SPAWN,
        INTROTYPE_ITEM,
        INTROTYPE_AMMO,
        INTROTYPE_SWIRL,
        INTROTYPE_ANIM,
        INTROTYPE_CUFF,
        INTROTYPE_CAMERA,
        INTROTYPE_WATCH,
        INTROTYPE_CREDITS,
        INTROTYPE_END,
        INTROTYPE_MAX
    } INTRO_TYPE;
    typedef enum MISSION_STATE_IDS
    {
        MISSION_STATE_0,
        MISSION_STATE_1,
        MISSION_STATE_2,
        MISSION_STATE_3,
        MISSION_STATE_4,
        MISSION_STATE_5,
        MISSION_STATE_6
    } MISSION_STATE_ID;

    typedef enum OBJECTIVESTATUS
    {
        OBJECTIVESTATUS_INCOMPLETE,
        OBJECTIVESTATUS_COMPLETE,
        OBJECTIVESTATUS_FAILED
    } OBJECTIVESTATUS;

    typedef enum TANK_RUN_STATE
    {
        TANK_RUN_STATE_NOT_RUNNING = 0,
        TANK_RUN_STATE_STARTING,
        TANK_RUN_STATE_RUNNING
    } TANK_RUN_STATE;

#pragma endregion

#pragma region VI
    typedef enum COLORMODE
    {
        COLORMODE_32BIT,
        COLORMODE_16BIT
    } COLORMODE;

    typedef enum SCREEN_SIZE
    {
        SCREEN_SIZE_320x240,
        SCREEN_SIZE_440x330
    } SCREEN_SIZE;

    typedef enum SCREEN_SIZE_OPTION
    {
        SCREEN_SIZE_FULLSCREEN,
        SCREEN_SIZE_WIDESCREEN,
        SCREEN_SIZE_CINEMA
    } SCREEN_SIZE_OPTION;

    typedef enum SCREEN_RATIO_OPTION
    {
        SCREEN_RATIO_NORMAL,
        SCREEN_RATIO_16_9
    } SCREEN_RATIO_OPTION;

    //canonically MD
    typedef enum VIDEOMODE
    {
        MD_BLACK,
        MD_NORMAL,
        MD_MAXIMUM,

        //just in case someone commits with old name
        VIDEOMODE_DISABLE_320x240 = MD_BLACK,
        VIDEOMODE_320x240 = MD_NORMAL,
        VIDEOMODE_640x480 = MD_MAXIMUM
    } VIDEOMODE;
#pragma endregion

#if !defined(VERSION_EU)
#define MAXROOMCOUNT    150
#else
#define MAXROOMCOUNT    139
#endif


/* special chr num IDs */
#define CHR_BOND_CINEMA -8 /* only works when bond has a third person model (intro/exit cutscene) */
#define CHR_CLONE       -7
#define CHR_SEE_SHOT    -6 /* stored as chr->chrseeshot */
#define CHR_SEE_DIE     -5 /* stored as chr->chrseedie */
#define CHR_PRESET      -4 /* stored as chr->chrpreset1 */
#define CHR_SELF        -3

    /* private chr ID, cannot be accessed with ai commands */
#define CHR_OBJECTIVE        -2    /* objective ai list chr ID */
#define CHR_FREE             -1    /* chr IDs when free'd (killed or removed from level) */
#define CHR_SPAWN_NUM_START  5000  /* default chr num for spawned guards with ai command BD/BE */
#define CHR_CLONED_NUM_START 10000 /* default chr num for cloed guards with ai command C1 */
    /* Special ID for selecting PadPreset in AI list */
#define PAD_PRESET1          9000 /* stored as chr->padpreset1 */

#define GAME_TICKRATE            60
#define OBJECTIVES_MAX           10
#define MAX_CHRWAYPOINTS         6
#define MAX_WAYMODE              ((s32)WAYMODE_MAGIC)
#define MAX_TEXTURES             3001
#define PROPRECORD_STAN_ROOM_LEN 4
#define NUMBER_SHOTGUN_BULLETS   5

#ifdef VERSION_EU
    #define NTSC 0
    #define PAL 1
    #define TICKS_PER_SECOND 50
    #define FRAMES_PER_SECOND 25
#else
    #define NTSC 1
    #define PAL 0
    #define TICKS_PER_SECOND 60
    #define FRAMES_PER_SECOND 30
#endif

#pragma endregion

#define S32_MAX  2147483647
#define U32_MAX  4294967295
#pragma region Inline Macro Functions
#ifndef _MATH_EXT_H_
    #define M_TAU_F               6.2831855f
    #define SECS_TO_TIMER60(SECS) (SECS * GAME_TICKRATE)
    #define MINS_TO_TIMER60(MINS) (SECS_TO_TIMER60(MINS * GAME_TICKRATE))
    /* Gets the byte representation of an angle (degrees) */
    #define DEG2BYTE(DEG)         (char)(256.0f / 360.0f * (DEG))
    /* Gets the byte representation of an angle (radians) */
    #define RAD2BYTE(RAD)         (char)(256.0f / M_TAU_F * (RAD))
    /* Converts an angle from Degrees to Radians */
    #define DegToRad(DEG)         (float)((DEG)*M_TAU_F / 360.0)
    /* Converts and halves an angle from Degrees to Radians */
    #define mDegToHalfRad(x)      ((x * M_PI_F) / 360.0f)
    /* Converts an angle from Radians to Degrees */
    #define RadToDeg(RAD)         (float)((RAD) / M_TAU_F * 360.0f)
    /* Gets the angle in radians represented by a byte */
    #define ByteToRadian(Byte)    ((Byte * M_TAU_F) * (1.0f / 256.0f))
    /*
        Inline Abs function - Not Needed, Compiler does this automatically
    */
    #define ABS_F(val)            (val) < 0 ? (float)(val) + 4294967296.0f /* -1.0f */: (float)(val)
    #define ABS(x)                ((x) < 0 ? -(x) : (x))
#endif
#define getVector(vec, a, b) \
    vec.x = b.x - a.x;       \
    vec.y = b.y - a.y;       \
    vec.z = b.z - a.z
#define getDistanceSquared(vec)             (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)
#define isVectorDistanceLessThan(dist, vec) (dist * dist) <= vec

#define _mkshort(a, b)            ((a << 8) | (b & 0xff))
#define _mkword(a, b)             ((a << 16) | (b & 0xffff))
#define CharArrayTo16(val, index) (                                         val[index+1] | val[index] << 8)
#define CharArrayTo24(val, index) (                     val[index+1] << 8 | val[index+2] | val[index] << 16)
#define CharArrayTo32(val, index) (val[index+1] << 16 | val[index+2] << 8 | val[index+3] | val[index] << 24)
    /* Pad Catagory */
#define isNotBoundPad(pad)        pad < 10000
#define getBoundPadNum(pad)       pad - 10000
#define setBoundPadNum(pad)       pad + 10000
    /* AI Catagory */
#define isGlobalAIListID(ID)      ((ID) <= 1024)
#define isBGAIListID(ID)          ((ID) >= 4096)
#define isChrAIListID(ID)         (!isGlobalAIListID(ID) && !isBGAIListID(ID))
#define setGlobalAIListID(ID)     ((ID) + 0)
#define setChrAIListID(ID)        ((ID) + 1025)
#define setBGAIListID(ID)         ((ID) + 4096)
#define getGlobalAIListID(ID)     ((ID) - 0)
#define getChrAIListID(ID)        ((ID) - 1025)
#define getBGAIListID(ID)         ((ID) - 4096)

    /* language file to slot allocation */
#define getStringID(TEXTBANK, TEXTSLOT) ((TEXTBANK * 0x0400U) + TEXTSLOT)

    /* Image ID to RAM allocation */
#define IMAGESEG(id)             0xABCD0000 | id

/*Doesnt work! might be handy for something else
#define setMask(t)\
      (t) <=   2 ? 1\
    : (t) <=   4 ? 2\
    : (t) <=   8 ? 3\
    : (t) <=  16 ? 4\
    : (t) <=  32 ? 5\
    : (t) <=  64 ? 6\
    : (t) <= 128 ? 7\
    : (t) <= 256 ? 8\
    : (t) <= 512 ? 9\
    : (t) <=1024 ? 10\
    : "TEXTURE TOO BIG (>1024)"*/

    //macros for FILERECORDS
#define SKELETON(NAME)    skeleton_ ## NAME
#define JOINTLIST(NAME)   jointlist_ ## NAME
#define JOINTNAMES(NAME)  jointnames_ ## NAME
#define SWITCHNAMES(NAME) switchnames_ ## NAME

/**
 * Define a New Model Skeleton
 * @param NAME: Name of Skeleton
 * @param SKELSIZE:  -TBC- its not always the skel size
 * @param HASNAMES:  (Optional TRUE/FALSE) Has debug names
 * @param NUMJOINTS: (Optional Integer) Number of Joints
 */
#define New_ModelSkeleton(NAME, SKELSIZE, HASNAMES, NUMJOINTS) \
    ModelSkeleton SKELETON(##NAME##) = {                   \
    IF_ELSE(IS_EMPTY(NUMJOINTS))                           \
    (                                                      \
        sizeof(JOINTLIST(NAME))/sizeof(ModelJoint)         \
    )                                                      \
    (                                                      \
        NUMJOINTS                                          \
    ),                                                     \
    0,                                                     \
    JOINTLIST(##NAME##),                                   \
    SKELSIZE,                                              \
    0                                                      \
    IF(AND(DEFINED(DEBUG), BOOL(HASNAMES)))                \
    (                                                      \
        DEFER(COMMA)() jointnames_##NAME                   \
    )                                                      \
    };

#define MODELSKELETON(NAME, NUMJOINTS, SKELSIZE) ModelSkeleton SKELETON( ## NAME ## ) = {NUMJOINTS, 0, JOINTLIST( ## NAME ## ), SKELSIZE, 0};


/**
 * Define a New Model Header
 * @param NAME:           Name of Model
 * @param SKELETONNAME:   Name of base Skeleton eg standard_object
 * @param BOUNDINGRADIUS: Float Bounding Volume Radius
 * @param NUMSWITCHES:    (Optional Integer) Number of Switches
 * @param HASNAMES:       (Optional TRUE/FALSE) Has debug names
 * @param NUMMATRICES:    (Optional Integer) Number of Matices used *AUTO
 * @param NUMTEXTURES:    (Optional Integer) Number of Textures defined *AUTO
 * @param NUMRECORDS:     (Optional Integer)Number of Records in Model
 * @param SWITCHES:       (Optional Pointer) Pointer to Switch Array (Never Used)
 * @param ROOTNODE:       (Optional Pointer) Pointer to Root Node (Never Used)
 */
#define New_ModelFileHeader(NAME, SKELETONNAME, BOUNDINGRADIUS, NUMSWITCHES, HASNAMES, NUMMATRICES, NUMTEXTURES, NUMRECORDS, SWITCHES, ROOTNODE) \
    ModelFileHeader NAME ## _header = {                                                                                                      \
    IF_ELSE(IS_EMPTY(ROOTNODE))                                                                                                              \
    (                                                                                                                                        \
        0                                                                                                                                    \
    )                                                                                                                                        \
    (                                                                                                                                        \
        ROOTNODE             /* Never Used */                                                                                                \
    ),                                                                                                                                       \
    & ## SKELETON(SKELETONNAME),                                                                                                             \
    IF_ELSE(IS_EMPTY(SWITCHES))                                                                                                              \
    (                                                                                                                                        \
        0                                                                                                                                    \
    )                                                                                                                                        \
    (                                                                                                                                        \
        SWITCHES             /* Never Used */                                                                                                \
    ),                                                                                                                                       \
    IF_ELSE(IS_EMPTY(NUMSWITCHES))                                                                                                           \
    (                                                                                                                                        \
        0                                                                                                                                    \
    )                                                                                                                                        \
    (                                                                                                                                        \
        NUMSWITCHES                                                                                                                          \
    ),                                                                                                                                       \
    IF_ELSE(IS_EMPTY(NUMMATRICES))                                                                                                           \
    (                                                                                                                                        \
        sizeof(JOINTLIST(SKELETONNAME))/sizeof(ModelJoint)                                                                                   \
    )                                                                                                                                        \
    (                                                                                                                                        \
        NUMMATRICES                                                                                                                          \
    ),                                                                                                                                       \
    BOUNDINGRADIUS,                                                                                                                          \
    IF_ELSE(IS_EMPTY(NUMRECORDS))                                                                                                            \
    (                                                                                                                                        \
        0                                                                                                                                    \
    )                                                                                                                                        \
    (                                                                                                                                        \
        NUMRECORDS                                                                                                                           \
    ),                                                                                                                                       \
    IF_ELSE(IS_EMPTY(NUMTEXTURES))                                                                                                           \
    (                                                                                                                                        \
        sizeof(NAME ## _textures)/sizeof(ModelFileTextures)                                                                                  \
    )                                                                                                                                        \
    (                                                                                                                                        \
        NUMTEXTURES                                                                                                                          \
    ),                                                                                                                                       \
    0                     /* Texture Pointer Always null */                                                                                  \
    IF(AND(DEFINED(DEBUG), BOOL(HASNAMES)))                                                                                                  \
    (                                                                                                                                        \
        DEFER(COMMA)() switchnames_##NAME                                                                                                    \
    )                                                                                                                                        \
    IF(NOT(DEFINED(VERSION_EU)))                                                                                                             \
    (                                                                                                                                        \
        DEFER(COMMA)() FALSE /* isLoaded Always FALSE */                                                                                     \
    )                                                                                                                                        \
    };

#if defined(VERSION_EU)
#define MODELFILEHEADER(NAME, ROOTNODE, SKELETON, SWITCHES, NUMSWITCHES, NUMMATRICES, BOUNDINGRADIUS, NUMRECORDS, NUMTEXTURES) struct ModelFileHeader NAME ## _header = {ROOTNODE, SKELETON, SWITCHES, NUMSWITCHES, NUMMATRICES, BOUNDINGRADIUS, NUMRECORDS, NUMTEXTURES, 0};
#else
#define MODELFILEHEADER(NAME, ROOTNODE, SKELETON, SWITCHES, NUMSWITCHES, NUMMATRICES, BOUNDINGRADIUS, NUMRECORDS, NUMTEXTURES) struct ModelFileHeader NAME ## _header = {ROOTNODE, SKELETON, SWITCHES, NUMSWITCHES, NUMMATRICES, BOUNDINGRADIUS, NUMRECORDS, NUMTEXTURES, 0, 0};
#endif

#define CHRFILERECORD(NAME, SCALE, OFFSET, HASHEAD, ISMALE) \
    {&##NAME##_header, STR(C##NAME##Z), SCALE, OFFSET, HASHEAD, ISMALE},

#define GUNSTATS(NAME) & ## NAME ## _stats
#define GUNFILERECORD(NAME, NOMODEL, STATS, UPPERTEXTID, LOWERTEXTID, POSX, POSY, POSZ, XROT, YROT, WOCTEXT, EQUIPTEXT, EQUIPX, EQUIPY, EQUIPZ) \
    { & ## NAME ## _header,STR(G## NAME ##Z), NOMODEL, STATS, UPPERTEXTID, LOWERTEXTID, POSX, POSY, POSZ, XROT, YROT, WOCTEXT, EQUIPTEXT, EQUIPX, EQUIPY, EQUIPZ},
#define SUIT_LFRECORD(NAME, NOMODEL, STATS, UPPERTEXTID, LOWERTEXTID, POSX, POSY, POSZ, XROT, YROT, WOCTEXT, EQUIPTEXT, EQUIPX, EQUIPY, EQUIPZ) \
    { & ## NAME ## _header,STR(C## NAME ##Z), NOMODEL, STATS, UPPERTEXTID, LOWERTEXTID, POSX, POSY, POSZ, XROT, YROT, WOCTEXT, EQUIPTEXT, EQUIPX, EQUIPY, EQUIPZ},
/**
 * Define a New Item Record
 * @param NAME:  Name of Model
 * @param SCALE: (Optional float) Scale of Model
 */
#define PROPFILERECORD(NAME, SCALE)        \
    {&NAME ## _header, STR(P ## NAME ##Z), \
    IF_ELSE(IS_EMPTY(SCALE))               \
    (                                      \
        0.1                                \
    )                                      \
    (                                      \
        SCALE                              \
    )                                      \
},

#define forever for (;;)

#define ARRAYCOUNT(a) (s32)(sizeof(a) / sizeof(a[0]))
#define ALIGN8(val)         (((val) + 0x7 | 0x7) ^ 0x7)
#define RANDOMFRAC() ((f32) randomGetNext() * 2.3283064e-10f)
#define MAXFLOAT ((float)3.40282346638528860e+38)

#define HUDHALIGN_RIGHT  0
#define HUDHALIGN_LEFT   1
#define HUDHALIGN_MIDDLE 2

#define HUDVALIGN_BOTTOM 0
#define HUDVALIGN_TOP    1
#define HUDVALIGN_MIDDLE 2

#pragma endregion

#endif

