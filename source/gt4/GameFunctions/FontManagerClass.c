#include <stdio.h>

#include "FontManagerClass.h"

void (*PDISTD_FontManagerClass_putstring)(FontManagerClass*, char*) = (void*)ADDR__PDISTD_FontManagerClass_putstring;
void (*PDISTD_FontManagerClass_printf)(FontManagerClass*, char*, ...) = (void*)ADDR__PDISTD_FontManagerClass_printf;
void (*PDISTD_FontManagerClass_setRegion)(FontManagerClass*, int, int, int, int) = (void*)ADDR__PDISTD_FontManagerClass_setRegion;
void (*PDISTD_FontManagerClass_setFont)(FontManagerClass*, char*) = (void*)ADDR__PDISTD_FontManagerClass_setFont;