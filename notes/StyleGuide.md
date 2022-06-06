
# GoldenEye C Style Guide

## Background

GE/PD mostly uses cammelCase namespaceFunctionName()
```C
// joy.c -> Tick Retrace
    joyTickRetrace();
// chrai.c -> If Opertunity Fire Jump F(orward)
    aiIfOpportunityFireJumpF();
```
with occasional Pascal_Snake_Case
```C
// snd.c -> Play Universal
    Snd_Play_Universal();
```
and snake_case
```C
// font.c -> Make G(reater) T(han)
    font_makegt();
```
however sometimes its Prefix_SnakePascalCase
```C
// pak.c -> Add One Camera File
    Pak_AddOneCameraFile();
```

GE Constant example
```C
    #define MAX_FUDGE_DATA_SIZE
```

Basically, Rare had no style guide!
Each mamber of the team was free to do whatever - which is fine for a closed
source game with only a few members.

Nintendo had a much better handle on the situation (though not perfect either
with a couple of deviations here and there) where the SDK also mostly uses
namespaceFunctionName() in camelCase
```C
// Audio Library (libaudio.h) -> Sound P(layer) -> Play/Stop
    alSndpPlay();
    alSndpStop();
// OS (os.h) -> P(arallel) I(interface) -> Get Status
    osPiGetStatus();
```

Since this project is open to more people and the code has to be written from scratch
we can set out some basic guides so that we are all following the same standard
and can read what others have done.

HOWEVER

Since we are going for a matching project as best we can - If an original (canonical) name is known - Use it! (unless there is a really good reason not to)

In all other cases follow this guide.

---

## Bracing
Allman Style bracing should be followed - though single line If's are acceptable
This keeps in line with SDK style too and maximizes readability as all "blocks" have a clear
start and end brace.
The only exception to this is Array Definitions, which should open on the same line as the '='.
```C
void SomeFunctionScope()
{
    int i;
    char *a = {
                'a',
                'b',
                2,
                3
    };

    for (i=0; i < 10; i++)
    {
        doSomething(i);
        if (i = 2)
        {
            i = 4; 
        }
        else
        {
            i = 9;
        }
    }
}
```

## Prefix/Suffix Tables

| Prefix 	| Meaning					| Example													| Notes																	
|--------	|----------------			|--------------------------------------						|--------------------------------------------							
| g_	 	| global		 			| g_PrefService												| Not needed if already prefixed "Global" 								
| s			| static member				| sPrefChecked						 						| Static Local retains value over App life, but remains local			
| m			| private member 			| mLength													| Static mLength can only be accessed within same file. External files require Get/Set
|			| enum constants 			| enum FOO<br>`{`<br>`	FOO_BAR,`<br>`	FOO_BAZ`<br>`}`	| Also prefix with Enum Name. 
| _ <br>__	| Implementation Reserved 	| __osThingy												| Underscore prefix should NOT be used in game code. However, expect to find them	as Internal Identifiers but no Accessable Identifier will start with _ or __.
| is        | Boolean Result            | isAlive                                                   | To ask a True/False question. Either a function or variable - where this should be the only non-noun variable name.


| Sufix		| Meaning					| Example													| Notes											
|--------	|----------------			|--------------------------------------						|--------------------------------------------	
| p			| Pointer					| glistp													| Pointer to glist								


## TYPES
Use SDK types (`u8`, `s32` etc) rather than C Types (`unsigned char`, `int` etc)
Remember to include `<ultra64.h>`

Bond Types use the "typedef" keyword


While typedefs are used to avoid typing "struct" and to help intellisence
they are not foolproof.

Using structs before they are declaired need to have the struct keyword (forward declairation) or
be re-ordered.

Example:
```C
typedef struct ARecord
{
    BRecord *Child; // This will not work since IDO doenst know it exists
    Struct BRecord *Next; //Forward declairation OK
} ARecord;

typedef struct BRecord
{
    ARecord Parent; // This is ok because it exists.
} BRecord; 
```

## INHERITANCE
Bond Struct Types that "Inherit" from another Struct should use the provided 'Inherits' keyword.
Example:
```C
// Base Struct has members A and B and can be accessed by var.A or var.B.
typedef struct ARecord
{
    u8 A;
    u8 B;
} ARecord;

// Child Struct adds member C, all three members can be
// accessed by var.A, var.B, var.C
typedef struct CRecord
{
    Inherits ARecord; // Does not have to be first, but makes sense to be first
    u8 C;
} CRecord; 
```



## CONSTANTS
ALL_CAPS_SNAKE_CASE for constants and enums eg.
```c
#define NULL 0
enum HIT
{
   HIT_WOOD,
   HIT_STONE
};
```

