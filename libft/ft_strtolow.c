/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:36:33 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 09:36:33 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtolow(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		*str = (char)ft_tolower(*str);
		str++;
	}
}
