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

char *get_filename_ext(char *filename) {
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return 0;
    return dot + 1;
}