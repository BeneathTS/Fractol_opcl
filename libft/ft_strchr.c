/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:35:40 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/15 18:00:59 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int sym)
{
	int i;

	i = -1;
	while (*(str + (++i)))
		if (*(str + i) == sym)
			return (((char*)str) + i);
	if (sym == '\0')
		return (((char*)str) + i);
	return (0);
}
