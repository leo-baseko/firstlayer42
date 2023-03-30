/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:55:27 by ldrieske          #+#    #+#             */
/*   Updated: 2023/03/30 17:00:29 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		cread;
	int		ctotal;
	char	congoing;
	char	*buffer;
	char	*newbuffer;
	char	*result;

	cread = 0;
	ctotal = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	// chaud il va read 1 caractere a la fois
	// c'est pas ce  qu'on veut : soucis d'optimisation
	// faudrais par exemple lire chaque caractere du buffer a la place
	// de plus on utilise pas de static la
	while (read(fd, &congoing, 1) > 0)
	{
		buffer[cread] = congoing;
		cread++;
		ctotal++;
		if (cread == BUFFER_SIZE)
		{
			newbuffer = malloc(sizeof(char) * (ctotal + BUFFER_SIZE));
			if (newbuffer == NULL)
				return (NULL);
			memcpy(newbuffer, buffer, cread * sizeof(char));
			free(buffer);
			buffer = newbuffer;
		}
		if (congoing == '\n')
			break ;
	}
	if (cread == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[cread] = '\0';
	result = malloc(sizeof(char) * (cread + 1));
	if (!result)
		return (NULL);
	memcpy(result, buffer, (cread + 1) * sizeof(char));
	free(buffer);
	return (result);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
