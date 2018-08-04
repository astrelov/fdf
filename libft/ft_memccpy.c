/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:46:29 by astrelov          #+#    #+#             */
/*   Updated: 2017/10/30 15:46:32 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dp;
	unsigned char	*sp;
	unsigned char	c2;

	c2 = (unsigned char)c;
	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	while (n--)
		if ((*dp++ = *sp++) == c2)
			return (dp);
	return (0);
}
