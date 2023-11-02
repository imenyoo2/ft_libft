#include "libft.h"

#include <stdio.h>
#include <ctype.h>


void print_array(void *array, int size)
{
	char *array_holder = array;
	int i;

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
