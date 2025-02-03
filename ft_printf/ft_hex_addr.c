/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:03:37 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:49:23 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_hex_addr(void *p)
{
	unsigned long	addr;
	int				i;
	char			buf[100];
	int				count;

	i = 0;
	addr = (unsigned long)p;
	count = 2;
	if (!p)
	{
		buf[i++] = '0';
		count++;
	}
	while (addr > 0)
	{
		buf[i++] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		count++;
	}
	write(1, "0x", 2);
	while (--i >= 0)
	{
		write(1, &buf[i], 1);
	}
	return (count);
}
