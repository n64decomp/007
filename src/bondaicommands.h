

/*
==============================================================================
//# AI Lists and Commands
//## Programmed by Mark Edmonds
==============================================================================

 AI lists are responsible for all character programming and much of the logic
 used in each stage. Without AI lists guards would not talk, move, or even
 respond to you.

 Each character has an AI list assigned to it. An AI list is a list of commands
 for characters to follow. Commands could be things like go to a certain room,
 shoot the player or say something. AI lists also contain if-statements, so it
 may for example check if the player is in sight then jump to a different part
 of the AI list if so.

 In some cases AI lists are assigned to objects as well (Dam truck, the
 runway plane and Cradle helicopter). Some AI lists, such as those
 which implement general level logic, are run automatically for the duration
 of the level without being assigned to a character or object.

 There are 17 "global" AI lists. These global AI lists handle common tasks such
 as generic combat, patrolling and sitting idle in a chair. They are available
 to use in any stage. The rest of the AI lists are specific to each stage and
 can only be used by that stage.

 Under the hood, AI in GoldenEye and Perfect Dark use a Symbolic Language
 (similar to Bytecode/Pcode) with a 1 or 2 byte "Command" followed by a variable
 length array of parameters.
 At run-time, a small "interpreter" - ai() scans over the code and runs
 the subroutine identified by the instruction - also known as a "branch table".
 However, All these details are abstracted away via meaningful C macros.

==============================================================================
//###Terminology:
 chr              Character
 BG               Background
 Entiry           Character or Object that can use an AI list (like guards and
                  Trucks)
 GAIList          Global List
 Global AI Lists  0000-0011 range
 Chr AI Lists     0401-04FF range
 BG AI Lists      1000-10FF range

==============================================================================

//## IDs and Naming
#############################

 Every AI list has a unique ID. These IDs are required so AI lists can
 reference other AI lists, such as assigning a different one. The IDs also
 determine what type of AI list it is and if/when it's started automatically
 depending on what range the ID falls into.

//### Global AI List info
==============================================================================
 Global AI lists can be assigned as the initial AI list for characters or
 assigned manually by other AI lists. They are not started automatically.
 Global AI lists can be referenced using constants such as GAILIST_AIM_AT_BOND

//### Entity AI List info
==============================================================================
 These are similar to global AI lists, but they are specific to individual
 stages. They are defined in each stage's setup file and use constants such
 as AILIST_SCIENTIST (no G prefix). They do not run automatically; they must
 be assigned as the initial function for an Entity or invoked by another
 function.
 Multiple Entities can use the same AI List - each Entity is treated as an
 independent thread with their own instance of unique data.

//### Background AI List info
==============================================================================
 AI lists in this range will be started automatically when the stage is
 started using gameplay (but not run when using the cinema menu). They are
 commonly used for overarching stage logic that isn't specific to a character,
 such as monitoring objectives, or waiting for the player to enter a room then
 triggering a radio message.
 BG AI Lists cannot run Entity commands due to the lack of level presence.
 Attempting to do so will crash the game.

//## AI Commands
######################

 //### AI commands with CHR_NUM argument
==============================================================================
 Most commands with "chr" in the name use a CHR_NUM argument. For the most
 part, this can be used with any loaded chr number and it will work fine.
 There is however one exception to this and that is the special CHR_XXX ID :
 CHR_BOND_CINEMA.
 This ID only works when bond has a third person model assigned (intro/exit
 cutscene).
 Only use CHR_BOND_CINEMA for intro/exit cutscene specific logic

//### Vehicle/aircraft AI command
==============================================================================
 Commands with a vehicle/aircraft prefix can only be executed by
 vehicle/aircraft objects. These types of objects do not use a chr struct.
 Most non-vehicle commands will crash if they try to access caller's
 chr struct

//### AI commands with label argument
==============================================================================
 Most commands will have a label argument in their function description. This
 is used when a command has a false/true state. For example, the jog to bond
 command (28) has goto label argument. When the command is executed, it will
 check if the guard is able to jog to bond. If for some reason the command
 fails (bond is unreachable/guard is dying/etc) then the command will not
 goto label and the next command will be executed. The most common use of
 commands with goto labels are jumping out of an infinite loop - for an
 example check global AI List GAILIST_STARTLE_AND_RUN_TO_BOND

 //### Yielding
==============================================================================
 When rendering a frame, the engine needs to iterate all characters and allow
 each of them to process a bit of their AI list. They can't process the list
 for too long or the engine will not be able to produce a frame in time and
 will cause frame lag. But it's also not desirable to give each AI list a
 fixed amount of CPU time before pausing it for the next frame, because then
 the state of the game may change between any two commands which would
 introduce bugs.
 Instead, each AI list is able to choose when to pause and yield control back
 to the game engine. This is done using the yield command. When yielding, the
 AI list is declaring that it's done for this frame. The game engine will
 continue the AI list from the next command in a later frame.
 Any time there's a loop, there must be a yield inside it otherwise the game
 would soft lock. Yields should also be done around relatively CPU heavy
 operations such as when spawning characters in bulk.

//### Labels, If Statements and Loops
==============================================================================
 AI lists lack native language constructs such as if/else/endif and while
 loops, however they do have primitive if/goto statements which can be used to
 achieve the same effect, albeit with less readable code.

 The primitive building blocks are:

     Labels: A label is a marker in the AI list. It is given a number so it can
             be identified. This number should be unique if it marks the start
             of a while loop. If it's the destination of an if statement then it
             can be a reused number.

     Goto Next: Jumps to the next label with the given ID.

     Goto First: Jumps to the first label in the AI list with the given ID. These
                 are used for loops.

 IF statements: Many commands will check for a condition then jump to the next
                label with the given ID if the condition passes. If the
                condition fails execution continues from the next command as
                normal.

 TRY statements: These commands make the character attempt to do something and
                 then go to the label if successful, otherwise execution
                 continues from the next command. An example is pathfinding;
                 if the character can't find a path to the destination then it
                 will fail.

 This project provides some macros to help give some structure to the AI lists:

    DO: Is just the same as declaring a label followed by yield.

    LOOP: Is literally just a GotoFirst, but LOOP was a more meaningful name
          given the intention.

    CONTINUE: Used when a loop has multiple points that jump back to the top of
              the loop. Like LOOP, it's also the same as a GotoFirst but with a
              more meaningful name.

    BREAK: Used then we want to exit a loop, the lable given should be below as
           this is literally a GotoNext but with a more meaningful name.

//### Co-Ordinate System
==============================================================================

 The N64 uses the right-handed coordinate system as do most others.
 In the right-handed system, the Z axis points out toward the viewer.
 However, The view coordinate system puts the view (camera) at the point of
 origin and places the direction of the view along the Z-axis. This means X
 "points left" according to Bond and other Entities.
 This is also known as North-counterclockwise convention.

 GE will also turn Negative angles into positive angles for AI
 so -90 becomes 270.

     Ortho View
                    90 Y+. Azimuth
                        /|\
                      .''|''
                     '   |
                    -    |
                   .     |
                         |  S  180
                  E 270  |  /
                      '-.|/`
                -      /' '''--..
                .    /'          ''--..     .
              0 .  /'                  ''--:.`.
                ./`                       :----' X+ W 90
            |'-.`
            |    `-
         Z+ '''''''' N 0


     10x10 Grid showing angles at distance from origin (Chr)

       45  39  31  22  11 ^ 349 338 329 321 315
       51  45  37  27  14 0 346 333 323 315 309
       59  53  45  34  18 | 342 326 315 307 301
       68  63  56  45  27 | 333 315 304 297 292
       79  76  72  63  45 | 315 297 288 284 281
       90 <-------------------------------- -90
      101 104 108 117 135 | 225 243 252 256 259
      112 117 124 135 154 | 206 225 236 243 248
      121 127 135 146 162 1 198 214 225 233 239
      129 135 143 154 166 8 194 206 217 225 231
      135 141 149 158 169 0 191 202 211 219 225


 Calling Angle Commands such as AngleToBondGreaterThan will therefore accept
 angles in a Counter-Clockwise rotation from 0 to 360 (or 0 - 6.28 Radian)

 ===========================================================================
*/

#ifndef _BONDAICOMMANDS_H_
#define _BONDAICOMMANDS_H_
#include <ultra64.h>



// Reverse endieness, to write things like 0x700 to be translated into 0x00, 0x07.
// This is not compatible with aicommands2.h
#define CharArrayFrom16Rev(input) (input) & 0x00FF, ((input) & 0xFF00) >> 8
#define CharArrayFrom24Rev(input) (input) & 0x0000FF, ((input) & 0x00FF00) >> 8, ((input) & 0xFF0000) >> 16
#define CharArrayFrom32Rev(input) (input) & 0x000000FF, ((input) & 0x0000FF00) >> 8, ((input) & 0x00FF0000) >> 16, ((input) & 0xFF000000) >> 24


 // "standard" aicommands2.h definition
#define CharArrayFrom16(input) ((input) & 0xFF00) >> 8, (input) & 0x00FF
#define CharArrayFrom24(input) ((input) & 0xFF0000) >> 16, ((input) & 0x00FF00) >> 8, (input) & 0x0000FF
#define CharArrayFrom32(input) ((input) & 0xFF000000) >> 24, ((input) & 0x00FF0000) >> 16, ((input) & 0x0000FF00) >> 8, (input) & 0x000000FF

#define AI_LIST_GLOBAL_START 0x0000
#define AI_LIST_CHR_START 0x0401
#define AI_LIST_OBJ_START 0x1000

// Print Helpful Compile-time error messages
#if defined(__INTELLISENSE__)
#    define AI_ERR_SUB (GAILIST_DEAD_AI)
#    define AI_ERR_NOTSUB (GAILIST_DEAD_AI)
#    define AI_ERR_NOTCHR (GAILIST_DEAD_AI)
#    define AI_ERR_NO_THIS 1
#else
#    define AI_ERR_SUB (('E','R','R','O','R',':',' ','A','I','_','L','I','S','T',' ','I','S',' ','A',' ','S','U','B','R','O','U','T','I','N','E',' ','O','R',' ','N','O','T',' ','F','O','R',' ','C','H','R'), 1)
#    define AI_ERR_NOTSUB (('E','R','R','O','R',':',' ','A','I','_','L','I','S','T',' ','N','O','T',' ','A',' ','S','U','B','R','O','U','T','I','N','E',' ','O','R',' ','N','O','T',' ','F','O','R',' ','C','H','R'), 1)
#    define AI_ERR_NOTCHR (('E','R','R','O','R',':',' ','A','I','_','L','I','S','T',' ','N','O','T',' ','F','O','R',' ','C','H','R'), 1)
#    define AI_ERR_NO_THIS ((('E','R','R','O','R',':',' ','C','a','n','n','o','t',' ','C','a','l','l',' ','A','I','_','L','I','S','T',' ','w','i','t','h','o','u','t',' ','d','e','f','i','n','i','n','g',' ','T','H','I','S',' ','f','o','r',' ','r','e','t','u','r','n'),1))\

#endif


/*=============================================================================
// global ai lists - gailists
//===========================================================================*/

/**
 * Is the called AI List a subroutine (will it return)
 * Per Setup Subroutines should be added to SETUPSUBROUTINES at the top of the
 * setup.
 * eg
 * #define SETUPSUBROUTINES(ID) (ID == ACTIVATE_OBJECT) |\
 */
#define isSubroutine(ID) ((ID == GAILIST_PLAY_IDLE_ANIMATION) |\
                            (ID == GAILIST_BASH_KEYBOARD) | \
                            (ID == GAILIST_ATTACK_BOND) | \
                            (ID == GAILIST_RUN_TO_BOND) | \
                            (ID == GAILIST_STARTLE_AND_RUN_TO_BOND) | \
                            (ID == GAILIST_WAIT_ONE_SECOND) \
                            IF(NOT(DEFINED(SETUPSUBROUTINES(ID))))\
                            (\
                                | SETUPSUBROUTINES(ID)\
                            ))\


typedef enum GAILISTID
{
    /**
      Try aiming at bond, otherwise do nothing
      @return No Return - AI List can only be changed by a 3rd party via SetChrAiList
     */
    GAILIST_AIM_AT_BOND,

    /**
      Dead or Removed AI.
      Use when AI has no more to do (or use YIELD_FOREVER)
      @return No Return - AI List can only be changed by a 3rd party via SetChrAiList
    */
    GAILIST_DEAD_AI,

    /**
      Stand Guard and Kill Time or patrol (Not typicaly used for patrolling).
      While killing time, play Idle animations
      On detecting Bond, Send a clone OR Run to Bond and Attack.
      This AI List is used by nearly all guards either as default or as a result
      of detecting Bond or finnishing their assigned behaivior.
      @return No Return - AI List can only be changed by a 3rd party via SetChrAiList
     */
    GAILIST_STANDARD_GUARD,

    /**
      Play one random idle animation
      @return to caller if called with CALL
      -or-
      return to List set by SetReturnAiList - If not set will crash
     */
    GAILIST_PLAY_IDLE_ANIMATION,

    /**
      Bash that Keyboard once with a random animation
      @return to caller if called with CALL
      -or-
      return to List set by SetReturnAiList - If not set will crash
     */
    GAILIST_BASH_KEYBOARD,

    /**
      Stand Guard Statically (No Clones, No animations) or patrol.
      On detecting Bond (sight/near-miss only), Act like a Standard Guard.
      @return to Standard Guard
     */
    GAILIST_SIMPLE_GUARD_DEAF,

    /**
      Attack Bond once via 1 random animation
      @return to caller if called with CALL
      -or-
      return to List set by SetReturnAiList - If not set will crash
     */
    GAILIST_ATTACK_BOND,

    /**
      Stand Guard Statically (No Clones, No animations) or patrol (Typical use of this type).
      On detecting Bond, Act like a Standard Guard.
      @return to Standard Guard
     */
    GAILIST_SIMPLE_GUARD,

    /**
      Run to bond and fire if seen, otherwise wait.
      @return to caller if called with CALL
      -or-
      return to List set by SetReturnAiList - If not set will crash
     */
    GAILIST_RUN_TO_BOND,

    /**
      Stand Guard Statically (No Clones, No animations) or patrol.
      On detecting Bond, Run to padpreset1 and activate alarm.
      Act like a Standard Guard thereafter
      @return to Standard Guard
     */
    GAILIST_SIMPLE_GUARD_ALARM_RAISER,

    /**
      Startle character then Run To Bond
      @return to caller if called with CALL
      -or-
      return to List set by SetReturnAiList - If not set will crash
     */
    GAILIST_STARTLE_AND_RUN_TO_BOND,

     /**
      If Calling Chr NOT been seen, Send Clone after Bond, otherwise Act like a
      Standard Guard
      @return to Standard Guard
     */
    GAILIST_TRY_CLONE_SEND_OR_RUN_TO_BOND,

    /**
      Run to bond then act like a Standard Guard
      @return to Standard Guard
     */
    GAILIST_STANDARD_CLONE,

    /**
       Persistently chase Bond and Attack (halt randomly)
       @return No Return - AI List can only be changed by a 3rd party via SetChrAiList
     */
    GAILIST_PERSISTENTLY_CHASE_AND_ATTACK_BOND,

    /**
      Wait for one second then return
      @return to caller if called with CALL -or- return to List set by SetReturnAiList - If not set will crash
     */
    GAILIST_WAIT_ONE_SECOND,

    /**
      Exit level and set BG AI to nothing
      @return No Return - AI is Dead
     */
    GAILIST_END_LEVEL,

    /**
      Draw TT33, Aim and fire.
      Act like a Standard Guard thereafter
      @return to Standard Guard
     */
    GAILIST_DRAW_TT33_AND_ATTCK_BOND,

    /**
      Remove Calling chr and set AI to nothing
      @return No Return - AI is dead
     */
    GAILIST_REMOVE_CHR
} GAILISTID;


/*===========================================================================*/

/*=============================================================================
## command bitfield flags and common settings
//===========================================================================*/

// command 0A - animation flags
#define ANIM_MIRROR                     0x01 /* Mirror animation*/
#define ANIM_UNKNOWN                    0x02 /* ?? (cancels no translation flag)*/
#define ANIM_LOOP_HOLD_LAST_FRAME       0x04 /* Loop/hold last frame (required for reverse flag)*/
#define ANIM_PLAY_SFX                   0x08 /* Play sneeze sfx with animation 9f (triggers 50% of the time)*/
#define ANIM_IDLE_POSE_WHEN_COMPLETE    0x10 /* Idle pose after animation has completed (does not work with looping animations)*/
#define ANIM_TRANSLATION_SCALE_4X       0x20 /* Translation scale multiplier x4 (used for dam and cradle cinema)*/
#define ANIM_NO_TRANSLATION             0x40 /* No translation*/
#define ANIM_REVERSE_LOOPING_ANIMATION  0x80 /* Reverse animation (only for looped animations)*/

#define ANIM_DEFAULT_INTERPOLATION      0x10 /* Use this if interpolation value isn't important*/

// command 14/15/16/17 - target flags
#define TARGET_BOND                     0x0001 /* Set target to bond (ignores target argument)*/
#define TARGET_FRONT_OF_CHR             0x0002 /* Set target to front of chr*/
#define TARGET_CHR                      0x0004 /* Set target type to chr_num*/
#define TARGET_PAD                      0x0008 /* Set target type to pad*/
#define TARGET_COMPASS                  0x0010 /* Set target to compass direction (hex) N: 0000 E: C000 S: 8000: W: 4000*/
#define TARGET_AIM_ONLY                 0x0020 /* Aim at target instead of firing*/
#define TARGET_DONTTURN                 0x0040 /* Limits target to 180 degrees in front of guard (cannot be used with TARGET_BOND flag)*/

// command 18/19 - target body part values
typedef enum HITTARGET
{
    HIT_NULL_PART,          /* Null part, no reaction - 1x damage*/
    HIT_LEFT_FOOT,          /* Left foot              - 1x damage*/
    HIT_LEFT_LEG,           /* Left leg               - 1x damage*/
    HIT_LEFT_THIGH,         /* Left thigh             - 1x damage*/
    HIT_RIGHT_FOOT,         /* Right foot             - 1x damage*/
    HIT_RIGHT_LEG,          /* Right leg              - 1x damage*/
    HIT_RIGHT_THIGH,        /* Right thigh            - 1x damage*/
    HIT_PELVIS,             /* Pelvis                 - 1x damage*/
    HIT_HEAD,               /* Head                   - 4x damage*/
    HIT_LEFT_HAND,          /* Left hand              - 1x damage*/
    HIT_LEFT_ARM,           /* Left arm               - 1x damage*/
    HIT_LEFT_SHOULDER,      /* Left shoulder          - 1x damage*/
    HIT_RIGHT_HAND,         /* Right hand             - 1x damage*/
    HIT_RIGHT_ARM,          /* Right arm              - 1x damage*/
    HIT_RIGHT_SHOULDER,     /* Right shoulder         - 1x damage*/
    HIT_CHEST,              /* Chest                  - 2x damage*/
    HIT_GUN         = 0x64, /* GUN                    - 0x damage*/
    HIT_HAT         = 0x6E, /* HAT                    - 0x damage*/
    HIT_GENERAL     = 0xC8,
    HIT_GENERALHALF = 0xC9
} HITTARGET;

// command 68 - door states
#define AI_DOOR_STATE_CLOSED               0x01 /* Closed*/
#define AI_DOOR_STATE_OPEN                 0x02 /* Opened*/
#define AI_DOOR_STATE_CLOSING              0x04 /* Closing*/
#define AI_DOOR_STATE_OPENING              0x08 /* Opening*/

