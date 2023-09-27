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
