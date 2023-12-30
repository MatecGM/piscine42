/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:57:14 by mbico             #+#    #+#             */
/*   Updated: 2023/07/27 21:56:27 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	argv++;
	while (*argv)
	{
		ft_putstr(*argv);
		write(1, "\n", 1);
		argv++;
	}
	return (0);
}
