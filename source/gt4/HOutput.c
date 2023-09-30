#include <stdbool.h>
#include <stdio.h>

#include "..\ps2\Memory.h"

#include "HOutput.h"

#include "GameFunctions/HOutput.h"
#include "GameFunctions/IO.h"

void HOutput_InstallHooks()
{
    HOOK_FUNC_ADDR(ADDR_HOutput_Handler, &HOOK_HOutput_Handler);

    // Fix stubbed loggers
    //HOOK(ADDR_ADHOC_debug, (void*)ADDR_print); // Spammy
    HOOK(ADDR_ADHOC_printf, ADDR_print);
}

void HOOK_HOutput_Handler(char* text)
{
    _print(text);
}