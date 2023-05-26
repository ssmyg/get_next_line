/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:04:42 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/05/26 16:50:35 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 4096
#define READ_ERROR -99

typedef struct s_buffer
{
	char	buf[BUF_SIZE];
	char	*bufp;
	int		n;
}			t_buffer;

char		*get_next_line(int fd);
int			ft_getchar(int fd);
