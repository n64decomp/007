/*
 COMPILE
/usr/bin/qemu-irix -silent -L tools/irix/root tools/irix/root/usr/bin/cc -Wab,-r4300_mul -non_shared -Olimit 2000 -G 0 -Xcpluscomm -woff 609,649,819,820,852,821,838 -I . -I include -I src -I src/game -I src/rarezip -mips2 -c build/test.c -o build/test.o -O2

PRE-COMPILE
 -E > build/testpre.c

 DISASSEMBLE
gdis -S build/test.o > build/test.txt

mips-linux-gnu-objdump --all-headers --disassemble --debugging --source --full-contents build/test.o > build/test1.mips

single regex for diff
  braces   |   non asm  |     addr     |       jal target                        |     Other targets         | Blank lines
((\{|\})\n)|(^.[^:]*$\n)|(^.*:.{11}\d?)|((?<=jal\t)([\d a b c d e f]{1,4} <.*\n))|([\d a b c d e f]{1,4} <.*)|(^$\n)

format for notepad++
(/\*.*\*\/\s*)|(\$(?=[^f]))

*/

#if 1

#    define TARGET_N64
/* #include "../src/game/chrobjdata.c"* /
#include "../src/bondconstants.h"
#include "../src/bondtypes.h" */
#    define DEB2UG 1
#    include "../src/ASSERT.H"
#    include "../src/bondgame.h"
#    include <limits.h>
#    include <math.h>

#    if 0 
 int aiAsTypedStructTest(char *ailist)
{

     //Variable array val
    {
         volatile struct
         {
             char cmd;
             char val[];
         } *ai = (ailist + 3);
        //8bit loa
        assert(*(char*)ai->val<=100); //# MATCH Assert Text

        //32 bit load (manual) - MATCH
        testflags(ai->cmd, ai->val[0] << 24 | ai->val[1] << 16 | ai->val[2] << 8 | ai->val[3]);

        //!32bit load (Compiler) - NOT MATCH
        testflags(ai->cmd, *(long *)ai->val);

        //16bit load (Compiler) - MATCH
        testflags(ai->cmd, *(unsigned short *)ai->val);

        //16bit load (manual) - MATCH
        testflags(ai->cmd, ai->val[0] << 8 | ai->val[1]);
    }
    //static char val
    {
        volatile struct
        {
            char cmd;
            char val;
        } *ai = (ailist + 3);

        assert(ai->val<=100); //MATCH

        //!32 bit load (manual) - NOT MATCH
        testflags(ai->cmd, *(((char*)ai->val)+0) << 24 | *(((char*)ai->val)+1) << 16 | *(((char*)ai->val)+2) << 8 | *(((char*)ai->val)+3));

        //!32bit load (Compiler) -  NOT MATCH
        testflags(ai->cmd, *(((unsigned long*)(char**)ai->val)));

        //!16bit load (Compiler) - NOT MATCH
        testflags(ai->cmd, *(unsigned short *)(char**)ai->val);

        //!16bit load (manual) - NOT MATCH
        //testflags(ai->cmd, ai->val[0] << 8 | ai->val[1]);

    }
    //typed struct
    {
        volatile struct
        {
            char cmd;
            short val;
            int val2;
            char val3;
        } *ai = (ailist[3]);
        assert(ai->val <= 100); //MATCH

        //32 bit load () - 
        testflags(ai->cmd, ai->val2);

        //16bit load () - 
        testflags(ai->cmd, ai->val);

        //8bit load () - 
        testflags(ai->cmd, ai->val3);

    }
    {
        volatile struct
        {
            char cmd;
            char val;
            char val2[2];
            char val4[1];
            char val3[4];
        } *ai6 = (ailist[3]);

        assert(ai6->val == 100);
        assert(*(unsigned short *)&ai6->val3 == 100);
        assert(*(short *)&ai6->val3 == 100);
        assert(*(unsigned int *)&ai6->val3 == 100);
        assert(*(int *)&ai6->val3 == 100);
        assert(*(float *)&ai6->val3 == 100);
    }
    return 0;
}
#    endif

#    define Deb4ugAIExecute

#    ifdef DebugEnvironment
#        include <fog.h>
// CODE.bss:800825C0
s32 gEnvironmentHasFog;
// CODE.bss:800825C4
u32 ptr_nearfog_enviroment_values;
// CODE.bss:800825C8
sfarfogdetails
{
    s32 buffer_far_pervasiveness; // 0
    // CODE.bss:800825CC
    s32 far_fog; // 4
    // CODE.bss:800825D0
    s16 D_800825D0; // 8
    // CODE.bss:800825D4
    s32 D_800825D4; // c
    // CODE.bss:800825D8
    s32 flt_CODE_bss_800825D8; // 10
    // CODE.bss:800825DC
    s32 flt_CODE_bss_800825DC; // 14
}
Curfarfogdetails;
// CODE.bss:800825E0
s32 buffer_far_ambiant;
// CODE.bss:800825E4
s32 bg_dif_light;
// CODE.bss:800825E8
EnvironmentRecord *gEnvironmentFoundp;
// CODE.bss:800825EC
EnvironmentRecord *gEnvironmentMainp;
// CODE.bss:800825F0
EnvironmentRecord *gEnvironmentAltp;
// CODE.bss:800825F4
s32 D_800825F4;
// CODE.bss:800825F8
// u32 dword_CODE_bss_800825F8;
// static EnvironmentRecord PreviousEnvironment; //tempCurrentEnvp
u32 TransitionEnvironmentID;        // 0 22 during fac gas = Fac Previous ID
f32 TransitionEnvironmentBlendMult; // 4 4120 during fac gas blendmult /
                                    // buffer_far_pervasiveness2
f32 TransitionEnvironmentFarFog;    // 8 ScaledFarFogDist2 (447A0000)
f32 DAT_80082604;                   // near
f32 DAT_80082608;                   // maxvis
f32 DAT_8008260c;                   // max obf
f32 DAT_80082610;                   // minvis
u32 DAT_80082614;                   // 3e7 intens

s32 TransitionEnvironmentDiffFarFog;   // 3de diff
s32 TransitionEnvironmentFarIntensity; // 3e8 far
                                       /* Nope
                                        * typedef struct Row
                                           {
                                               u8 val : 5;
                                           } colour; */
vu8 TransitionEnvironmentSkyRed;       // r
vu8 TransitionEnvironmentSkyGreen;     // g
vu8 TransitionEnvironmentSkyBlue;      // b
u8 byte_CODE_bss_80082623;             // clouds
u8 byte_CODE_bss_80082624;             //{
u8 byte_CODE_bss_80082625;             // |
u8 byte_CODE_bss_80082626;             // | cldrep
u8 byte_CODE_bss_80082627;             //}
u8 byte_CODE_bss_80082628;             //{ skyimg
u8 byte_CODE_bss_80082629;             //}
u8 byte_CODE_bss_8008262a;             //{ res
u8 byte_CODE_bss_8008262b;             //}
u8 byte_CODE_bss_8008262c;
u8 byte_CODE_bss_8008262d;
u8 byte_CODE_bss_8008262e;
u8 byte_CODE_bss_8008262f;
u8 byte_CODE_bss_80082630;
u8 byte_CODE_bss_80082631;
u8 byte_CODE_bss_80082632;
u8 byte_CODE_bss_80082633;
u8 byte_CODE_bss_80082634;
u8 byte_CODE_bss_80082635;
u8 byte_CODE_bss_80082636;
u8 byte_CODE_bss_80082637;
u8 byte_CODE_bss_80082638;

// data
// D:80044DC0
s32 D_80044DC0 = 0;
// D:80044DC4
f32 near_fog_value = 3.4028235e38;
// D:80044DC8
f32 near_fog_times_intensity = 0.0;
// D:80044DCC
// Default Environment
CurrentEnvironmentRecord CurrentEnvironment = {
    0x384, // 0 dif_in_light
    0x3E8, // 4 far_ambiantlight
    0,     // 8,9,a,b RGBC
    0,     // ccloudrepeat
    0,     // 10skyimageid
    0,     // 14cloudred
    0,     // 18cloudgreen
    0,     // 1ccloudblue
    0,     // 20iswater
    0,     // 24waterrepeat
    0,     // 28waterimageid
    0,     // 2cwaterred
    0,     // 30watergreen
    0,     // 34 waterblue
    0,     // 38 waterconcavity
    0,     // 3c* extra?
    0      // 40*
};

EnvironmentRecord fog_tables[] = {

    {0x16, 15.0, 3500.0,  2000.0, 2500.0, 2000.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0,
     0,    8,    1,       5000.0, 0,      0,      170.0, 100.0, 40.0,  0,     0,
     0,    0,    -1000.0, 0,      0,      0.0,    0.0,   0.0,   30.0},
    {0x10, 15.0, 3500.0,  2000.0, 2500.0, 2000.0, 0.0,   1,     2,    3, 0,
     0,    8,    12,      5000.0, 0,      0,      170.0, 100.0, 40.0, 0, 0,
     0,    0,    -1000.0, 0,      0,      0.0,    0.0,   0.0,   30.0},
    {ENVIRONMENTDATA_END}

};

CurrentEnvironmentRecord *get_ptr_currentdata(void)
{
    return &CurrentEnvironment;
}

