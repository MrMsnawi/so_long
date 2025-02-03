/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:27:25 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:49:26 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_low_hex(unsigned int hex)
{
	int	n;

	n = 0;
	if (hex >= 16)
	{
		n += ft_low_hex(hex / 16);
		n += ft_low_hex(hex % 16);
	}
	else
		n += write(1, &"0123456789abcdef"[hex], 1);
	return (n);
}
