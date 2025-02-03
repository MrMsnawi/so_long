/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:18:04 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:50:27 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	n_len(long n)
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

static char	*ft_itoa_sp(char *str, long n, int size)
{
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		str[size + 1] = '\0';
		while (size)
		{
			str[size--] = n % 10 + 48;
			n /= 10;
		}
	}
	else
	{
		str[size--] = '\0';
		while (size >= 0)
		{
			str[size--] = n % 10 + 48;
			n /= 10;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n < 0)
	{
		size = n_len(-(long)n);
		str = malloc(size + 2);
	}
	else
	{
		size = n_len((long)n);
		str = malloc(size + 1);
	}
	if (!str)
		return (NULL);
	str = ft_itoa_sp(str, (long)n, size);
	return (str);
}
