/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:59:12 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/20 17:38:15 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	ct;
	char	*b;

	i = -1;
	ct = ft_strlen(str) + 1;
	b = (char*)malloc(sizeof(char) * ct);
	if (NULL == b)
		return (0);
	while (++i < ct)
		*(b + i) = *(str + i);
	return (b);
}
