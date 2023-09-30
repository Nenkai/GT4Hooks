#pragma once

#include "GameStructs\Adhoc.h"

void ADHOC_RegisterModules();

void mNewModule_Create();
void mNewModule_Init();
void mNewModule_Cleanup();

void mNewModule_InitClass(hClass* class);

void mNewModule__f_CRC32(void* a1, int argc, hObject** argv);
