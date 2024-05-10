#pragma once

#include "../GameStructs/FontManagerClass.h"

#define ADDR__PDISTD_FontManagerClass_putstring 0x33B740
#define ADDR__PDISTD_FontManagerClass_setRegion 0x33B418
#define ADDR__PDISTD_FontManagerClass_setFont 0x33AF90
#define ADDR__PDISTD_FontManagerClass_printf 0x33B6B0

extern void (*PDISTD_FontManagerClass_putstring)(FontManagerClass* manager, char* str);
extern void (*PDISTD_FontManagerClass_printf)(FontManagerClass* manager, char* str, ...);
extern void (*PDISTD_FontManagerClass_setRegion)(FontManagerClass* manager, int x, int y, int w, int h);
extern void (*PDISTD_FontManagerClass_setFont)(FontManagerClass* manager, char* fontName);