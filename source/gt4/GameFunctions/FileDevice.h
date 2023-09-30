#pragma once

#include "..\GameStructs\FileDevice.h"
#define ADDR_PlayStation2_FileDeviceRo_openStream 0x6D9694
#define ADDR_PlayStation2_FileDeviceRo2_GetFileEntry 0x6D96E4
#define ADDR_PlayStation2_FileDeviceRo2_readStat 0x6D96CC
#define ADDR_PDISTD_FileDevice_readStream 0x6D96A4
#define ADDR_PlayStation2_FileDeviceRo_rawReadStream 0x466288
#define ADDR_PlayStation2_FileDeviceRo_closeStream 0x6D968C
#define ADDR_PlayStation2_FileDeviceRo2_IOControlStream 0x4665C0
#define ADDR_PlayStation2_FileDeviceRo_pipe 0x466CB0
#define ADDR_PDISTD_FileInternalStream_ioctl 0x464CD0
#define ADDR_PDISTD_FileInternalStream_getDevice 0x464D28

#define ADDR_UnitArenaBase_allocate 0x528580
#define ADDR_UnitArenaBase_free 0x5285B0

#define ADDR_PageManager_GetEntryForFile 0x4613C0

#define ADDR_PDISTD_FileStatus_FileStatus 0x464968
#define ADDR_PDISTD_FileDevice_setExpander 0x462FD0
#define ADDR_PDISTD_FileDevice_removeExpander 0x463020

//int (*PlayStation2_FileDeviceRo2_IOControlStream)(struct FileDeviceRo* device, struct FileInternalStream* stream, void* command) = (void*)ADDR_PlayStation2_FileDeviceRo2_IOControlStream;
//int (*PlayStation2_FileDeviceRo_pipe)(struct FileDeviceRo* device, void* command) = (void*)ADDR_PlayStation2_FileDeviceRo_pipe;
//void* (*PDISTD_FileInternalStream_ioctl)(void* stream, void* command) = (void*)ADDR_PDISTD_FileInternalStream_ioctl;

extern void (*PageManager_GetEntryForFile)(VolumeEntryTypeInfo* retEntry, PageManager* manager, char* fileName);
extern void* (*UnitArenaBase_allocate)(UnitArena* ptr);
extern void* (*UnitArenaBase_free)(void*, UnitArena* ptr);

extern struct FileDevice* (*PDISTD_FileInternalStream_getDevice)(void* stream);
extern void (*PDISTD_FileStatus_FileStatus)(FileStatus* status);
extern void (*PDISTD_FileDevice_setExpander)(void* device, FileInternalStream *stream);
extern void (*PDISTD_FileDevice_removeExpander)(void* device, FileInternalStream *stream);