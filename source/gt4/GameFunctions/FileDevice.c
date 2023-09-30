#include "FileDevice.h"

void (*PageManager_GetEntryForFile)(struct VolumeEntryTypeInfo* retEntry, struct PageManager* manager, char* fileName) = (void*)ADDR_PageManager_GetEntryForFile;
void* (*UnitArenaBase_allocate)(struct UnitArena* ptr) = (void*)ADDR_UnitArenaBase_allocate;
void* (*UnitArenaBase_free)(void*, struct UnitArena* ptr) = (void*)ADDR_UnitArenaBase_free;

struct FileDevice* (*PDISTD_FileInternalStream_getDevice)(void* stream) = (void*)ADDR_PDISTD_FileInternalStream_getDevice;
void (*PDISTD_FileStatus_FileStatus)(struct FileStatus* status) = (void*)ADDR_PDISTD_FileStatus_FileStatus;
void (*PDISTD_FileDevice_setExpander)(void* device, struct FileInternalStream *stream) = (void*)ADDR_PDISTD_FileDevice_setExpander;
void (*PDISTD_FileDevice_removeExpander)(void* device, struct FileInternalStream *stream) = (void*)ADDR_PDISTD_FileDevice_removeExpander;