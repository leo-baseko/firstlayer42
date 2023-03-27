/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:55:27 by ldrieske          #+#    #+#             */
/*   Updated: 2023/03/27 19:32:08 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <ctype.h>
char *get_next_line(int fd)
{
	int			i;
	int			c;
	int			d;
	int			size;
	char		*buffer;
	size_t		numbytes;
	static int	o;
	
	//arranger max et min BUFFER_SIZE
	size = (int)BUFFER_SIZE;
	if (size > 100000 || size < 1)
		size = 2048;
	//malloc buffer
	buffer = malloc(sizeof(char) * (size));
	if (!buffer)
		return (0);
	numbytes = 1;
	c = 0;
	//boucle tant qu'on n'arrive pas a la fin du fd
	while (numbytes > 0)
	{
		numbytes = read(fd, buffer, size);
		if (numbytes != 0)
			c += numbytes;
	}
	
	d = 0;
	o = 0;
	while (isprint(buffer[d]) != 0 && buffer[d] != '\n')
		d++;
	char *coucou;
	coucou = malloc(sizeof(char) * (d + 1));
	if (!coucou)
		return (0);
	i = 0;
	while (i < d)
	{
		coucou[i] = buffer[i];
		i++;
	}
	coucou[i] = '\0';
	free(buffer);
	return (coucou);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
