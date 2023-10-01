#include <stdio.h>

#include "MMyModule.h"

void mMyModule__f_CRC32(void* a1, int argc, hObject** argv)
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

ADHOC_START_MODULE(mMyModule, MMyModule)
{
    // This module is a parent of the base object
    struct hClass* super = hObject_GetClassID();
    hClass_setSuperClassID(class, super);

    // Fun begins here :)
}
ADHOC_END_MODULE()

/*
// Base modules are always added in engine, new modules needs to be added
// though InitializeAdhocMenu, init_menu and init_gt4app callbacks to hADHOC::addModuleHandle
MAKE_JAL(0x121B50, &mNewModule_getClassId);
*/
