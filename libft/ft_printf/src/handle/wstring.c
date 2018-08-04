/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:19:36 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 16:53:35 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	prepare_string_arg(t_pf *arg)
{
	if (arg->specifier == 's' && arg->length == LENGTH_LONG)
		arg->specifier = 'S';
}

size_t	wstr_bytes_to_print(t_pf *arg, wchar_t *str)
{
	size_t	str_bytes;
	size_t	char_bytes;

	str_bytes = 0;
	while (*str)
	{
		char_bytes = wide_char_bytes(*str++);
		if ((arg->flags & FLAG_GOT_PRECISION) && (str_bytes + char_bytes) >
														arg->precision)
			break ;
		str_bytes += char_bytes;
	}
	return (str_bytes);
}

void	fill_wide_str(t_pf *arg, t_buff *arg_buff, wchar_t *str,
						size_t str_bytes)
{
	size_t	char_bytes;

	char_bytes = wide_char_bytes(*str);
	while (str_bytes >= char_bytes)
	{
		handle_char(arg, arg_buff, *str++);
		str_bytes -= char_bytes;
		char_bytes = wide_char_bytes(*str);
	}
}
