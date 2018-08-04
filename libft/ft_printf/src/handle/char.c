/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:54:36 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 15:04:27 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		char_pre_padding(t_pf *arg, t_buff *arg_buff, size_t bytes)
{
	char	char_to_fill;

	char_to_fill = (char)(arg->flags & FLAG_ZERO ? '0' : ' ');
	while (!(arg->flags & FLAG_MINUS) && (arg->width)-- > bytes)
	{
		if (arg_buff->index >= arg_buff->size)
			buff_realloc(arg_buff);
		(arg_buff->buff)[arg_buff->index++] = char_to_fill;
	}
}

void		char_post_padding(t_pf *arg, t_buff *arg_buff, size_t bytes)
{
	while ((arg->flags & FLAG_MINUS) && (arg->width)-- > bytes)
	{
		if (arg_buff->index >= arg_buff->size)
			buff_realloc(arg_buff);
		(arg_buff->buff)[arg_buff->index++] = ' ';
	}
}

void		fill_wide_char(t_buff *arg_buff, unsigned int chr, size_t bytes)
{
	if (arg_buff->index + 4 >= arg_buff->size)
		buff_realloc(arg_buff);
	if (bytes == 1)
		one_byte(arg_buff, chr);
	else if (bytes == 2)
		two_bytes(arg_buff, chr);
	else if (bytes == 3)
		three_bytes(arg_buff, chr);
	else if (bytes == 4)
		four_bytes(arg_buff, chr);
}

void		fill_char(t_buff *arg_buff, char chr)
{
	push_chars(arg_buff, chr, 1);
}

void		handle_char(t_pf *arg, t_buff *arg_buff, wchar_t chr)
{
	size_t	bytes;

	if (arg->specifier == 'c' && arg->length == LENGTH_LONG)
		arg->specifier = 'C';
	bytes = arg->specifier == 'c' ? 1 : wide_char_bytes(chr);
	if (arg->specifier == 'c' || arg->specifier == 'C')
		char_pre_padding(arg, arg_buff, bytes);
	if (arg->specifier == 'c')
		fill_char(arg_buff, (char)chr);
	else
		fill_wide_char(arg_buff, (unsigned int)chr, bytes);
	if (arg->specifier == 'c' || arg->specifier == 'C')
		char_post_padding(arg, arg_buff, bytes);
}
