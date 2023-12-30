/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:17:21 by mbico             #+#    #+#             */
/*   Updated: 2023/07/17 14:22:54 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_output(char a1, char a2, char b1, char b2)
{
	a1 = '0' + a1;
	a2 = '0' + a2;
	b1 = '0' + b1;
	b2 = '0' + b2;
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, " ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
	write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < 98)
	{
		while (b < 99)
		{
			b ++;
			if (b > a)
				ft_output(a / 10, a % 10, b / 10, b % 10);
		}
		a ++;
		b = 0;
	}
	write(1, "98 99", 5);
}
