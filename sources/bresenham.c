/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:23:05 by fialexan          #+#    #+#             */
/*   Updated: 2023/01/28 16:10:07 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "fdf.h"

void	bresenham(t_2Dcoord *points, int x, int y, t_data *data)
{
	int	x_iter;
	int	y_iter;

	y_iter = 0;
	while (y_iter < y)
	{
		x_iter = 0;
		while (x_iter < x)
		{
			if (x_iter < x - 1)
				bresenham_algo(points[y_iter * x + x_iter],
					points[y_iter * x + x_iter + 1], data);
			if (y_iter < y - 1)
				bresenham_algo(points[y_iter * x + x_iter],
					points[(y_iter + 1) * x + x_iter], data);
			x_iter++;
		}
		y_iter++;
	}
}

void	bresenham_algo(t_2Dcoord begin, t_2Dcoord end, t_data *data)
{
	t_bresenham	algo;

	algo = bresenham_init(begin, end);
	while (begin.x != end.x && begin.y != end.y)
	{
		my_mlx_pixel_put(data, begin, 0x00FF0000);
		algo.abs_diff2x = algo.abs_diff * 2;
		if (algo.abs_diff2x > -algo.absolute_y)
		{
			algo.abs_diff -= algo.absolute_y;
			begin.x += algo.x_modifier;
		}
		if (algo.abs_diff2x < algo.absolute_x)
		{
			algo.abs_diff += algo.absolute_x;
			begin.y += algo.y_modifier;
		}
	}
	my_mlx_pixel_put(data, begin, 0x00FF0000);
}

t_bresenham	bresenham_init(t_2Dcoord begin, t_2Dcoord end)
{
	t_bresenham	algo;

	algo.absolute_x = (int)fabs((double)end.x - (double)begin.x);
	algo.absolute_y = (int)fabs((double)end.y - (double)begin.y);
	if (begin.x < end.x)
		algo.x_modifier = 1;
	else
		algo.x_modifier = -1;
	if (begin.y < end.y)
		algo.y_modifier = 1;
	else
		algo.y_modifier = -1;
	algo.abs_diff = algo.absolute_x - algo.absolute_y;
	return (algo);
}
