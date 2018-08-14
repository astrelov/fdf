/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sundry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:50:58 by null              #+#    #+#             */
/*   Updated: 2018/08/14 16:10:53 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		del(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	ft_memdel(&content);
}

int			split_len(char **split)
{
	int		len;

	len = -1;
	while (split[++len])
		;
	return (len);
}

int				calculate_line_y(int x, t_dot_3d *d0, t_dot_3d *d1)
{
	return (int)round((x - d0->x) * (d1->y - d0->y) / (d1->x - d0->x) + d0->y);
}

int				calculate_line_x(int y, t_dot_3d *d0, t_dot_3d *d1)
{
	return (int)round((y - d0->y) * (d1->x - d0->x) / (d1->y - d0->y) + d0->x);
}