f32 get_near_fog_value(void)
{
    return near_fog_value;
}

f32 square_near_fog_value(void)
{
    return near_fog_value * near_fog_value;
}
extern void set_page_height();
extern void video_related_27();
extern int bgGetLevelVisibilityScale();

void copy_table1_env_to_current(EnvironmentRecord *fog_tables_Entry)
{
    f32 sp34;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 temp_f14;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;
    f32 temp_ret;

    set_page_height(fog_tables_Entry->Visibility.blendmultiplier,
                    fog_tables_Entry->Visibility.farfog); // 30, 15000
    video_related_27(&sp30);
    temp_ret = bgGetLevelVisibilityScale();
    temp_f6  = sp30 / temp_ret;
    sp30     = temp_f6;
    sp34     = (f32)(sp34 / temp_ret);

    // arg1 = agr0;

    bg_dif_light =
        (f32)((f32)fog_tables_Entry->Fog.DifferenceFromFarIntensity / 1000.0f);

    temp_f14 = sp34 - temp_f6;

    buffer_far_ambiant =
        (f32)((f32)fog_tables_Entry->Fog.FarIntensity / 1000.0f);

    near_fog_value = (f32)(temp_f6 + (temp_f14 * buffer_far_ambiant));

    near_fog_times_intensity = (f32)(temp_f6 + (temp_f14 * bg_dif_light));

    Curfarfogdetails.buffer_far_pervasiveness =
        (f32)(fog_tables_Entry->Visibility.blendmultiplier / temp_ret);

    sp18    = (f32)(buffer_far_ambiant - bg_dif_light);
    temp_f4 = sp18;

    Curfarfogdetails.far_fog =
        (f32)(fog_tables_Entry->Visibility.farfog / temp_ret);
    sp20 = (f32)(128.0f / temp_f4);
    temp_f8 =
        Curfarfogdetails.far_fog - Curfarfogdetails.buffer_far_pervasiveness;
    sp18 = temp_f8;
    sp1C = (f32)(((0.5f - bg_dif_light) * 256.0f) / temp_f4);
    Curfarfogdetails.flt_CODE_bss_800825D8 =
        (f32)((((-sp20 * Curfarfogdetails.far_fog) *
                (Curfarfogdetails.buffer_far_pervasiveness + 1.0f)) /
               temp_f8) /
              255.0f);
    Curfarfogdetails.flt_CODE_bss_800825DC =
        (f32)(((((Curfarfogdetails.far_fog + 1.0f) * sp20) / temp_f8) + sp1C) /
              255.0f);

    CurrentEnvironment.Fog.DifferenceFromFarIntensity =
        (f32)fog_tables_Entry->Fog.DifferenceFromFarIntensity;
    CurrentEnvironment.Fog.FarIntensity = fog_tables_Entry->Fog.FarIntensity;
    CurrentEnvironment.Sky.red          = fog_tables_Entry->Sky.red;
    CurrentEnvironment.Sky.green        = fog_tables_Entry->Sky.green;
    CurrentEnvironment.Sky.blue         = fog_tables_Entry->Sky.blue;
    CurrentEnvironment.Sky.clouds       = fog_tables_Entry->Sky.clouds;
    CurrentEnvironment.Sky.cloudrepeat  = fog_tables_Entry->Sky.cloudrepeat;
    CurrentEnvironment.Sky.skyimageid   = fog_tables_Entry->Sky.skyimageid;
    CurrentEnvironment.Sky.cloudred     = fog_tables_Entry->Sky.cloudred;
    CurrentEnvironment.Sky.cloudgreen   = fog_tables_Entry->Sky.cloudgreen;
    CurrentEnvironment.Sky.cloudblue    = fog_tables_Entry->Sky.cloudblue;
    CurrentEnvironment.Sky.iswater      = fog_tables_Entry->Sky.iswater;
    CurrentEnvironment.Sky.waterrepeat  = fog_tables_Entry->Sky.waterrepeat;
    CurrentEnvironment.Sky.waterimageid = fog_tables_Entry->Sky.waterimageid;
    CurrentEnvironment.Sky.waterred     = fog_tables_Entry->Sky.waterred;
    CurrentEnvironment.Sky.watergreen   = fog_tables_Entry->Sky.watergreen;
    CurrentEnvironment.Sky.waterblue    = fog_tables_Entry->Sky.waterblue;
    CurrentEnvironment.Sky.waterconcavity =
        fog_tables_Entry->Sky.waterconcavity;

    // Simplify Above to:
    // CurrentEnvironment.Fog = fog_tables_Entry->Fog;
    // CurrentEnvironment.Sky = fog_tables_Entry->Sky;
    if (fog_tables_Entry->Visibility.nearfog = 0)
    {
        ptr_nearfog_enviroment_values = 0;
    }
    else
    {
        ptr_nearfog_enviroment_values =
            (s32)(fog_tables_Entry->Visibility.nearfog); // not a pointer
    }
    gEnvironmentHasFog = 1;
    // return &CurrentEnvironment;
}
void load_enviroment(int StageID, int param_2)
{
    s32 NumPlayers;
    u32 EnvironmentUID;
    EnvironmentRecord *FogTablep;
    EnvironmentFoglessRecord *FogTableFoglessp;
    EnvironmentFoglessRecord *FogTableFoglessFoundp;

    NumPlayers = get_num_players();
    if (NumPlayers == 1)
    {
        NumPlayers = 0;
    }

    ScaledFarFogIntensity               = default_near_fog;
    ScaledDifferenceFromFarFogIntensity = 0.00000000;

    if (isCutscene)
    {
        FogTablep      = fog_tables;
        EnvironmentUID = fog_tables[0].ID;
        while (EnvironmentUID != ENVIRONMENTDATA_END)
        {
            if (StageID + ENVIRONMENTDATA_CINEMA == EnvironmentUID)
            {
                gEnvironmentFoundp = FogTablep;
                gEnvironmentMainp  = FogTablep;
                gEnvironmentAltp   = FogTablep + 1;
                copy_table1_env_to_current(gEnvironmentFoundp);
                return;
            }
            EnvironmentUID = FogTablep[1].ID; // Next ID
            FogTablep++;
        }
    }

    EnvironmentUID = fog_tables[0].ID;
    FogTablep      = fog_tables;
    while (EnvironmentUID != ENVIRONMENTDATA_END)
    {
        if (StageID + NumPlayers * 100 == EnvironmentUID)
        {
            gEnvironmentFoundp = FogTablep;
            gEnvironmentMainp  = FogTablep;
            gEnvironmentAltp   = FogTablep + 1;
            copy_table1_env_to_current(gEnvironmentFoundp);
            return;
        }
        EnvironmentUID = FogTablep[1].ID;
        FogTablep++;
    }

    // default MP Skies
    if (NumPlayers > 1)
    {
        EnvironmentUID = fog_tables[0].ID;
        while (EnvironmentUID != ENVIRONMENTDATA_END)
        {
            if (NumPlayers * 100 == EnvironmentUID)
            {
                gEnvironmentFoundp = FogTablep;
                gEnvironmentMainp  = FogTablep;
                gEnvironmentAltp   = FogTablep + 1;
                copy_table1_env_to_current(gEnvironmentFoundp);
                return;
            }
            EnvironmentUID = FogTablep[1].ID;
            FogTablep++;
        }
    }

    // still no Environment, Assume Fogless
    set_page_height(15.00000000, (f32)flt_80058D74);
    gEnvironmentHasFog = 0;
    FogTableFoglessp   = fog_tables2;
    EnvironmentUID     = fog_tables2[0].ID;
    while (EnvironmentUID != ENVIRONMENTDATA_END)
    {
        if (StageID == EnvironmentUID)
        {
            FogTableFoglessFoundp = FogTableFoglessp;
        }
        EnvironmentUID = FogTableFoglessp[1].ID;
        FogTableFoglessp++;
    }

    // still No Environment?
    if (FogTableFoglessFoundp == NULL)
    {
        FogTableFoglessFoundp = fog_tables2; // Use first Fogless as default
    }
    copy_table2_env_to_current((int)FogTableFoglessFoundp);
    gEnvironmentFoundp = NULL; // Why bother, its never used again
    return;
}

