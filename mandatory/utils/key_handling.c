/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:06:24 by abmasnao          #+#    #+#             */
/*   Updated: 2025/01/29 15:05:12 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	b_close(t_vars *vars)
{
	free_f(vars);
	exit(0);
}

void	free_f(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map)
	{
		while (vars->map[i])
		{
			free(vars->map[i]);
			i++;
		}
		free(vars->map);
	}
}

int	a_close(t_vars *vars)
{
	if (vars->player)
		mlx_destroy_image(vars->mlx, vars->player);
	if (vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (vars->floor)
		mlx_destroy_image(vars->mlx, vars->floor);
	if (vars->exit)
		mlx_destroy_image(vars->mlx, vars->exit);
	if (vars->food)
		mlx_destroy_image(vars->mlx, vars->food);
	mlx_clear_window(vars->mlx, vars->window);
	mlx_destroy_window(vars->mlx, vars->window);
	free_f(vars);
	exit(0);
}

int	key_handling(int key_code, t_vars *vars)
{
	if (key_code == 53)
		a_close(vars);
	else if (key_code == 13)
		move_up(vars);
	else if (key_code == 1)
		move_down(vars);
	else if (key_code == 2)
		move_right(vars);
	else if (key_code == 0)
		move_left(vars);
	return (0);
}
