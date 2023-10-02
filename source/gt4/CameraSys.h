#pragma once

#include "Enums\Enums.h"

void CameraSys_InstallHooks();

int HOOK__CameraSys_CameraOnBoard_GetCameraMountIndex(CameraOnboardMount nextCamera);
int HOOK__CameraSys_CameraOnBoard_GetCamOffset(int currentCamMountIndex, CameraOnboardMount currentCamMount);