#include <stdbool.h>

#include "..\ps2\Memory.h"

#include "CameraSys.h"
#include "Enums\Enums.h"
#include "GameFunctions\CameraSys.h"
#include "GameFunctions\IO.h"

void CameraSys_InstallHooks()
{
    MAKE_JAL(0x23F438, &HOOK__CameraSys_CameraOnBoard_GetCameraMountIndex);
    MAKE_JAL(0x23F444, &HOOK__CameraSys_CameraOnBoard_GetCamOffset);
}

static CameraOnboardMount CameraSys__mtTable[] = {
    CameraOnboardMount_DRIVER,   // 0
    CameraOnboardMount_CHASE,    // 1
    CameraOnboardMount_BONNET,   // 6
    CameraOnboardMount_ROOF,     // 7
    CameraOnboardMount_OPTION_1, // 18
    CameraOnboardMount_METER,    // 20
};

int HOOK__CameraSys_CameraOnBoard_GetCameraMountIndex(CameraOnboardMount nextCamera)
{
    _print("HOOK__CameraSys_CameraOnBoard_GetCameraMountIndex: %d\n", nextCamera);
    const int numCams = sizeof(CameraSys__mtTable) / sizeof(CameraSys__mtTable[0]);

    for (int i = 0; i < numCams; i++)
    {
        if (CameraSys__mtTable[i] == nextCamera)
            return i;
    }

    return -1;
}

int HOOK__CameraSys_CameraOnBoard_GetCamOffset(int currentCamMountIndex, CameraOnboardMount currentCamMount)
{
    const int numCams = sizeof(CameraSys__mtTable) / sizeof(CameraSys__mtTable[0]);
    return CameraSys__mtTable[(currentCamMountIndex + currentCamMount) % numCams];
}