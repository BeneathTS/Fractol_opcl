/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:49:49 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/24 19:03:18 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int	num;
	int					ct;
	int					znk;

	ct = 0;
	znk = 1;
	num = ct;
	ft_ss(&ct, str);
	if ((*(str + ct) == '-' || *(str + ct) == '+') &&
		(*(str + (ct + 1)) >= '0' && *(str + (ct + 1)) <= '9'))
	{
		if (*(str + ct) == '-')
			znk = -1;
		ct++;
	}
	while ((*(str + ct) >= '0' && *(str + ct) <= '9'))
		num = (num * 10) + (*(str + (ct++)) - '0');
	if ((num > 9223372036854775807) && (znk == -1))
		return (0);
	else if ((num >= 9223372036854775807) && (znk == 1))
		return (-1);
	return ((int)num * znk);
}
