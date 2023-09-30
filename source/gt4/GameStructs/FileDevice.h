#pragma once

#include "../Enums/Enums.h"

typedef struct UnitArena
{
    int field_0x00;
    int Offset;
    int field_0x08;
    void* field_0x0C;
} UnitArena;

typedef struct FileStatus
{
    FileError Status;
    int Compressed;
    int RealSize;
    int CompressedSize;
    char* Buffer;
    int DataOffset;
} FileStatus;

typedef struct FileDeviceRo FileDeviceRo;

typedef struct FileObject
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
    FileDeviceRo* Device;
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
    FileStatus Status;
    int field_9C;
    int field_A0;
    int DataOffset;
    int VTable;
} FileObject;

typedef struct MemorySpace
{
    void* BufferPtr;
    int BufferSize;
} MemorySpace;

////////////////////////////////////////////////
// Streams
///////////////////////////////////////////////
typedef struct FileInternalStream
{
    int Status;
    FileObject* FileObject;
    int unk3;
    UnitArena* State;
    int field_0x10;
    int field_0x14;
    int DefaultCallback;
    int field_0x1C;
    int vtable;
} FileInternalStream;

typedef struct FileInternalStreamDefault
{
    FileInternalStream Base;
    int unk;
    unsigned long long CurrentOffset;
    MemorySpace MemSpace;
    int field_0x38;
} FileInternalStreamDefault;

////////////////////////////////////////////////
// FileDeviceRo specifics
///////////////////////////////////////////////
typedef struct VolumeEntryTypeInfo
{
  int Status;
  int NodeID;
  int PageOffset;
  int field_C;
  long long ModifiedDate;
  int CompressedSize;
  int RealSize;
  char EntryType;
} VolumeEntryTypeInfo;

typedef struct PageManagerUnk
{
  int a;
  int b;
  int c;
  int d;
  int e;
} PageManagerUnk;

typedef struct PageManager
{
  void* vtable;
  char *HeaderBuffer;
  int field_8;
  int RoInflator;
  PageManagerUnk field_0x10;
} PageManager;

////////////////////////////////////////
// File Devices
////////////////////////////////////////
typedef struct FileDevice FileDevice;

typedef void* (*IOControlStream_cb)(void *, FileInternalStream*, void*);
typedef void* (*readStat_cb)(FileStatus*, FileDevice*, FileObject*);
typedef int (*getCdOffsetFromDataOffset_cb)(FileDeviceRo*, char*, int, int);
typedef int (*rawReadStream_cb)(FileDevice*, FileInternalStream*, MemorySpace*);

typedef struct FileDeviceVT
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
} FileDeviceVT;

typedef struct FileDevice
{
    char fields[0xA4];
    FileDeviceVT *VTable;
} FileDevice;

typedef struct FileDevicePipe
{
    FileDevice Base;
    int field_0xA8;
    int MountPath;
} FileDevicePipe;

typedef struct FileDeviceRo
{
    FileDevicePipe Pipe;
    int UnkBool;
    char* VolPath;
    int TocOffset;
    int TocPageOffset;
} FileDeviceRo;

typedef struct FileDeviceRo2
{
    struct FileDeviceRo Ro;
    int field_0xC0;
    PageManager PageManager;
    int CustomPageOffset;
    int TopFileDevice;
    void *PtrToSelf;
} FileDeviceRo2;

/////////////////////////////////
// IOCTL
/////////////////////////////////
typedef struct IOControlStreamCommand0
{
    int Mode;
    char padding[0x0C];
} IOControlStreamCommand0;

typedef struct IOControlStreamCommand1
{
    int Mode;
    void* Buffer;
    int Size;
    int Unused;
} IOControlStreamCommand1;

typedef struct IOControlStreamCommand2
{
    int Mode;
    void* UnkPtr;
    int Size;
    int Unused;
} IOControlStreamCommand2;