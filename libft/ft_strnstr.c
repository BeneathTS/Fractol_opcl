/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:03:39 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/23 15:41:37 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hst, const char *nd, size_t len)
{
	size_t	i;
	size_t	ct;
	size_t	ct2;

	if (len == (size_t)-1)
		return (NULL);
	if ((*(hst) == '\0' && *(nd) == '\0')
	|| *(nd) == '\0')
		return ((char*)hst);
	i = -1;
	while ((*(hst + (++i)) != '\0') && (i < len))
	{
		ct = i;
		ct2 = 0;
		while ((*(hst + ct) == *(nd + ct2)) && (ct < len))
		{
			ct++;
			ct2++;
			if (*(nd + ct2) == '\0')
				return (((char*)hst) + i);
		}
	}
	return (NULL);
}
