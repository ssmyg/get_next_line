/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:42 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/29 19:58:48 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define BLOCK_SIZE 4096
# define READ_ERROR -99

# include <stddef.h>

typedef struct s_buffer
{
	char	buf[BUFFER_SIZE];
	char	*bufp;
	int		n;
}			t_buffer;

typedef struct s_string
{
	char	*str;
	size_t	max_len;
	size_t	len;
}			t_string;

char		*get_next_line(int fd);

int			ft_getc(int fd);
t_string	*ft_putc(t_string *str, char c);
t_string	*init_str(void);
void		free_str(t_string *str);

#endif
