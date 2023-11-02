

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char *returnValue;

	returnValue = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			returnValue =  (char *) s;
		s++;
	}
	if (*s == (unsigned char)c)
		returnValue =  (char *) s;

	return (returnValue);
}
