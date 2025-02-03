/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:56:06 by abmasnao          #+#    #+#             */
/*   Updated: 2025/01/01 11:28:20 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	e_up(t_vars *vars, int ex, int ey)
{
	if (vars->map[ex - 1][ey] != '1' && vars->map[ex - 1][ey] != 'E'
			&& vars->map[ex - 1][ey] != 'C')
	{
		vars->map[ex][ey] = '0';
		vars->map[--ex][ey] = 'G';
	}
}

void	e_down(t_vars *vars, int ex, int ey)
{
	if (vars->map[ex + 1][ey] != '1' && vars->map[ex + 1][ey] != 'E'
			&& vars->map[ex + 1][ey] != 'C')
	{
		vars->map[ex][ey] = '0';
		vars->map[++ex][ey] = 'G';
	}
}

void	e_right(t_vars *vars, int ex, int ey)
{
	if (vars->map[ex][ey + 1] != '1' && vars->map[ex][ey + 1] != 'E'
			&& vars->map[ex][ey + 1] != 'C')
	{
		vars->map[ex][ey] = '0';
		vars->map[ex][++ey] = 'G';
	}
}

void	e_left(t_vars *vars, int ex, int ey)
{
	if (vars->map[ex][ey - 1] != '1' && vars->map[ex][ey - 1] != 'E'
			&& vars->map[ex][ey - 1] != 'C')
	{
		vars->map[ex][ey] = '0';
		vars->map[ex][--ey] = 'G';
	}
}

void	enemy_patrol(t_vars *vars)
{
	int	ex;
	int	ey;
	int	e_dir;

	ex = find_ex(vars);
	ey = find_ey(vars);
	e_dir = (rand() % 4) + 1;
	if (e_dir == 1)
		e_up(vars, ex, ey);
	else if (e_dir == 2)
		e_down(vars, ex, ey);
	else if (e_dir == 3)
		e_right(vars, ex, ey);
	else if (e_dir == 4)
		e_left(vars, ex, ey);
}
