#include "FileDevice.h"

void (*PageManager_GetEntryForFile)(VolumeEntryTypeInfo* retEntry, PageManager* manager, char* fileName) = (void*)ADDR_PageManager_GetEntryForFile;
void* (*UnitArenaBase_allocate)(UnitArena* ptr) = (void*)ADDR_UnitArenaBase_allocate;
void* (*UnitArenaBase_free)(void*, UnitArena* ptr) = (void*)ADDR_UnitArenaBase_free;

struct FileDevice* (*PDISTD_FileInternalStream_getDevice)(void* stream) = (void*)ADDR_PDISTD_FileInternalStream_getDevice;
void (*PDISTD_FileStatus_FileStatus)(FileStatus* status) = (void*)ADDR_PDISTD_FileStatus_FileStatus;
void (*PDISTD_FileDevice_setExpander)(void* device, FileInternalStream *stream) = (void*)ADDR_PDISTD_FileDevice_setExpander;
void (*PDISTD_FileDevice_removeExpander)(void* device, FileInternalStream *stream) = (void*)ADDR_PDISTD_FileDevice_removeExpander;