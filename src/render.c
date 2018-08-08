/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:56:28 by null              #+#    #+#             */
/*   Updated: 2018/08/07 16:29:57 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_image_pixel(t_img *img, int x, int y, int color)
{
	if (img && img->img_buff && x >= 0 && x < img->width
												&& y >= 0 && y < img->height)
		*(int *)(img->img_buff + img->bpp * (x + y * img->width)) = color;
}

void	make_image(t_fdf *fdf)
{
	fdf->img_struct.width = fdf->win_width;
	fdf->img_struct.height = fdf->win_height;
	if (!(fdf->img_struct.img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->img_struct.width, fdf->img_struct.height)))
		ft_err_exit("ERROR: couldn't create image");
	fdf->img_struct.img_buff = mlx_get_data_addr(fdf->img_struct.img_ptr, &fdf->img_struct.bpp, &fdf->img_struct.size_line, &fdf->img_struct.endian);
	fdf->img_struct.bpp /= 8;
}

void	delete_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_struct.img_ptr);
	ft_bzero(&fdf->img_struct, sizeof(fdf->img_struct));
}

void	fill_image(t_fdf *fdf)
{
	static int	color = 0xa0a0a0;

	for (int y = 0; y < fdf->img_struct.height; y++)
		for (int x = 0; x < fdf->img_struct.width; x++)
			fill_image_pixel(&fdf->img_struct, x, y, color);
	color++;
}

int		render(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);

	if (fdf->img_struct.img_ptr)
		delete_image(fdf);
	make_image(fdf);
	fill_image(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_struct.img_ptr, 0, 0);

	return (0);
}
