/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:07:02 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:49:40 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_up_hex(unsigned int hex)
{
	int	n;

	n = 0;
	if (hex >= 16)
	{
		n += ft_up_hex(hex / 16);
		n += ft_up_hex(hex % 16);
	}
	else
		n += write(1, &"0123456789ABCDEF"[hex], 1);
	return (n);
}
