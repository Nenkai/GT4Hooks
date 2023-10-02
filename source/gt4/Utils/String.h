#pragma once

#include "stdbool.h"

char *strrchr (char *s, int c);
void *memchr(const void *bigptr, int ch, size_t length);
void *__memrchr(const void *m, int c, size_t n);

bool starts_with(char *restrict string, char* prefix);
char* get_filename_ext(char *filename);
char* _dirname(register char *pathname);
char* get_file_name(char* fullpath);
