/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:15:12 by null              #+#    #+#             */
/*   Updated: 2018/08/15 20:15:12 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void 		rotate_xy_dots(t_rotate *r, t_dot_3d **dots)
{
	while (++r->line < r->lines)
	{
		r->column = -1;
		while (++r->column < r->columns)
		{
			r->prev_x = dots[r->line][r->column].x;
			r->prev_y = dots[r->line][r->column].y;
			r->prev_z = dots[r->line][r->column].z;
			dots[r->line][r->column].x = r->prev_x * cos(r->y_angle) +
				r->prev_z * sin(r->y_angle);
			dots[r->line][r->column].y = r->prev_x * sin(r->x_angle) *
				sin(r->y_angle) + r->prev_y * cos(r->x_angle) - r->prev_z *
				sin(r->x_angle) * cos(r->y_angle);
			dots[r->line][r->column].z = -r->prev_x * sin(r->y_angle) *
				cos(r->x_angle) + r->prev_y * sin(r->x_angle) + r->prev_z *
				cos(r->x_angle) * cos(r->y_angle);
		}
	}
}

void 		rotate_xz_dots(t_rotate *r, t_dot_3d **dots)
{
	while (++r->line < r->lines)
	{
		r->column = -1;
		while (++r->column < r->columns)
		{
			r->prev_x = dots[r->line][r->column].x;
			r->prev_y = dots[r->line][r->column].y;
			r->prev_z = dots[r->line][r->column].z;
			dots[r->line][r->column].x = r->prev_x * cos(r->z_angle) -
				r->prev_y * sin(r->z_angle);
			dots[r->line][r->column].y = r->prev_x * cos(r->x_angle) *
				sin(r->z_angle) + r->prev_y * cos(r->x_angle) *
				cos(r->z_angle) - r->prev_z * sin(r->x_angle);
			dots[r->line][r->column].z = r->prev_x * sin(r->x_angle) *
				sin(r->z_angle) + r->prev_y * sin(r->x_angle) *
				cos(r->z_angle) + r->prev_z * cos(r->x_angle);
		}
	}
}

void 		rotate_yz_dots(t_rotate *r, t_dot_3d **dots)
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
				cos(r->z_angle) - r->prev_y * sin(r->z_angle) *
				cos(r->y_angle) + r->prev_z * sin(r->y_angle);
			dots[r->line][r->column].y = r->prev_x * sin(r->z_angle) +
				r->prev_y * cos(r->z_angle);
			dots[r->line][r->column].z = -r->prev_x * sin(r->y_angle) *
				cos(r->z_angle) + r->prev_y * sin(r->y_angle) *
				sin(r->z_angle) + r->prev_z * cos(r->y_angle);
		}
	}
}

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
