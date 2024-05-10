#pragma once

void MStorage_InstallHooks();
unsigned int HOOK__mStorageMC_getFileSize(void* this_, char* name);