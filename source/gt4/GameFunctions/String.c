#include <stdio.h>

#include "String.h"

int (*__strlen)(char* str) = (void*)ADDR_strlen;
int (*__strcmp)(const char* left, const char* right) = (void*)ADDR_strcmp;
char* (*__strcpy)(const char* destination, const char* source) = (void*)ADDR_strcpy;
char* (*__strstr)(const char* str1, const char* str2) = (void*)ADDR_strstr;