/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbritani <sbritani@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:21:37 by sbritani          #+#    #+#             */
/*   Updated: 2022/10/28 19:42:12 by sbritani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	rec_hexi_print(unsigned long long nb,
	char *base, unsigned long long len)
{
	int	res;

	res = 0;
	if (nb < len)
	{
		print_char(base[nb]);
		return (1);
	}
	else
	{
		res = rec_hexi_print(nb / len, base, len);
		print_char(base[nb % len]);
		return (res + 1);
	}
}

static int	hexi_print(unsigned long long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr < 0)
		nbr = 2147483647 + nbr;
	len += rec_hexi_print(nbr, base, 16);
	return (len);
}

static int	process_flag(va_list args, const char flag)
{
	if (flag == '%')
		return (print_char('%'));
	if (flag == 'c')
		return (print_char(va_arg(args, int)));
	if (flag == 'd' || flag == 'i')
		return (print_nbr(va_arg(args, int)));
	if (flag == 's')
		return (putstr_fd(va_arg(args, char *), 1));
	if (flag == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	if (flag == 'x')
		return (hexi_print(va_arg(args, unsigned int), "0123456789abcdef\0"));
	if (flag == 'p')
		return (putstr_fd("0x", 1)
			+ hexi_print(va_arg(args, unsigned long long),
				"0123456789abcdef\0"));
	if (flag == 'X')
		return (hexi_print(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		res;

	va_start(args, str);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += process_flag(args, str[++i]);
			i++;
		}
		else
		{
			res += print_char(str[i++]);
		}
	}
	va_end(args);
	return (res);
}
