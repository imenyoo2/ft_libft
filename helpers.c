/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayait-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:09:40 by ayait-el          #+#    #+#             */
/*   Updated: 2023/11/03 15:09:56 by ayait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

// TODO: REMOVE FROM GIT
void	print_array(void *array, int size)
{
	char	*array_holder;
	int		i;

	array_holder = array;
	printf("\t[");
	for (i = 0; i < size - 1; i++)
	{
		if (isalnum(array_holder[i]) || array_holder[i] == ' ')
			printf("'%c', ", array_holder[i]);
		else
			printf(" %.2x, ", array_holder[i]);
	}
	if (isalnum(array_holder[i]))
		printf("'%c'", array_holder[i]);
	else
		printf(" %.2x", array_holder[i]);
	printf("]\n");
}
