#include <stdbool.h>

#include "gt4\HostFs.h"

void init()
{
    HostFs_InstallHooks();   
}

void INVOKER()
{
    asm("ei\n");
    asm("addiu $ra, -4\n");

    init();
}

int main()
{
    return 0;
}