#include <stdbool.h>
#include <stdio.h>

//#include "gt4\HostFs.h"

void init()
{
    HostFs_InstallHooks();   
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