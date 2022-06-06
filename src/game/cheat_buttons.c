#include <os_extension.h>
#include <ultra64.h>
#include <bondgame.h>
#include <bondconstants.h>
#include <joy.h>
#include <music.h>
#include <snd.h>
#include "bondinv.h"
#include "bondview.h"
#include "cheat_buttons.h"
#include "chr.h"
#include "debugmenu_handler.h"
#include "file2.h"
#include "front.h"
#include "gun.h"
#include "lvl_text.h"
#include "objecthandler.h"
#include "player.h"
#include "player_2.h"
//#include "chraicommands.h" /* needed for ai list commands, remove when moving global ai lists to chraicommands/chrai */
// bss

// This shows up a lot but not quite sure what it represents.
#define CHEAT_20    20



u8 g_CheatPlayerTextRelated[CHEAT_INVALID + 1];

#pragma region ButtonCodes

//D:8003F430
u16 mBtnCheatExtraMPChars[] = {
    L_TRIG | R_TRIG | L_CBUTTONS  , 
    L_TRIG |          U_CBUTTONS ,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG |          R_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG |          U_CBUTTONS ,
    L_TRIG | R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG |          D_JPAD
};

//D:8003F444
u16 mBtnCheatInvincibility[] = {
    L_TRIG |          D_JPAD,
             R_TRIG | R_CBUTTONS ,
             R_TRIG | U_CBUTTONS ,
    L_TRIG |          R_JPAD,
    L_TRIG |          D_CBUTTONS ,
             R_TRIG | U_CBUTTONS ,
    L_TRIG |          R_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG |          L_JPAD,
    L_TRIG | R_TRIG | R_CBUTTONS  
};

