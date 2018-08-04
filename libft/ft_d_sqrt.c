/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_sqrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:43:56 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/05 16:43:57 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_abs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static int		close_enough(double a, double b)
{
	if (ft_abs(a - b) < .001)
		return (1);
	return (0);
}

static double	better_guess(double x, double g)
{
	return ((g + x / g) / 2);
}

double			ft_d_sqrt2(double x, double g)
{
	if (close_enough(x / g, g))
		return (g);
	return (ft_d_sqrt2(x, better_guess(x, g)));
}

double			ft_d_sqrt(double x)
{
	double		g;

	g = 1;
	if (x < 0)
	{
		ft_errmsg("ft_d_sqrt: negative input to function.\n");
		return (-1);
	}
	return (ft_d_sqrt2(x, g));
}