// command BD/BE - spawn flags
#define SPAWN_SUNGLASSES                0x00000001 /* Sunglasses*/
#define SPAWN_SUNGLASSES_RANDOM         0x00000002 /* Sunglasses (random, 50% of the time)*/
#define SPAWN_00000004                  0x00000004 /* Unknown*/
#define SPAWN_00000008                  0x00000008 /* unknown*/
#define SPAWN_IGNORE_PAD_SIGHT_CHECK    0x00000010 /* Ignore check for pad within view (force spawn)*/
#define SPAWN_00000020                  0x00000020 /* unknown*/
#define SPAWN_00000040                  0x00000040 /* unknown*/
#define SPAWN_00000080                  0x00000080 /* unknown*/
#define SPAWN_00000100                  0x00000100 /* unknown*/
#define SPAWN_00000200                  0x00000200 /* unknown*/
#define SPAWN_00000400                  0x00000400 /* unknown*/
#define SPAWN_00000800                  0x00000800 /* unknown*/
#define SPAWN_00001000                  0x00001000 /* unknown*/
#define SPAWN_00002000                  0x00002000 /* unknown*/
#define SPAWN_00004000                  0x00004000 /* unknown*/
#define SPAWN_00008000                  0x00008000 /* unknown*/
#define SPAWN_00010000                  0x00010000 /* unknown*/
#define SPAWN_00020000                  0x00020000 /* unknown*/
#define SPAWN_00040000                  0x00040000 /* unknown*/
#define SPAWN_00080000                  0x00080000 /* unknown*/
#define SPAWN_00100000                  0x00100000 /* unknown*/
#define SPAWN_00200000                  0x00200000 /* unknown*/
#define SPAWN_00400000                  0x00400000 /* unknown*/
#define SPAWN_00800000                  0x00800000 /* unknown*/
#define SPAWN_01000000                  0x01000000 /* unknown*/
#define SPAWN_02000000                  0x02000000 /* unknown*/
#define SPAWN_04000000                  0x04000000 /* unknown*/
#define SPAWN_08000000                  0x08000000 /* unknown*/
#define SPAWN_10000000                  0x10000000 /* unknown*/
#define SPAWN_20000000                  0x20000000 /* unknown*/
#define SPAWN_40000000                  0x40000000 /* unknown*/
#define SPAWN_80000000                  0x80000000 /* unknown*/

// command D7 - hud flags
#define HUD_HIDE_ALL                    0x00 /* Hide all*/
#define HUD_SHOW_TEXT_TOP               0x01 /* Don't hide top text*/
#define HUD_SHOW_TEXT_BOTTOM            0x02 /* Don't hide bottom text*/
#define HUD_SHOW_HUD_COUNTDOWN          0x04 /* Don't hide hud countdown*/

/*===========================================================================*/

/**
   Simple Switch Statement.
   Test should separate Command from value.
   Empty Test is equivelant to a switch default:.
   Limited to 16 cases.
   Format: SWITCH(VARIABLE_TO_TEST,
                  TEST_COMMAND, TEST_VALUE,
                      CASE_CONTENT,...)
 */
#define SWITCH(VAR, \
               CASE0, CASE_VAL0, CASE_CONTENT0,\
               CASE1, CASE_VAL1, CASE_CONTENT1,\
               CASE2, CASE_VAL2, CASE_CONTENT2,\
               CASE3, CASE_VAL3, CASE_CONTENT3,\
               CASE4, CASE_VAL4, CASE_CONTENT4,\
               CASE5, CASE_VAL5, CASE_CONTENT5,\
               CASE6, CASE_VAL6, CASE_CONTENT6,\
               CASE7, CASE_VAL7, CASE_CONTENT7,\
               CASE8, CASE_VAL8, CASE_CONTENT8,\
               CASE9, CASE_VAL9, CASE_CONTENT9,\
               CASEA, CASE_VALA, CASE_CONTENTA,\
               CASEB, CASE_VALB, CASE_CONTENTB,\
               CASEC, CASE_VALC, CASE_CONTENTC,\
               CASED, CASE_VALD, CASE_CONTENTD,\
               CASEE, CASE_VALE, CASE_CONTENTE,\
               CASEF, CASE_VALF, CASE_CONTENTF)\
VAR \
IF_VA(NOT(IS_EMPTY(CASEF)))(0}; Error: Switch Limited to 15 elements + 1 default                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            \
                                     /*This is here to stop the spread of errors*/u8 CASEF[] = {)\
IF_VA(NOT(IS_EMPTY(CASE_CONTENTF)))(                                                    CASEE (CASE_VALE,lblNext) EXPAND_ARGS_STACK(CASE_CONTENTF)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENTE)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENTF)))(Label(lblNext)) CASED (CASE_VALD,lblNext) EXPAND_ARGS_STACK(CASE_CONTENTE)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENTD)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENTE)))(Label(lblNext)) CASEC (CASE_VALC,lblNext) EXPAND_ARGS_STACK(CASE_CONTENTD)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENTC)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENTD)))(Label(lblNext)) CASEB (CASE_VALB,lblNext) EXPAND_ARGS_STACK(CASE_CONTENTC)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENTB)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENTC)))(Label(lblNext)) CASEA (CASE_VALA,lblNext) EXPAND_ARGS_STACK(CASE_CONTENTB)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENTA)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENTB)))(Label(lblNext)) CASE9 (CASE_VAL9,lblNext) EXPAND_ARGS_STACK(CASE_CONTENTA)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT9)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENTA)))(Label(lblNext)) CASE8 (CASE_VAL8,lblNext) EXPAND_ARGS_STACK(CASE_CONTENT9)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT8)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENT9)))(Label(lblNext)) CASE7 (CASE_VAL7,lblNext) EXPAND_ARGS_STACK(CASE_CONTENT8)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT7)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENT8)))(Label(lblNext)) CASE6 (CASE_VAL6,lblNext) EXPAND_ARGS_STACK(CASE_CONTENT7)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT6)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENT7)))(Label(lblNext)) CASE5 (CASE_VAL5,lblNext) EXPAND_ARGS_STACK(CASE_CONTENT6)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT5)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENT6)))(Label(lblNext)) CASE4 (CASE_VAL4,lblNext) EXPAND_ARGS_STACK(CASE_CONTENT5)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT4)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENT5)))(Label(lblNext)) CASE3 (CASE_VAL3,lblNext) EXPAND_ARGS_STACK(CASE_CONTENT4)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT3)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENT4)))(Label(lblNext)) CASE2 (CASE_VAL2,lblNext) EXPAND_ARGS_STACK(CASE_CONTENT3)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT2)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENT3)))(Label(lblNext)) CASE1 (CASE_VAL1,lblNext) EXPAND_ARGS_STACK(CASE_CONTENT2)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT1)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENT2)))(Label(lblNext)) CASE0 (CASE_VAL0,lblNext) EXPAND_ARGS_STACK(CASE_CONTENT1)(lblDone))\
IF_VA(NOT(IS_EMPTY(CASE_CONTENT0)))(IF_VA(NOT(IS_EMPTY(CASE_CONTENT1)))(Label(lblNext))                           EXPAND_ARGS_STACK(CASE_CONTENT0)(lblDone) \
Label(lblDone))

 /**
   Simple AND Statement.
   Test should separate Command from value.
   Empty Test is equivelant to a switch default:.
   Limited to 16 compares.
   Format: AND(Fail_Label,
                  TEST_COMMAND, TEST_VALUE,
                  TEST_COMMAND, TEST_VALUE,...)
                do stuff
            Label(FAIL)
                do stuff
 */
#define AND(FAIL_LBL,\
               CASE0, CASE_VAL0, \
               CASE1, CASE_VAL1, \
               CASE2, CASE_VAL2, \
               CASE3, CASE_VAL3, \
               CASE4, CASE_VAL4, \
               CASE5, CASE_VAL5, \
               CASE6, CASE_VAL6, \
               CASE7, CASE_VAL7, \
               CASE8, CASE_VAL8, \
               CASE9, CASE_VAL9, \
               CASEA, CASE_VALA, \
               CASEB, CASE_VALB, \
               CASEC, CASE_VALC, \
               CASED, CASE_VALD, \
               CASEE, CASE_VALE, \
               CASEF, CASE_VALF)\
IF_VA(NOT(IS_EMPTY(CASEF)))(0}; Error: And Limited to 15 elements                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            \
                                     /*This is here to stop the spread of errors*/  u8 CASEF[] = {)\
IF_VA(NOT(IS_EMPTY(CASE_VALF)))(                                                    CASEE (CASE_VALE,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VALE)))(IF_VA(NOT(IS_EMPTY(CASE_VALF)))(BREAK(FAIL_LBL) Label(lblNext)) CASED (CASE_VALD,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VALD)))(IF_VA(NOT(IS_EMPTY(CASE_VALE)))(BREAK(FAIL_LBL) Label(lblNext)) CASEC (CASE_VALC,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VALC)))(IF_VA(NOT(IS_EMPTY(CASE_VALD)))(BREAK(FAIL_LBL) Label(lblNext)) CASEB (CASE_VALB,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VALB)))(IF_VA(NOT(IS_EMPTY(CASE_VALC)))(BREAK(FAIL_LBL) Label(lblNext)) CASEA (CASE_VALA,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VALA)))(IF_VA(NOT(IS_EMPTY(CASE_VALB)))(BREAK(FAIL_LBL) Label(lblNext)) CASE9 (CASE_VAL9,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL9)))(IF_VA(NOT(IS_EMPTY(CASE_VALA)))(BREAK(FAIL_LBL) Label(lblNext)) CASE8 (CASE_VAL8,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL8)))(IF_VA(NOT(IS_EMPTY(CASE_VAL9)))(BREAK(FAIL_LBL) Label(lblNext)) CASE7 (CASE_VAL7,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL7)))(IF_VA(NOT(IS_EMPTY(CASE_VAL8)))(BREAK(FAIL_LBL) Label(lblNext)) CASE6 (CASE_VAL6,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL6)))(IF_VA(NOT(IS_EMPTY(CASE_VAL7)))(BREAK(FAIL_LBL) Label(lblNext)) CASE5 (CASE_VAL5,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL5)))(IF_VA(NOT(IS_EMPTY(CASE_VAL6)))(BREAK(FAIL_LBL) Label(lblNext)) CASE4 (CASE_VAL4,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL4)))(IF_VA(NOT(IS_EMPTY(CASE_VAL5)))(BREAK(FAIL_LBL) Label(lblNext)) CASE3 (CASE_VAL3,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL3)))(IF_VA(NOT(IS_EMPTY(CASE_VAL4)))(BREAK(FAIL_LBL) Label(lblNext)) CASE2 (CASE_VAL2,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL2)))(IF_VA(NOT(IS_EMPTY(CASE_VAL3)))(BREAK(FAIL_LBL) Label(lblNext)) CASE1 (CASE_VAL1,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL1)))(IF_VA(NOT(IS_EMPTY(CASE_VAL2)))(BREAK(FAIL_LBL) Label(lblNext)) CASE0 (CASE_VAL0,lblNext) )\
IF_VA(NOT(IS_EMPTY(CASE_VAL0)))(IF_VA(NOT(IS_EMPTY(CASE_VAL1)))(BREAK(FAIL_LBL) Label(lblNext))                           )

#include "aicommands2.h"

#if 1


/*=============================================================================
// ai commands macros and information
//=============================================================================
// name and description per command, please read carefully when creating new
// ai lists. ensure that you don't cause loops without a ai_sleep command or else
// command parser will never release and game will softlock
//===========================================================================*/

/*=============================================================================
// name: goto_next
// command id: 00
// info: goto the next label (command 02) - skips all commands between command
//       and goto label - continues executing after found label
//===========================================================================*/
#define goto_next_ID 0x00
#define goto_next_LENGTH 0x02
#define goto_next(label) \
        goto_next_ID, \
        label,

/*=============================================================================
// name: goto_first
// command id: 01
// info: like goto_next, but it starts scanning label from start of list
//===========================================================================*/
#define goto_first_ID 0x01
#define goto_first_LENGTH 0x02
#define goto_first(label) \
        goto_first_ID, \
        label,

/*=============================================================================
// name: label
// command id: 02
// info: label marker for ai list - used for all commands that return true
//===========================================================================*/
#define label_ID 0x02
#define label_LENGTH 0x02
#define label(id) \
        label_ID, \
        id,

/*=============================================================================
// name: ai_sleep
// command id: 03
// info: halt the ai list - frees engine to start executing next ai list until
//       all lists have been executed for game tick.
//=============================================================================
// note: offscreen/idle guards will take 14 game ticks instead of 1 tick on ai_sleep
//===========================================================================*/
#define ai_sleep_ID 0x03
#define ai_sleep_LENGTH 0x01
#define ai_sleep \
        ai_sleep_ID,

/*=============================================================================
// name: ai_list_end
// command id: 04
// info: used for ai list parser to check when list ends
//=============================================================================
// note: not recommended to execute this command - to finish a list create an
// infinite loop (goto_loop_infinite) or jump to GAILIST_DEAD_AI when list has
// finished tasks
//===========================================================================*/
#define ai_list_end_ID 0x04
#define ai_list_end_LENGTH 0x01
#define ai_list_end \
        ai_list_end_ID

/*=============================================================================
// name: jump_to_ai_list
// command id: 05
// info: set chr num's current ai list program counter to beginning of a list
//=============================================================================
// note: not recommended to goto an obj list (10XX)
//===========================================================================*/
#define jump_to_ai_list_ID 0x05
#define jump_to_ai_list_LENGTH 0x04
#define jump_to_ai_list(chr_num, ai_list) \
        jump_to_ai_list_ID, \
        chr_num, \
        CharArrayFrom16Rev(ai_list),

/*=============================================================================
// name: set_return_ai_list
// command id: 06
// info: store a list ptr in current chr struct - used for command 07 return
//=============================================================================
// note: not recommended to set stored list to an obj list (10XX)
//===========================================================================*/
#define set_return_ai_list_ID 0x06
#define set_return_ai_list_LENGTH 0x03
#define set_return_ai_list(ai_list) \
        set_return_ai_list_ID, \
        CharArrayFrom16Rev(ai_list),

/*=============================================================================
// name: jump_to_return_ai_list
// command id: 07
// info: jump the return ai list set in chr struct - pointer set by command 06.
//       used for subroutine lists. if list pointer isn't set, game will crash
//=============================================================================
// note: after return, set chr->aioffset to top of ai list
//===========================================================================*/
#define jump_to_return_ai_list_ID 0x07
#define jump_to_return_ai_list_LENGTH 0x01
#define jump_to_return_ai_list \
        jump_to_return_ai_list_ID,

/*=============================================================================
// name: guard_animation_stop
// command id: 08
// info: reset guard back to idle pose - can be used to stop guards in place
//===========================================================================*/
#define guard_animation_stop_ID 0x08
#define guard_animation_stop_LENGTH 0x01
#define guard_animation_stop \
        guard_animation_stop_ID,

/*=============================================================================
// name: guard_kneel
// command id: 09
// info: make guard kneel on one knee
//===========================================================================*/
#define guard_kneel_ID 0x09
#define guard_kneel_LENGTH 0x01
#define guard_kneel \
        guard_kneel_ID,

/*=============================================================================
// name: guard_play_animation
// command id: 0A
// info: set guard to playback animation
//=============================================================================
// arguments:
// start/end set to -1/-1 will playback the entire animation length.
// interpolation time will set how long it will take to transition from the previous state.
// if interpolation time is too low it may crash! - use 0x10 if unsure.
// start/end keyframe uses animation 30 tick units - interpolation use 60 tick units.
// use ANIM_# flags for bitfield argument
//===========================================================================*/
#define guard_play_animation_ID 0x0A
#define guard_play_animation_LENGTH 0x09
#define guard_play_animation(animation_id, start_time30, end_time30, bitfield, interpol_time60) \
        guard_play_animation_ID, \
        CharArrayFrom16Rev(animation_id), \
        CharArrayFrom16Rev(start_time30), \
        CharArrayFrom16Rev(end_time30), \
        bitfield, \
        interpol_time60,

/*=============================================================================
// name: if_guard_playing_animation
// command id: 0B
// info: if guard is in animation playback state (ACT_ANIM), goto label
//===========================================================================*/
#define if_guard_playing_animation_ID 0x0B
#define if_guard_playing_animation_LENGTH 0x02
#define if_guard_playing_animation(label) \
        if_guard_playing_animation_ID, \
        label,

/*=============================================================================
// name: guard_points_at_bond
// command id: 0C
// info: guard points if bond is directly in front of guard, else command is ignored
//=============================================================================
// note: global ai list GAILIST_ATTACK_BOND skips this command if
// bitfield flag FLAGS2_DONT_POINT_AT_BOND is on
//===========================================================================*/
#define guard_points_at_bond_ID 0x0C
#define guard_points_at_bond_LENGTH 0x01
#define guard_points_at_bond \
        guard_points_at_bond_ID,

/*=============================================================================
// name: guard_looks_around_self
// command id: 0D
// info: set guard to playback animation - used when shots land near guard
//===========================================================================*/
#define guard_looks_around_self_ID 0x0D
#define guard_looks_around_self_LENGTH 0x01
#define guard_looks_around_self \
        guard_looks_around_self_ID,

/*=============================================================================
// name: guard_try_sidestepping
// command id: 0E
// info: trigger guard to sidestep, goto label if successful
//=============================================================================
// note: direction is random
//===========================================================================*/
#define guard_try_sidestepping_ID 0x0E
#define guard_try_sidestepping_LENGTH 0x02
#define guard_try_sidestepping(label) \
        guard_try_sidestepping_ID, \
        label,

/*=============================================================================
// name: guard_try_hopping_sideways
// command id: 0F
// info: trigger guard to hop sideways, goto label if successful
//=============================================================================
// note: direction is random
//===========================================================================*/
#define guard_try_hopping_sideways_ID 0x0F
#define guard_try_hopping_sideways_LENGTH 0x02
#define guard_try_hopping_sideways(label) \
        guard_try_hopping_sideways_ID, \
        label,

/*=============================================================================
// name: guard_try_running_to_side
// command id: 10
// info: trigger guard to run sideways of bond, goto label if successful
//=============================================================================
// note: direction is random
//===========================================================================*/
#define guard_try_running_to_side_ID 0x10
#define guard_try_running_to_side_LENGTH 0x02
#define guard_try_running_to_side(label) \
        guard_try_running_to_side_ID, \
        label,

/*=============================================================================
// name: guard_try_firing_walk
// command id: 11
// info: trigger guard to walk and fire at bond, goto label if successful
//=============================================================================
// note: bond needs to be at long distance away from guard to work
//===========================================================================*/
#define guard_try_firing_walk_ID 0x11
#define guard_try_firing_walk_LENGTH 0x02
#define guard_try_firing_walk(label) \
        guard_try_firing_walk_ID, \
        label,

/*=============================================================================
// name: guard_try_firing_run
// command id: 12
// info: trigger guard to run and fire at bond, goto label if successful
//=============================================================================
// note: bond needs to be at long distance away from guard to work
//===========================================================================*/
#define guard_try_firing_run_ID 0x12
#define guard_try_firing_run_LENGTH 0x02
#define guard_try_firing_run(label) \
        guard_try_firing_run_ID, \
        label,

/*=============================================================================
// name: guard_try_firing_roll
// command id: 13
// info: trigger guard to roll on ground then fire at bond, goto label if successful
//=============================================================================
// note: bond cannot be too close to guard or it won't work
//===========================================================================*/
#define guard_try_firing_roll_ID 0x13
#define guard_try_firing_roll_LENGTH 0x02
#define guard_try_firing_roll(label) \
        guard_try_firing_roll_ID, \
        label,

/*=============================================================================
// name: guard_try_fire_or_aim_at_target
// command id: 14
// info: make guard aim/fire their weapon at target, goto label if successful
//=============================================================================
// note: bitfield argument is used to set the target type (pad/bond/chr).
//       use TARGET_# flags for bitfield argument
//===========================================================================*/
#define guard_try_fire_or_aim_at_target_ID 0x14
#define guard_try_fire_or_aim_at_target_LENGTH 0x06
#define guard_try_fire_or_aim_at_target(bitfield, target, label) \
        guard_try_fire_or_aim_at_target_ID, \
        CharArrayFrom16Rev(bitfield), \
        CharArrayFrom16Rev(target), \
        label,

