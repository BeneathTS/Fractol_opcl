/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:57:10 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/15 17:31:48 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	int i;

	i = 0;
	while ((*(s1 + i) && *(s2 + i)) &&
			(*(s1 + i) == *(s2 + i)) &&
			(size_t)i != num)
		i++;
	if ((size_t)i == num)
		return (0);
	else
		return (*(((unsigned char*)s1) + i) - *(((unsigned char*)s2) + i));
}
