/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:55:27 by ldrieske          #+#    #+#             */
/*   Updated: 2023/05/16 17:28:07 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * free_null
 *
 * Take a pointer and frees it
*/
void	free_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		ptr = NULL;
	}
}

/*
 * merge_line 
 *
 * prend la position (?) et double buffer pour me casser les couilles ca ptn
 * il est long le code
 * si la position newline est egale ou inferieur a 0 -> on free le buffer
 * on utilise un tampon qui va prendre ft_substr
*/
char	*merge_line(int newline_position, char **buffer)
{
	char	*res;
	char	*temp;

	temp = NULL;
	if (newline_position <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	temp = ft_substr(*buffer, newline_position, BUFFER_SIZE);
	res = *buffer;
	res[newline_position] = 0;
	*buffer = temp;
	return (res);
}

/*
 * read_line
 * 
 * Returns the line that as been read
*/
char	*read_line(int fd, char **buffer, char *bunny)
{
	char	*newline;
	char	*temp;
	int		b_read;

	newline = ft_strchr(*buffer, '\n');
	temp = 0;
	b_read = 0;
	while (!newline)
	{
		b_read = read(fd, bunny, BUFFER_SIZE);
		if (b_read <= 0)
			return (merge_line(b_read, buffer));
		bunny[b_read] = '\0';
		temp = ft_strjoin(*buffer, bunny);
		free_null(buffer);
		*buffer = temp;
		newline = ft_strchr(*buffer, '\n');
	}
	return (merge_line(newline - *buffer + 1, buffer));
}

/*
 * get_next_line
 * 
 * Returns a line read from a file descriptor
 * The line is either finishing by '\n' or the end of the file
 * Returns NULL if an error occur
*/
char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD + 1];
	char		*bunny;
	char		*res;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	bunny = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!bunny)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	res = read_line(fd, &buffer[fd], bunny);
	free_null(&bunny);
	return (res);
}