/*=============================================================================
// name: guard_try_fire_or_aim_at_target_kneel
// command id: 15
// info: make guard kneel and aim/fire their weapon at target, goto label if successful
//=============================================================================
// note: bitfield argument is used to set the target type (pad/bond/chr).
//       use TARGET_# flags for bitfield argument
//===========================================================================*/
#define guard_try_fire_or_aim_at_target_kneel_ID 0x15
#define guard_try_fire_or_aim_at_target_kneel_LENGTH 0x06
#define guard_try_fire_or_aim_at_target_kneel(bitfield, target, label) \
        guard_try_fire_or_aim_at_target_kneel_ID, \
        CharArrayFrom16Rev(bitfield), \
        CharArrayFrom16Rev(target), \
        label,

/*=============================================================================
// name: guard_try_fire_or_aim_at_target_update
// command id: 16
// info: update guard's aim/fire target, goto label if successful
//=============================================================================
// note: this command only works if guard is currently aiming at a target.
//       bitfield argument is used to set the target type (pad/bond/chr).
//       use TARGET_# flags for bitfield argument
//===========================================================================*/
#define guard_try_fire_or_aim_at_target_update_ID 0x16
#define guard_try_fire_or_aim_at_target_update_LENGTH 0x06
#define guard_try_fire_or_aim_at_target_update(bitfield, target, label) \
        guard_try_fire_or_aim_at_target_update_ID, \
        CharArrayFrom16Rev(bitfield), \
        CharArrayFrom16Rev(target), \
        label,

/*=============================================================================
// name: guard_try_facing_target
// command id: 17
// info: make guard continuously face target, goto label if successful
//=============================================================================
// note: if guard was shot while facing target, guard will snap out of facing state.
// bitfield argument is used to set the target type (pad/bond/chr).
// use TARGET_# flags for bitfield argument. command can't use TARGET_AIM_ONLY flag
//===========================================================================*/
#define guard_try_facing_target_ID 0x17
#define guard_try_facing_target_LENGTH 0x06
#define guard_try_facing_target(bitfield, target, label) \
        guard_try_facing_target_ID, \
        CharArrayFrom16Rev(bitfield), \
        CharArrayFrom16Rev(target), \
        label,

/*=============================================================================
// name: chr_hit_body_part_with_item_damage
// command id: 18
// info: hit chr's body part with item's damage, play reaction to hit location
//=============================================================================
// note: command does not trigger item's fire sfx. item's damage uses body part
//       damage modifier. use HIT_# define for hit part number
//===========================================================================*/
#define chr_hit_body_part_with_item_damage_ID 0x18
#define chr_hit_body_part_with_item_damage_LENGTH 0x04
#define chr_hit_body_part_with_item_damage(chr_num, part_num, item_num) \
        chr_hit_body_part_with_item_damage_ID, \
        chr_num, \
        part_num, \
        item_num,

/*=============================================================================
// name: chr_hit_chr_body_part_with_held_item
// command id: 19
// info: chr hits chr's body part with held item, play reaction to hit location
//=============================================================================
// note: command does not trigger item's fire sfx or chr firing animation.
// item's damage uses body part damage modifier. use HIT_# define for hit part number
//===========================================================================*/
#define chr_hit_chr_body_part_with_held_item_ID 0x19
#define chr_hit_chr_body_part_with_held_item_LENGTH 0x04
#define chr_hit_chr_body_part_with_held_item(chr_num, chr_num_target, part_num) \
        chr_hit_chr_body_part_with_held_item_ID, \
        chr_num, \
        chr_num_target, \
        part_num,

/*=============================================================================
// name: guard_try_throwing_grenade
// command id: 1A
// info: trigger guard to throw a grenade at bond, goto label if successful
//=============================================================================
// note: a rng byte is generated and compared again chr->grenadeprob, if rng byte
// is less than grenadeprob throw grenade and goto label, else do nothing.
// chr->grenadeprob default is 0 - to change use setup object 12 or command 8D
//===========================================================================*/
#define guard_try_throwing_grenade_ID 0x1A
#define guard_try_throwing_grenade_LENGTH 0x02
#define guard_try_throwing_grenade(label) \
        guard_try_throwing_grenade_ID, \
        label,

/*=============================================================================
// name: guard_try_dropping_item
// command id: 1B
// info: spawn and drop item with prop model from guard, goto label if successful
//=============================================================================
// note: dropped item uses item type (08) with model number - they can be picked up.
// grenade/mines will be dropped live - this is used for cradle (list #0411)
//===========================================================================*/
#define guard_try_dropping_item_ID 0x1B
#define guard_try_dropping_item_LENGTH 0x05
#define guard_try_dropping_item(prop_num, item_num, label) \
        guard_try_dropping_item_ID, \
        CharArrayFrom16Rev(prop_num), \
        item_num, \
        label,

/*=============================================================================
// name: guard_runs_to_pad
// command id: 1C
// info: makes the guard run to pad
//===========================================================================*/
#define guard_runs_to_pad_ID 0x1C
#define guard_runs_to_pad_LENGTH 0x03
#define guard_runs_to_pad(pad) \
        guard_runs_to_pad_ID, \
        CharArrayFrom16Rev(pad),

/*=============================================================================
// name: guard_runs_to_pad_preset
// command id: 1D
// info: makes the guard run to guard->padpreset1 (PAD_PRESET - 9000)
//===========================================================================*/
#define guard_runs_to_pad_preset_ID 0x1D
#define guard_runs_to_pad_preset_LENGTH 0x01
#define guard_runs_to_pad_preset \
        guard_runs_to_pad_preset_ID,

/*=============================================================================
// name: guard_walks_to_pad
// command id: 1E
// info: makes the guard walk to pad
//===========================================================================*/
#define guard_walks_to_pad_ID 0x1E
#define guard_walks_to_pad_LENGTH 0x03
#define guard_walks_to_pad(pad) \
        guard_walks_to_pad_ID, \
        CharArrayFrom16Rev(pad),

/*=============================================================================
// name: guard_sprints_to_pad
// command id: 1F
// info: makes the guard sprint to pad
//===========================================================================*/
#define guard_sprints_to_pad_ID 0x1F
#define guard_sprints_to_pad_LENGTH 0x03
#define guard_sprints_to_pad(pad) \
        guard_sprints_to_pad_ID, \
        CharArrayFrom16Rev(pad),

/*=============================================================================
// name: guard_start_patrol
// command id: 20
// info: makes guard walk a predefined path within setup
//=============================================================================
// note: usually paired with goto GAILIST_SIMPLE_GUARD_DEAF
//       or GAILIST_SIMPLE_GUARD
//===========================================================================*/
#define guard_start_patrol_ID 0x20
#define guard_start_patrol_LENGTH 0x02
#define guard_start_patrol(path_num) \
        guard_start_patrol_ID, \
        path_num,

/*=============================================================================
// name: guard_surrenders
// command id: 21
// info: makes a guard surrender and drop all attached and held items
//=============================================================================
// note: will not drop items embedded within guard
//===========================================================================*/
#define guard_surrenders_ID 0x21
#define guard_surrenders_LENGTH 0x01
#define guard_surrenders \
        guard_surrenders_ID,

/*=============================================================================
// name: guard_remove_fade
// command id: 22
// info: sets guard to fade away - fade time is 90 ticks (1.5 seconds). when
//       the fade finishes, automatically remove guard
//=============================================================================
// note: guard collision is ignored during fade - will not drop items
//===========================================================================*/
#define guard_remove_fade_ID 0x22
#define guard_remove_fade_LENGTH 0x01
#define guard_remove_fade \
        guard_remove_fade_ID,

/*=============================================================================
// name: chr_remove_instant
// command id: 23
// info: instantly remove chr unlike above command
//=============================================================================
// note: will not drop items
//===========================================================================*/
#define chr_remove_instant_ID 0x23
#define chr_remove_instant_LENGTH 0x02
#define chr_remove_instant(chr_num) \
        chr_remove_instant_ID, \
        chr_num,

/*=============================================================================
// name: guard_try_triggering_alarm_at_pad
// command id: 24
// info: guard activates alarm assigned to pad, goto label if successful
//=============================================================================
// note: command doesn't care what object type is at pad, as long as the object
// isn't destroyed. command also checks if guard is alive before activating alarm.
// when triggering alarm, guard will be set to state ACT_STARTALARM and play animation
//===========================================================================*/
#define guard_try_triggering_alarm_at_pad_ID 0x24
#define guard_try_triggering_alarm_at_pad_LENGTH 0x04
#define guard_try_triggering_alarm_at_pad(pad, label) \
        guard_try_triggering_alarm_at_pad_ID, \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: alarm_on
// command id: 25
// info: activates alarm
//===========================================================================*/
#define alarm_on_ID 0x25
#define alarm_on_LENGTH 0x01
#define alarm_on \
        alarm_on_ID,

/*=============================================================================
// name: alarm_off
// command id: 26
// info: deactivates alarm
//===========================================================================*/
#define alarm_off_ID 0x26
#define alarm_off_LENGTH 0x01
#define alarm_off \
        alarm_off_ID,

/*=============================================================================
// name: removed_command27
// command id: 27
// info: command no longer exists, never goto label
//===========================================================================*/
#define removed_command27_ID 0x27
#define removed_command27_LENGTH 0x02
#define removed_command27(label) \
        removed_command27_ID, \
        label,

/*=============================================================================
// name: guard_try_running_to_bond_position
// command id: 28
// info: if guard is able to run to bond, goto label
//=============================================================================
// note: don't goto label if guard can't run to bond (guard has died) or bond is
//       at an unreachable area (no navigation pads in area)
//===========================================================================*/
#define guard_try_running_to_bond_position_ID 0x28
#define guard_try_running_to_bond_position_LENGTH 0x02
#define guard_try_running_to_bond_position(label) \
        guard_try_running_to_bond_position_ID, \
        label,

/*=============================================================================
// name: guard_try_walking_to_bond_position
// command id: 29
// info: if guard is able to walk to bond, goto label
//=============================================================================
// note: don't goto label if guard can't walk to bond (guard has died) or bond is
//       at an unreachable area (no navigation pads in area)
//===========================================================================*/
#define guard_try_walking_to_bond_position_ID 0x29
#define guard_try_walking_to_bond_position_LENGTH 0x02
#define guard_try_walking_to_bond_position(label) \
        guard_try_walking_to_bond_position_ID, \
        label,

/*=============================================================================
// name: guard_try_sprinting_to_bond_position
// command id: 2A
// info: if guard is able to sprint to bond, goto label
//=============================================================================
// note: don't goto label if guard can't sprint to bond (guard has died) or bond
//       is at an unreachable area (no navigation pads in area)
//===========================================================================*/
#define guard_try_sprinting_to_bond_position_ID 0x2A
#define guard_try_sprinting_to_bond_position_LENGTH 0x02
#define guard_try_sprinting_to_bond_position(label) \
        guard_try_sprinting_to_bond_position_ID, \
        label,

/*=============================================================================
// name: removed_command2B
// command id: 2B
// info: command no longer exists, never goto label
//===========================================================================*/
#define removed_command2B_ID 0x2B
#define removed_command2B_LENGTH 0x02
#define removed_command2B(label) \
        removed_command2B_ID, \
        label,

/*=============================================================================
// name: guard_try_running_to_chr_position
// command id: 2C
// info: if guard is able to run to chr, goto label
//=============================================================================
// note: don't goto label if guard can't run to chr (guard has died) or chr is
// at an unreachable area (no navigation pads in area) or chr doesn't exist
//===========================================================================*/
#define guard_try_running_to_chr_position_ID 0x2C
#define guard_try_running_to_chr_position_LENGTH 0x03
#define guard_try_running_to_chr_position(chr_num, label) \
        guard_try_running_to_chr_position_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: guard_try_walking_to_chr_position
// command id: 2D
// info: if guard is able to walk to chr, goto label
//=============================================================================
// note: don't goto label if guard can't walk to chr (guard has died) or chr is
// at an unreachable area (no navigation pads in area) or chr doesn't exist
//===========================================================================*/
#define guard_try_walking_to_chr_position_ID 0x2D
#define guard_try_walking_to_chr_position_LENGTH 0x03
#define guard_try_walking_to_chr_position(chr_num, label) \
        guard_try_walking_to_chr_position_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: guard_try_sprinting_to_chr_position
// command id: 2E
// info: if guard is able to sprint to chr, goto label
//=============================================================================
// note: don't goto label if guard can't sprint to chr (guard has died) or chr
// is at an unreachable area (no navigation pads in area) or chr doesn't exist
//===========================================================================*/
#define guard_try_sprinting_to_chr_position_ID 0x2E
#define guard_try_sprinting_to_chr_position_LENGTH 0x03
#define guard_try_sprinting_to_chr_position(chr_num, label) \
        guard_try_sprinting_to_chr_position_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: if_guard_has_stopped_moving
// command id: 2F
// info: if guard has stopped moving, goto label
//=============================================================================
// note: check if guard isn't looking for bond or if guard has finished moving
//       to destination
//===========================================================================*/
#define if_guard_has_stopped_moving_ID 0x2F
#define if_guard_has_stopped_moving_LENGTH 0x02
#define if_guard_has_stopped_moving(label) \
        if_guard_has_stopped_moving_ID, \
        label,

/*=============================================================================
// name: if_chr_dying_or_dead
// command id: 30
// info: if chr has died (or in dying state), goto label
//===========================================================================*/
#define if_chr_dying_or_dead_ID 0x30
#define if_chr_dying_or_dead_LENGTH 0x03
#define if_chr_dying_or_dead(chr_num, label) \
        if_chr_dying_or_dead_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: if_chr_does_not_exist
// command id: 31
// info: if chr doesn't exist (died and faded/not spawned), goto label
//=============================================================================
// note: this command is used to check if chr has finished dying animation and
// faded away, or chr num is free
//===========================================================================*/
#define if_chr_does_not_exist_ID 0x31
#define if_chr_does_not_exist_LENGTH 0x03
#define if_chr_does_not_exist(chr_num, label) \
        if_chr_does_not_exist_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: if_guard_sees_bond
// command id: 32
// info: check vision for bond, goto label if spotted bond
//=============================================================================
// note: uses chr->visionrange while checking for bond. once bond has been spotted,
// check if bond and guard are within line of sight (ignores facing direction).
// injured guards will also set spotted Bond state (won't work with invincible/armored guards).
// if bond breaks line of sight, do not goto label. if bond has broken line of
// sight for more than 10 seconds, reset spotted bond state. when using with
// command 3E, make sure 32 takes priority over command 3E
//===========================================================================*/
#define if_guard_sees_bond_ID 0x32
#define if_guard_sees_bond_LENGTH 0x02
#define if_guard_sees_bond(label) \
        if_guard_sees_bond_ID, \
        label,

/*=============================================================================
// name: random_generate_seed
// command id: 33
// info: generate a random byte and store to chr->random
//=============================================================================
// note: random byte range is 00-FF (unsigned)
//===========================================================================*/
#define random_generate_seed_ID 0x33
#define random_generate_seed_LENGTH 0x01
#define random_generate_seed \
        random_generate_seed_ID,

/*=============================================================================
// name: if_random_seed_less_than
// command id: 34
// info: if chr->random < byte, goto label
//=============================================================================
// note: compare is unsigned
//===========================================================================*/
#define if_random_seed_less_than_ID 0x34
#define if_random_seed_less_than_LENGTH 0x03
#define if_random_seed_less_than(byte, label) \
        if_random_seed_less_than_ID, \
        byte, \
        label,

/*=============================================================================
// name: if_random_seed_greater_than
// command id: 35
// info: if chr->random > byte, goto label
//=============================================================================
// note: compare is unsigned
//===========================================================================*/
#define if_random_seed_greater_than_ID 0x35
#define if_random_seed_greater_than_LENGTH 0x03
#define if_random_seed_greater_than(byte, label) \
        if_random_seed_greater_than_ID, \
        byte, \
        label,

/*=============================================================================
// name: if_alarm_is_on_unused
// command id: 36
// info: if alarm is activated, goto label
//=============================================================================
// note: this command works but is unused in retail game, use command 37 instead
//===========================================================================*/
#define if_alarm_is_on_unused_ID 0x36
#define if_alarm_is_on_unused_LENGTH 0x02
#define if_alarm_is_on_unused(label) \
        if_alarm_is_on_unused_ID, \
        label,

/*=============================================================================
// name: if_alarm_is_on
// command id: 37
// info: if alarm is activated, goto label
//===========================================================================*/
#define if_alarm_is_on_ID 0x37
#define if_alarm_is_on_LENGTH 0x02
#define if_alarm_is_on(label) \
        if_alarm_is_on_ID, \
        label,

/*=============================================================================
// name: if_gas_is_leaking
// command id: 38
// info: if gas leak event triggered, goto label
//=============================================================================
// note: once gas leak event has started, always goto label
//===========================================================================*/
#define if_gas_is_leaking_ID 0x38
#define if_gas_is_leaking_LENGTH 0x02
#define if_gas_is_leaking(label) \
        if_gas_is_leaking_ID, \
        label,

/*=============================================================================
// name: if_guard_heard_bond
// command id: 39
// info: if guard heard bond fire weapon, goto label
//=============================================================================
// note: uses chr->hearingscale while listening for bond. to check if bond has
//       shot within the last 10 seconds, use command 3F
//===========================================================================*/
#define if_guard_heard_bond_ID 0x39
#define if_guard_heard_bond_LENGTH 0x02
#define if_guard_heard_bond(label) \
        if_guard_heard_bond_ID, \
        label,

/*=============================================================================
// name: if_guard_see_another_guard_shot
// command id: 3A
// info: if guard sees another guard shot (from anyone), goto label
//=============================================================================
// note: guard friendly fire (if flagged) will trigger this command to goto label.
// command checks if chr->chrseeshot is set to valid chrnum (not -1). does not
// work with shot invincible/armoured guards
//===========================================================================*/
#define if_guard_see_another_guard_shot_ID 0x3A
#define if_guard_see_another_guard_shot_LENGTH 0x02
#define if_guard_see_another_guard_shot(label) \
        if_guard_see_another_guard_shot_ID, \
        label,

/*=============================================================================
// name: if_guard_see_another_guard_die
// command id: 3B
// info: if guard sees another guard die (from anyone), goto label
//=============================================================================
// note: when a guard in sight switches to ACT_DIE/ACT_DEAD, goto label.
//       command checks if chr->chrseedie is set to valid chrnum (not -1)
//===========================================================================*/
#define if_guard_see_another_guard_die_ID 0x3B
#define if_guard_see_another_guard_die_LENGTH 0x02
#define if_guard_see_another_guard_die(label) \
        if_guard_see_another_guard_die_ID, \
        label,

/*=============================================================================
// name: if_guard_and_bond_within_line_of_sight
// command id: 3C
// info: if guard and bond are within line of sight, goto label
//=============================================================================
// note: line of sight uses clipping - ignores facing direction of bond/guard.
// if prop/guard is in the way do not goto label. does not use chr->visionrange
// for line of sight check. use command 32 to check using chr->visionrange and
// command 42 to account for bond's view
//===========================================================================*/
#define if_guard_and_bond_within_line_of_sight_ID 0x3C
#define if_guard_and_bond_within_line_of_sight_LENGTH 0x02
#define if_guard_and_bond_within_line_of_sight(label) \
        if_guard_and_bond_within_line_of_sight_ID, \
        label,

/*=============================================================================
// name: if_guard_and_bond_within_partial_line_of_sight
// command id: 3D
// info: if guard and bond are within partial line of sight, goto label
//=============================================================================
// note: unused command, functions like above but only goto label if bond is
//       half occluded by clipping (not blocked or within full view)
//===========================================================================*/
#define if_guard_and_bond_within_partial_line_of_sight_ID 0x3D
#define if_guard_and_bond_within_partial_line_of_sight_LENGTH 0x02
#define if_guard_and_bond_within_partial_line_of_sight(label) \
        if_guard_and_bond_within_partial_line_of_sight_ID, \
        label,

