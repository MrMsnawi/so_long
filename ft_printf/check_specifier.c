/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:30:24 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:49:19 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_else1(const char **format, int *count, va_list list);
void	check_else2(const char **format, int *count, va_list list);

void	check_specifier(const char **format, int *count, va_list list)
{
	char	*str;
	char	c;

	(*format)++;
	if (**format != '\0')
	{
		if (**format == 's')
		{
			str = va_arg(list, char *);
			*count += ft_putstr(str) - 1;
		}
		else if (**format == 'c')
		{
			c = va_arg(list, int);
			*count += ft_putchar(c) - 1;
		}
		else
			check_else1(format, count, list);
	}
	else
		(*format)--;
}

void	check_else1(const char **format, int *count, va_list list)
{
	int				nbr;
	void			*p;

	if (**format != '\0')
	{
		if (**format == 'p')
		{
			p = va_arg(list, void *);
			*count += ft_hex_addr(p) - 1;
		}
		else if (**format == 'i' || **format == 'd')
		{
			nbr = va_arg(list, int);
			*count += ft_putnbr(nbr) - 1;
		}
		else
			check_else2(format, count, list);
	}
	else
		(*format)--;
}

void	check_else2(const char **format, int *count, va_list list)
{
	unsigned int	un;

	if (**format != '\0')
	{
		if (**format == 'u')
		{
			un = va_arg(list, unsigned int);
			*count += ft_putun(un) - 1;
		}
		else if (**format == 'x')
		{
			un = va_arg(list, unsigned int);
			*count += ft_low_hex(un) - 1;
		}
		else if (**format == 'X')
		{
			un = va_arg(list, unsigned int);
			*count += ft_up_hex(un) - 1;
		}
		else
			*count += ft_putchar(**format) - 1;
	}
	else
		(*format)--;
}
