/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:55:27 by ldrieske          #+#    #+#             */
/*   Updated: 2023/03/29 16:34:02 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <ctype.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = strlen((char *)s1) + strlen((char *)s2);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

int	asnextline(char *string)
{
	int	i;
	
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*add;
	// char	*result;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);

	add = malloc(sizeof(char) * (1));
	if (!add)
		return (0);
	add = ft_strjoin(add, buffer);
	printf("add 1 : %s\n", add);
	printf("buffer 1 : %s\n", buffer);
	read(fd, buffer, BUFFER_SIZE);
	add = ft_strjoin(add, buffer);
	printf("add 2 : %s\n", add);
	printf("buffer 2 : %s\n", buffer);
	read(fd, buffer, BUFFER_SIZE);
	add = ft_strjoin(add, buffer);
	printf("add 3 : %s\n", add);
	printf("buffer 3 : %s\n", buffer);

	i = 0;
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
