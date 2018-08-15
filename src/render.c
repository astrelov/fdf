/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:56:28 by null              #+#    #+#             */
/*   Updated: 2018/08/15 13:21:02 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		calculate_2d_dot(t_dot_3d *d_curr, t_dot_3d *d_init, t_view *s_view)
{
	d_curr->x = (int)((d_init->x * s_view->cam_dist /
					   (d_init->z + s_view->cam_dist)) *
					  s_view->zoom_multiplier + s_view->x_2d_shift);
	d_curr->y = (int)((-d_init->y * s_view->cam_dist /
					   (d_init->z + s_view->cam_dist)) *
					  s_view->zoom_multiplier + s_view->y_2d_shift);
}

static void		fill_image_pixel(t_image *img, int x, int y, int color)
{
	if (img && img->img_buff && x >= 0 && x < img->width
												&& y >= 0 && y < img->height)
		*(int *)(img->img_buff + img->bpp * (x + y * img->width)) = color;
}

static void		make_image(void *mlx_ptr, t_image *s_img)
{
	s_img->width = WIN_WIDTH;
	s_img->height = WIN_HEIGHT;
	if (!(s_img->img_ptr = mlx_new_image(mlx_ptr, s_img->width, s_img->height)))
		ft_err_exit("ERROR: couldn't create image");
	s_img->img_buff = mlx_get_data_addr(s_img->img_ptr, &s_img->bpp, &s_img->size_line, &s_img->endian);
	s_img->bpp /= 8;
}

static void		delete_image(void *mlx_ptr, t_image *s_img)
{
	mlx_destroy_image(mlx_ptr, s_img->img_ptr);
	ft_bzero(s_img, sizeof(s_img));
}

static void		fill_image_background(t_image *s_img, int color)
{
	int 		x;
	int 		y;

	y = -1;
	while (++y < s_img->height)
	{
		x = -1;
		while (++x < s_img->width)
			fill_image_pixel(s_img, x, y, color);
	}
}

static void		draw_line_in_img(t_dot_3d *d0, t_dot_3d *d1, t_env *env)
{
	int 	i;

	if (d0->x < d1->x)
	{
		i = (int)d0->x - 1;
		while (++i < d1->x)
			fill_image_pixel(&env->s_img, i, calculate_2d_line_y(i, d0, d1), 0xffffff);
	}
	else
	{
		i = (int)d1->x - 1;
		while (++i < d0->x)
			fill_image_pixel(&env->s_img, i, calculate_2d_line_y(i, d1, d0), 0xffffff);
	}
	if (d0->y < d1->y)
	{
		i = (int)d0->y - 1;
		while (++i < d1->y)
			fill_image_pixel(&env->s_img, calculate_2d_line_x(i, d0, d1), i, 0xffffff);
	}
	else
	{
		i = (int)d1->y - 1;
		while (++i < d0->y)
			fill_image_pixel(&env->s_img, calculate_2d_line_x(i, d1, d0), i, 0xffffff);
	}
}

static void		print_coordinates_angles(void *mlx_ptr, void *win_ptr, t_map *s_map, t_view *s_view)
{
	char 		*str;
	t_dot_3d	**dots;
	t_dot_3d	dot;

	dots = s_map->dots_curr;
	calculate_2d_dot(&dot, &dots[s_map->lines / 2][s_map->columns / 2], s_view);
	str = ft_itoa((int)dot.x);
	mlx_string_put(mlx_ptr, win_ptr, 60, 20, s_view->info_color, str);
	ft_strdel(&str);
	str = ft_itoa((int)dot.y);
	mlx_string_put(mlx_ptr, win_ptr, 117, 20, s_view->info_color, str);
	ft_strdel(&str);
	str = ft_itoa((int)s_view->x_angle);
	mlx_string_put(mlx_ptr, win_ptr, 260, 20, s_view->info_color, str);
	ft_strdel(&str);
	str = ft_itoa((int)s_view->y_angle);
	mlx_string_put(mlx_ptr, win_ptr, 320, 20, s_view->info_color, str);
	ft_strdel(&str);
	str = ft_itoa((int)s_view->z_angle);
	mlx_string_put(mlx_ptr, win_ptr, 380, 20, s_view->info_color, str);
	ft_strdel(&str);
}

static void		print_info(void *mlx_ptr, void *win_ptr, t_map *s_map, t_view *s_view)
{
	mlx_string_put(mlx_ptr, win_ptr, 5, 20, s_view->info_color, "POS: x =       y =");
	mlx_string_put(mlx_ptr, win_ptr, 180, 20, s_view->info_color, "ANGLES: x =       y =       z =");
	print_coordinates_angles(mlx_ptr, win_ptr, s_map, s_view);
	mlx_string_put(mlx_ptr, win_ptr, 5, 50, s_view->info_color, "Help toggle: press TAB");
	if (s_view->show_help)
	{
		mlx_string_put(mlx_ptr, win_ptr, 25, 65, s_view->info_color, "decrease/increase map height: -/+");
		mlx_string_put(mlx_ptr, win_ptr, 25, 80, s_view->info_color, "zoom in/out: mouse wheel up/down");
		mlx_string_put(mlx_ptr, win_ptr, 25, 95, s_view->info_color, "rotate x axis: 1/Q");
		mlx_string_put(mlx_ptr, win_ptr, 25, 110, s_view->info_color, "rotate y axis: 2/W");
		mlx_string_put(mlx_ptr, win_ptr, 25, 125, s_view->info_color, "rotate z axis: 3/E");
		mlx_string_put(mlx_ptr, win_ptr, 25, 140, s_view->info_color, "move map: arrows");
		mlx_string_put(mlx_ptr, win_ptr, 25, 155, s_view->info_color, "reset map: BACKSPACE");
	}
}

static void		draw_map_in_img(t_env *env)
{
	t_dot_3d	**dots;
	t_dot_3d	d0;
	t_dot_3d	d1;
	int 		line;
	int 		column;

	dots = env->s_map.dots_curr;
	line = -1;
	while (++line < env->s_map.lines)
	{
		column = -1;
		while (++column < env->s_map.columns)
		{
			calculate_2d_dot(&d0, &dots[line][column], &env->s_view);
			if (line + 1 < env->s_map.lines)
			{
				calculate_2d_dot(&d1, &dots[line + 1][column], &env->s_view);
				draw_line_in_img(&d0, &d1, env);
			}
			if (column + 1 < env->s_map.columns)
			{
				calculate_2d_dot(&d1, &dots[line][column + 1], &env->s_view);
				draw_line_in_img(&d0, &d1, env);
			}
		}
	}
}

static void 	copy_initial_to_curr_dots(t_map *s_map)
{
	t_dot_3d	**dots_i;
	t_dot_3d	**dots_c;
	int 		line;
	int 		column;

	dots_i = s_map->dots_initial;
	dots_c = s_map->dots_curr;
	line = -1;
	while (++line < s_map->lines)
	{
		column = -1;
		while (++column < s_map->columns)
			ft_memcpy(&dots_c[line][column], &dots_i[line][column], sizeof(t_dot_3d));
	}
}

static void		change_land_height(t_map *s_map)
{
	int 		line;
	int 		column;

	line = -1;
	while (++line < s_map->lines)
	{
		column = -1;
		while (++column < s_map->columns)
			s_map->dots_curr[line][column].z *= s_map->z_multiplier;
	}
}

int				render(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	if (env->s_img.img_ptr)
		delete_image(env->mlx_ptr, &env->s_img);

	make_image(env->mlx_ptr, &env->s_img);
	fill_image_background(&env->s_img, FDF_COLOR_GRAY);

	copy_initial_to_curr_dots(&env->s_map);
	change_land_height(&env->s_map);
	rotate_dots_3_axis(&env->s_map, &env->s_view);

	draw_map_in_img(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->s_img.img_ptr, 0, 0);

	print_info(env->mlx_ptr, env->win_ptr, &env->s_map, &env->s_view);
	return (0);
}
