/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:12:52 by abmasnao          #+#    #+#             */
/*   Updated: 2025/01/01 11:28:59 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_col(t_vars *vars)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void	you_lose(t_vars *vars)
{
	ft_printf("YOU LOSE!!\n");
	a_close(vars);
}
