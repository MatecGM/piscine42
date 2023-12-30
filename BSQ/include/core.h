/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:15:36 by nrontey           #+#    #+#             */
/*   Updated: 2023/08/02 20:41:28 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		x;
	int		y;
	char	*element;
	int		value;
}	t_map;

//Basic
int		ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
char    *ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_unsigned_atoi(char *str);
//value attribution
void	ft_value_attribution(t_map *map, int *result);
int	ft_get_value(t_map *map, int x, int y);
int	ft_get_index(t_map *map, int x, int y);
//display
void	ft_square(t_map *map, int *result);
void	ft_display(t_map *map);
//parse
t_map	*ft_parse(char *filename);

#endif