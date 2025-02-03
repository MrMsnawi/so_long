/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:58:11 by abmasnao          #+#    #+#             */
/*   Updated: 2025/01/29 08:21:39 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_up(t_vars *vars)
{
	int	x;
	int	y;

	x = find_px(vars);
	y = find_py(vars);
	if (vars->map[x - 1][y] != '1')
	{
		if (vars->map[x - 1][y] == 'E' && vars->col_num == 0)
			check_up(vars, x, y);
		if (vars->map[x - 1][y] != 'E')
		{
			if (vars->map[x - 1][y] == 'C')
				vars->col_num--;
			if (vars->map[x - 1][y] == 'G')
				you_lose(vars);
			vars->map[x][y] = '0';
			vars->map[--x][y] = 'P';
			vars->moves++;
			mlx_clear_window(vars->mlx, vars->window);
			render(vars);
		}
	}
}

void	move_down(t_vars *vars)
{
	int	x;
	int	y;

	x = find_px(vars);
	y = find_py(vars);
	if (vars->map[x + 1][y] != '1')
	{
		if (vars->map[x + 1][y] == 'E' && vars->col_num == 0)
			check_down(vars, x, y);
		if (vars->map[x + 1][y] != 'E')
		{
			if (vars->map[x + 1][y] == 'C')
				vars->col_num--;
			if (vars->map[x + 1][y] == 'G')
				you_lose(vars);
			vars->map[x][y] = '0';
			vars->map[++x][y] = 'P';
			vars->moves++;
			mlx_clear_window(vars->mlx, vars->window);
			render(vars);
		}
	}
}

void	move_right(t_vars *vars)
{
	int	x;
	int	y;

	x = find_px(vars);
	y = find_py(vars);
	if (vars->map[x][y + 1] != '1')
	{
		if (vars->map[x][y + 1] == 'E' && vars->col_num == 0)
			check_right(vars, x, y);
		if (vars->map[x][y + 1] != 'E')
		{
			if (vars->map[x][y + 1] == 'C')
				vars->col_num--;
			if (vars->map[x][y + 1] == 'G')
				you_lose(vars);
			vars->map[x][y] = '0';
			vars->map[x][++y] = 'P';
			vars->moves++;
			mlx_clear_window(vars->mlx, vars->window);
			render(vars);
		}
	}
}

void	move_left(t_vars *vars)
{
	int	x;
	int	y;

	x = find_px(vars);
	y = find_py(vars);
	if (vars->map[x][y - 1] != '1')
	{
		if (vars->map[x][y - 1] == 'E' && vars->col_num == 0)
			check_left(vars, x, y);
		if (vars->map[x][y - 1] != 'E')
		{
			if (vars->map[x][y - 1] == 'C')
				vars->col_num--;
			if (vars->map[x][y - 1] == 'G')
				you_lose(vars);
			vars->map[x][y] = '0';
			vars->map[x][--y] = 'P';
			vars->moves++;
			mlx_clear_window(vars->mlx, vars->window);
			render(vars);
		}
	}
}
