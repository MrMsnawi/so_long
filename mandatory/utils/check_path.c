/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:17:32 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/02 12:42:31 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_path(char **c_map, int x, int y, t_checker *checker)
{
	if (c_map[x][y] == '1')
		return ;
	if (c_map[x][y] == 'E')
	{
		checker->checker = 'v';
		return ;
	}
	if (c_map[x][y] == 'a')
		return ;
	if (c_map[x][y] == 'C')
		checker->col_num_check++;
	c_map[x][y] = 'a';
	check_path(c_map, x + 1, y, checker);
	check_path(c_map, x - 1, y, checker);
	check_path(c_map, x, y + 1, checker);
	check_path(c_map, x, y - 1, checker);
}

void	free_c(char **c_map)
{
	int	i;

	i = 0;
	if (c_map)
	{
		while (c_map[i])
		{
			free(c_map[i]);
			i++;
		}
		free(c_map);
	}
}

void	check_valid_path(t_vars *vars, t_checker *checker, char *str)
{
	char	**c_map;

	c_map = ft_split(str, '\n');
	if (!c_map)
	{
		ft_putendl_fd("Error\ncan't import map!", 2);
		b_close(vars);
	}
	vars->col_num = count_col(vars);
	checker->col_num_check = 0;
	checker->col_num_full = vars->col_num;
	check_path(c_map, find_px(vars), find_py(vars), checker);
	free_c(c_map);
	if (checker->col_num_check != checker->col_num_full)
	{
		ft_putendl_fd("Error\nThe player can't collect all collectibles!", 2);
		b_close(vars);
	}
	if (checker->checker != 'v')
	{
		ft_putendl_fd("Error\nInvalid path!", 2);
		b_close(vars);
	}
}
