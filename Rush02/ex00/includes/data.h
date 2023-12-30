/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:51:36 by mbico             #+#    #+#             */
/*   Updated: 2023/07/30 21:52:40 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <stdio.h>

typedef struct s_data
{
	char	*id;
	char	*value;
}	t_data;

char	**ft_split(char *str, char *charset);
char	*ft_trim(char *str);
char	*rm_spaces(char *str);
int		ft_size_conv(int nbr);
char	*ft_itoa(int num);
int		ft_atoi(char *str);
t_data	*ft_covertpars(char *name);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_str_is_numeric(char *str);
int		*ft_categorize(int *pos, int len);
int		ft_search_id(char *nb_str, char nb_chr, t_data *data, int pos);
int		ft_check_error(int argc, char **argv);
void	ft_convert_number(char *nb, char *name);
#endif