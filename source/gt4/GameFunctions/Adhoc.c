#include "Adhoc.h"

void (*HClassInit_HClassInit)(const struct HClassInit* this, int name, int size, HClassInit_Create_cb create, HClassInit_Init_cb init, HClassInit_Cleanup_cb cleanup) = (void*)ADDR_HClassInit_HClassInit;
struct hClass* (*HClassInit_CreateClass)() = (void*)ADDR_HClassInit_CreateClass;

void (*ADHOC_Deallocate)(void* pool, void *buffer, int size) = (void*)ADDR_ADHOC_Deallocate;
struct hClass* (*hObject_GetClassID)() = (void*)ADDR_hObject_GetClassID;
void (*hClass_setSuperClassID)(struct hClass* this, struct hClass* super) = (void*)ADDR_hClass_setSuperClassID;