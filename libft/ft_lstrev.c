/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:51:15 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/08 12:45:45 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rev(t_list **head, t_list *prev, t_list *curr)
{
	if (curr)
	{
		rev(head, curr, curr->next);
		curr->next = prev;
	}
	else if (prev)
		*head = prev;
	else if ((*head)->next)
	{
		prev = *head;
		curr = (*head)->next;
		rev(head, curr, (*head)->next->next);
		curr->next = prev;
		prev->next = NULL;
	}
}

t_list	*ft_lstrev(t_list **head)
{
	rev(head, NULL, NULL);
	return (*head);
}
