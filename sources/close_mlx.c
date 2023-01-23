/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:35:27 by fialexan          #+#    #+#             */
/*   Updated: 2023/01/23 12:07:00 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

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
