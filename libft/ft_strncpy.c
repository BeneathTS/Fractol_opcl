/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:22:30 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/15 17:35:44 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t num)
{
	size_t i;

	i = 0;
	while ((i < num) && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	while (i < num)
		*(dst + (i++)) = '\0';
	return (dst);
}
