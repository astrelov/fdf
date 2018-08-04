/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:17:02 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/03 11:17:03 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list *)malloc(sizeof(*res))))
		return (0);
	if (!content)
	{
		res->content = 0;
		res->content_size = 0;
	}
	else
	{
		if (!(res->content = malloc(content_size)))
		{
			free(res);
			return (0);
		}
		ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
	}
	res->next = 0;
	return (res);
}
