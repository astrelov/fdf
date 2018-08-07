/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:02:31 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/06 17:35:06 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
#define FDF_FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <mlx_int.h>

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			size_line;
	int			bpp;
	int			width;
	int			height;
	int 		endian;
}				t_image;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
	int 		win_width;
	int 		win_height;
}				t_fdf;

void			error(char *err);

void			parse_map(char *file, t_fdf *fdf);
int				render(t_fdf *fdf);

#endif
