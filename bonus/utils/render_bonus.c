/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:47:12 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/02 13:02:48 by abmasnao         ###   ########.fr       */
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
	if (vars->map[vars->m_i][vars->m_j] == 'G')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->enemy, vars->m_x, vars->m_y);
}

int	food_sprite(t_vars *vars)
{
	if (vars->tic == 7)
		vars->food = mlx_xpm_file_to_image(vars->mlx,
				"images/food.xpm", &vars->wi, &vars->hi);
	else if (vars->tic == 14)
		vars->food = mlx_xpm_file_to_image(vars->mlx,
				"images/food1.xpm", &vars->wi, &vars->hi);
	else if (vars->tic == 21)
		vars->food = mlx_xpm_file_to_image(vars->mlx,
				"images/food2.xpm", &vars->wi, &vars->hi);
	else if (vars->tic == 28)
		vars->food = mlx_xpm_file_to_image(vars->mlx,
				"images/food1.xpm", &vars->wi, &vars->hi);
	if (vars->tic > 28)
		vars->tic = -1;
	vars->tic++;
	mlx_clear_window(vars->mlx, vars->window);
	render(vars);
	if (find_player(vars) == -1)
		you_lose(vars);
	return (0);
}

void	render(t_vars *vars)
{
	char	*str;

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
	str = ft_itoa(vars->moves);
	mlx_string_put(vars->mlx, vars->window,
		(ft_strlen(vars->map[0]) - 1) * 1, 10,
		0xffed29, str);
	free(str);
}
