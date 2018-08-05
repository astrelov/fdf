/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:57:40 by null              #+#    #+#             */
/*   Updated: 2018/08/05 22:15:23 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	parse_map(char *file, t_fdf *fdf)
{
	fdf += 0;
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		error("failed to open file");
	while (ft_gnl(fd, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
