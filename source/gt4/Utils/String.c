#include "stdbool.h"
#include "stdio.h"

#include "String.h"
#include "..\GameFunctions\String.h"

char *strrchr (char *s, int c)
{
  char *rtnval = 0;

  do {
    if (*s == c)
      rtnval = (char*) s;
  } while (*s++);
  return (rtnval);
}

void *_memchr(const void *bigptr, int ch, size_t length)
{
	const char *big = (const char *)bigptr;
	size_t n;
	for (n = 0; n < length; n++)
		if (big[n] == ch)
			return (void *)&big[n];
	return NULL;
}

void *__memrchr(const void *m, int c, size_t n)
{
	const unsigned char *s = m;
	c = (unsigned char)c;
	while (n--) if (s[n]==c) return (void *)(s+n);
	return 0;
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
    if(!dot || dot == filename) return NULL;
    return dot + 1;
}

char *_dirname (char *path)
{
  static const char dot[] = ".";
  char *last_slash;
  /* Find last '/'.  */
  last_slash = path != NULL ? strrchr(path, '/') : NULL;
  if (last_slash != NULL && last_slash != path && last_slash[1] == '\0')
    {
      /* Determine whether all remaining characters are slashes.  */
      char *runp;
      for (runp = last_slash; runp != path; --runp)
	if (runp[-1] != '/')
	  break;
      /* The '/' is the last character, we have to look further.  */
      if (runp != path)
	last_slash = __memrchr (path, '/', runp - path);
    }
  if (last_slash != NULL)
    {
      /* Determine whether all remaining characters are slashes.  */
      char *runp;
      for (runp = last_slash; runp != path; --runp)
	if (runp[-1] != '/')
	  break;
      /* Terminate the path.  */
      if (runp == path)
	{
	  /* The last slash is the first character in the string.  We have to
	     return "/".  As a special case we have to return "//" if there
	     are exactly two slashes at the beginning of the string.  See
	     XBD 4.10 Path Name Resolution for more information.  */
	  if (last_slash == path + 1)
	    ++last_slash;
	  else
	    last_slash = path + 1;
	}
      else
	last_slash = runp;
      last_slash[0] = '\0';
    }
  else
    /* This assignment is ill-designed but the XPG specs require to
       return a string containing "." in any case no directory part is
       found and so a static and constant string is required.  */
    path = (char *) dot;
  return path;
}

char* get_file_name(char* fullpath)
{
   for(size_t i = __strlen(fullpath) - 1; i; i--)  
   {
        if (fullpath[i] == '/')
        {
            return &fullpath[i+1];
        }
    }
    return fullpath;
}