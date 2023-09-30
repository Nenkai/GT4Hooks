#pragma once

#include "..\GameStructs\SceStructs.h"

#define ADDR_sprintf 0x50F1D8
#define ADDR_print 0x50F120

#define ADDR_sceOpen 0x5DF338
#define ADDR_sceClose 0x5DF5C8
#define ADDR_sceRead 0x5DF980
#define ADDR_sceGetStat 0x5E0F20
#define ADDR_sceStdioConvertError 0x5E5AF0
#define ADDR_sceLSeek 0x5DF740

#define ADDR_PlaystationX_LockFileName 0x467060
#define ADDR_PlayStationX_UnlockFileName 0x467080

extern void (*_sprintf)(char* dest, const char* format, ...);
extern void (*_print)(const char* format, ...);

extern int (*sceOpen)(const char* name, int flags);
extern int (*sceClose)(int fd);
extern int (*sceRead)(int fd, void* buf, int count);
extern int (*sceLSeek)(int fd, int offset, int whence);
extern int (*sceGetStat)(const char* name, struct sce_stat *buf);
extern int (*sceStdioConvertError)(int func, int ioerror);

extern char* (*PlaystationX_LockFileName)(unsigned int nameHandle);
extern void (*PlayStationX_UnlockFileName)(unsigned int nameHandle);
