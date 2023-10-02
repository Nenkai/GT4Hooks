#include "Adhoc\MMyModule.h"
#include "GameFunctions\IO.h"

#include "..\ps2\Memory.h"

void (*funcs[])() = {
    // Add modules constructor functions here.
    mMyModule_CreateInit_,
};

/* Hook: Adhoc
   Purpose: Adds new adhoc modules.
   How: Creates brand new class inits, class definitions.
   Note: Not done yet, see TODO below.
*/

void ADHOC_InjectNewModules()
{
    // Base modules are always added in engine, new modules needs to be added
    // though InitializeAdhocMenu, init_menu and init_gt4app callbacks to hADHOC::addModuleHandle
    // TODO: Fix this rather than hijack mUsedCar::getClassID call
    MAKE_JAL(0x121B50, &mMyModule_getClassId);

    int num = sizeof(funcs) / sizeof(funcs[0]);

    for (int i = 0; i < num; i++)
        funcs[i]();
}