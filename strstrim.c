
#include "main.h"


static int is_in(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	char *result;
	size_t i;

	// removing leading characters
	start = 0;
	while (is_in(s1[start], set))
		start++;
	// removing end characters
	end = ft_strlen(s1);
	if (end != 0)
		end--;
	while (is_in(s1[end], set))
		end--;
	
	result = malloc(sizeof(char) * (end - start + 2));
	i = 0;
	while (start <= end)
	{
		result[i] = s1[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
