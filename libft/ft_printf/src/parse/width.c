/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:55:43 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/20 16:36:49 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	width_helper(char **format, va_list va, t_pf *arg)
{
	int		w;

	if ((w = va_arg(va, int)) < 0)
	{
		arg->flags |= FLAG_MINUS;
		arg->width = (unsigned int)-w;
	}
	else
		arg->width = (unsigned int)w;
	(*format)++;
}

int		parse_width(char **format, va_list va, t_pf *arg)
{
	int		found;

	found = 0;
	while (1)
	{
		if (ft_isdigit(**format))
		{
			found = 1;
			arg->width = parse_atoi(format);
		}
		else if (**format == '*')
		{
			found = 1;
			width_helper(format, va, arg);
		}
		else
			break ;
	}
	return (found);
}
