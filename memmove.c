

#include "main.h"
#include <stdio.h>

// TODO: if n > 1024 this may cause issues

static size_t min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

/*
void *ft_memmove(void *dest, const void *src, size_t n)
{
	char temp[1024];
	size_t copied;

	copied = 0;
	while (copied < n)
	{
		ft_memcpy(temp + copied, src + copied, min(1024, n - copied));
		ft_memcpy(dest + copied, temp, min(1024, n - copied));
		copied += min(1024, n - copied);
	}
	return (dest);
}
*/

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t counter;
	unsigned char *destholder;
	const unsigned char *srcholder;

	if (dest == NULL || src == NULL)
		return (NULL);
	destholder = (unsigned char *) dest;
	srcholder = (const unsigned char *) src;
	counter = 0;
	if (destholder > srcholder)
	{
		while (counter < n)
		{
			destholder[n - counter - 1] = srcholder[n - counter - 1];
			counter++;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
