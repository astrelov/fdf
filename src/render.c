/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:56:28 by null              #+#    #+#             */
/*   Updated: 2018/08/06 18:18:38 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	make_image(t_fdf *fdf)
{
	fdf->img.width = fdf->win_width;
	fdf->img.height = fdf->win_height;
	fdf->img.image = mlx_new_image(fdf->mlx_ptr, fdf->img.width, fdf->img.height);
	fdf->img.ptr = mlx_get_data_addr(fdf->img.image, &fdf->img.bpp, &fdf->img.size_line, &fdf->img.endian);
//	ft_printf("bpp: %d, size_line: %d, endian: %d\n", fdf->img.bpp, fdf->img.size_line, fdf->img.endian);
}

int		render(t_fdf *fdf)
{
	static int	tmp = 0;
	char 		*tmp_str = ft_itoa(tmp);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 0xffa908, tmp_str);
	ft_strdel(&tmp_str);
	tmp += 1;

//	make_image(fdf);

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 40, 0xffff00, "PISH PISH");
	for (int i = 50; i < 100; i++)
		for (int j = 50; j < 100; j++)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, j, 0xff0000);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	return (0);
}
