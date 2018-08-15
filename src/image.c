/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:19:14 by null              #+#    #+#             */
/*   Updated: 2018/08/15 15:19:14 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		fill_image_pixel(t_image *img, int x, int y, int color)
{
	if (img && img->img_buff && x >= 0 && x < img->width
		&& y >= 0 && y < img->height)
		*(int *)(img->img_buff + img->bpp * (x + y * img->width)) = color;
}

void			make_image(void *mlx_ptr, t_image *s_img)
{
	s_img->width = WIN_WIDTH;
	s_img->height = WIN_HEIGHT;
	if (!(s_img->img_ptr = mlx_new_image(mlx_ptr, s_img->width, s_img->height)))
		ft_err_exit("ERROR: couldn't create image");
	s_img->img_buff = mlx_get_data_addr(s_img->img_ptr, &s_img->bpp, &s_img->size_line, &s_img->endian);
	s_img->bpp /= 8;
}

void			delete_image(void *mlx_ptr, t_image *s_img)
{
	mlx_destroy_image(mlx_ptr, s_img->img_ptr);
	ft_bzero(s_img, sizeof(s_img));
}

void			fill_image_background(t_image *s_img, int color)
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

void			draw_line_in_img(t_dot_3d *d0, t_dot_3d *d1, t_env *env)
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
