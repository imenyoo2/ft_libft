

#include "main.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *holder;
	size_t i;

	holder = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (holder[i] == (unsigned char) c)
			return ((void *) &holder[i]);
		i++;
	}
	return (NULL);
}
