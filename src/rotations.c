/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:08 by null              #+#    #+#             */
/*   Updated: 2018/08/16 15:50:39 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotate_xyz_dots(t_rotate *r, t_dot_3d **dots)
{
	while (++r->line < r->lines)
	{
		r->column = -1;
		while (++r->column < r->columns)
		{
			r->prev_x = dots[r->line][r->column].x;
			r->prev_y = dots[r->line][r->column].y;
			r->prev_z = dots[r->line][r->column].z;
			dots[r->line][r->column].x = r->prev_x * cos(r->y_angle) *
					cos(r->z_angle) - r->prev_y * cos(r->y_angle) *
					sin(r->z_angle) + r->prev_z * sin(r->y_angle);
			dots[r->line][r->column].y = r->prev_x * (sin(r->x_angle) *
					sin(r->y_angle) * cos(r->z_angle) + cos(r->x_angle) *
					sin(r->z_angle)) + r->prev_y * (-sin(r->x_angle) *
					sin(r->y_angle) * sin(r->z_angle) + cos(r->x_angle) *
					cos(r->z_angle)) - r->prev_z * sin(r->x_angle) *
					cos(r->y_angle);
			dots[r->line][r->column].z = r->prev_x * (-cos(r->x_angle) *
					sin(r->y_angle) * cos(r->z_angle) + sin(r->x_angle) *
					sin(r->z_angle)) + r->prev_y * (cos(r->x_angle) *
					sin(r->y_angle) * sin(r->z_angle) + sin(r->x_angle) *
					cos(r->z_angle)) + r->prev_z * cos(r->x_angle) *
					cos(r->y_angle);
		}
	}
}

static void		fill_rotate_struct(t_rotate *r, t_map *s_map, t_view *s_view)
{
	r->lines = s_map->lines;
	r->columns = s_map->columns;
	r->x_angle = s_view->x_angle * M_PI / 180;
	r->y_angle = s_view->y_angle * M_PI / 180;
	r->z_angle = s_view->z_angle * M_PI / 180;
	r->line = -1;
}

void		rotate_dots_3_axis(t_map *s_map, t_view *s_view)
{
	t_rotate	r;

	fill_rotate_struct(&r, s_map, s_view);
	rotate_xyz_dots(&r, s_map->dots_curr);
}
