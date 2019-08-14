/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:12:00 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/16 23:25:50 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	ct;

	ct = 0;
	if ((NULL == s1) || (NULL == s2))
		return (0);
	while ((*(s1 + ct) == *(s2 + ct)) && (*(s1 + ct) && *(s2 + ct)) && (ct < n))
		ct++;
	if ((!*(s1 + ct) && !*(s2 + ct)) ||
	((*(s1 + (ct - 1)) == *(s2 + (ct - 1))) && (ct == n)))
		return (1);
	else
		return (0);
}
