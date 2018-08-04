/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:32:56 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 17:04:48 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	inner_pf(char *format, va_list va, t_buff *buff)
{
	t_pf	*arg_params;
	t_buff	*arg_buff;

	arg_params = NULL;
	buff_realloc(buff);
	while (*format)
	{
		if (buff->index >= buff->size)
			buff_realloc(buff);
		if (*format != '%')
		{
			push_chars(buff, *format++, 1);
			continue;
		}
		if (*(++format))
		{
			parse(&format, va, &arg_params);
			if (arg_params->specifier)
			{
				arg_buff = handle_argument(va, arg_params);
				concat_buffs(buff, &arg_buff);
			}
		}
	}
	ft_memdel((void **)&arg_params);
}

int		ft_printf(const char *format, ...)
{
	va_list	va;
	t_buff	*buff;
	int		result;

	buff = (t_buff *)ft_memalloc(sizeof(t_buff));
	buff_realloc(buff);
	va_start(va, format);
	inner_pf((char *)format, va, buff);
	va_end(va);
	result = (int)buff->index;
	write(1, buff->buff, buff->index);
	ft_memdel((void **)&(buff->buff));
	ft_memdel((void **)&buff);
	return (result);
}
