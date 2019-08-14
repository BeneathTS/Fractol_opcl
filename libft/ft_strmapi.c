/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 22:46:15 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/16 23:06:22 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		*(nw + ct) = f(ct, *(s + ct));
	*(nw + ct) = '\0';
	return (nw);
}
