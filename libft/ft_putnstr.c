/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:53:10 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 12:57:19 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, size_t n)
{
	size_t	len;

	len = ft_strlen(s);
	if (s)
		write(1, s, (len > n) ? n : len);
}
