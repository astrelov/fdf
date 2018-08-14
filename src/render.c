/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:56:28 by null              #+#    #+#             */
/*   Updated: 2018/08/14 16:56:41 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			fill_image_pixel(t_image *img, int x, int y, int color)
{
	if (img && img->img_buff && x >= 0 && x < img->width
												&& y >= 0 && y < img->height)
		*(int *)(img->img_buff + img->bpp * (x + y * img->width)) = color;
}

void			make_image(t_env *env)
{
	env->s_img.width = env->win_width;
	env->s_img.height = env->win_height;
	if (!(env->s_img.img_ptr = mlx_new_image(env->mlx_ptr, env->s_img.width, env->s_img.height)))
		ft_err_exit("ERROR: couldn't create image");
	env->s_img.img_buff = mlx_get_data_addr(env->s_img.img_ptr, &env->s_img.bpp, &env->s_img.size_line, &env->s_img.endian);
	env->s_img.bpp /= 8;
}

void			delete_image(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->s_img.img_ptr);
	ft_bzero(&env->s_img, sizeof(env->s_img));
}

void			fill_image_background(t_env *env, int color)
{
	int 		x;
	int 		y;

	y = -1;
	while (++y < env->s_img.height)
	{
		x = -1;
		while (++x < env->s_img.width)
			fill_image_pixel(&env->s_img, x, y, color);
	}
}

void			draw_line_in_img(t_dot_3d *d0, t_dot_3d *d1, t_env *env)
{
	int 	i;

//	ft_dprintf(fd_logfile, "draw_line_in_img: x0=%d, y0=%d, x1=%d, y1=%d\n", (int)d0->x, (int)d0->y, (int)d1->x, (int)d1->y);


	if (d0->x < d1->x)
	{
		i = (int)d0->x - 1;
		while (++i < d1->x)
			fill_image_pixel(&env->s_img, i, calculate_line_y(i, d0, d1), 0xffffff);
	}
	else
	{
		i = (int)d1->x - 1;
		while (++i < d0->x)
			fill_image_pixel(&env->s_img, i, calculate_line_y(i, d1, d0), 0xffffff);
	}


	if (d0->y < d1->y)
	{
		i = (int)d0->y - 1;
		while (++i < d1->y)
			fill_image_pixel(&env->s_img, calculate_line_x(i, d0, d1), i, 0xffffff);
	}
	else
	{
		i = (int)d1->y - 1;
		while (++i < d0->y)
			fill_image_pixel(&env->s_img, calculate_line_x(i, d1, d0), i, 0xffffff);
	}
}

void			draw_map_in_img(t_env *env)
{
	t_dot_3d	**dots;
	t_dot_3d	d0;
	t_dot_3d	d1;
	int 		line;
	int 		column;

	dots = env->s_map.dots;
	line = -1;
	while (++line < env->s_map.lines)
	{
		column = -1;
		while (++column < env->s_map.columns)
		{
			d0.x = (int)(dots[line][column].x * env->s_view.x_multiplier + env->s_view.x_2d_shift);
			d0.y = (int)((dots[line][column].y - dots[line][column].z) * env->s_view.yz_multiplier + env->s_view.y_2d_shift);

			if (line + 1 < env->s_map.lines)
			{
				d1.x = (int)(dots[line + 1][column].x * env->s_view.x_multiplier + env->s_view.x_2d_shift);
				d1.y = (int)((dots[line + 1][column].y - dots[line + 1][column].z) * env->s_view.yz_multiplier + env->s_view.y_2d_shift);
				draw_line_in_img(&d0, &d1, env);
			}

			if (column + 1 < env->s_map.columns)
			{
				d1.x = (int)(dots[line][column + 1].x * env->s_view.x_multiplier + env->s_view.x_2d_shift);
				d1.y = (int)((dots[line][column + 1].y - dots[line][column + 1].z) * env->s_view.yz_multiplier + env->s_view.y_2d_shift);
				draw_line_in_img(&d0, &d1, env);
			}
		}
	}
}

int				render(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);

	if (env->s_img.img_ptr)
		delete_image(env);
	make_image(env);
//	fill_image_background(env, FDF_COLOR_GRAY);
	draw_map_in_img(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->s_img.img_ptr, 0, 0);

	return (0);
}
