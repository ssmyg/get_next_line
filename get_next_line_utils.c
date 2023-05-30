/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:32 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/30 15:35:46 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_getc(int fd)
{
	static t_buffer	buf;

	if (buf.n == 0)
	{
		buf.n = read(fd, buf.buf, BUFFER_SIZE);
		if (buf.n < 0)
		{
			buf.n = 0;
			return (READ_ERROR);
		}
		buf.bufp = buf.buf;
	}
	if (--buf.n >= 0)
	{
		return ((unsigned char)*buf.bufp++);
	}
	buf.n = 0;
	return (EOF);
}
