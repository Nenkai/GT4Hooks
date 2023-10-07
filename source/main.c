#include <stdbool.h>
#include <stdio.h>

#include "gt4\HostFs.h"
#include "gt4\HOutput.h"
#include "gt4\CameraSys.h"
#include "gt4\Adhoc.h"
#include "gt4\MStorage.h"
#include "gt4\MCarGarage.h"

#include "gt4\GameFunctions\IO.h"
#include "ps2\Memory.h"

void init()
{
    // See: makefile comment for base address. clear memset so that it doesn't override our code
    NOP(0x5225F0);

    HostFs_InstallHooks();
    HOutput_InstallHooks();
    CameraSys_InstallHooks();
    ADHOC_InjectNewModules();
    MStorage_InstallHooks();
    MCarGarage_InstallHooks();
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