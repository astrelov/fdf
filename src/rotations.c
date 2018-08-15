/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:08 by null              #+#    #+#             */
/*   Updated: 2018/08/15 11:32:02 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate_x_dots(int lines, int columns, t_dot_3d **dots, double angle)
{
	double 	prev_y;
	double 	prev_z;
	int 	line;
	int 	column;

	angle = angle * M_PI / 180;
	line = -1;
	while (++line < lines)
	{
		column = -1;
		while (++column < columns)
		{
			prev_y = dots[line][column].y;
			prev_z = dots[line][column].z;
			dots[line][column].y = prev_y * cos(angle) - prev_z * sin(angle);
			dots[line][column].z = prev_y * sin(angle) + prev_z * cos(angle);
		}
	}
}

static void	rotate_y_dots(int lines, int columns, t_dot_3d **dots, double angle)
{
	double 	prev_x;
	double 	prev_z;
	int 	line;
	int 	column;

	angle = angle * M_PI / 180;
	line = -1;
	while (++line < lines)
	{
		column = -1;
		while (++column < columns)
		{
			prev_x = dots[line][column].x;
			prev_z = dots[line][column].z;
			dots[line][column].x = prev_x * cos(angle) + prev_z * sin(angle);
			dots[line][column].z = -prev_x * sin(angle) + prev_z * cos(angle);
		}
	}
}

static void	rotate_z_dots(int lines, int columns, t_dot_3d **dots, double angle)
{
	double 	prev_x;
	double 	prev_y;
	int 	line;
	int 	column;

	angle = angle * M_PI / 180;
	line = -1;
	while (++line < lines)
	{
		column = -1;
		while (++column < columns)
		{
			prev_x = dots[line][column].x;
			prev_y = dots[line][column].y;
			dots[line][column].x = prev_x * cos(angle) - prev_y * sin(angle);
			dots[line][column].y = prev_x * sin(angle) + prev_y * cos(angle);
		}
	}
}

void		rotate_dots_3_axis(t_map *s_map, t_view *s_view)
{
	rotate_x_dots(s_map->lines, s_map->columns, s_map->dots_curr, s_view->x_angle);
	rotate_y_dots(s_map->lines, s_map->columns, s_map->dots_curr, s_view->y_angle);
	rotate_z_dots(s_map->lines, s_map->columns, s_map->dots_curr, s_view->z_angle);
}
