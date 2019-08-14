/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:46:49 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/16 20:59:51 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ct;
	size_t	ct2;
	size_t	l_dst;
	size_t	l_src;

	ct = 0;
	ct2 = 0;
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size <= l_dst)
		return (size + l_src);
	while (*(dst + ct))
		ct++;
	while (*(src + ct2) && (ct < (size - 1)))
		*(dst + (ct++)) = *(src + (ct2++));
	*(dst + ct) = '\0';
	return (l_dst + l_src);
}
