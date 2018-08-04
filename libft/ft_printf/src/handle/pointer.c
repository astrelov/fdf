/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:10:42 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 16:52:11 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../../libft.h"

void	print_hash_ptr(t_buff *arg_buff)
{
	push_chars(arg_buff, '0', 1);
	push_chars(arg_buff, 'x', 1);
}

void	pre_padding_ptr(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	if (arg->width > arg->precision + 2 && arg->width > nbr_len + 2 &&
			!(arg->flags & FLAG_MINUS) && !(arg->flags & FLAG_ZERO))
	{
		if (arg->precision > nbr_len)
			push_chars(arg_buff, ' ', arg->width - arg->precision - 2);
		else
			push_chars(arg_buff, ' ', arg->width - nbr_len - 2);
	}
}

void	fill_ptr(t_pf *arg, t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	print_hash_ptr(arg_buff);
	if (arg->precision > nbr_len)
		push_chars(arg_buff, '0', arg->precision - nbr_len);
	while (nbr_len--)
		(arg_buff->buff)[arg_buff->index++] = *nbr_str++;
}

void	post_padding_ptr(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	char	char_to_fill;

	char_to_fill = ' ';
	if ((arg->flags & FLAG_ZERO) && !(arg->flags & FLAG_MINUS))
		char_to_fill = '0';
	if (arg->width > arg->precision + 2 && arg->width > nbr_len + 2 &&
			(arg->flags & FLAG_MINUS || arg->flags & FLAG_ZERO))
	{
		if (arg->precision > nbr_len)
			push_chars(arg_buff, char_to_fill, arg->width -
					arg->precision - 2);
		else
			push_chars(arg_buff, char_to_fill, arg->width - nbr_len - 2);
	}
}

void	handle_pointer(t_pf *arg, t_buff *arg_buff, size_t nbr)
{
	char	*nbr_str;
	size_t	nbr_len;
	size_t	bytes_left;

	arg->base = 16;
	arg->length = LENGTH_SIZE_T;
	nbr_str = stringify_nbr(arg, nbr);
	nbr_len = ft_strlen(nbr_str);
	if (nbr == 0 && arg->flags & FLAG_GOT_PRECISION && !arg->precision)
		nbr_len = 0;
	bytes_left = arg_buff->size - arg_buff->index;
	while (bytes_left < nbr_len || bytes_left < arg->width ||
			bytes_left < arg->precision)
	{
		buff_realloc(arg_buff);
		bytes_left = arg_buff->size - arg_buff->index;
	}
	pre_padding_ptr(arg, arg_buff, nbr_len);
	fill_ptr(arg, arg_buff, nbr_str, nbr_len);
	post_padding_ptr(arg, arg_buff, nbr_len);
	ft_memdel((void **)&nbr_str);
}
