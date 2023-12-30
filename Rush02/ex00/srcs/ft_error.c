/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:10:54 by mbico             #+#    #+#             */
/*   Updated: 2023/07/30 19:54:03 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

int		ft_strlen(char *str);

int	ft_error(int type)
{
	if (type == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else if (type == 1)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	return (0);
}

int	ft_onlynumbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_error(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		return (ft_error(0));
	else if (argc == 2)
	{
		if (ft_strlen(argv[1]) > 12)
			return (ft_error(0));
		else if (ft_onlynumbers(argv[1]) == 0)
			return (ft_error(0));
		return (1);
	}
	else if (argc == 3)
	{
		if (ft_strlen(argv[2]) > 12)
			return (ft_error(0));
		else if (ft_onlynumbers(argv[2]) == 0)
			return (ft_error(0));
		return (2);
	}
	return (0);
}
