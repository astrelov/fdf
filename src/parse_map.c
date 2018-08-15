/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:57:40 by null              #+#    #+#             */
/*   Updated: 2018/08/15 12:56:57 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_dot_3d		*make_dots_arr(char **split, t_env *env, int line_ind)
{
	char			*nbr_str;
	t_dot_3d		*dots;
	int				column_ind;

	if (!env->s_map.columns)
		if (!(env->s_map.columns = strsplit_len(split)))
			ft_err_exit("ERROR: empty line");
	dots = (t_dot_3d *)ft_memalloc(sizeof(t_dot_3d) * env->s_map.columns);
	column_ind = -1;
	while (split[++column_ind])
	{
		dots[column_ind].x = column_ind - env->s_map.columns / 2.0;
		dots[column_ind].y = line_ind - env->s_map.lines / 2.0;
		dots[column_ind].z = ft_atoi(split[column_ind]);
		nbr_str = ft_itoa((int)dots[column_ind].z);
		if (!ft_strequ(nbr_str, split[column_ind]))
			ft_err_exit("ERROR: coordinates must be integers");
		ft_strdel(&nbr_str);
	}
	if (column_ind != env->s_map.columns)
		ft_err_exit("ERROR: wrong amount of coordinates at some line");
	return (dots);
}

static void			make_3d_dots_2d_array(t_list *lst, t_env *env)
{
	char			**split;
	int				ind;

	env->s_map.lines = (int)ft_lstlen(lst);
	env->s_map.dots_initial = (t_dot_3d **)ft_memalloc(sizeof(t_dot_3d *) * env->s_map.lines);
	env->s_map.dots_curr = (t_dot_3d **)ft_memalloc(sizeof(t_dot_3d *) * env->s_map.lines);
	ind = 0;
	while (lst)
	{
		split = ft_strsplit(lst->content, ' ');
		env->s_map.dots_initial[ind] = make_dots_arr(split, env, ind);
		env->s_map.dots_curr[ind] = make_dots_arr(split, env, ind);
		ft_strsplit_del(&split);
		lst = lst->next;
		ind++;
	}
}

void				parse_map(char *file, t_env *env)
{
	int				fd;
	char			*line;
	t_list			*lst;
	t_list			*new;

	lst = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_err_exit("ERROR: failed to open file");
	while (ft_gnl(fd, &line) == 1)
	{
		if (!ft_strlen(line))
			ft_err_exit("ERROR: empty line in map description");
		new = ft_lstnew(line, ft_strlen(line) + 1);
		ft_lstadd(&lst, new);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);

	ft_lstrev(&lst);
	make_3d_dots_2d_array(lst, env);
	ft_lstdel(&lst, del);
}
