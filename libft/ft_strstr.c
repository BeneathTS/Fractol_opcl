/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:26:40 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/23 15:34:51 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t	i;
	size_t	ct;
	size_t	ct2;

	if ((*(str1) == '\0' && *(str2) == '\0')
	|| *(str2) == '\0')
		return ((char*)str1);
	i = -1;
	while (*(str1 + (++i)) != '\0')
	{
		ct = i;
		ct2 = 0;
		while (*(str1 + ct) == *(str2 + ct2))
		{
			ct++;
			ct2++;
			if (*(str2 + ct2) == '\0')
				return (((char*)str1) + i);
		}
	}
	return (NULL);
}
