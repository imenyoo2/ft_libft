/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayait-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:02:40 by ayait-el          #+#    #+#             */
/*   Updated: 2023/11/01 10:02:23 by ayait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

// TODO: im assuming here the integer need to be converted to ascii
// TODO: not tested

void ft_putnbr_fd(int n, int fd)
{
  char *str;

  str = ft_itoa(n);
  ft_putstr_fd(str, fd);
  free(str);
}
