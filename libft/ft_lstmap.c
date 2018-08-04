/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:16:56 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/03 14:16:57 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*link;

	new = 0;
	link = 0;
	while (lst && f)
	{
		if (!new)
		{
			new = f(lst);
			link = new;
		}
		else
		{
			link->next = f(lst);
			link = link->next;
		}
		lst = lst->next;
	}
	return (new);
}
