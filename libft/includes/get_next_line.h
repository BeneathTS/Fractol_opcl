/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:56:39 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/12 17:31:53 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 2

# define ERROR -1
# define SUCCESS 1
# define NOTHING_RD 0

typedef struct		s_gnl
{
	int				fd;
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
#endif
