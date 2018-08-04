/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:32:35 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/15 11:32:36 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*struct_memalloc(t_gnl **t_cur, int fd)
{
	if (!((*t_cur) = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (0);
	(*t_cur)->fd = fd;
	if (!((*t_cur)->b = (char *)ft_memalloc(BUFF_SIZE + 1)))
	{
		free(*t_cur);
		return (0);
	}
	return (*t_cur);
}

static t_gnl	*create_get_fdstruct(t_gnl **t_head, int fd)
{
	t_gnl		*temp;

	temp = 0;
	if (!(*t_head))
		return (struct_memalloc(t_head, fd));
	temp = *t_head;
	while (temp->next && temp->fd != fd)
		temp = temp->next;
	if (temp->fd != fd)
	{
		if (!(temp = struct_memalloc(&temp, fd)))
			return (0);
		temp->next = *t_head;
		*t_head = temp;
	}
	return (temp);
}

static int		paste_to_line(t_gnl *t_c, char **line, long n)
{
	char		*temp;

	if (!n)
	{
		if (!(temp = (char *)ft_memalloc(ft_strlen(*line) +\
			ft_strlen(t_c->b) + 1)))
			return (0);
		temp = ft_strcpy(temp, *line);
		ft_strcpy(temp + ft_strlen(*line), t_c->b);
		ft_strdel(line);
		*line = ft_strdup(temp);
		ft_bzero(t_c->b, BUFF_SIZE);
		ft_strdel(&temp);
		return (t_c->bslshn = 1);
	}
	n = n - (long)t_c->b;
	temp = (char *)ft_memalloc(ft_strlen(*line) + n + 1);
	temp = ft_strcpy(temp, *line);
	ft_strncpy(temp + ft_strlen(*line), t_c->b, n);
	ft_strdel(line);
	*line = ft_strdup(temp);
	t_c->b = (char *)ft_memmove(t_c->b, t_c->b + n + 1, BUFF_SIZE - n - 1);
	ft_bzero(t_c->b + BUFF_SIZE - n - 1, n + 1);
	ft_strdel(&temp);
	return (t_c->bslshn = 0);
}

static int		write_to_line(t_gnl *t_cur, char **line)
{
	long		n;

	if (!(*(t_cur->b)))
	{
		if (!(t_cur->rdn = read(t_cur->fd, t_cur->b, BUFF_SIZE)))
		{
			if (t_cur->bslshn == 1 && t_cur->rdn == 0)
				return (t_cur->bslshn = 0);
			return (t_cur->rdn == -1 ? -1 : -2);
		}
		t_cur->bufflen = (int)ft_strlen(t_cur->b);
	}
	if (*(t_cur->b))
	{
		n = (long)ft_strchr(t_cur->b, '\n');
		return (paste_to_line(t_cur, line, n));
	}
	return (-1);
}

int				ft_gnl(const int fd, char **line)
{
	static t_gnl	*t_head;
	t_gnl			*t_cur;
	int				i;

	if (fd < 0 || !line)
		return (-1);
	if (!(t_cur = create_get_fdstruct(&t_head, fd)))
		return (-1);
	i = 1;
	if (!(*line = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while (i > 0)
		i = write_to_line(t_cur, line);
	if (i == -2)
		return (0);
	return ((i == -1) ? -1 : 1);
}
