/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:08 by null              #+#    #+#             */
/*   Updated: 2018/08/14 16:10:53 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x_dots(t_env *env, int angle)
{
	t_dot_3d	**dots = env->s_map.dots;
	double 		prev_y;
	double 		prev_z;
	int 		line;
	int 		column;

	line = -1;
	while (++line < env->s_map.lines)
	{
		column = -1;
		while (++column < env->s_map.columns)
		{
			prev_y = dots[line][column].y;
			prev_z = dots[line][column].z;
			dots[line][column].y = prev_y * cos(angle) - prev_z * sin(angle);
			dots[line][column].z = prev_y * sin(angle) + prev_z * cos(angle);
		}
	}
	env->s_view.x_angle += angle;
}

void	rotate_y_dots(t_env *env, int angle)
{
	t_dot_3d	**dots = env->s_map.dots;
	double 		prev_x;
	double 		prev_z;
	int 		line;
	int 		column;

	line = -1;
	while (++line < env->s_map.lines)
	{
		column = -1;
		while (++column < env->s_map.columns)
		{
			prev_x = dots[line][column].x;
			prev_z = dots[line][column].z;
			dots[line][column].x = prev_x * cos(angle) + prev_z * sin(angle);
			dots[line][column].z = -prev_x * sin(angle) + prev_z * cos(angle);
		}
	}
	env->s_view.y_angle += angle;
}

void	rotate_z_dots(t_env *env, int angle)
{
	t_dot_3d	**dots = env->s_map.dots;
	double 		prev_x;
	double 		prev_y;
	int 		line;
	int 		column;

	line = -1;
	while (++line < env->s_map.lines)
	{
		column = -1;
		while (++column < env->s_map.columns)
		{
			prev_x = dots[line][column].x;
			prev_y = dots[line][column].y;
			dots[line][column].x = prev_x * cos(angle) - prev_y * sin(angle);
			dots[line][column].y = prev_x * sin(angle) + prev_y * cos(angle);
		}
	}
	env->s_view.z_angle += angle;
}
