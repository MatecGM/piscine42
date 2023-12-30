/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:26:35 by mbico             #+#    #+#             */
/*   Updated: 2023/07/25 11:09:54 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
			j ++;
			if (to_find[j+1] == 0)
				return (str + i);
		i ++;
	}
	return (0);
}

#include <stdio.h>

int	main()
{
	char str[] = "vasy";
	printf("%s", ft_strstr(str, "sy"));
}
