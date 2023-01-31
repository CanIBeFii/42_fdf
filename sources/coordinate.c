/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:53:52 by fialexan          #+#    #+#             */
/*   Updated: 2023/01/31 15:31:38 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

t_2Dcoord	*get_all_points(t_map map)
{
	t_3Dcoord	*coords_in_3d;
	t_2Dcoord	*return_coord;

	coords_in_3d = malloc(sizeof(t_3Dcoord) * (map.x * map.y));
	if (coords_in_3d == NULL)
		return (NULL);
	return_coord = malloc(sizeof(t_2Dcoord) * (map.x * map.y));
	if (return_coord == NULL)
		return (NULL);
	coords_in_3d = translate_map_to_coords(map, coords_in_3d);
	return_coord = translate_3d_to_2d(coords_in_3d, return_coord,
			map, map.x * map.y);
	free(coords_in_3d);
	return (return_coord);
}

t_3Dcoord	*translate_map_to_coords(t_map map, t_3Dcoord *coords)
{
	int		x;
	int		y;
	char	**line;

	y = 0;
	while (y < map.y)
	{
		line = ft_split(map.map[y], ' ');
		x = 0;
		while (x < map.x)
		{
			coords[y * map.x + x].x = x;
			coords[y * map.x + x].y = y;
			coords[y * map.x + x].z = ft_atoi(line[x]);
			free(line[x]);
			x++;
		}
		free(line);
		y++;
	}
	return (coords);
}

t_2Dcoord	*translate_3d_to_2d(t_3Dcoord *coords, t_2Dcoord *res,
			t_map map, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		res[index] = transform_3dcoord(coords[index], map);
		index++;
	}
	return (res);
}

t_2Dcoord	transform_3dcoord(t_3Dcoord coord, t_map map)
{
	t_2Dcoord	res;
	int			offset;

	if ((WINDOW_WIDTH / map.x / 2) > (WINDOW_HEIGHT / map.y / 2))
		offset = WINDOW_HEIGHT / map.y / 2;
	else
		offset = WINDOW_WIDTH / map.x / 2;
	if (offset < 1)
		offset = 1;
	coord.x *= offset;
	coord.y *= offset;
	coord.z *= offset;
	res.x = (WINDOW_WIDTH / 2) - (map.x / 2) * offset;
	res.y = (WINDOW_HEIGHT / 2) - (map.y / 2) * offset;
	res.x += (int)round((coord.x - coord.y) * cos(0.523599));
	res.y += (int)round((coord.x + coord.y) * sin(0.523599) - coord.z);
	res.x += WINDOW_WIDTH / 5;
	res.y += WINDOW_HEIGHT / 10;
	return (res);
}
