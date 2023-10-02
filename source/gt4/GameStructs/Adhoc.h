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

typedef struct RefCounter_VT
{
  void* _dtor_;
  void (*dtor)();
  void* dtor2_;
  void (*dtor2)();
  void* cleanup_;
  void (*cleanup)();
  void* toString_;
  void (*toString)();
  void* rc_class_;
  void (*rc_class)();
  void* rc_size_;
  void (*rc_size)();
  void* weak_inc_;
  void (*weak_inc)();
  void* weak_dec_;
  void (*weak_dec)();
  void* weak_count_;
  void (*weak_count)();
} RefCounter_VT;

typedef struct RefCounter
{
  int dword0;
  RefCounter_VT* vtable;
} RefCounter;

typedef struct hObject_VT
{
  RefCounter_VT Base_VT;
  void* getObjectValue_;
  void (*getObjectValue)();
  void* deepCopy_;
  void (*deepCopy)();
  void* getClassID_;
  void (*getClassID)();
  void* c_str_;
  void (*c_str)();
  void* toInt_;
  void (*toInt)();
  void* toFloat_;
  void (*toFloat)();
  void* getElement_;
  void (*getElement)();
  void* getElementCount_;
  void (*getElementCount)();
  void* unk__;
  void (*unk_)();
  void* setElement_;
  void (*setElement)();
  void* copyPrimitive_;
  void (*copyPrimitive)();
  void* evaluate_;
  void (*evaluate)();
  void* assign_;
  void (*assign)();
  void* isValid_;
  void (*isValid)();
  void* call_;
  void (*call)();
  void* call2_;
  void (*call2)();
  void* op_add_;
  void (*op_add)();
  void* op_and_;
  void (*op_and)();
  void* op_andand_;
  void (*op_andand)();
  void* op_call_;
  void (*op_call)();
  void* op_div_;
  void (*op_div)();
  void* op_elem_;
  void (*op_elem)();
  void* op_eq_;
  void (*op_eq)();
  void* op_ge_;
  void (*op_ge)();
  void* op_gt_;
  void (*op_gt)();
  void* op_invert_;
  void (*op_invert)();
  void* op_le_;
  void (*op_le)();
  void* op_lshift_;
  void (*op_lshift)();
  void* op_lt_;
  void (*op_lt)();
  void* op_mod_;
  void (*op_mod)();
  void* op_mul_;
  void (*op_mul)();
  void* op_ne_;
  void (*op_ne)();
  void* op_not_;
  void (*op_not)();
  void* op_or_;
  void (*op_or)();
  void* op_oror_;
  void (*op_oror)();
  void* op_post_decr_;
  void (*op_post_decr)();
  void* op_post_incr_;
  void (*op_post_incr)();
  void* op_pow_;
  void (*op_pow)();
  void* op_pre_decr_;
  void (*op_pre_decr)();
  void* op_pre_incr_;
  void (*op_pre_incr)();
  void* op_rshift_;
  void (*op_rshift)();
  void* op_sub_;
  void (*op_sub)();
  void* op_uminus_;
  void (*op_uminus)();
  void* op_uplus_;
  void (*op_uplus)();
  void* op_xor_;
  void (*op_xor)();
} hObject_VT;

typedef struct hObject
{
  RefCounter RefCounter;
  int dword8;
  int dwordC;
} hObject;

typedef struct hModule_VT
{
  hObject_VT Base;
  void* setName_;
  void (*setName)();
  void* getModuleValue_;
  void (*getModuleValue)();
} hModule_VT;

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

// Reference Stuff
typedef struct RefPointer
{
  RefCounter* Counter;
} RefPointer;

typedef struct HObject
{
  RefPointer RefPointer;
} HObject;

typedef struct HInt
{
  HObject Object;
} HInt;