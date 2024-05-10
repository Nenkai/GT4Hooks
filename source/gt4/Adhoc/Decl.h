#pragma once

#include "..\GameFunctions\Adhoc.h"

/* Defines a new module (for the header file) */
#define ADHOC_HEADER_MODULE(type_name) \
hClass* type_name##_getClassId(); \
void type_name##_Create_(); \
void type_name##_Init_(); \
void type_name##_CreateInit_(); \
void type_name##_InitClass(hClass* class);

/* Defines a new module (for the code file). */
#define ADHOC_START_MODULE(type_name, access_name) \
static const HClassInit type_name##_ClassInit_; \
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
    HClassInit_HClassInit(&type_name##_ClassInit_, #type_name, 0x10, type_name##_Create_, type_name##_Init_, type_name##_Cleanup_); \
} \
\
void type_name##_InitClass(hClass* class) \
{ /* std::basic_string boilerplate crap */ \
    STD_STRING(#access_name); \
    ((hModule_VT*)class->Module.Object.RefCounter.vtable)->setName(class, &unk); \
\
    void* v4 = (char*)unk - 16; \
    long long v5 = (long long)unk - 16; \
    long long v6 = *((int *)unk - 2) - 1; \
    *((int *)unk - 2) = v6; \
    if (!v6) \
        ADHOC_Deallocate(v5, *((int *)v4 + 1) + 16, 4LL);

#define ADHOC_END_MODULE() }

/* Defines a new adhoc function. */
#define ADHOC_DEFINE_FUNCTION(class, func_name, func) \
    hModule_defineFunction(unk, &class->Module, func_name, func);

/* Defines a new adhoc method */
#define ADHOC_DEFINE_METHOD(class, method_name, method) \
    hModule_defineMethod(unk, &class->Module, method_name, method);

/* Defines a new adhoc function. */
#define ADHOC_DEFINE_ATTRIBUTE(class, attribute_name, getter, setter) \
    hModule_defineAttibute(unk, &class->Module, attribute_name, getter, setter);

/** Copies the reference of a object handle to another. */
void ADHOC_MakeRef(HObject* target, HObject* source);
