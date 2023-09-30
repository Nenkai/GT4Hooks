#pragma once

typedef enum
{
  FileError_OK = 0x0,
  FileError_CANCEL = 0x1,
  FileError_NOTSUPPORT = 0x2,
  FileError_NOMEMORY = 0x3,
  FileError_NODEVICE = 0x4,
  FileError_IO = 0x5,
  FileError_DEVICEFULL = 0x6,
  FileError_READONLY = 0x7,
  FileError_NOTPERMITTED = 0x8,
  FileError_NOTFOUND = 0x9,
  FileError_ILLEGAL = 0xA,
} FileError;