#include "Adhoc.h"

void (*HClassInit_HClassInit)(const struct HClassInit* this, const char* name, int size, HClassInit_Create_cb create, HClassInit_Init_cb init, HClassInit_Cleanup_cb cleanup) = (void*)ADDR_HClassInit_HClassInit;
struct hClass* (*HClassInit_CreateClass)() = (void*)ADDR_HClassInit_CreateClass;

void (*ADHOC_Deallocate)(void* pool, void *buffer, int size) = (void*)ADDR_ADHOC_Deallocate;
struct hClass* (*hObject_GetClassID)() = (void*)ADDR_hObject_GetClassID;
void (*hClass_setSuperClassID)(struct hClass* this, struct hClass* super) = (void*)ADDR_hClass_setSuperClassID;

void (*RefCounter_ref)(RefCounter* this) = (void*)ADDR_RefCounter_ref;
void (*RefCounter_unref)(RefCounter* this) = (void*)ADDR_RefCounter_unref;

// HInt
void (*HInt_HInt)(HInt* this, int value) = (void*)ADDR_HInt_HInt;
void (*HInt_dtor)(HInt* this, int flag) = (void*)ADDR_HInt_dtor;

void (*hModule_defineFunction)(void*, hModule* thisModule, char* functionName, Adhoc_function_cb function) = (void*)ADDR_hModule_defineFunction;