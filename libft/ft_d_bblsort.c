/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_bblsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:58:01 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/06 12:58:02 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_d_bblsort(int *arr, size_t len)
{
	int		temp;
	size_t	i;
	size_t	j;

	if (!arr)
	{
		ft_errmsg("ft_d_bblsort: incorrect input to function.\n");
		return (0);
	}
	i = -1;
	while (++i < len)
	{
		j = 0;
		while (++j < len - i)
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
	}
	return (arr);
}
