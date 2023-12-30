/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:15:44 by mamarinc          #+#    #+#             */
/*   Updated: 2023/07/30 22:03:39 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include <unistd.h>

int	ft_strlen(char *str);

int	ft_strcmp(char *data, char *nb)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] != nb[i])
			return (data[i] - nb[i]);
		i ++;
	}
	if (nb[i])
	{
		return (data[i] - nb[i]);
	}
	return (0);
}

int	ft_strcmp_char(char *data, char nb, int pos, int teen)
{
	if (ft_strlen(data) == 2 && pos == 1 && data[0] == '1' && teen == 1)
	{
		return (data[1] - nb);
	}
	else if (ft_strlen(data) == 2 && pos == 2 && data[1] == '0' && teen == 0)
	{
		return (data[0] - nb);
	}
	else if (ft_strlen(data) == 1 && pos != 2 && teen == 0)
		return (data[0] - nb);
	return (-1);
}

int	ft_searcher(char nb_chr, t_data *data, int pos, int teen)
{
	int	i;

	i = 0;
	while (data[i].id)
	{
		if (ft_strcmp_char(data[i].id, nb_chr, pos, teen) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_search_id(char *nb_str, char nb_chr, t_data *data, int pos)
{
	int	i;

	i = 0;
	if (nb_chr != 0 && nb_str[0] == '1')
		return (ft_searcher(nb_chr, data, pos, 1));
	else if (nb_chr != 0)
		return (ft_searcher(nb_chr, data, pos, 0));
	else if (nb_str[0] != 0)
	{
		while (data[i].id)
		{
			if (ft_strcmp(data[i].id, nb_str) == 0)
				return (i);
			i++;
		}
		return (-1);
	}
	else
		return (-1);
}
