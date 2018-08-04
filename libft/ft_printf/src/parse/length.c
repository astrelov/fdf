/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 10:30:22 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/20 16:07:52 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		parse_length(char **format, t_pf *arg)
{
	int				found;
	unsigned int	length;

	found = 0;
	length = 0;
	if (**format == 'h')
		length = (*(*format + 1) == 'h') ? LENGTH_SHORT_SHORT : LENGTH_SHORT;
	else if (**format == 'l')
		length = (*(*format + 1) == 'l') ? LENGTH_LONG_LONG : LENGTH_LONG;
	else if (**format == 'j')
		length = LENGTH_INTMAX;
	else if (**format == 'z')
		length = LENGTH_SIZE_T;
	if (length)
	{
		found = 1;
		*format += (length == LENGTH_LONG_LONG
					|| length == LENGTH_SHORT_SHORT) ? 2 : 1;
	}
	if (length > arg->length)
		arg->length = length;
	return (found);
}
