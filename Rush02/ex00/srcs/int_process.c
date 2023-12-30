/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbec <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:40:32 by lbec              #+#    #+#             */
/*   Updated: 2023/07/30 19:40:34 by lbec             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include <stdlib.h>

int	ft_size_conv(int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_reverse(char *str, int start, int end)
{
	char	temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

char	*ft_itoa(int num)
{
	int		i;
	char	*str;
	int		rem;

	i = 0;
	str = malloc(sizeof(char) * ft_size_conv(num));
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num != 0)
	{
		rem = num % 10;
		if (rem > 9)
			str[i++] = (rem - 10) + 'a';
		else
			str[i++] = rem + '0';
		num = num / 10;
	}
	str[i] = '\0';
	return (ft_reverse(str, 0, i - 1));
}

int	ft_atoi(char *str)
{
	unsigned int	index;
	int				result;
	int				signe;

	result = 0;
	index = 0;
	signe = 0;
	while (str[index] == ' ' || (str[index] >= 7 && str[index] <= 13))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			signe++;
		index++;
	}
	while (str[index] >= 48 && str[index] <= 57 && str[index] != '\0')
	{
		result = result * 10 + (str[index] - 48);
		index++;
	}
	if (signe % 2 == 0)
		return (result);
	return (result * -1);
}
