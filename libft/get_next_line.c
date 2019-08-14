/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:02:41 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/12 17:29:19 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*ft_list_creator(int fd, t_gnl *prev, t_gnl *next)
{
	t_gnl *new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	if (!(new->temp = ft_strnew(0)))
	{
		free(new);
		return (NULL);
	}
	new->fd = fd;
	new->prev = prev;
	new->next = next;
	return (new);
}

t_gnl	*ft_check_fd(int fd, t_gnl *buf)
{
	if (!buf)
		return (ft_list_creator(fd, buf, NULL));
	if (fd == buf->fd)
		return (buf);
	else if (fd > buf->fd)
	{
		while (buf->fd != fd && buf->next)
			buf = buf->next;
		return (buf->fd == fd ? buf :
			(buf->next = ft_list_creator(fd, buf, NULL)));
	}
	else
	{
		while (buf->fd != fd && buf->prev)
			buf = buf->prev;
		return (buf->fd == fd ? buf : ft_list_creator(fd, NULL, buf));
	}
}

int		ft_temp_check(t_gnl *buf)
{
	char	*temp;

	if (buf->temp && *buf->temp)
	{
		temp = ft_strchr(buf->temp, '\n');
		if (temp)
			ft_memmove(buf->temp, temp + 1, ft_strlen(temp));
		else
		{
			free(buf->temp);
			buf->temp = ft_strnew(0);
		}
		return (SUCCESS);
	}
	return (NOTHING_RD);
}

int		ft_writer(t_gnl *buf, char **line)
{
	long int	ct;

	while ((ct = read(buf->fd, buf->buffer, BUFF_SIZE)))
	{
		if (ct < 0)
			return (ERROR);
		buf->buffer[ct] = '\0';
		if (!(buf->temp = ft_strjoinfree(buf->temp, buf->buffer, 1)))
			return (ERROR);
		if (ft_strchr(buf->buffer, '\n'))
			break ;
	}
	if (buf->temp)
		if (!(*line = ft_strchrdup(buf->temp, '\n')))
			return (ERROR);
	return (ft_temp_check(buf) == SUCCESS ? SUCCESS : NOTHING_RD);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*buf;
	int				status;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (ERROR);
	if (!(buf = ft_check_fd(fd, buf)))
		return (ERROR);
	status = ft_writer(buf, line);
	if (status == SUCCESS)
		return (SUCCESS);
	else if (status == ERROR)
		return (ERROR);
	else
		return (NOTHING_RD);
}
