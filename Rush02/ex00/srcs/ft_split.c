/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:43:10 by lbec              #+#    #+#             */
/*   Updated: 2023/07/30 21:57:31 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/data.h"

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	if (charset == NULL)
		return (0);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (charset == NULL)
		return (1);
	else if (str == NULL)
		return (0);
	while (str[i])
	{
		if (!ft_is_separator(str[i], charset)
			&& ft_is_separator(str[i +1], charset))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (src[count] != '\0' && count < n)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	while (count < n)
	{
		count++;
		dest[count] = '\0';
	}
	return (dest);
}

void	ft_words_process(char *str, char *charset,
	char **final_array, int words_num)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (words_num > 0 && str[i])
	{
		if (ft_is_separator(str[i], charset))
			i++;
		else
		{
			while (! ft_is_separator(str[i + j], charset))
				j++;
			final_array[z] = malloc(sizeof(char) * (j + 1));
			ft_strncpy(final_array[z], str + i, j);
			i += j;
			z++;
			j = 0;
			free (final_array[z]);
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**final_array;
	int		words_num;
	int		str_size;

	str_size = 0;
	words_num = ft_count_words(str, charset);
	final_array = malloc(sizeof(char *) * (words_num) + 1);
	if (charset == NULL)
	{
		while (str[str_size])
			str_size++;
		final_array[0] = malloc(sizeof(char) * (str_size + 1));
		ft_strncpy(final_array[0], str, str_size);
		final_array[words_num] = 0;
		return (final_array);
	}
	ft_words_process(str, charset, final_array, words_num);
	final_array[words_num] = 0;
	return (final_array);
}
