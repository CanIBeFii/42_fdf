/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:51:06 by fialexan          #+#    #+#             */
/*   Updated: 2023/01/28 16:13:35 by fialexan         ###   ########.fr       */
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
