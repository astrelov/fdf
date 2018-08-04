/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 10:21:37 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 15:25:13 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	pres_helper(char **format, va_list va, t_pf *arg)
{
	int	precis;

	if ((precis = va_arg(va, int)) >= 0)
	{
		arg->precision = (unsigned int)precis;
		arg->flags |= FLAG_GOT_PRECISION;
	}
	(*format)++;
}

int		parse_precision(char **format, va_list va, t_pf *arg)
{
	int found;

	found = 0;
	if (**format == '.')
	{
		found = 1;
		(*format)++;
		if (ft_isdigit(**format))
		{
			arg->precision = parse_atoi(format);
			arg->flags |= FLAG_GOT_PRECISION;
		}
		else if (**format == '*')
			pres_helper(format, va, arg);
		else
		{
			arg->flags |= FLAG_GOT_PRECISION;
			arg->precision = 0;
		}
	}
	return (found);
}
