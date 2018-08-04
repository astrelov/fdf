/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:41:05 by astrelov          #+#    #+#             */
/*   Updated: 2017/10/31 12:41:06 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	int					len;
	unsigned int		i;

	i = -1;
	if (s && f)
	{
		len = ft_strlen(s);
		if (!(str = (char *)malloc(len + 1)))
			return (0);
		while (s[++i])
			str[i] = f(i, s[i]);
		str[i] = '\0';
		return (str);
	}
	return (0);
}
