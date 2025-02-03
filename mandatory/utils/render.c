/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:47:12 by abmasnao          #+#    #+#             */
/*   Updated: 2025/01/01 15:53:47 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_images(t_vars *vars)
{
	if (vars->map[vars->m_i][vars->m_j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->wall, vars->m_x, vars->m_y);
	if (vars->map[vars->m_i][vars->m_j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->floor, vars->m_x, vars->m_y);
	if (vars->map[vars->m_i][vars->m_j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player, vars->m_x, vars->m_y);
	if (vars->map[vars->m_i][vars->m_j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->food, vars->m_x, vars->m_y);
	if (vars->map[vars->m_i][vars->m_j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->exit, vars->m_x, vars->m_y);
}

void	render(t_vars *vars)
{
	vars->m_i = 0;
	vars->m_y = 0;
	while (vars->map[vars->m_i])
	{
		vars->m_j = 0;
		vars->m_x = 0;
		while (vars->map[vars->m_i][vars->m_j])
		{
			put_images(vars);
			vars->m_j++;
			vars->m_x += 50;
		}
		vars->m_y += 50;
		vars->m_i++;
	}
}
