/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:55:27 by ldrieske          #+#    #+#             */
/*   Updated: 2023/05/20 14:17:56 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*fd_error(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*substract_line(int nl_pos, char **buffer)
{
	char	*res;
	char	*temp;

	temp = 0;
	if (nl_pos == -1)
		return (fd_error(buffer));
	if (nl_pos == 0)
	{
		if (!**buffer)
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	temp = ft_substr(*buffer, nl_pos, BUFFER_SIZE);
	res = *buffer;
	res[nl_pos] = 0;
	*buffer = temp;
	return (res);
}

char	*read_line(int fd, char **buffer, char *buffer2)
{
	char	*newline;
	char	*temp;
	int		b_read;
	int		nl_pos;

	newline = ft_strchr(*buffer, '\n');
	temp = 0;
	b_read = 0;
	nl_pos = 0;
	while (!newline)
	{
		b_read = read(fd, buffer2, BUFFER_SIZE);
		if (b_read <= 0)
			return (substract_line(b_read, buffer));
		buffer2[b_read] = 0;
		temp = ft_strjoin(*buffer, buffer2);
		free_null(buffer);
		*buffer = temp;
		newline = ft_strchr(*buffer, '\n');
	}
	nl_pos = newline - *buffer + 1;
	return (substract_line(nl_pos, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX + 1];
	char		*buffer2;
	char		*res;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer2 = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer2)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	res = read_line(fd, &buffer[fd], buffer2);
	free_null(&buffer2);
	return (res);
}
