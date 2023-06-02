/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:32 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/06/02 12:13:54 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_buffer	g_buffer_list;

static t_buffer	*init_buffer(int fd)
{
	t_buffer	*ret;

	ret = (t_buffer *)malloc(sizeof(t_buffer));
	if (!ret)
		return (NULL);
	ret->bufp = ret->buf;
	ret->n = 0;
	ret->fd = fd;
	ret->next = NULL;
	return (ret);
}

static void	free_buffer(int fd)
{
	t_buffer	*buf;
	t_buffer	*prev;

	buf = &g_buffer_list;
	prev = buf;
	while (buf)
	{
		if (buf->fd == fd)
		{
			prev->next = buf->next;
			free(buf);
			return ;
		}
		prev = buf;
		buf = buf->next;
	}
}

static t_buffer	*find_buffer(int fd)
{
	t_buffer	*buf;
	t_buffer	*prev;

	if (fd < 0)
		return (NULL);
	g_buffer_list.fd = DUMMY_FD;
	buf = &g_buffer_list;
	prev = buf;
	while (buf)
	{
		if (buf->fd == fd)
			return (buf);
		prev = buf;
		buf = buf->next;
	}
	buf = init_buffer(fd);
	if (!buf)
		return (NULL);
	prev->next = buf;
	return (buf);
}

int	ft_getc(int fd)
{
	t_buffer	*buf;

	buf = find_buffer(fd);
	if (!buf)
		return (READ_ERROR);
	if (buf->n == 0)
	{
		buf->n = read(fd, buf->buf, BUFFER_SIZE);
		if (buf->n < 0)
		{
			buf->n = 0;
			free_buffer(fd);
			return (READ_ERROR);
		}
		buf->bufp = buf->buf;
	}
	if (--buf->n >= 0)
	{
		return ((unsigned char)*buf->bufp++);
	}
	buf->n = 0;
	free_buffer(fd);
	return (EOF);
}
