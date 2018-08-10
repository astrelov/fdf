/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_fact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:36:49 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/08 13:49:34 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_ll_fact(short num)
{
	long long	res;

	res = 1;
	if (num < 0 || num > 21)
	{
		ft_err_exit("ft_ll_fact: negative/too big input to function.\n");
		return (0);
	}
	while (num)
		res *= num--;
	return (res);
}
