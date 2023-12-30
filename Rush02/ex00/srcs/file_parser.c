/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:46:08 by lbec              #+#    #+#             */
/*   Updated: 2023/07/30 22:05:17 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/data.h"

int	ft_read_files(char *name, char *buffer)
{
	int		file;

	file = open(name, O_RDONLY);
	if (file == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	read(file, buffer, 1024);
	close(file);
	return (1);
}

int	ft_strlen(char *str);

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

t_data	*ft_alloc(t_data *data, char **result)
{
	unsigned int	id_size;
	unsigned int	value_size;
	unsigned int	i;
	unsigned int	j;
	char			*number;

	i = 0;
	j = 0;
	while (result[i] != 0)
	{
		id_size = ft_strlen(result[i]);
		value_size = ft_strlen(result[i +1]);
		data[j].id = malloc(sizeof(int) * id_size);
		data[j].value = malloc(sizeof(int) * value_size);
		if (data[j].id == NULL || data[j].value == NULL)
			return (NULL);
		number = ft_itoa(ft_atoi(result[i]));
		ft_strcat(data[j].id, number);
		free(number);
		ft_strcat(data[j].value, ft_trim(rm_spaces(result[i +1])));
		i += 2;
		j++;
	}
	return (data);
}

t_data	*ft_covertpars(char *name)
{
	char			**result;
	char			buffer[1024];
	t_data			*data;
	unsigned int	result_size;

	result_size = 0;
	if (!ft_read_files(name, buffer))
		return (0);
	result = ft_split(buffer, ":\n");
	while (result[result_size] != 0)
		result_size++;
	data = malloc(sizeof(t_data) * (result_size +1));
	data[result_size].id = 0;
	if (data == NULL)
		return (0);
	return (ft_alloc(data, result));
}
