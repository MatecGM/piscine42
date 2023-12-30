/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:23:36 by mbico             #+#    #+#             */
/*   Updated: 2023/07/23 20:25:16 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//Fait la len et verifie la validité des valeurs et formats
int	ft_str_verifier(int n, char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{		
		if (!((i % 2 == 0 && str[i] >= '1' && str[i] <= '0' + n)
				|| (i % 2 == 1 && str[i] == ' ')))
			return (-1);
		i ++;
	}
	return (i);
}

int	ft_args_error(int n, int nb_args, char **args)
{
	char	*str;
	int		max_len_str;

	str = args[1];
	max_len_str = n * 8 - 1;
	
	//Verifie le nombre d'arguments et le contenue
	if (nb_args != 2 || ft_str_verifier(n, str) != max_len_str)
		return (0);
	else
		return (1);
}

//transforme le string en tableau de int
void	ft_trait(int n, char **args, int *tab)
{
	char	*str;
	int		i;
	
	str = args[1];
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			tab[i / 2] = str[i] - '0';
		}
		i ++;
	}
}

void	ft_display(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n * n)
	{
		write(1, &(char){tab[i] + '0'}, 1);
		if ((i + 1) % n == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i ++;
	}
}

int	main(int nb_args, char **args)
{
	int	n;
	int	*tab;
	int	i;
	int	*alc;
	
	int test[]= {1,2,3,4,1,2,3,4,1,2,3,4,1,2,4,4};
	
	//n est la taille de la grille
	n = 4;
	if (1)
	{
		
		
		
		//test


		
		
		tab = malloc(n * 4 * sizeof(int));
		
		
		ft_display(test, n);
		free(tab);
		
		
	}
		
	else
		write(1, "Error\n", 6);
}