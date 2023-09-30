#pragma once

#include "..\GameStructs\Adhoc.h"

#define ADDR_HClassInit_HClassInit 0x4E2940
#define ADDR_HClassInit_CreateClass 0x4E28C8

#define ADDR_HInt_HInt 0x4E9B00
#define ADDR_HInt_dtor 0x4E7FD8

#define ADDR_ADHOC_Deallocate 0x508B58

#define ADDR_hObject_GetClassID 0x4F33E8

#define ADDR_hClass_setSuperClassID 0x4E27B8

#define ADDR_RefCounter_ref 0x50C0D0
#define ADDR_RefCounter_unref 0x50C138

#define ADDR_hModule_defineFunction 0x4F0650

// Ref counter
extern void (*RefCounter_ref)(RefCounter* this);
extern void (*RefCounter_unref)(RefCounter* this);

// HInt
extern void (*HInt_HInt)(HInt* this, int value);
extern void (*HInt_dtor)(HInt* this, int flag);

extern void (*ADHOC_Deallocate)(void* pool, void *buffer, int size);

typedef void (*HClassInit_Create_cb)();
typedef void (*HClassInit_Init_cb)();
typedef void (*HClassInit_Cleanup_cb)();

extern void (*HClassInit_HClassInit)(const HClassInit* this, const char* name, int size, HClassInit_Create_cb create, HClassInit_Init_cb init, HClassInit_Cleanup_cb cleanup);
extern struct hClass* (*HClassInit_CreateClass)();

extern struct hClass* (*hObject_GetClassID)();

extern void (*hClass_setSuperClassID)(hClass* this, hClass* super); 

typedef void (*Adhoc_function_cb)(void*, int argc, hObject** argv);
extern void (*hModule_defineFunction)(void*, hModule* thisModule, char* functionName, Adhoc_function_cb function);