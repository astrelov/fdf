/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:09:15 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/20 15:12:39 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	decimal_pre_padding_helper(t_pf *arg, size_t nbr_len, t_buff *arg_buff,
								char char_to_fill)
{
	if (arg->width > arg->precision && arg->precision > nbr_len)
		push_chars(arg_buff, ' ', arg->width - arg->precision);
	if (arg->width > nbr_len && nbr_len > arg->precision &&
		(arg->flags & FLAG_GOT_PRECISION))
		push_chars(arg_buff, char_to_fill, arg->width - nbr_len);
	if (arg->width > arg->precision && arg->precision == nbr_len)
		push_chars(arg_buff, char_to_fill, arg->width - arg->precision);
	if (arg->width > nbr_len && !(arg->flags & FLAG_GOT_PRECISION))
		push_chars(arg_buff, char_to_fill, arg->width - nbr_len);
}
