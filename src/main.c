/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:53:25 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/14 16:57:15 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_view(t_env *env)
{
	env->s_view.x_multiplier = (int)(WIN_WIDTH / 1.5 / env->s_map.columns);
	env->s_view.yz_multiplier = env->s_view.x_multiplier / 2;
	env->s_view.x_2d_shift = WIN_WIDTH / 2;
	env->s_view.y_2d_shift = WIN_HEIGHT / 2;
}

void	handle_file(char *file)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	parse_map(file, &env);
	if (!(env.mlx_ptr = mlx_init()))
		ft_err_exit("ERROR: mlx failed to initialize");
	env.win_width = WIN_WIDTH;
	env.win_height = WIN_HEIGHT;
	env.win_ptr = mlx_new_window(env.mlx_ptr, env.win_width, env.win_height, file);

	set_view(&env);
//	rotate_x_dots(&env, 0);
//	rotate_y_dots(&env, 10);
//	rotate_z_dots(&env, 10);
	render(&env);

	mlx_key_hook(env.win_ptr, handle_key_pressed, &env);
	mlx_mouse_hook(env.win_ptr, handle_mouse_click, &env);
	mlx_hook(env.win_ptr, 17, 0, close_event, NULL);
	mlx_hook(env.win_ptr, 12, 0, handle_expose_event, &env);
//	mlx_hook(env.win_ptr, 6, 0, handle_mouse_movement, &env);
//	mlx_loop_hook(env.mlx_ptr, &render, &env);
	system("leaks -q env");
	mlx_loop(env.mlx_ptr);
}

int		main(int ac, char **av)
{
	system("rm -f file.log && touch file.log");
	fd_logfile = open("file.log", O_RDWR);

	if (ac != 2)
		ft_err_exit("ERROR: wrong number of arguments (must be 1)");
	handle_file(av[1]);
	return (0);
}
