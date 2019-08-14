/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:43:18 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/15 18:08:15 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			ct;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	ct = 0;
	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	while (ct < n)
	{
		if (*(tmp1 + ct) != *(tmp2 + ct))
			return (*(tmp1 + ct) - *(tmp2 + ct));
		ct++;
	}
	return (0);
}
