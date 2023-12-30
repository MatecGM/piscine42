/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:06:17 by mbico             #+#    #+#             */
/*   Updated: 2023/08/01 16:40:29 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tab = malloc((max - min) * sizeof(int));
	if (tab == NULL)
	{
		*range = 0;
		return (-1);
	}
	*range = tab;
	if (tab == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		tab[i] = min + i;
		i ++;
	}
	return (max - min);
}
