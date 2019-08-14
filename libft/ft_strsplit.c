/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:36:57 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/26 15:38:07 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_cs(char *s, size_t *ct, char c)
{
	while ((*(s + *ct) == c) || !*(s + *ct))
		*ct = *ct + 1;
}

static size_t	ft_cw(char *s, size_t ct, char c)
{
	size_t wrds;
	size_t bee;

	wrds = 0;
	bee = 0;
	while (*(s + ct))
	{
		if (*(s + ct) != c && *(s + ct) && !bee)
		{
			wrds++;
			bee = 1;
			ct++;
		}
		else if (*(s + ct) == c)
		{
			bee = 0;
			ct++;
		}
		else
			ct++;
	}
	return (wrds);
}

static int		ft_cc(char *s, size_t ct, char c)
{
	size_t chrs;

	chrs = 4;
	while (*(s + ct) && *(s + ct) != c)
	{
		ct++;
		chrs++;
	}
	return (chrs);
}

static char		**ft_clear_mem(char **spl, size_t i)
{
	size_t ct;

	ct = -1;
	if (i > 0)
		while (++ct < i)
			free(*(spl + ct));
	free(spl);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	ct;
	size_t	ct2;
	size_t	i;
	char	**spl;

	i = -1;
	ct = 0;
	if (NULL == s)
		return (NULL);
	spl = (char**)malloc(sizeof(char*) * (ft_cw((char*)s, 0, c) + 1));
	if (spl == NULL)
		return (NULL);
	while (++i < ft_cw((char*)s, 0, c))
	{
		ct2 = 0;
		ft_cs((char*)s, &ct, c);
		*(spl + i) = ft_memalloc((ft_cc((char*)s, ct, c) + 1));
		if (*(spl + i) == NULL)
			return (ft_clear_mem(spl, i));
		while (*(s + ct) != c && *(s + ct))
			*((*(spl + i)) + (ct2++)) = *(s + (ct++));
	}
	*(spl + i) = NULL;
	return (spl);
}
