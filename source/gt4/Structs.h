#pragma once

#include "Enums.h"

struct MemorySpace
{
    void* BufferPtr;
    int BufferSize;
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
  int Device;
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

struct UnitArena
{
    int field_0x00;
    int Offset;
    int field_0x08;
    void* UnkArena;
};

struct FileInternalStream
{
    int Status;
    struct FileObject* FileObject;
    int unk3;
    struct UnitArena State;
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