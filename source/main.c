#include <stdbool.h>
#include <stdio.h>

#include "gt4\HostFs.h"
#include "gt4\HOutput.h"
#include "gt4\CameraSys.h"
#include "gt4\Adhoc.h"

#include "gt4\GameFunctions\IO.h"

void init()
{
    HostFs_InstallHooks();
    HOutput_InstallHooks();
    //CameraSys_InstallHooks();
    //ADHOC_InjectNewModules();
}

void __attribute__((optimize("O3"))) INVOKER()
{
    asm("ei\n");
    asm("addiu $ra, -4\n");

    init();
}

int main()
{
    return 0;
}