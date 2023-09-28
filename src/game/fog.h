#ifndef _FOG_H_
#define _FOG_H_

#include <ultra64.h>
#include <bondtypes.h>

#if defined(VERSION_EU)

// TODO: FIXME:
// There's something terrible going on with NearFogRecord on EU
// the function chrobjFogVisRangeRelated() treats it as a struct
// with 3 floats, but declaring it as such makes the struct too big.
// NearFogRecordF was created so we can cast it where applicable...
// but it isn't an ideal fix.

typedef struct NearFogRecord {
    s16 NearFog;
    s16 MaxVisRange;
    s16 MaxObfuscationRange;
} NearFogRecord;

typedef struct NearFogRecordF {
    f32 NearFog;
    f32 MaxVisRange;
    f32 MaxObfuscationRange;
} NearFogRecordF;

#else

typedef struct NearFogRecord {
    f32 NearFog;
    f32 MaxVisRange;
    f32 MaxObfuscationRange;
} NearFogRecord;

#endif

//New Definitions below
// SubRecords

// Skybox and Water Plane
typedef struct SkyBoxRecord
{
    u8 Red;
    u8 Green;
    u8 Blue;
    u8 Clouds;
#if defined(VERSION_EU)
    s16 CloudRepeat;
    u8 SkyImageId;
    u8 CloudRed;
    u8 CloudGreen;
    u8 CloudBlue;
    u8 IsWater;
    s16 WaterRepeat;
    u8 WaterImageId;
    u8 WaterRed;
    u8 WaterGreen;
    u8 WaterBlue;
    u8 WaterConcavity;
    u8 unknown;
#else
    f32 CloudRepeat;
    s16 SkyImageId;
    u16 Reserved;
    f32 CloudRed;
    f32 CloudGreen;
    f32 CloudBlue;
    u8 IsWater;
    u8 Padding[3];
    f32 WaterRepeat;
    s16 WaterImageId;
    u16 Reserved2;
    f32 WaterRed;
    f32 WaterGreen;
    f32 WaterBlue;
    f32 WaterConcavity;
#endif
} SkyBoxRecord;

// Fog intensity
typedef struct FogRecord
{
#if defined(VERSION_EU)
    s16 DifferenceFromFarIntensity;
    s16 FarIntensity;
#else
    /**
     * Inverse NearFog
    */
    s32 DifferenceFromFarIntensity;
    s32 FarIntensity;
#endif
} FogRecord;

// Visibility distances and Z-Buffer accuriacy
typedef struct VisibilityRecord
{
#if defined(VERSION_EU)
    s16 BlendMultiplier;
    s16 FarFog;
    NearFogRecord Nfd;
#else
    f32 BlendMultiplier;
    f32 FarFog;
    NearFogRecord Nfd;
    f32 MinVisrange;
    u32 Intensity;
#endif
} VisibilityRecord;

//Main Records

// Current Environment for rendering
typedef struct CurrentEnvironmentRecord
{
    s32 DifferenceFromFarIntensity;
    s32 FarIntensity;
    u8 Red;
    u8 Green;
    u8 Blue;
    u8 Clouds;
    f32 CloudRepeat;
    s16 SkyImageId;
    u16 Reserved;
    f32 CloudRed;
    f32 CloudGreen;
    f32 CloudBlue;
    u8 IsWater;
    u8 Padding[3];
    f32 WaterRepeat;
    s16 WaterImageId;
    u16 Reserved2;
    f32 WaterRed;
    f32 WaterGreen;
    f32 WaterBlue;
    f32 WaterConcavity;
} CurrentEnvironmentRecord;

// Environment Record, Holds Visibility, Fog and Skybox
typedef struct EnvironmentRecord
{
    /**
     * ID = StageID + Token eg, Bunker Cinema is 9 + 900 = 909
    */
#if defined(VERSION_EU)
    s16 Id;
#else
    u32 Id;
#endif
    VisibilityRecord Visibility;
    FogRecord Fog;
    SkyBoxRecord Sky;
} EnvironmentRecord;

// Environment Record, Holds only Skybox
typedef struct EnvironmentFoglessRecord
{
    /**
     * ID = StageID + Token eg, Bunker Cinema is 9 + 900 = 909
    */
    u32 Id;
    u8 Red;
    u8 Green;
    u8 Blue;
    u8 Clouds;
    f32 CloudRepeat;
    s16 SkyImageId;
    u16 Reserved;
    f32 CloudRed;
    f32 CloudGreen;
    f32 CloudBlue;
    u8 IsWater;
    u8 Padding[3];
    f32 WaterRepeat;
    s16 WaterImageId;
    u16 Reserved2;
    f32 WaterRed;
    f32 WaterGreen;
    f32 WaterBlue;
    f32 WaterConcavity;
} EnvironmentFoglessRecord;

extern s32 g_FogSkyIsEnabled;

struct CurrentEnvironmentRecord *fogGetCurrentEnvironmentp(void);
f32 fogGetScaledFarFogIntensitySquared(void);
void fogLoadLevelEnvironment(s32 level_id, s32 arg1);
s32 fogPositionIsVisibleThroughFog(coord3d *pos, f32 range);
Gfx *fogSetRenderFogColor(Gfx *arg0, s32 arg1);
Gfx *fogRenderClearFogMode(Gfx *gdl);
s32 fogGetPropDistColor(PropRecord *prop, struct rgba_f32 *color);
void fogSwitchToSolosky2(f32 arg0);
void fogRemoved7F0BAA5C(s32 a);
struct NearFogRecord *fogGetNearFogValuesP(void);

#endif
