/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:02:31 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/07 16:50:59 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
#define FDF_FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define KEY_ESC	53

# define FALSE		0
# define TRUE		1

typedef struct		s_img
{
	void			*img_ptr;
	char			*img_buff;
	int 			width;
	int 			height;
	int				bpp;
	int				size_line;
	int 			endian;
}					t_img;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	int 			win_width;
	int 			win_height;
}					t_fdf;

void				error(char *err);

void				make_image(t_fdf *fdf);
void				delete_image(t_fdf *fdf);

void				parse_map(char *file, t_fdf *fdf);
int					render(t_fdf *fdf);
void				fill_image_pixel(t_img *img, int x, int y, int color);

int 	handle_expose_event(t_fdf *fdf);
int 	handle_key_pressed(int key, t_fdf *fdf);
int		handle_mouse_click(int button, int x, int y, t_fdf *fdf);
int 	handle_mouse_movement(int x, int y, t_fdf *fdf);
int		close_event();

#endif
