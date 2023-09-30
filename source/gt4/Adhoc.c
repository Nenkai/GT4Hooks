#include <stdio.h>

#include "..\ps2\Memory.h"

#include "Adhoc.h"

#include "GameFunctions\String.h"
#include "GameFunctions\Adhoc.h"

static const HClassInit mNewModule;
static hClass* ClassID_ = NULL;

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

hClass* mNewModule_getClassId()
{
    return ClassID_;
}

void ADHOC_RegisterModules()
{
    HClassInit_HClassInit(&mNewModule, "mMyModule", 0x10, mNewModule_Create, mNewModule_Init, mNewModule_Cleanup);

    // Base modules are always added in engine, new modules needs to be added
    // though InitializeAdhocMenu, init_menu and init_gt4app callbacks to hADHOC::addModuleHandle
    MAKE_JAL(0x121B50, &mNewModule_getClassId);
}

void mNewModule_Create()
{
    ClassID_ = HClassInit_CreateClass();
}

void mNewModule_Init()
{
    mNewModule_InitClass(ClassID_);
}

void mNewModule_Cleanup()
{
    ClassID_ = NULL;
}

void mNewModule_InitClass(hClass* class)
{
    STD_STRING("MMyModule");
    ((void(*)(void*, void*))(*(int*)(class->Module.Object.RefCounter.vtable + 0x1B4)))(class, (unsigned int)&unk); // hModule::setName

    char* v4 = (char*)unk - 16;
    long long v5 = (long long)unk - 16;
    long long v6 = *((int *)unk - 2) - 1;
    *((int *)unk - 2) = v6;
    if (!v6)
        ADHOC_Deallocate(v5, *((int *)v4 + 1) + 16, 4LL);

    struct hClass* super = hObject_GetClassID();
    hClass_setSuperClassID(class, super);

    // Fun begins here :)
    hModule_defineFunction(unk, &class->Module, "Literally1984", &mNewModule__f_CRC32);
}

void mNewModule__f_CRC32(void* a1, int argc, hObject** argv)
{
    void* hInt;
    HInt_HInt((unsigned int)&hInt, 1984);

    void* v2 = hInt;
    if (a1 != (unsigned int)&hInt)
    {
        if (hInt)
            RefCounter_ref((int)hInt);

        if (*((int*)a1))
            RefCounter_unref(*(int *)a1);

        *(int *)a1 = v2;
    }

    HInt_dtor(&hInt, 2);
}
