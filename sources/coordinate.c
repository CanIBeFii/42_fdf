/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:53:52 by fialexan          #+#    #+#             */
/*   Updated: 2022/12/06 13:56:41 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

t_2Dcoord	*get_all_points(t_map map, t_window *mlx)
{
	t_3Dcoord	*coords_in_3d;
	t_2Dcoord	*res;

	coords_in_3d = malloc(sizeof(t_3Dcoord) * (map.x * map.y));
	if (coords_in_3d == NULL)
		return (NULL);
	res = malloc(sizeof(t_2Dcoord) * (map.x * map.y));
	if (res == NULL)
		return (NULL);
	coords_in_3d = translate_map_to_coords(map, coords_in_3d);
	res = translate_3d_to_2d(coords_in_3d, res, map.x * map.y, mlx);
	free(coords_in_3d);
	return (res);
}

t_3Dcoord	*translate_map_to_coords(t_map map, t_3Dcoord *coords)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			coords[y * map.x + x].x = x;
			coords[y * map.x + x].y = y;
			coords[y * map.x + x].z = map.map[y][x];
			x++;
		}
		y++;
	}
	return (coords);
}

t_2Dcoord	*translate_3d_to_2d(t_3Dcoord *coords, t_2Dcoord *res, int size,
		t_window *mlx)
{
	int	i;
	int	x_offset;
	int	y_offset;
	int	e;

	i = 0;
	while (i < size)
	{
		e = i % mlx->x;
		x_offset = mlx->width_offset * e;
		e = (i / mlx->x);
		y_offset = mlx->heigth_offset * e;
		res[i] = transform_3Dcoord(coords[i], x_offset, y_offset);
		i++;
	}
	return (res);
}

t_2Dcoord	transform_3dcoord(t_3Dcoord coord, int x_offset, int y_offset)
{
	t_2Dcoord	res;

	res.x = coord.x + 50 + x_offset;
	res.y = coord.y + 50 + y_offset;
	return (res);
}

// res.x = (int)(50 + lround(coord.x + cos(M_PI_4) * 
//	coord.z - cos(M_PI_4) * coord.y)) + x_offset;
// res.y = (int)(50 + lround(-coord.y *
// sin(M_PI_4) - coord.z * sin(M_PI_4))) + y_offset;
