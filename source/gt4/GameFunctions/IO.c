#include "IO.h"

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