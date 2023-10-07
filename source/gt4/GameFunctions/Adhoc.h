#pragma once

#include "..\GameStructs\Adhoc.h"

#define ADDR_HClassInit_HClassInit 0x4E2940
#define ADDR_HClassInit_CreateClass 0x4E28C8

#define ADDR_HInt_HInt 0x4E9B00
#define ADDR_HInt_dtor 0x4E7FD8

#define ADDR_HFloat_HFloat 0x4E6468
#define ADDR_HFloat_dtor 0x4E4B98

#define ADDR_HValue_dtor 0x5071C8

#define ADDR_ADHOC_Deallocate 0x508B58

#define ADDR_hObject_GetClassID 0x4F33E8

#define ADDR_hClass_setSuperClassID 0x4E27B8

#define ADDR_RefCounter_ref 0x50C0D0
#define ADDR_RefCounter_unref 0x50C138

#define ADDR_hModule_defineFunction 0x4F0650
#define ADDR_hModule_defineMethod 0x4F0B10
#define ADDR_hModule_defineStatic 0x4F0830
#define ADDR_hModule_defineAttribute 0x4F0C00
#define ADDR_hModule_defineClass 0x4EFC00

// Ref counter
extern void (*RefCounter_ref)(RefCounter* this);
extern void (*RefCounter_unref)(RefCounter* this);

// HValue
extern void (*HValue_dtor)(void* this, int flag);;

// HInt
extern void (*HInt_HInt)(HInt* this, int value);
extern void (*HInt_dtor)(HInt* this, int flag);

// HFloat
extern void (*HFloat_HFloat)(HFloat* this, float value);
extern void (*HFloat_dtor)(HFloat* this, int flag);

// ADHOC
extern void (*ADHOC_Deallocate)(void* pool, void *buffer, int size);

// HClassInit
typedef void (*HClassInit_Create_cb)();
typedef void (*HClassInit_Init_cb)();
typedef void (*HClassInit_Cleanup_cb)();
extern void (*HClassInit_HClassInit)(const HClassInit* this, const char* name, int size, HClassInit_Create_cb create, HClassInit_Init_cb init, HClassInit_Cleanup_cb cleanup);
extern struct hClass* (*HClassInit_CreateClass)();

// hClass
extern void (*hClass_setSuperClassID)(hClass* this, hClass* super); 

// hObject
extern struct hClass* (*hObject_GetClassID)();

// hModule
/* Adhoc function callback handler */
typedef void (*Adhoc_function_cb)(HObject* return_value, int argc, hObject** argv);

/* Defines a new adhoc function in this module. */
extern void (*hModule_defineFunction)(void*, hModule* thisModule, char* functionName, Adhoc_function_cb function);

/* Adhoc method callback handler */
typedef void (*Adhoc_method_cb)(HObject* return_value, HObject* this, int argc, hObject** argv);

/* Defines a new adhoc method in this module. */
extern void (*hModule_defineMethod)(void*, hModule* thisModule, char* methodName, Adhoc_method_cb method);

/* Defines a new adhoc static member (i.e constants). */
extern void (*hModule_defineStatic)(void*, hModule* thisModule, char* staticName, HObject* value);

/* Adhoc attrubute callback handler */
typedef void (*Adhoc_attribute_cb)(HObject* return_value, HObject* this, HObject* unk, int argc, hObject** argv);
extern void (*hModule_defineAttibute)(void*, hModule* thisModule, char* attributeName, Adhoc_attribute_cb getter, Adhoc_attribute_cb setter);

extern void (*hModule_defineClass)(void*, hModule* previous, hModule* classId);
