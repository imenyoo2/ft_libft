/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayait-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:26:01 by ayait-el          #+#    #+#             */
/*   Updated: 2023/11/04 13:48:23 by ayait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	fill_array(const char *src, char *result, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
	{
		result[i] = src[start];
		start++;
		i++;
	}
	if (result[i - 1])
		result[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (is_in(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end != 0)
		end--;
	if (start < ft_strlen(s1))
	{
		while (is_in(s1[end], set) && end > 0)
			end--;
	}
	if (*s1 == '\0')
		result = malloc(sizeof(char) * (end - start + 1));
	else
		result = malloc(sizeof(char) * (end - start + 2));
	if (result == NULL)
		return (NULL);
	fill_array(s1, result, start, end);
	return (result);
}
