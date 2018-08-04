/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:11:44 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/01 17:11:45 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		memory(char const *s, char **res, char c)
{
	int			lett;
	int			i;
	int			ind;

	ind = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			lett = 0;
			while (s[i] != c && s[i])
			{
				i++;
				lett++;
			}
			if (!(res[ind] = (char *)malloc(sizeof(*res) * lett + 1)))
				return (0);
			ind++;
		}
	}
	res[ind] = 0;
	return (1);
}

static void		fill(char const *s, char **res, char c)
{
	int			i;
	int			ind;
	int			ind2;

	i = 0;
	ind = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			ind2 = 0;
			while (s[i] != c && s[i])
				res[ind][ind2++] = s[i++];
			res[ind][ind2] = '\0';
			ind++;
		}
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	int			i;
	int			words;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	(s[0] == c) ? 1 : (words = 1);
	while (s[++i])
		if (s[i] != c && s[i - 1] == c)
			words++;
	if (!(res = (char **)malloc(sizeof(res) * i + 1)))
		return (0);
	if (memory(s, res, c) == 0)
		return (0);
	fill(s, res, c);
	return (res);
}
