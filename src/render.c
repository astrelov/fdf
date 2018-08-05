/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:56:28 by null              #+#    #+#             */
/*   Updated: 2018/08/05 22:26:30 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		render(t_fdf *fdf)
{
	static int	tmp = 0;
	char 		*tmp_str = ft_itoa(tmp);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, 0xffa908, tmp_str);
	ft_strdel(&tmp_str);
	tmp++;

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 40, 0xffff00, "PISH PISH");
	for (int i = 50; i < 100; i++)
		for (int j = 50; j < 100; j++)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, j, 0xff0000);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	return (0);
}
