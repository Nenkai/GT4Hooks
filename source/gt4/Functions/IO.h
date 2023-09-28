#pragma once

#include "..\SceStructs.h"

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


void (*_sprintf)(char* dest, const char* format, ...) = (void*)ADDR_sprintf;
void (*_print)(const char* format, ...) = (void*)ADDR_print;

int (*sceOpen)(const char* name, int flags) = (void*)ADDR_sceOpen;
int (*sceClose)(int fd) = (void*)ADDR_sceClose;
int (*sceRead)(int fd, void* buf, int count) = (void*)ADDR_sceRead;
int (*sceLSeek)(int fd, int offset, int whence) = (void*)ADDR_sceLSeek;
int (*sceGetStat)(const char* name, struct sce_stat *buf) = (void*)ADDR_sceGetStat;
int (*sceStdioConvertError)(int func, int ioerror) = (void*)ADDR_sceStdioConvertError;

char* (*PlaystationX_LockFileName)(unsigned int nameHandle) = (void*)ADDR_PlaystationX_LockFileName;
void (*PlayStationX_UnlockFileName)(unsigned int nameHandle) = (void*)ADDR_PlayStationX_UnlockFileName;