void switch_to_solosky2(f32 Opacity)
{
    /*
     * called by 7f055f64
     Arg0 value table on activation
     0.000278
     0.1000
     0.105278 (1 frame = 0.000278)
     0.130278
     0.130556
     ...
     0.998889
     1
     1
     loop forever?
     */

    // cast static variables to EnvData
    EnvironmentRecord *TransitionEnvironmentp =
        (EnvironmentRecord *)&TransitionEnvironmentID;

    // EnvironmentRecord *gEnvironmentAltp = 0;

    *TransitionEnvironmentp = *gEnvironmentMainp; // copy values from 1st sky

    // NextEnvironmentp = gEnvironmentAltp; //dont name or assign, use directly

    // now alter some parts for transitioning to 2nd sky
    TransitionEnvironmentBlendMult =
        (gEnvironmentMainp->Visibility.blendmultiplier +
         (Opacity * (gEnvironmentAltp->Visibility.blendmultiplier -
                     gEnvironmentMainp->Visibility.blendmultiplier)));

    TransitionEnvironmentFarFog =
        (gEnvironmentMainp->Visibility.farfog +
         (Opacity * (gEnvironmentAltp->Visibility.farfog -
                     gEnvironmentMainp->Visibility.farfog)));

    TransitionEnvironmentDiffFarFog =
        (gEnvironmentMainp->Fog.DifferenceFromFarIntensity +
         (Opacity * ((f32)gEnvironmentAltp->Fog.DifferenceFromFarIntensity -
                     gEnvironmentMainp->Fog.DifferenceFromFarIntensity)));
    /*Match down to here--*/
    /*has extra lui	at,0x HI TransitionEnvironmentFarIntensity*/
    TransitionEnvironmentFarIntensity =
        (gEnvironmentMainp->Fog.FarIntensity +
         (Opacity * ((f32)gEnvironmentAltp->Fog.FarIntensity -
                     gEnvironmentMainp->Fog.FarIntensity)));

    {
#        if 0
        volatile f32 aa, bb, cc;
        volatile f32 a, b, c;
        a   = (Opacity * ((f32)gEnvironmentAltp->Sky.red -
                      gEnvironmentMainp->Sky.red));
        TransitionEnvironmentSkyRed =
            (gEnvironmentMainp->Sky.red + (u8)a) & 0xf8;
        b  = (Opacity * ((f32)gEnvironmentAltp->Sky.green -
                      gEnvironmentMainp->Sky.green));
        TransitionEnvironmentSkyGreen =
            (gEnvironmentMainp->Sky.green + (u8)b) & 0xf8;
        c = (Opacity * ((f32)gEnvironmentAltp->Sky.blue -
                      gEnvironmentMainp->Sky.blue));
        TransitionEnvironmentSkyBlue =
            (gEnvironmentMainp->Sky.blue + (u8)c) & 0xf8;
#        endif
        /*Closest to match but with andi order difference */
        TransitionEnvironmentSkyRed =
            (u32)(gEnvironmentMainp->Sky.red +
                  (Opacity * ((f32)gEnvironmentAltp->Sky.red -
                              gEnvironmentMainp->Sky.red))) &
            248;

        TransitionEnvironmentSkyGreen =
            (u32)(gEnvironmentMainp->Sky
                      .green + /*& f8 for Red happens round here*/
                  (Opacity * ((f32)gEnvironmentAltp->Sky.green -
                              gEnvironmentMainp->Sky.green))) &
            248;

        TransitionEnvironmentSkyBlue =
            (u32)(gEnvironmentMainp->Sky.blue +
                  /*& f8 for Green happens round here*/
                  (Opacity * ((f32)gEnvironmentAltp->Sky.blue -
                              gEnvironmentMainp->Sky.blue))) &
            248;

        /*& f8 for Blue happens round here*/
        // Store Bytes happen here but
        // cannot be repeated like below otherwise a1-a3 are produced
        // TransitionEnvironmentSkyRed &= 248;
        // TransitionEnvironmentSkyGreen &= 248;
        // TransitionEnvironmentSkyBlue &= 248;
        copy_table1_env_to_current(TransitionEnvironmentp);
    }
}
#    endif

#    ifdef DebugAIExecute

#        include "../src/bondaicommands.h" //make sure this is after constants
#        include "../src/game/chrai.h"

#        if 0

/******************************************************************************
 * this is a brief description of func
 * with a new line
 * @param thing1 = number of theory
 * @param thing2 = thing21
 * @returns nothing
 *****************************************************************************/
void cstyle(int theory, int theory2) {}

/**
 * this is a brief description of func
 * with a new line
 * @param thing1 = number of theory
 * @param thing2 = thing21
 * @return nothing
 */
void cstyle2(int theory, int theory2) {}

/// <summary>
/// this is a test
/// </summary>
/// <param name="theory"> number of therory</param>
/// <param name="theory2"> thing2</param>
/// <returns>nothing</returns>
void cstyle43(int theory, int theory2) {}
#        endif


#        if 0
int assertTest(void *Entityp, s32 EntityType)
{
    // initialise to 0
    VehichleRecord *VehichleEntityp = NULL; // a2
    AircraftRecord *AircraftEntityp = NULL; // v1
    ChrRecord *ChrEntityp           = NULL; // s7
    s32 regs1                       = 1;
    s32 regs2                       = 2;
    s32 regs3                       = 3;
    s32 regs4                       = 4;
    s32 regs5                       = 5;
    s32 regs6                       = 6;
    s32 regs7                       = 7;
    s32 regs8                       = 8;
    s32 regs9                       = 9;
    s32 regs10                       = 10;
    s32 regs11                       = 11;
    s32 regs0                       = 0; // s2 save/load tofrom sp7a4


    if (EntityType == PROP_TYPE_CHR) //ra,116  f20 48sp  f22 52sp
    {
        ChrEntityp = Entityp;
    }

    if (EntityType == PROP_TYPE_OBJ) //not elseif to stop double li,at,1
    {
        if (((ObjectRecord *)Entityp)->type == PROPDEF_VEHICHLE)
        {
            VehichleEntityp = Entityp;
        }
        else if (((ObjectRecord *)Entityp)->type == PROPDEF_AIRCRAFT)
        {
            AircraftEntityp = Entityp;
        }
    }
    // Load ailist
    if (ChrEntityp)
    {
        regs1   = ChrEntityp->accuracyrating;
        regs2   = ChrEntityp->speedrating;
        regs3   = ChrEntityp->sleep;
        regs4   = ChrEntityp->headnum;
        regs5    = ChrEntityp->invalidmove;
        regs6    = ChrEntityp->numarghs;
        regs7    = ChrEntityp->numclosearghs;
        regs8    = ChrEntityp->chrnum;
        regs0    = ChrEntityp->aioffset; // offset 0x108 264
        regs9    = ChrEntityp->chrwidth;
        regs10    = ChrEntityp->fadealpha;
        regs11    = ChrEntityp->field_184;
   }
    else if (VehichleEntityp) // truck
    {
        regs1   = ChrEntityp->accuracyrating;
        regs2   = ChrEntityp->speedrating;
        regs3   = ChrEntityp->sleep;
        regs4   = ChrEntityp->headnum;
        regs5   = ChrEntityp->invalidmove;
        regs6   = ChrEntityp->numarghs;
        regs7   = ChrEntityp->numclosearghs;
        regs8   = ChrEntityp->chrnum;

        regs0 = VehichleEntityp->aioffset; // offset 0x84 132
        regs9  = ChrEntityp->chrwidth;
        regs10 = ChrEntityp->fadealpha;
        regs11 = ChrEntityp->field_184;
    }
    else if (AircraftEntityp) // heli
    {
        regs1   = ChrEntityp->accuracyrating;
        regs2   = ChrEntityp->speedrating;
        regs3   = ChrEntityp->sleep;
        regs4   = ChrEntityp->headnum;
        regs5   = ChrEntityp->invalidmove;
        regs6   = ChrEntityp->numarghs;
        regs7   = ChrEntityp->numclosearghs;
        regs8   = ChrEntityp->chrnum;

        regs0 = AircraftEntityp->aioffset; // offset 0x84 132
        regs9  = ChrEntityp->chrwidth;
        regs10 = ChrEntityp->fadealpha;
        regs11 = ChrEntityp->field_184;
    }

    {
        for (;;) // loop forever (or until broken)
        {
            AIRecord *ai = ((AIRecord *)regs0 + regs6);
            switch (ai->cmd)
            {
                case AI_GOTO_NEXT:
                {
                    switch (((AIRecord *)regs3)->cmd)
                    {
                        case 0:
                            return;
                        case 1:
                            return;
                    }
                    regs0 = chraiGoT2oLabel(ChrEntityp, ai,regs0, regs1, regs2, regs3, regs4, regs5, regs6, regs7, regs8, regs9, regs10, regs11);
                    break;
                }
                case AI_GOTO_FIRST:
                {
                    switch (((AIRecord *)regs3)->cmd)
                    {
                        case 0:
                            return;
                        case 1:
                            return;
                    }
                    regs0 = chraiGoT2oLabel(ChrEntityp, ai, regs0, regs1, regs2, regs3, regs4, regs5, regs6, regs7, regs8, regs9, regs10, regs11);
                    break;
                }
            }
        }
    }
}
#        endif
#        endif



typedef struct bitdesc //0xc long
{
    u16 start;  //   <= bit offset to the data within one frame?
    u8  num;    //   <= number of bits per value?
    s16 offset; //   <= an offset value for all stored data values - so need to add this to values obtained from the following transroty data
} bitdesc;

typedef struct AnimationKeyframe  //0xcc long
{
    s16 keyframeTranslationX;
    s16 keyframeTranslationY;
    s16 keyframeTranslationZ;
    f32 keyframeYRotation;
    vec3d partRotations[0x10];
} AnimationKeyframe;

