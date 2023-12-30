/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:23:38 by mbico             #+#    #+#             */
/*   Updated: 2023/08/01 16:39:09 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (0);
	tab = malloc((max - min) * sizeof(int));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		tab[i] = min + i;
		i ++;
	}
	return (tab);
}
