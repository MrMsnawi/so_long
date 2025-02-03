/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:05:20 by abmasnao          #+#    #+#             */
/*   Updated: 2025/02/02 16:42:24 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ber(char *av)
{
	int		len;
	int		i;
	char	*ber;

	i = 5;
	ber = ".ber";
	len = ft_strlen(av);
	while (*ber)
		ber++;
	while (i && *ber == av[len])
	{
		ber--;
		len--;
		i--;
	}
	if (i == 0)
		return (0);
	return (-1);
}

void	init_vars(t_vars *vars)
{
	vars->tic = 0;
	vars->moves = 0;
	vars->hight = 0;
	vars->width = 0;
	while (vars->map[vars->hight] != NULL)
		vars->hight++;
	vars->width = ft_strlen(vars->map[0]);
	vars->hight *= 50;
	vars->width *= 50;
	vars->wi = 50;
	vars->hi = 50;
	vars->m_i = 0;
	vars->m_j = 0;
	vars->m_x = 0;
	vars->m_y = 0;
}

int	start_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, vars->width,
			vars->hight, "so_long");
	vars->player = mlx_xpm_file_to_image(vars->mlx,
			"images/player.xpm", &vars->wi, &vars->hi);
	vars->enemy = mlx_xpm_file_to_image(vars->mlx,
			"images/enemy.xpm", &vars->wi, &vars->hi);
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"images/wall.xpm", &vars->wi, &vars->hi);
	vars->floor = mlx_xpm_file_to_image(vars->mlx,
			"images/floor.xpm", &vars->wi, &vars->hi);
	vars->exit = mlx_xpm_file_to_image(vars->mlx,
			"images/exit.xpm", &vars->wi, &vars->hi);
	vars->food = mlx_xpm_file_to_image(vars->mlx,
			"images/food.xpm", &vars->wi, &vars->hi);
	if (!vars->player || !vars->wall || !vars->floor
		|| !vars->exit || !vars->food)
		return (ft_putendl_fd("Error\nInvalid image path!", 2),
			a_close(vars), -1);
	render(vars);
	return (0);
}

int	main(int ac, char **av)
{
	int			fd;
	char		str[10000];
	t_vars		vars;
	t_checker	checker;

	if (ac != 2)
		return (ft_putendl_fd("Error\nMust be one argument!", 2), 0);
	if (check_ber(av[1]) == -1)
		return (ft_putendl_fd("Error\nmust end with \".ber\"!", 2), 0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error fd", 2), 0);
	parse(&vars, &checker, str, fd);
	init_vars(&vars);
	if (start_window(&vars) == -1)
		return (0);
	mlx_hook(vars.window, 2, 0, key_handling, &vars);
	mlx_hook(vars.window, 17, 0, a_close, &vars);
	mlx_loop_hook(vars.mlx, food_sprite, &vars);
	mlx_loop(vars.mlx);
}