typedef struct AnimationHeader //0x18 long
{
    AnimationKeyframe *motion;        //   <= joint rotation data stored on rom
    u16                numframes;     //   <= number of frames of animation data
    u8                 rotbits;       //   <= number of bits per x, y, z rotation?
    u8                 flags;         //   <= for looping or forcing a gun to drop on death
    bitdesc           *bitsrel;       //   <= points to bitsdesc array at start
    u16                bitssizerel;   //   <= number of bits in one frame of transroty data
    u16                bitssize;      //   <= number of bits in one frame of joint rotation data
    u8 *               bitsmotionrel; //   <= points to transroty data (following the bitsdesc array)
} AnimationHeader;
#        define PTR_ANIM_ENTRY_idle 0x0000
// this is a sample of Idle Pose (_animation_dataSegmentRomStart)
u32 ANIM_DATA_idle[] =
    {
        {PTR_ANIM_ENTRY_idle, 0x00a3, 0x0c, 0x00, 0x00000000, 0x0000, 0x0220, 0x00000018},
        {0x0000, 0x06, 0x0000}, //x
        (0x0100, 0x06, 0x0700}, //y
        (0x0412, 0x00, 0x0d06}. //z
        (0x00ff, 0xff, 0x0013}, //rot
    {0x0000, 0x00, 0x0019},
    {0x6864, 0xae, 0xf0b5},
    {0x9e14, 0xb0, 0x1516},
    {0x763a, 0xa0, 0x0552},
    {0x202a, 0x42, 0x0148},
    {0x422a, 0x17, 0xf501},
    {0x7e98, 0x1f, 0x520d},
    {0xea85, 0x7e, 0x4e58},
    {0x6748, 0x20, 0xb0a5},
    {0x8c2c, 0x60, 0xe310},
    {0x14d2, 0x02, 0xa038},
    {0x7446, 0x10, 0x70a2},
    {0x1134, 0x13, 0x84fb},
    {0x401f, 0x42, 0x0bd0},
    {0xb0f8, 0x8e, 0x7643},
    {0xc8b4, 0x40, 0x1683},
    {0xfae0, 0x7e, 0x6523},
    {0xcd63, 0xf9, 0xb84e},
    {0xfb8b, 0xdf, 0xb17d},
    {0xf81f, 0x7f, 0x84f7},
    {0xf89f, 0x7c, 0x07ff},
    {0x807f, 0xec, 0x1ffd},
    {0x03ff, 0xb0, 0x40f6},
    {0x081e, 0x82, 0x03d8},
    {0x3ffa, 0x07, 0xff80},
    {0xfff8, 0x1f, 0xff04},
    {0x07e0, 0x81, 0xf80f},
    {0xff01, 0xff, 0xf03f},
    {0xfd07, 0xff, 0xa0fd},
    {0xf41f, 0xfe, 0x83ff},
    {0xc07f, 0xf8, 0x0fff},
    {0x01ff, 0xe0, 0x5ffd},
    {0x07ef, 0xc0, 0xfffc},
    {0x1fff, 0x83, 0xfff0},
    {0xbffe, 0x0f, 0xff43},
    {0xfbe0, 0xff, 0xf81b},
    {0xff00, 0xff, 0xe010},
    {0x3c03, 0xff, 0x707f},
    {0xf00f, 0xdd, 0x81fb},
    {0xb01e, 0x77, 0xf79f},
    {0x5ee8, 0x03, 0xae7d},
    {0x79f7, 0xc0, 0x3ef7},
    {0xff5d, 0xb7, 0xe3af},
    {0x55ed, 0xb3, 0x3cf7},
    {0xe186, 0xdb, 0xae57},
    {0x9d99, 0xf3, 0xa515},
    {0x74a4, 0xda, 0xcd99},
    {0xe0cb, 0x3c, 0xb8fd},
    {0xc72f, 0x82, 0x03f1},
    {0x707e, 0x40, 0x0fcb},
    {0x41f9, 0x60, 0x3f2c},
    0x04
}
;

