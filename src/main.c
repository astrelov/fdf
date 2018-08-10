/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:53:25 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/08 13:42:06 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_file(char *file)
{
	t_fdf	fdf;

	parse_map(file, &fdf);
	if (!(fdf.mlx_ptr = mlx_init()))
		ft_err_exit("ERROR: mlx failed to initialize");
	fdf.win_width = 500;
	fdf.win_height = 500;
	ft_bzero(&fdf.img_struct, sizeof(fdf.img_struct));
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.win_width, fdf.win_height, file);

	render(&fdf);

	mlx_key_hook(fdf.win_ptr, handle_key_pressed, &fdf);
	mlx_mouse_hook(fdf.win_ptr, handle_mouse_click, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, close_event, NULL);
	mlx_hook(fdf.win_ptr, 12, 0, handle_expose_event, &fdf);
//	mlx_hook(fdf.win_ptr, 6, 0, handle_mouse_movement, &fdf);
//	mlx_loop_hook(fdf.mlx_ptr, &render, &fdf);
	system("leaks -q fdf");
	mlx_loop(fdf.mlx_ptr);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_err_exit("ERROR: wrong number of arguments (must be 1)");
	handle_file(av[1]);
	return (0);
}
