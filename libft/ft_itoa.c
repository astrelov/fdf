/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:22:46 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/08 15:11:55 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		n2length(long n2)
{
	int		length;

	length = 0;
	if (n2 == 0)
		return (1);
	while (n2 > 0)
	{
		n2 /= 10;
		length++;
	}
	return (length);
}

static void		isnegative(long *n2, int *isneg, int *length)
{
	*isneg = 1;
	*length = 0;
	if (*n2 < 0)
	{
		*n2 = -*n2;
		*isneg = 0;
		*length = 1;
	}
}

static void		charfill(char *res, long n2, int length)
{
	if (n2 >= 10)
	{
		charfill(res, n2 / 10, length - 1);
		charfill(res, n2 % 10, length);
	}
	else
		res[length] = n2 + '0';
}

char			*ft_itoa(int n)
{
	long		n2;
	char		*res;
	int			isneg;
	int			length;

	n2 = n;
	isnegative(&n2, &isneg, &length);
	length += n2length(n2);
	if (!(res = (char *)malloc(length + 1)))
		return (0);
	if (isneg == 0)
		res[isneg++] = '-';
	charfill(res, n2, length - isneg);
	res[isneg + length - 1] = '\0';
	return (res);
}
