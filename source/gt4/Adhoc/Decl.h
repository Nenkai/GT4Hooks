#pragma once

#include "..\GameFunctions\Adhoc.h"

#define ADHOC_MODULE_HEADER(type_name) \
hClass* type_name##_getClassId(); \
void type_name##_Create_(); \
void type_name##_Init_(); \
void type_name##_CreateInit_(); \
void type_name##_InitClass(hClass* class);

#define ADHOC_START_MODULE(type_name, access_name) \
\
static const HClassInit type_name##ClassInit_; \
static hClass* type_name##_ClassID_ = NULL; \
\
hClass* type_name##_getClassId() \
{ \
    return type_name##_ClassID_; \
} \
\
void type_name##_Create_() \
{ \
    type_name##_ClassID_ = HClassInit_CreateClass(); \
} \
\
void type_name##_Init_() \
{ \
    type_name##_InitClass(type_name##_ClassID_); \
} \
\
void type_name##_Cleanup_() \
{ \
    type_name##_ClassID_ = NULL; \
} \
\
void type_name##_CreateInit_() \
{ \
    HClassInit_HClassInit(&type_name##ClassInit_, #type_name, 0x10, type_name##_Create_, type_name##_Init_, type_name##_Cleanup_); \
} \
\
void type_name##_InitClass(hClass* class) \
{ \
    STD_STRING(#access_name); \
    ((void(*)(void*, void*))(*((int*)(class->Module.Object.RefCounter.vtable) + 0x1B4)))(class, (unsigned int)&unk); \
\
    char* v4 = (char*)unk - 16; \
    long long v5 = (long long)unk - 16; \
    long long v6 = *((int *)unk - 2) - 1; \
    *((int *)unk - 2) = v6; \
    if (!v6) \
        ADHOC_Deallocate(v5, *((int *)v4 + 1) + 16, 4LL);

#define ADHOC_END_MODULE() }

#define ADHOC_FUNCTION(class, name) \
    hModule_defineFunction(unk, &class->Module, #name, &mMyModule__f_##name);