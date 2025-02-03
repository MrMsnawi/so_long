/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:51:09 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:51:14 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (len--)
			*(destination++) = *(source++);
	}
	else if (dst > src)
	{
		destination += len - 1;
		source += len - 1;
		while (len--)
		{
			*(destination--) = *(source--);
		}
	}
	return (dst);
}
