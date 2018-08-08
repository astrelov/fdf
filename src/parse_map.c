/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:57:40 by null              #+#    #+#             */
/*   Updated: 2018/08/08 15:23:01 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		split_len(char **split)
{
	int		len;

	len = 0;
	while (split[len++])
		;
	return (len);
}

int		*make_int_arr2(char **split, t_fdf *fdf)
{
	char	*nbr_str;
	int		*arr;
	int		ind;

	fdf->map_struct.columns = split_len(split);
	arr = (int *)ft_memalloc(sizeof(int) * fdf->map_struct.columns);
	ind = -1;
	while (split[++ind])
	{
		arr[ind] = ft_atoi(split[ind]);
		nbr_str = ft_itoa(arr[ind]);
		if (!ft_strequ(nbr_str, split[ind]))
			ft_err_exit("ERROR: heights must be integers");
		ft_strdel(&nbr_str);
	}
	return (arr);
}

void	make_int_arr(t_list *lst, t_fdf *fdf)
{
	fdf += 0;
	char	**split;
	int		ind;

	fdf->map_struct.lines = (int)ft_lstlen(lst);
	fdf->map_struct.heights = (int **)ft_memalloc(sizeof(int *) * fdf->map_struct.lines);
	ind = 0;
	while (lst)
	{
		ft_putendl(lst->content);
		split = ft_strsplit(lst->content, ' ');
		fdf->map_struct.heights[ind++] = make_int_arr2(split, fdf);
		ft_strsplit_del(&split);
		lst = lst->next;
	}
}

void	del(void *content, size_t content_size)
{
	content_size += 0;
	free(content);
}

void	parse_map(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_err_exit("ERROR: failed to open file");
	while (ft_gnl(fd, &line))
	{
		if (!ft_strlen(line))
			ft_err_exit("ERROR: empty line in map description");
		new = ft_lstnew(line, ft_strlen(line));
		ft_lstadd(&lst, new);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);

	ft_lstrev(&lst);
	make_int_arr(lst, fdf);
	ft_lstdel(&lst, del);
}
