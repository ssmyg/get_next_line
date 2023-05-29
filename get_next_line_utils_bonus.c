/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:32 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/29 20:17:06 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_getc(int fd)
{
	static t_buffer	buffer;

	if (buffer.n == 0)
	{
		buffer.n = read(fd, buffer.buf, BUFFER_SIZE);
		if (buffer.n < 0)
		{
			buffer.n = 0;
			return (READ_ERROR);
		}
		buffer.bufp = buffer.buf;
	}
	if (--buffer.n >= 0)
	{
		return ((unsigned char)*buffer.bufp++);
	}
	buffer.n = 0;
	return (EOF);
}

t_string	*ft_putc(t_string *str, char c)
{
	size_t	i;
	char	*new_str;

	if (str->len + 1 >= str->max_len)
	{
		new_str = (char *)malloc(sizeof(char) * (str->max_len + BLOCK_SIZE));
		if (!new_str)
		{
			free_str(str);
			return (NULL);
		}
		i = 0;
		while (i < str->len)
		{
			new_str[i] = str->str[i];
			i++;
		}
		free(str->str);
		str->str = new_str;
		str->max_len = str->max_len + BLOCK_SIZE;
	}
	str->str[str->len] = c;
	str->len++;
	return (str);
}

t_string	*init_str(void)
{
	t_string	*str;

	str = (t_string *)malloc(sizeof(t_string));
	if (!str)
		return (NULL);
	str->str = (char *)malloc(sizeof(char) * BLOCK_SIZE);
	if (!str->str)
	{
		free(str);
		return (NULL);
	}
	str->max_len = BLOCK_SIZE;
	str->len = 0;
	return (str);
}

void	free_str(t_string *str)
{
	free(str->str);
	free(str);
}
