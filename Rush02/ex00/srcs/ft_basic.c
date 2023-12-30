/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:13:37 by gviaud            #+#    #+#             */
/*   Updated: 2023/07/30 22:03:27 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/data.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i ++;
	}
	return (1);
}

int	*ft_categorize(int *pos, int len)
{
	if (len > 9)
		pos[0] = 4;
	else if (len > 6)
		pos[0] = 3;
	else if (len > 3)
		pos[0] = 2;
	else
		pos[0] = 1;
	if (len % 3 == 0)
		pos[1] = 3;
	else if (len % 3 == 2)
		pos[1] = 2;
	else
		pos[1] = 1;
	return (pos);
}
