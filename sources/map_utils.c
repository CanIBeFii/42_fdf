/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:26:45 by filipe            #+#    #+#             */
/*   Updated: 2023/04/04 11:39:51 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdlib.h"
#include "../includes/fdf.h"

int	get_map(char *filename, t_map *map)
{
	int		fd;
	int		temporary;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	temporary = get_line_num(fd);
	if (temporary == -1)
		return (0);
	map->y = temporary;
	close(fd);
	map->map = get_map_str(filename, map->y);
	if (map->map == NULL)
		return (0);
	map->x = get_line_size(map->map[0]);
	return (1);
}

int	get_line_size(char *line)
{
	int		index;
	char	**temp;

	index = 0;
	temp = ft_split(line, ' ');
	while (temp[index] != NULL)
	{
		free(temp[index]);
		index++;
	}
	free(temp);
	return (index);
}

int	get_line_num(int fd)
{
	int		lines;
	int		was_read;
	char	c;

	lines = 0;
	was_read = read(fd, &c, 1);
	while (was_read != 0)
	{
		if (was_read < 0)
			return (-1);
		if (c == '\n')
			lines++;
		was_read = read(fd, &c, 1);
	}
	return (lines);
}

char	**get_map_str(char *filename, int line_num)
{
	char	**map_str;
	int		index;
	int		fd;

	index = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_str = (char **)malloc(sizeof(char *) * line_num + 1);
	if (map_str == NULL)
		return (NULL);
	while (index < line_num)
	{
		map_str[index] = get_next_line(fd);
		index++;
	}
	return (map_str);
}
