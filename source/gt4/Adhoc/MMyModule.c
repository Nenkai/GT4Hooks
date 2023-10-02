#include <stdio.h>

#include "MMyModule.h"

// Declares a module named "MMyModule", which its type name is "mMyModule"
ADHOC_START_MODULE(mMyModule, MMyModule)
{
    // This module is a parent of the base object
    struct hClass* super = hObject_GetClassID();
    hClass_setSuperClassID(class, super);

    // Define functions, statics, etc, here
    ADHOC_DEFINE_FUNCTION(class, "GetHookSTDCVersion", &f_GetHookSTDCVersion); // TODO cleanup value
    // ADHOC_DEFINE_ATTRIBUTE(class, "my_attribute", &m_getMyAttribute, &m_setMyAttribute)
}
ADHOC_END_MODULE()

void f_GetHookSTDCVersion(HObject* return_value, int argc, hObject** argv)
{
    HInt* hInt;
    HInt_HInt(&hInt, __STDC_VERSION__);

    // Set return value
    ADHOC_MakeRef(return_value, (HObject*)hInt);

    // Clean up HInt
    HInt_dtor(&hInt, 2);
}
