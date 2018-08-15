/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:56:28 by null              #+#    #+#             */
/*   Updated: 2018/08/15 15:29:31 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		draw_map_in_img(t_env *env, t_dot_3d **dots)
{
	t_dot_3d	d0;
	t_dot_3d	d1;
	int 		line;
	int 		column;

	line = -1;
	while (++line < env->s_map.lines)
	{
		column = -1;
		while (++column < env->s_map.columns)
		{
			dot_3d_to_2d(&d0, &dots[line][column], &env->s_view);
			if (line + 1 < env->s_map.lines)
			{
				dot_3d_to_2d(&d1, &dots[line + 1][column], &env->s_view);
				draw_line_in_img(&d0, &d1, env);
			}
			if (column + 1 < env->s_map.columns)
			{
				dot_3d_to_2d(&d1, &dots[line][column + 1], &env->s_view);
				draw_line_in_img(&d0, &d1, env);
			}
		}
	}
}

void			render(t_env *env)
{
	calculate_3d_map(&env->s_map, &env->s_view);

	if (env->s_img.img_ptr)
		delete_image(env->mlx_ptr, &env->s_img);
	make_image(env->mlx_ptr, &env->s_img);
	fill_image_background(&env->s_img, FDF_COLOR_GRAY);
	draw_map_in_img(env, env->s_map.dots_curr);

	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->s_img.img_ptr, 0, 0);
	print_info_to_win(env->mlx_ptr, env->win_ptr, &env->s_map, &env->s_view);
}
