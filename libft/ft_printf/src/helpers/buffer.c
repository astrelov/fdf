/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:56:58 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/18 12:43:46 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	buff_realloc(t_buff *buff)
{
	char	*new_buff;
	size_t	i;

	if (!(buff->buff))
	{
		buff->size = 1 << 10;
		buff->buff = (char *)ft_memalloc(buff->size);
		return ;
	}
	new_buff = (char *)ft_memalloc(buff->size << 1);
	i = 0;
	while (i < buff->size)
	{
		new_buff[i] = (buff->buff)[i];
		i += 1;
	}
	free(buff->buff);
	buff->buff = new_buff;
	buff->size <<= 1;
}

void	concat_buffs(t_buff *buff, t_buff **arg_buff)
{
	size_t ind;

	ind = 0;
	while (ind < (*arg_buff)->index)
	{
		if (buff->index >= buff->size)
			buff_realloc(buff);
		(buff->buff)[buff->index++] = ((*arg_buff)->buff)[ind++];
	}
	free((*arg_buff)->buff);
	free(*arg_buff);
}
