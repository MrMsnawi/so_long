/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmasnao <abmasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:04:51 by abmasnao          #+#    #+#             */
/*   Updated: 2025/01/01 11:28:24 by abmasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	find_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
}
