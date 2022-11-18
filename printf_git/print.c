/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbritani <sbritani@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:38:11 by sbritani          #+#    #+#             */
/*   Updated: 2022/10/20 23:47:47 by sbritani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_putnbr_fd(long long nb, int fd)
{
	if (nb == -2147483648)
	{
		print_char('-');
		print_char('2');
		ft_putnbr_fd(147483648, fd);
	}
	else
	{
		if (nb < 0)
		{
			print_char('-');
			ft_putnbr_fd(nb * -1, fd);
		}
		else
		{
			if (nb < 10)
				print_char((char)(nb + 48));
			else
			{
				ft_putnbr_fd(nb / 10, fd);
				print_char((char)(nb % 10 + 48));
			}
		}
	}
}

int	print_nbr(long long nbr)
{
	int			res;
	long long	temp;

	temp = nbr;
	res = 0;
	if (temp <= 0)
	{
		res = 1;
		temp = -temp;
	}
	while (temp)
	{
		temp = temp / 10;
		res += 1;
	}
	ft_putnbr_fd(nbr, 1);
	return (res);
}

int	putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], fd);
		i++;
	}
	return (i);
}

int	print_unsigned(long long nbr)
{
	if (nbr < 0)
		return (print_nbr(4294967295 + nbr));
	return (print_nbr(nbr));
}
