#include <ultra64.h>
#include "speed_graph.h"
#include "unk_0C0A70.h"
#include "speedgraphrenderer.h"
#include "debugmenu.h"
#include "sched.h"

/**
* Used in speedgraphDisplayMetrics to check if speedgraphframes and g_speedGraphCountAccumulator are
* over the threshold for output.
*/
#define COUNT_REQUIRED_FOR_OUTPUT 20

/**
 * Used in speedgraphDisplayMetrics to calculate display Hz.
 */
#ifdef REFRESH_PAL
#define VICLOCK 50
#else
#define VICLOCK 60
#endif

#if defined(LEFTOVERDEBUG)
s32 gSpeedGraphMarkerFlags[3];
Gfx gSpeedGraphDisplayLists[2][266];
s32 gSpeedGraphDisplayListIndex;
u32 g_speedGraphLastOsCount;
u32 g_speedGraphCurrentOsCount;
u32 dword_CODE_bss_800604AC;
#endif

typedef struct {
    u32 markerFlags;
    u32 osCount;
} SpeedGraphMarker;

#if defined(LEFTOVERDEBUG)
SpeedGraphMarker gSpeedGraphMarkers[3][32];
s32 gSpeedGraphMarkerIndices[3];
s32 gSpeedGraphMarkerNextIndices[3];
s32 gSpeedGraphMarkerHeadIndices[3];

#endif
s32 D_800231D0 = 0;

typedef struct {
    s32 index;
    s32 color;
    s32 width;
    s32 height;
} SpeedGraphColorSettings;

#if defined(LEFTOVERDEBUG)
SpeedGraphColorSettings gSpeedGraphColorSettings[5] = {
    {0x00000000, 0x00000000, 0x00000002, 0x00000000},
    {0x00000001, 0x00000000, 0x00000002, 0x00000000},
    {0x00000002, 0xFF000000, 0x00000002, 0x00000000},
    {0x00000003, 0x00009200, 0x00000004, 0xFFFFFFFF},
    {0x00000004, 0xDB000000, 0x00000004, 0xFFFFFFFF}
};

/**
 * 80023224. Seems to accumulate speedgraphframes in speedgraphDisplayMetrics. Once above the threshold COUNT_REQUIRED_FOR_OUTPUT,
 * the value COUNT_REQUIRED_FOR_OUTPUT is repeatedly subtracted until below the threshold.
 */
u32 g_speedGraphCountAccumulator = 0;

/**
 * 80023228. Stores max value of speedgraphframes seen in speedgraphDisplayMetrics. Resets to zero once
 * output is rendered.
 */
s32 g_speedGraphMaxSeenCount = 0;

#endif

// forward declarations
void speedgraphMarkerCommit(void);
/////


/**
 * @brief Initializes the speed graph display lists and marker indices.
 */
void speedgraphInit(void)
{
    #if defined(LEFTOVERDEBUG)
    s32 i;

    gSPEndDisplayList(gSpeedGraphDisplayLists[0]);
    gSPEndDisplayList(gSpeedGraphDisplayLists[1]);
    gSpeedGraphDisplayListIndex = 0;

    for (i = 0; i < 3; i++)
    {
        gSpeedGraphMarkerIndices[i] = 0;
        gSpeedGraphMarkerHeadIndices[i] = 1;
    }

    speedgraphMarkerCommit();
    #endif
}


/**
 * @brief Updates the speed graph marker indices and current OS counter value.
 */
void speedgraphMarkerUpdate(void) {
    #if defined(LEFTOVERDEBUG)
    s32 i;

    g_speedGraphCurrentOsCount = osGetCount();

    for (i = 0; i < 3; i++)
    {        
        gSpeedGraphMarkerNextIndices[i] = ((gSpeedGraphMarkerHeadIndices[i] + 31) % 32);
    }
    #endif
}


/**
 * @brief Commits the current speed graph marker states.
 */
void speedgraphMarkerCommit(void) {
    #if defined(LEFTOVERDEBUG)
    s32 i;

    g_speedGraphLastOsCount = g_speedGraphCurrentOsCount;

    for (i = 0; i < 3; i++)
    {
        gSpeedGraphMarkerIndices[i] = gSpeedGraphMarkerNextIndices[i];
    }
    #endif
}

