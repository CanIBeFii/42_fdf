/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:42:11 by filipe            #+#    #+#             */
/*   Updated: 2023/01/16 10:47:58 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press(int keycode, t_window *mlx)
{
	if (keycode == ESC_KEY)
		return ;
	else if (keycode == W_KEY || keycode == UP_KEY)
		return ;
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		return ;
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		return ;
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		return ;
}
