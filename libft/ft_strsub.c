/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:28:11 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/19 22:24:23 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	ct;
	char	*nw;

	if (len == (size_t)-1)
		return (NULL);
	ct = -1;
	if (NULL == s)
		return (0);
	nw = ft_memalloc(len + 1);
	if (NULL == nw)
		return (0);
	while ((++ct < len) && *(s + start))
		*(nw + ct) = *(s + start++);
	*(nw + ct) = '\0';
	return (nw);
}
