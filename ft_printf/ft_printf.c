/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:25:07 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:49:06 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		count;

	count = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
			check_specifier(&format, &count, list);
		else
			write(1, format, 1);
		format++;
		count++;
	}
	va_end(list);
	return (count);
}
