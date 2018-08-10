/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:07:32 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/07 17:02:27 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_event()
{
	ft_printf("Close event.\n");
	exit(0);
}

int 	handle_expose_event(t_fdf *fdf)
{
	fdf += 0;
	ft_printf("Expose event.\n");
	return (0);
}

int 	handle_key_pressed(int key, t_fdf *fdf)
{
	fdf += 0;
	ft_printf("Keyboard key press event. key: %d\n", key);
	if (key == KEY_ESC)
		close_event();
	return (0);
}

int 	handle_mouse_movement(int x, int y, t_fdf *fdf)
{
	ft_printf("Mouse movement event. x: %d, y: %d\n", x, y);
	for (int i = 0; i < 2; i++) {
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x - i, y, 0xffffff);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x + i, y, 0xffffff);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y - i, 0xffffff);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y + i, 0xffffff);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x - i, y - i, 0xffffff);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x + i, y - i, 0xffffff);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x - i, y + i, 0xffffff);
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x + i, y + i, 0xffffff);
	}
	return (0);
}

int		calculate_line_y(int x, int x0, int y0, int x1, int y1)
{
	return (int)lround((x - x0) * (y1 - y0) / (x1 - x0) + y0);
}

int		calculate_line_x(int y, int x0, int y0, int x1, int y1)
{
	return (int)lround((y - y0) * (x1 - x0) / (y1 - y0) + x0);
}

int		handle_mouse_click(int button, int x, int y, t_fdf *fdf)
{
	button += 0;
	fdf += 0;
	static int	x_prev = 0;
	static int	y_prev = 0;
	static int	first_click = TRUE;
	if (first_click)
		first_click = FALSE;
	else
	{
		if (x < x_prev)
			for (int i = x; i < x_prev; i++)
				mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, calculate_line_y(i, x, y, x_prev, y_prev), 0xffffff);
		else
			for (int i = x_prev; i < x; i++)
				mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, calculate_line_y(i, x_prev, y_prev, x, y), 0xffffff);

		if (y < y_prev)
			for (int i = y; i < y_prev; i++)
				mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, calculate_line_x(i, x, y, x_prev, y_prev), i, 0xffffff);
		else
			for (int i = y_prev; i < y; i++)
				mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, calculate_line_x(i, x_prev, y_prev, x, y), i, 0xffffff);
	}
	x_prev = x;
	y_prev = y;
//	ft_printf("Mouse click event. key: %d, x: %d, y: %d\n", button, x, y);
//	fill_image_pixel(fdf->img_struct.img_ptr, x, y, 0xffffff);
//	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xffffff);
//	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
//	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_struct.img_ptr, 0, 0);
	return (0);
}
