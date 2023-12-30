/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:49:29 by lbec              #+#    #+#             */
/*   Updated: 2023/07/30 22:03:57 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/data.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*ft_trim(char *str)
{
	char	*start;
	char	*end;

	start = str;
	end = str;
	while (*start && ft_isspace(*start))
		start++;
	while (*end)
		end++;
	while (end > start && ft_isspace(*(end - 1)))
		end--;
	*end = '\0';
	return (start);
}

char	*rm_spaces(char *str)
{
	char	*src;
	char	*dest;
	int		in_word;

	in_word = 0;
	dest = str;
	src = str;
	while (*src)
	{
		if (ft_isspace(*src))
		{
			if (! in_word)
				*dest++ = ' ';
			in_word = 1;
		}
		else
		{
			in_word = 0;
			*dest++ = *src;
		}
		src++;
	}
	*dest = '\0';
	return (str);
}
