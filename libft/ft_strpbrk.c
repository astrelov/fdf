/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:11:01 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/23 16:11:02 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s, const char *charset)
{
	int		i;

	if (!s || !charset)
		return (0);
	while (*s)
	{
		i = -1;
		while (charset[++i])
			if (*s == charset[i])
				return ((char *)s);
		s++;
	}
	return (0);
}
