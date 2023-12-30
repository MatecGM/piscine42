/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:15:23 by nrontey           #+#    #+#             */
/*   Updated: 2023/08/02 20:24:13 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/core.h"

char    *ft_file_read(int fd)
{
    char    buf[2048];
    char    *value;
    char    *tmp;
    int        size;
    int        len;

    len = 0;
    size = 0;
    value = malloc(sizeof(char));
    value[0] = '\0';
    if (!value)
        return (NULL);
    len = read(fd, buf, 2048);
    while (len > 0)
    {
        tmp = malloc((size + len + 1) * sizeof(char));
        tmp[0] = '\0';
        if (!tmp)
            break ;
        tmp = ft_strncpy(tmp, value, size);
        free(value);
        ft_strncpy(tmp + size, buf, len);
        value = tmp;
        size += len;
        value[size] = '\0';
        len = read(fd, buf, 2048);
    }
    if (len)
        free(value);
    return (value);
}

int ft_nb_lign(char *content, int *i)
{
    char    *temp;
    int     lign;
    
    i[0] = 0;
    while (content[i[0] ] >= '0' && content[i[0]] <= '9')
        i[0] ++;
    if (i[0]  == 0)
        return (0);
    temp = malloc(sizeof(char) * i[0]);
    if (temp == NULL)
        return (0);
    temp = ft_strncpy(temp, content, i[0]);
    lign = ft_unsigned_atoi(temp);
    free(temp);
    return (lign);
}

int ft_nb_column(char *content, int *i, int lign, char *e)
{
    int column;
    int x;

    x = 0;
    column = 0;
    i[1] = 0;
    while (i[1] < lign && content[i[0]])
    {
        while (content[i[0]] != '\n')
        {
            if (content[i[0]] == '\0' || (content[i[0]] != e[0] 
                && content[i[0]] != e[1] && content[i[0]] != e[2]))
                return (0);
            i[0] ++;
            x ++;
        }
        if (i[1] == 0)
            column = x;
        else if (x != column)
            return (0);
        x = 0;
        i[1]++;
        i[0]++;
    }
    if (content[i[0]] != '\0')
        return (0);
    return (column);
}

t_map   *ft_alloc(int lign, int column, char e[3])
{
    int     i;
    t_map   *map;

    i = 1;
    map = malloc(sizeof(t_map) * ((lign + 1) * (column + 1)) + 2);
    map[0].element = malloc(sizeof(char) * 3);
    map[(lign + 1) * (column + 1) + 1].element = malloc(sizeof(char));
    if (map[0].element == NULL 
        && map[(lign + 1) * (column + 1) + 1].element == NULL)
            return (NULL);
    map[0].x = column;
    map[0].y = lign;
    ft_strcpy(map[0].element, e);
    while (i < ((lign + 1) * (column + 1)) + 2)
    {
        map[i].element = malloc(sizeof(char));
        if (map[i].element == NULL)
            return (NULL);
        i ++;
    }
    return (map);
}

t_map   *ft_topline(char *content)
{
    int     i[2];
    int     lign;
    int     column;
    char    e[3];
    
    lign = ft_nb_lign(content, i);
    if (!lign)
        return (NULL);
    i[1] = 0;
    while(content[i[0]] != '\n' && content[i[0]] != '\0' )
    {
        e[i[1]] = content[i[0]];
        i[1] ++;
        i[0] ++;
    }
    if (!content[i[0]] || i[1] != 3 || e[0] == e[1] || e[2] == e[1] || e[0] == e[2])
        return (NULL);
    i[0] ++;
    column = ft_nb_column(content, i, lign, e);
    if (!column)
        return (NULL);
    return (ft_alloc(lign, column, e));
}
void    ft_fill(t_map *map, char *content)
{
    int i;
    int j;
    int xy[2];
    
    i = 1;
    j = 0;
    xy[0] = 0;
    xy[1] = 0;
    while (content[j] != '\n')
        j++;
    j++;
    while (content[j])
    {
        while(content[j] != '\n')
        {
            map[i].x = xy[0];
            map[i].y = xy[1];
            map[i].element[0] = content[j];
            if (xy[0] == 0 || xy[1] == 0 || content[j] == map[0].element[1])
                map[i].value = 0;
            else
                map[i].value = -1;
            i ++;
            j ++;
            xy[0] ++;
        }
        j ++;
        xy[0] = 0;
        xy[1] ++;
    }
}

t_map    *ft_parse(char *filename)
{
    char    *content;
    int        fd;
    t_map    *map;

    fd = open(filename, O_RDWR);
    if (fd == -1)
        return (NULL);
    content = ft_file_read(fd);
    close(fd);
    map = ft_topline(content);
    if (map == NULL)
        return (NULL);
    ft_fill(map, content);
    return (map);
}