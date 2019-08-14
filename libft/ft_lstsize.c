/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:56:19 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/23 15:59:52 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_lstsize(t_list *lst)
{
	size_t	ct;

	if (!lst)
		return (0);
	ct = 0;
	while (lst)
	{
		ct++;
		lst = (*lst).next;
	}
	return (ct);
}
