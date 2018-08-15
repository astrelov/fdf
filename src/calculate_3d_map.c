/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_3d_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:28:21 by null              #+#    #+#             */
/*   Updated: 2018/08/15 15:13:44 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void 	copy_initial_to_curr_dots(t_map *s_map)
{
	t_dot_3d	**dots_i;
	t_dot_3d	**dots_c;
	int 		line;
	int 		column;

	dots_i = s_map->dots_initial;
	dots_c = s_map->dots_curr;
	line = -1;
	while (++line < s_map->lines)
	{
		column = -1;
		while (++column < s_map->columns)
			ft_memcpy(&dots_c[line][column], &dots_i[line][column], sizeof(t_dot_3d));
	}
}

static void		multiply_map_heights(t_map *s_map)
{
	int 		line;
	int 		column;

	line = -1;
	while (++line < s_map->lines)
	{
		column = -1;
		while (++column < s_map->columns)
			s_map->dots_curr[line][column].z *= s_map->z_multiplier;
	}
}

void			calculate_3d_map(t_map *s_map, t_view *s_view)
{
	copy_initial_to_curr_dots(s_map);
	multiply_map_heights(s_map);
	rotate_dots_3_axis(s_map, s_view);
}