Examples from GE:
```C
stick<XUSER_MAX_COUNT
p->type==prop_type_chr //should be caps
currentplayer->gunmemused[GUNRIGHT]==0
prevblock<MAXBLOCKS
```

## INCLUDE UNITS IN NAMES
If a variable represents time, weight, or some other unit then include the unit
in the name so developers can more easily spot problems.
For example:
```C
    int timeout_msecs;
    int MyWeight_lbs;
```


## VARIABLE NAMES
Should be nouns (as they represent state). The name should be camelCase
    (e.g. index, currentEnvironment or bond).

Prefixes are sometimes usefull, please refer to prefix table above

Suffixes are sometimes useful eg:
*    `max` - to mean the maximum value something can have.
*    `cnt` - the current count of a running count variable.
*    `key` - key value.

For example: `retry_max` to mean the maximum number of retries, `retry_cnt` to mean
the current retry count.

Examples from GE:
```C
    num < MAX_STARTPADS
    mFilteredNum==0
    numBits<=32
    p->type //where p is a pad
    inst->obj->nummatrices //where inst is an object instance
    PadData[stick].numPos[xy]

```
### Global (Public) Variables
Should be prefixed by `g_` eg:
*   `g_chraiCurrentSetup` global Current Setup defined in file chrai.c

Public Global Variables must be declaired (not defined) in a header file that is included by all C files
that use the variable, and use the `extern` keyword eg:
*   `extern stagesetup g_chraiCurrentSetup;`
Global Variables should only be defined once in their own C file.

### Global (Private) Variables
Should be prefixed by `m_` eg:
*   `m_numGuards` global Number of Guards defined in file chr.c

Private Global Variables must be defined (implicitly declaired) in the C file
that use the variable (Not in a header).

Access to Private Variables from outside the C file should be done via Get/Set functions (declaired in a h file)

## FUNCTION NAMES
Should be verb phrases (as they represent actions), and command-like functions
should be imperative.
The name should make clear what it does:
`CheckForErrors()` instead of `error_check(),`
`DumpDataToFile()` instead of `data_file().`
This will also make functions and data objects more distinguishable.

Prefixes are sometimes useful:

* `is` - to ask a question about something. Usually TRUE/FALSE
* `get` - Get a value.
* `set` - Set a value.

For example: `isAlive`
```C
    //Only do something if we are alive
    if(isAlive())
    {
        doSomething();
    }
```

Functions, especually Public, should be prefixed by "class" or "namespace"
```C
    chrResetNearMiss()
    chrIsAlive()
```

Examples from GE:
```C
    IsBadMtx44()
    GetState()
    getCurrent()
    skeletonGetNumJoints( skel )
```

### Private Functions
Private functions that only serve a purpose __within__ a single C file should NOT be declaired
in a h file, and should only be declaired ahead of definition (forward decleration) if it is to be used before
it is defined.

### Public Functions
Public Functions MUST be declaired in a h file to be included in any C that uses the function.
the `extern` keyword has no effect on functions but it may be of use to highlight the public
nature/intention of the function.
Public functions MUST have a namespace as the first part of the name.

## STRUCT NAMES
Structs are often nouns and should be PascalCase
Database like structs should not be named "data" - which should be reserved for
the variable wich uses the struct. Instead "Record" is suggested eg:
```C
typedef struct PadRecord
{
    coord3d    pos;
    coord3d    up; 
    coord3d    look;
    char      *plink;
    StandTile *stan; 
} PadRecord;

PadRecord padData; //variable holding data for pad
```
Examples from GE:
```C
```

## POINTERS
Pointers should be declaired with the * right-aligned eg:
```C
    ChrData *ChrAp, *ChrBp;
```
instead of:
```C
    ChrData* ChrAp, ChrBp; //this would not make ChrB a pointer.
```
Pointers _should_ be suffixed by p following sdk style eg: `glistp // pointer to glist` however GE also
prefixed with p and suffixed in Ptr (see note about GE being inconsistent haha)

Examples from GE:
```C
    pPlayback
    ppFileData
    tagNamePtr
    ((void*)assetPtr != NULL)
    ((void*)nodePtr != NULL)
```
## COMMENTS
Comments should be C style / * * / for block comments and header documentation.

Comments _can_ be C++ style / / for inline comments documenting single items.

Function documentation should precede functions directly
without extra line breaks and begin with a double asterix - Left aligned astrices are optional
```C
int var; //This is an integer

/** Take an integer and convert it to a float of half its size
 * @param in: Integer to convert
 * @return A float of half the input size
 */
float mathHalfMe(int in)
{
    return in/2;
}
```
`@param`, `@return` help with editors that support function hinting by showing these values in a
tooltip.


