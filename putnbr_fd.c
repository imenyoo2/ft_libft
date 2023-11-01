
#include "main.h"

// TODO: im assuming here the integer need to be converted to ascii
// TODO: not tested

void ft_putnbr_fd(int n, int fd)
{
  char *str;

  str = ft_itoa(n);
  ft_putstr_fd(str, fd);
  free(str);
}
