/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:38:52 by fialexan          #+#    #+#             */
/*   Updated: 2023/01/16 13:01:31 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include "stdlib.h"
#include "fdf.h"
#include <mlx.h>

//put_all_points_in_window(mlx.coords, map.x * map.y, mlx.data);
int	main(int argc, char **argv)
{
	t_window	mlx;
	t_map		map;

	if (file_checker(argc, argv) == 0)
		return (-1);
	if (get_map(argv[1], &map) == 0)
		return (-1);
	if (init_win(&mlx, &map) == 0)
		return (1);
	mlx.coords = get_all_points(map);
	free_map(&map);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, mlx.window_width,
			mlx.window_heigth, "Fdf");
	mlx.data->img = mlx_new_image(mlx.mlx, mlx.window_width, mlx.window_heigth);
	mlx.data->addr = mlx_get_data_addr(mlx.data->img, &mlx.data->bits_per_pixel,
			&mlx.data->line_length, &mlx.data->endian);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.data->img, 0, 0);
	while (1)
	{
		mlx_key_hook(mlx.mlx_win, key_press, &mlx);
		mlx_hook(mlx.mlx_win, 17, 0, shutdown_mlx, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}

int	init_win(t_window *mlx, t_map *map)
{
	mlx->mlx = NULL;
	mlx->mlx_win = NULL;
	mlx->data = malloc(sizeof(t_data));
	if (mlx->data == NULL)
		return (0);
	mlx->coords = NULL;
	mlx->window_heigth = 540;
	mlx->window_width = 960;
	mlx->x = map->x;
	mlx->y = map->y;
	return (1);
}

void	free_map(t_map *map)
{
	int	index;

	index = 0;
	while (index < map->y)
	{
		free(map->map[index]);
		index++;
	}
	free(map->map);
}