/*=============================================================================
// name: if_guard_was_shot_or_seen_bond_within_last_10_secs
// command id: 3E
// info: if guard was shot (from anyone) or saw Bond within the last 10 seconds, goto label
//=============================================================================
// note: command will not count guard as shot if they are invincible/have armour.
// if guard saw Bond (using command 32) in the last 10 seconds, goto label. when
// using with command 32, make sure 32 takes priority over command 3E. if guard
// was injured within the last 10 seconds, goto label when finished injury reaction
// animation (will not work with invincible/armored guards).
// to check if guard was hit/damaged use commands 7E/F8 instead, or check if
// guard flags CHRFLAG_WAS_DAMAGED/CHRFLAG_WAS_HIT are set using command 9F/A2
//===========================================================================*/
#define if_guard_was_shot_or_seen_bond_within_last_10_secs_ID 0x3E
#define if_guard_was_shot_or_seen_bond_within_last_10_secs_LENGTH 0x02
#define if_guard_was_shot_or_seen_bond_within_last_10_secs(label) \
        if_guard_was_shot_or_seen_bond_within_last_10_secs_ID, \
        label,

/*=============================================================================
// name: if_guard_heard_bond_within_last_10_secs
// command id: 3F
// info: if guard heard bond fire weapon within the last 10 seconds, goto label
//=============================================================================
// note: uses chr->hearingscale while listening for bond. to check if bond has
//       now fired weapon instead of within the last 10 seconds, use command 39
//===========================================================================*/
#define if_guard_heard_bond_within_last_10_secs_ID 0x3F
#define if_guard_heard_bond_within_last_10_secs_LENGTH 0x02
#define if_guard_heard_bond_within_last_10_secs(label) \
        if_guard_heard_bond_within_last_10_secs_ID, \
        label,

/*=============================================================================
// name: if_guard_in_room_with_chr
// command id: 40
// info: if guard is in same room with chr, goto label
//===========================================================================*/
#define if_guard_in_room_with_chr_ID 0x40
#define if_guard_in_room_with_chr_LENGTH 0x03
#define if_guard_in_room_with_chr(chr_num, label) \
        if_guard_in_room_with_chr_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: if_guard_has_not_been_seen
// command id: 41
// info: if guard has not been seen before on screen, goto label
//=============================================================================
// note: when bond has seen guard, it will add a flag to chr->chrflags.
//       the seen flag will be kept true for duration of level
//===========================================================================*/
#define if_guard_has_not_been_seen_ID 0x41
#define if_guard_has_not_been_seen_LENGTH 0x02
#define if_guard_has_not_been_seen(label) \
        if_guard_has_not_been_seen_ID, \
        label,

/*=============================================================================
// name: if_guard_is_on_screen
// command id: 42
// info: if guard is currently being rendered on screen, goto label
//=============================================================================
// note: portals will affect this command's output. if guard is being culled
//       off screen, command will not goto label
//===========================================================================*/
#define if_guard_is_on_screen_ID 0x42
#define if_guard_is_on_screen_LENGTH 0x02
#define if_guard_is_on_screen(label) \
        if_guard_is_on_screen_ID, \
        label,

/*=============================================================================
// name: if_guard_room_containing_self_is_on_screen
// command id: 43
// info: if the room containing guard is being rendered on screen, goto label
//=============================================================================
// note: only checks if room is being rendered, not if bond can see guard.
//       to check if guard is being rendered use command 42 instead.
//===========================================================================*/
#define if_guard_room_containing_self_is_on_screen_ID 0x43
#define if_guard_room_containing_self_is_on_screen_LENGTH 0x02
#define if_guard_room_containing_self_is_on_screen(label) \
        if_guard_room_containing_self_is_on_screen_ID, \
        label,

/*=============================================================================
// name: if_room_containing_pad_is_on_screen
// command id: 44
// info: if room containing pad is being rendered on screen, goto label
//=============================================================================
// note: only checks if room is being rendered, not if bond can see inside room
//===========================================================================*/
#define if_room_containing_pad_is_on_screen_ID 0x44
#define if_room_containing_pad_is_on_screen_LENGTH 0x04
#define if_room_containing_pad_is_on_screen(pad, label) \
        if_room_containing_pad_is_on_screen_ID, \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: if_guard_is_targeted_by_bond
// command id: 45
// info: if bond is looking/aiming at guard, goto label
//=============================================================================
// note: also checks if crosshair is aiming at guard
//===========================================================================*/
#define if_guard_is_targeted_by_bond_ID 0x45
#define if_guard_is_targeted_by_bond_LENGTH 0x02
#define if_guard_is_targeted_by_bond(label) \
        if_guard_is_targeted_by_bond_ID, \
        label,

/*=============================================================================
// name: if_guard_shot_from_bond_missed
// command id: 46
// info: if bond's shot missed/landed near guard, goto label
//=============================================================================
// note: command will sometimes goto label if guard was shot - use command
//       3E instead to check if guard was shot recently (more consistent)
//===========================================================================*/
#define if_guard_shot_from_bond_missed_ID 0x46
#define if_guard_shot_from_bond_missed_LENGTH 0x02
#define if_guard_shot_from_bond_missed(label) \
        if_guard_shot_from_bond_missed_ID, \
        label,

/*=============================================================================
// name: if_guard_counter_clockwise_direction_to_bond_less_than
// command id: 47
// info: if guard's counter-clockwise direction to bond < direction argument, goto label
//=============================================================================
// note: direction input (hex):
// 00: no rotation, never goto label because degrees are always above 0
// 40: bond and guard within 9-to-12 o'clock (90 degrees)
// 80: bond is on guard's left-side (180 degrees)
// C0: bond and guard within 3-to-12 o'clock (270 degrees)
// FF: full rotation, always goto label except for a tiny degree (0-359 degrees)
//===========================================================================*/
#define if_guard_counter_clockwise_direction_to_bond_less_than_ID 0x47
#define if_guard_counter_clockwise_direction_to_bond_less_than_LENGTH 0x03
#define if_guard_counter_clockwise_direction_to_bond_less_than(direction, label) \
        if_guard_counter_clockwise_direction_to_bond_less_than_ID, \
        direction, \
        label,

/*=============================================================================
// name: if_guard_counter_clockwise_direction_to_bond_greater_than
// command id: 48
// info: if guard's counter-clockwise direction to bond > direction argument, goto label
//=============================================================================
// note: direction input (hex):
// FF: no rotation, never goto label except for a tiny degree (0-1 degrees)
// C0: bond and guard within 12-to-3 o'clock (90 degrees)
// 80: bond on guard's right-side (180 degrees)
// 40: bond and guard within 12-to-9 o'clock (270 degrees)
// 00: full rotation, always goto label
//===========================================================================*/
#define if_guard_counter_clockwise_direction_to_bond_greater_than_ID 0x48
#define if_guard_counter_clockwise_direction_to_bond_greater_than_LENGTH 0x03
#define if_guard_counter_clockwise_direction_to_bond_greater_than(direction, label) \
        if_guard_counter_clockwise_direction_to_bond_greater_than_ID, \
        direction, \
        label,

/*=============================================================================
// name: if_guard_counter_clockwise_direction_from_bond_less_than
// command id: 49
// info: if bond's counter-clockwise direction to guard < direction argument, goto label
//=============================================================================
// note: direction input (hex):
// 00: no rotation, never goto label because degrees are always above 0
// 40: guard and bond within 9-to-12 o'clock (90 degrees)
// 80: guard is on bond's left-side (180 degrees)
// C0: guard and bond within 3-to-12 o'clock (270 degrees)
// FF: full rotation, always goto label except for a tiny degree (0-359 degrees)
//===========================================================================*/
#define if_guard_counter_clockwise_direction_from_bond_less_than_ID 0x49
#define if_guard_counter_clockwise_direction_from_bond_less_than_LENGTH 0x03
#define if_guard_counter_clockwise_direction_from_bond_less_than(direction, label) \
        if_guard_counter_clockwise_direction_from_bond_less_than_ID, \
        direction, \
        label,

/*=============================================================================
// name: if_guard_counter_clockwise_direction_from_bond_greater_than
// command id: 4A
// info: if bond's counter-clockwise direction to guard > direction argument, goto label
//=============================================================================
// note: direction input (hex):
// FF: no rotation, never goto label except for a tiny degree (0-1 degrees)
// C0: guard and bond within 12-to-3 o'clock (90 degrees)
// 80: guard on bond's right-side (180 degrees)
// 40: guard and bond within 12-to-9 o'clock (270 degrees)
// 00: full rotation, always goto label
//===========================================================================*/
#define if_guard_counter_clockwise_direction_from_bond_greater_than_ID 0x4A
#define if_guard_counter_clockwise_direction_from_bond_greater_than_LENGTH 0x03
#define if_guard_counter_clockwise_direction_from_bond_greater_than(direction, label) \
        if_guard_counter_clockwise_direction_from_bond_greater_than_ID, \
        direction, \
        label,

/*=============================================================================
// name: if_guard_distance_to_bond_less_than
// command id: 4B
// info: if guard's distance to bond < distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define if_guard_distance_to_bond_less_than_ID 0x4B
#define if_guard_distance_to_bond_less_than_LENGTH 0x04
#define if_guard_distance_to_bond_less_than(distance, label) \
        if_guard_distance_to_bond_less_than_ID, \
        CharArrayFrom16Rev(distance), \
        label,

/*=============================================================================
// name: if_guard_distance_to_bond_greater_than
// command id: 4C
// info: if guard's distance to bond > distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define if_guard_distance_to_bond_greater_than_ID 0x4C
#define if_guard_distance_to_bond_greater_than_LENGTH 0x04
#define if_guard_distance_to_bond_greater_than(distance, label) \
        if_guard_distance_to_bond_greater_than_ID, \
        CharArrayFrom16Rev(distance), \
        label,

/*=============================================================================
// name: if_chr_distance_to_pad_less_than
// command id: 4D
// info: if chr's distance to pad < distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define if_chr_distance_to_pad_less_than_ID 0x4D
#define if_chr_distance_to_pad_less_than_LENGTH 0x07
#define if_chr_distance_to_pad_less_than(chr_num, distance, pad, label) \
        if_chr_distance_to_pad_less_than_ID, \
        chr_num, \
        CharArrayFrom16Rev(distance), \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: if_chr_distance_to_pad_greater_than
// command id: 4E
// info: if chr's distance to pad > distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define if_chr_distance_to_pad_greater_than_ID 0x4E
#define if_chr_distance_to_pad_greater_than_LENGTH 0x07
#define if_chr_distance_to_pad_greater_than(chr_num, distance, pad, label) \
        if_chr_distance_to_pad_greater_than_ID, \
        chr_num, \
        CharArrayFrom16Rev(distance), \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: if_guard_distance_to_chr_less_than
// command id: 4F
// info: if guard's distance to chr < distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define if_guard_distance_to_chr_less_than_ID 0x4F
#define if_guard_distance_to_chr_less_than_LENGTH 0x05
#define if_guard_distance_to_chr_less_than(distance, chr_num, label) \
        if_guard_distance_to_chr_less_than_ID, \
        CharArrayFrom16Rev(distance), \
        chr_num, \
        label,

/*=============================================================================
// name: if_guard_distance_to_chr_greater_than
// command id: 50
// info: if guard's distance to chr > distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define if_guard_distance_to_chr_greater_than_ID 0x50
#define if_guard_distance_to_chr_greater_than_LENGTH 0x05
#define if_guard_distance_to_chr_greater_than(distance, chr_num, label) \
        if_guard_distance_to_chr_greater_than_ID, \
        CharArrayFrom16Rev(distance), \
        chr_num, \
        label,

/*=============================================================================
// name: guard_try_setting_chr_preset_to_guard_within_distance
// command id: 51
// info: if guard's distance to any chr < distance argument, set chr->padpreset1
//       to found guard's chrnum and goto label
//=============================================================================
// note: argument scale is 10 units per meter. command does not pick the closest
// found chr, but whoever was first found within the distance argument. if no
// guards were found within distance range, do not goto label
//===========================================================================*/
#define guard_try_setting_chr_preset_to_guard_within_distance_ID 0x51
#define guard_try_setting_chr_preset_to_guard_within_distance_LENGTH 0x04
#define guard_try_setting_chr_preset_to_guard_within_distance(distance, label) \
        guard_try_setting_chr_preset_to_guard_within_distance_ID, \
        CharArrayFrom16Rev(distance), \
        label,

/*=============================================================================
// name: if_bond_distance_to_pad_less_than
// command id: 52
// info: if bond's distance to pad < distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define if_bond_distance_to_pad_less_than_ID 0x52
#define if_bond_distance_to_pad_less_than_LENGTH 0x06
#define if_bond_distance_to_pad_less_than(distance, pad, label) \
        if_bond_distance_to_pad_less_than_ID, \
        CharArrayFrom16Rev(distance), \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: if_bond_distance_to_pad_greater_than
// command id: 53
// info: if bond's distance to pad > distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define if_bond_distance_to_pad_greater_than_ID 0x53
#define if_bond_distance_to_pad_greater_than_LENGTH 0x06
#define if_bond_distance_to_pad_greater_than(distance, pad, label) \
        if_bond_distance_to_pad_greater_than_ID, \
        CharArrayFrom16Rev(distance), \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: if_chr_in_room_with_pad
// command id: 54
// info: if chr id in same room with pad, goto label
//===========================================================================*/
#define if_chr_in_room_with_pad_ID 0x54
#define if_chr_in_room_with_pad_LENGTH 0x05
#define if_chr_in_room_with_pad(chr_num, pad, label) \
        if_chr_in_room_with_pad_ID, \
        chr_num, \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: if_bond_in_room_with_pad
// command id: 55
// info: if bond in same room with pad, goto label
//===========================================================================*/
#define if_bond_in_room_with_pad_ID 0x55
#define if_bond_in_room_with_pad_LENGTH 0x04
#define if_bond_in_room_with_pad(pad, label) \
        if_bond_in_room_with_pad_ID, \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: if_bond_collected_object
// command id: 56
// info: if bond collected tagged object, goto label
//===========================================================================*/
#define if_bond_collected_object_ID 0x56
#define if_bond_collected_object_LENGTH 0x03
#define if_bond_collected_object(object_tag, label) \
        if_bond_collected_object_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: if_item_is_stationary_within_level
// command id: 57
// info: if item exists in level and is stationary (not moving/in mid-air), goto label
//=============================================================================
// note: used to check if bond threw an item in level. also checks if item was
// attached to an object (item is stationary within level). so make sure command
// 58 takes priority over command 57 when using both commands
//===========================================================================*/
#define if_item_is_stationary_within_level_ID 0x57
#define if_item_is_stationary_within_level_LENGTH 0x03
#define if_item_is_stationary_within_level(item_num, label) \
        if_item_is_stationary_within_level_ID, \
        item_num, \
        label,

/*=============================================================================
// name: if_item_is_attached_to_object
// command id: 58
// info: if item was thrown onto tagged object, goto label
//=============================================================================
// note: used to check if bond threw an item onto a tagged object. if used with
// command 57, make sure command 58 take priority over command 57
//===========================================================================*/
#define if_item_is_attached_to_object_ID 0x58
#define if_item_is_attached_to_object_LENGTH 0x04
#define if_item_is_attached_to_object(item_num, object_tag, label) \
        if_item_is_attached_to_object_ID, \
        item_num, \
        object_tag, \
        label,

/*=============================================================================
// name: if_bond_has_item_equipped
// command id: 59
// info: if bond has an item equipped (currently held), goto label
//===========================================================================*/
#define if_bond_has_item_equipped_ID 0x59
#define if_bond_has_item_equipped_LENGTH 0x03
#define if_bond_has_item_equipped(item_num, label) \
        if_bond_has_item_equipped_ID, \
        item_num, \
        label,

/*=============================================================================
// name: if_object_exists
// command id: 5A
// info: if tagged object exists in level, goto label
//===========================================================================*/
#define if_object_exists_ID 0x5A
#define if_object_exists_LENGTH 0x03
#define if_object_exists(object_tag, label) \
        if_object_exists_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: if_object_not_destroyed
// command id: 5B
// info: if tagged object is not destroyed, goto label
//===========================================================================*/
#define if_object_not_destroyed_ID 0x5B
#define if_object_not_destroyed_LENGTH 0x03
#define if_object_not_destroyed(object_tag, label) \
        if_object_not_destroyed_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: if_object_was_activated
// command id: 5C
// info: if tagged object was activated since last check, goto label
//=============================================================================
// note: when executed, it will clear tagged object's activated flag. only bond
// and command 5E can activate tagged objects. bond cannot activate destroyed
// objects
//===========================================================================*/
#define if_object_was_activated_ID 0x5C
#define if_object_was_activated_LENGTH 0x03
#define if_object_was_activated(object_tag, label) \
        if_object_was_activated_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: if_bond_used_gadget_on_object
// command id: 5D
// info: if bond used a gadget item on a tagged object since last check, goto label
//=============================================================================
// note: gadgets are a pre-defined list of items set to gadget flag:
// ITEM_BOMBDEFUSER
// ITEM_DATATHIEF
// ITEM_DOORDECODER
// ITEM_EXPLOSIVEFLOPPY
// ITEM_DATTAPE
//===========================================================================*/
#define if_bond_used_gadget_on_object_ID 0x5D
#define if_bond_used_gadget_on_object_LENGTH 0x03
#define if_bond_used_gadget_on_object(object_tag, label) \
        if_bond_used_gadget_on_object_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: object_activate
// command id: 5E
// info: activate a tagged object
//=============================================================================
// note: command does not check if object has been destroyed
//===========================================================================*/
#define object_activate_ID 0x5E
#define object_activate_LENGTH 0x02
#define object_activate(object_tag) \
        object_activate_ID, \
        object_tag,

/*=============================================================================
// name: object_destroy
// command id: 5F
// info: destroy/explode a tagged object
//=============================================================================
// note: only works if object is not destroyed. cannot destroy invincible objects
//===========================================================================*/
#define object_destroy_ID 0x5F
#define object_destroy_LENGTH 0x02
#define object_destroy(object_tag) \
        object_destroy_ID, \
        object_tag,

/*=============================================================================
// name: object_drop_from_chr
// command id: 60
// info: drop tagged object held/attached to chr
//=============================================================================
// note: item must be held/attached to a chr. embedded objects will not drop,
//       only works with attached objects. props can be damaged on drop
//===========================================================================*/
#define object_drop_from_chr_ID 0x60
#define object_drop_from_chr_LENGTH 0x02
#define object_drop_from_chr(object_tag) \
        object_drop_from_chr_ID, \
        object_tag,

/*=============================================================================
// name: chr_drop_all_concealed_items
// command id: 61
// info: make chr drop all concealed attachments
//=============================================================================
// note: item must be attached to chr, to drop held items use command 62. embedded
// objects will not drop, only works with attached objects. props can be damaged
// on drop
//===========================================================================*/
#define chr_drop_all_concealed_items_ID 0x61
#define chr_drop_all_concealed_items_LENGTH 0x02
#define chr_drop_all_concealed_items(chr_num) \
        chr_drop_all_concealed_items_ID, \
        chr_num,

/*=============================================================================
// name: chr_drop_all_held_items
// command id: 62
// info: make chr drop all held items
//=============================================================================
// note: items must be held by chr, to drop concealed attachments use command 61.
// embedded objects will not drop, only works with attached objects
//===========================================================================*/
#define chr_drop_all_held_items_ID 0x62
#define chr_drop_all_held_items_LENGTH 0x02
#define chr_drop_all_held_items(chr_num) \
        chr_drop_all_held_items_ID, \
        chr_num,

