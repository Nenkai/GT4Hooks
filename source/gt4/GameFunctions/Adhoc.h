#pragma once

#include "..\GameStructs\Adhoc.h"

#define ADDR_HClassInit_HClassInit 0x4E2940
#define ADDR_HClassInit_CreateClass 0x4E28C8

#define ADDR_ADHOC_Deallocate 0x508B58

#define ADDR_hObject_GetClassID 0x4F33E8
#define ADDR_hClass_setSuperClassID 0x4E27B8

typedef void (*HClassInit_Create_cb)();
typedef void (*HClassInit_Init_cb)();
typedef void (*HClassInit_Cleanup_cb)();

extern void (*HClassInit_HClassInit)(const struct HClassInit* this, int name, int size, HClassInit_Create_cb create, HClassInit_Init_cb init, HClassInit_Cleanup_cb cleanup);
extern struct hClass* (*HClassInit_CreateClass)();

extern void (*ADHOC_Deallocate)(void* pool, void *buffer, int size);
extern struct hClass* (*hObject_GetClassID)();
extern void (*hClass_setSuperClassID)(struct hClass* this, struct hClass* super); 