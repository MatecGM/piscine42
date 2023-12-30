/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:19:32 by mbico             #+#    #+#             */
/*   Updated: 2023/07/30 22:42:08 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/data.h"

void	ft_free_all(t_data	*data)
{
	unsigned int	i;

	i = 0;
	while (data[i].id != 0)
	{
		free(data[i].id);
		free(data[i].value);
		i++;
	}
	free(data);
}

int	ft_digit(t_data *data, char *nb, int i, int *pos_and_memory)
{
	int	pam;

	pam = pos_and_memory[1];
	if (pam == 3)
	{
		ft_putstr(data[ft_search_id("", nb[i], data, pam)].value);
		write(1, " ", 1);
		ft_putstr(data[ft_search_id("100", 0, data, pam)].value);
	}
	else if (pam == 2 && nb[i] != '1')
		ft_putstr(data[ft_search_id("", nb[i], data, pam)].value);
	else if (pam == 2 && nb[i] == '1')
		pos_and_memory[3]++;
	else if (pam == 1 && pos_and_memory[3] < 1)
		ft_putstr(data[ft_search_id("", nb[i], data, pam)].value);
	else if (pam == 1)
		ft_putstr(data[ft_search_id("1", nb[i], data, pam)].value);
	if (pos_and_memory[0] != 1 || (pam != 1 && !ft_str_is_numeric(&nb[i])))
		write(1, " ", 1);
	return (i);
}

void	ft_extra_name(t_data *data, char *nb, int i, int *pos_and_memory)
{
	int	pam;

	pam = pos_and_memory[1];
	if (pos_and_memory[0] != 1 && pos_and_memory[2] < 3)
	{
		if (pos_and_memory[0] == 4)
			ft_putstr(data[ft_search_id("1000000000", 0, data, pam)].value);
		else if (pos_and_memory[0] == 3)
			ft_putstr(data[ft_search_id("1000000", 0, data, pam)].value);
		else if (pos_and_memory[0] == 2)
			ft_putstr(data[ft_search_id("1000", 0, data, pam)].value);
	}
	if (!ft_str_is_numeric(&nb[i]))
		write(1, " ", 1);
	pos_and_memory[2] = 0;
	pos_and_memory[3] = 0;
	pos_and_memory[1] = 3;
	pos_and_memory[0]--;
}

int	ft_initialize(int *pos_and_memory, char *nb, t_data *data)
{
	int	i;

	if (nb[0] == '0' && ft_strlen(nb) == 1)
		ft_putstr(data[ft_search_id("", nb[0], data, pos_and_memory[1])].value);
	ft_categorize(pos_and_memory, ft_strlen(nb));
	i = 0;
	while (nb[i] == '0')
		i++;
	ft_categorize(pos_and_memory, ft_strlen(nb) - i);
	return (i);
}

void	ft_convert_number(char *nb, char *name)
{
	t_data	*data;
	int		i;
	int		pos_and_memory[4];

	data = ft_covertpars(name);
	i = ft_initialize(pos_and_memory, nb, data);
	pos_and_memory[2] = 0;
	pos_and_memory[3] = 0;
	while (pos_and_memory[0] > 0)
	{
		while (pos_and_memory[1] > 0)
		{		
			if (nb[i] != '0' || pos_and_memory[3] > 0)
				i = ft_digit(data, nb, i, pos_and_memory);
			else
				pos_and_memory[2]++;
			pos_and_memory[1]--;
			i++;
		}
		ft_extra_name(data, nb, i, pos_and_memory);
	}
	write(1, "\n", 1);
	ft_free_all(data);
}
