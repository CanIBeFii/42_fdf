/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:42:11 by filipe            #+#    #+#             */
/*   Updated: 2023/01/31 13:13:14 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	key_press(int keycode, void *params)
{
	t_window	*mlx;

	mlx = (t_window *)params;
	if (keycode == ESC_KEY)
		exit(close_mlx(mlx, SUCCESS));
	return (0);
}

int	close_mlx(t_window *mlx, int error_code)
{
	free_mlx(mlx);
	return (error_code);
}

int	shutdown_mlx(t_window *mlx)
{
	exit(close_mlx(mlx, SUCCESS));
}

void	free_mlx(t_window *mlx)
{
	if (mlx != NULL)
	{
		if (mlx->data != NULL)
		{
			mlx_destroy_image(mlx->mlx, mlx->data->img);
			free(mlx->data);
		}
		if (mlx->mlx_win != NULL)
			mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		if (mlx->mlx != NULL)
		{
			mlx_destroy_display(mlx->mlx);
			free(mlx->mlx);
		}
	}
}
