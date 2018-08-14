/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:07:32 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/14 16:59:40 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				close_event()
{
	ft_dprintf(fd_logfile, "Close event.\n");
	system("leaks -q fdf"); // DEBUG
	exit(0);
}

int 			handle_expose_event(t_env *env)
{
	env += 0;
	ft_dprintf(fd_logfile, "Expose event.\n"); // DEBUG
	return (0);
}

static void		move_map(int key, t_env *env)
{
	if (key == KEY_RIGHT_ARROW)
		env->s_view.x_2d_shift -= 100;
	if (key == KEY_LEFT_ARROW)
		env->s_view.x_2d_shift += 100;
	if (key == KEY_DOWN_ARROW)
		env->s_view.y_2d_shift -= 50;
	if (key == KEY_UP_ARROW)
		env->s_view.y_2d_shift += 50;
	render(env);
}

void 			rotate(int key, t_env *env)
{
	if (key == KEY_Q)
		rotate_z_dots(env, ROTATE_Z_ANGLE);
	if (key == KEY_W)
		rotate_z_dots(env, -ROTATE_Z_ANGLE);
	if (key == KEY_A)
		rotate_y_dots(env, ROTATE_Y_ANGLE);
	if (key == KEY_S)
		rotate_y_dots(env, -ROTATE_Y_ANGLE);
	if (key == KEY_E)
		rotate_x_dots(env, ROTATE_X_ANGLE);
	if (key == KEY_D)
		rotate_x_dots(env, -ROTATE_X_ANGLE);
	render(env);
}

void			change_land_height(int key, t_env *env)
{
	double 		multiplier;
	int 		line;
	int 		column;

	multiplier = (key == KEY_2) ? 2 : 0.5;
	line = -1;
	while (++line < env->s_map.lines)
	{
		column = -1;
		while (++column < env->s_map.columns)
			env->s_map.dots[line][column].z *= multiplier;
	}
	render(env);
}

int 			handle_key_pressed(int key, t_env *env)
{
	ft_dprintf(fd_logfile, "Keyboard key press event. key: %d\n", key); // DEBUG

	if (key == KEY_ESC_MAC || key == KEY_ESC_WINDOWS)
		close_event();
	if (key == KEY_LEFT_ARROW || key == KEY_RIGHT_ARROW || key == KEY_UP_ARROW || key == KEY_DOWN_ARROW)
		move_map(key, env);
	if (key == KEY_Q || key == KEY_W || key == KEY_E || key == KEY_A || key == KEY_S || key == KEY_D)
		rotate(key, env);
	if (key == KEY_1 || key == KEY_2)
		change_land_height(key, env);
	return (0);
}

int 			handle_mouse_movement(int x, int y, t_env *env)
{
	ft_dprintf(fd_logfile, "Mouse movement event. x: %d, y: %d\n", x, y); // DEBUG
	for (int i = 0; i < 2; i++) {
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x - i, y, 0xffffff);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x + i, y, 0xffffff);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y - i, 0xffffff);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y + i, 0xffffff);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x - i, y - i, 0xffffff);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x + i, y - i, 0xffffff);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x - i, y + i, 0xffffff);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x + i, y + i, 0xffffff);
	}
	return (0);
}
//
//void			draw_line_in_window(t_dot_3d *d0, t_dot_3d *d1, t_env *env)
//{
//	ft_dprintf(fd_logfile, "DRAW_LINE: x0=%d, y0=%d, x1=%d, y1=%d\n", d0->x, d0->y, d1->x, d1->y); // DEBUG
//	if (d0->x < d1->x)
//		for (int i = (int)d0->x; i < d1->x; i++)
//			mlx_pixel_put(env->mlx_ptr, env->win_ptr, i, calculate_line_y(i, d0->x, d0->y, d1->x, d1->y), 0xffffff);
//	else
//		for (int i = (int)d1->x; i < d0->x; i++)
//			mlx_pixel_put(env->mlx_ptr, env->win_ptr, i, calculate_line_y(i, d1->x, d1->y, d0->x, d0->y), 0xffffff);
//
//	if (d0->y < d1->y)
//		for (int i = (int)d0->y; i < d1->y; i++)
//			mlx_pixel_put(env->mlx_ptr, env->win_ptr, calculate_line_x(i, d0->x, d0->y, d1->x, d1->y), i, 0xffffff);
//	else
//		for (int i = (int)d1->y; i < d0->y; i++)
//			mlx_pixel_put(env->mlx_ptr, env->win_ptr, calculate_line_x(i, d1->x, d1->y, d0->x, d0->y), i, 0xffffff);
//}

//static void		mouse_click_left_button(int x, int y, t_env *env)
//{
//	static int	prev_x = 0;
//	static int	prev_y = 0;
//	static int	first_click = TRUE;
//
//	if (first_click)
//		first_click = FALSE;
//	else
////		draw_line_in_window(prev_x, prev_y, x, y, env);
//		;
//	prev_x = x;
//	prev_y = y;
//}

static void		zoom_in(t_env *env)
{
	env->s_view.x_multiplier *= 1.2;
	env->s_view.yz_multiplier = env->s_view.x_multiplier / 2;
//	env->s_view.x_2d_shift = (int)(WIN_WIDTH / 1.5 - env->s_map.columns * env->s_view.x_multiplier);
	render(env);
}

static void		zoom_out(t_env *env)
{
	env->s_view.x_multiplier /= 1.2;
	env->s_view.yz_multiplier = env->s_view.x_multiplier / 2;
//	env->s_view.x_2d_shift = (int)(WIN_WIDTH / 1.5 - env->s_map.columns * env->s_view.x_multiplier);
	render(env);
}

int				handle_mouse_click(int button, int x, int y, t_env *env)
{
	ft_dprintf(fd_logfile, "Mouse click event. key: %d, x: %d, y: %d\n", button, x, y); // DEBUG

	if (button == MOUSE_LEFT_BUTTON)
//		mouse_click_left_button(x, y, env);
	{

	}
	if (button == MOUSE_WHEEL_UP)
		zoom_in(env);
	if (button == MOUSE_WHEEL_DOWN)
		zoom_out(env);
	return (0);
}
