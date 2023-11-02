

#include "libft.h"

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        unsigned int    counter;

        if (n == 0)
                return (0);
        counter = 0;
        while (*s1 - *s2 == 0 && *s1 && *s2 && counter < n - 1)
        {
                s1++;
                s2++;
                counter++;
        }
        if (*s1 - *s2 > 0)
                return (1);
        else if (*s1 - *s2 < 0)
                return (-1);
        else
                return (0);
}
