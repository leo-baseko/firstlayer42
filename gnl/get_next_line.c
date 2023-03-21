/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:55:27 by ldrieske          #+#    #+#             */
/*   Updated: 2023/03/21 11:45:07 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_count(char line)
{
	static int	count;
	(void)line;

	count = 0;
	return (0);
}

/*
 * get_next_line
 *
 * Returns the line that was read. If there's nothing/an error, returns NULL
 * 
 * int fd : file descriptor with the sweets lines we want
*/

char	*get_next_line(int fd)
{
	int		size;
	char	*buffer;
	size_t	numbytes;

	size = (int)BUFFER_SIZE;
	if (size > 100000 || size < 1)
		size = 2048;
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (0);
	numbytes = 1;
	while (numbytes > 0)
	{
		numbytes = read(fd, buffer, BUFFER_SIZE);
		write(1, buffer, numbytes);
	}
	buffer[numbytes] = 0;
	return (0);
}

int	main(void)
{
	int		fd;

	fd = open("del_texte", O_RDONLY);
	if (fd == -1)
		return (0);
	get_next_line(fd);
	close(fd);
	return (0);
}
