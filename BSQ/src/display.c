/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:22:37 by mbico             #+#    #+#             */
/*   Updated: 2023/08/02 19:58:39 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/core.h"

void	ft_square(t_map *map, int *result)
{
	int	x;
	int	y;

	x = result[2] - (result[0] - 1);
	y = result[3] - (result[0] - 1);
	while (y <= result[3])
	{
		while (x <= result[2])
		{
			map[ft_get_index(map, x, y)].element[0] = map[0].element[2];
			x ++;
		}
		x = result[2] - (result[0] - 1);;
		y ++;
	}
}

void	ft_display(t_map *map)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y <= map[0].y)
	{
		while (x <= map[0].x)
		{
			write(1, &map[ft_get_index(map, x, y)].element[0], 1);
			x ++;
		}
		write(1, "\n", 1);
		x = 1;
		y ++;
	}
}
