/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:17:48 by abmasnao          #+#    #+#             */
/*   Updated: 2025/01/29 17:40:07 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_up(t_vars *vars, int x, int y)
{
	vars->map[x][y] = '0';
	vars->map[--x][y] = 'P';
	vars->moves++;
	mlx_clear_window(vars->mlx, vars->window);
	render(vars);
	ft_printf("YOU WIN!!\n");
	a_close(vars);
}

void	check_down(t_vars *vars, int x, int y)
{
	vars->map[x][y] = '0';
	vars->map[++x][y] = 'P';
	vars->moves++;
	mlx_clear_window(vars->mlx, vars->window);
	render(vars);
	ft_printf("YOU WIN!!\n");
	a_close(vars);
}

void	check_right(t_vars *vars, int x, int y)
{
	vars->map[x][y] = '0';
	vars->map[x][++y] = 'P';
	vars->moves++;
	mlx_clear_window(vars->mlx, vars->window);
	render(vars);
	ft_printf("YOU WIN!!\n");
	a_close(vars);
}

void	check_left(t_vars *vars, int x, int y)
{
	vars->map[x][y] = '0';
	vars->map[x][--y] = 'P';
	vars->moves++;
	mlx_clear_window(vars->mlx, vars->window);
	render(vars);
	ft_printf("YOU WIN!!\n");
	a_close(vars);
}
