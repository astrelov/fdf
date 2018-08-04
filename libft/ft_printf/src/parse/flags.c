/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:28:14 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/18 12:43:46 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		parse_flags(char **format, t_pf *arg)
{
	int		found;
	char	tmp;

	found = 0;
	while (1)
	{
		tmp = **format;
		if (tmp == '+' || tmp == '#' || tmp == '-' || tmp == ' ' || tmp == '0')
			found = 1;
		if (**format == '+')
			arg->flags |= FLAG_PLUS;
		else if (**format == '#')
			arg->flags |= FLAG_HASH;
		else if (**format == '-')
			arg->flags |= FLAG_MINUS;
		else if (**format == ' ')
			arg->flags |= FLAG_SPACE;
		else if (**format == '0')
			arg->flags |= FLAG_ZERO;
		else
			break ;
		(*format)++;
	}
	return (found);
}
