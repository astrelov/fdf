/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:53:25 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/15 13:14:20 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		set_initial_view(t_env *env)
{
	env->s_view.x_angle = ROTATE_X_ANGLE * 0;
	env->s_view.y_angle = ROTATE_Y_ANGLE * 0;
	env->s_view.z_angle = ROTATE_Z_ANGLE * 0;
	env->s_view.zoom_multiplier = (int)(WIN_WIDTH / 1.5 / env->s_map.columns);
	env->s_view.x_2d_shift = WIN_WIDTH / 2;
	env->s_view.y_2d_shift = WIN_HEIGHT / 2;
	env->s_view.cam_dist = (int)ft_d_sqrt(env->s_map.columns * env->s_map.lines);
	env->s_view.info_color = 0x000000;
	env->s_map.z_multiplier = 1;
}

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

	set_initial_view(&env);
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

	if (ac != 2)
		ft_err_exit("ERROR: wrong number of arguments (must be 1)");
	handle_file(av[1]);
	return (0);
}
