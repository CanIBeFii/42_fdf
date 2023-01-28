/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:51:06 by fialexan          #+#    #+#             */
/*   Updated: 2023/01/28 16:07:25 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "math.h"

void	my_mlx_pixel_put(t_data *data, t_2Dcoord coord, int color)
{
	char	*dst;

	dst = data->addr + (coord.y * data->line_length + coord.x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	write_line(t_data *data, t_2Dcoord *begin, t_2Dcoord *end, int color)
{
	t_2Dcoord	coord;

	coord = *begin;
	ft_printf("%d %d tp %d %d\n", coord.x, coord.y, end->x, end->y);
	while (coord.x != end->x || coord.y != end->y)
	{
		my_mlx_pixel_put(data, coord, color);
		if (coord.x != end->x)
			coord.x++;
		if (coord.y != end->y)
			coord.y++;
	}
}

void	put_all_points_in_window(t_2Dcoord	*points, int size, t_data *data)
{
	int	i;

	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(data, points[i], 0x00FF0000);
		i++;
	}
}

void	write_line_between_points(t_2Dcoord *points, t_map *map, t_data *data)
{
	int	i;

	i = 0;
	ft_printf("%d\n", map->y);
	while (i < map->y)
	{
		write_line(data, &points[i * (map->x)], &points[map->x * (i + 1) - 1],
			0xA0FFFFFF);
		if (i <= map->x)
			write_line(data, &points[i], &points[(map->x) * (map->y - 1) + i],
				0xA0FFFFFF);
		i++;
	}
}
