/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:48:42 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/17 21:18:56 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ct;
	size_t	ct2;
	char	*nw;

	ct = -1;
	ct2 = ct;
	if (NULL == s2 || NULL == s1)
		return (NULL);
	nw = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (NULL == nw)
		return (NULL);
	while (*(s1 + (++ct)))
		*(nw + ct) = *(s1 + ct);
	while (*(s2 + (++ct2)))
		*(nw + ct++) = *(s2 + ct2);
	return (nw);
}