#if !defined(LEFTOVERDEBUG)
/**
 * @brief Renders the speed graph based on the collected marker data.
 * EU is a dummy function.
 */
void speedgraphRenderGraph(void)
{
}
#endif

/**
 * @brief Handles setting a marker in the speed graph, updating flags and OS count.
 *
 * @param arg0 Specifies the marker state to be set.
 */
void speedgraphMarkerHandler(s32 arg0)
{
#if defined(LEFTOVERDEBUG)
    s32 index;
    s32 markerFlag;
    OSIntMask mask;
    s32 nextIndex;
    SpeedGraphMarker *marker;

    index = arg0 & 0xFFFF;
    mask = osSetIntMask(OS_IM_NONE);
    markerFlag = arg0 >> 16;
    nextIndex = gSpeedGraphMarkerHeadIndices[index];

    if (markerFlag == 3)
    {
        // set highest bit
        markerFlag = gSpeedGraphMarkerFlags[index] | 0x8000;
    }
    else if (markerFlag == 6)
    {
        // clear highest bit
        markerFlag = gSpeedGraphMarkerFlags[index] & 0x7FFF;
    }

    marker = &gSpeedGraphMarkers[index][nextIndex];
    marker->markerFlags = markerFlag;
    marker->osCount = osGetCount();
    gSpeedGraphMarkerFlags[index] = markerFlag;

    nextIndex++;
    
    if (nextIndex >= 32)
    {
        nextIndex = 0;
    }

    gSpeedGraphMarkerHeadIndices[index] = nextIndex;

    osSetIntMask(mask);
#endif
}

/**
 * @brief Displays the speed graph metrics, including frame rate and processor utilization.
 *
 * @param gdl Pointer to the current display list.
 * @return Pointer to the updated display list.
 */
Gfx *speedgraphDisplayMetrics(Gfx *gdl)
{
#if defined(LEFTOVERDEBUG)
    u32 *counters;
    u32 localCountAccumulator = g_speedGraphCountAccumulator;
    s32 *pmaxSeenCount = &g_speedGraphMaxSeenCount;
    char buffer[12];
    volatile u32 *pcountAccumulator = &g_speedGraphCountAccumulator;
    
    localCountAccumulator += speedgraphframes;

    if (*pmaxSeenCount < speedgraphframes)
    {
        *pmaxSeenCount = speedgraphframes;
    }

    *pcountAccumulator = localCountAccumulator;
    
    if (localCountAccumulator > COUNT_REQUIRED_FOR_OUTPUT)
    {
        *pcountAccumulator = localCountAccumulator;

        if (localCountAccumulator > COUNT_REQUIRED_FOR_OUTPUT)
        {
            do
            {
                localCountAccumulator -= COUNT_REQUIRED_FOR_OUTPUT;
            }
            while (localCountAccumulator > COUNT_REQUIRED_FOR_OUTPUT);

            *pcountAccumulator = localCountAccumulator;
        }
        
        counters = get_counters();

        debmenuSetFgColour(255, 255, 255, 255);
        debmenuSetEnvColor(0, 0, 0, 255);

        // utz %
        debmenuSetPos(8, 5);
        sprintf(buffer, "utz %2.0f%%\n", (((counters[1] - counters[3]) * 100.0f) / counters[0]));
        debmenuPrintString(buffer);

        // rsp %
        debmenuSetPos(8, 6);
        sprintf(buffer, "rsp %2.0f%%\n", (((counters[0] - counters[1]) * 100.0f) / counters[0]));
        debmenuPrintString(buffer);

        // tex %
        debmenuSetPos(8, 7);
        sprintf(buffer, "tex %2.0f%%", ((counters[3] * 100.0f) / counters[0]));
        debmenuPrintString(buffer);

        // hz (60 / framerate)
        // -- or 50 for PAL
        debmenuSetPos(28, 5);
        sprintf(buffer, "%2d hz", ((speedgraphframes == 0) ? 0 : (VICLOCK / speedgraphframes)));
        debmenuPrintString(buffer);

        // framerate
        debmenuSetPos(28, 6);
        sprintf(buffer, "%2d frames", speedgraphframes);
        debmenuPrintString(buffer);

        // (continues framerate output)
        if (speedgraphframes != g_speedGraphMaxSeenCount)
        {
            sprintf(buffer, " [%2d]", *pmaxSeenCount);
        }
        else
        {
            sprintf(buffer, "     ");
        }

        debmenuPrintString(buffer);
        
        g_speedGraphMaxSeenCount = 0;
    }

    gSPDisplayList(gdl++, gSpeedGraphDisplayLists[gSpeedGraphDisplayListIndex ^ 1]);
#endif
    return gdl;
}