//D:8003F458
u16 mBtnCheatAllGuns[] = {
    L_TRIG | R_TRIG | D_JPAD,
    L_TRIG |          L_CBUTTONS ,
    L_TRIG |          R_CBUTTONS ,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG |          D_JPAD,
    L_TRIG |          D_CBUTTONS ,
             R_TRIG | L_CBUTTONS ,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
             R_TRIG | U_JPAD,
    L_TRIG |          L_CBUTTONS 

};
//D:8003F46C
u16 mBtnCheatMaxAmmo[] = {
    L_TRIG | R_TRIG | R_CBUTTONS  ,
             R_TRIG | U_JPAD,
             R_TRIG | D_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
    L_TRIG | R_TRIG | L_JPAD,
             R_TRIG | D_JPAD,
             R_TRIG | U_JPAD,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
             R_TRIG | L_JPAD

};
//D:8003F480
u16 mBtnCheatInvalid[] = {
    L_TRIG |          U_JPAD,
             R_TRIG | R_CBUTTONS ,
             R_TRIG | D_CBUTTONS ,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | R_JPAD,
             R_TRIG | D_JPAD,
             R_TRIG | U_CBUTTONS ,
             R_TRIG | R_CBUTTONS ,
    L_TRIG | R_TRIG | D_JPAD

};
//D:8003F494
u16 mBtnCheatDeactivateInvincibilityMulti[] = {
             R_TRIG | R_JPAD,
    L_TRIG |          L_JPAD,
    L_TRIG |          L_JPAD,
             R_TRIG | U_JPAD,
    L_TRIG |          D_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          L_CBUTTONS ,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
    L_TRIG |          D_JPAD,
    L_TRIG |          U_CBUTTONS 
};
//D:8003F4A8
u16 mBtnCheatLineMode[] = {
             R_TRIG | D_CBUTTONS ,
    L_TRIG | R_TRIG | D_JPAD,
    L_TRIG |          R_JPAD,
             R_TRIG | U_CBUTTONS ,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
             R_TRIG | U_JPAD,
    L_TRIG |          D_JPAD,
    L_TRIG |          R_JPAD,
             R_TRIG | L_CBUTTONS ,
             R_TRIG | U_CBUTTONS 

};
//D:8003F4BC
u16 mBtnCheatInvisibility[] = {
             R_TRIG | L_CBUTTONS ,
    L_TRIG | R_TRIG | U_CBUTTONS  ,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | U_JPAD,
             R_TRIG | U_JPAD,
    L_TRIG |          L_CBUTTONS ,
             R_TRIG | U_CBUTTONS ,
    L_TRIG |          D_CBUTTONS ,
    L_TRIG | R_TRIG | L_JPAD,
             R_TRIG | R_JPAD
};
//D:8003F4D0
u16 mBtnCheatInvisibilityMulti[] = {
    L_TRIG |          U_CBUTTONS ,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
             R_TRIG | U_JPAD,
    L_TRIG |          R_CBUTTONS ,
             R_TRIG | L_CBUTTONS ,
    L_TRIG |          R_JPAD,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG |          R_CBUTTONS ,
    L_TRIG |          U_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  
};
//D:8003F4E4
u16 mBtnCheatDam[] = {
    L_TRIG | R_TRIG | U_CBUTTONS  ,
             R_TRIG | L_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          D_CBUTTONS ,
             R_TRIG | U_JPAD,
    L_TRIG |          D_JPAD,
             R_TRIG | R_CBUTTONS ,
    L_TRIG |          R_JPAD,
    L_TRIG | R_TRIG | R_JPAD,
             R_TRIG | D_CBUTTONS 
};
//D:8003F4F8
u16 mBtnCheatFacility[] = {
    L_TRIG | R_TRIG | U_CBUTTONS  ,
             R_TRIG | L_CBUTTONS ,
    L_TRIG |          L_JPAD,
             R_TRIG | U_CBUTTONS ,
    L_TRIG |          L_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          R_CBUTTONS ,
             R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | U_CBUTTONS  ,
    L_TRIG |          R_JPAD
};
//D:8003F50C
u16 mBtnCheatRunway[] = {
    L_TRIG | R_TRIG | L_JPAD,
             R_TRIG | L_JPAD,
    L_TRIG |          U_CBUTTONS ,
    L_TRIG |          L_JPAD,
             R_TRIG | U_CBUTTONS ,
             R_TRIG | D_CBUTTONS ,
             R_TRIG | R_CBUTTONS ,
             R_TRIG | R_JPAD,
    L_TRIG |          D_JPAD,
             R_TRIG | L_CBUTTONS 
};
//D:8003F520
u16 mBtnCheatSurface[] = {
             R_TRIG | L_CBUTTONS ,
    L_TRIG | R_TRIG | U_CBUTTONS  ,
    L_TRIG |          L_JPAD,
             R_TRIG | U_JPAD,
             R_TRIG | L_JPAD,
    L_TRIG |          U_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          R_JPAD,
    L_TRIG |          R_CBUTTONS ,
    L_TRIG | R_TRIG | D_JPAD,
};
//D:8003F534
u16 mBtnCheatBunker[] = {
    L_TRIG |          D_CBUTTONS ,
             R_TRIG | R_JPAD,
    L_TRIG |          R_CBUTTONS ,
             R_TRIG | L_CBUTTONS ,
    L_TRIG |          D_CBUTTONS ,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG |          R_CBUTTONS ,
    L_TRIG | R_TRIG | U_JPAD,
             R_TRIG | R_CBUTTONS ,
    L_TRIG |          U_JPAD,
};
//D:8003F548
u16 mBtnCheatSilo[] = {
    L_TRIG |          U_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          L_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG |          L_CBUTTONS ,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
    L_TRIG |          U_CBUTTONS ,
             R_TRIG | R_JPAD,
             R_TRIG | R_JPAD,
             R_TRIG | R_CBUTTONS 
};
//D:8003F55C
u16 mBtnCheatFrigate[] = {
             R_TRIG | U_CBUTTONS ,
    L_TRIG |          D_JPAD,
             R_TRIG | R_CBUTTONS ,
    L_TRIG |          L_JPAD,
    L_TRIG | R_TRIG | U_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
             R_TRIG | R_CBUTTONS ,
             R_TRIG | U_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
             R_TRIG | U_JPAD
};
//D:8003F570
u16 mBtnCheatSurface2[] = {
    L_TRIG |          D_CBUTTONS ,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
             R_TRIG | R_CBUTTONS ,
             R_TRIG | U_CBUTTONS ,
             R_TRIG | L_CBUTTONS ,
    L_TRIG |          R_JPAD,
    L_TRIG | R_TRIG | U_CBUTTONS  ,
    L_TRIG |          U_CBUTTONS ,
    L_TRIG | R_TRIG | D_JPAD,
    L_TRIG |          R_CBUTTONS 
};
//D:8003F584
u16 mBtnCheatBunker2[] = {
    L_TRIG |          D_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG | R_TRIG | U_CBUTTONS  ,
    L_TRIG |          L_JPAD,
    L_TRIG | R_TRIG | R_JPAD,
    L_TRIG |          L_CBUTTONS ,
             R_TRIG | R_JPAD,
    L_TRIG |          U_CBUTTONS ,
    L_TRIG |          L_JPAD,
    L_TRIG |          D_CBUTTONS 
};
//D:8003F598
u16 mBtnCheatStatue[] = {
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG |          R_JPAD,
    L_TRIG | R_TRIG | L_JPAD,
             R_TRIG | L_JPAD,
             R_TRIG | R_CBUTTONS ,
    L_TRIG | R_TRIG | L_JPAD,
             R_TRIG | U_CBUTTONS ,
             R_TRIG | D_CBUTTONS ,
             R_TRIG | R_JPAD
};
//D:8003F5AC
u16 mBtnCheatArchives[] = {
             R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | U_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
             R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
    L_TRIG |          L_JPAD,
    L_TRIG | R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG |          U_JPAD,
             R_TRIG | D_CBUTTONS 
};
//D:8003F5C0
u16 mBtnCheatStreets[] = {
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG |          R_CBUTTONS ,
    L_TRIG |          U_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
             R_TRIG | R_CBUTTONS ,
             R_TRIG | D_CBUTTONS ,
             R_TRIG | L_JPAD,
             R_TRIG | D_CBUTTONS ,
             R_TRIG | U_CBUTTONS ,
    L_TRIG |          D_JPAD
};
//D:8003F5D4
u16 mBtnCheatDepot[] = {
    L_TRIG |          D_JPAD,
    L_TRIG |          D_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          R_CBUTTONS ,
    L_TRIG | R_TRIG | R_JPAD,
             R_TRIG | L_CBUTTONS ,
    L_TRIG |          D_JPAD,
    L_TRIG |          L_CBUTTONS ,
    L_TRIG |          R_CBUTTONS ,
    L_TRIG |          U_JPAD
};
//D:8003F5E8
u16 mBtnCheatTrain[] = {
             R_TRIG | L_JPAD,
             R_TRIG | D_CBUTTONS ,
             R_TRIG | R_CBUTTONS ,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG |          R_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          L_JPAD,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG |          U_JPAD,
    L_TRIG |          U_CBUTTONS 
};
//D:8003F5FC
u16 mBtnCheatJungle[] = {
             R_TRIG | D_CBUTTONS ,
             R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | U_JPAD,
             R_TRIG | R_JPAD,
             R_TRIG | D_JPAD,
             R_TRIG | D_JPAD,
             R_TRIG | U_JPAD,
             R_TRIG | L_CBUTTONS ,
             R_TRIG | U_CBUTTONS ,
    L_TRIG | R_TRIG | L_JPAD
};
//D:8003F610
u16 mBtnCheatControl[] = {
    L_TRIG |          D_CBUTTONS ,
             R_TRIG | D_JPAD,
    L_TRIG |          R_JPAD,
             R_TRIG | R_CBUTTONS ,
             R_TRIG | D_CBUTTONS ,
             R_TRIG | L_JPAD,
             R_TRIG | L_JPAD,
             R_TRIG | U_CBUTTONS ,
             R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | U_CBUTTONS  
};
//D:8003F624
u16 mBtnCheatCaverns[] = {
    L_TRIG |          D_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG | R_TRIG | U_JPAD,
    L_TRIG |          R_JPAD,
             R_TRIG | U_CBUTTONS ,
             R_TRIG | L_CBUTTONS ,
             R_TRIG | U_JPAD,
    L_TRIG |          L_CBUTTONS ,
    L_TRIG |          U_JPAD,
             R_TRIG | L_CBUTTONS 
};
//D:8003F638
u16 mBtnCheatCradle[] = {
    L_TRIG | R_TRIG | U_CBUTTONS  ,
    L_TRIG |          L_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG |          D_JPAD,
    L_TRIG |          U_CBUTTONS ,
    L_TRIG |          D_JPAD,
             R_TRIG | R_JPAD,
             R_TRIG | U_CBUTTONS ,
    L_TRIG |          L_CBUTTONS ,
             R_TRIG | R_JPAD
};
//D:8003F64C
u16 mBtnCheatAztek[] = {
             R_TRIG | D_CBUTTONS ,
             R_TRIG | L_JPAD,
    L_TRIG |          R_JPAD,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
    L_TRIG |          D_JPAD,
    L_TRIG | R_TRIG | U_CBUTTONS  ,
    L_TRIG |          L_JPAD,
    L_TRIG | R_TRIG | U_CBUTTONS  ,
    L_TRIG | R_TRIG | R_JPAD,
    L_TRIG |          L_CBUTTONS 
};
//D:8003F660
u16 mBtnCheatEgypt[] = {
    L_TRIG | R_TRIG | U_JPAD,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
    L_TRIG |          D_JPAD,
             R_TRIG | R_JPAD,
             R_TRIG | U_JPAD,
    L_TRIG |          D_JPAD,
    L_TRIG |          L_JPAD,
    L_TRIG |          R_CBUTTONS ,
    L_TRIG | R_TRIG | R_CBUTTONS  ,
    L_TRIG |          L_JPAD,
    L_TRIG | R_TRIG | A_BUTTON,
    L_TRIG | R_TRIG | B_BUTTON,
    L_TRIG | R_TRIG | A_BUTTON,
    L_TRIG | R_TRIG | B_BUTTON
};
//D:8003F67C
u16 mBtnCheatPaintballMod[] = {
    L_TRIG |          U_JPAD,
                      U_CBUTTONS,
             R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG |          U_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          D_CBUTTONS ,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG | R_TRIG | U_JPAD,
    L_TRIG |          D_CBUTTONS 
};
//D:8003F690
u16 mBtnCheatInvincible2[] = {
             R_TRIG | L_JPAD,
    L_TRIG |          D_JPAD,
                      L_JPAD,
                      U_JPAD,
                      D_JPAD,
             R_TRIG | L_CBUTTONS ,
    L_TRIG |          L_CBUTTONS ,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | R_JPAD,
    L_TRIG |          L_CBUTTONS 
};
//D:8003F6A4
u16 mBtnCheatDKMode[] = {
    L_TRIG | R_TRIG | U_JPAD,
                      R_CBUTTONS,
             R_TRIG | L_JPAD,
             R_TRIG | U_JPAD,
                      U_JPAD,
             R_TRIG | R_JPAD,
                      U_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG | R_TRIG | D_JPAD,
    L_TRIG | R_TRIG | L_CBUTTONS  
};
//D:8003F6B8
u16 mBtnCheat2xGL[] = {
             R_TRIG | D_JPAD,
             R_TRIG | U_JPAD,
                      R_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG |          R_JPAD,
             R_TRIG | L_JPAD,
                      L_JPAD,
                      D_JPAD,
                      U_JPAD,
             R_TRIG | D_CBUTTONS 
};
//D:8003F6CC
u16 mBtnCheat2xRL[] = {
             R_TRIG | R_JPAD,
    L_TRIG |          U_JPAD,
                      D_JPAD,
                      D_JPAD,
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          L_JPAD,
    L_TRIG |          L_CBUTTONS ,
             R_TRIG | U_JPAD,
             R_TRIG | D_JPAD,
             R_TRIG | L_CBUTTONS 
};
//D:8003F6E0
u16 mBtnCheatTurboMode[] = {
    L_TRIG |          D_JPAD,
    L_TRIG |          D_CBUTTONS ,
    L_TRIG | R_TRIG | U_JPAD,
             R_TRIG | D_CBUTTONS ,
                      L_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG |          D_CBUTTONS ,
                      U_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG |          R_JPAD
};
//D:8003F6F4
u16 mBtnCheatNoRadar[] = {
             R_TRIG | U_JPAD,
                      D_CBUTTONS,
                      L_CBUTTONS,
                      U_CBUTTONS,
    L_TRIG |          D_JPAD,
             R_TRIG | U_JPAD,
                      L_CBUTTONS,
                      R_JPAD,
             R_TRIG | L_JPAD,
             R_TRIG | R_JPAD
};
//D:8003F708
u16 mBtnCheatTinyBond[] = {
    L_TRIG | R_TRIG | D_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG |          D_CBUTTONS ,
                      L_JPAD,
             R_TRIG | L_CBUTTONS ,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
                      R_JPAD,
                      D_JPAD,
             R_TRIG | D_CBUTTONS ,
             R_TRIG | R_JPAD
};
//D:8003F71C
u16 mBtnCheat2xTKnives[] = {
             R_TRIG | L_CBUTTONS ,
    L_TRIG |          L_JPAD,
                      U_JPAD,
    L_TRIG | R_TRIG | R_JPAD,
                      R_JPAD,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
             R_TRIG | D_JPAD,
             R_TRIG | L_JPAD,
             R_TRIG | L_CBUTTONS 
};
//D:8003F730
u16 mBtnCheatFastAnimation[] = {
    L_TRIG |          D_CBUTTONS ,
    L_TRIG |          L_CBUTTONS ,
                      D_CBUTTONS,
                      R_CBUTTONS,
                      L_CBUTTONS,
    L_TRIG | R_TRIG | R_JPAD,
                      R_CBUTTONS,
    L_TRIG | R_TRIG | U_JPAD,
             R_TRIG | L_CBUTTONS ,
    L_TRIG |          L_JPAD
};
//D:8003F744
u16 mBtnCheatBondInvisible[] = {
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG |          L_CBUTTONS ,
             R_TRIG | L_CBUTTONS ,
             R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG |          R_JPAD,
                      L_JPAD,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG |          D_JPAD
};
//D:8003F758
u16 mBtnCheatEnemyRL[] = {
    L_TRIG | R_TRIG | D_CBUTTONS  ,
                      L_CBUTTONS,
             R_TRIG | D_CBUTTONS ,
                      D_CBUTTONS,
                      D_CBUTTONS,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG | R_TRIG | U_JPAD,
                      D_CBUTTONS,
             R_TRIG | U_JPAD,
    L_TRIG |          U_JPAD
};
//D:8003F76C
u16 mBtnCheatSlowAnimation[] = {
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | D_JPAD,
    L_TRIG | R_TRIG | L_JPAD,
                      R_CBUTTONS,
    L_TRIG | R_TRIG | D_JPAD,
    L_TRIG | R_TRIG | D_JPAD,
    L_TRIG |          D_JPAD,
                      L_CBUTTONS,
                      U_CBUTTONS
};
//D:8003F780
u16 mBtnCheatSilverPPK[] = {
    L_TRIG |          L_JPAD,
    L_TRIG | R_TRIG | U_JPAD,
    L_TRIG |          R_JPAD,
    L_TRIG | R_TRIG | U_JPAD,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | D_JPAD,
                      D_CBUTTONS,
    L_TRIG | R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | L_JPAD
};
//D:8003F794
u16 mBtnCheat2xHKnives[] = {
             R_TRIG | D_CBUTTONS ,
    L_TRIG |          R_JPAD,
             R_TRIG | L_CBUTTONS ,
             R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | U_JPAD,
    L_TRIG |          D_JPAD,
             R_TRIG | L_JPAD,
    L_TRIG |          R_JPAD,
    L_TRIG |          L_CBUTTONS 
};
//D:8003F7A8
u16 mBtnCheatInfinitAmmo[] = {
    L_TRIG |          L_CBUTTONS ,
    L_TRIG | R_TRIG | R_JPAD,
                      R_CBUTTONS,
                      L_CBUTTONS,
             R_TRIG | L_JPAD,
    L_TRIG |          D_CBUTTONS ,
    L_TRIG | R_TRIG | L_JPAD,
    L_TRIG | R_TRIG | D_CBUTTONS  ,
    L_TRIG |          U_JPAD,
                      R_CBUTTONS
};
//D:8003F7BC
u16 mBtnCheat2xFNP90[] = {
                      U_JPAD,
                      R_JPAD,
    L_TRIG |          L_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG |          U_JPAD,
    L_TRIG |          L_CBUTTONS ,
    L_TRIG |          L_JPAD,
                      R_CBUTTONS,
                      U_CBUTTONS,
    L_TRIG | R_TRIG | D_JPAD
};
//D:8003F7D0
u16 mBtnCheatGoldPPK[] = {
    L_TRIG | R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | D_JPAD,
    L_TRIG |          U_JPAD,
    L_TRIG | R_TRIG | D_JPAD,
                      U_CBUTTONS,
             R_TRIG | U_JPAD,
    L_TRIG | R_TRIG | R_JPAD,
    L_TRIG |          L_JPAD,
                      D_JPAD,
    L_TRIG |          D_CBUTTONS 
};
//D:8003F7E4
u16 mBtnCheat2xLaser[] = {
    L_TRIG |          R_JPAD,
    L_TRIG | R_TRIG | L_CBUTTONS  ,
    L_TRIG |          D_JPAD,
             R_TRIG | L_JPAD,
             R_TRIG | D_JPAD,
    L_TRIG |          R_JPAD,
                      U_CBUTTONS,
                      R_JPAD,
             R_TRIG | R_JPAD,
    L_TRIG | R_TRIG | U_JPAD
};
//D:8003F7F8
u16 mBtnCheatUnlockAllGuns[] = {
                      D_JPAD,
                      L_JPAD,
                      U_CBUTTONS,
                      R_JPAD,
    L_TRIG |          D_JPAD,
    L_TRIG |          L_JPAD,
    L_TRIG |          U_JPAD,
                      L_CBUTTONS,
                      L_JPAD,
                      D_CBUTTONS
};
#pragma endregion

