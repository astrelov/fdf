/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:22:02 by null              #+#    #+#             */
/*   Updated: 2018/08/15 15:25:20 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		calculate_2d_line_y(int x, t_dot_3d *d0, t_dot_3d *d1)
{
	return (int)round((x - d0->x) * (d1->y - d0->y) / (d1->x - d0->x) + d0->y);
}

int		calculate_2d_line_x(int y, t_dot_3d *d0, t_dot_3d *d1)
{
	return (int)round((y - d0->y) * (d1->x - d0->x) / (d1->y - d0->y) + d0->x);
}

void	dot_3d_to_2d(t_dot_3d *dot_2d, t_dot_3d *dot_3d, t_view *s_view)
{
	dot_2d->x = (int)((dot_3d->x * s_view->cam_dist /
					   (dot_3d->z + s_view->cam_dist)) *
					  s_view->zoom_multiplier + s_view->x_2d_shift);
	dot_2d->y = (int)((-dot_3d->y * s_view->cam_dist /
					   (dot_3d->z + s_view->cam_dist)) *
					  s_view->zoom_multiplier + s_view->y_2d_shift);
}
