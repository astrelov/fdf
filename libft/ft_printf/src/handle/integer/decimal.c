/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:06:24 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/20 15:07:08 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	print_sign_decimal(t_pf *arg, t_buff *arg_buff)
{
	if (arg->nbr_is_negative)
		push_chars(arg_buff, '-', 1);
	else if (arg->flags & FLAG_PLUS)
		push_chars(arg_buff, '+', 1);
	else if (arg->flags & FLAG_SPACE)
		push_chars(arg_buff, ' ', 1);
}

void	pre_padding_decimal(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	char char_to_fill;

	char_to_fill = ' ';
	if ((arg->flags & FLAG_ZERO) && !(arg->flags & FLAG_GOT_PRECISION))
	{
		char_to_fill = '0';
		print_sign_decimal(arg, arg_buff);
	}
	if (!(arg->flags & FLAG_MINUS))
		decimal_pre_padding_helper(arg, nbr_len, arg_buff, char_to_fill);
	if (char_to_fill == ' ')
		print_sign_decimal(arg, arg_buff);
	if (arg->precision > nbr_len)
	{
		if (char_to_fill == '0')
			print_sign_decimal(arg, arg_buff);
		push_chars(arg_buff, '0', arg->precision - nbr_len);
	}
}

void	fill_decimal(t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	while (nbr_len--)
		(arg_buff->buff)[arg_buff->index++] = *nbr_str++;
}

void	post_padding_decimal(t_pf *arg, t_buff *arg_buff, size_t nbr_len)
{
	if (arg->width > nbr_len && nbr_len > arg->precision)
		push_chars(arg_buff, ' ', arg->width - nbr_len);
	if (arg->width > arg->precision && arg->precision >= nbr_len)
		push_chars(arg_buff, ' ', arg->width - arg->precision);
}

void	decimal(t_pf *arg, t_buff *arg_buff, char *nbr_str, size_t nbr_len)
{
	if (*nbr_str == '0' && nbr_len == 1 && arg->flags & FLAG_GOT_PRECISION)
		nbr_len = 0;
	if (arg->nbr_is_negative || arg->flags & (FLAG_SPACE | FLAG_PLUS))
		arg->width -= arg->width > 0 ? 1 : 0;
	pre_padding_decimal(arg, arg_buff, nbr_len);
	fill_decimal(arg_buff, nbr_str, nbr_len);
	if (arg->flags & FLAG_MINUS)
		post_padding_decimal(arg, arg_buff, nbr_len);
}
