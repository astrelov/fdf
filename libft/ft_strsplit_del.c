/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:48:11 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/08 14:54:01 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strsplit_del(char ***split0)
{
	char	**split;
	int		i;

	split = *split0;
	*split0 = NULL;
	i = -1;
	while (split[++i])
		ft_strdel(&(split[i]));
	free(split);
	return (NULL);
}
