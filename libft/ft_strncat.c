/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:21:48 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/15 17:14:02 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t num)
{
	int		i;
	size_t	ct;

	i = 0;
	ct = 0;
	while (*(dst + i) != '\0')
		i++;
	while (*(src + ct) && (ct != num))
		*(dst + (i++)) = *(src + (ct++));
	*(dst + i) = '\0';
	return (dst);
}
