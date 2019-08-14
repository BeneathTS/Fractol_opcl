/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:29:19 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/23 15:31:22 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *cntnt, size_t cntnt_s)
{
	if (!cntnt && !cntnt_s)
		return ;
	free(cntnt);
	cntnt = NULL;
	cntnt_s = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*map;
	t_list	*back;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	map = ft_lstnew((*tmp).content, (*tmp).content_size);
	if (!map)
		return (NULL);
	back = map;
	while ((lst = (*lst).next))
	{
		tmp = f(lst);
		(*map).next = ft_lstnew((*tmp).content, (*tmp).content_size);
		if (!(*map).next)
		{
			ft_lstdel(&back, ft_del);
			return (NULL);
		}
		map = (*map).next;
	}
	return (back);
}
