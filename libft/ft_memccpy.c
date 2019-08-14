/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:22:59 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/16 21:07:12 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t ct;

	ct = -1;
	while (++ct < n)
	{
		*(((unsigned char*)dst) + ct) = *(((unsigned char*)src) + ct);
		if (*(((unsigned char*)src) + (ct)) == (unsigned char)c)
			return (dst + (ct + 1));
	}
	return (NULL);
}