/**
 * Address 0x8003F80C.
 */
CheatInfo g_CheatInfo[] = {
    {          CHEAT_EXTRA_MP_CHARS,  0xA, 0, 0, mBtnCheatExtraMPChars,                       0, 0,  /* 0x31 */ CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_MENUS}, 
    {           CHEAT_INVINCIBILITY,  0xA, 0, 0, mBtnCheatInvincibility,       TEXT(LMISC,0x00), 0,  /* 0x06 */ CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME}, 
    {                 CHEAT_ALLGUNS,  0xA, 0, 0, mBtnCheatAllGuns,             TEXT(LMISC,0x01), 0,  /* 0x02 */ CHEAT_MASK_SPGAME}, 
    {                 CHEAT_MAXAMMO,  0xA, 0, 0, mBtnCheatMaxAmmo,                            0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {   CHEAT_DEBUG_RETURN_SAVED_RA,  0xA, 0, 0, mBtnCheatInvalid,                            0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {CHEAT_DEACTIVATE_INVINCIBILITY,  0xA, 0, 0, mBtnCheatDeactivateInvincibilityMulti,       0, 0,  /* 0x34 */ CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_MPGAME},
    {                CHEAT_LINEMODE,  0xA, 0, 0, mBtnCheatLineMode,            TEXT(LMISC,0x37), 0,  /* 0x66 */ CHEAT_MASK_TOGGLE | CHEAT_MASK_GLOBAL | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {               CHEAT_2X_HEALTH,    0, 0, 0,                0,                            0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {                CHEAT_2X_ARMOR,    0, 0, 0,                0,                            0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {            CHEAT_INVISIBILITY,  0xA, 0, 0, mBtnCheatInvisibility,        TEXT(LMISC,0x04), 0,  /* 0x62 */ CHEAT_MASK_TOGGLE | CHEAT_MASK_GLOBAL | CHEAT_MASK_SPGAME},
    {           CHEAT_INFINITE_AMMO,    0, 0, 0,                0,             TEXT(LMISC,0x06), 0,  /* 0x66 */ CHEAT_MASK_TOGGLE | CHEAT_MASK_GLOBAL | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {                 CHEAT_DK_MODE,    0, 0, 0,                0,             TEXT(LMISC,0x07), 0,  /* 0x26 */ CHEAT_MASK_GLOBAL | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {           CHEAT_EXTRA_WEAPONS,    0, 0, 0,                0,                            0, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {               CHEAT_TINY_BOND,    0, 0, 0,                0,             TEXT(LMISC,0x08), 0,  /* 0x02 */ CHEAT_MASK_SPGAME},
    {               CHEAT_PAINTBALL,    0, 0, 0,                0,             TEXT(LMISC,0x38), 0,  /* 0x66 */ CHEAT_MASK_TOGGLE | CHEAT_MASK_GLOBAL | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {              CHEAT_10X_HEALTH,    0, 0, 0,                0,                            0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {                  CHEAT_MAGNUM,    0, 0, 0,                0,             TEXT(LMISC,0x0A), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {                   CHEAT_LASER,    0, 0, 0,                0,             TEXT(LMISC,0x0B), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {              CHEAT_GOLDEN_GUN,    0, 0, 0,                0,             TEXT(LMISC,0x0C), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {              CHEAT_SILVER_PP7,    0, 0, 0,                0,             TEXT(LMISC,0x0D), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {                CHEAT_GOLD_PP7,    0, 0, 0,                0,             TEXT(LMISC,0x0E), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {         CHEAT_INVISIBILITY_MP,  0xA, 0, 0, mBtnCheatInvisibilityMulti,                  0, 0,  /* 0x12 */ CHEAT_MASK_MPGAME},
    {             CHEAT_NO_RADAR_MP,    0, 0, 0,                0,             TEXT(LMISC,0x43), 0,  /* 0x64 */ CHEAT_MASK_TOGGLE | CHEAT_MASK_GLOBAL | CHEAT_MASK_MPGAME},
    {              CHEAT_TURBO_MODE,    0, 0, 0,                0,             TEXT(LMISC,0x40), 0,  /* 0x66 */ CHEAT_MASK_TOGGLE | CHEAT_MASK_GLOBAL | CHEAT_MASK_MPGAME | CHEAT_MASK_SPGAME},
    {               CHEAT_DEBUG_POS,    0, 0, 0,                0,                            0, 0,  /* 0x20 */ CHEAT_MASK_GLOBAL},
    {          CHEAT_FAST_ANIMATION,    0, 0, 0,                0,             TEXT(LMISC,0x41), 0,  /* 0x72 */ CHEAT_MASK_TOGGLE | CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {          CHEAT_SLOW_ANIMATION,    0, 0, 0,                0,             TEXT(LMISC,0x42), 0,  /* 0x72 */ CHEAT_MASK_TOGGLE | CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {           CHEAT_ENEMY_ROCKETS,    0, 0, 0,                0,             TEXT(LMISC,0x39), 0,  /* 0x01 */ CHEAT_MASK_MENUS},
    {      CHEAT_2X_ROCKET_LAUNCHER,    0, 0, 0,                0,             TEXT(LMISC,0x3A), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {     CHEAT_2X_GRENADE_LAUNCHER,    0, 0, 0,                0,             TEXT(LMISC,0x3B), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {                CHEAT_2X_RCP90,    0, 0, 0,                0,             TEXT(LMISC,0x3C), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {       CHEAT_2X_THROWING_KNIFE,    0, 0, 0,                0,             TEXT(LMISC,0x3D), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {        CHEAT_2X_HUNTING_KNIFE,    0, 0, 0,                0,             TEXT(LMISC,0x3E), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},
    {                CHEAT_2X_LASER,    0, 0, 0,                0,             TEXT(LMISC,0x3F), 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_SPGAME},

    {        CHEAT_UNLOCK_PAINTBALL,  0xA, 0, 0, mBtnCheatPaintballMod,                       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {       CHEAT_UNLOCK_INVINCIBLE,  0xA, 0, 0, mBtnCheatInvincible2,                        0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {           CHEAT_UNLOCK_DKMODE,  0xA, 0, 0, mBtnCheatDKMode,                             0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {             CHEAT_UNLOCK_2XGL,  0xA, 0, 0, mBtnCheat2xGL,                               0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {             CHEAT_UNLOCK_2XRL,  0xA, 0, 0, mBtnCheat2xRL,                               0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {            CHEAT_UNLOCK_TURBO,  0xA, 0, 0, mBtnCheatTurboMode,                          0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {          CHEAT_UNLOCK_NORADAR,  0xA, 0, 0, mBtnCheatNoRadar,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {             CHEAT_UNLOCK_TINY,  0xA, 0, 0, mBtnCheatTinyBond,                           0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {         CHEAT_UNLOCK_2XTKNIFE,  0xA, 0, 0, mBtnCheat2xTKnives,                          0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {             CHEAT_UNLOCK_FAST,  0xA, 0, 0, mBtnCheatFastAnimation,                      0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {            CHEAT_UNLOCK_INVIS,  0xA, 0, 0, mBtnCheatBondInvisible,                      0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {          CHEAT_UNLOCK_ENEMYRL,  0xA, 0, 0, mBtnCheatEnemyRL,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {             CHEAT_UNLOCK_SLOW,  0xA, 0, 0, mBtnCheatSlowAnimation,                      0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {        CHEAT_UNLOCK_SILVERPPK,  0xA, 0, 0, mBtnCheatSilverPPK,                          0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {         CHEAT_UNLOCK_2XHKNIFE,  0xA, 0, 0, mBtnCheat2xHKnives,                          0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {          CHEAT_UNLOCK_INFAMMO,  0xA, 0, 0, mBtnCheatInfinitAmmo,                        0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {           CHEAT_UNLOCK_2XFNP0,  0xA, 0, 0, mBtnCheat2xFNP90,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {          CHEAT_UNLOCK_GOLDPPK,  0xA, 0, 0, mBtnCheatGoldPPK,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {          CHEAT_UNLOCK_2XLASER,  0xA, 0, 0, mBtnCheat2xLaser,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu
    {          CHEAT_UNLOCK_ALLGUNS,  0xA, 0, 0, mBtnCheatUnlockAllGuns,                      0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at cheat menu

    {              CHEAT_UNLOCK_DAM,  0xA, 0, 0, mBtnCheatDam,                                0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {         CHEAT_UNLOCK_FACILITY,  0xA, 0, 0, mBtnCheatFacility,                           0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {           CHEAT_UNLOCK_RUNWAY,  0xA, 0, 0, mBtnCheatRunway,                             0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {          CHEAT_UNLOCK_SURFACE,  0xA, 0, 0, mBtnCheatSurface,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {           CHEAT_UNLOCK_BUNKER,  0xA, 0, 0, mBtnCheatBunker,                             0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {             CHEAT_UNLOCK_SILO,  0xA, 0, 0, mBtnCheatSilo,                               0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {          CHEAT_UNLOCK_FRIGATE,  0xA, 0, 0, mBtnCheatFrigate,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {         CHEAT_UNLOCK_SURFACE2,  0xA, 0, 0, mBtnCheatSurface2,                           0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {          CHEAT_UNLOCK_BUNKER2,  0xA, 0, 0, mBtnCheatBunker2,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {           CHEAT_UNLOCK_STATUE,  0xA, 0, 0, mBtnCheatStatue,                             0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {         CHEAT_UNLOCK_ARCHIVES,  0xA, 0, 0, mBtnCheatArchives,                           0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {          CHEAT_UNLOCK_STREETS,  0xA, 0, 0, mBtnCheatStreets,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {            CHEAT_UNLOCK_DEPOT,  0xA, 0, 0, mBtnCheatDepot,                              0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {            CHEAT_UNLOCK_TRAIN,  0xA, 0, 0, mBtnCheatTrain,                              0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {           CHEAT_UNLOCK_JUNGLE,  0xA, 0, 0, mBtnCheatJungle,                             0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {          CHEAT_UNLOCK_CONTROL,  0xA, 0, 0, mBtnCheatControl,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {          CHEAT_UNLOCK_CAVERNS,  0xA, 0, 0, mBtnCheatCaverns,                            0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {           CHEAT_UNLOCK_CRADLE,  0xA, 0, 0, mBtnCheatCradle,                             0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {            CHEAT_UNLOCK_AZTEK,  0xA, 0, 0, mBtnCheatAztek,                              0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {            CHEAT_UNLOCK_EGYPT,  0xA, 0, 0, mBtnCheatEgypt,                              0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_MENUS}, //at mission select
    {0}
};



// rodata

// forward declarations
// Private Functions?

s32 cheatButtonCountBitsSet(u16 bits);
void cheatButtonActivateRelated(void);
void cheatButtonHandleCheatsTurnedOn(CHEAT_ID cheat);
void cheatButtonHandleCheatsTurnedOff(CHEAT_ID cheat_id);
bool cheatCheckIfMPCheat(CHEAT_ID cheat_id);
void cheatButtonSetDkMode(CHEAT_ID cheat_id);

// end forward declarations




/**
 * Address 0x7F091740.
 */
s32 cheatButtonCountBitsSet(u16 bits)
{
    s32 count;

    for (count = 0; (u32)bits != 0; bits >>= 1)
    {
        if (bits & 1)
        {
            count++;
        }
    }

    return count;
}





/**
 * Address 0x7F09177C.
 */
void cheatButtonActivateRelated(void)
{
    CheatInfo *info = &g_CheatInfo[0];
    s32 bitmask;
    s32 id_index;
    s32 find_index;
    bool isDone = FALSE;
    
    if (lvlGetCurrentStageToLoad() == LEVELID_TITLE)
    {
        bitmask = CHEAT_MASK_MENUS;
    }
    else
    {
        bitmask = (getPlayerCount() == 1) ? CHEAT_MASK_SPGAME : CHEAT_MASK_MPGAME;
    }

    for (; info->cheat_id != 0 && !isDone; info++)
    {
        if (info->count_of_something > 0)
        {
            if ((g_CurrentPlayer->can_display_cheat_text >= info->count_of_something) && ((info->maskfield & bitmask) != 0))
            {
                id_index = ((g_CurrentPlayer->something_with_cheat_text - info->count_of_something) + CHEAT_20) % CHEAT_20;

                find_index=0;
                for (; find_index < info->count_of_something; find_index++)
                {
                    if (g_CurrentPlayer->cheat_display_text_related[id_index] == info->cheatbuttons[find_index])
                    {
                        id_index = (s32) (id_index + 1) % CHEAT_20;
                        continue;
                    }

                    break;
                }

                if (find_index == info->count_of_something)
                {
                    g_CurrentPlayer->can_display_cheat_text = 0;

                    if (!cheatIsActive((s32) info->cheat_id) || ((info->maskfield & CHEAT_MASK_16) != 0))
                    {
                        cheatButtonHandleCheatsTurnedOn(info->cheat_id);
                    }
                    else
                    {
                        cheatButtonHandleCheatsTurnedOff(info->cheat_id);
                    }
                }
            }
        }
    }
}



/**
 * Address 0x7F09193C.
 */
void cheat_buttons_mp_related(void)
{
    u16 jgb;
    u16 jgbptf;
    u16 jgb_trig;

    jgb = joyGetButtons(get_cur_playernum(), ANY_BUTTON);
    jgbptf = joyGetButtonsPressedThisFrame(get_cur_playernum(), ANY_BUTTON);
    jgb_trig = (jgb & (L_TRIG | R_TRIG));
    jgb &= ~(jgb_trig);
    jgbptf &= ~(jgb_trig);
    
    
    if (jgbptf != 0)
    {       
        if ((cheatButtonCountBitsSet(jgbptf) == 1) && ((cheatButtonCountBitsSet(jgb) == 1)))
        {
            g_CurrentPlayer->cheat_display_text_related[g_CurrentPlayer->something_with_cheat_text] = jgbptf | jgb_trig;
            g_CurrentPlayer->something_with_cheat_text =  (g_CurrentPlayer->something_with_cheat_text + 1) % CHEAT_20;

            if ((s32) g_CurrentPlayer->can_display_cheat_text < CHEAT_20)
            {
                g_CurrentPlayer->can_display_cheat_text += 1;
            }
        } 
        else
        {
            g_CurrentPlayer->can_display_cheat_text = 0;
        }
    }
    
    cheatButtonActivateRelated();
}



/**
 * true if param is CHEAT_ENEMY_ROCKETS
 *
 * Address 7F091A5C.
 */
bool cheatIsEnemyRockets(CHEAT_ID id)
{
    if (id == CHEAT_ENEMY_ROCKETS) {
        return TRUE;
    }
    return FALSE;
}






/**
 * true if param is MP cheat
 * 
 * Address 0x7F091A78.
 */
bool cheatCheckIfMPCheat(CHEAT_ID cheat_id)
{
    if ((g_CheatInfo[cheat_id - 1].maskfield & CHEAT_MASK_MPGAME) == CHEAT_MASK_MPGAME)
    {
        return TRUE;
    }

    return FALSE;
}




/**
 * Address 0x7F091AAC.
 */
void cheatButtonTurnOnCheatForPlayers(CHEAT_ID cheatindex)
{
    u32 cheat_mask;
    s32 starting_player_number;
    s32 numplayers;
    s32 i;

    cheat_mask = g_CheatInfo[cheatindex - 1].maskfield;
    starting_player_number = get_cur_playernum();
    numplayers = getPlayerCount();

    if (numplayers == 1)
    {
        cheatButtonHandleCheatsTurnedOn(cheatindex);
    }
    else
    {
        if (cheat_mask & CHEAT_MASK_MPGAME)
        {
            if (cheat_mask & CHEAT_MASK_GLOBAL)
            {
                cheatButtonHandleCheatsTurnedOn(cheatindex);
            }
            else
            {
                for(i=0; i<numplayers; i++)
                {
                    set_cur_player(i);
                    cheatButtonHandleCheatsTurnedOn(cheatindex);
                }

                set_cur_player(starting_player_number);
            }
        }
    }

    return;
}



/**
 * Address 0x7F091B64 (VERSION_US)
 * Address 0x7F092644 (VERSION_JP)
 * Address 0x7F090FE4 (VERSION_EU)
 */
void cheatButtonHandleCheatsTurnedOn(CHEAT_ID cheat_id)
{
    s32 mask;
    s32 current_player_number;
    s32 player_count;
    
    mask = g_CheatInfo[cheat_id - 1].maskfield;
    current_player_number = get_cur_playernum();
    player_count = getPlayerCount();

    if ((mask & CHEAT_MASK_16) == 0)
    {
        if ((mask & CHEAT_MASK_GLOBAL) == 0)
        {
            g_CheatPlayerTextRelated[cheat_id] |= (1 << current_player_number);
        }
        else
        {
            g_CheatPlayerTextRelated[cheat_id] = (1 << player_count) - 1;
        }
    }

    switch (cheat_id)
    {
        case CHEAT_EXTRA_MP_CHARS:
            unlock_all_mp_chars();
            return;

        case CHEAT_INVINCIBILITY:
            if (!get_bondata_invincible_flag())
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x0F)));
                set_bondata_invincible_flag(TRUE);
                return;
            }
            return;

        case CHEAT_ALLGUNS:
            if (!bondinvGetAllGunsFlag())
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x10)));
                bondinvSetAllGunsFlag(TRUE);
                return;
            }
            return;

        case CHEAT_MAXAMMO:
            HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x11)));
            set_max_ammo_for_cur_player();
            return;

        case CHEAT_DEACTIVATE_INVINCIBILITY:
            {
                s32 i;
                s32 flag=0;
                if (player_count >= 2)
                {
                    i=0;
                    for (; i<player_count; i++)
                    {
                        if (i != current_player_number)
                        {
                            set_cur_player(i);
                            if (get_bondata_invincible_flag())
                            {
                                set_bondata_invincible_flag(FALSE);
                                flag = TRUE;
                            }
                        }

                        set_cur_player(current_player_number);
                    }

                    if (flag)
                    {
                        sndPlaySfx(g_musicSfxBufferPtr, CAMERA_BEEP1_SFX, 0);
                        return;
                    }

                    return;
                }
            }
            return;

        case CHEAT_LINEMODE:
            set_debug_VisCVG_flag(TRUE);
            return;

        case CHEAT_2X_HEALTH:
            if ((g_CurrentPlayer->actual_health == 1.0f) || (g_CurrentPlayer->bondhealth < 1.0f))
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x12)));
                g_CurrentPlayer->bondhealth = 1.0f;
                g_CurrentPlayer->actual_health = 2.0f;
            }
            return;

        case CHEAT_2X_ARMOR:
            if ((g_CurrentPlayer->actual_armor == 1.0f) || (g_CurrentPlayer->bondarmour < 1.0f))
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x13)));
#if defined(BUGFIX_R1)
                if(TRUE)
                {
                    // removed
                }
#endif
                g_CurrentPlayer->bondarmour = 1.0f;
                g_CurrentPlayer->actual_armor = 2.0f;
            }
            return;

        case CHEAT_INVISIBILITY:
            if (bondviewGetVisibleToGuardsFlag())
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x14)));
                bondviewSetVisibleToGuardsFlag(FALSE);
                return;
            }
            return;

        case CHEAT_INFINITE_AMMO:
            HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x16)));
            /**
            * Note: the lvlRender in lvl.c checks if infinite ammo is on then calls set_max_ammo_for_cur_player
            */
            return;

        case CHEAT_DK_MODE:
            HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x17)));
            cheatButtonSetDkMode(TRUE);
            return;

        case CHEAT_EXTRA_WEAPONS:
            if (player_count == 1)
            {
                s32 vvv;

                vvv = bondinvAddInvItem(ITEM_RUGER);
                vvv += bondinvAddInvItem(ITEM_LASER);
                vvv += bondinvAddInvItem(ITEM_GOLDENGUN);
                vvv += bondinvAddInvItem(ITEM_SILVERWPPK);
                vvv += bondinvAddInvItem(ITEM_GOLDWPPK);

                give_cur_player_ammo(AMMO_MAGNUM, get_max_ammo_for_type(AMMO_MAGNUM));
                give_cur_player_ammo(AMMO_GGUN, get_max_ammo_for_type(AMMO_GGUN));
                give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));

                if (vvv > 0)
                {
                    HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x18)));
                }
                return;
            }
            return;

        case CHEAT_TINY_BOND:
            if ((player_count == 1) && (g_playerPerm->player_perspective_height == 1.0f))
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x19)));
                g_playerPerm->player_perspective_height = 0.5f;

                if (g_CurrentPlayer->ptr_char_objectinstance != NULL)
                {
                    modelSetScale((struct Model *)g_CurrentPlayer->ptr_char_objectinstance, ((struct Model *)g_CurrentPlayer->ptr_char_objectinstance)->scale * 0.5f);
                }
                return;
            }
            return;

        case CHEAT_PAINTBALL:
            HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x1A)));
            return;

        case CHEAT_10X_HEALTH:
            if ((g_CurrentPlayer->actual_health == 1.0f) || (g_CurrentPlayer->bondhealth < 1.0f))
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x1B)));
#if defined(BUGFIX_R1)
                if(TRUE)
                {
                    // removed
                }
#endif
                g_CurrentPlayer->bondhealth = 1.0f;
                g_CurrentPlayer->actual_health = 10.0f;
                return;
            }
            return;

        case CHEAT_MAGNUM:
            if (player_count == 1)
            {
                bondinvAddInvItem(ITEM_RUGER);
                give_cur_player_ammo(AMMO_MAGNUM, get_max_ammo_for_type(AMMO_MAGNUM));
                return;
            }
            return;

        case CHEAT_LASER:
            if (player_count == 1)
            {
                bondinvAddInvItem(ITEM_LASER);
                return;
            }
            return;

        case CHEAT_GOLDEN_GUN:
            if (player_count == 1)
            {
                bondinvAddInvItem(ITEM_GOLDENGUN);
                give_cur_player_ammo(AMMO_GGUN, get_max_ammo_for_type(AMMO_GGUN));
                return;
            }
            return;

        case CHEAT_SILVER_PP7:
            if (player_count == 1)
            {
                bondinvAddInvItem(ITEM_SILVERWPPK);
                give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
                return;
            }
            return;

        case CHEAT_GOLD_PP7:
            if (player_count == 1)
            {
                bondinvAddInvItem(ITEM_GOLDWPPK);
                give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
                return;
            }
            return;

        case CHEAT_INVISIBILITY_MP: /* unknown */
            currentPlayerStartChrFade(300.0f, 0.05f);
            return;

        case CHEAT_TURBO_MODE:
            if (!get_debug_fast_bond_flag())
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x1D)));
                set_debug_fast_bond_flag(TRUE);
                return;
            }
            return;

        case CHEAT_DEBUG_POS:
            if (!get_debug_testingmanpos_flag())
            {
                set_debug_testingmanpos_flag(TRUE);
                return;
            }
            return;

        case CHEAT_FAST_ANIMATION:
            if (get_animation_rate() < 4.0f)
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x34)));
                animation_speed_related(4.0f);
                return;
            }
            return;

        case CHEAT_SLOW_ANIMATION:
            if (get_animation_rate() > 0.25f)
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x32)));
                animation_speed_related(0.25);
                return;
            }
            return;

        case CHEAT_2X_ROCKET_LAUNCHER:
            if (player_count == 1)
            {
#if defined(BUGFIX_R1)
                bondinvAddInvItem(ITEM_ROCKETLAUNCH);
#endif
                bondinvAddDoublesInvItem(ITEM_ROCKETLAUNCH, ITEM_ROCKETLAUNCH);
                give_cur_player_ammo(AMMO_ROCKETS, get_max_ammo_for_type(AMMO_ROCKETS));
                return;
            }
            return;

        case CHEAT_2X_GRENADE_LAUNCHER:
            if (player_count == 1)
            {
#if defined(BUGFIX_R1)
                bondinvAddInvItem(ITEM_GRENADELAUNCH);
#endif
                bondinvAddDoublesInvItem(ITEM_GRENADELAUNCH, ITEM_GRENADELAUNCH);
                give_cur_player_ammo(AMMO_GRENADEROUND, get_max_ammo_for_type(AMMO_GRENADEROUND));
                return;
            }
            return;

        case CHEAT_2X_RCP90:
            if (player_count == 1)
            {
#if defined(BUGFIX_R1)
                bondinvAddInvItem(ITEM_FNP90);
#endif
                bondinvAddDoublesInvItem(ITEM_FNP90, ITEM_FNP90);
                give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
                return;
            }
            return;

        case CHEAT_2X_THROWING_KNIFE:
            if (player_count == 1)
            {
#if defined(BUGFIX_R1)
                bondinvAddInvItem(ITEM_THROWKNIFE);
#endif
                bondinvAddDoublesInvItem(ITEM_THROWKNIFE, ITEM_THROWKNIFE);
                give_cur_player_ammo(AMMO_KNIFE, get_max_ammo_for_type(AMMO_KNIFE));
                return;
            }
            return;

        case CHEAT_2X_HUNTING_KNIFE:
            if (player_count == 1)
            {
#if defined(BUGFIX_R1)
                if (j_text_trigger)
                {
                    bondinvAddInvItem(ITEM_ROCKETLAUNCH);
                    bondinvAddInvItem(ITEM_SNIPERRIFLE);
                    bondinvAddDoublesInvItem(ITEM_SNIPERRIFLE, ITEM_ROCKETLAUNCH);
                    give_cur_player_ammo(AMMO_ROCKETS, get_max_ammo_for_type(AMMO_ROCKETS));
                    give_cur_player_ammo(ITEM_THROWKNIFE, get_max_ammo_for_type(ITEM_THROWKNIFE));
                    return;
                }
                bondinvAddInvItem(ITEM_KNIFE);
#endif
                bondinvAddDoublesInvItem(ITEM_KNIFE, ITEM_KNIFE);
                return;
            }
            return;

        case CHEAT_2X_LASER:
            if (player_count == 1)
            {
#if defined(BUGFIX_R1)
                bondinvAddInvItem(ITEM_LASER);
#endif
                bondinvAddDoublesInvItem(ITEM_LASER, ITEM_LASER);
                return;
            }
            return;

        case CHEAT_UNLOCK_PAINTBALL: /* fall through */
        case CHEAT_UNLOCK_INVINCIBLE:
        case CHEAT_UNLOCK_DKMODE:
        case CHEAT_UNLOCK_2XGL:
        case CHEAT_UNLOCK_2XRL:
        case CHEAT_UNLOCK_TURBO:
        case CHEAT_UNLOCK_NORADAR:
        case CHEAT_UNLOCK_TINY:
        case CHEAT_UNLOCK_2XTKNIFE:
        case CHEAT_UNLOCK_FAST:
        case CHEAT_UNLOCK_INVIS:
        case CHEAT_UNLOCK_ENEMYRL:
        case CHEAT_UNLOCK_SLOW:
        case CHEAT_UNLOCK_SILVERPPK:
        case CHEAT_UNLOCK_2XHKNIFE:
        case CHEAT_UNLOCK_INFAMMO:
        case CHEAT_UNLOCK_2XFNP0:
        case CHEAT_UNLOCK_GOLDPPK:
        case CHEAT_UNLOCK_2XLASER:
        case CHEAT_UNLOCK_ALLGUNS:
            {
                s32 val = cheat_id - CHEAT_UNLOCK_PAINTBALL;
                if ((selected_folder_num >= 0) && (selected_folder_num < 4))
                {
                    sub_GAME_7F01E760(selected_folder_num, val);
                    sndPlaySfx(g_musicSfxBufferPtr, CAMERA_BEEP1_SFX, 0);
                    return;
                }
            }
            return;
            
        case CHEAT_UNLOCK_DAM:  /* fall through */
        case CHEAT_UNLOCK_FACILITY:
        case CHEAT_UNLOCK_RUNWAY:
        case CHEAT_UNLOCK_SURFACE:
        case CHEAT_UNLOCK_BUNKER:
        case CHEAT_UNLOCK_SILO:
        case CHEAT_UNLOCK_FRIGATE:
        case CHEAT_UNLOCK_SURFACE2:
        case CHEAT_UNLOCK_BUNKER2:
        case CHEAT_UNLOCK_STATUE:
        case CHEAT_UNLOCK_ARCHIVES:
        case CHEAT_UNLOCK_STREETS:
        case CHEAT_UNLOCK_DEPOT:
        case CHEAT_UNLOCK_TRAIN:
        case CHEAT_UNLOCK_JUNGLE:
        case CHEAT_UNLOCK_CONTROL:
        case CHEAT_UNLOCK_CAVERNS:
        case CHEAT_UNLOCK_CRADLE:
        case CHEAT_UNLOCK_AZTEK:
        case CHEAT_UNLOCK_EGYPT:
            {
                s32 max = cheat_id - CHEAT_UNLOCK_DAM;
                s32 stagenum;
                s32 unlock_count;
                if (selected_folder_num >= 0 && selected_folder_num < 4)
                {
                    unlock_count = 0;
                    stagenum = 0; 
                    for (; stagenum < max; stagenum++)
                    {
                        if (fileIsStageUnlockedAtDifficulty(selected_folder_num, stagenum, DIFFICULTY_AGENT) == 3)
                        {
                            unlock_count++;
                        }
                    }

                    if (max - 1 == (unlock_count))
                    {
                        fileUnlockStageInFolderAtDifficulty(selected_folder_num, max - 1, DIFFICULTY_AGENT, 0x5F5E0FF);
                        sndPlaySfx(g_musicSfxBufferPtr, CAMERA_BEEP1_SFX, 0);
                    }
                }
            }
            return;     
        
        default:
            return;   
    }
}



/**
 * Address 0x7F092438 (all versions)
 */
void cheatButtonHandleCheatsTurnedOff(CHEAT_ID cheat_id)
{
    s32 mask;
    s32 current_player_number;
    s32 player_count;

    mask = g_CheatInfo[cheat_id - 1].maskfield;
    current_player_number = get_cur_playernum();
    player_count = getPlayerCount();

    if ((mask & CHEAT_MASK_16) == 0)
    {
        if ((mask & CHEAT_MASK_GLOBAL) == 0)
        {
            g_CheatPlayerTextRelated[cheat_id] &= ~(1 << current_player_number);
        }
        else
        {
            g_CheatPlayerTextRelated[cheat_id] = 0;
        }
    }

    switch (cheat_id)
    {
        case CHEAT_INVINCIBILITY:
            if (get_bondata_invincible_flag())
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x1e)));
                set_bondata_invincible_flag(FALSE);
                return;
            }
            return;
            
        case CHEAT_ALLGUNS:
            if (bondinvGetAllGunsFlag())
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x1F)));
                bondinvSetAllGunsFlag(FALSE);
                return;
            }
            return;

        case CHEAT_LINEMODE:
            set_debug_VisCVG_flag(FALSE);
            return;

        case CHEAT_INVISIBILITY:
            if (!bondviewGetVisibleToGuardsFlag())
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x20)));
                bondviewSetVisibleToGuardsFlag(TRUE);
                return;
            }
            return;

        case CHEAT_INFINITE_AMMO:
            HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x22)));
            return;
            
        case CHEAT_DK_MODE:
            HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x23)));
            cheatButtonSetDkMode(FALSE);
            return;

        case CHEAT_TINY_BOND:
            if ((player_count == 1) && (g_playerPerm->player_perspective_height != 1.0f))
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x24)));
                g_playerPerm->player_perspective_height = 1.0f;
                if (g_CurrentPlayer->ptr_char_objectinstance)
                {
                    modelSetScale(g_CurrentPlayer->ptr_char_objectinstance, 2.0f * ((struct Model *)g_CurrentPlayer->ptr_char_objectinstance)->scale);
                }
                return;
            }
            return;

        case CHEAT_PAINTBALL:
            HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x25)));
            return;

        case CHEAT_INVISIBILITY_MP: /* multiplayer? but the function call is for "fade"? */
            currentPlayerStartChrFade(300.0f, 1.0f);
            return;

        case CHEAT_TURBO_MODE:
            if (get_debug_fast_bond_flag())
            {
                HUDMESSAGEBOTTOM((char *)langGet(TEXT(LMISC, 0x27)));
                set_debug_fast_bond_flag(FALSE);
                return;
            }
            return;

        case CHEAT_DEBUG_POS:
            if (get_debug_testingmanpos_flag())
            {
                set_debug_testingmanpos_flag(FALSE);
            }
            return;

        
        case CHEAT_EXTRA_MP_CHARS:
        case CHEAT_MAXAMMO:
        case CHEAT_DEBUG_RETURN_SAVED_RA:
        case CHEAT_DEACTIVATE_INVINCIBILITY:
        case CHEAT_2X_HEALTH:
        case CHEAT_2X_ARMOR:
        case CHEAT_EXTRA_WEAPONS:
        case CHEAT_10X_HEALTH:
        case CHEAT_MAGNUM:
        case CHEAT_LASER:
        case CHEAT_GOLDEN_GUN:
        case CHEAT_SILVER_PP7:
        case CHEAT_GOLD_PP7:
        case CHEAT_NO_RADAR_MP:
        case CHEAT_FAST_ANIMATION:
        case CHEAT_SLOW_ANIMATION:
        case CHEAT_ENEMY_ROCKETS:
        case CHEAT_2X_ROCKET_LAUNCHER:
        case CHEAT_2X_GRENADE_LAUNCHER:
        case CHEAT_2X_RCP90:
        case CHEAT_2X_THROWING_KNIFE:
        case CHEAT_2X_HUNTING_KNIFE:
        case CHEAT_2X_LASER:
        case CHEAT_UNLOCK_PAINTBALL:
        case CHEAT_UNLOCK_INVINCIBLE:
        case CHEAT_UNLOCK_DKMODE:
        case CHEAT_UNLOCK_2XGL:
        case CHEAT_UNLOCK_2XRL:
        case CHEAT_UNLOCK_TURBO:
        case CHEAT_UNLOCK_NORADAR:
        case CHEAT_UNLOCK_TINY:
        case CHEAT_UNLOCK_2XTKNIFE:
        case CHEAT_UNLOCK_FAST:
        case CHEAT_UNLOCK_INVIS:
        case CHEAT_UNLOCK_ENEMYRL:
        case CHEAT_UNLOCK_SLOW:
        case CHEAT_UNLOCK_SILVERPPK:
        case CHEAT_UNLOCK_2XHKNIFE:
        case CHEAT_UNLOCK_INFAMMO:
        case CHEAT_UNLOCK_2XFNP0:
        case CHEAT_UNLOCK_GOLDPPK:
        case CHEAT_UNLOCK_2XLASER:
        case CHEAT_UNLOCK_ALLGUNS:
        case CHEAT_UNLOCK_DAM:
        case CHEAT_UNLOCK_FACILITY:
        case CHEAT_UNLOCK_RUNWAY:
        case CHEAT_UNLOCK_SURFACE:
        case CHEAT_UNLOCK_BUNKER:
        case CHEAT_UNLOCK_SILO:
        case CHEAT_UNLOCK_FRIGATE:
        case CHEAT_UNLOCK_SURFACE2:
        case CHEAT_UNLOCK_BUNKER2:
        case CHEAT_UNLOCK_STATUE:
        case CHEAT_UNLOCK_ARCHIVES:
        case CHEAT_UNLOCK_STREETS:
        case CHEAT_UNLOCK_DEPOT:
        case CHEAT_UNLOCK_TRAIN:
        case CHEAT_UNLOCK_JUNGLE:
        case CHEAT_UNLOCK_CONTROL:
        case CHEAT_UNLOCK_CAVERNS:
        case CHEAT_UNLOCK_CRADLE:
        case CHEAT_UNLOCK_AZTEK:
        case CHEAT_UNLOCK_EGYPT:
        
        default:
        break;
    }
    
}