//blob for animation data, variable length keyframes (_animation_tableSegmentRomStart) bitArry cannot be made into structs
u32 ANIM_ENTRY_idle[] =
    {
        {0xfa0f7f00,
         0x8034029f,
         0xfb06805c,
         0x03607a01,
         0xfc99a817,
         0x57c8d000},

        {
            0xd5d00000,
            0x0239000a,
            0x86f68fb5,
            0xf57fcb12,
            0x6fe203fc,
            0x040e6fe2,
            0x3bd00003,
            0xe000000f
        },
        0xb8000f7f,
        0xfe8ff4fb,
        0xd01f0390,
        0xfa0f7f00,
        0x8033029f,
        0xfb06805c,
        0x03507a01,
        0xfc99a827,
        0x56c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00003,
        0xf000000f,
        0xbb000f7f,
        0xfe8ff4fc,
        0x101d03b0,
        0xfa0f7f00,
        0x8033029f,
        0xfb06805c,
        0x03507a01,
        0xfc99a827,
        0x56c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00003,
        0xe000000f,
        0xba000f80,
        0xfe8ff4fb,
        0xe01e03a0,
        0xfa0f7f00,
        0x8033029f,
        0xfb06805a,
        0x03407a01,
        0xfc99a827,
        0x56c8d000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00003,
        0xd000000f,
        0xb9000f80,
        0xfe8ff4fb,
        0xb01f0380,
        0xf9ff7f00,
        0x7033029f,
        0xfb069059,
        0x03407a01,
        0xfc99a817,
        0x57c8d000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00003,
        0xf000000f,
        0xba000f7f,
        0xfe8ff4fb,
        0xe01e0390,
        0xf9df7f00,
        0x703302af,
        0xfb06a059,
        0x03407a01,
        0xfc99a837,
        0x56c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xb9000f7f,
        0xfe8ff4fc,
        0x101d03b0,
        0xf9cf7f00,
        0x7032029f,
        0xfb06a059,
        0x03407a01,
        0xfc99a837,
        0x55c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xb9000f7f,
        0xfe8ff4fc,
        0x201d03c0,
        0xf99f7e00,
        0x7033029f,
        0xfb06a05a,
        0x03407a01,
        0xfc99a847,
        0x55c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x3000000f,
        0xb9000f7f,
        0xfe8ff4fc,
        0x501c03d0,
        0xf96f7e00,
        0x7034029f,
        0xfb06b05a,
        0x03407a01,
        0xfc99a847,
        0x55c8d000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xbb000f7e,
        0xfe8ff4fc,
        0xa01a0400,
        0xf97f7e00,
        0x7034029f,
        0xfb06b05a,
        0x03407a01,
        0xfc99a857,
        0x55c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xbb000f7e,
        0xfe8ff4fc,
        0xa01a0410,
        0xf98f7e00,
        0x7034028f,
        0xfb06b05a,
        0x03507a01,
        0xfc99a877,
        0x54c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x6000000f,
        0xbb000f7e,
        0xfe8ff4fc,
        0x801b0400,
        0xf99f7e00,
        0x7034028f,
        0xfb06b05b,
        0x03607a01,
        0xfc99a877,
        0x55c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x7000000f,
        0xbb000f7e,
        0xfe8ff4fc,
        0x901a0400,
        0xf9af7e00,
        0x7034027f,
        0xfb06c05b,
        0x03607a01,
        0xfc99a887,
        0x55c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x7000000f,
        0xbc000f7e,
        0xfe8ff4fc,
        0xa01a0400,
        0xf9bf7e00,
        0x7034026f,
        0xfb06c05b,
        0x03607a01,
        0xfc99a887,
        0x56c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x6000000f,
        0xbd000f7e,
        0xfe8ff4fc,
        0x601b03e0,
        0xf9af7e00,
        0x7034026f,
        0xfb06c05b,
        0x03607a01,
        0xfc99a867,
        0x56c8c000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x7000000f,
        0xbf000f7e,
        0xfe8ff4fc,
        0x501b03d0,
        0xf9af7e00,
        0x7035027f,
        0xfb06b05b,
        0x03607a01,
        0xfc99a857,
        0x57c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xc0000f7e,
        0xfe8ff4fc,
        0x701a03e0,
        0xf9cf7e00,
        0x7035027f,
        0xfb06c05b,
        0x03707a01,
        0xfc99a847,
        0x58c8c000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xc1000f7e,
        0xfe8ff4fc,
        0x801a03e0,
        0xf9cf7e00,
        0x7035027f,
        0xfb06c05b,
        0x03707a01,
        0xfc99a847,
        0x58c8c000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xc1000f7e,
        0xfe8ff4fc,
        0x801a03e0,
        0xf9cf7e00,
        0x7035027f,
        0xfb06c05c,
        0x03707a01,
        0xfc99a857,
        0x57c8b000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x6000000f,
        0xc0000f7e,
        0xfe8ff4fc,
        0x601b03d0,
        0xf9cf7e00,
        0x7034026f,
        0xfb06c05c,
        0x03807a01,
        0xfc99a877,
        0x55c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbf000f7f,
        0xfe8ff4fc,
        0x301c03c0,
        0xf9bf7e00,
        0x7034027f,
        0xfb06b05c,
        0x03807a01,
        0xfc99a867,
        0x55c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xbf000f7f,
        0xfe8ff4fc,
        0x401b03d0,
        0xf9bf7e00,
        0x7035027f,
        0xfb06b05c,
        0x03807a01,
        0xfc99a857,
        0x55c8d000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x7000000f,
        0xc0000f7e,
        0xfe8ff4fc,
        0x401b03d0,
        0xf9ef7e00,
        0x7034028f,
        0xfb06a05b,
        0x03907a01,
        0xfc99a847,
        0x55c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xc0000f7f,
        0xfe8ff4fc,
        0x001d03a0,
        0xfa1f7e00,
        0x7033026f,
        0xfa06b05c,
        0x03a07a01,
        0xfc99a887,
        0x53c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xc0000f7f,
        0xfe8ff4fb,
        0xd01e0380,
        0xfa1f7e00,
        0x8033026f,
        0xfa06c05d,
        0x03c07a01,
        0xfc99a8b7,
        0x51c8a000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xc1000f7f,
        0xfe8ff4fb,
        0xf01e0390,
        0xfa2f7f00,
        0x8033025f,
        0xfa06c05d,
        0x03d07a01,
        0xfc99a8d7,
        0x50c89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xc0000f7f,
        0xfe8ff4fb,
        0xd01e0390,
        0xfa2f7f00,
        0x8033025f,
        0xfa06d05d,
        0x03c07a01,
        0xfc99a8e7,
        0x50c89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xb01f0370,
        0xfa3f7e00,
        0x8034026f,
        0xfa06d05d,
        0x03d07a01,
        0xfc99a8d7,
        0x50c8a000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xe01e0390,
        0xfa4f7e00,
        0x8035027f,
        0xfa06d05d,
        0x03d07a01,
        0xfc99a8e7,
        0x50c8a000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xbe000f7f,
        0xfe8ff4fc,
        0x101d03b0,
        0xfa8f7e00,
        0x8036026f,
        0xfa06e05d,
        0x03c07a01,
        0xfc99a907,
        0x4fc89000,
        0xd5d00000,
        0x023c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xf01d03a0,
        0xfa8f7e00,
        0x8036025f,
        0xfa06f05d,
        0x03c07a01,
        0xfc99a907,
        0x4fc89000,
        0xd5d00000,
        0x023c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xf01c03a0,
        0xfa7f7e00,
        0x8037025f,
        0xfa06f05d,
        0x03d07a01,
        0xfc99a907,
        0x50c89000,
        0xd5d00000,
        0x023d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xf01c03a0,
        0xfa8f7f00,
        0x8036025f,
        0xfa06f05d,
        0x03d07a01,
        0xfc99a8f7,
        0x50c89000,
        0xd5d00000,
        0x023d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xba000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa7f7f00,
        0x8037025f,
        0xfa06f05e,
        0x03d07a01,
        0xfc99a8e7,
        0x50c8a000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xba000f7f,
        0xfe8ff4fb,
        0xc01d0390,
        0xfa6f7f00,
        0x8038025f,
        0xfb06f05f,
        0x03c07a01,
        0xfc99a8d7,
        0x4fc8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xbb000f7f,
        0xfe8ff4fb,
        0xe01d03a0,
        0xfa6f7f00,
        0x8038025f,
        0xfb06f05f,
        0x03c07a01,
        0xfc99a8d7,
        0x4fc8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xbb000f7f,
        0xfe8ff4fb,
        0xe01d03a0,
        0xfa6f7f00,
        0x8038027f,
        0xfb06e05d,
        0x03c07a01,
        0xfc99a897,
        0x51c8c000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbb000f80,
        0xfe8ff3fb,
        0xc01d0390,
        0xfa6f7f00,
        0x8038028f,
        0xfb06e05c,
        0x03c07a01,
        0xfc99a877,
        0x52c8c000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbb000f80,
        0xfe8ff3fb,
        0xc01d0380,
        0xfa6f7f00,
        0x8038027f,
        0xfb06e05d,
        0x03d07a01,
        0xfc99a887,
        0x51c8b000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbb000f80,
        0xfe8ff3fb,
        0xc01d0380,
        0xfa7f7f00,
        0x8037026f,
        0xfb06e060,
        0x03f07a01,
        0xfc99a8b7,
        0x4fc8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbb000f80,
        0xfe8ff3fb,
        0xb01e0380,
        0xfa7f7f00,
        0x8037026f,
        0xfb06e061,
        0x04107a01,
        0xfc99a8b7,
        0x4ec8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbc000f80,
        0xfe8ff3fb,
        0xb01e0380,
        0xfa7f7f00,
        0x8037026f,
        0xfb06e062,
        0x04107a01,
        0xfc99a8c7,
        0x4ec8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbc000f80,
        0xfe8ff3fb,
        0xb01e0380,
        0xfa6f7f00,
        0x8036026f,
        0xfb06e062,
        0x04107a01,
        0xfc99a8d7,
        0x4dc8a000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbc000f80,
        0xfe8ff3fb,
        0xb01e0380,
        0xfa6f7f00,
        0x8036026f,
        0xfb06e062,
        0x04107a01,
        0xfc99a8e7,
        0x4dc8a000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbc000f80,
        0xfe8ff3fb,
        0xc01e0380,
        0xfa4f7f00,
        0x8037027f,
        0xfb06e062,
        0x04207a01,
        0xfc99a8e7,
        0x4dc8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa4f7f00,
        0x8037027f,
        0xfb06e063,
        0x04307a01,
        0xfc99a8f7,
        0x4dc8a000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xe01d03a0,
        0xfa5f7f00,
        0x8037026f,
        0xfa06e063,
        0x04407a01,
        0xfc99a907,
        0x4dc8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa5f7f00,
        0x8037026f,
        0xfa06f064,
        0x04507a01,
        0xfc99a907,
        0x4dc8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa4f7f00,
        0x8038026f,
        0xfb071065,
        0x04607a01,
        0xfc99a917,
        0x4dc8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xe01d03a0,
        0xfa5f7f00,
        0x8038026f,
        0xfa071065,
        0x04707a01,
        0xfc99a927,
        0x4dc89000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa5f7f00,
        0x8038026f,
        0xfa071065,
        0x04707a01,
        0xfc99a917,
        0x4ec8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xb01d0380,
        0xfa5f7f00,
        0x8038026f,
        0xfb072065,
        0x04707a01,
        0xfc99a907,
        0x4ec8a000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xb01d0380,
        0xfa5f7f00,
        0x8038027f,
        0xfb072066,
        0x04807a01,
        0xfc99a8f7,
        0x4fc89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa5f7f00,
        0x8037027f,
        0xfa072066,
        0x04807a01,
        0xfc99a8f7,
        0x4fc89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xd01c0390,
        0xfa5f7f00,
        0x8037027f,
        0xfa072066,
        0x04807a01,
        0xfc99a8f7,
        0x4fc89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbf000f7f,
        0xfe8ff4fb,
        0xd01c0390,
        0xfa4f7f00,
        0x8038027f,
        0xfb071066,
        0x04607a01,
        0xfc99a8c7,
        0x4fc8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbf000f80,
        0xfe8ff4fb,
        0xb01d0390,
        0xfa4f7f00,
        0x8038027f,
        0xfb071066,
        0x04707a01,
        0xfc99a8c7,
        0x4fc8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0xb01d0380,
        0xfa5f7f00,
        0x8037027f,
        0xfb071066,
        0x04607a01,
        0xfc99a8c7,
        0x4fc8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xc1000f80,
        0xfe7ff3fb,
        0x901e0370,
        0xfa7f7f00,
        0x8036028f,
        0xfb071065,
        0x04607a01,
        0xfc99a8b7,
        0x50c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xc1000f80,
        0xfe7ff3fb,
        0x50200340,
        0xfa8f7f00,
        0x8035029f,
        0xfb070063,
        0x04507a01,
        0xfc99a887,
        0x52c8c000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe103fc,
        0x040e6fe2,
        0x3be00003,
        0xf000000f,
        0xc0000f80,
        0xfe7ff3fb,
        0x10220310,
        0xfa7f7f00,
        0x803602af,
        0xfb070063,
        0x04407a01,
        0xfc99a897,
        0x53c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe103fc,
        0x040e6fe2,
        0x3bd00003,
        0xf000000f,
        0xc0000f80,
        0xfe7ff3fb,
        0x20210320,
        0xfa7f7f00,
        0x803602af,
        0xfb071063,
        0x04407a01,
        0xfc99a8d7,
        0x52c8c000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xc1000f80,
        0xfe7ff3fb,
        0x60200350,
        0xfa6f7f00,
        0x803602bf,
        0xfb071063,
        0x04407a01,
        0xfc99a907,
        0x51c8d000,
        0xd5d00000,
        0x0234000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x701f0360,
        0xfa5f7f00,
        0x803702cf,
        0xfb072063,
        0x04407a01,
        0xfc99a927,
        0x51c8d000,
        0xd5d00000,
        0x0233000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0xa01d0380,
        0xfa6f7f00,
        0x803702cf,
        0xfb072063,
        0x04407a01,
        0xfc99a937,
        0x52c8c000,
        0xd5d00000,
        0x0234000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc0000f7f,
        0xfe8ff4fb,
        0xc01c03a0,
        0xfa8f7f00,
        0x803702cf,
        0xfb073063,
        0x04507a01,
        0xfc99a957,
        0x53c8c000,
        0xd5d00000,
        0x0235000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0xa01c0390,
        0xfa8f7f00,
        0x803602bf,
        0xfb073064,
        0x04507a01,
        0xfc99a947,
        0x55c8c000,
        0xd5d00000,
        0x0235000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x701d0370,
        0xfa7f7f00,
        0x803702bf,
        0xfb074064,
        0x04507a01,
        0xfc99a957,
        0x56c8c000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xbf000f7f,
        0xfe8ff4fb,
        0xa01b0390,
        0xfa8f7f00,
        0x803602af,
        0xfb075065,
        0x04607a01,
        0xfc99a967,
        0x56c8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0x901b0390,
        0xfaaf8000,
        0x8034027f,
        0xfb075064,
        0x04607a01,
        0xfc99a957,
        0x58c8c000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xe000000f,
        0xbd000f80,
        0xfe8ff3fb,
        0x001e0330,
        0xfa9f8000,
        0x8033025f,
        0xfb074064,
        0x04607a01,
        0xfc99a947,
        0x59c8d000,
        0xd5d00000,
        0x0235000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe103fc,
        0x040e6fe3,
        0x3be00003,
        0xd000000f,
        0xbf000f81,
        0xfe8ff3fa,
        0xe01f0310,
        0xfa7f8000,
        0x8034026f,
        0xfb074064,
        0x04707a01,
        0xfc99a957,
        0x59c8c000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xe000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x201d0350,
        0xfa6f8000,
        0x8034026f,
        0xfb074064,
        0x04807a01,
        0xfc99a977,
        0x58c8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xd000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x401b0360,
        0xfa5f8000,
        0x8034026f,
        0xfb074064,
        0x04907a01,
        0xfc99a987,
        0x58c8b000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xd000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x401b0360,
        0xfa3f7f00,
        0x8035026f,
        0xfc073065,
        0x04807a01,
        0xfc99a997,
        0x57c8c000,
        0xd5d00000,
        0x0234000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x70190380,
        0xfa4f7f00,
        0x8035026f,
        0xfc073065,
        0x04807a01,
        0xfc99a9b7,
        0x56c8c000,
        0xd5d00000,
        0x0234000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x70190380,
        0xfa6f8000,
        0x8034025f,
        0xfb073065,
        0x04707a01,
        0xfc99a9d7,
        0x55c8c000,
        0xd5d00000,
        0x0233000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xe000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x401a0350,
        0xfa5f8000,
        0x8034025f,
        0xfc074064,
        0x04707a01,
        0xfc99a9d7,
        0x55c8c000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xe000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x401a0360,
        0xfa5f8000,
        0x8034025f,
        0xfc074064,
        0x04707a01,
        0xfc99a9e7,
        0x55c8c000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xf000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x501a0360,
        0xfa4f8000,
        0x8034025f,
        0xfc078063,
        0x04707a01,
        0xfc99aa17,
        0x54c8a000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x60190370,
        0xfa4f8000,
        0x8034024f,
        0xfc078062,
        0x04707a01,
        0xfc99aa37,
        0x54c8a000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x60190370,
        0xfa5f8000,
        0x8035024f,
        0xfc079061,
        0x04707a01,
        0xfc99aa37,
        0x54c8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x50190370,
        0xfa5f8000,
        0x8036025f,
        0xfc07b061,
        0x04707a01,
        0xfc99aa47,
        0x54c8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x80180380,
        0xfa7f8000,
        0x8037025f,
        0xfc07c060,
        0x04707a01,
        0xfc99aa57,
        0x54c89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x80170380,
        0xfa8f8000,
        0x8037026f,
        0xfb07c05e,
        0x04607a01,
        0xfc99aa47,
        0x54c89000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xe000000f,
        0xbd000f80,
        0xfe8ff3fb,
        0x50180360,
        0xfa7f8000,
        0x8038026f,
        0xfc07b05e,
        0x04707a01,
        0xfc99aa27,
        0x55c8a000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x60180370,
        0xfa4f8000,
        0x803a026f,
        0xfc07a05d,
        0x04707a01,
        0xfc99a9f7,
        0x56c8a000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x90160390,
        0xfa5f8000,
        0x803a026f,
        0xfc07b05d,
        0x04807a01,
        0xfc99aa07,
        0x55c8a000,
        0xd5d00000,
        0x0233000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x80160390,
        0xfa5f8000,
        0x803a026f,
        0xfc07a05d,
        0x04807a01,
        0xfc99aa17,
        0x52c89000,
        0xd5d00000,
        0x0233000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x60170380,
        0xfa4f8000,
        0x803b027f,
        0xfc07905d,
        0x04807a01,
        0xfc99aa17,
        0x50c8a000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x60170370,
        0xfa3f8000,
        0x803c028f,
        0xfc07805b,
        0x04807a01,
        0xfc99a9e7,
        0x51c8c000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x70160380,
        0xfa4f8000,
        0x803c029f,
        0xfc07805a,
        0x04807a01,
        0xfc99a9c7,
        0x51c8c000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x50170370,
        0xfa3f8000,
        0x803b029f,
        0xfb07905a,
        0x04a07a01,
        0xfc99a9f7,
        0x4fc8b000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xe000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x50170360,
        0xfa2f8000,
        0x803c028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x70170380,
        0xfa3f8000,
        0x803d028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa07,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x80170380,
        0xfa3f8000,
        0x803d028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa07,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x80170390,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8c000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x50180360,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8c000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x40180350,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8c000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x50180360,
        0xfa4f8000,
        0x803d028f,
        0xfb079059,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x1000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x60180370,
        0xfa4f8000,
        0x803d028f,
        0xfb079059,
        0x04b07a01,
        0xfc99aa17,
        0x4dc8b000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x40180360,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04b07a01,
        0xfc99aa27,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00004,
        0x1000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x30190350,
        0xfa3f8000,
        0x803d028f,
        0xfb07905a,
        0x04b07a01,
        0xfc99aa27,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe4,
        0x3be00004,
        0x2000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x40180360,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04b07a01,
        0xfc99aa27,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00004,
        0x2000000f,
        0xc1000f80,
        0xfe8ff3fb,
        0x30180360,
        0xfa4f8100,
        0x803c028f,
        0xfb07905a,
        0x04b07a01,
        0xfc99aa27,
        0x4ec8b000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc1000f80,
        0xfe8ff3fb,
        0x20190350,
        0xfa3f8000,
        0x803c028f,
        0xfb07805a,
        0x04c07a01,
        0xfc99aa17,
        0x4ec8b000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc2000f80,
        0xfe8ff3fb,
        0x20190350,
        0xfa0f8000,
        0x803d028f,
        0xfb07805a,
        0x04d07a01,
        0xfc99aa07,
        0x4fc8b000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x60170380,
        0xf9ff8000,
        0x803e029f,
        0xfb07705a,
        0x04c07a01,
        0xfc99aa17,
        0x4ec8b000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x4000000f,
        0xc4000f7f,
        0xfe8ff3fb,
        0x80160390,
        0xfa0f8000,
        0x803d029f,
        0xfb07605a,
        0x04c07a01,
        0xfc99aa17,
        0x4ec8a000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc4000f7f,
        0xfe8ff3fb,
        0x70170380,
        0xf9ff8000,
        0x803c028f,
        0xfc07705b,
        0x04d07a01,
        0xfc99aa17,
        0x4fc8b000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x70170370,
        0xfa0f8000,
        0x803b028f,
        0xfc07705b,
        0x04e07a01,
        0xfc99aa17,
        0x50c8c000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x70170370,
        0xfa1f8000,
        0x8037025f,
        0xfb07a05d,
        0x05007a01,
        0xfc99aa87,
        0x4fc89000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x50180360,
        0xfa1f8000,
        0x8034024f,
        0xfb07c05e,
        0x05107a01,
        0xfc99aac7,
        0x4ec88000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x40190360,
        0xfa0f8000,
        0x8034023f,
        0xfb07d05f,
        0x05007a01,
        0xfc99aad7,
        0x4ec89000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc3000f80,
        0xfe8ff3fb,
        0x40190360,
        0xfa0f8000,
        0x8034023f,
        0xfb07d05f,
        0x05007a01,
        0xfc99aad7,
        0x4fc89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x2000000f,
        0xc3000f80,
        0xfe8ff3fb,
        0x40190360,
        0xf9ff8000,
        0x8034022f,
        0xfb07d05f,
        0x04f07a01,
        0xfc99aa97,
        0x53c8b000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x70170370,
        0xfa0f8000,
        0x8034022f,
        0xfb07e05f,
        0x04f07a01,
        0xfc99aab7,
        0x53c8a000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x70170370,
        0xfa0f8000,
        0x8033022f,
        0xfb07e060,
        0x04f07a01,
        0xfc99aac7,
        0x52c89000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x70100370,
        0xfa0f8000,
        0x8032021f,
        0xfb07f060,
        0x04f07a01,
        0xfc99aad7,
        0x52c88000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x50120360,
        0xf9ff8000,
        0x803101ff,
        0xfb080060,
        0x04e07a01,
        0xfc99aad7,
        0x53c89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x400c0360,
        0xfa0f8100,
        0x802f01ef,
        0xfc080060,
        0x04d07a01,
        0xfc99aac7,
        0x54c89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x200a0340,
        0xfa1f8100,
        0x802e01df,
        0xfb081061,
        0x04d07a01,
        0xfc99aac7,
        0x54c88000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fa,
        0xe00b0320,
        0xfa0f8100,
        0x802e01df,
        0xfc081062,
        0x04e07a01,
        0xfc99aac7,
        0x54c89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fa,
        0xe00a0320,
        0xfa1f8100,
        0x802e01cf,
        0xfc082063,
        0x04e07a01,
        0xfc99aad7,
        0x54c88000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc7000f80,
        0xfe8ff3fa,
        0xf00a0330,
        0xfa1f8100,
        0x802e01cf,
        0xfc083064,
        0x04f07a01,
        0xfc99aae7,
        0x53c88000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc6000f80,
        0xfe8ff3fa,
        0xf00a0330,
        0xfa0f8100,
        0x802d01cf,
        0xfc085064,
        0x05007a01,
        0xfc99aad7,
        0x54c88000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc6000f80,
        0xfe8ff3fa,
        0xf0080330,
        0xfa0f8100,
        0x802e01df,
        0xfc086062,
        0x05007a01,
        0xfc99aac7,
        0x54c88000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x000c0330,
        0xfa0f8100,
        0x802d01df,
        0xfc087060,
        0x04f07a01,
        0xfc99aad7,
        0x54c88000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x000d0330,
        0xfa0f8100,
        0x802d01df,
        0xfc089060,
        0x05007a01,
        0xfc99aae7,
        0x53c88000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x000c0330,
        0xfa0f8100,
        0x802c01cf,
        0xfc08d060,
        0x05307a01,
        0xfc99ab07,
        0x51c88000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100d0340,
        0xfa0f8100,
        0x802c01cf,
        0xfc08d060,
        0x05307a01,
        0xfc99ab17,
        0x51c88000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100c0350,
        0xfa1f8100,
        0x802c01cf,
        0xfc08e060,
        0x05307a01,
        0xfc99ab27,
        0x50c88000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100c0350,
        0xfa1f8100,
        0x802c01cf,
        0xfc08e060,
        0x05207a01,
        0xfc99ab37,
        0x50c88000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100e0350,
        0xfa0f8100,
        0x802d01cf,
        0xfc08f060,
        0x05207a01,
        0xfc99ab37,
        0x4fc88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100b0340,
        0xfa0f8100,
        0x802d01df,
        0xfc090060,
        0x05207a01,
        0xfc99ab37,
        0x4fc88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x200d0350,
        0xfa0f8100,
        0x802d01cf,
        0xfc091060,
        0x05207a01,
        0xfc99ab47,
        0x4ec88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x200c0350,
        0xfa1f8100,
        0x802d01cf,
        0xfc093060,
        0x05207a01,
        0xfc99ab57,
        0x4ec87000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100d0340,
        0xfa1f8100,
        0x802e01cf,
        0xfc09405f,
        0x05207a01,
        0xfc99ab57,
        0x4ec87000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100e0340,
        0xfa0f8100,
        0x802e01cf,
        0xfc09505f,
        0x05307a01,
        0xfc99ab57,
        0x4ec87000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x200d0350,
        0xfa1f8100,
        0x802e01cf,
        0xfc09505f,
        0x05307a01,
        0xfc99ab57,
        0x4ec87000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x100a0350,
        0xfa1f8100,
        0x802f01cf,
        0xfc095060,
        0x05307a01,
        0xfc99ab47,
        0x4ec87000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3be00004,
        0x2000000f,
        0xc7000f80,
        0xfe8ff3fb,
        0x000d0340,
        0xfa0f8100,
        0x802f01df,
        0xfc095060,
        0x05407a01,
        0xfc99ab27,
        0x4ec88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x4000000f,
        0xc9000f80,
        0xfe8ff3fb,
        0x10090340,
        0xfa1f8100,
        0x802f01ef,
        0xfc095060,
        0x05407a01,
        0xfc99ab17,
        0x4ec87000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc9000f80,
        0xfe8ff3fb,
        0x00090330,
        0xfa1f8100,
        0x802f01ff,
        0xfc09305f,
        0x05407a01,
        0xfc99aaf7,
        0x4fc88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc8000f80,
        0xfe8ff3fa,
        0xd00c0320,
        0xfa1f8100,
        0x802f020f,
        0xfc09305f,
        0x05307a01,
        0xfc99aab7,
        0x50c8b000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc8000f81,
        0xfe8ff3fa,
        0xc0080310,
        0xfa1f8100,
        0x8030021f,
        0xfc09305f,
        0x05307a01,
        0xfc99aaa7,
        0x50c8b000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc8000f80,
        0xfe8ff3fa,
        0xe0090330,
        0xfa1f8100,
        0x8030021f,
        0xfc09205f,
        0x05307a01,
        0xfc99aab7,
        0x50c8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc8000f80,
        0xfe8ff3fb,
        0x00080330,
        0xfa2f8100,
        0x8030021f,
        0xfc09105f,
        0x05307a01,
        0xfc99aab7,
        0x50c8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc7000f80,
        0xfe8ff3fa,
        0xe00b0320,
        0xfa3f8100,
        0x8030021f,
        0xfc09105f,
        0x05307a01,
        0xfc99aab7,
        0x50c8b000,
        0xd5d00000,
        0x0229000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xd00a0320,
        0xfa3f8100,
        0x8030021f,
        0xfc09105f,
        0x05207a01,
        0xfc99aab7,
        0x50c8b000,
        0xd5d00000,
        0x0229000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xd00c0320,
        0xfa3f8100,
        0x8030022f,
        0xfc09105f,
        0x05207a01,
        0xfc99aab7,
        0x50c8b000,
        0xd5d00000,
        0x0229000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xd00c0320,
        0xfa3f8100,
        0x8031022f,
        0xfc09105f,
        0x05207a01,
        0xfc99aab7,
        0x4fc8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc7000f80,
        0xfe8ff3fa,
        0xe00b0320,
        0xfa3f8100,
        0x8031022f,
        0xfc09205f,
        0x05207a01,
        0xfc99aab7,
        0x4fc8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xf00c0320,
        0xfa3f8100,
        0x8030021f,
        0xfc09205f,
        0x05307a01,
        0xfc99aac7,
        0x4fc8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xe00b0320,
        0xfa3f8100,
        0x8030021f,
        0xfc09205f,
        0x05307a01,
        0xfc99aad7,
        0x4ec8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xc8000f80,
        0xfe8ff3fa,
        0xd00a0320,
        0xfa2f8100,
        0x8030020f,
        0xfc092060,
        0x05307a01,
        0xfc99aad7,
        0x4fc8a000,
        0xd5d00000,
        0x022b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xca000f80,
        0xfe7ff3fa,
        0xe0060320,
        0xfa1f8100,
        0x802f01ff,
        0xfc092060,
        0x05307a01,
        0xfc99aad7,
        0x4fc8a000,
        0xd5d00000,
        0x022b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x3000000f,
        0xca000f80,
        0xfe7ff3fa,
        0xc0070310,
        0xfa1f8100,
        0x803001ff,
        0xfc09105f,
        0x05407a01,
        0xfc99aac7,
        0x4fc8a000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x3000000f,
        0xc9000f80,
        0xfe7ff3fa,
        0xa0070300,
        0xfa1f8100,
        0x803001ff,
        0xfc09105f,
        0x05407a01,
        0xfc99aab7,
        0x50c8a000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3be00004,
        0x3000000f,
        0xca000f80,
        0xfe7ff3fa,
        0xb0060310,
        0xfa1f8100,
        0x8030020f,
        0xfc09105f,
        0x05407a01,
        0xfc99aac7,
        0x50c89000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xca000f80,
        0xfe7ff3fa,
        0xc0070320,
        0xfa1f8100,
        0x8030020f,
        0xfc092060,
        0x05407a01,
        0xfc99aac7,
        0x4fc89000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x2000000f,
        0xc9000f80,
        0xfe8ff3fa,
        0xc0060320,
        0xf9ff8100,
        0x8032021f,
        0xfc091060,
        0x05507a01,
        0xfc99aac7,
        0x4fc8a000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc7000f80,
        0xfe8ff3fb,
        0x00070340,
        0xfa8f7e00,
        0x8036025f,
        0xfa092060,
        0x05507a01,
        0xfc99aac7,
        0x4fc89000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe4,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x50070380};

