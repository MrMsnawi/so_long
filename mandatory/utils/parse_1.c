/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:06:39 by abmasnao          #+#    #+#             */
/*   Updated: 2025/01/31 16:27:52 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_invalid_char(char **map, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E')
			{
				ft_putendl_fd("Error\nInvalid character!", 2);
				b_close(vars);
			}
			j++;
		}
		i++;
	}
}

int	count(char **map, int i, int j, char c)
{
	if (map[i][j] == c)
		return (1);
	return (0);
}

int	check_chars_num(char **map, int player_c, int exit_c, int col_c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			player_c += count(map, i, j, 'P');
			col_c += count(map, i, j, 'C');
			exit_c += count(map, i, j, 'E');
		}
		i++;
	}
	if (player_c != 1)
		return (ft_putendl_fd("Error\nMust be one player!", 2), -1);
	if (exit_c != 1)
		return (ft_putendl_fd("Error\nMust be one Exit!", 2), -1);
	if (col_c < 1)
		return (ft_putendl_fd("Error\nMust be at least one collectible!", 2),
			-1);
	return (0);
}

void	check_chars(char **map, t_vars *vars)
{
	check_invalid_char(map, vars);
	if (check_chars_num(map, 0, 0, 0) == -1)
		b_close(vars);
}
