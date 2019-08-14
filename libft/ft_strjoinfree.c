/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:48:42 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/10 19:47:46 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int num)
{
	size_t	ct;
	size_t	ct2;
	char	*nw;

	ct = -1;
	ct2 = ct;
	if (NULL == s2 || NULL == s1)
		return (NULL);
	if (!(nw = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*(s1 + (++ct)))
		*(nw + ct) = *(s1 + ct);
	while (*(s2 + (++ct2)))
		*(nw + ct++) = *(s2 + ct2);
	if (num == 1)
		ft_strdel(&s1);
	else if (num == 2)
		ft_strdel(&s2);
	else if (num == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (nw);
}
