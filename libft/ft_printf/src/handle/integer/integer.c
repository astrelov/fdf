/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:25:24 by astrielov         #+#    #+#             */
/*   Updated: 2018/04/18 14:47:59 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static char			*handle_intmax_t(t_pf *arg, intmax_t nbr)
{
	char			*res;
	int				sign;
	size_t			len;
	uintmax_t		tmp;

	sign = (nbr < 0) ? -1 : 1;
	tmp = (uintmax_t)nbr * sign;
	len = 1;
	while (tmp /= arg->base)
		len++;
	res = (char *)ft_memalloc(len + 1);
	while (len--)
	{
		res[len] = BASE_STRING[nbr % arg->base * sign];
		nbr /= arg->base;
	}
	arg->nbr_is_negative = (sign == -1) ? 1 : 0;
	return (res);
}

static char			*handle_u_intmax_t(t_pf *arg, uintmax_t nbr)
{
	char			*res;
	size_t			len;
	uintmax_t		tmp;

	tmp = nbr;
	len = 1;
	while (tmp /= arg->base)
		len++;
	res = (char *)ft_memalloc(len + 1);
	while (len--)
	{
		res[len] = BASE_STRING[nbr % arg->base];
		nbr /= arg->base;
	}
	return (res);
}

static uintmax_t	handle_signed_length(t_pf *arg, uintmax_t nbr)
{
	if (arg->length == LENGTH_SHORT_SHORT)
		return ((char)nbr);
	if (arg->length == LENGTH_SHORT)
		return ((short)nbr);
	if (arg->length == LENGTH_LONG)
		return ((long)nbr);
	if (arg->length == LENGTH_LONG_LONG)
		return ((long long)nbr);
	if (arg->length == LENGTH_INTMAX)
		return ((intmax_t)nbr);
	if (arg->length == LENGTH_SIZE_T)
		return ((size_t)nbr);
	return ((int)nbr);
}

static uintmax_t	handle_unsigned_length(t_pf *arg, uintmax_t nbr)
{
	if (arg->length == LENGTH_SHORT_SHORT)
		return ((unsigned char)nbr);
	if (arg->length == LENGTH_SHORT)
		return ((unsigned short)nbr);
	if (arg->length == LENGTH_LONG)
		return ((unsigned long)nbr);
	if (arg->length == LENGTH_LONG_LONG)
		return ((unsigned long long)nbr);
	if (arg->length == LENGTH_INTMAX)
		return ((uintmax_t)nbr);
	if (arg->length == LENGTH_SIZE_T)
		return ((size_t)nbr);
	return ((unsigned int)nbr);
}

char				*stringify_nbr(t_pf *arg, uintmax_t nbr)
{
	char	*nbr_str;

	if (arg->base == 10 && arg->specifier != 'u')
		nbr_str = handle_intmax_t(arg, handle_signed_length(arg, nbr));
	else
		nbr_str = handle_u_intmax_t(arg, handle_unsigned_length(arg, nbr));
	if (arg->flags & FLAG_UPPERCASE)
		ft_strtoupp(nbr_str);
	return (nbr_str);
}
