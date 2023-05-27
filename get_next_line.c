/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:37 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/27 19:50:49 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	c;
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_ERROR)
		{
			free(ret);
			return (NULL);
		}
		if (c == EOF)
		{
			if (i > 0)
			{
				ret[i] = '\0';
				return (ret);
			}
			else
			{
				free(ret);
				return (NULL);
			}
		}
		if (c == '\n')
		{
			ret[i] = '\n';
			i++;
			ret[i] = '\0';
			return (ret);
		}
		if (i > 4000)
		{
			ret[i] = '\n';
			i++;
			ret[i] = '\0';
			return (ret);
		}
		ret[i] = c;
		i++;
		//write(1, &c, 1);
	}
}
