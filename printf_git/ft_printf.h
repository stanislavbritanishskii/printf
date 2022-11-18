/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbritani <sbritani@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:00:51 by sbritani          #+#    #+#             */
/*   Updated: 2022/10/20 23:46:33 by sbritani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		print_nbr(long long nbr);
int		putstr_fd(char *s, int fd);
int		ft_printf(const char *str, ...);
int		print_char(char c);
int		print_unsigned(long long nbr);

#endif
