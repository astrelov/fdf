/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexademical.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:06:09 by astrelov          #+#    #+#             */
/*   Updated: 2018/04/20 16:58:55 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	print_hash_hex(t_pf *arg, t_buff *arg_buff)
{
	push_chars(arg_buff, '0', 1);
	push_chars(arg_buff, (char)(arg->flags & FLAG_UPPERCASE ? 'X' : 'x'), 1);
}

void	pre_padding_hexademical(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	char	char_to_fill;

	char_to_fill = (char)(arg->flags & FLAG_ZERO ? '0' : ' ');
	if (arg->flags & FLAG_ZERO && arg->flags & FLAG_HASH && nbr_len)
		print_hash_hex(arg, arg_buff);
	if (!(arg->flags & FLAG_MINUS))
	{
		if (arg->width > arg->precision && arg->precision > nbr_len)
			push_chars(arg_buff, char_to_fill, arg->width - arg->precision);
		if (arg->width > nbr_len && nbr_len > arg->precision &&
				(arg->flags & FLAG_GOT_PRECISION))
			push_chars(arg_buff, char_to_fill, arg->width - nbr_len);
		if (arg->width > arg->precision && arg->precision == nbr_len)
			push_chars(arg_buff, char_to_fill, arg->width - arg->precision);
		if (arg->width > nbr_len && !(arg->flags & FLAG_GOT_PRECISION))
			push_chars(arg_buff, char_to_fill, arg->width - nbr_len);
	}
	if (arg->precision > nbr_len)
	{
		if (arg->flags & FLAG_HASH && nbr_len)
			print_hash_hex(arg, arg_buff);
		push_chars(arg_buff, '0', arg->precision - nbr_len);
	}
}

void	fill_hexademical(t_pf *arg, t_buff *arg_buff, char *nbr_str,
						size_t nbr_len)
{
	if (arg->flags & FLAG_HASH && nbr_len >= arg->precision && nbr_len)
		if (!(nbr_len == 1 && *nbr_str == '0'))
			if (!(arg->width > nbr_len + 2 && (arg->flags & FLAG_ZERO)))
				print_hash_hex(arg, arg_buff);
	while (nbr_len--)
		(arg_buff->buff)[arg_buff->index++] = *nbr_str++;
}

void	post_padding_hexademical(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	if (arg->width > nbr_len && nbr_len > arg->precision)
		push_chars(arg_buff, ' ', arg->width - nbr_len);
	if (arg->width > arg->precision && arg->precision >= nbr_len)
		push_chars(arg_buff, ' ', arg->width - arg->precision);
}

void	hexademical(t_pf *arg, t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	if (*nbr_str == '0' && nbr_len == 1 && arg->flags & FLAG_GOT_PRECISION)
		nbr_len = 0;
	if (arg->flags & FLAG_GOT_PRECISION)
		arg->flags &= ~FLAG_ZERO;
	if (arg->flags & FLAG_HASH && nbr_len)
		arg->width -= (arg->width > 2) ? 2 : arg->width;
	pre_padding_hexademical(arg, arg_buff, nbr_len);
	fill_hexademical(arg, arg_buff, nbr_str, nbr_len);
	if (arg->flags & FLAG_MINUS)
		post_padding_hexademical(arg, arg_buff, nbr_len);
}
