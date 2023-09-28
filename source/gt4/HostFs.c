#include <stdbool.h>

#include "SceStructs.h"
#include "SceEnums.h"
#include "HostFs.h"
#include "Functions/IO.h"

#include "..\ps2\Memory.h"

#define ADDR_PlayStation2_FileDeviceRo_openStream 0x4660D8
#define ADDR_PlayStation2_FileDeviceRo2_GetFileEntry 0x45FF60
#define ADDR_PlayStation2_FileDeviceRo2_readStat 0x466AB0
#define ADDR_PlayStation2_FileDeviceRo_rawReadStream 0x466288
#define ADDR_PlayStation2_FileDeviceRo_closeStream 0x466040

#define ADDR_PDISTD_FileStatus_FileStatus 0x464968
#define ADDR_PDISTD_FileDevice_setExpander 0x462FD0

void (*PlayStation2_FileDeviceRo_openStream)(int*, int*) = (void*)ADDR_PlayStation2_FileDeviceRo_openStream;
int (*PlayStation2_FileDeviceRo2_GetFileEntry)(char* ptr, struct FileStatus* status, char* fileName) = (void*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry;
int (*PlayStation2_FileDeviceRo2_readStat)(void* device, struct FileInternalStream* stream) = (void*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry;
int (*PlayStation2_FileDeviceRo_rawReadStream)(void* device, struct FileInternalStream* stream, void* memSpace) = (void*)ADDR_PlayStation2_FileDeviceRo_rawReadStream;
int (*PlayStation2_FileDeviceRo_closeStream)(void* device, struct FileInternalStream* stream) = (void*)ADDR_PlayStation2_FileDeviceRo_closeStream;

void (*PDISTD_FileStatus_FileStatus)(struct FileStatus* status) = (void*)ADDR_PDISTD_FileStatus_FileStatus;
void (*PDISTD_FileDevice_setExpander)(void* device, struct FileInternalStream *stream) = (void*)ADDR_PDISTD_FileDevice_setExpander;

static const char HOST_DEVICE[] = "host";
static const char HOST_DIR[] = "VOL_extract";
static const char FILE_SPLIT[] = "%s:%s/%s";

void HOOK(unsigned int func_start_addr, void* func)
{
    MAKE_JMP(func_start_addr, func);
    NOP(func_start_addr + 4); // Avoid cases where branch delay slot screw the stack up
}

void HostFs_InstallHooks()
{
    HOOK(ADDR_PlayStation2_FileDeviceRo2_GetFileEntry, HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry);
    HOOK(ADDR_PlayStation2_FileDeviceRo2_readStat, HOOK_HostFs__PlayStation2_FileDeviceRo2_readStat);
    HOOK(ADDR_PlayStation2_FileDeviceRo_openStream, HOOK_HostFs__PlayStation2_FileDeviceRo_openStream);
    HOOK(ADDR_PlayStation2_FileDeviceRo_rawReadStream, HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream);
    HOOK(ADDR_PlayStation2_FileDeviceRo_closeStream, HOOK_HostFs__PlayStation2_FileDeviceRo_closeStream);
}

bool HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry(char* thisDevice, struct FileStatus* status, char* fileName)
{
    char path[128];
    _sprintf(path, FILE_SPLIT, HOST_DEVICE, HOST_DIR, fileName);

    struct sce_stat stat = {0};
    int res = sceGetStat(path, &stat);

    int err = 0;
    err = sceStdioConvertError(0, res);

    static const char Str[] = "FileDeviceRo::GetFileEntry: sceGetStat name=%s, err=%x, st_size=%x\n";
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

void HOOK_HostFs__PlayStation2_FileDeviceRo2_readStat(struct FileStatus* retStatus, void* device, struct FileObject* fileObj)
{
    struct FileStatus status = {0};
    PDISTD_FileStatus_FileStatus(&status);
    status.Status = FileError_NOTFOUND;

    char* fileName = PlaystationX_LockFileName(fileObj->FileNameHandle);
    HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry(device, &status, fileName);
    PlayStationX_UnlockFileName(fileObj->FileNameHandle);

    retStatus->Status = status.Status;
    retStatus->RealSize = status.RealSize;
    retStatus->CompressedSize = status.RealSize;
    retStatus->Compressed = status.Compressed;

    // Likely goes back to PlayStationX::FileDeviceHost::doOpen
    // Then PDISTD::FileDevice::doOpen
}

void HOOK_HostFs__PlayStation2_FileDeviceRo_openStream(void* device, struct FileInternalStream *stream)
{
    struct FileObject* fileObj = stream->FileObject;

    // Lock name handle
    char* fileName = PlaystationX_LockFileName(fileObj->FileNameHandle);
    
    static const char n[] = "FileDeviceRo::openStream: name=%s, fd=%d\n";
    _print(n, fileName, fileObj->FileNameHandle);

    // Start opening
    struct FileStatus status = {0};
    HOOK_HostFs__PlayStation2_FileDeviceRo2_readStat(&status, fileObj->Device, fileObj);

    fileObj->Status = status;
    if (fileObj->Status.Status == FileError_OK)
    {
        char pathToFile[128];
        _sprintf(pathToFile, FILE_SPLIT, HOST_DEVICE, HOST_DIR, fileName);

        int fd = sceOpen(pathToFile, SCE_RDONLY);
        if (fd >= 0)
        {
            static const char n2[] = "FileDeviceRo::openStream: name=%s, fd=%d\n";
            _print(n2, fileName, fd);

            // Reuse data offset field as a file descriptor lol
            fileObj->Status.DataOffset = fd;

            // Setting expander doesn't seem to be required
            // But we do it anyway
            // I think it's related to decompression? It will check the stream's file status for whether the file is compressed
            // If not, no expander?
            PDISTD_FileDevice_setExpander(device, stream);
            stream->State.Offset = 0;
        }
        else
        {
            stream->Status = FileError_NOTFOUND;
        }
    }
    else
    {
        static const char failMsg[] = "Failed, status isn't OK\n";
        _print(failMsg);
    }

    // Release name handle
    PlayStationX_UnlockFileName(fileObj->FileNameHandle);
}

int HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream(void* device, struct FileInternalStream *stream, struct MemorySpace* memSpace)
{
    // Some notes: files read through hFileIO::read will read buffered 0x800 chunks.
    // This is the case for i.e projects/GT4Application.adc

    int toRead = memSpace->BufferSize;
    void* outputPtr = memSpace->BufferPtr;

    int currentOffset = stream->State.Offset;
    int fileLength = stream->FileObject->Status.RealSize;
    int rem = fileLength - currentOffset;

    if (toRead > rem)
        toRead = rem;

    int fd = stream->FileObject->Status.DataOffset;
    sceLSeek(fd, currentOffset, SCE_SEEK_SET);

    int actuallyRead = sceRead(fd, outputPtr, toRead);

    static const char n2[] = "FileDeviceRo::rawReadStream: fd=%d, req=%x, read=%x, offset=%x, data=%x\n";
    _print(n2, fd, toRead, actuallyRead, currentOffset, *(int*)outputPtr);

    // Update
    stream->State.Offset += actuallyRead;

    // Return number of bytes read. A few apis uses the return value
    return actuallyRead;
}

int HOOK_HostFs__PlayStation2_FileDeviceRo_closeStream(void *device, struct FileInternalStream *stream)
{
    int res = sceClose(stream->FileObject->Status.DataOffset);

    static const char str[] = "FileDeviceRo::closeStream: fd=%d, res=%x\n";
    _print(str, stream->FileObject->Status.DataOffset, res);

    if (res >= 0)
        return 0;

    return -1;
}