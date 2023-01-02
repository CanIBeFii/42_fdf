/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:37:01 by fialexan          #+#    #+#             */
/*   Updated: 2023/01/02 08:50:02 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>

// Type

/**
 * @brief 2D coordinate
 * 
 * @param x int
 * @param y int
 */
typedef struct s_2Dcoord
{
	int	x;
	int	y;
}	t_2Dcoord;

/**
 * @brief 3D coordinate
 * 
 * @param x int
 * @param y int
 * @param z int
 */
typedef struct s_3Dcoord
{
	int	x;
	int	y;
	int	z;
}	t_3Dcoord;

/**
 * @brief Map and his size
 * 
 * @param map char**
 * @param x int - width of the map
 * @param y int - heigth of the map
 */
typedef struct s_map {
	char	**map;
	int		x;
	int		y;
}	t_map;

/**
 * @brief Data of the image
 * 
 */
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/**
 * @brief Window with the data information and pointer to mlx.
 * 
 * @param mlx void *
 * @param mlx_win void *
 * @param data t_data
 * @param window_width int
 * @param window_heigth int
 * @param width_offset int
 * @param heigth_offset int
 */
typedef struct s_window {
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	int		window_width;
	int		window_heigth;
	int		width_offset;
	int		heigth_offset;
	int		x;
	int		y;
}	t_window;

// Main

/**
 * @brief Initializes mlx with the defaults values
 * 
 * @param mlx t_window
 */
void		init_win(t_window *mlx, t_map *map);

// File_checker
int			file_checker(int argc, char **argv);
int			check_filename(char *filename);

// Map_Utils
int			get_map(char *filename, t_map *map);
char		**get_map_str(char *filename, int line_num);
int			get_line_size(char *line);
int			get_line_num(int fd);

// Window Management

/**
 * @brief Receives a 2D coordinate of a pixel and changes it's color.
 * 
 * @param data Image data
 * @param coord Coordinate of the pixel
 * @param color TRGB code
 */
void		my_mlx_pixel_put(t_data *data, t_2Dcoord coord, int color);

/**
 * @brief Receives two 2D coordinates and creares a line between them using 
 * Bresenham's algorithm.
 * 
 * @param data 
 * @param begin 
 * @param end 
 * @param color 
 */
void		write_line(t_data *data, t_2Dcoord *begin, t_2Dcoord *end,
				int color);

/**
 * @brief Puts all the points in the image.
 * 
 * @param points Array with all the points.
 * @param size Size of the array.
 * @param data Data of the image.
 */
void		put_all_points_in_window(t_2Dcoord	*points, int size,
				t_data *data);

void		write_line_between_points(t_2Dcoord *points, t_map *map,
				t_data *data);

// Color

/**
 * @brief Create a trgb object
 * 
 * @param t Transparent 
 * @param r Red
 * @param g Green
 * @param b Blue
 * 
 * @return int 
 */
int			create_trgb(int t, int r, int g, int b);

int			get_transparence(int trgb);
int			get_red(int trgb);
int			get_green(int trgb);
int			get_blue(int trgb);

// Coordinate

/**
 * @brief Receives a map, gets all the 3D coordinates from it.
 * Transforms the 3D coordinates to 2D coordinates.
 * Returns a pointer to an array with all the coordinates.
 * 
 * @param map Map with the coordinate and the number of rows and lines
 * @param mlx Mlx with all additional information
 * 
 * @return t_2Dcoord* 
 */
t_2Dcoord	*get_all_points(t_map map, t_window *mlx);

/**
 * @brief Receives a map and transforms the char** to an array of 3D coordinates.
 * 
 * @param map Map with the coordinate and the number of rows and lines
 * @param coords Pointer for the array of 3D coordinates
 * 
 * @return t_3Dcoord* 
 */
t_3Dcoord	*translate_map_to_coords(t_map map, t_3Dcoord *coords);

/**
 * @brief Transforms an array of 3D coordinates to an array of 2D coordinates.
 * 
 * @param coords 	Array with the 3D coordinates to transform.
 * @param res 	Array of the 2D coordinates.
 * @param size	Size of the arrays.
 * @param mlx Mlx with all additional information
 * 
 * @return t_2Dcoord* 
 */
t_2Dcoord	*translate_3d_to_2d(t_3Dcoord *coords, t_2Dcoord *res,
				int size, t_window *mlx);

/**
 * @brief Receives an 3D coordinate transforms it to an 2D coordinate with 
 * the numbers rounded to the nearest intenger.
 * Adds 50 pixels to give a border.
 * 
 * @param coord 3D coordinate
 * @param mlx Mlx with additional information for the scaling
 * @param x_offset Offset of the x value
 * @param y_offset Offset of the y value
 * 
 * @return t_2Dcoord 
 */
t_2Dcoord	transform_3dcoord(t_3Dcoord coord, int x_offset, int y_offset);

#endif