/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:03:56 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/20 21:24:55 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	ct;

	ct = -1;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		while (++ct < len)
			*(((unsigned char*)dst) + ct) = *(((unsigned char*)src) + ct);
	else
		while (len--)
			*(((unsigned char*)dst) + len) = *(((unsigned char*)src) + len);
	return (dst);
}
