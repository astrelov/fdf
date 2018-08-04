/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:53:31 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/02 12:53:32 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		i2;
	int		temp;

	i = -1;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[++i])
	{
		i2 = 0;
		temp = i;
		while (haystack[temp++] == needle[i2++])
			if (!needle[i2])
				return ((char *)haystack + i);
	}
	return (0);
}
