/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:24:22 by mbico             #+#    #+#             */
/*   Updated: 2023/08/02 20:39:20 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/core.h"
int	main(int argv, char **argc)
{
	t_map	*map;
	int		*result;
	
	map = ft_parse("test");
	ft_value_attribution(map, result);
	ft_square(map, result);
	ft_display(map);
}