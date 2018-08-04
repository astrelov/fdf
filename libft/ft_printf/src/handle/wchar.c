/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:21:07 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 16:48:22 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t		wide_char_bytes(wchar_t chr)
{
	size_t	binary_len;
	int		tmp;

	binary_len = 0;
	tmp = chr;
	while (tmp)
	{
		tmp /= 2;
		binary_len++;
	}
	if (binary_len <= 7)
		return (1);
	if (binary_len <= 11)
		return (2);
	if (binary_len <= 16)
		return (3);
	return (4);
}

void		one_byte(t_buff *arg_buff, unsigned int chr)
{
	(arg_buff->buff)[arg_buff->index++] = chr;
}

void		two_bytes(t_buff *arg_buff, unsigned int chr)
{
	int				mask;
	unsigned char	o1;
	unsigned char	o2;

	mask = 49280;
	o1 = ((chr >> 6) << 27) >> 27;
	o2 = (chr << 26) >> 26;
	(arg_buff->buff)[arg_buff->index++] = (mask >> 8) | o1;
	(arg_buff->buff)[arg_buff->index++] = ((mask << 24) >> 24) | o2;
}

void		three_bytes(t_buff *arg_buff, unsigned int chr)
{
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;

	mask = 14712960;
	o1 = ((chr >> 12) << 28) >> 28;
	o2 = ((chr >> 6) << 26) >> 26;
	o3 = (chr << 26) >> 26;
	(arg_buff->buff)[arg_buff->index++] = (mask >> 16) | o1;
	(arg_buff->buff)[arg_buff->index++] = ((mask << 16) >> 24) | o2;
	(arg_buff->buff)[arg_buff->index++] = ((mask << 24) >> 24) | o3;
}

void		four_bytes(t_buff *arg_buff, unsigned int chr)
{
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;

	mask = 4034953344;
	o1 = ((chr >> 18) << 29) >> 29;
	o2 = ((chr >> 12) << 26) >> 26;
	o3 = ((chr >> 6) << 26) >> 26;
	o4 = (chr << 26) >> 26;
	(arg_buff->buff)[arg_buff->index++] = (mask >> 24) | o1;
	(arg_buff->buff)[arg_buff->index++] = ((mask << 8) >> 24) | o2;
	(arg_buff->buff)[arg_buff->index++] = ((mask << 16) >> 24) | o3;
	(arg_buff->buff)[arg_buff->index++] = ((mask << 24) >> 24) | o4;
}
