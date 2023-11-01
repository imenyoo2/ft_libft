
#include "main.h"

// TODO: not tested
void ft_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}
