/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:16:45 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/15 18:02:32 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	int i;

	i = (int)ft_strlen(str);
	if (sym == '\0')
		return (((char*)str) + i);
	while (i >= 0)
	{
		if (*(str + i) == sym)
			return (((char*)str) + i);
		i--;
	}
	return (0);
}
