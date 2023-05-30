/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:37 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/30 15:40:01 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_string	*init_str(void)
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

static void	free_str(t_string *str)
{
	free(str->str);
	free(str);
}

static t_string	*ft_putc(t_string *str, char c)
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

static t_string	*read_line(int fd)
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
	free_str(str);
	return (ret);
}
