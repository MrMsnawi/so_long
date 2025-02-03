/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:56:55 by abmasnao          #+#    #+#             */
/*   Updated: 2025/01/01 11:28:29 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	find_py(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == 'P')
				return (y);
			y++;
		}
		x++;
	}
	return (0);
}

int	find_px(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == 'P')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

int	find_ex(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == 'G')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

int	find_ey(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == 'G')
				return (y);
			y++;
		}
		x++;
	}
	return (0);
}
