/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:02:31 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/14 16:57:15 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
#include <stdio.h>

# define KEY_ESC_MAC		53
# define KEY_ESC_WINDOWS	65307
# define KEY_RIGHT_ARROW	65363
# define KEY_LEFT_ARROW		65361
# define KEY_UP_ARROW		65362
# define KEY_DOWN_ARROW		65364
# define KEY_Q				113
# define KEY_W				119
# define KEY_E				101
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_1				49
# define KEY_2				50

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	3
# define MOUSE_WHEEL_UP		4
# define MOUSE_WHEEL_DOWN	5

# define FALSE				0
# define TRUE				1

# define WIN_WIDTH			1280
# define WIN_HEIGHT			720

# define ROTATE_X_ANGLE		5
# define ROTATE_Y_ANGLE		5
# define ROTATE_Z_ANGLE		5

# define FDF_COLOR_GRAY		0xa0a0a0

int 						fd_logfile; // DEBUG

typedef struct				s_image
{
	void					*img_ptr;
	char					*img_buff;
	int 					width;
	int 					height;
	int						bpp;
	int						size_line;
	int 					endian;
}							t_image;

typedef struct				s_dot_3d
{
	double 					x;
	double 					y;
	double 					z;
}							t_dot_3d;

typedef struct				s_map
{
	t_dot_3d				**dots;
	int 					lines;
	int						columns;
}							t_map;

//typedef struct				s_map
//{
//	int 					**dots;
//	int 					lines;
//	int						columns;
//}							t_map;

typedef struct				s_view
{
	int						x_2d_shift;
	int 					y_2d_shift;
	float 					x_multiplier;
	float 					yz_multiplier;
	int 					x_angle;
	int 					y_angle;
	int 					z_angle;
}							t_view;

typedef struct				s_env
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_image					s_img;
	t_map					s_map;
	t_view					s_view;
	int 					win_width;
	int 					win_height;
}							t_env;

void						make_image(t_env *env);
void						delete_image(t_env *env);

void						parse_map(char *file, t_env *env);
int							render(t_env *env);
void						fill_image_pixel(t_image *img, int x, int y, int color);

int 						handle_expose_event(t_env *env);
int 						handle_key_pressed(int key, t_env *env);
int							handle_mouse_click(int button, int x, int y, t_env *env);
int 						handle_mouse_movement(int x, int y, t_env *env);
int							close_event();

void						draw_line_in_window(t_dot_3d *d0, t_dot_3d *d1, t_env *env);
int							calculate_line_y(int x, t_dot_3d *d0, t_dot_3d *d1);
int							calculate_line_x(int y, t_dot_3d *d0, t_dot_3d *d1);

void						rotate_x_dots(t_env *env, int angle);
void						rotate_y_dots(t_env *env, int angle);
void						rotate_z_dots(t_env *env, int angle);

void						del(void *content, size_t content_size);
int							split_len(char **split);

#endif
