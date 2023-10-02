#pragma once

void MStorage_InstallHooks();
int HOOK__mStorageMC_getFileSize(void* this, char* name);