/*=============================================================================
// name: bond_collect_object
// command id: 63
// info: force bond to instantly collect a tagged object
//=============================================================================
// note: does not trigger bottom text telling player they collected an item
//===========================================================================*/
#define bond_collect_object_ID 0x63
#define bond_collect_object_LENGTH 0x02
#define bond_collect_object(object_tag) \
        bond_collect_object_ID, \
        object_tag,

/*=============================================================================
// name: chr_equip_object
// command id: 64
// info: makes chr hold tagged object
//=============================================================================
// note: if chr's hands are occupied, object will be equipped as an concealed
// attachment. but if tagged object's GUNHAND flag is free on guard then
// guard will equip weapon. tagged object's prop must have a holding position
// command within the model file
//===========================================================================*/
#define chr_equip_object_ID 0x64
#define chr_equip_object_LENGTH 0x03
#define chr_equip_object(object_tag, chr_num) \
        chr_equip_object_ID, \
        object_tag, \
        chr_num,

/*=============================================================================
// name: object_move_to_pad
// command id: 65
// info: move object to pad
//=============================================================================
// note: if object is assigned to padextra type, then object scale will be lost
//       after moving to target pad. object will inherit rotation from target pad
//===========================================================================*/
#define object_move_to_pad_ID 0x65
#define object_move_to_pad_LENGTH 0x04
#define object_move_to_pad(object_tag, pad) \
        object_move_to_pad_ID, \
        object_tag, \
        CharArrayFrom16Rev(pad),

/*=============================================================================
// name: door_open
// command id: 66
// info: open tagged door
//=============================================================================
// note: open tagged door even if locked
//===========================================================================*/
#define door_open_ID 0x66
#define door_open_LENGTH 0x02
#define door_open(object_tag) \
        door_open_ID, \
        object_tag,

/*=============================================================================
// name: door_close
// command id: 67
// info: close tagged door
//===========================================================================*/
#define door_close_ID 0x67
#define door_close_LENGTH 0x02
#define door_close(object_tag) \
        door_close_ID, \
        object_tag,

/*=============================================================================
// name: if_door_state_equal
// command id: 68
// info: if tagged door state matches any of bitfield argument, goto label
//=============================================================================
// note: use DOOR_STATE_# flags for door state argument. flags can be combined
//===========================================================================*/
#define if_door_state_equal_ID 0x68
#define if_door_state_equal_LENGTH 0x04
#define if_door_state_equal(object_tag, door_state, label) \
        if_door_state_equal_ID, \
        object_tag, \
        door_state, \
        label,

/*=============================================================================
// name: if_door_has_been_opened_before
// command id: 69
// info: if tagged door has been opened before, goto label
//=============================================================================
// note: if tagged door is open by default in setup, then it must be closed before
//       it will check if opened again
//===========================================================================*/
#define if_door_has_been_opened_before_ID 0x69
#define if_door_has_been_opened_before_LENGTH 0x03
#define if_door_has_been_opened_before(object_tag, label) \
        if_door_has_been_opened_before_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: door_set_lock
// command id: 6A
// info: set tagged door's lock with flags
//=============================================================================
// note: use DOOR_LOCK_# flags for lock argument. lock flags are same as used
//       within setup for doors and keys
//===========================================================================*/
#define door_set_lock_ID 0x6A
#define door_set_lock_LENGTH 0x03
#define door_set_lock(object_tag, lock_flag) \
        door_set_lock_ID, \
        object_tag, \
        lock_flag,

/*=============================================================================
// name: door_unset_lock
// command id: 6B
// info: unset tagged door's lock with flags
//=============================================================================
// note: use DOOR_LOCK_# flags for lock argument. lock flags are same as used
//       within setup for doors and keys
//===========================================================================*/
#define door_unset_lock_ID 0x6B
#define door_unset_lock_LENGTH 0x03
#define door_unset_lock(object_tag, lock_flag) \
        door_unset_lock_ID, \
        object_tag, \
        lock_flag,

/*=============================================================================
// name: if_door_lock_equal
// command id: 6C
// info: if tagged door's lock flags matches any lock flag argument, goto label
//=============================================================================
// note: use DOOR_LOCK_# flags for lock argument. lock flags are same as used
//       within setup for doors and keys
//===========================================================================*/
#define if_door_lock_equal_ID 0x6C
#define if_door_lock_equal_LENGTH 0x04
#define if_door_lock_equal(object_tag, lock_flag, label) \
        if_door_lock_equal_ID, \
        object_tag, \
        lock_flag, \
        label,

/*=============================================================================
// name: if_objective_num_complete
// command id: 6D
// info: if objective # completed, goto label
//=============================================================================
// note: ignores difficulty settings. for example - if game on agent and player
// completes an unlisted 00 agent objective, checking that objective num will
// goto label
//===========================================================================*/
#define if_objective_num_complete_ID 0x6D
#define if_objective_num_complete_LENGTH 0x03
#define if_objective_num_complete(obj_num, label) \
        if_objective_num_complete_ID, \
        obj_num, \
        label,

/*=============================================================================
// name: guard_try_unknown6E
// command id: 6E
// info: unknown command, goto label
//=============================================================================
// note: sets chr->padpreset1
// bitfield (hex):
// 0001: sets to nearest pad to path to bond
// 0004: ???
// 0008: ???
// 0010: ???
// 0020: ???
//===========================================================================*/
#define guard_try_unknown6E_ID 0x6E
#define guard_try_unknown6E_LENGTH 0x03
#define guard_try_unknown6E(unknown_flag, label) \
        guard_try_unknown6E_ID, \
        unknown_flag, \
        label,

/*=============================================================================
// name: guard_try_unknown6F
// command id: 6F
// info: unknown command, goto label
//=============================================================================
// note: sets chr->padpreset1
// bitfield (hex):
// 0001: set to nearest pad in direction of bond
// 0004: ???
// 0008: ???
// 0010: ???
// 0020: ???
//===========================================================================*/
#define guard_try_unknown6F_ID 0x6F
#define guard_try_unknown6F_LENGTH 0x03
#define guard_try_unknown6F(unknown_flag, label) \
        guard_try_unknown6F_ID, \
        unknown_flag, \
        label,

/*=============================================================================
// name: if_game_difficulty_less_than
// command id: 70
// info: if current difficulty < difficulty argument, goto label
//=============================================================================
// note: provided argument will compare the following difficult settings
// 01: agent only
// 02: agent/secret agent
// 03: agent/secret agent/00 agent
//===========================================================================*/
#define if_game_difficulty_less_than_ID 0x70
#define if_game_difficulty_less_than_LENGTH 0x03
#define if_game_difficulty_less_than(argument, label) \
        if_game_difficulty_less_than_ID, \
        argument, \
        label,

/*=============================================================================
// name: if_game_difficulty_greater_than
// command id: 71
// info: if current difficulty > difficulty argument, goto label
//=============================================================================
// note: provided argument will compare the following difficult settings
// 00: secret agent/00 agent/007
// 01: 00 agent/007
// 02: 007 only
//===========================================================================*/
#define if_game_difficulty_greater_than_ID 0x71
#define if_game_difficulty_greater_than_LENGTH 0x03
#define if_game_difficulty_greater_than(argument, label) \
        if_game_difficulty_greater_than_ID, \
        argument, \
        label,

/*=============================================================================
// name: if_mission_time_less_than
// command id: 72
// info: if current mission time (in seconds) < seconds argument, goto label
//=============================================================================
// note: converts (unsigned) seconds to float and compares against mission timer
//===========================================================================*/
#define if_mission_time_less_than_ID 0x72
#define if_mission_time_less_than_LENGTH 0x04
#define if_mission_time_less_than(seconds, label) \
        if_mission_time_less_than_ID, \
        CharArrayFrom16Rev(seconds), \
        label,

/*=============================================================================
// name: if_mission_time_greater_than
// command id: 73
// info: if current mission time (in seconds) > seconds argument, goto label
//=============================================================================
// note: converts (unsigned) seconds to float and compares against mission timer
//===========================================================================*/
#define if_mission_time_greater_than_ID 0x73
#define if_mission_time_greater_than_LENGTH 0x04
#define if_mission_time_greater_than(seconds, label) \
        if_mission_time_greater_than_ID, \
        CharArrayFrom16Rev(seconds), \
        label,

/*=============================================================================
// name: if_system_power_time_less_than
// command id: 74
// info: if system powered on time (in minutes) < minutes argument, goto label
//=============================================================================
// note: converts (unsigned) minutes to float and compares against system time
//===========================================================================*/
#define if_system_power_time_less_than_ID 0x74
#define if_system_power_time_less_than_LENGTH 0x04
#define if_system_power_time_less_than(minutes, label) \
        if_system_power_time_less_than_ID, \
        CharArrayFrom16Rev(minutes), \
        label,

/*=============================================================================
// name: if_system_power_time_greater_than
// command id: 75
// info: if system powered on time (in minutes) > minutes argument, goto label
//=============================================================================
// note: converts (unsigned) minutes to float and compares against system time
//===========================================================================*/
#define if_system_power_time_greater_than_ID 0x75
#define if_system_power_time_greater_than_LENGTH 0x04
#define if_system_power_time_greater_than(minutes, label) \
        if_system_power_time_greater_than_ID, \
        CharArrayFrom16Rev(minutes), \
        label,

/*=============================================================================
// name: if_level_id_less_than
// command id: 76
// info: if current level id < level id argument, goto label
//=============================================================================
// note: level id uses LEVELID enum values, not briefing menu stage number
//===========================================================================*/
#define if_level_id_less_than_ID 0x76
#define if_level_id_less_than_LENGTH 0x03
#define if_level_id_less_than(level_id, label) \
        if_level_id_less_than_ID, \
        level_id, \
        label,

/*=============================================================================
// name: if_level_id_greater_than
// command id: 77
// info: if current level id > level id argument, goto label
//=============================================================================
// note: level id uses LEVELID enum values, not briefing menu stage number
//===========================================================================*/
#define if_level_id_greater_than_ID 0x77
#define if_level_id_greater_than_LENGTH 0x03
#define if_level_id_greater_than(level_id, label) \
        if_level_id_greater_than_ID, \
        level_id, \
        label,

/*=============================================================================
// name: if_guard_hits_less_than
// command id: 78
// info: if guard's hits taken < hit_num, goto label
//=============================================================================
// note: compares signed byte against chr->numarghs. hits count even if guard
//       is invincible
//===========================================================================*/
#define if_guard_hits_less_than_ID 0x78
#define if_guard_hits_less_than_LENGTH 0x03
#define if_guard_hits_less_than(hit_num, label) \
        if_guard_hits_less_than_ID, \
        hit_num, \
        label,

/*=============================================================================
// name: if_guard_hits_greater_than
// command id: 79
// info: if guard's hits taken > hit_num, goto label
//=============================================================================
// note: compares signed byte against chr->numarghs. hits count even if guard
//       is invincible
//===========================================================================*/
#define if_guard_hits_greater_than_ID 0x79
#define if_guard_hits_greater_than_LENGTH 0x03
#define if_guard_hits_greater_than(hit_num, label) \
        if_guard_hits_greater_than_ID, \
        hit_num, \
        label,

/*=============================================================================
// name: if_guard_hits_missed_less_than
// command id: 7A
// info: if bond's shot missed/landed near guard total < missed_num, goto label
//=============================================================================
// note: compares signed byte against chr->numclosearghs
//===========================================================================*/
#define if_guard_hits_missed_less_than_ID 0x7A
#define if_guard_hits_missed_less_than_LENGTH 0x03
#define if_guard_hits_missed_less_than(missed_num, label) \
        if_guard_hits_missed_less_than_ID, \
        missed_num, \
        label,

/*=============================================================================
// name: if_guard_hits_missed_greater_than
// command id: 7B
// info: if bond's shot missed/landed near guard total > missed_num, goto label
//=============================================================================
// note: compares signed byte argument against chr->numclosearghs
//===========================================================================*/
#define if_guard_hits_missed_greater_than_ID 0x7B
#define if_guard_hits_missed_greater_than_LENGTH 0x03
#define if_guard_hits_missed_greater_than(missed_num, label) \
        if_guard_hits_missed_greater_than_ID, \
        missed_num, \
        label,

/*=============================================================================
// name: if_chr_health_less_than
// command id: 7C
// info: if chr's health < health argument, goto label
//=============================================================================
// note: argument is unsigned. converted to float and compares different between
// chr->maxdamage - chr->damage. default guard health is 40 (0x28), or after
// float conversion 4.0f. armour is tested
//===========================================================================*/
#define if_chr_health_less_than_ID 0x7C
#define if_chr_health_less_than_LENGTH 0x04
#define if_chr_health_less_than(chr_num, health, label) \
        if_chr_health_less_than_ID, \
        chr_num, \
        health, \
        label,

/*=============================================================================
// name: if_chr_health_greater_than
// command id: 7D
// info: if chr's health > health argument, goto label
//=============================================================================
// note: argument is unsigned. converted to float and compares different between
// chr->maxdamage - chr->damage. default guard health is 40 (0x28), or after
// float conversion 4.0f. armour is tested
//===========================================================================*/
#define if_chr_health_greater_than_ID 0x7D
#define if_chr_health_greater_than_LENGTH 0x04
#define if_chr_health_greater_than(chr_num, health, label) \
        if_chr_health_greater_than_ID, \
        chr_num, \
        health, \
        label,

/*=============================================================================
// name: if_chr_was_damaged_since_last_check
// command id: 7E
// info: if chr has taken damage since last check, goto label
//=============================================================================
// note: checks chr->chrflags if CHRFLAG_WAS_DAMAGED is set. if true, unset flag
// and goto label. CHRFLAG_WAS_DAMAGED is set if guard took damage (not invincible)
//===========================================================================*/
#define if_chr_was_damaged_since_last_check_ID 0x7E
#define if_chr_was_damaged_since_last_check_LENGTH 0x03
#define if_chr_was_damaged_since_last_check(chr_num, label) \
        if_chr_was_damaged_since_last_check_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: if_bond_health_less_than
// command id: 7F
// info: if bond's health < health argument, goto label
//=============================================================================
// note: does not check armour. health argument is unsigned, argument range is
//       between 00 and FF, with FF equal to 100% health
//===========================================================================*/
#define if_bond_health_less_than_ID 0x7F
#define if_bond_health_less_than_LENGTH 0x03
#define if_bond_health_less_than(health, label) \
        if_bond_health_less_than_ID, \
        health, \
        label,

/*=============================================================================
// name: if_bond_health_greater_than
// command id: 80
// info: if bond's health > health argument, goto label
//=============================================================================
// note: does not check armour. health argument is unsigned, argument range is
//       between 00 and FF, with FF equal to 100% health
//===========================================================================*/
#define if_bond_health_greater_than_ID 0x80
#define if_bond_health_greater_than_LENGTH 0x03
#define if_bond_health_greater_than(health, label) \
        if_bond_health_greater_than_ID, \
        health, \
        label,

/*=============================================================================
// name: local_byte_1_set
// command id: 81
// info: set chr->flags byte value to byte argument
//=============================================================================
// note: argument is unsigned. this is a private byte that is stored in chr struct.
//       it can be used for anything. default value is 0
//===========================================================================*/
#define local_byte_1_set_ID 0x81
#define local_byte_1_set_LENGTH 0x02
#define local_byte_1_set(set_byte) \
        local_byte_1_set_ID, \
        set_byte,

/*=============================================================================
// name: local_byte_1_add
// command id: 82
// info: add byte argument to chr->flags byte value
//=============================================================================
// note: argument is unsigned, add value is clamped at 0xFF (255 dec). this is
// a private byte that is stored in chr struct. it can be used for anything.
// default value is 0
//===========================================================================*/
#define local_byte_1_add_ID 0x82
#define local_byte_1_add_LENGTH 0x02
#define local_byte_1_add(add_byte) \
        local_byte_1_add_ID, \
        add_byte,

/*=============================================================================
// name: local_byte_1_subtract
// command id: 83
// info: subtract byte argument from chr->flags byte value
//=============================================================================
// note: argument is unsigned, subtract value is clamped at 0. this is a private
// byte that is stored in chr struct. it can be used for anything. default value is 0
//===========================================================================*/
#define local_byte_1_subtract_ID 0x83
#define local_byte_1_subtract_LENGTH 0x02
#define local_byte_1_subtract(subtract_byte) \
        local_byte_1_subtract_ID, \
        subtract_byte,

/*=============================================================================
// name: if_local_byte_1_less_than
// command id: 84
// info: if chr->flags byte value < byte argument, goto label
//=============================================================================
// note: argument is unsigned. this is a private byte that is stored in chr struct.
//       it can be used for anything. default value is 0
//===========================================================================*/
#define if_local_byte_1_less_than_ID 0x84
#define if_local_byte_1_less_than_LENGTH 0x03
#define if_local_byte_1_less_than(compare_byte, label) \
        if_local_byte_1_less_than_ID, \
        compare_byte, \
        label,

/*=============================================================================
// name: if_local_byte_1_less_than_random_seed
// command id: 85
// info: if chr->flags byte value < chr->random, goto label
//=============================================================================
// note: chr->random must be pre-generated by command 33 before comparing. this
// is a private byte that is stored in chr struct. it can be used for anything.
// default value is 0
//===========================================================================*/
#define if_local_byte_1_less_than_random_seed_ID 0x85
#define if_local_byte_1_less_than_random_seed_LENGTH 0x02
#define if_local_byte_1_less_than_random_seed(label) \
        if_local_byte_1_less_than_random_seed_ID, \
        label,

/*=============================================================================
// name: local_byte_2_set
// command id: 86
// info: set chr->flags2 byte value to byte argument
//=============================================================================
// note: argument is unsigned. this is a private byte that is stored in chr struct.
//       it can be used for anything. default value is 0
//===========================================================================*/
#define local_byte_2_set_ID 0x86
#define local_byte_2_set_LENGTH 0x02
#define local_byte_2_set(set_byte) \
        local_byte_2_set_ID, \
        set_byte,

/*=============================================================================
// name: local_byte_2_add
// command id: 87
// info: add byte argument to chr->flags2 byte value
//=============================================================================
// note: argument is unsigned, add value is clamped at 0xFF (255 dec). this is
// a private byte that is stored in chr struct. it can be used for anything.
// default value is 0
//===========================================================================*/
#define local_byte_2_add_ID 0x87
#define local_byte_2_add_LENGTH 0x02
#define local_byte_2_add(add_byte) \
        local_byte_2_add_ID, \
        add_byte,

/*=============================================================================
// name: local_byte_2_subtract
// command id: 88
// info: subtract byte argument from chr->flags2 byte value
//=============================================================================
// note: argument is unsigned, subtract value is clamped at 0. this is a private
// byte that is stored in chr struct. it can be used for anything. default value is 0
//===========================================================================*/
#define local_byte_2_subtract_ID 0x88
#define local_byte_2_subtract_LENGTH 0x02
#define local_byte_2_subtract(subtract_byte) \
        local_byte_2_subtract_ID, \
        subtract_byte,

/*=============================================================================
// name: if_local_byte_2_less_than
// command id: 89
// info: if chr->flags2 byte value < byte argument, goto label
//=============================================================================
// note: argument is unsigned. this is a private byte that is stored in chr struct.
//       it can be used for anything. default value is 0
//===========================================================================*/
#define if_local_byte_2_less_than_ID 0x89
#define if_local_byte_2_less_than_LENGTH 0x03
#define if_local_byte_2_less_than(compare_byte, label) \
        if_local_byte_2_less_than_ID, \
        compare_byte, \
        label,

/*=============================================================================
// name: if_local_byte_2_less_than_random_seed
// command id: 8A
// info: if chr->flags2 byte value < chr->random, goto label
//=============================================================================
// note: chr->random must be pre-generated by command 33 before comparing. this
// is a private byte that is stored in chr struct. it can be used for anything.
// default value is 0
//===========================================================================*/
#define if_local_byte_2_less_than_random_seed_ID 0x8A
#define if_local_byte_2_less_than_random_seed_LENGTH 0x02
#define if_local_byte_2_less_than_random_seed(label) \
        if_local_byte_2_less_than_random_seed_ID, \
        label,

