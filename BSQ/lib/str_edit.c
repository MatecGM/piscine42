/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_edit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:05:10 by nrontey           #+#    #+#             */
/*   Updated: 2023/08/02 16:17:31 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/core.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int    count;

    count = 0;
    while (src[count] != '\0' && count < n)
    {
        dest[count] = src[count];
        count++;
    }
    while (count < n)
    {
        dest[count] = '\0';
        count++;
    }
    return (dest);
}

int	ft_unsigned_atoi(char *str)
{
    int    i;
    int    nb;

    i = 0;
    nb = 0;
    if (str[i] == '-')
        return (0);
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    return (nb);
}