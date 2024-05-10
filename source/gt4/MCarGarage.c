#include "MCarGarage.h"

/* Hook: MCarGarage
   Purpose: Extends the MCarGarage built-in module.
            Adds getPerformanceIndex method to retrieve a car's performance index.
   How: Redirect hModule::defineFunction(..., ..., "sortByDisplacement", ...) to our hook, 
        which will register sortByDisplacement on its own along with our new stuff.
   Extra Note: This is a useful sample to view how to extend an existing built-in module.
*/

#define ADDR_MCarGarage_sortByDisplacement_register 0x132E60
void MCarGarage_InstallHooks()
{
    MAKE_JAL(ADDR_MCarGarage_sortByDisplacement_register, &HOOK_ExtendMCarGarage);
}

// NOTE: This function matches the signature for **function** registering
// If you are hooking into an attribute register function, make sure to adjust this function signature 
void HOOK_ExtendMCarGarage(void* tempHValue, hModule* module, char* name, Adhoc_function_cb func)
{
    // NOTE: This should be changed if you are hooking into a method (or something else)
    hModule_defineFunction(tempHValue, module, name, func);
    HValue_dtor(tempHValue, 2);

    hModule_defineMethod(&tempHValue, module, "getPerformanceIndex", &m_getPerformanceIndex);
    // No dtor call here, it'll be handled by parent function
}

void m_getPerformanceIndex(HObject* return_value, HObject* this_, int argc, hObject** argv)
{
    MCarGarage* garage;
    MCarGarage_MCarGarage(&garage, this_);

    CarGarage* car = mCarGarage_getCarGarage(garage);
    float perfIndex = QUICK_MENU_GetGTPerformanceIndex(car);

    HFloat* result;
    HFloat_HFloat(&result, perfIndex);
    ADHOC_MakeRef(return_value, (HObject*)result);

    HFloat_dtor(&result, 2);
    MCarGarage_dtor(&garage, 2);
}