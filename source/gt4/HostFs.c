#include <stdbool.h>
#include <stdio.h>

#include "..\ps2\Memory.h"

#include "GameFunctions/IO.h"
#include "GameFunctions/String.h"
#include "GameFunctions/FileDevice.h"
#include "GameStructs/SceStructs.h"
#include "Enums/SceEnums.h"
#include "Utils/String.h"

#include "HostFs.h"

static const char HOST_DIR[] = "VOL_extract";

/* Hook: HostFS
   Purpose: Hijack FileDeviceRo (read only volume reader)'s functions to read loose files.
   How: Overrides relevant file device functions. Files that must be streamed from IOP (i.e sound/movies) was considered, but too hard.
        These files MUST be streamed from IOP.
        Which is why there's some remaining code for ioctl/IOControlStream, which are the ones that are used for streaming.
        The overriden functions are almost identical to original code, but adds HostFS handling aswell.
   Note: Modify "HOST_DIR" above.
*/

void HostFs_InstallHooks()
{
    HOOK_FUNC_ADDR((void*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry, &HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry);
    HOOK_FUNC_ADDR(ADDR_PlayStation2_FileDeviceRo_openStream, &HOOK_HostFs__PlayStation2_FileDeviceRo_openStream);
    HOOK(ADDR_PlayStation2_FileDeviceRo_rawReadStream, HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream);
    HOOK_FUNC_ADDR((void*)ADDR_PlayStation2_FileDeviceRo_closeStream, &HOOK_HostFs__PlayStation2_FileDeviceRo_closeStream);
    HOOK_FUNC_ADDR((void*)ADDR_PDISTD_FileDevice_readStream, &HOOK_HostFs__PDISTD_FileDevice_readStream);
    //HOOK(ADDR_PlayStation2_FileDeviceRo2_IOControlStream, HOOK_HostFs__PlayStation2_FileDeviceRo_IOControlStream);
    //HOOK(ADDR_PDISTD_FileInternalStream_ioctl, HOOK_HostFs__PDISTD_FileInternalStream_ioctl);
}

int HOOK_HostFs__PDISTD_FileDevice_readStream(FileDevice* device, FileInternalStream* stream, MemorySpace* memSpace, int expand)
{
    char* fileName = PlaystationX_LockFileName(stream->FileObject->FileNameHandle);
    bool isStreamedFile = IsStreamedFile(fileName);

#if HOSTFS_PRINT && PRINT_HOSTFS_READS
    _print("FileDeviceRo::readStream: %s\n", fileName);
#endif

    PlayStationX_UnlockFileName(stream->FileObject->FileNameHandle);

    int ret = 0;

    // Read from vol, fix hook
    if (isStreamedFile)
    {
        *(int*)ADDR_PlayStation2_FileDeviceRo_rawReadStream = 0x27BDFFB0;
        *((int*)ADDR_PlayStation2_FileDeviceRo_rawReadStream + 1) = 0xFFB70038;
    }

    if (expand)
    {
        ret = device->VTable->rawReadStream(device, stream, memSpace);
    }
    else
    {
        
        ret = device->VTable->rawReadStream(device, stream, memSpace);
    }

    HOOK(ADDR_PlayStation2_FileDeviceRo_rawReadStream, HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream);

    return ret;
}

// Guessed function name
bool HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry(FileDeviceRo2* device, FileStatus* status, char* fileName)
{
    if (IsStreamedFile(fileName))
    {
        VolumeEntryTypeInfo volFile = {0};

        PageManager* pageManager = &device->PageManager;
        PageManager_GetEntryForFile(&volFile, pageManager, fileName);

        if (volFile.Status >= 0)
        {
            status->Status = FileError_OK;
            status->Compressed = (volFile.EntryType >> 1) & 1;
            status->RealSize = volFile.RealSize;
            status->CompressedSize = volFile.CompressedSize;
            status->DataOffset = device->Ro.TocOffset
                   + *(int*)(pageManager->HeaderBuffer + 0x0C)
                   + volFile.PageOffset;

#if HOSTFS_PRINT
            _print("GetVolumeFileInfo: pageManager compressed=%d, real_size=%x, comp_size=%x, data_offset=%x\n", 
                status->Compressed, status->RealSize, status->CompressedSize, status->DataOffset);
#endif

            return true;
        }
    }
    else
    {
        char path[128];
        _sprintf(path, "host:%s/%s", HOST_DIR, fileName);

        struct sce_stat stat = {0};
        int res = sceGetStat(path, &stat);

        int err = 0;
        err = sceStdioConvertError(0, res);

#if HOSTFS_PRINT
        _print("FileDeviceRo::GetFileEntry: sceGetStat name=%s, err=%x, st_size=%x\n", path, err, stat.st_size);
#endif

        if (res >= 0)
        { 
            status->Status = FileError_OK;
            status->Compressed = false;
            status->CompressedSize = stat.st_size;
            status->RealSize = stat.st_size;
            return true;
        }
    }

    return false;
}

int HOOK_HostFs__PlayStation2_FileDeviceRo_openStream(FileDeviceRo* device, FileInternalStream *stream)
{
    int res = -1;

    FileObject* fileObj = stream->FileObject;
    int fileMode = fileObj->FileMode;

    // Lock name handle
    char* fileName = PlaystationX_LockFileName(fileObj->FileNameHandle);

#if HOSTFS_PRINT
    _print("FileDeviceRo::openStream: name=%s, mode=%d\n", fileName, fileMode);
#endif

    if (fileMode != 3)
    {
        if (fileMode > 0)
        {

        }
        else
        {
            FileStatus status = {0};

            // Do NOT load these files from host, they need to be put into IOP memory using IRX RPC, pain to deal with
            if (IsStreamedFile(fileName))
            {
                device->Pipe.Base.VTable->readStat(&status, device, fileObj);
                fileObj->Status = status;

                if (fileObj->Status.Status)
                    goto err;

                res = device->Pipe.Base.VTable->getCdOffsetFromDataOffset(device, fileName, status.DataOffset, status.CompressedSize);
            }
            else
            {
                res = HandleHostFsOpen(device, stream, fileName, fileObj);
            }
        }

        if (res)
        {
            // Expanders are what processes a file after it's been read
            // i.e decompressor/inflator.
            // FileDeviceRo's expander check if the stream's file object is compressed before doing anything
            PDISTD_FileDevice_setExpander(device, stream);

            // This is required for files that we force read from CDVD
            UnitArena* unit = UnitArenaBase_allocate((UnitArena*)(0x885340));
            // Actual disc sector offset likely goes here - calculated from 0x466C00 (FileDeviceRo2::GetSectorOffsetOfFileName?)
            unit->field_0x00 = res; 
            unit->Offset = 0;
            unit->field_0x08 = 0;
            unit->field_0x0C = UnitArenaBase_allocate((UnitArena*)(0x885360));
            stream->State = unit;
        }
        else
        {
            stream->Status = FileError_NOTFOUND;
        }
    }
    else
    {
        res = 0;
    }

err:
    // Release name handle
    PlayStationX_UnlockFileName(fileObj->FileNameHandle);
    return res;
}

int HandleHostFsOpen(FileDeviceRo* device, FileInternalStream* stream, char* fileName, FileObject* fileObj)
{
    // Start opening
    FileStatus status = {0};

    device->Pipe.Base.VTable->readStat(&status, device, fileObj);
    fileObj->Status = status;

    if (fileObj->Status.Status == FileError_OK)
    {
        char pathToFile[128];
        _sprintf(pathToFile, "host:%s/%s", HOST_DIR, fileName);

        int fd = sceOpen(pathToFile, SCE_RDONLY);

#if HOSTFS_PRINT
        _print("HandleHostFsOpen: name=%s, fd=%d\n", fileName, fd);
#endif
        if (fd >= 0)
        {
            // Reuse data offset field as a file descriptor lol
            fileObj->Status.DataOffset = fd;
            return 1; // Good
        }
    }
    else
    {
#if HOSTFS_PRINT
        _print("HandleHostFsOpen: Failed, status isn't OK\n");
#endif
    }

    return 0;
}

int HOOK_HostFs__PlayStation2_FileDeviceRo_rawReadStream(FileDeviceRo* device, FileInternalStream *stream, MemorySpace* memSpace)
{
    // Some notes: files read through hFileIO::read will read buffered 0x800 chunks.
    // This is the case for i.e projects/GT4Application.adc
    int toRead = memSpace->BufferSize;
    void* outputPtr = memSpace->BufferPtr;

    int currentOffset = stream->State->Offset;
    int fileLength = stream->FileObject->Status.RealSize;
    int rem = fileLength - currentOffset;

    if (toRead > rem)
        toRead = rem;

    int fd = stream->FileObject->Status.DataOffset;
    //sceLSeek(fd, currentOffset, SCE_SEEK_SET);

    int actuallyRead = sceRead(fd, outputPtr, toRead);

#if HOSTFS_PRINT && PRINT_HOSTFS_READS
    _print("FileDeviceRo::rawReadStream: fd=%d, req=%x, read=%x, offset=%x, data=%x\n", fd, toRead, actuallyRead, currentOffset, *(int*)outputPtr);
#endif

    // Update
    stream->State->Offset += actuallyRead;

    // Return number of bytes read. A few apis uses the return value
    return actuallyRead;
}

int HOOK_HostFs__PlayStation2_FileDeviceRo_closeStream(FileDeviceRo* device, FileInternalStream *stream)
{
    PDISTD_FileDevice_removeExpander(device, stream);
    if (stream->State)
    {
        if (stream->FileObject->FileMode == 1 && stream->State->field_0x08)
             ((void(*)(int, void*, int))0x51B478)(stream->State->field_0x00, stream->State->field_0x0C, 0x40 - stream->State->field_0x08);
        ((void(*)(int))0x51B4A8)(stream->State->field_0x00);
        UnitArenaBase_free((void*)0x885360, stream->State->field_0x0C);
        UnitArenaBase_free((void*)0x885340, stream->State);
        stream->State = NULL;
    }

#if HOSTFS_PRINT
        _print("FileDeviceRo::closeStream\n");
#endif

    if (stream->FileObject->Status.DataOffset == 0)
    {
        int res = sceClose(stream->FileObject->Status.DataOffset);
    }

    return 0;
}

// Not used
/*
void* HOOK_HostFs__PDISTD_FileInternalStream_ioctl(void* stream, void* command)
{
    if (*(int*)command == 1 || *(int*)command == 2)
        return 0;

    // This is used for some files that streams files over IOP memory using IRX code - ins, ads, pss movies
    // The strategy here is to recover some functions that are used whose's start were overwritten for a bit
    *(int*)ADDR_PlayStation2_FileDeviceRo2_readStat = 0x27BDFFC0;
    *((int*)ADDR_PlayStation2_FileDeviceRo2_readStat + 1) = 0xFFB00020;

    *(int*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry = 0x27BDFFB0;
    *((int*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry + 1) = 0xFFB20040;

    struct FileDeviceRo* device = (struct FileDeviceRo*)PDISTD_FileInternalStream_getDevice(stream);
    void* ret = device->VTable->IOControlStream(device, stream, command);

    HOOK(ADDR_PlayStation2_FileDeviceRo2_readStat, HOOK_HostFs__PlayStation2_FileDeviceRo2_readStat);
    HOOK(ADDR_PlayStation2_FileDeviceRo2_GetFileEntry, HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry);
    return ret;
}
*/

// called by PDISTD::FileInternalStream::ioctl
// not used for now - not easy to deal with and callers seems to want IOP memory only
/*
void* HOOK_HostFs__PlayStation2_FileDeviceRo_IOControlStream(struct FileDeviceRo* device, struct FileInternalStream* stream, void* command)
{
    // PSS Files: Passes to PDISTR.IRX through RPC (request id is 0x4D504731 (MPG1) and 0x4D504732 (MPG2)) - command 1?
    // ADS Files: Passes to PDISTR.IRX through RPC (request id is 0x5042474D (PBGM)) - command 1?

    // STRP Service Function callback: 0x2A48 (in PDISTR.IRX)
    int mode = *(int*)command;
    if (mode == 0)
    {
        // Get Stat? FileDeviceRo.pipe (?) is called
        // Refer to above comments for how certain files are handled
        struct IOControlStreamCommand0* cmd = (struct IOControlStreamCommand0*)command;

        // Briefly undo hook
        *(int*)ADDR_PlayStation2_FileDeviceRo2_readStat = 0x27BDFFC0;
        *((int*)ADDR_PlayStation2_FileDeviceRo2_readStat + 1) = 0xFFB00020;

        *(int*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry = 0x27BDFFB0;
        *((int*)ADDR_PlayStation2_FileDeviceRo2_GetFileEntry + 1) = 0xFFB20040;

        void* ret = PlayStation2_FileDeviceRo_pipe(device, command); // breaks stack not vtable call?

        HOOK(ADDR_PlayStation2_FileDeviceRo2_readStat, HOOK_HostFs__PlayStation2_FileDeviceRo2_readStat);
        HOOK(ADDR_PlayStation2_FileDeviceRo2_GetFileEntry, HOOK_HostFs__PlayStation2_FileDeviceRo2_GetFileEntry);

        return ret;
    }
    else if (mode == 1)
    {
        // Read (Passes to PDISTD.IRX with request id 0x53545250 (STRP)) with command 4, 2 arguments
        // Used by ins reading
        struct IOControlStreamCommand1* cmd = (struct IOControlStreamCommand1*)command;
        sceRead(stream->FileObject->DataOffset, cmd->Buffer, cmd->Size);
        return command;
    }
    else if (mode == 2)
    {
        // ? (Passes to PDISTD.IRX with request id 0x53545250 (STRP)) with command 5, 2 arguments
        // Used by ins reading
        struct IOControlStreamCommand2* cmd = (struct IOControlStreamCommand2*)command;

        return command;
    }
    else
    {
        // ? (Passes to PDISTD.IRX with request id 0x53545250 (STRP)) with command 9, 1 argument
        return 0;
    }

    return 0;
}
*/

bool IsStreamedFile(char* fileName)
{
    if (starts_with(fileName, "carsound/"))
        return true;

    char* ext = get_filename_ext(fileName);
    return ext != NULL && (!__strcmp(ext, "ins") || !__strcmp(ext, "ads") || !__strcmp(ext, "sqt") || !__strcmp(ext, "es") || !__strcmp(ext, "pss"));
}