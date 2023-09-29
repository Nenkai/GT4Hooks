#pragma once

#include "Structs.h"

void HostFs_InstallHooks();

bool HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry(struct FileDeviceRo2* device, struct FileStatus* status, char* fileName);
void HOOK_HostFs__PlayStation2_FileDeviceRo2_readStat(struct FileStatus* retStatus, struct FileDeviceRo2* device, struct FileObject* fileObj);
int HOOK_HostFs__PlayStation2_FileDeviceRo_openStream(struct FileDeviceRo* device, struct FileInternalStream *stream);
int HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream(struct FileDeviceRo* device, struct FileInternalStream *stream, struct MemorySpace* memSpace);
int HOOK_HostFs__PlayStation2_FileDeviceRo_closeStream(struct FileDeviceRo* device, struct FileInternalStream *stream);
int HOOK_HostFs__PDISTD_FileDevice_readStream(struct FileDevice* device, struct FileInternalStream* stream, struct MemorySpace* memSpace, int expand);
//void* HOOK_HostFs__PDISTD_FileInternalStream_ioctl(void* stream, void* command);
//void* HOOK_HostFs__PlayStation2_FileDeviceRo_IOControlStream(struct FileDeviceRo* device, struct FileInternalStream* stream, void* command);

int HandleHostFsOpen(struct FileDeviceRo* device, struct FileInternalStream* stream, char* fileName, struct FileObject* fileObj);
bool IsStreamedFile(char* fileName);