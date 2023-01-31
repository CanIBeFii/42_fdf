/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:05:08 by filipe            #+#    #+#             */
/*   Updated: 2023/01/31 11:19:27 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fcntl.h"
#include "../includes/fdf.h"

int	file_checker(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("The number of arguments was %d instead of 2\n", &argc);
		return (0);
	}
	if (check_filename(argv[1]) == 0)
	{
		ft_printf("Filename if incorrect it doesn't end in .fdf\n");
		return (0);
	}
	return (1);
}

int	check_filename(char *filename)
{
	int	begin;
	int	file_descriptor;

	begin = ft_strlen(filename) - 1;
	if (filename[begin] != 'f' || filename[begin - 1] != 'd'
		|| filename[begin - 2] != 'f' || filename[begin - 3] != '.')
		return (0);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_printf("File doesn't exist :(( You did a popo.\n");
	}
	return (1);
}
