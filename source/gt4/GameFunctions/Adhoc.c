#include "Adhoc.h"

void (*HClassInit_HClassInit)(const struct HClassInit* this, const char* name, int size, HClassInit_Create_cb create, HClassInit_Init_cb init, HClassInit_Cleanup_cb cleanup) = (void*)ADDR_HClassInit_HClassInit;
struct hClass* (*HClassInit_CreateClass)() = (void*)ADDR_HClassInit_CreateClass;

void (*ADHOC_Deallocate)(void* pool, void *buffer, int size) = (void*)ADDR_ADHOC_Deallocate;
struct hClass* (*hObject_GetClassID)() = (void*)ADDR_hObject_GetClassID;
void (*hClass_setSuperClassID)(struct hClass* this, struct hClass* super) = (void*)ADDR_hClass_setSuperClassID;

void (*RefCounter_ref)(RefCounter* this) = (void*)ADDR_RefCounter_ref;
void (*RefCounter_unref)(RefCounter* this) = (void*)ADDR_RefCounter_unref;

// HValue
void (*HValue_dtor)(void* this, int flag) = (void*)ADDR_HValue_dtor;

// HInt
void (*HInt_HInt)(HInt* this, int value) = (void*)ADDR_HInt_HInt;
void (*HInt_dtor)(HInt* this, int flag) = (void*)ADDR_HInt_dtor;

// HFloat
void (*HFloat_HFloat)(HFloat* this, float value) = (void*)ADDR_HFloat_HFloat;
void (*HFloat_dtor)(HFloat* this, int flag) = (void*)ADDR_HFloat_dtor;

// hModule
void (*hModule_defineFunction)(void*, hModule* thisModule, char* functionName, Adhoc_function_cb function) = (void*)ADDR_hModule_defineFunction;
void (*hModule_defineMethod)(void*, hModule* thisModule, char* methodName, Adhoc_method_cb method) = (void*)ADDR_hModule_defineMethod;
void (*hModule_defineStatic)(void*, hModule* thisModule, char* staticName, HObject* value) = (void*)ADDR_hModule_defineStatic;
void (*hModule_defineAttribute)(void*, hModule* thisModule, char* attributeName, Adhoc_attribute_cb getter, Adhoc_attribute_cb setter) = (void*)ADDR_hModule_defineAttribute;
void (*hModule_defineClass)(void*, hModule* previous, hModule* classId) = (void*)ADDR_hModule_defineClass;