#include <stdbool.h>
#include <stdio.h>

#include "..\ps2\Memory.h"

#include "HOutput.h"

#include "GameFunctions/HOutput.h"
#include "GameFunctions/IO.h"

void HOutput_InstallHooks()
{
    HOOK_FUNC_ADDR(ADDR_HOutput_Handler, &HOOK_HOutput_Handler);
}

void HOOK_HOutput_Handler(char* text)
{
    _print(text);
}