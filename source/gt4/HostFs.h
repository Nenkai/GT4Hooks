#pragma once

#include "Structs.h"

void HostFs_InstallHooks();

bool HOOK_HostFs_PlayStation2_FileDeviceRo2_GetFileEntry(char* thisDevice, struct FileStatus* status, char* fileName);
void HOOK_HostFs_PlayStation2_FileDeviceRo2_readStat(struct FileStatus* retStatus, void* device, struct FileObject* fileObj);
void HOOK_HostFs_PlayStation2_FileDeviceRo_openStream(void* device, struct FileInternalStream *stream);