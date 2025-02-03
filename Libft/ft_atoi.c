/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:28:53 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:49:48 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_sign(char *s, int *i, int sign)
{
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	long long	tmp;
	int			sign;
	char		*s;

	i = 0;
	res = 0;
	tmp = 0;
	sign = 1;
	s = (char *)str;
	while (s[i] && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
		i++;
	sign = check_sign(s, &i, sign);
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - 48);
		if (tmp > res && sign == 1)
			return (-1);
		else if (tmp > res && sign == -1)
			return (0);
		i++;
		tmp = res;
	}
	return ((int)(sign * res));
}
