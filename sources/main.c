/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:38:52 by fialexan          #+#    #+#             */
/*   Updated: 2022/12/06 12:09:57 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include "stdlib.h"
#include "fdf.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_window	mlx;
	t_map		map;
	t_2Dcoord	*points;

	if (file_checker(argc, argv) == 0)
		return (-1);
	if (get_map(argv[1], &map) == 0)
		return (-1);
	init_win(&mlx, &map);
	points = get_all_points(map, &mlx);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, mlx.window_width,
			mlx.window_heigth, "Fdf");
	mlx.data.img = mlx_new_image(mlx.mlx, mlx.window_width, mlx.window_heigth);
	mlx.data.addr = mlx_get_data_addr(mlx.data.img, &mlx.data.bits_per_pixel,
			&mlx.data.line_length, &mlx.data.endian);
	write_line_between_points(points, &map, &mlx.data);
	put_all_points_in_window(points, map.x * map.y, &mlx.data);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.data.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

void	init_win(t_window *mlx, t_map *map)
{
	mlx->window_heigth = 1080;
	mlx->window_width = 1920;
	mlx->width_offset = (1920 - 100) / map->x;
	mlx->heigth_offset = (1080 - 50) / map->y;
	mlx->x = map->x;
	mlx->y = map->y;
}
