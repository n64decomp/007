#include <ultra64.h>
#include <bondtypes.h>
#include "unk_091080.h"
#include "bondview.h"
#include "player_2.h"
#include "gun.h"
#include "math.h"
#include "fr.h"

// bss
//CODE.bss:80079E20
s32 debugCameraStateCounter;


// data
//D:80037010
s32 D_80037010 = 0; //unused

// 0x80037014
coord3d debugCameraPosition = {0.0f,0.0f,0.0f};

coord3d debugCameraForward = {0.0f,0.0f,-1.0f};

//D:8003702C
coord3d debugCameraUp = {0.0f,1.0f,0.0f};

//D:80037038
f32 debugCameraHorizontalAngle = 0.0f;
//D:8003703C
f32 debugCameraHorizontalCosine = 1.0f;
//D:80037040
f32 debugCameraHorizontalSine = 0.0f;
//D:80037044
f32 debugCameraVerticalAngle = 0.0f;
//D:80037048
f32 debugCameraVerticalCosine = 1.0f;
//D:8003704C
f32 debugCameraVerticalSine = 0.0f;

/***
 * NTSC address 0x7F091080.
*/
void debugFreeCamera(s8 joyX, s8 joyY, u16 joyBtns)
{
    f32 speedModifier;
    s32 temp_v0;

    static f32 movementSpeed = 1.0f;
    static u16 previousButtons = 0;

    speedModifier = 1.0f;
    
    if (joyX < -3)
    {
        joyX += 3;
    }
    else if (joyX > 3)
    {
        joyX -= 3;
    }
    else
    {
        joyX = 0;
    }
    
    if (joyY < -3)
    {
        joyY += 3;
    }
    else if (joyY > 3)
    {
        joyY -= 3;
    }
    else
    {
        joyY = 0;
    }

    if (!(joyBtns & (R_TRIG|L_TRIG)))
    {
        if (joyBtns & Z_TRIG)
        {
            speedModifier /= 5.0f;
        }
        
        temp_v0 = joyBtns & ~previousButtons;
        
        if (temp_v0 & A_BUTTON)
        {
            movementSpeed *= 2.0f;
        }
        
        if (temp_v0 & B_BUTTON)
        {
            movementSpeed *= 0.5f;
        }
        
        debugCameraPosition.f[0] += ((f32) joyY * debugCameraHorizontalSine * speedModifier * movementSpeed);
        debugCameraPosition.f[2] += (-(f32) joyY * debugCameraHorizontalCosine * speedModifier * movementSpeed);
        
        if (joyBtns & (L_CBUTTONS|L_JPAD))
        {
            debugCameraPosition.f[0] -= (20.0f * debugCameraHorizontalCosine * speedModifier * movementSpeed);
            debugCameraPosition.f[2] -= (20.0f * debugCameraHorizontalSine * speedModifier * movementSpeed);
        }
        
        if (joyBtns & (R_CBUTTONS|R_JPAD))
        {
            debugCameraPosition.f[0] += (20.0f * debugCameraHorizontalCosine * speedModifier * movementSpeed);
            debugCameraPosition.f[2] += (20.0f * debugCameraHorizontalSine * speedModifier * movementSpeed);
        }
        
        debugCameraHorizontalAngle += (f32) joyX * speedModifier * 0.125f;
        
        if (joyBtns & U_JPAD)
        {
            debugCameraVerticalAngle -= 2.0f * speedModifier;
        }
        
        if (joyBtns & D_JPAD)
        {
            debugCameraVerticalAngle += 2.0f * speedModifier;
        }
        
        if (joyBtns & U_CBUTTONS)
        {
            debugCameraPosition.f[1] += (20.0f * speedModifier * movementSpeed);
        }
        
        if (joyBtns & D_CBUTTONS)
        {
            debugCameraPosition.f[1] -= (20.0f * speedModifier * movementSpeed);
        }
    }

    while (debugCameraHorizontalAngle < 0.0f)
    {
        debugCameraHorizontalAngle += 360.0f;            
    }

    while (debugCameraHorizontalAngle >= 360.0f)
    {
        debugCameraHorizontalAngle -= 360.0f;
    }

    while (debugCameraVerticalAngle < 0.0f)
    {
        debugCameraVerticalAngle += 360.0f;
    }

    while (debugCameraVerticalAngle >= 360.0f)
    {
        debugCameraVerticalAngle -= 360.0f;            
    }

    debugCameraHorizontalCosine = cosf(debugCameraHorizontalAngle * DegToRad(1));
    debugCameraHorizontalSine = sinf(debugCameraHorizontalAngle * DegToRad(1));
    debugCameraVerticalCosine = cosf(debugCameraVerticalAngle * DegToRad(1));
    debugCameraVerticalSine = sinf(debugCameraVerticalAngle * DegToRad(1));
    
    debugCameraForward.f[1] = (f32) debugCameraVerticalSine;
    debugCameraForward.f[0] = (f32) (debugCameraVerticalCosine * debugCameraHorizontalSine);
    debugCameraForward.f[2] = (f32) (-debugCameraVerticalCosine * debugCameraHorizontalCosine);
    
    debugCameraUp.f[1] = (f32) debugCameraVerticalCosine;
    debugCameraUp.f[0] = (f32) (-debugCameraVerticalSine * debugCameraHorizontalSine);
    debugCameraUp.f[2] = (f32) (debugCameraVerticalSine * debugCameraHorizontalCosine);
    
    previousButtons = joyBtns;
    
    set_cur_player_fovy(FOV_Y_F);
    
    debugCameraStateCounter++;
    if (debugCameraStateCounter == 1)
    {
        remove_item_in_hand(GUNRIGHT);
        remove_item_in_hand(GUNLEFT);

        return;
    }
    
    if (debugCameraStateCounter == 4)
    {
        solo_char_load();
    }
}


