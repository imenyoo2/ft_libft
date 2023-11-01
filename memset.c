
#include "main.h"

void *ft_memset(void *s, int c, size_t n)
{
	int i;
	unsigned char *holder;

	i = 0;
	holder = s;
	while (i < n)
	{
		holder[i] = c;
		i++;
	}
	return (s);
}
