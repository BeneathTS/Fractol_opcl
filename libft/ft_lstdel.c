/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:28:50 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/26 15:36:22 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next_link;

	next_link = *alst;
	if (!alst || !del)
		return ;
	while (next_link)
	{
		next_link = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next_link;
	}
}
