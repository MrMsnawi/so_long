/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:37:06 by abmasnao          #+#    #+#             */
/*   Updated: 2024/12/30 12:51:37 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	words(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static char	**deleting(char **s, int i)
{
	while (--i >= 0 && s[i])
		free(s[i]);
	free(s);
	return (NULL);
}

static int	allocation(char ***buf, size_t words)
{
	*buf = (char **)malloc((words + 1) * sizeof(char *));
	if (*buf == NULL)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*from;
	char	**buf;

	if (s == NULL)
		return (NULL);
	if (allocation(&buf, words(s, c)) == 0)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			buf[i++] = ft_substr(from, 0, ((char *)s - from));
			if (buf[i - 1] == NULL)
				return (deleting(buf, i - 1));
		}
		else
			++s;
	}
	buf[i] = NULL;
	return (buf);
}
