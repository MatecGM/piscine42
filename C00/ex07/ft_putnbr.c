/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:23:31 by mbico             #+#    #+#             */
/*   Updated: 2023/07/17 14:26:21 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_output(char nb)
{
	write(1, &nb, 1);
}

int	ft_negative_number(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}	
	return (nb);
}

void	ft_putnbr(int nb)
{
	int	n;
	int	c;

	n = 1;
	c = 0;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		nb = ft_negative_number(nb);
		c = nb;
		while (c > 9)
		{
			c = c / 10;
			n = n * 10;
		}
		c = nb;
		while (n > 0)
		{
			ft_output('0' + c / n);
			c = c % n;
			n = n / 10;
		}	
	}		
}
