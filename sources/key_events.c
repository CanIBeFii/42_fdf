/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:42:11 by filipe            #+#    #+#             */
/*   Updated: 2023/01/16 12:56:53 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, void *params)
{
	t_window	*mlx;

	mlx = (t_window *)params;
	if (keycode == ESC_KEY)
		exit(close_mlx(mlx, SUCCESS));
	else if (keycode == W_KEY || keycode == UP_KEY)
		return (1);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		return (1);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		return (1);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		return (1);
	return (0);
}
