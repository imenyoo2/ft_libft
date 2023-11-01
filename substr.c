

#include "main.h"


char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *sub;

	if (s == NULL || len == 0)
		return (NULL);
	i = 0;
	sub = malloc(sizeof(char) * len);
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	return (sub);
}
