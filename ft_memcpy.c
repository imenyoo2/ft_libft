
#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *destholder;
	char *srcholder;

	if (dest == NULL && src == NULL)
		return (NULL);
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

/*
#include <string.h>
#include <stdio.h>
int main()
{
	printf("%p", memcpy(NULL, NULL, 10));
}
*/
