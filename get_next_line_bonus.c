/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:37 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/29 20:16:58 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_string	*read_line(int fd)
{
	char		c;
	t_string	*str;

	str = init_str();
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_ERROR)
		{
			free_str(str);
			return (NULL);
		}
		if (c == EOF)
			return (str);
		if (c == '\n')
		{
			str = ft_putc(str, '\n');
			return (str);
		}
		str = ft_putc(str, c);
		if (!str)
			return (NULL);
	}
}

char	*get_next_line(int fd)
{
	t_string	*str;
	char		*ret;
	size_t		i;

	str = read_line(fd);
	if (!str)
		return (NULL);
	if (str->len == 0)
	{
		free_str(str);
		return (NULL);
	}
	ret = (char *)malloc(sizeof(char) * (str->len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < str->len)
	{
		ret[i] = str->str[i];
		i++;
	}
	ret[str->len] = '\0';
	return (ret);
}
