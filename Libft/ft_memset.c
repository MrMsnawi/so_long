/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:47:56 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:51:17 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	x;

	i = 0;
	a = (unsigned char *)b;
	x = (unsigned char) c;
	while (i < len)
		a[i++] = x;
	return (b);
}