/*=============================================================================
// name: guard_set_hearing_scale
// command id: 8B
// info: set guard's hearing scale - the higher the value, the further away guard
//       can hear bond's gunfire
//=============================================================================
// note: sets to chr->hearingscale. default value is 0x03E8 (1000 dec). argument
//       is converted to float and divided by 1000 before setting to hearingscale
//===========================================================================*/
#define guard_set_hearing_scale_ID 0x8B
#define guard_set_hearing_scale_LENGTH 0x03
#define guard_set_hearing_scale(hearing_scale) \
        guard_set_hearing_scale_ID, \
        CharArrayFrom16Rev(hearing_scale),

/*=============================================================================
// name: guard_set_vision_range
// command id: 8C
// info: set guard's vision range - the smaller the value, the longer the guard
//       takes to detect bond with command 32. does not affect firing distance
//=============================================================================
// note: sets to chr->visionrange. default value is 0x0064 (100 dec). argument
//       is unsigned and converted to float before setting to hearingscale
//===========================================================================*/
#define guard_set_vision_range_ID 0x8C
#define guard_set_vision_range_LENGTH 0x02
#define guard_set_vision_range(vision_range) \
        guard_set_vision_range_ID, \
        vision_range,

/*=============================================================================
// name: guard_set_grenade_probability
// command id: 8D
// info: set guard's grenade probability - used for rng comparison by command 1A.
//       the higher the value, the likelyhood of guard throwing a grenade
//=============================================================================
// note: sets to chr->grenadeprob - 0 by default. argument is unsigned. the only
// way to make guards throw grenades is by using this command or assigning setup
// object 0x12 to chr
//===========================================================================*/
#define guard_set_grenade_probability_ID 0x8D
#define guard_set_grenade_probability_LENGTH 0x02
#define guard_set_grenade_probability(grenade_prob) \
        guard_set_grenade_probability_ID, \
        grenade_prob,

/*=============================================================================
// name: guard_set_chr_num
// command id: 8E
// info: set guard's chr num
//=============================================================================
// note: sets to chr->chrnum - commonly used for respawning guards
//===========================================================================*/
#define guard_set_chr_num_ID 0x8E
#define guard_set_chr_num_LENGTH 0x02
#define guard_set_chr_num(chr_num) \
        guard_set_chr_num_ID, \
        chr_num,

/*=============================================================================
// name: guard_set_health_total
// command id: 8F
// info: set guard's total health - the higher the value, the more shots needed
//       to kill guard.
//=============================================================================
// note: sets to chr->maxdamage. default health is 4.0f (0x0028/40 dec for argument).
// argument is converted to float and divided by 10 before setting to maxdamage.
// if difficulty mode 007 is active, command will use 007 health modifier
//===========================================================================*/
#define guard_set_health_total_ID 0x8F
#define guard_set_health_total_LENGTH 0x03
#define guard_set_health_total(total_health) \
        guard_set_health_total_ID, \
        CharArrayFrom16Rev(total_health),

/*=============================================================================
// name: guard_set_armour
// command id: 90
// info: set guard's armour value - the higher the value, the higher the armour.
// armoured guards will not show hit reactions. they also don't instantly die
// from explosions, instead taking damaged based on how close they are to explosions
// like bond. to any setup designers reading this, please use armour sparingly!
//=============================================================================
// note: subtracts from chr->damage - negative damage means guard has armour.
// instead of storing armour as a separate chr variable, we reuse the current
// damage and read negative damage as armour. technically this command should
// be titled 'guard_remove_damage' but its used mostly for adding armour to guards.
// argument is converted to float and divided by 10 before subtracting chr->damage.
// if difficulty mode 007 is active, command will use 007 health modifier.
// argument is unsigned - 0xFFFF will be set to 6553.5f armour, or -6553.5f damage
//===========================================================================*/
#define guard_set_armour_ID 0x90
#define guard_set_armour_LENGTH 0x03
#define guard_set_armour(armour_value) \
        guard_set_armour_ID, \
        CharArrayFrom16Rev(armour_value),

/*=============================================================================
// name: guard_set_speed_rating
// command id: 91
// info: set guard's speed rating - controls how quickly the guard animates.
//=============================================================================
// note: sets to chr->speedrating. default speed is 0 - argument is signed.
// negative values will make guard animate slower - this affects firing animations.
// command does not use 007 reaction speed modifier. do not use values above/below
// 100 or it may crash
//===========================================================================*/
#define guard_set_speed_rating_ID 0x91
#define guard_set_speed_rating_LENGTH 0x02
#define guard_set_speed_rating(speed_rating) \
        guard_set_speed_rating_ID, \
        speed_rating,

/*=============================================================================
// name: guard_set_argh_rating
// command id: 92
// info: set guard's argh rating - controls how quickly the guard recovers from
//       being shot. range is -100 to 100 (100 show almost no hit reaction)
//=============================================================================
// note: sets to chr->arghrating. default value is 0 - argument is signed.
// negative values will make guard animate slower - this affects firing animations.
// command does not use 007 reaction speed modifier
//===========================================================================*/
#define guard_set_argh_rating_ID 0x92
#define guard_set_argh_rating_LENGTH 0x02
#define guard_set_argh_rating(speed_rating) \
        guard_set_argh_rating_ID, \
        speed_rating,

/*=============================================================================
// name: guard_set_accuracy_rating
// command id: 93
// info: set guard's accuracy rating - controls how accurately the guard fires
//       their weapon
//=============================================================================
// note: sets to chr->accuracyrating. default value is 0 and ranges from -100
// to 100, argument is signed byte. command does not use 007 accuracy modifier
//===========================================================================*/
#define guard_set_accuracy_rating_ID 0x93
#define guard_set_accuracy_rating_LENGTH 0x02
#define guard_set_accuracy_rating(accuracy_rating) \
        guard_set_accuracy_rating_ID, \
        accuracy_rating,

/*=============================================================================
// name: guard_bitfield_set_on
// command id: 94
// info: set chr->BITFIELD on
//=============================================================================
// note: can be used to store a custom flag per chr, useful for missions. global
// lists use flag 01, which is defined as FLAGS2_DONT_POINT_AT_BOND. other bits
// are free to use for setup's ai lists. can be used by obj ai lists, obj lists
// are free to utilize the entire spectrum of flags
//===========================================================================*/
#define guard_bitfield_set_on_ID 0x94
#define guard_bitfield_set_on_LENGTH 0x02
#define guard_bitfield_set_on(bitfield) \
        guard_bitfield_set_on_ID, \
        bitfield,

/*=============================================================================
// name: guard_bitfield_set_off
// command id: 95
// info: set chr->BITFIELD off
//=============================================================================
// note: can be used to store a custom flag per chr, useful for missions. global
// lists use flag 01, which is defined as FLAGS2_DONT_POINT_AT_BOND. other bits
// are free to use for setup's ai lists. can be used by obj ai lists, obj lists
// are free to utilize the entire spectrum of flags
//===========================================================================*/
#define guard_bitfield_set_off_ID 0x95
#define guard_bitfield_set_off_LENGTH 0x02
#define guard_bitfield_set_off(bitfield) \
        guard_bitfield_set_off_ID, \
        bitfield,

/*=============================================================================
// name: if_guard_bitfield_is_set_on
// command id: 96
// info: if any bits in argument are set on in chr->BITFIELD, goto label
//=============================================================================
// note: can be used by obj ai lists, obj lists are free to utilize the entire
//       spectrum of flags
//===========================================================================*/
#define if_guard_bitfield_is_set_on_ID 0x96
#define if_guard_bitfield_is_set_on_LENGTH 0x03
#define if_guard_bitfield_is_set_on(bitfield, label) \
        if_guard_bitfield_is_set_on_ID, \
        bitfield, \
        label,

/*=============================================================================
// name: chr_bitfield_set_on
// command id: 97
// info: set chr->BITFIELD on
//=============================================================================
// note: can be used to store a custom flag per chr, useful for missions. global
// lists use flag 01, which is defined as FLAGS2_DONT_POINT_AT_BOND. other bits
// are free to use for setup's ai lists
//===========================================================================*/
#define chr_bitfield_set_on_ID 0x97
#define chr_bitfield_set_on_LENGTH 0x03
#define chr_bitfield_set_on(chr_num, bitfield) \
        chr_bitfield_set_on_ID, \
        chr_num, \
        bitfield,

/*=============================================================================
// name: chr_bitfield_set_off
// command id: 98
// info: set chr->BITFIELD off
//=============================================================================
// note: can be used to store a custom flag per chr, useful for missions. global
// lists use flag 01, which is defined as FLAGS2_DONT_POINT_AT_BOND. other bits
// are free to use for setup's ai lists
//===========================================================================*/
#define chr_bitfield_set_off_ID 0x98
#define chr_bitfield_set_off_LENGTH 0x03
#define chr_bitfield_set_off(chr_num, bitfield) \
        chr_bitfield_set_off_ID, \
        chr_num, \
        bitfield,

/*=============================================================================
// name: if_chr_bitfield_is_set_on
// command id: 99
// info: if any bits in argument are set on in chr->BITFIELD, goto label
//===========================================================================*/
#define if_chr_bitfield_is_set_on_ID 0x99
#define if_chr_bitfield_is_set_on_LENGTH 0x04
#define if_chr_bitfield_is_set_on(chr_num, bitfield, label) \
        if_chr_bitfield_is_set_on_ID, \
        chr_num, \
        bitfield, \
        label,

/*=============================================================================
// name: objective_bitfield_set_on
// command id: 9A
// info: set bits in objective bitfield on
//=============================================================================
// note: can be used to store a mission unique objective flag, which can be linked
// to mission objectives. it can also be used to store miscellaneous flags used
// by other ai lists. if a mission objective is changed while in third person,
// it will not be updated on the briefing page - all mission objectives status
// are locked while in third person
//===========================================================================*/
#define objective_bitfield_set_on_ID 0x9A
#define objective_bitfield_set_on_LENGTH 0x05
#define objective_bitfield_set_on(bitfield) \
        objective_bitfield_set_on_ID, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: objective_bitfield_set_off
// command id: 9B
// info: set bits in objective bitfield off
//=============================================================================
// note: can be used to store a mission unique objective flag, which can be linked
// to mission objectives. it can also be used to store miscellaneous flags used
// by other ai lists. if a mission objective is changed while in third person,
// it will not be updated on the briefing page - all mission objectives status
// are locked while in third person
//===========================================================================*/
#define objective_bitfield_set_off_ID 0x9B
#define objective_bitfield_set_off_LENGTH 0x05
#define objective_bitfield_set_off(bitfield) \
        objective_bitfield_set_off_ID, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: if_objective_bitfield_is_set_on
// command id: 9C
// info: if bits in objective bitfield are set on, goto label
//=============================================================================
// note: can check multiple flags at once
//===========================================================================*/
#define if_objective_bitfield_is_set_on_ID 0x9C
#define if_objective_bitfield_is_set_on_LENGTH 0x06
#define if_objective_bitfield_is_set_on(bitfield, label) \
        if_objective_bitfield_is_set_on_ID, \
        CharArrayFrom32Rev(bitfield), \
        label,

/*=============================================================================
// name: guard_flags_set_on
// command id: 9D
// info: set chr->chrflags on
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine. bitfield uses CHRFLAG_# defines. command can be
// used by obj ai lists, obj lists are free to utilize the entire spectrum of flags
//===========================================================================*/
#define guard_flags_set_on_ID 0x9D
#define guard_flags_set_on_LENGTH 0x05
#define guard_flags_set_on(bitfield) \
        guard_flags_set_on_ID, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: guard_flags_set_off
// command id: 9E
// info: set chr->chrflags off
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine. bitfield uses CHRFLAG_# defines. can be used by
// obj ai lists, obj lists are free to utilize the entire spectrum of flags
//===========================================================================*/
#define guard_flags_set_off_ID 0x9E
#define guard_flags_set_off_LENGTH 0x05
#define guard_flags_set_off(bitfield) \
        guard_flags_set_off_ID, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: if_guard_flags_is_set_on
// command id: 9F
// info: if bits is set on in chr->chrflags, goto label
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine. bitfield uses CHRFLAG_# defines. can be used by
// obj ai lists, obj lists are free to utilize the entire spectrum of flags
//===========================================================================*/
#define if_guard_flags_is_set_on_ID 0x9F
#define if_guard_flags_is_set_on_LENGTH 0x06
#define if_guard_flags_is_set_on(bitfield, label) \
        if_guard_flags_is_set_on_ID, \
        CharArrayFrom32Rev(bitfield), \
        label,

/*=============================================================================
// name: chr_flags_set_on
// command id: A0
// info: set chr->chrflags on
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine. bitfield uses CHRFLAG_# defines
//===========================================================================*/
#define chr_flags_set_on_ID 0xA0
#define chr_flags_set_on_LENGTH 0x06
#define chr_flags_set_on(chr_num, bitfield) \
        chr_flags_set_on_ID, \
        chr_num, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: chr_flags_set_off
// command id: A1
// info: set chr->chrflags off
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine. bitfield uses CHRFLAG_# defines
//===========================================================================*/
#define chr_flags_set_off_ID 0xA1
#define chr_flags_set_off_LENGTH 0x06
#define chr_flags_set_off(chr_num, bitfield) \
        chr_flags_set_off_ID, \
        chr_num, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: if_chr_flags_is_set_on
// command id: A2
// info: if bits is set on in chr->chrflags, goto label
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine. bitfield uses CHRFLAG_# defines
//===========================================================================*/
#define if_chr_flags_is_set_on_ID 0xA2
#define if_chr_flags_is_set_on_LENGTH 0x07
#define if_chr_flags_is_set_on(chr_num, bitfield, label) \
        if_chr_flags_is_set_on_ID, \
        chr_num, \
        CharArrayFrom32Rev(bitfield), \
        label,

/*=============================================================================
// name: object_flags_1_set_on
// command id: A3
// info: set object->propflags on
//=============================================================================
// note: bitfield uses PROPFLAG_# defines
//===========================================================================*/
#define object_flags_1_set_on_ID 0xA3
#define object_flags_1_set_on_LENGTH 0x06
#define object_flags_1_set_on(object_tag, bitfield) \
        object_flags_1_set_on_ID, \
        object_tag, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: object_flags_1_set_off
// command id: A4
// info: set object->propflags off
//=============================================================================
// note: bitfield uses PROPFLAG_# defines
//===========================================================================*/
#define object_flags_1_set_off_ID 0xA4
#define object_flags_1_set_off_LENGTH 0x06
#define object_flags_1_set_off(object_tag, bitfield) \
        object_flags_1_set_off_ID, \
        object_tag, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: if_object_flags_1_is_set_on
// command id: A5
// info: if bits is set on in object->propflags, goto label
//=============================================================================
// note: bitfield uses PROPFLAG_# defines
//===========================================================================*/
#define if_object_flags_1_is_set_on_ID 0xA5
#define if_object_flags_1_is_set_on_LENGTH 0x07
#define if_object_flags_1_is_set_on(object_tag, bitfield, label) \
        if_object_flags_1_is_set_on_ID, \
        object_tag, \
        CharArrayFrom32Rev(bitfield), \
        label,

/*=============================================================================
// name: object_flags_2_set_on
// command id: A6
// info: set object->propflags2 on
//=============================================================================
// note: bitfield uses PROPFLAG2_# defines
//===========================================================================*/
#define object_flags_2_set_on_ID 0xA6
#define object_flags_2_set_on_LENGTH 0x06
#define object_flags_2_set_on(object_tag, bitfield) \
        object_flags_2_set_on_ID, \
        object_tag, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: object_flags_2_set_off
// command id: A7
// info: set object->propflags2 off
//=============================================================================
// note: bitfield uses PROPFLAG2_# defines
//===========================================================================*/
#define object_flags_2_set_off_ID 0xA7
#define object_flags_2_set_off_LENGTH 0x06
#define object_flags_2_set_off(object_tag, bitfield) \
        object_flags_2_set_off_ID, \
        object_tag, \
        CharArrayFrom32Rev(bitfield),

/*=============================================================================
// name: if_object_flags_2_is_set_on
// command id: A8
// info: if bits is set on in object->propflags2, goto label
//=============================================================================
// note: bitfield uses PROPFLAG2_# defines
//===========================================================================*/
#define if_object_flags_2_is_set_on_ID 0xA8
#define if_object_flags_2_is_set_on_LENGTH 0x07
#define if_object_flags_2_is_set_on(object_tag, bitfield, label) \
        if_object_flags_2_is_set_on_ID, \
        object_tag, \
        CharArrayFrom32Rev(bitfield), \
        label,

/*=============================================================================
// name: guard_set_chr_preset
// command id: A9
// info: set guard->chrpreset1 to chr_preset
//=============================================================================
// note: can be used by obj ai lists
//===========================================================================*/
#define guard_set_chr_preset_ID 0xA9
#define guard_set_chr_preset_LENGTH 0x02
#define guard_set_chr_preset(chr_preset) \
        guard_set_chr_preset_ID, \
        chr_preset,

/*=============================================================================
// name: chr_set_chr_preset
// command id: AA
// info: set chr->chrpreset1 to chr_preset
//===========================================================================*/
#define chr_set_chr_preset_ID 0xAA
#define chr_set_chr_preset_LENGTH 0x03
#define chr_set_chr_preset(chr_num, chr_preset) \
        chr_set_chr_preset_ID, \
        chr_num, \
        chr_preset,

/*=============================================================================
// name: guard_set_pad_preset
// command id: AB
// info: set guard->padpreset1 to pad_preset
//=============================================================================
// note: can be used by obj ai lists
//===========================================================================*/
#define guard_set_pad_preset_ID 0xAB
#define guard_set_pad_preset_LENGTH 0x03
#define guard_set_pad_preset(pad_preset) \
        guard_set_pad_preset_ID, \
        CharArrayFrom16Rev(pad_preset),

/*=============================================================================
// name: chr_set_pad_preset
// command id: AC
// info: set chr->padpreset1 to pad_preset
//===========================================================================*/
#define chr_set_pad_preset_ID 0xAC
#define chr_set_pad_preset_LENGTH 0x04
#define chr_set_pad_preset(chr_num, pad_preset) \
        chr_set_pad_preset_ID, \
        chr_num, \
        CharArrayFrom16Rev(pad_preset),

/*=============================================================================
// name: debug_log
// command id: AD
// info: debug comment
//=============================================================================
// note: may have originally printed to stderr on host sgi devkit. command is
// variable length must end with null terminator character '\0' (debug_log_end)
//===========================================================================*/
#define debug_log_ID 0xAD
#define debug_log_LENGTH 0x32 // max length
#define debug_log \
        debug_log_ID,

/*=============================================================================
// name: local_timer_reset_start
// command id: AE
// info: reset and start chr->timer60
//=============================================================================
// note: local timer is different to hud countdown. local timer is unique for each chr,
// while hud countdown is global for the entire mission. chr->timer60 only counts up
//===========================================================================*/
#define local_timer_reset_start_ID 0xAE
#define local_timer_reset_start_LENGTH 0x01
#define local_timer_reset_start \
        local_timer_reset_start_ID,

/*=============================================================================
// name: local_timer_reset
// command id: AF
// info: reset chr->timer60
//=============================================================================
// note: local timer is different to hud countdown. local timer is unique for each chr,
// while hud countdown is global for the entire mission. chr->timer60 only counts up
//===========================================================================*/
#define local_timer_reset_ID 0xAF
#define local_timer_reset_LENGTH 0x01
#define local_timer_reset \
        local_timer_reset_ID,

/*=============================================================================
// name: local_timer_stop
// command id: B0
// info: pauses chr->timer60 (does not reset value)
//=============================================================================
// note: local timer is different to hud countdown. local timer is unique for each chr,
// while hud countdown is global for the entire mission. chr->timer60 only counts up
//===========================================================================*/
#define local_timer_stop_ID 0xB0
#define local_timer_stop_LENGTH 0x01
#define local_timer_stop \
        local_timer_stop_ID,

