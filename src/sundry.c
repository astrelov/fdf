/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sundry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:50:58 by null              #+#    #+#             */
/*   Updated: 2018/08/15 14:24:39 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	del(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	ft_memdel(&content);
}

int		strsplit_len(char **split)
{
	int		len;

	len = -1;
	while (split[++len])
		;
	return (len);
}

void	set_initial_view_params(t_view *s_view, t_map *s_map)
{
	s_view->x_angle = ROTATE_X_ANGLE * 7;
	s_view->y_angle = ROTATE_Y_ANGLE * 1;
	s_view->z_angle = ROTATE_Z_ANGLE * 11;
	s_view->zoom_multiplier = (int)(WIN_WIDTH / 1.5 / s_map->columns);
	s_view->x_2d_shift = WIN_WIDTH / 2;
	s_view->y_2d_shift = WIN_HEIGHT / 2;
	s_view->cam_dist = (int)ft_d_sqrt(s_map->columns * s_map->lines);
	s_view->info_color = 0x505050;
	s_map->z_multiplier = 0.5;
}
