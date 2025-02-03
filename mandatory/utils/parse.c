/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:58:24 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/02 16:42:55 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_qu(int count, int i, t_vars *vars, int fd)
{
	if (count == 0 && i == 0)
	{
		ft_putendl_fd("Error\nThe map is empty!", 2);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if ((i + 1) > 10000)
	{
		ft_putendl_fd("Error\nThe map very large!\n", 2);
		close(fd);
		b_close(vars);
	}
}

char	*get_map(int fd, char *str, t_vars *vars)
{
	int		i;
	char	c;
	int		lim;
	ssize_t	count;

	i = 0;
	lim = 0;
	count = 1;
	while (count)
	{
		count = read(fd, &c, 1);
		if (count < 0)
			return (close(fd), NULL);
		if (i == 0 && c == '\n')
			return (close(fd), NULL);
		check_qu(count, i, vars, fd);
		if (count != 0)
			str[i++] = c;
		str[i] = '\0';
		if (str[i - 1] == '\n' && str[i - 2] == '\n')
			return (ft_putendl_fd("Error\nthe map must be rectangular!", 2),
				close(fd), exit(EXIT_FAILURE), NULL);
	}
	return (close(fd), str);
}

void	check_rectangular(char **map, t_vars *vars)
{
	int		i;
	size_t	ref;

	i = -1;
	ref = ft_strlen(map[0]);
	while (map[++i])
	{
		if (ref != ft_strlen(map[i]))
		{
			ft_putendl_fd("Error\nThe map must be rectangular!", 2);
			b_close(vars);
		}
	}
}

void	check_border(char **map, t_vars *vars)
{
	int		i;
	int		j;
	size_t	len;

	i = -1;
	j = 0;
	len = ft_strlen(map[0]) - 1;
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][len] != '1')
		{
			ft_putendl_fd("Error\nThe map must be closed by walls!", 2);
			b_close(vars);
		}
	}
	i--;
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[i][j] != '1')
		{
			ft_putendl_fd("Error\nThe map must be closed by walls!", 2);
			b_close(vars);
		}
		j++;
	}
}

void	parse(t_vars *vars, t_checker *checker, char *str, int fd)
{
	vars->map = ft_split(get_map(fd, str, vars), '\n');
	if (!vars->map)
	{
		ft_putendl_fd("Error\nIn map", 2);
		b_close(vars);
	}
	check_rectangular(vars->map, vars);
	check_border(vars->map, vars);
	check_chars(vars->map, vars);
	check_valid_path(vars, checker, str);
}