/*=============================================================================
// name: local_timer_start
// command id: B1
// info: start chr->timer60 (does not reset value)
//=============================================================================
// note: local timer is different to hud countdown. local timer is unique for each chr,
// while hud countdown is global for the entire mission. chr->timer60 only counts up
//===========================================================================*/
#define local_timer_start_ID 0xB1
#define local_timer_start_LENGTH 0x01
#define local_timer_start \
        local_timer_start_ID,

/*=============================================================================
// name: if_local_timer_has_stopped
// command id: B2
// info: if chr->timer60 is not active (paused), goto label
//=============================================================================
// note: by default, chr->timer60 is inactive
//===========================================================================*/
#define if_local_timer_has_stopped_ID 0xB2
#define if_local_timer_has_stopped_LENGTH 0x02
#define if_local_timer_has_stopped(label) \
        if_local_timer_has_stopped_ID, \
        label,

/*=============================================================================
// name: if_local_timer_less_than
// command id: B3
// info: if chr->timer60 < time60, goto label
//=============================================================================
// note: time60 argument is converted to float from unsigned int and compared.
//       chr->timer60 only counts up
//===========================================================================*/
#define if_local_timer_less_than_ID 0xB3
#define if_local_timer_less_than_LENGTH 0x05
#define if_local_timer_less_than(time60, label) \
        if_local_timer_less_than_ID, \
        CharArrayFrom24Rev(time60), \
        label,

/*=============================================================================
// name: if_local_timer_greater_than
// command id: B4
// info: if chr->timer60 > time60, goto label
//=============================================================================
// note: time60 argument is converted to float from unsigned int and compared.
//       chr->timer60 only counts up
//===========================================================================*/
#define if_local_timer_greater_than_ID 0xB4
#define if_local_timer_greater_than_LENGTH 0x05
#define if_local_timer_greater_than(time60, label) \
        if_local_timer_greater_than_ID, \
        CharArrayFrom24Rev(time60), \
        label,

/*=============================================================================
// name: hud_countdown_show
// command id: B5
//=============================================================================
// info: shows the hud countdown
//===========================================================================*/
#define hud_countdown_show_ID 0xB5
#define hud_countdown_show_LENGTH 0x01
#define hud_countdown_show \
        hud_countdown_show_ID,

/*=============================================================================
// name: hud_countdown_hide
// command id: B6
// info: hides the hud countdown
//=============================================================================
// note: can be used as a hidden global timer for objective logic
//===========================================================================*/
#define hud_countdown_hide_ID 0xB6
#define hud_countdown_hide_LENGTH 0x01
#define hud_countdown_hide \
        hud_countdown_hide_ID,

/*=============================================================================
// name: hud_countdown_set
// command id: B7
// info: set the hud countdown
//=============================================================================
// note: to make the timer count up, set to 0 and start timer
//===========================================================================*/
#define hud_countdown_set_ID 0xB7
#define hud_countdown_set_LENGTH 0x03
#define hud_countdown_set(seconds) \
        hud_countdown_set_ID, \
        CharArrayFrom16Rev(seconds),

/*=============================================================================
// name: hud_countdown_stop
// command id: B8
// info: stops the hud countdown
//===========================================================================*/
#define hud_countdown_stop_ID 0xB8
#define hud_countdown_stop_LENGTH 0x01
#define hud_countdown_stop \
        hud_countdown_stop_ID,

/*=============================================================================
// name: hud_countdown_start
// command id: B9
// info: start the hud countdown
//===========================================================================*/
#define hud_countdown_start_ID 0xB9
#define hud_countdown_start_LENGTH 0x01
#define hud_countdown_start \
        hud_countdown_start_ID,

/*=============================================================================
// name: if_hud_countdown_has_stopped
// command id: BA
// info: if hud countdown isn't active (paused), goto label
//=============================================================================
// note: by default, hud countdown is inactive
//===========================================================================*/
#define if_hud_countdown_has_stopped_ID 0xBA
#define if_hud_countdown_has_stopped_LENGTH 0x02
#define if_hud_countdown_has_stopped(label) \
        if_hud_countdown_has_stopped_ID, \
        label,

/*=============================================================================
// name: if_hud_countdown_less_than
// command id: BB
// info: if hud countdown < seconds, goto label
//=============================================================================
// note: if seconds argument is 0, it will only goto label if timer is less than
// zero (counting up). seconds value is unsigned and can't test negative values
//===========================================================================*/
#define if_hud_countdown_less_than_ID 0xBB
#define if_hud_countdown_less_than_LENGTH 0x04
#define if_hud_countdown_less_than(seconds, label) \
        if_hud_countdown_less_than_ID, \
        CharArrayFrom16Rev(seconds), \
        label,

/*=============================================================================
// name: if_hud_countdown_greater_than
// command id: BC
// info: if hud countdown > seconds, goto label
//=============================================================================
// note: if seconds argument is 0, it will only goto label if timer is greater than
// zero (counting down). seconds value is unsigned and can't test negative values
//===========================================================================*/
#define if_hud_countdown_greater_than_ID 0xBC
#define if_hud_countdown_greater_than_LENGTH 0x04
#define if_hud_countdown_greater_than(seconds, label) \
        if_hud_countdown_greater_than_ID, \
        CharArrayFrom16Rev(seconds), \
        label,

/*=============================================================================
// name: chr_try_spawning_at_pad
// command id: BD
// info: spawn chr at pad, goto label if successful
//=============================================================================
// note: if out of memory/can't spawn chr, do not goto label. if pad is blocked,
//       attempt to spawn chr around pad. bitfield uses SPAWN_# defines
//===========================================================================*/
#define chr_try_spawning_at_pad_ID 0xBD
#define chr_try_spawning_at_pad_LENGTH 0x0C
#define chr_try_spawning_at_pad(body_num, head_num, pad, ai_list, bitfield, label) \
        chr_try_spawning_at_pad_ID, \
        body_num, \
        head_num, \
        CharArrayFrom16Rev(pad), \
        CharArrayFrom16Rev(ai_list), \
        CharArrayFrom32Rev(bitfield), \
        label,

/*=============================================================================
// name: chr_try_spawning_next_to_unseen_chr
// command id: BE
// info: spawn a chr next to another chr, goto label if successful
//=============================================================================
// note: if out of memory/can't spawn chr, do not goto label. bitfield uses SPAWN_# defines.
// target chr must still exist in level or else command will crash. command will
// not spawn chr if target chr has been seen before (CHRFLAG_HAS_BEEN_ON_SCREEN)
//===========================================================================*/
#define chr_try_spawning_next_to_unseen_chr_ID 0xBE
#define chr_try_spawning_next_to_unseen_chr_LENGTH 0x0B
#define chr_try_spawning_next_to_unseen_chr(body_num, head_num, chr_num_target, ai_list, bitfield, label) \
        chr_try_spawning_next_to_unseen_chr_ID, \
        body_num, \
        head_num, \
        chr_num_target, \
        CharArrayFrom16Rev(ai_list), \
        CharArrayFrom32Rev(bitfield), \
        label,

/*=============================================================================
// name: guard_try_spawning_item
// command id: BF
// info: spawn weapon for guard, goto label if successful
//=============================================================================
// note: if out of memory/can't spawn item/hands occupied, do not goto label.
// spawned prop must have a holding position command within the model file,
// else use conceal flag so guard does not attempt to hold prop
//===========================================================================*/
#define guard_try_spawning_item_ID 0xBF
#define guard_try_spawning_item_LENGTH 0x09
#define guard_try_spawning_item(prop_num, item_num, prop_bitfield, label) \
        guard_try_spawning_item_ID, \
        CharArrayFrom16Rev(prop_num), \
        item_num, \
        CharArrayFrom32Rev(prop_bitfield), \
        label,

/*=============================================================================
// name: guard_try_spawning_hat
// command id: C0
// info: spawn hat for guard, goto label if successful
//=============================================================================
// note: if out of memory/can't spawn item/already have hat, do not goto label.
// spawned hat must have a holding position command within the model file
//===========================================================================*/
#define guard_try_spawning_hat_ID 0xC0
#define guard_try_spawning_hat_LENGTH 0x08
#define guard_try_spawning_hat(prop_num, prop_bitfield, label) \
        guard_try_spawning_hat_ID, \
        CharArrayFrom16Rev(prop_num), \
        CharArrayFrom32Rev(prop_bitfield), \
        label,

/*=============================================================================
// name: chr_try_spawning_clone
// command id: C1
// info: if guard has clone flag on, spawn a new guard - goto label if successful
//=============================================================================
// note: clone flag is stored in chr->chrflags which is assigned at setup init.
//       newly spawned guard is placed in front of original guard
//===========================================================================*/
#define chr_try_spawning_clone_ID 0xC1
#define chr_try_spawning_clone_LENGTH 0x05
#define chr_try_spawning_clone(chr_num, ai_list, label) \
        chr_try_spawning_clone_ID, \
        chr_num, \
        CharArrayFrom16Rev(ai_list), \
        label,

/*=============================================================================
// name: text_print_bottom
// command id: C2
// info: print text slot to bottom left part of screen (where pickup text is located)
//=============================================================================
// note: if text slot is not currently allocated in memory, game will softlock.
// expects string to end with \n character
//===========================================================================*/
#define text_print_bottom_ID 0xC2
#define text_print_bottom_LENGTH 0x03
#define text_print_bottom(text_slot) \
        text_print_bottom_ID, \
        CharArrayFrom16Rev(text_slot),

/*=============================================================================
// name: text_print_top
// command id: C3
// info: print text slot to top part of screen
//=============================================================================
// note: if text slot is not currently allocated in memory, game will softlock.
// ensure that end of text has a \n character or text background will be misaligned
//===========================================================================*/
#define text_print_top_ID 0xC3
#define text_print_top_LENGTH 0x03
#define text_print_top(text_slot) \
        text_print_top_ID, \
        CharArrayFrom16Rev(text_slot),

/*=============================================================================
// name: sfx_play
// command id: C4
// info: play a sound effect
//=============================================================================
// note: channel argument range is 0-7. use a channel if you plan on modifying
// sfx volume with commands C5-CA. if you don't plan on doing this, use a invalid
// channel such as -1. this will play the sfx but not bother initializing channel
// data for commands C5-CA. if a sfx is already occupying channel, retriggering
// sfx will overwrite old sfx slot data and no longer can be used by commands C5-CA
//===========================================================================*/
#define sfx_play_ID 0xC4
#define sfx_play_LENGTH 0x04
#define sfx_play(sound_num, channel_num) \
        sfx_play_ID, \
        CharArrayFrom16Rev(sound_num), \
        channel_num,

/*=============================================================================
// name: sfx_emit_from_object
// command id: C5
// info: set a occupied sfx channel to emit from a tagged object
//=============================================================================
// note: panning is not calculated (mono), only affects volume. decay argument
// is number of ticks to fully transition from max volume to target volume
//===========================================================================*/
#define sfx_emit_from_object_ID 0xC5
#define sfx_emit_from_object_LENGTH 0x05
#define sfx_emit_from_object(channel_num, object_tag, vol_decay_time60) \
        sfx_emit_from_object_ID, \
        channel_num, \
        object_tag, \
        CharArrayFrom16Rev(vol_decay_time60),

/*=============================================================================
// name: sfx_emit_from_pad
// command id: C6
// info: set a occupied sfx channel to emit from a pad
//=============================================================================
// note: panning is not calculated (mono), only affects volume. decay argument
// is number of ticks to fully transition from max volume to target volume
//===========================================================================*/
#define sfx_emit_from_pad_ID 0xC6
#define sfx_emit_from_pad_LENGTH 0x06
#define sfx_emit_from_pad(channel_num, pad, vol_decay_time60) \
        sfx_emit_from_pad_ID, \
        channel_num, \
        CharArrayFrom16Rev(pad), \
        CharArrayFrom16Rev(vol_decay_time60),

/*=============================================================================
// name: sfx_set_channel_volume
// command id: C7
// info: set occupied sfx channel's volume
//=============================================================================
// note: time argument is number of ticks to fade between current volume to
// target volume. volume argument is signed. range is 0x0000-0x7FFF
//===========================================================================*/
#define sfx_set_channel_volume_ID 0xC7
#define sfx_set_channel_volume_LENGTH 0x06
#define sfx_set_channel_volume(channel_num, target_volume, transition_time60) \
        sfx_set_channel_volume_ID, \
        channel_num, \
        CharArrayFrom16Rev(target_volume), \
        CharArrayFrom16Rev(transition_time60),

/*=============================================================================
// name: sfx_fade_channel_volume
// command id: C8
// info: fade out occupied sfx channel's volume by volume percent
//=============================================================================
// note: time argument is number of ticks to fade between current volume to
// target volume. volume argument is signed. range is 0x0000-0x7FFF (0-100%)
//===========================================================================*/
#define sfx_fade_channel_volume_ID 0xC8
#define sfx_fade_channel_volume_LENGTH 0x06
#define sfx_fade_channel_volume(channel_num, fade_volume_percent, fade_time60) \
        sfx_fade_channel_volume_ID, \
        channel_num, \
        CharArrayFrom16Rev(fade_volume_percent), \
        CharArrayFrom16Rev(fade_time60),

/*=============================================================================
// name: sfx_stop_channel
// command id: C9
// info: stop playing sfx in occupied sfx channel
//===========================================================================*/
#define sfx_stop_channel_ID 0xC9
#define sfx_stop_channel_LENGTH 0x02
#define sfx_stop_channel(channel_num) \
        sfx_stop_channel_ID, \
        channel_num,

/*=============================================================================
// name: if_sfx_channel_volume_less_than
// command id: CA
// info: if sfx channel's volume is < volume argument, goto label
//=============================================================================
// note: if sfx channel is free (no audio playing), goto label. volume argument
// is signed. range is 0x0000-0x7FFF
//===========================================================================*/
#define if_sfx_channel_volume_less_than_ID 0xCA
#define if_sfx_channel_volume_less_than_LENGTH 0x05
#define if_sfx_channel_volume_less_than(channel_num, volume, label) \
        if_sfx_channel_volume_less_than_ID, \
        channel_num, \
        CharArrayFrom16Rev(volume), \
        label,

/*=============================================================================
// name: vehicle_start_path
// command id: CB
// info: makes vehicle follow a predefined path within setup
//===========================================================================*/
#define vehicle_start_path_ID 0xCB
#define vehicle_start_path_LENGTH 0x02
#define vehicle_start_path(path_num) \
        vehicle_start_path_ID, \
        path_num,

/*=============================================================================
// name: vehicle_speed
// command id: CC
// info: sets vehicle speed, usually paired with command CB
//=============================================================================
// note: arguments are unsigned. 1000 units = 1 meter per second travel speed.
// acceleration_time60 is number of game ticks to reach top speed (lower = faster)
//===========================================================================*/
#define vehicle_speed_ID 0xCC
#define vehicle_speed_LENGTH 0x05
#define vehicle_speed(top_speed, acceleration_time60) \
        vehicle_speed_ID, \
        CharArrayFrom16Rev(top_speed), \
        CharArrayFrom16Rev(acceleration_time60),

/*=============================================================================
// name: aircraft_rotor_speed
// command id: CD
// info: sets aircraft's rotor speed
//=============================================================================
// note: arguments are unsigned. argument scale is 10 units per degree, per tick.
// acceleration_time60 is number of game ticks to reach top speed (lower = faster)
//===========================================================================*/
#define aircraft_rotor_speed_ID 0xCD
#define aircraft_rotor_speed_LENGTH 0x05
#define aircraft_rotor_speed(rotor_speed, acceleration_time60) \
        aircraft_rotor_speed_ID, \
        CharArrayFrom16Rev(rotor_speed), \
        CharArrayFrom16Rev(acceleration_time60),

/*=============================================================================
// name: if_camera_is_in_intro
// command id: CE
// info: if camera mode equal to INTRO_CAM/FADESWIRL_CAM (viewing mission intro),
//       goto label
//=============================================================================
// note: if setup lacks intro camera structs, intro will be skipped
//===========================================================================*/
#define if_camera_is_in_intro_ID 0xCE
#define if_camera_is_in_intro_LENGTH 0x02
#define if_camera_is_in_intro(label) \
        if_camera_is_in_intro_ID, \
        label,

/*=============================================================================
// name: if_camera_is_in_bond_swirl
// command id: CF
// info: if camera mode equal to SWIRL_CAM (moving to back of bond's head), goto label
//=============================================================================
// note: if setup lacks swirl points, intro swirl will be skipped
//===========================================================================*/
#define if_camera_is_in_bond_swirl_ID 0xCF
#define if_camera_is_in_bond_swirl_LENGTH 0x02
#define if_camera_is_in_bond_swirl(label) \
        if_camera_is_in_bond_swirl_ID, \
        label,

/*=============================================================================
// name: tv_change_screen_bank
// command id: D0
// info: change the screen bank of a tagged tv monitor
//=============================================================================
// note: if tagged object has multiple screens, use screen index argument to set.
//       if tagged object has one screen, screen index is ignored
//===========================================================================*/
#define tv_change_screen_bank_ID 0xD0
#define tv_change_screen_bank_LENGTH 0x04
#define tv_change_screen_bank(object_tag, screen_index, screen_bank) \
        tv_change_screen_bank_ID, \
        object_tag, \
        screen_index, \
        screen_bank,

/*=============================================================================
// name: if_bond_in_tank
// command id: D1
// info: if bond is controlling tank, goto label
//===========================================================================*/
#define if_bond_in_tank_ID 0xD1
#define if_bond_in_tank_LENGTH 0x02
#define if_bond_in_tank(label) \
        if_bond_in_tank_ID, \
        label,

/*=============================================================================
// name: exit_level
// command id: D2
// info: exits the level
//=============================================================================
// note: recommend not to use this command, instead goto GAILIST_END_LEVEL for
// exit cutscene list. retail game has a glitch with hires mode that needs to
// execute this command in a loop, check cuba's 1000 list
//===========================================================================*/
#define exit_level_ID 0xD2
#define exit_level_LENGTH 0x01
#define exit_level \
        exit_level_ID,

/*=============================================================================
// name: camera_return_to_bond
// command id: D3
// info: switch back to first person view
//=============================================================================
// note: unused command, never used in retail game. tagged items within inventory
// will become invalid after command - only weapons are safe. command must have
// 3 ai_sleep commands before executing this command or else engine will crash
// on console (use camera_transition_to_bond). mission time is resumed on return
// to first person view
//===========================================================================*/
#define camera_return_to_bond_ID 0xD3
#define camera_return_to_bond_LENGTH 0x01
#define camera_return_to_bond \
        camera_return_to_bond_ID,

/*=============================================================================
// name: camera_look_at_bond_from_pad
// command id: D4
// info: change view to pad and look at bond
//=============================================================================
// note: command must have a bond_hide_weapons command and 3 ai_sleep commands
// before executing this command or else engine will crash (use camera_transition_from_bond).
// if camera mode is already in third person then you don't need to do the above.
// mission time is paused while in third person
//===========================================================================*/
#define camera_look_at_bond_from_pad_ID 0xD4
#define camera_look_at_bond_from_pad_LENGTH 0x03
#define camera_look_at_bond_from_pad(pad) \
        camera_look_at_bond_from_pad_ID, \
        CharArrayFrom16Rev(pad),

/*=============================================================================
// name: camera_switch
// command id: D5
// info: change view to tagged camera's position and rotation
//=============================================================================
// note: command must have a bond_hide_weapons command and 3 ai_sleep commands
// before executing this command or else engine will crash (use camera_transition_from_bond).
// if camera mode is already in third person then you don't need to do the above.
// only look at bond if flag is set. unused flag may have separated look at bond
// as x/y flags instead of a single flag - for retail unused flag does nothing.
// mission time is paused while in third person
//===========================================================================*/
#define camera_switch_ID 0xD5
#define camera_switch_LENGTH 0x06
#define camera_switch(object_tag, look_at_bond_flag, unused_flag) \
        camera_switch_ID, \
        object_tag, \
        CharArrayFrom16Rev(look_at_bond_flag), \
        CharArrayFrom16Rev(unused_flag),

