/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:07:32 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/16 11:10:05 by astrelov         ###   ########.fr       */
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

	if (key == KEY_ESC_MAC)
		close_action();
	if (key == KEY_LEFT_ARROW_MAC || key == KEY_RIGHT_ARROW_MAC || key == KEY_UP_ARROW_MAC || key == KEY_DOWN_ARROW_MAC)
		move_map_action(key, env);
	if (key == KEY_Q_MAC || key == KEY_W_MAC || key == KEY_E_MAC || key == KEY_1_MAC || key == KEY_2_MAC || key == KEY_3_MAC)
		rotate_axis_action(key, env);
	if (key == KEY_MINUS_MAC || key == KEY_PLUS_MAC)
		change_land_height_action(key, env);
	if (key == KEY_TAB_MAC)
		help_toggle_action(env);
	if (key == KEY_BACKSPACE_MAC)
		reset_view_action(env);
	return (0);
}

int		handle_mouse_click(int button, int x, int y, t_env *env)
{
	ft_dprintf(fd_logfile, "Mouse click event. key: %d, x: %d, y: %d\n", button, x, y); // DEBUG

	if (button == MOUSE_WHEEL_UP_MAC || button == MOUSE_WHEEL_DOWN_MAC)
		zoom_action(button, env);
	return (0);
}
