/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:53:16 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/10 18:54:34 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrdup(char *str, char chr)
{
	long int	ct;
	long int	ct2;
	char		*new;

	ct = 0;
	ct2 = -1;
	while (str[ct] != chr && str[ct])
		ct++;
	if (!(new = ft_strnew(ct)))
		return (NULL);
	while (++ct2 < ct)
		new[ct2] = str[ct2];
	return (new);
}