void ReadAnimationSet(Animation *animations, int numberAnimations, unsigned long animationTable, int numParts)
{
    //&_animation_dataSegmentRomStart;
    //&_animation_tableSegmentRomStart; //0x124AC0;

    animations.clear();

    for (int animationNumber = 0; animationNumber < numberAnimations; animationNumber++)
    {
        int animationOffset = &animationTable + (animationNumber * 4);
        AnimationHeader animation;
        AnimationHeader animationHeaderTemp;

        animation.numframes = numParts;
        animation.motion.clear();

        animationHeaderTemp.motion        = &_animation_tableSegmentRomStart + *(&_animation_dataSegmentRomStart + animationOffset + 0); //0x124AC0 AKA &ANIM_DATA_empty[] + ANIM_ENTRY_Idle.motion
        animationHeaderTemp.numframes     = &_animation_dataSegmentRomStart + animationOffset + 4;
        animationHeaderTemp.rotbits       = &_animation_dataSegmentRomStart + animationOffset + 6;
        animationHeaderTemp.flags         = &_animation_dataSegmentRomStart + animationOffset + 7;
        animationHeaderTemp.bitsrel       = &_animation_dataSegmentRomStart + *(&_animation_dataSegmentRomStart + animationOffset + 8);
        animationHeaderTemp.bitssizerel   = &_animation_dataSegmentRomStart + animationOffset + 0xC;
        animationHeaderTemp.bitssize      = &_animation_dataSegmentRomStart + animationOffset + 0xE;
        animationHeaderTemp.bitsmotionrel = &_animation_dataSegmentRomStart + *(&_animation_dataSegmentRomStart + animationOffset + 0x10);

        for (int r = 0; r < 4; r++)
        {
            animation.bitsrel[r].start            = ([animationHeaderTemp.bitsrel + (0x6 * r)]);
            animation.bitsrel[r].num              = [animationHeaderTemp.bitsrel + (0x6 * r) + 2];
            animation.bitsrel[r].offset           = ([animationHeaderTemp.bitsrel + (0x6 * r + 4)]);
        }

        animation.flags                      = animationHeaderTemp.flags;
        animation.rotbits = animationHeaderTemp.rotbits;
        animation.bitssize      = animationHeaderTemp.bitssize;
        animation.bitssizerel                = animationHeaderTemp.bitssizerel;

        animation.motion.clear();

        for (int keyframeIndex = 0; keyframeIndex < animationHeaderTemp.numframes; keyframeIndex++) //eg idle is 0 to 163, bitssizerel = 0, bitsise = 544, robits = 12, start = 0, num = 6
        {
            AnimationKeyframe keyframe;
            unsigned long     transRotYROMOffset = animationHeaderTemp.bitsmotionrel; //eg idle = 0x18

            unsigned short    valueRead   = GetBitsFromIndex(keyframeIndex, [transRotYROMOffset], animationHeaderTemp.bitssizerel, animation.animationBitsDesc[0].start, animation.animationBitsDesc[0].num);
            keyframe.keyframeTranslationX = SignExtend(animation.animationBitsDesc[0].num, valueRead) + (signed short)animation.animationBitsDesc[0].offset;

            valueRead                     = GetBitsFromIndex(keyframeIndex, [transRotYROMOffset], animationHeaderTemp.bitssizerel, animation.animationBitsDesc[1].start, animation.animationBitsDesc[1].num);
            keyframe.keyframeTranslationY = SignExtend(animation.animationBitsDesc[1].num, valueRead) + (signed short)animation.animationBitsDesc[1].offset;

            valueRead                     = GetBitsFromIndex(keyframeIndex, [transRotYROMOffset], animationHeaderTemp.bitssizerel, animation.animationBitsDesc[2].start, animation.animationBitsDesc[2].num);
            keyframe.keyframeTranslationZ = SignExtend(animation.animationBitsDesc[2].num, valueRead) + (signed short)animation.animationBitsDesc[2].offset;

            valueRead                  = GetBitsFromIndex(keyframeIndex, [transRotYROMOffset], animationHeaderTemp.bitssizerel, animation.animationBitsDesc[3].start, animation.animationBitsDesc[3].num);
            unsigned short valueRot    = SignExtend(animation.animationBitsDesc[3].num, valueRead) + (unsigned short)animation.animationBitsDesc[3].offset;
            keyframe.keyframeYRotation = D3DXToDegree((valueRot * TWOPI) / 65536.0f);

            unsigned long motion = animationHeaderTemp.motion + (animationHeaderTemp.bitssize >> 3) * keyframeIndex;

            for (int x = 0; x < numParts; x++)
            {
                unsigned long xrotMapOffset1 = GetBitsFromIndex(x * 3, [motion], animationHeaderTemp.rotbits, 0, animationHeaderTemp.rotbits) << 4;
                float         xcoordRot      = (xrotMapOffset1 * TWOPI) / 65536.0f;
                keyframe.partRotations[x].x  = D3DXToDegree(xcoordRot);

                unsigned long yrotMapOffset1 = GetBitsFromIndex(x * 3, [motion], animationHeaderTemp.rotbits, animationHeaderTemp.rotbits, animationHeaderTemp.rotbits) << 4;
                float         ycoordRot      = (yrotMapOffset1 * TWOPI) / 65536.0f;
                keyframe.partRotations[x].y  = D3DXToDegree(ycoordRot);

                unsigned long zrotMapOffset1 = GetBitsFromIndex(x * 3, [motion], animationHeaderTemp.rotbits, animationHeaderTemp.rotbits * 2, animationHeaderTemp.rotbits) << 4;
                float         zcoordRot      = (zrotMapOffset1 * TWOPI) / 65536.0f;
                keyframe.partRotations[x].z  = D3DXToDegree(zcoordRot);
            }

            animation.motion.push_back(keyframe);
        }

        animations.push_back(animation);
    }
}
#    endif
#endif

