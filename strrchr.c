

#include "main.h"

char *ft_strrchr(const char *s, int c)
{
	char *returnValue;

	returnValue = NULL;
	while (*s)
	{
		if (*s == c)
			returnValue =  (char *) s;
		s++;
	}
	if (*s == c)
		returnValue =  (char *) s;

	return (returnValue);
}
