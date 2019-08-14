/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:22:41 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/23 18:41:11 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		find_start(char const *s, size_t *ct)
{
	while (((*(s + *ct) == ' ') || (*(s + *ct) == '\n') ||
	(*(s + *ct) == '\t')) && *(s + *ct))
		*ct = *ct + 1;
}

static size_t	find_end(char const *s, size_t end)
{
	size_t ct;

	ct = end - 1;
	while (((*(s + ct) == ' ') || (*(s + ct) == '\n') ||
	(*(s + ct) == '\t')) && *(s + ct) && ct > 0)
		ct--;
	if (ct == 0)
		return (end);
	return (ct);
}

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	ct;
	char	*str;

	if (NULL == s)
		return (0);
	start = 0;
	ct = 0;
	end = ft_strlen(s);
	find_start(s, &start);
	end = find_end(s, end);
	str = ft_memalloc(end - start + 2);
	if (NULL == str)
		return (0);
	while (start <= end && *(s + (start)))
		*(str + (ct++)) = *(s + (start++));
	return (str);
}
