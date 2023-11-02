


#include "libft.h"

size_t ft_strlcpy(char * dst, const char * src, size_t dstsize)
{
        unsigned int    counter;
        unsigned int    return_value;

        return_value = ft_strlen(src);
        if (dstsize < 1)
                return (return_value);
        counter = 0;
        while (counter < dstsize - 1 && *src)
        {
                *dst = *src;
                dst++;
                counter++;
                src++;
        }
        *dst = '\0';
        return (return_value);
}


