/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:33:53 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/16 22:38:15 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*nw;
	size_t	ct;

	ct = -1;
	if ((NULL == s) || (NULL == f))
		return (NULL);
	nw = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (NULL == nw)
		return (NULL);
	while (*(s + (++ct)))
		*(nw + ct) = f(*(s + ct));
	*(nw + ct) = '\0';
	return (nw);
}
