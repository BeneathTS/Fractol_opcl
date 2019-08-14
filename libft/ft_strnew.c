/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:24:41 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/19 22:24:39 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == (size_t)-1)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (NULL == str)
		return (NULL);
	ft_memset(str, 0, (size + 1));
	return (str);
}
