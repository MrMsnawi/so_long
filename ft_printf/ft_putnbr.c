/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:15:39 by abmasnao          #+#    #+#             */
/*   Updated: 2024/11/17 17:16:08 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr(int n)
{
	int		len;
	int		i;
	long	nbr;

	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	else
	{
		i = ft_putchar(nbr + 48);
		len += i;
	}
	return (len);
}
