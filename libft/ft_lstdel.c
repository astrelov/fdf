/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:27:09 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/03 13:27:10 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*nextlst;

	if (!alst || !del)
		return ;
	temp = *alst;
	while (temp)
	{
		nextlst = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = nextlst;
	}
	*alst = 0;
}
