/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:30:35 by mbico             #+#    #+#             */
/*   Updated: 2023/08/02 19:14:20 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/core.h"

//map[0] = x max, y max, char utilisé
int	ft_get_value(t_map *map, int x, int y)
{
	int	i;
	
	i = 1;
	while (i <= map[0].x * map[0].y)
	{
		if (map[i].x == x && map[i].y == y)
			return (map[i].value);
		i ++;
	}
	return (-1);
}

int	ft_get_index(t_map *map, int x, int y)
{
	int	i;
	
	i = 1;
	while (i <= map[0].x * map[0].y)
	{
		if (map[i].x == x && map[i].y == y)
			return (i);
		i ++;
	}
	return (-1);
}