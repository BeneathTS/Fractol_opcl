/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:43:55 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/19 21:43:21 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_fsize(int n)
{
	int tmp;
	int	size;

	size = 0;
	tmp = n;
	if (tmp < 0)
		size++;
	while ((tmp = tmp / 10))
		++size;
	return (size + 1);
}

char			*ft_itoa(int n)
{
	char		*num;
	int			size;
	int			a;
	long int	tmp;

	a = 0;
	tmp = n;
	size = ft_fsize(tmp);
	num = ft_memalloc(size + 1);
	if (NULL == num)
		return (0);
	if (n < 0)
	{
		*num = '-';
		tmp *= -1;
		a = 1;
	}
	while (size > a)
	{
		*(num + (--size)) = (tmp % 10) + '0';
		tmp = tmp / 10;
	}
	return (num);
}
