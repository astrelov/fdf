/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:29:46 by null              #+#    #+#             */
/*   Updated: 2018/08/16 12:21:15 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		print_coordinates_angles(void *mlx_ptr, void *win_ptr, t_map *s_map, t_view *s_view)
{
	char 		*str;
	t_dot_3d	**dots;
	t_dot_3d	dot;

	dots = s_map->dots_curr;
	dot_3d_to_2d(&dot, &dots[s_map->lines / 2][s_map->columns / 2], s_view);
	str = ft_itoa((int)dot.x);
//	mlx_string_put(mlx_ptr, win_ptr, 125, 20, s_view->info_color, str);
	mlx_string_put(mlx_ptr, win_ptr, INFO_CHAR_WIDTH_PX(12), 20, s_view->info_color, str);
	ft_strdel(&str);
	str = ft_itoa((int)dot.y);
	mlx_string_put(mlx_ptr, win_ptr, INFO_CHAR_WIDTH_PX(21), 20, s_view->info_color, str);
	ft_strdel(&str);
	str = ft_itoa((int)s_view->x_angle);
	mlx_string_put(mlx_ptr, win_ptr, INFO_CHAR_WIDTH_PX(12), 40, s_view->info_color, str);
	ft_strdel(&str);
	str = ft_itoa((int)s_view->y_angle);
	mlx_string_put(mlx_ptr, win_ptr, INFO_CHAR_WIDTH_PX(21), 40, s_view->info_color, str);
	ft_strdel(&str);
	str = ft_itoa((int)s_view->z_angle);
	mlx_string_put(mlx_ptr, win_ptr, INFO_CHAR_WIDTH_PX(30), 40, s_view->info_color, str);
	ft_strdel(&str);
}

void			print_info_to_win(void *mlx_ptr, void *win_ptr, t_map *s_map, t_view *s_view)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 20, s_view->info_color, "POS:    x =      y =");
	mlx_string_put(mlx_ptr, win_ptr, 5, 40, s_view->info_color, "ANGLES: x =      y =      z =");
	print_coordinates_angles(mlx_ptr, win_ptr, s_map, s_view);
	mlx_string_put(mlx_ptr, win_ptr, 5, 70, s_view->info_color, "Help toggle: press TAB");
	if (s_view->show_help)
	{
		mlx_string_put(mlx_ptr, win_ptr, 25, INFO_CHAR_HEIGHT_PX(5), s_view->info_color, "decrease/increase map height: -/+");
		mlx_string_put(mlx_ptr, win_ptr, 25, INFO_CHAR_HEIGHT_PX(6), s_view->info_color, "zoom in/out: mouse wheel up/down");
		mlx_string_put(mlx_ptr, win_ptr, 25, INFO_CHAR_HEIGHT_PX(7), s_view->info_color, "rotate x axis: 1/Q");
		mlx_string_put(mlx_ptr, win_ptr, 25, INFO_CHAR_HEIGHT_PX(8), s_view->info_color, "rotate y axis: 2/W");
		mlx_string_put(mlx_ptr, win_ptr, 25, INFO_CHAR_HEIGHT_PX(9), s_view->info_color, "rotate z axis: 3/E");
		mlx_string_put(mlx_ptr, win_ptr, 25, INFO_CHAR_HEIGHT_PX(10), s_view->info_color, "move map: arrows");
		mlx_string_put(mlx_ptr, win_ptr, 25, INFO_CHAR_HEIGHT_PX(11), s_view->info_color, "reset map: BACKSPACE");
	}
}

void			print_usage()
{
	ft_putendl("usage: fdf /path-to-map/map.fdf");
}
