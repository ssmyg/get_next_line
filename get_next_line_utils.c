/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:32 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/26 16:55:48 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_getchar(int fd)
{
	static t_buffer	buffer;

	if (buffer.n == 0)
	{
		buffer.n = read(fd, buffer.buf, BUF_SIZE);
		if (buffer.n < 0)
			return (READ_ERROR);
		buffer.bufp = buffer.buf;
	}
	if (--buffer.n >= 0)
	{
		return ((unsigned char)*buffer.bufp++);
	}
	return (EOF);
}

/*
char	*read_stdin(void)
{
	ssize_t	len;
	char	*file_buf;
	int		c;
	int		i;

	len = 11000 * 11000 + 100;
	file_buf = malloc(sizeof(char) * (len + 1));
	if (file_buf == NULL)
		return (NULL);
	i = 0;
	while (1)
	{
		c = ft_getchar();
		if (c == EOF)
			break ;
		file_buf[i] = (unsigned char)c;
		i++;
		if (i == len)
			break ;
	}
	file_buf[i] = '\0';
	return (file_buf);
}
*/
