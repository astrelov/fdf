/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:28:00 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/20 16:29:31 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned long	num;
	short			isneg;

	isneg = 0;
	num = 0;
	while ((*str >= '\b' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			isneg = 1;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	if (num > 9223372036854775807)
		return (isneg ? 0 : -1);
	return ((int)(isneg ? -num : num));
}
