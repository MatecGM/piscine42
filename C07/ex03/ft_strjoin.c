/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:23:54 by mbico             #+#    #+#             */
/*   Updated: 2023/08/01 16:38:20 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i ++;
	while (src[j])
	{
		dest[i] = src[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_alloc(int size, char **strs, char *sep)
{
	int		i;
	int		len_str;
	char	*str;

	i = 0;
	len_str = 0;
	while (i < size)
	{
		len_str += ft_strlen(strs[i]);
		i ++;
	}
	len_str += ft_strlen(sep) * (size - 1);
	str = malloc((len_str + 1) * sizeof(char));
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	if (sep == NULL)
		sep = "";
	if (size != 0)
	{
		if (strs == NULL)
			return (NULL);
		str = ft_alloc(size, strs, sep);
		if (str == NULL)
			return (NULL);
		*str = 0;
		i = 0;
		while (i < size)
		{
			str = ft_strcat(str, strs[i]);
			if (i != size - 1)
				str = ft_strcat(str, sep);
			i ++;
		}
	}
	else
		str = malloc(sizeof(char));
	return (str);
}
