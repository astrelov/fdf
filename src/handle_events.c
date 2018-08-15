/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:07:32 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/15 13:13:04 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_action()
{
	ft_dprintf(fd_logfile, "Close event.\n"); // DEBUG
	system("leaks -q fdf"); // DEBUG

	exit(0);
}

int 	handle_key_pressed(int key, t_env *env)
{
	ft_dprintf(fd_logfile, "Keyboard key press event. key: %d\n", key); // DEBUG

	if (key == KEY_ESC_MAC || key == KEY_ESC_WINDOWS)
		close_action();
	if (key == KEY_LEFT_ARROW || key == KEY_RIGHT_ARROW || key == KEY_UP_ARROW || key == KEY_DOWN_ARROW)
		move_map_action(key, env);
	if (key == KEY_Q || key == KEY_W || key == KEY_E || key == KEY_1 || key == KEY_2 || key == KEY_3)
		rotate_axis_action(key, env);
	if (key == KEY_MINUS || key == KEY_PLUS)
	{
		change_land_height_action(key, env);
		render(env);
	}
	if (key == KEY_TAB)
		help_toggle_action(env);
	if (key == KEY_BACKSPACE)
		reset_view_action(env);
	return (0);
}

int		handle_mouse_click(int button, int x, int y, t_env *env)
{
	ft_dprintf(fd_logfile, "Mouse click event. key: %d, x: %d, y: %d\n", button, x, y); // DEBUG

	if (button == MOUSE_WHEEL_UP)
		zoom_in_action(env);
	if (button == MOUSE_WHEEL_DOWN)
		zoom_out_action(env);
	return (0);
}
