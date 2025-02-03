/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:32:33 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:52:23 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	if (len)
	{
		while (haystack[i] && i < len)
		{
			while (haystack[i + j] == needle[j] && haystack[i + j]
				&& i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *) haystack + i);
			}
			i++;
			j = 0;
		}
	}
	return (NULL);
}
