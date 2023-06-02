/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:42 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/06/02 12:15:46 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define BLOCK_SIZE 4096
# define READ_ERROR -99
# define DUMMY_FD -9999

# include <stddef.h>

typedef struct s_buffer
{
	int				fd;
	struct s_buffer	*next;

	int				n;
	char			*bufp;
	char			buf[BUFFER_SIZE];
}					t_buffer;

typedef struct s_string
{
	char			*str;
	size_t			max_len;
	size_t			len;
}					t_string;

char				*get_next_line(int fd);
int					ft_getc(int fd);

#endif