#if defined(LEFTOVERDEBUG)
/**
 * @brief Renders the speed graph based on the collected marker data.
 */
void speedgraphRenderGraph(void)
{
    s32 currentMarkerIndex;
    s32 i; // sp 0xc8
    f32 graphWidth;
    s32 markerFlags;
    u32 currentMarkerOsCount;
    Gfx *gdl;
    s32 graphStates[3];
    u32 previousOsCount[3];
    Gfx *head;
    SpeedGraphColorSettings *colorSettings;
    u32 tempOsCount;

    static s32 frameToggle = 0;
    static u32 speedGraphCounterForFrames = 0;
    static s32 toggleFlag = 1;

    speedGraphCounterForFrames += speedgraphframes;
    if (speedGraphCounterForFrames > 200)
    {
        toggleFlag ^= 1;
        speedGraphCounterForFrames -= 200;
    }

    if (toggleFlag != (frameToggle++ & 1))
    {
        gdl = InitializeSpeedGraphDL(gSpeedGraphDisplayLists[gSpeedGraphDisplayListIndex]);
        
        for (i = 0; i < 3; i++)
        {
            graphStates[i] = 0;
        }

        for (i = 0; i < 3; i++)
        {
            previousOsCount[i] = g_speedGraphLastOsCount;
        }
        
        for (i = 0; i < 3; i++)
        {
            currentMarkerIndex = gSpeedGraphMarkerIndices[i];
                        
            if(1);
            graphWidth = 0;
            
            while (currentMarkerIndex != gSpeedGraphMarkerHeadIndices[i])
            {          
                markerFlags = gSpeedGraphMarkers[i][currentMarkerIndex].markerFlags;
                
                if (markerFlags & 0x8000)
                {
                    markerFlags = 3;
                }
                
                tempOsCount = gSpeedGraphMarkers[i][currentMarkerIndex].osCount; 
                
                if(currentMarkerIndex);
                //if(1);
                
                currentMarkerOsCount = previousOsCount[i];
                if (currentMarkerOsCount < g_speedGraphLastOsCount)
                {
                    currentMarkerOsCount = g_speedGraphLastOsCount;
                }
                
                if (tempOsCount >= g_speedGraphLastOsCount && tempOsCount >= currentMarkerOsCount)
                {
                    if ((graphStates[i] != 1) && (graphStates[i] != 3) && ((graphStates[i] & 0x8000) == 0))
                    {
                        graphWidth += (tempOsCount - currentMarkerOsCount) / 775875.0f;
                    }

                    colorSettings = &gSpeedGraphColorSettings[graphStates[i]];
                    
                    if (graphStates[i] == 1)
                    {
                        UpdateGraphPosition((tempOsCount - currentMarkerOsCount) / 775875.0f);
                    }
                    else
                    {
                        gdl = DrawGraphBar(
                            gdl++,
                            (tempOsCount - currentMarkerOsCount) / 775875.0f, 
                            ((colorSettings->color >> 0x18) & 0xFF), 
                            ((colorSettings->color >> 0x10) & 0xFF), 
                            ((colorSettings->color >> 0x8) & 0xFF), 
                            colorSettings->width, 
                            colorSettings->height);
                    }

                    head = gdl++;
                    gDPPipeSync(head);
                    //gDPPipeSync(gdl++);
                }
                
                graphStates[i] = markerFlags;
                previousOsCount[i] = tempOsCount;
                currentMarkerIndex = ((currentMarkerIndex + 1) % 32);
            }
            
            if (i < 2)
            {
                AlignGraphPosition();
            }
        }
        
        gdl = DrawVerticalLines(gdl++, 0, 0, 0);
        gDPPipeSync(gdl++);
        gSPEndDisplayList(gdl);
        
        gSpeedGraphDisplayListIndex ^= 1;
    }

}
#endif
