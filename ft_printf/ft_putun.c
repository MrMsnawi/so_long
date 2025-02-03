/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:16:42 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:49:38 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	num_len(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putun(unsigned int n)
{
	int				nlen1;
	int				nlen2;
	unsigned long	nbr;
	char			str[10];

	nbr = n;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	nlen1 = num_len(nbr);
	nlen2 = nlen1;
	while (nbr > 0)
	{
		str[--nlen1] = (nbr % 10) + 48;
		nbr /= 10;
	}
	write(1, str, nlen2);
	return (nlen2);
}
