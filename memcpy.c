
#include "main.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *destholder;
	char *srcholder;

	i = 0;
	destholder = (char *) dest;
	srcholder = (char *) src;
	while (i < n)
	{
		destholder[i] = srcholder[i];
		i++;
	}
	return (dest);
}
