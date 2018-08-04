/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:41:23 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/02 12:41:25 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i] != c)
		if (s[i] == '\0' && c != '\0')
			return (0);
	return ((char *)(s + i));
}