//D:80037058
f32 debugCameraScale = 1.0f;
//D:8003705C
f32 debugCameraInverseScale = 1.0f;
//D:80037060
coord3d debugCameraPreviousPosition = {0.0f,0.0f,0.0f};


/*
* Address: 0x7F091580
*/
Gfx * sub_GAME_7F091580(Gfx * arg0) {
    sub_GAME_7F0876C4(&debugCameraPosition, &debugCameraForward, &debugCameraUp);
    return arg0;
}


/*
* Address: 0x7F0915BC
*/
void setDebugCameraScale(float scale)
{
  float scaleFactor;
  
  scaleFactor = debugCameraScale / scale;
  debugCameraScale = scale;
  debugCameraPosition.x = debugCameraPosition.x * scaleFactor;
  debugCameraPosition.y = debugCameraPosition.y * scaleFactor;
  debugCameraPosition.z = debugCameraPosition.z * scaleFactor;
  debugCameraInverseScale = 1.0f / scale;
}


/*
* Address: 0x7f091618
*/
void initializeDebugCameraPosition(void)
{
    coord3d* pos; //needed to be declared but not used to match
    f32 x;

    bondviewGetCurrentPlayersPosition();  //normally would return a coord3d pos but not here
    x = M_TAU_F -  get_curplay_horizontal_rotation_in_degrees();
    cosf(x);
    sinf(x);
    cosf(x);
    sinf(x);
   /*osSyncPrintf("propBondIntroKey(INTROKEY_RELBONDDIR,%ff,%ff,%ff,0.75f,40.0f) ", cosf(x),sinf(x));*/
}


/*
* Address: 0x7f09166c
*/
void updateDebugCameraWorldPosition(void)
{
    sqrtf((debugCameraPosition.x - debugCameraPreviousPosition.x) * (debugCameraPosition.x - debugCameraPreviousPosition.x) +
          (debugCameraPosition.y - debugCameraPreviousPosition.y) * (debugCameraPosition.y - debugCameraPreviousPosition.y) +
          (debugCameraPosition.z - debugCameraPreviousPosition.z) * (debugCameraPosition.z - debugCameraPreviousPosition.z));
    #ifdef DEBUG
    osSyncPrintf("world pos = %f,%f,%f\n", debugCameraPosition.x, debugCameraPosition.y, debugCameraPosition.z);
    osSyncPrintf("world theta = %f verta = %f\n", (debugCameraPreviousPosition.x * 6.283185) / 360.0, (debugCameraPreviousPosition.z * 6.283185) / 360.0);
    osSyncPrintf("dist from prev = %f\n",
                 sqrtf((debugCameraPosition.x - debugCameraPreviousPosition.x) * (debugCameraPosition.x - debugCameraPreviousPosition.x) +
                       (debugCameraPosition.y - debugCameraPreviousPosition.y) * (debugCameraPosition.y - debugCameraPreviousPosition.y) +
                       (debugCameraPosition.z - debugCameraPreviousPosition.z) * (debugCameraPosition.z - debugCameraPreviousPosition.z)));
    #endif
    debugCameraPreviousPosition.x = debugCameraPosition.x;
    debugCameraPreviousPosition.y = debugCameraPosition.y;
    debugCameraPreviousPosition.z = debugCameraPosition.z;
}

/*
* Address: 0x7F0916F4
*/
void resetDebugCameraToPlayerPosition(void)
{
    coord3d *pos;

    pos = bondviewGetCurrentPlayersPosition();
    debugCameraPosition.x = pos->x;
    debugCameraPosition.y = pos->y;
    debugCameraPosition.z = pos->z;
    debugCameraStateCounter = 0;
}



