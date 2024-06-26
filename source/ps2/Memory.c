#include "Memory.h"

void MAKE_JAL(unsigned int addr, void* func)
{
	*(int*)addr = ((0x0C000000 | (((unsigned int)func & 0x0fffffff) >> 2)));
}

void PATCH_INT(unsigned int addr, int data)
{
	*(int*)(addr) = data;
}

void PATCH_FLOAT(unsigned int addr, float data)
{
	*(float*)(addr) = data;
}

void MAKE_JMP(unsigned int addr, void* func)
{
	*(int*)addr = (0x08000000 | (((unsigned int)(func) & 0x0FFFFFFC) >> 2));
}

void NOP(unsigned int addr)
{
	PATCH_INT(addr, 0);
}

void PATCH_SHORT(unsigned int addr, short data)
{
	*(short*)(addr) = data;
}

void HOOK_FUNC_ADDR(void* func_start_addr, void* func)
{
    *((int*)func_start_addr) = (int)func;
}

void HOOK(unsigned int func_start_addr, void* func)
{
    MAKE_JMP(func_start_addr, func);
    NOP(func_start_addr + 4); // Avoid cases where branch delay slot screw the stack up
}

/*
typedef struct Hook
{
	void* OrigFuncAddress;
	void* NewFuncAddress;
	unsigned int HookLength;
	unsigned int OriginalBytes[];
} Hook;

Hook HOOKS_Create(unsigned int addr, void* func)
{
	Hook hook =
	{
		.Address = addr,
		.NewFunc = func,
		.HookLength = 4,
		.OriginalBytes = *(int*)addr
	};

	MAKE_JAL(addr, func);
}

void HOOKS_CallOriginal(Hook* hook)
{
	for (int i = 0; i < hook->HookLength / 4; i++)
		*((int*)hook->OrigFuncAddress + i) = hook->OriginalBytes[i];

	((void(*)())hook->OrigFuncAddress)();
}
*/
