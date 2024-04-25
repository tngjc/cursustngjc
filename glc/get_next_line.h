/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaing <jtaing@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:43:33 by jtaing            #+#    #+#             */
/*   Updated: 2024/04/25 07:43:43 by jtaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_string
{
	size_t	len;
	size_t	m_s;
	char	*inside;
}			t_string;

char		*get_next_line(int fd);
int			file_desc(int fd, t_string *str);
int			new_line(char *str, ssize_t *len);
void		ft_strlcpy(char *dst, const char *src, size_t size);

#endif
