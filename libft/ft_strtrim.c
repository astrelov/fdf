/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:00:46 by astrelov          #+#    #+#             */
/*   Updated: 2017/10/31 14:00:47 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		lastind;
	int		firstind;

	if (s)
	{
		i = 0;
		lastind = 0;
		firstind = 0;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			firstind = i++;
		while (s[i++])
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0')
				lastind = i + 1;
		if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
			firstind++;
		if (lastind == 0)
			lastind = firstind;
		if (!(res = ft_strsub(s, firstind, lastind - firstind)))
			return (0);
		return (res);
	}
	return (0);
}
