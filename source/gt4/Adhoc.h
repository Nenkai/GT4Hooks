#pragma once

#include "GameStructs\Adhoc.h"
#include "GameFunctions\String.h"

void ADHOC_InjectNewModules();
void  HOOK_defineMoreClasses(void* value, hClass* previous, hClass* classId);

// std::basic_string shit
#define STD_STRING_BOILERPLATE(name) \
    void* unk; \
    int* v2 = (void*)0x6A4178; \
    if (*(int*)0x6A4174) \
        v2 = ((int(*)(void*))(0x5EEB00))((int*)0x6A4168); \
    else \
        ++(*((int*)0x6A4170)); \
    unk = (void*)v2;

#define STD_STRING(name) \
    STD_STRING_BOILERPLATE(); \
    int len = __strlen(name); \
    ((void(*)(void*, int, long long, char*, int))0x5EEBC0)(&unk, 0, -1, name, len);