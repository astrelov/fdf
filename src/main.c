/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:53:25 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/06 10:36:43 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error(char *err)
{
	ft_printf("ERROR: %s\n", err);
	exit(0);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;

	ac += 0;
	av += 0;
	if (ac != 2)
		error("wrong number of arguments (must be 1)");
	parse_map(av[1], &fdf);
	if (!(fdf.mlx_ptr = mlx_init()))
		error("mlx failed to initialize");
	fdf.win_width = 500;
	fdf.win_height = 500;
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.win_width, fdf.win_height, av[1]);
	mlx_loop_hook(fdf.mlx_ptr, &render, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
