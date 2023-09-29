#include "stdbool.h"
#include "String.h"

char *strrchr (char *s, int c)
{
  char *rtnval = 0;

  do {
    if (*s == c)
      rtnval = (char*) s;
  } while (*s++);
  return (rtnval);
}

bool starts_with(char *restrict string, char* prefix)
{
    while(*prefix)
    {
        if(*prefix++ != *string++)
            return false;
    }

    return true;
}

char *get_filename_ext(char *filename) {
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return 0;
    return dot + 1;
}