/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:02:31 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/05 22:02:01 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
#define FDF_FDF_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int 		win_width;
	int 		win_height;
}				t_fdf;

void			error(char *err);

void			parse_map(char *file, t_fdf *fdf);
int				render(t_fdf *fdf);

#endif
