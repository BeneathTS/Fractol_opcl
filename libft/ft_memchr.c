/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 00:17:06 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/15 17:58:08 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t ct;

	ct = -1;
	while ((++ct < n))
		if (*(((unsigned char*)s) + ct) == (unsigned char)c)
			return ((char*)s + ct);
	return (0);
}
