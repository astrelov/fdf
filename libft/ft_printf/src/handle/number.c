/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:34:17 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/18 14:39:35 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	prepare_number_arg(t_pf *arg)
{
	if (arg->specifier == 'X' || arg->specifier == 'O')
		arg->flags |= FLAG_UPPERCASE;
	if (arg->specifier == 'D' || arg->specifier == 'U' || arg->specifier == 'O')
		arg->length = LENGTH_LONG;
	if (ft_strchr("DOXU", arg->specifier))
		arg->specifier += 32;
	if (arg->specifier == 'i')
		arg->specifier = 'd';
	if (arg->specifier != 'd')
		arg->flags &= ~(FLAG_PLUS | FLAG_SPACE);
	if (arg->specifier == 'x')
		arg->base = 16;
	else if (arg->specifier == 'o')
		arg->base = 8;
	else
	{
		arg->base = 10;
		arg->flags &= ~FLAG_HASH;
	}
}

void	handle_number(t_pf *arg, t_buff *arg_buff, uintmax_t nbr)
{
	char	*nbr_str;
	size_t	nbr_len;
	size_t	bytes_left;

	prepare_number_arg(arg);
	nbr_str = stringify_nbr(arg, nbr);
	nbr_len = ft_strlen(nbr_str);
	bytes_left = arg_buff->size - arg_buff->index;
	while (bytes_left < nbr_len || bytes_left < arg->width ||
			bytes_left < arg->precision)
	{
		buff_realloc(arg_buff);
		bytes_left = arg_buff->size - arg_buff->index;
	}
	if (arg->base == 8)
		octal(arg, arg_buff, nbr_str, nbr_len);
	if (arg->base == 10)
		decimal(arg, arg_buff, nbr_str, nbr_len);
	if (arg->base == 16)
		hexademical(arg, arg_buff, nbr_str, nbr_len);
	ft_memdel((void **)&nbr_str);
}
