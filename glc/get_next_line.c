/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaing <jtaing@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:43:20 by jtaing            #+#    #+#             */
/*   Updated: 2024/04/25 07:43:23 by jtaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	file_desc(int fd, t_string *str)
{
	ssize_t	t_r;
	ssize_t	i;
	char	*tmp;

	i = 0;
	t_r = BUFFER_SIZE;
	while (!new_line(str->inside + i, &i) && t_r == BUFFER_SIZE)
	{
		if (str->len + BUFFER_SIZE >= str->m_s)
		{
			tmp = malloc(str->m_s * 2);
			if (!tmp)
				return (-1);
			ft_strlcpy(tmp, str->inside, str->len + 1);
			free(str->inside);
			str->inside = tmp;
			str->m_s *= 2;
		}
		t_r = read(fd, str->inside + str->len, BUFFER_SIZE);
		if (t_r == -1)
			return (-1);
		str->len += t_r;
		str->inside[str->len] = 0;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	t_string	str;
	char		*line;
	static char	rest[BUFFER_SIZE] = {0};
	ssize_t		l_l;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str.m_s = BUFFER_SIZE + 1;
	str.inside = malloc(str.m_s);
	if (!str.inside)
		return (NULL);
	str.len = 0;
	while (rest[str.len])
		str.len++;
	ft_strlcpy(str.inside, rest, str.len + 1);
	l_l = file_desc(fd, &str);
	if (l_l == -1 || !*str.inside)
		return (free(str.inside), NULL);
	line = malloc(l_l + 1);
	if (!line)
		return (free(str.inside), NULL);
	ft_strlcpy(line, str.inside, l_l + 1);
	ft_strlcpy(rest, str.inside + l_l, str.len - l_l + 1);
	return (free(str.inside), line);
}
