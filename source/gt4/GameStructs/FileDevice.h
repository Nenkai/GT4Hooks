#pragma once

#include "../Enums/Enums.h"

struct UnitArena
{
    int field_0x00;
    int Offset;
    int field_0x08;
    void* field_0x0C;
};

struct FileStatus
{
    FileError Status;
    int Compressed;
    int RealSize;
    int CompressedSize;
    char* Buffer;
    int DataOffset;
};

struct FileObject
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    struct FileDeviceRo* Device;
    int ListElement;
    int field_40;
    int field_44;
    /* ID of the name as a handle */
    int FileNameHandle;
    int Stream;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int FileMode;
    int field_78;
    int field_7C;
    int field_80;
    struct FileStatus Status;
    int field_9C;
    int field_A0;
    int DataOffset;
    int VTable;
};

struct MemorySpace
{
    void* BufferPtr;
    int BufferSize;
};

////////////////////////////////////////////////
// Streams
///////////////////////////////////////////////
struct FileInternalStream
{
    int Status;
    struct FileObject* FileObject;
    int unk3;
    struct UnitArena* State;
    int field_0x10;
    int field_0x14;
    int DefaultCallback;
    int field_0x1C;
    int vtable;
};

struct FileInternalStreamDefault
{
    struct FileInternalStream Base;
    int unk;
    unsigned long long CurrentOffset;
    struct MemorySpace MemSpace;
    int field_0x38;
};

////////////////////////////////////////////////
// FileDeviceRo specifics
///////////////////////////////////////////////
struct VolumeEntryTypeInfo
{
  int Status;
  int NodeID;
  int PageOffset;
  int field_C;
  long long ModifiedDate;
  int CompressedSize;
  int RealSize;
  char EntryType;
};

struct PageManager
{
  void* vtable;
  char *HeaderBuffer;
  int field_8;
  int RoInflator;
  struct Unk
  {
    int a;
    int b;
    int c;
    int d;
    int e;
  } field_0x10;
};

////////////////////////////////////////
// File Devices
////////////////////////////////////////
struct FileDevice;

typedef void* (*IOControlStream_cb)(void *, struct FileInternalStream*, void*);
typedef void* (*readStat_cb)(struct FileStatus*, struct FileDevice*, struct FileObject*);
typedef int (*getCdOffsetFromDataOffset_cb)(struct FileDeviceRo*, char*, int, int);
typedef int (*rawReadStream_cb)(struct FileDevice*, struct FileInternalStream*, struct MemorySpace*);

struct FileDevice
{
    char fields[0xA4];
    struct FileDeviceVT
    {
        char fields[0x9C];
        rawReadStream_cb rawReadStream;
        void* field_A0;
        void* readStream;
        void* field_A8;
        void* seekStream;
        void* field_B0;
        void* tellStream;
        void* field_B8;
        void* writeStream;
        void* field_C0;
        IOControlStream_cb IOControlStream;
        void* field_C8;
        readStat_cb readStat;
        void* field_D0;
        getCdOffsetFromDataOffset_cb getCdOffsetFromDataOffset;
    } *VTable;
};

struct FileDevicePipe
{
    struct FileDevice Base;
    int field_0xA8;
    int MountPath;
};

struct FileDeviceRo
{
    struct FileDevicePipe Pipe;
    int UnkBool;
    char* VolPath;
    int TocOffset;
    int TocPageOffset;
};

struct FileDeviceRo2
{
    struct FileDeviceRo Ro;
    int field_0xC0;
    struct PageManager PageManager;
    int CustomPageOffset;
    int TopFileDevice;
    struct FileDeviceRo2 *PtrToSelf;
};

/////////////////////////////////
// IOCTL
/////////////////////////////////
struct IOControlStreamCommand0
{
    int Mode;
    char padding[0x0C];
};

struct IOControlStreamCommand1
{
    int Mode;
    void* Buffer;
    int Size;
    int Unused;
};

struct IOControlStreamCommand2
{
    int Mode;
    void* UnkPtr;
    int Size;
    int Unused;
};