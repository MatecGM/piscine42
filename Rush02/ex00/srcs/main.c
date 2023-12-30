/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:48:15 by lbec              #+#    #+#             */
/*   Updated: 2023/07/30 21:52:24 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

int	main(int argc, char **argv)
{
	int	check;

	check = ft_check_error(argc, argv);
	if (check == 1)
		ft_convert_number(argv[1], "numbers.dict");
	else if (check == 2)
		ft_convert_number(argv[2], argv[1]);
}
