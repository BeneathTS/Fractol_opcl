/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:29:59 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/21 16:35:21 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_ls;

	if (content_size == (size_t)-1)
		return (NULL);
	new_ls = (t_list*)malloc(sizeof(t_list));
	if (NULL == new_ls)
		return (NULL);
	if (!content)
	{
		(*new_ls).content = NULL;
		(*new_ls).content_size = 0;
	}
	else
	{
		(*new_ls).content = ft_memalloc(ft_strlen(content) + 1);
		if (!(*new_ls).content)
		{
			free(new_ls);
			return (NULL);
		}
		ft_memcpy((*new_ls).content, (void*)content, ft_strlen(content));
		(*new_ls).content_size = content_size;
	}
	new_ls->next = NULL;
	return (new_ls);
}
