/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:25:33 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/01 20:03:46 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	str_bytes_to_print(t_pf *arg, char *str)
{
	size_t	str_bytes;

	str_bytes = ft_strlen(str);
	if ((arg->flags & FLAG_GOT_PRECISION) && str_bytes > arg->precision)
		str_bytes = arg->precision;
	return (str_bytes);
}

void	str_pre_padding(t_pf *arg, t_buff *arg_buff, size_t str_bytes_to_print)
{
	char	char_to_fill;

	char_to_fill = (char)(arg->flags & FLAG_ZERO ? '0' : ' ');
	while (!(arg->flags & FLAG_MINUS) && arg->width-- > str_bytes_to_print)
	{
		if (arg_buff->index >= arg_buff->size)
			buff_realloc(arg_buff);
		(arg_buff->buff)[arg_buff->index++] = char_to_fill;
	}
}

void	str_post_padding(t_pf *arg, t_buff *arg_buff, size_t str_bytes_to_print)
{
	char	char_to_fill;

	char_to_fill = ' ';
	while ((arg->flags & FLAG_MINUS) && arg->width-- > str_bytes_to_print)
	{
		if (arg_buff->index >= arg_buff->size)
			buff_realloc(arg_buff);
		(arg_buff->buff)[arg_buff->index++] = char_to_fill;
	}
}

void	fill_str(t_buff *arg_buff, char *str, size_t str_bytes)
{
	while (str_bytes--)
	{
		if (arg_buff->index >= arg_buff->size)
			buff_realloc(arg_buff);
		arg_buff->buff[arg_buff->index++] = *str++;
	}
}

void	handle_string(t_pf *arg, t_buff *arg_buff, wchar_t *str)
{
	size_t	str_bytes;

	prepare_string_arg(arg);
	if (!str)
	{
		arg->specifier = 's';
		str = (wchar_t *)"(null)";
	}
	if (arg->specifier == 'S')
		str_bytes = wstr_bytes_to_print(arg, str);
	else
		str_bytes = str_bytes_to_print(arg, (char *)str);
	str_pre_padding(arg, arg_buff, str_bytes);
	if (arg->specifier == 's')
		fill_str(arg_buff, (char *)str, str_bytes);
	if (arg->specifier == 'S')
		fill_wide_str(arg, arg_buff, str, str_bytes);
	str_post_padding(arg, arg_buff, str_bytes);
}