#if 1

#    include "../include/CPPLib.h"
#    include "../src/bondaicommands.h" //make sure this is after constants
#    include "../src/bondconstants.h"
#    include "../src/game/chrai.h"
#    define IFNOT(COND) EVAL2(PUSH_ARGS(INC(GNUM), IF_##COND)) \
    _AI_IF
#    define _AI_IF(a)             a _AI_IF_ELSE
#    define _AI_IF_ELSE(a)        a
#    define _SWAPSTATEMENTS(A, B) B A
#    define ELSEIIF(COND)         IF_##COND
#    define GNUM                  0
        DO( //D O(GAILIST LOOP1)

            IFNOT(GUARD_HAS_STOPPED_MOVING(INCGNUM)) 
            (
                 /*ELSE*/ CONTINUE(GAILIST_LOOP1)
            )
            (
                LABEL(GAILIST_STOPPED_MOVING)
                IF_GUARD_SEES_BOND(INC(GNUM))
                /*ELSE*/ IF_GUARD_WAS_SHOT_OR_SEEN_WITHIN_LAST_10_SECS(GAILIST_DONE)
                /*ELSE*/ IF_GUARD_HEARD_BOND_WITHIN_LAST_10_SECS(GAILIST_DONE)
                /*ELSEIF*/ RANDOM_GENERATE_GREATER_THAN(1, GAILIST_NEXT) // 1/255 chance of playing idle animation
                /*ELSE*/
                    SETRETURNAILIST(GAILIST_ID_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
                    JUMP(CHR_SELF, GAILIST_ID_IDLE_RAND_ANIM_SUBROUTINE) // play idle animation and return to list
                /*ENDIF*/
            )
            LABEL(GAILIST_NEXT)
        )
#endif

/* The circumference of a circle with diameter 1, PI.*/
#define M_PI_F       3.1415927f
/* The circumference of a circle with diameter 1, PI.*/
#define M_MINUS_PI_F -3.1415927f

/* The circumference of a circle with radius 1, PI*2.*/
#define M_TAU              6.28318530717958647692
/* The circumference of a circle with radius 1, PI*2.*/
#define M_TAU_F            6.2831855f
// Converts radians to degrees.
#define DEG2BYTE(DEG)      (char)(256.0f / 360.0f * (DEG))
#define RAD2BYTE(RAD)      (char)(256.0f / M_TAU_F * (RAD))
#define DegToRad(DEG)      (float)((DEG)*M_TAU / 360.0)
#define RadToDeg(RAD)      (float)((RAD) / M_TAU_F * 360.0f)
#define ByteToRadian(Byte) ((Byte * M_TAU_F) * (1.0f / 256.0f))

float M_45_DEG_IN_RAD  = 0.7853982f;
float M45              = DegToRad(45);
float M_90_DEG_IN_RAD  = 1.5707964f;
float M90              = DegToRad(90);
float M_100_DEG_IN_RAD = 1.7453293f;
float M100             = DegToRad(100);
float M_110_DEG_IN_RAD = 1.9198622f;
float M110             = DegToRad(110);
float M_135_DEG_IN_RAD = 2.3561945f;
float M135             = DegToRad(135);
float M_225_DEG_IN_RAD = 3.926991f;
float M225             = DegToRad(225.00001);
float M_250_DEG_IN_RAD = 4.363323f;
float M250             = DegToRad(250);
float M_260_DEG_IN_RAD = 4.537856f;
float M260             = DegToRad(260);
float M_270_DEG_IN_RAD = 4.712389f;
float M270             = DegToRad(270);
float M_315_DEG_IN_RAD = 5.4977875f;
float M315             = DegToRad(315.00001);

#define TARGET_N64
#include <PR/ultratypes.h>
#include <PR/os.h>
#include <PR/r4300.h>
u16 * g_DebugOutputVideoBuffer1 = NULL;
u16 * g_DebugOutputVideoBuffer2 = NULL;

void  deboutSetBuffers(u16 *buffer1, u16 *buffer2)
{
    g_DebugOutputVideoBuffer1 = (void*)K0_TO_K1(buffer1);
    g_DebugOutputVideoBuffer2 = (void*)K0_TO_K1(buffer2);
}
void deboutSetBuffers2(u16 *buffer1, u16 *buffer2)
{
    g_DebugOutputVideoBuffer1 = OS_PHYSICAL_TO_K1(buffer1);
    g_DebugOutputVideoBuffer2 = OS_PHYSICAL_TO_K1(buffer2);
}


