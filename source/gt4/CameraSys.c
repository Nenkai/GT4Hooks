#include <stdbool.h>

#include "..\ps2\Memory.h"

#include "CameraSys.h"
#include "GameFunctions\CameraSys.h"

void CameraSys_InstallHooks()
{
    MAKE_JAL(0x23F438, &HOOK__CameraSys_CameraOnBoard_GetCameraMountIndex);
    MAKE_JAL(0x23F444, &HOOK__CameraSys_CameraOnBoard_GetCamOffset);
}

#define NUM_CAMS 25
static int CameraSys__mtTable[NUM_CAMS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

int HOOK__CameraSys_CameraOnBoard_GetCameraMountIndex(int nextCamera)
{
    for (int i = 0; i < NUM_CAMS; i++)
    {
        if (CameraSys__mtTable[i] == nextCamera)
            return i;
    }

    return -1;
}

int HOOK__CameraSys_CameraOnBoard_GetCamOffset(int currentCamMountIndex, int currentCamMount)
{
    return CameraSys__mtTable[(currentCamMountIndex + currentCamMount) % NUM_CAMS];
}