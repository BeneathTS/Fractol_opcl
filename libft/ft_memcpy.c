/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:07:22 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/20 21:25:45 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t ct;

	if (!dst && !src)
		return (0);
	ct = -1;
	while (++ct < n)
		*(((char*)dst) + ct) = *(((char*)src) + ct);
	return (dst);
}
