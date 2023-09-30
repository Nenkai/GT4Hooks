#pragma once

struct HClassInit
{
    char* ModuleName;
    void* Create_cb;
    void* Init_cb;
    void* Cleanup_cb;
    struct HClassInit* Previous;
};

struct RefCounter
{
  int dword0;
  void* vtable;
};

struct hObject
{
  struct RefCounter RefCounter;
  int dword8;
  int dwordC;
};

struct hModule
{
  struct hObject Object;
  long long qword10;
  char gap18[4];
  int int1C;
  int dword20;
  char byte24;
  int dword28;
};

struct hClass
{
  struct hModule Module;
  int dword2C;
};