/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:28:40 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 15:47:00 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

unsigned int	parse_atoi(char **format)
{
	unsigned int	res;

	res = 0;
	while (ft_isdigit(**format))
		res = res * 10 + *((*format)++) - '0';
	return (res);
}

void			pf_realloc(t_pf **arg)
{
	if (*arg)
		free(*arg);
	*arg = (t_pf *)ft_memalloc(sizeof(t_pf));
}

void			parse(char **format, va_list va, t_pf **arg)
{
	int found;

	pf_realloc(arg);
	found = 1;
	while (found)
	{
		found = 0;
		found += parse_flags(format, *arg);
		found += parse_width(format, va, *arg);
		found += parse_precision(format, va, *arg);
		found += parse_length(format, *arg);
	}
	(*arg)->specifier = *((*format)++);
	if (!(*arg)->specifier)
		(*format)--;
}
