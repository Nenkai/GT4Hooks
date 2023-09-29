#pragma once

#define ADDR_strlen 0x511040
#define ADDR_strcmp 0x510F40
#define ADDR_strstr 0x5D80C0

int (*__strlen)(char* str) = (void*)ADDR_strlen;
int (*__strcmp)(const char* left, const char* right) = (void*)ADDR_strcmp;
char* (*__strstr)(const char* str1, const char* str2) = (void*)ADDR_strstr;