/**
 * Address 0x7F0926C0.
 */
void cheatDisableAllCheats(void)
{
    s32 numplayers;
    s32 starting_player_number;
    s32 i;
    s32 j;

    numplayers = getPlayerCount();
    starting_player_number = get_cur_playernum();

    for (i=0; i<numplayers; i++)
    {
        set_cur_player(i);

        for (j=1; j<CHEAT_INVALID; j++)
        {
            if ((g_CheatInfo[j - 1].maskfield & CHEAT_MASK_TOGGLE) && (cheatIsActive(j)))
            {
                cheatButtonHandleCheatsTurnedOff(j);
            }
        }
    }

    set_cur_player(starting_player_number);
}





/**
 * Address 0x7F092774.
 */
char *cheatGetMenuTextPointer(CHEAT_ID cheat_id)
{
    u16 temp_v0;

    temp_v0 = g_CheatInfo[cheat_id - 1].text_bank_id;

    if (temp_v0 != 0)
    {
        return langGet((s32) temp_v0);
    }

    return langGet(TEXT(LMISC,0x28));
}



/**
 * Address 0x7F0927BC.
 */
bool cheatIsActive(CHEAT_ID cheat)
{
    return ((bool) (u8) g_CheatPlayerTextRelated[cheat] >> get_cur_playernum()) & 1;
}




/**
 * Address 0x7F0927F4.
 */
void cheatButtonSetDkMode(CHEAT_ID cheat_id)
{
    s32 num_guards;
    s32 i;
    f32 scale;
    Model *model;
    ChrRecord* guard = ptr_guard_data;

    num_guards = get_numguards();

    if (cheat_id)
    {
        scale = 0.8f;
    }
    else
    {
        scale = 1.25f;
    }

    for (i=0; i<num_guards; i++, guard++)
    {

#if defined(VERSION_US)
        model = (Model*)guard->model;
        if (model)
        {
            modelSetScale(model, model->scale * scale);
        }
#else
        if (guard->model && not_in_us_7F0209EC(guard->bodynum, guard->headnum))
        {
            model = (Model*)guard->model;
            modelSetScale(model, model->scale * scale);
        }
#endif
    }
}
