#pragma once

#include "stdbool.h"

bool starts_with(char *restrict string, char* prefix);
char *get_filename_ext(char *filename);
char *strrchr(char *s, int c);
