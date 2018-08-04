/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lf_pow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:45:16 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/05 16:45:17 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_lf_pow(double num, short pow)
{
	double	res;
	short	powisneg;

	res = 1;
	powisneg = 0;
	if (pow < 0)
	{
		pow = -pow;
		powisneg = 1;
	}
	while (pow--)
		res *= num;
	if (powisneg)
		return (1 / res);
	return (res);
}