## SCOPE
Variables inside braces have "Block" scope and end when the block ends (unless
declared static where they retain their value till program ends).
```C
    if(1)
    {
        int a = 1;
    }
    else
    {
        int a = 0;
    }

    //a is undefined hereafter
```
Variables Outside functions, usually at top of file (NOT in header) have by
default Global (Private) Scope.
If declaired as extern they are promoted to Public Scope - provided the declairation is in a
h file and the h file is included by all C files that use the Global.
Both extern and static have Static Duration - they end when the program ends.
```C
//Initial Declaration in h (all initial declairations within
//                           a C will work for that C)
int gi4;            // tentative defnition, unknown linkage (Private/Public)
                    //  Including this header in another C file will fail.
static int mi5;     // tentative defnition, internal linkage (Private)
                    //  Including this header in another C file ends up with its
                    //  own private version of the 'global' variable
extern int gi6;     // tentative defnition, external linkage (Public)
                    //  Including this header in another C file
                    //  Use the Global as expected

//Initial Definition in h - Fail (all initial definitions within
//                           a C will work for that C)

int gi1        = 1; // defnition, Unknown linkage (Private/Public)
                    //  Including this header in more than 1 C file will fail.
static int mi2 = 2; // defnition, internal linkage (Private)
                    //  Including this header in another C file ends up with its
                    //  own private version of the 'global' variable
extern int gi3 = 3; // defnition, external linkage (Public)
                    //  Including this header in another C file will fail.
```
### Headers
A header file only contains extern declarations of variables - never static or unqualified variable definitions.

For any given variable, only one header file declares it (SPOT - Single Point of Truth).

A source file never contains extern declarations of variables - source files always include the (sole) header that declares them.

For any given variable, exactly one source file defines the variable, preferably initializing it too. 

The source file that defines the variable also includes the header to ensure that the definition and the declaration are consistent.

A function should never need to declare a variable using extern.

---

##  EXAMPLE C


### FILE1.c 
```C
    #include "file1.h"                        // Prove my definitions are the same as declaired to others

    static f32 mAiTime;                       // Static, holds value for duration of program, scoped to file 1 (Private)

    /**
    * @returns the time
    */
    f32 f1GetTime()                           // Public Function, make sure its declaired in a header
    {
        return mAiTime;                       // Gets time from private mTime
    }

    /**
    * @param time: Integer to Set time as
    */
    void setTime(u32 time)                   // Private Function, make sure its NOT declaired in a header
    {
        mAiTime = time / 60;                 // Sets time to mTime format
    }
```




### FILE1.h (File 1 Public Vars/Funcs)
```C
    extern int f1GetTime();                // Gets time from private mTime (Public Func, Includes "Namespace")
    extern u32 g_f2GlobalData              // Public Global Data

```

### FILE2.c

```C
    #include "file1.h"                             // Brings into scope "Public" Variables and functions

    s32 D_80000000;                                // Unknown label data (Private by default)
    g_f2GlobalData = 0;                            // camelCasedNaming and defined as early as possible

    typedef enum ID                              
    {
        ID_AGENT,                                  // prefix with enum name
        ID_SECRETAGENT,
        ID_00AGENT
    }ID;

    typedef struct Person                          // structs themselves should use PascalCase and be Nouns
    {
        ID ID;                                     // struct member Noun and PascalCase
        char *Name;
        int Age;
    } Person;

    Person gTrevor = {ID_00AGENT, "Trevor", 30};   // Global Person defined early

    // This can be done, but its pointless since gGlobalData has global scope and nothing special is being done
    // Also, unless this is declaired in a header, the function is Private
    int getGlobalData()
    {
        return g_f2GlobalData;
    }

    /**
    * functions should be camelCase
    * further documentation
    * @param parameter1: defines the number of xxx
    */
    void functionNameSample(int Parameter1) 
    {                                              // newline for opening braces (ALLMAN)
        u32 tempvar;                               // Use SDK Types

        if (g_f2GlobalData == 1)
        {
            gGlobalData = 2;
            D_80000000  = 10;
        }
        else
        {
            tempVar = getGlobalData();             // wastes cpu instructions switching funcs
            tempVar = g_f2GlobalData();            // This works equally as well
        }

        if (g_f2GlobalData == 4)
            g_f2GlobalData = 2;                    // this syntex may be used
    }

    void main()
    {
        int time = f1GetTime();                 // Access Global Getter
        //time = mAiTime;                       // This fails as mAiTime is not visible in this file (Scope limited to file1)
        functionNameSample(time);
        //setTime(23);                          // This fails as setTime is not visible in this file (Scope limited to file1)
    }

    ```
