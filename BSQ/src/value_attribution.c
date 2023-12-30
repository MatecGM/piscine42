/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_attribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:23:54 by mbico             #+#    #+#             */
/*   Updated: 2023/08/02 20:41:59 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/core.h"

void	ft_influence(t_map *map, int *xy, int value, int* result)
{
	if (ft_get_value(map, xy[0] - 1, xy[1]) == value 
		|| ft_get_value(map, xy[0], xy[1] - 1) == value
		|| ft_get_value(map, xy[0] - 1, xy[1] - 1) == value)
	{
		map[ft_get_index(map, xy[0], xy[1])].value = value + 1;
		if (result[0] < value + 1)
		{
			result[0] = value + 1;
			result[1] = xy[0];
			result[2] = xy[1];
		}
	}
}

void	ft_check_value(t_map *map, int value, int* result)
{
	int	xy[2];
	
	
	xy[0] = 1;
	xy[1] = 1;
	while (xy[1] <= map[0].y)
	{
		while (xy[0] <= map[0].x)
		{
			ft_influence(map, xy, value, result);
			xy[0] ++;
		}
		xy[0] = 1;
		xy[1] ++;
	}
}

int	ft_fill_check(t_map *map)
{
	int	xy[2];
	
	
	xy[0] = 1;
	xy[1] = 1;
	while (xy[1] <= map[0].y)
	{
		while (xy[0] <= map[0].x)
		{
			if (ft_get_value(map, xy[0], xy[1]) > 0)
				return (1);
			xy[0] ++;
		}
		xy[0] = 1;
		xy[1] ++;
	}
	return (0);
}

void	ft_value_attribution(t_map *map, int *result)
{
	int	value;

	result[0] = 0;
	value = 0;
	while (ft_fill_check(map))
	{
		ft_check_value(map, value, result);
		value ++;
	}
}