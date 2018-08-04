/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:03:43 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 15:33:00 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_buff	*handle_argument(va_list va, t_pf *arg)
{
	t_buff	*arg_buff;

	arg_buff = (t_buff *)ft_memalloc(sizeof(t_buff));
	buff_realloc(arg_buff);
	if (ft_strchr("dDioOuUxX", arg->specifier))
		handle_number(arg, arg_buff, va_arg(va, uintmax_t));
	else if (ft_strchr("cC", arg->specifier))
		handle_char(arg, arg_buff, va_arg(va, wchar_t));
	else if (ft_strchr("sS", arg->specifier))
		handle_string(arg, arg_buff, va_arg(va, wchar_t *));
	else if (arg->specifier == 'p')
		handle_pointer(arg, arg_buff, va_arg(va, size_t));
	else
		invalid_specifier(arg, arg_buff);
	return (arg_buff);
}