/*=============================================================================
// name: if_bond_y_pos_less_than
// command id: D6
// info: if bond's y axis position < position argument, goto label
//=============================================================================
// note: checks if bond's y axis is below the provided argument. command uses
// world units. argument is signed and scale is 1:1 to in-game position.
// bond's point of view is accounted for by command (like debug manpos)
//===========================================================================*/
#define if_bond_y_pos_less_than_ID 0xD6
#define if_bond_y_pos_less_than_LENGTH 0x04
#define if_bond_y_pos_less_than(y_pos, label) \
        if_bond_y_pos_less_than_ID, \
        CharArrayFrom16Rev(y_pos), \
        label,

/*=============================================================================
// name: hud_hide_and_lock_controls_and_pause_mission_time
// command id: D7
// info: hide hud elements, lock player control and stop mission time.
//       command is commonly used for exit mission lists
//=============================================================================
// note: argument flag will not hide element on command execution. this is
// needed for dialog/hud countdown while in cinema mode. flags can be combined
// together to show multiple elements. sequential executions of D7 can be used
// to hide more elements, but once an element has been hidden it cannot be shown
// again until command D8 is executed. bond can take damage while in locked state.
// use HUD_# flags for bitfield argument
//===========================================================================*/
#define hud_hide_and_lock_controls_and_pause_mission_time_ID 0xD7
#define hud_hide_and_lock_controls_and_pause_mission_time_LENGTH 0x02
#define hud_hide_and_lock_controls_and_pause_mission_time(bitfield) \
        hud_hide_and_lock_controls_and_pause_mission_time_ID, \
        bitfield,

/*=============================================================================
// name: hud_show_all_and_unlock_controls_and_resume_mission_time
// command id: D8
// info: show all hud elements, unlock player control and resume mission time
//=============================================================================
// note: should only be executed after D7 command
//===========================================================================*/
#define hud_show_all_and_unlock_controls_and_resume_mission_time_ID 0xD8
#define hud_show_all_and_unlock_controls_and_resume_mission_time_LENGTH 0x01
#define hud_show_all_and_unlock_controls_and_resume_mission_time \
        hud_show_all_and_unlock_controls_and_resume_mission_time_ID,

/*=============================================================================
// name: chr_try_teleporting_to_pad
// command id: D9
// info: teleport chr to pad, goto label if successful
//===========================================================================*/
#define chr_try_teleporting_to_pad_ID 0xD9
#define chr_try_teleporting_to_pad_LENGTH 0x05
#define chr_try_teleporting_to_pad(chr_num, pad, label) \
        chr_try_teleporting_to_pad_ID, \
        chr_num, \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: screen_fade_to_black
// command id: DA
// info: fades the screen out to black
//=============================================================================
// note: fade duration is 1 second
//===========================================================================*/
#define screen_fade_to_black_ID 0xDA
#define screen_fade_to_black_LENGTH 0x01
#define screen_fade_to_black \
        screen_fade_to_black_ID,

/*=============================================================================
// name: screen_fade_from_black
// command id: DB
// info: fades the screen from black
//=============================================================================
// note: fade duration is 1 second
//===========================================================================*/
#define screen_fade_from_black_ID 0xDB
#define screen_fade_from_black_LENGTH 0x01
#define screen_fade_from_black \
        screen_fade_from_black_ID,

/*=============================================================================
// name: if_screen_fade_completed
// command id: DC
// info: when screen fade has completed (from/to black), goto label
//=============================================================================
// note: fade duration is 1 second
//===========================================================================*/
#define if_screen_fade_completed_ID 0xDC
#define if_screen_fade_completed_LENGTH 0x02
#define if_screen_fade_completed(label) \
        if_screen_fade_completed_ID, \
        label,

/*=============================================================================
// name: chr_hide_all
// command id: DD
// info: hide all characters in level - including bond's third person model.
//       execute this before switching to exit camera or bond will disappear
//=============================================================================
// note: hidden characters will halt their ai list execution until unhidden
//===========================================================================*/
#define chr_hide_all_ID 0xDD
#define chr_hide_all_LENGTH 0x01
#define chr_hide_all \
        chr_hide_all_ID,

/*=============================================================================
// name: chr_show_all
// command id: DE
// info: show all characters previously hidden by command DD
//===========================================================================*/
#define chr_show_all_ID 0xDE
#define chr_show_all_LENGTH 0x01
#define chr_show_all \
        chr_show_all_ID,

/*=============================================================================
// name: door_open_instant
// command id: DF
// info: instantly open tagged door
//=============================================================================
// note: mostly used for cutscenes, doesn't trigger door opening sfx. open tagged
//       door even if locked
//===========================================================================*/
#define door_open_instant_ID 0xDF
#define door_open_instant_LENGTH 0x02
#define door_open_instant(object_tag) \
        door_open_instant_ID, \
        object_tag,

/*=============================================================================
// name: chr_remove_item_in_hand
// command id: E0
// info: remove the item held by hand index
//=============================================================================
// note: does not drop item, instead clears holding item flag for hand index
//===========================================================================*/
#define chr_remove_item_in_hand_ID 0xE0
#define chr_remove_item_in_hand_LENGTH 0x03
#define chr_remove_item_in_hand(chr_num, hand_index) \
        chr_remove_item_in_hand_ID, \
        chr_num, \
        hand_index,

/*=============================================================================
// name: if_number_of_active_players_less_than
// command id: E1
// info: if the number of active players < argument, goto label
//=============================================================================
// note: single player always has a total of active players set to 1
//===========================================================================*/
#define if_number_of_active_players_less_than_ID 0xE1
#define if_number_of_active_players_less_than_LENGTH 0x03
#define if_number_of_active_players_less_than(number, label) \
        if_number_of_active_players_less_than_ID, \
        number, \
        label,

/*=============================================================================
// name: if_bond_item_total_ammo_less_than
// command id: E2
// info: if bond's total ammo for item < ammo_total argument, goto label
//=============================================================================
// note: ammo_total argument is signed. total ammo also accounts for loaded gun
//===========================================================================*/
#define if_bond_item_total_ammo_less_than_ID 0xE2
#define if_bond_item_total_ammo_less_than_LENGTH 0x04
#define if_bond_item_total_ammo_less_than(item_num, ammo_total, label) \
        if_bond_item_total_ammo_less_than_ID, \
        item_num, \
        ammo_total, \
        label,

/*=============================================================================
// name: bond_equip_item
// command id: E3
// info: forces bond to equip an item - only works in first person
//=============================================================================
// note: can be used for any item, even if bond doesn't have it in inventory
//===========================================================================*/
#define bond_equip_item_ID 0xE3
#define bond_equip_item_LENGTH 0x02
#define bond_equip_item(item_num) \
        bond_equip_item_ID, \
        item_num,

/*=============================================================================
// name: bond_equip_item_cinema
// command id: E4
// info: forces bond to equip an item - only works in third person (cinema)
//=============================================================================
// note: can be used for any item, even if bond doesn't have it in inventory
//===========================================================================*/
#define bond_equip_item_cinema_ID 0xE4
#define bond_equip_item_cinema_LENGTH 0x02
#define bond_equip_item_cinema(item_num) \
        bond_equip_item_cinema_ID, \
        item_num,

/*=============================================================================
// name: bond_set_locked_velocity
// command id: E5
// info: forces bond to move in X/Z direction
//=============================================================================
// note: only works when bond has been locked by command D7. used for dam jump.
// argument is signed and scale is 1:1 to in-game position. speed is number of
// world units per tick
//===========================================================================*/
#define bond_set_locked_velocity_ID 0xE5
#define bond_set_locked_velocity_LENGTH 0x03
#define bond_set_locked_velocity(x_speed60, z_speed60) \
        bond_set_locked_velocity_ID, \
        x_speed60, \
        z_speed60,

/*=============================================================================
// name: if_object_in_room_with_pad
// command id: E6
// info: if tagged object in the same room with pad, goto label
//===========================================================================*/
#define if_object_in_room_with_pad_ID 0xE6
#define if_object_in_room_with_pad_LENGTH 0x05
#define if_object_in_room_with_pad(object_tag, pad, label) \
        if_object_in_room_with_pad_ID, \
        object_tag, \
        CharArrayFrom16Rev(pad), \
        label,

/*=============================================================================
// name: if_guard_is_firing_and_using_180_range_flag
// command id: E7
// info: if guard is in firing state (ACT_ATTACK) and TARGET_180_RANGE is set, goto label
//===========================================================================*/
#define if_guard_is_firing_and_using_180_range_flag_ID 0xE7
#define if_guard_is_firing_and_using_180_range_flag_LENGTH 0x02
#define if_guard_is_firing_and_using_180_range_flag(label) \
        if_guard_is_firing_and_using_180_range_flag_ID, \
        label,

/*=============================================================================
// name: if_guard_is_firing
// command id: E8
// info: if guard is in firing state (ACT_ATTACK), goto label
//===========================================================================*/
#define if_guard_is_firing_ID 0xE8
#define if_guard_is_firing_LENGTH 0x02
#define if_guard_is_firing(label) \
        if_guard_is_firing_ID, \
        label,

/*=============================================================================
// name: switch_fog_instantly
// command id: E9
// info: instantly switch fog to the next fog's slot
//=============================================================================
// note: this command can't be stopped after executing. level must have a fog
// assigned or will crash!
//===========================================================================*/
#define switch_fog_instantly_ID 0xE9
#define switch_fog_instantly_LENGTH 0x01
#define switch_fog_instantly \
        switch_fog_instantly_ID,

/*=============================================================================
// name: trigger_fade_and_exit_level_on_button_press
// command id: EA
// info: if player pressed any button, fade to black and exit level
//=============================================================================
// note: this command activates a state where game will fade to black when button
// input is detected from controller 1. command does not pause mission time
//===========================================================================*/
#define trigger_fade_and_exit_level_on_button_press_ID 0xEA
#define trigger_fade_and_exit_level_on_button_press_LENGTH 0x01
#define trigger_fade_and_exit_level_on_button_press \
        trigger_fade_and_exit_level_on_button_press_ID,

/*=============================================================================
// name: if_bond_is_dead
// command id: EB
// info: if bond has died/been killed, goto label
//===========================================================================*/
#define if_bond_is_dead_ID 0xEB
#define if_bond_is_dead_LENGTH 0x02
#define if_bond_is_dead(label) \
        if_bond_is_dead_ID, \
        label,

/*=============================================================================
// name: bond_disable_damage_and_pickups
// command id: EC
// info: disables bond damage and ability to pick up items
//=============================================================================
// note: commonly used for level exit ai lists - prevents bond dying after
//       triggering exit cutscene. use command F3 to check if flag is set on
//===========================================================================*/
#define bond_disable_damage_and_pickups_ID 0xEC
#define bond_disable_damage_and_pickups_LENGTH 0x01
#define bond_disable_damage_and_pickups \
        bond_disable_damage_and_pickups_ID,

/*=============================================================================
// name: bond_hide_weapons
// command id: ED
// info: set bond's left/right weapons to be invisible
//===========================================================================*/
#define bond_hide_weapons_ID 0xED
#define bond_hide_weapons_LENGTH 0x01
#define bond_hide_weapons \
        bond_hide_weapons_ID,

/*=============================================================================
// name: camera_orbit_pad
// command id: EE
// info: change view to orbit a pad with set speed
//=============================================================================
// note: command must have a bond_hide_weapons command and 3 ai_sleep commands
// before executing this command or else engine will crash (use camera_transition_from_bond).
// if camera mode is already in third person then you don't need to do the above.
// arguments:
// lat_distance: camera distance from pad, 100 units per meter. argument is unsigned
// vert_distance: camera distance from pad, 100 units per meter. argument is signed
// orbit_speed: speed to orbit around pad, argument is signed. unit format uses
//              compass direction like target commands (14-17). generally stick
//              to a low range as it is used for delta timing (0100-FF00)
// pad: pad for camera to target and orbit around
// y_pos_offset: offset the relative y position for pad (boom/jib), argument is signed
// initial_rotation: uses compass direction like target commands (14-17)
//                   but inverted - hex N: 0000 E: C000 S: 8000: W: 4000
// mission time is paused while in third person
//===========================================================================*/
#define camera_orbit_pad_ID 0xEE
#define camera_orbit_pad_LENGTH 0x0D
#define camera_orbit_pad(lat_distance, vert_distance, orbit_speed60, pad, y_pos_offset, initial_rotation) \
        camera_orbit_pad_ID, \
        CharArrayFrom16Rev(lat_distance), \
        CharArrayFrom16Rev(vert_distance), \
        CharArrayFrom16Rev(orbit_speed60), \
        CharArrayFrom16Rev(pad), \
        CharArrayFrom16Rev(y_pos_offset), \
        CharArrayFrom16Rev(initial_rotation),

/*=============================================================================
// name: credits_roll
// command id: EF
// info: trigger credits crawl
//=============================================================================
// note: credits text and positions are stored in setup intro struct
//===========================================================================*/
#define credits_roll_ID 0xEF
#define credits_roll_LENGTH 0x01
#define credits_roll \
        credits_roll_ID,

/*=============================================================================
// name: if_credits_has_completed
// command id: F0
// info: credits crawl has finished, goto label
//===========================================================================*/
#define if_credits_has_completed_ID 0xF0
#define if_credits_has_completed_LENGTH 0x02
#define if_credits_has_completed(label) \
        if_credits_has_completed_ID, \
        label,

/*=============================================================================
// name: if_objective_all_completed
// command id: F1
// info: if all objectives for current difficulty has been completed, goto label
//=============================================================================
// note: uses objective difficulty settings within setup, briefing file settings
//       are not referenced. ensure both setup and briefing files are consistent
//===========================================================================*/
#define if_objective_all_completed_ID 0xF1
#define if_objective_all_completed_LENGTH 0x02
#define if_objective_all_completed(label) \
        if_objective_all_completed_ID, \
        label,

/*=============================================================================
// name: if_folder_actor_is_equal
// command id: F2
// info: if current bond equal to folder actor index, goto label
//=============================================================================
// note: in retail release only index 0 works. originally this would have checked
// which bond (brosnan/connery/moore/dalton) is currently used, with each briefing
// folder using a different bond likeness in-game. however rare didn't have the
// license to use the other actor's faces so this feature was removed.
// command is only used for cuba (credits)
//===========================================================================*/
#define if_folder_actor_is_equal_ID 0xF2
#define if_folder_actor_is_equal_LENGTH 0x03
#define if_folder_actor_is_equal(bond_actor_index, label) \
        if_folder_actor_is_equal_ID, \
        bond_actor_index, \
        label,

/*=============================================================================
// name: if_bond_damage_and_pickups_disabled
// command id: F3
// info: if bond damage and ability to pick up items disabled, goto label
//=============================================================================
// note: used to check when bond has exited level, usually to stop guards from
//       spawning during mission cinema. use command EC to set state on
//===========================================================================*/
#define if_bond_damage_and_pickups_disabled_ID 0xF3
#define if_bond_damage_and_pickups_disabled_LENGTH 0x02
#define if_bond_damage_and_pickups_disabled(label) \
        if_bond_damage_and_pickups_disabled_ID, \
        label,

/*=============================================================================
// name: music_xtrack_play
// command id: F4
// info: play level's x track for duration
//=============================================================================
// note: seconds arguments are unsigned, available music slots range is 0-3.
// stopped duration argument is used by command F5. when using F5 to stop a music
// slot, the xtrack will continue to play until this or total time reaches 0.
// if you don't want this to happen, set the seconds stopped duration argument to 0
//===========================================================================*/
#define music_xtrack_play_ID 0xF4
#define music_xtrack_play_LENGTH 0x04
#define music_xtrack_play(music_slot, seconds_stopped_duration, seconds_total_duration) \
        music_xtrack_play_ID, \
        music_slot, \
        seconds_stopped_duration, \
        seconds_total_duration,

/*=============================================================================
// name: music_xtrack_stop
// command id: F5
// info: stop currently playing x track in slot
//=============================================================================
// note: music slots range is 0-3. use slot -1 to stop all xtrack slots instantly.
// when stopping a music slot, it will let the track continue to play until the
// seconds stopped duration time or total time (set by command F4) reaches zero.
// this is ignored when using music slot -1
//===========================================================================*/
#define music_xtrack_stop_ID 0xF5
#define music_xtrack_stop_LENGTH 0x02
#define music_xtrack_stop(music_slot) \
        music_xtrack_stop_ID, \
        music_slot,

/*=============================================================================
// name: trigger_explosions_around_bond
// command id: F6
// info: triggers explosions around the player, will continue forever
//=============================================================================
// note: does not trigger level exit or killed in action state
//===========================================================================*/
#define trigger_explosions_around_bond_ID 0xF6
#define trigger_explosions_around_bond_LENGTH 0x01
#define trigger_explosions_around_bond \
        trigger_explosions_around_bond_ID,

/*=============================================================================
// name: if_killed_civilians_greater_than
// command id: F7
// info: if total civilians killed > argument, goto label
//=============================================================================
// note: guards flagged with CHRFLAG_COUNT_DEATH_AS_CIVILIAN will count towards
//       total when killed. usually set for scientists/civilians/innocent NPCs
//===========================================================================*/
#define if_killed_civilians_greater_than_ID 0xF7
#define if_killed_civilians_greater_than_LENGTH 0x03
#define if_killed_civilians_greater_than(civilians_killed, label) \
        if_killed_civilians_greater_than_ID, \
        civilians_killed, \
        label,

/*=============================================================================
// name: if_chr_was_shot_since_last_check
// command id: F8
// info: if chr was shot since last check, goto label
//=============================================================================
// note: checks chr->chrflags if CHRFLAG_WAS_HIT is set. if true, unset flag and
//       goto label. CHRFLAG_WAS_HIT is set even if guard is invincible
//===========================================================================*/
#define if_chr_was_shot_since_last_check_ID 0xF8
#define if_chr_was_shot_since_last_check_LENGTH 0x03
#define if_chr_was_shot_since_last_check(chr_num, label) \
        if_chr_was_shot_since_last_check_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: bond_killed_in_action
// command id: F9
// info: sets briefing status to killed in action, automatic mission failure
//=============================================================================
// note: does not kill the player, only changes the mission status
//===========================================================================*/
#define bond_killed_in_action_ID 0xF9
#define bond_killed_in_action_LENGTH 0x01
#define bond_killed_in_action \
        bond_killed_in_action_ID,

/*=============================================================================
// name: guard_raises_arms
// command id: FA
// info: makes guard raise their arms for half a second
//===========================================================================*/
#define guard_raises_arms_ID 0xFA
#define guard_raises_arms_LENGTH 0x01
#define guard_raises_arms \
        guard_raises_arms_ID,

/*=============================================================================
// name: gas_leak_and_fade_fog
// command id: FB
// info: trigger gas leak event and slowly transition fog to the next fog's slot
//=============================================================================
// note: this command triggers a gas leak. for the level egypt, this command
// will not trigger a gas leak, but instead will only transition the fog.
// this command can't be stopped after executing. level must have a fog assigned
// or will crash!
//===========================================================================*/
#define gas_leak_and_fade_fog_ID 0xFB
#define gas_leak_and_fade_fog_LENGTH 0x01
#define gas_leak_and_fade_fog \
        gas_leak_and_fade_fog_ID,

/*=============================================================================
// name: object_rocket_launch
// command id: FC
// info: launch a tagged object like a rocket
//=============================================================================
// note: if tagged object can't be turned upright, object will be destroyed instead.
//       can be used to drop attached props
//===========================================================================*/
#define object_rocket_launch_ID 0xFC
#define object_rocket_launch_LENGTH 0x02
#define object_rocket_launch(object_tag) \
        object_rocket_launch_ID, \
        object_tag,

#endif
#endif


