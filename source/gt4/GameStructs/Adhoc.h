#pragma once

typedef struct HClassInit HClassInit;
typedef struct HClassInit
{
    char* ModuleName;
    void* Create_cb;
    void* Init_cb;
    void* Cleanup_cb;
    HClassInit* Previous;
} HClassInit;

typedef struct RefCounter
{
  int dword0;
  void* vtable;
} RefCounter;

typedef struct hObject
{
  RefCounter RefCounter;
  int dword8;
  int dwordC;
} hObject;

typedef struct hModule
{
  hObject Object;
  long long qword10;
  char gap18[4];
  int int1C;
  int dword20;
  char byte24;
  int dword28;
} hModule;

typedef struct hClass
{
  hModule Module;
  int dword2C;
} hClass;

// Numeric
typedef struct hInt
{
  hObject Object;
  int Value;
} hInt;

typedef struct HInt
{
  void* aa;
} HInt;