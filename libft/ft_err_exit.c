/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:38:45 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/16 12:32:58 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_err_exit(char *err_msg)
{
	if (err_msg)
	{
		ft_printf(COLOR_BRED);
		ft_putendl_fd(err_msg, 2);
		ft_printf(COLOR_RESET);
	}
	exit(1);
}
