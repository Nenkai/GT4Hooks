#include <stdbool.h>

#include "SceStructs.h"
#include "SceEnums.h"
#include "HostFs.h"
#include "Functions.h"

#include "..\ps2\Memory.h"

#define ADDR_PlayStation2_FileDeviceRo_openStream 0x4660D8
#define ADDR_PlayStation2_FileDeviceRo2_GetFileEntry 0x45FF60
#define ADDR_PlayStation2_FileDeviceRo2_readStat 0x466AB0

#define ADDR_PDISTD_FileStatus_FileStatus 0x464968

void (*PlayStation2_FileDeviceRo_openStream)(int*, int*) = (void*)ADDR_PlayStation2_FileDeviceRo_openStream;
int (*PlayStation2_FileDeviceRo2_GetFileEntry)(char* ptr, struct FileStatus* status, char* fileName) = (void*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry;
int (*PlayStation2_FileDeviceRo2_readStat)(void* device, struct FileInternalStream *stream) = (void*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry;

void (*PDISTD_FileStatus_FileStatus)(struct FileStatus* status) = (void*)ADDR_PDISTD_FileStatus_FileStatus;

static const char HOST_DEVICE[] = "host";
static const char HOST_DIR[] = "VOL_extract";

void HostFs_InstallHooks()
{
    MAKE_JMP(ADDR_PlayStation2_FileDeviceRo2_GetFileEntry, HOOK_HostFs_PlayStation2_FileDeviceRo2_GetFileEntry);
    MAKE_JMP(ADDR_PlayStation2_FileDeviceRo2_readStat, HOOK_HostFs_PlayStation2_FileDeviceRo2_readStat);
    MAKE_JMP(ADDR_PlayStation2_FileDeviceRo_openStream, HOOK_HostFs_PlayStation2_FileDeviceRo_openStream);
}

bool HOOK_HostFs_PlayStation2_FileDeviceRo2_GetFileEntry(char* thisDevice, struct FileStatus* status, char* fileName)
{
    char path[128];

    static const char FILE_SPLIT[] = "%s:%s/%s";
    _sprintf(path, FILE_SPLIT, HOST_DEVICE, HOST_DIR, fileName);

    struct sce_stat stat = {0};
    int res = sceGetStat(path, &stat);

    int err = 0;
    err = sceStdioConvertError(0, res);

    static const char Str[] = "FileDeviceRo2::GetFileEntry: sceGetStat name=%s, err=%x, st_size=%x\n";
    _print(Str, path, err, stat.st_size);

    if (res < 0)
    {
        return false;
    }

    status->Status = FileError_OK;
    status->Compressed = false;
    status->CompressedSize = stat.st_size;
    status->RealSize = stat.st_size;
    return true;
}

void HOOK_HostFs_PlayStation2_FileDeviceRo2_readStat(struct FileStatus* retStatus, void* device, struct FileObject* fileObj)
{
    struct FileStatus status = {0};
    PDISTD_FileStatus_FileStatus(&status);
    status.Status = FileError_NOTFOUND;

    char* fileName = PlaystationX_LockFileName(fileObj->FileDescriptor);
    HOOK_HostFs_PlayStation2_FileDeviceRo2_GetFileEntry(device, &status, fileName);
    PlayStationX_UnlockFileName(fileObj->FileDescriptor);

    retStatus->Status = status.Status;
    retStatus->RealSize = status.RealSize;
    retStatus->CompressedSize = status.RealSize;
    retStatus->Compressed = status.Compressed;

    // Likely goes back to PlayStationX::FileDeviceHost::doOpen
    // Then PDISTD::FileDevice::doOpen
}

void HOOK_HostFs_PlayStation2_FileDeviceRo_openStream(void* device, struct FileInternalStream *stream)
{
    struct FileObject* fileObj = stream->FileObject;

    // Lock name handle
    char* fileName = PlaystationX_LockFileName(fileObj->FileDescriptor);
    
    static const char n[] = "PlayStation2_FileDeviceRo_openStream: %s (%d)\n";
    _print(n, fileName, fileObj->FileDescriptor);

    // Start opening
    struct FileStatus status = {0};
    HOOK_HostFs_PlayStation2_FileDeviceRo2_readStat(&status, fileObj->Device, fileObj);

    fileObj->Status = status;
    if (fileObj->Status.Status == FileError_OK)
    {
        int fd = sceOpen(fileName, SCE_RDONLY);
        if (fd != -1)
        {
            
        }
        else
        {
            stream->Status = FileError_NOTFOUND;
        }
    }

    // Release handle
    PlayStationX_UnlockFileName(fileObj->FileDescriptor);
}