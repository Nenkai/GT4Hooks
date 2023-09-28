#pragma once

#include "Structs.h"

void HostFs_InstallHooks();

bool HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry(char* thisDevice, struct FileStatus* status, char* fileName);
void HOOK_HostFs__PlayStation2_FileDeviceRo2_readStat(struct FileStatus* retStatus, void* device, struct FileObject* fileObj);
void HOOK_HostFs__PlayStation2_FileDeviceRo_openStream(void* device, struct FileInternalStream *stream);
int HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream(void* device, struct FileInternalStream *stream, struct MemorySpace* memSpace);
int HOOK_HostFs__PlayStation2_FileDeviceRo_closeStream(void *device, struct FileInternalStream *stream);