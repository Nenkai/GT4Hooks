#pragma once

#define LOWORD(l)           ((uint16_t)((*(uint32_t*)(&l)) & 0xffff))
#define HIWORD(l)           ((uint16_t)(((*(uint32_t*)(&l)) >> 16) & 0xffff))

/*
    Patches a short at the specified address.

	@param addr Address of the value
    @param data Data
*/
void PATCH_SHORT(unsigned int addr, short data);

/*
    Calls a specified function with a specified function hook.
    You can use this to replace an existing JAL instruction to call your own function instead.

	@param addr Address to jump to
    @param func Function callback
*/
void MAKE_JAL(unsigned int addr, void* func);

/*
    Patches a int at the specified address.

	@param addr Address of the value
    @param data Data
*/
void PATCH_INT(unsigned int addr, int data);

/*
    Patches a float at the specified address.

	@param addr Address of the value
    @param data Data
*/
void PATCH_FLOAT(unsigned int addr, float data);

/*
    Jumps to the specified address with a specified function hook.
    Example: You can use this at the start (or end) of a game function to jump to your own code.

	@param addr Address to jump to
    @param func Function callback
*/
void MAKE_JMP(unsigned int addr, void* func);

/*
    NOPs the instruction at a specified address.

	@param addr Address to NOP
*/
void NOP(unsigned int addr);

/*
    Hijacks a function address with another one.

	@param func_addr_location Address where the function address is located
    @param func Hook function
*/
void HOOK_FUNC_ADDR(void* func_start_addr, void* func);

void HOOK(unsigned int func_start_addr, void* func);