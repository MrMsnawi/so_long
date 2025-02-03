/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:25:29 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:51:27 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	n_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		nlen1;
	int		nlen2;
	long	nbr;
	char	str[10];

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	nlen1 = n_len(nbr);
	nlen2 = nlen1;
	while (nbr > 0)
	{
		str[--nlen1] = (nbr % 10) + 48;
		nbr /= 10;
	}
	write(fd, str, nlen2);
}
