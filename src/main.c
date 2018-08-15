/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:53:25 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/15 15:41:46 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	handle_file(char *file)
{
	t_env	env;

	if (open(file, O_DIRECTORY) > 0)
		ft_err_exit("ERROR: given path is a directory");
	ft_bzero(&env, sizeof(env));
	parse_map(file, &env);
	if (!(env.mlx_ptr = mlx_init()))
		ft_err_exit("ERROR: mlx failed to initialize");
	env.win_ptr = mlx_new_window(env.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, file);

	set_initial_view_params(&env.s_view, &env.s_map);
	render(&env);

	mlx_key_hook(env.win_ptr, handle_key_pressed, &env);
	mlx_mouse_hook(env.win_ptr, handle_mouse_click, &env);
	mlx_hook(env.win_ptr, 17, 0, close_action, NULL);
	system("leaks -q env"); // DEBUG
	mlx_loop(env.mlx_ptr);
}

int		main(int ac, char **av)
{
	system("rm -f file.log && touch file.log"); // DEBUG
	fd_logfile = open("file.log", O_RDWR); // DEBUG

	if (ac == 1)
		print_usage();
	if (ac > 1)
		handle_file(av[1]);
	return (0);
}
