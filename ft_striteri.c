

#include "libft.h"

// TODO: may need to just pass s instead of &s[i]
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t i;

	i = 0;
	while (s[i])
	{
		f((unsigned int) i, &s[i]);
		i++;
	}
}
