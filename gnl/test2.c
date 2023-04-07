#include "get_next_line.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *res;
        size_t  len;
        size_t  i;
        size_t  j;

        if (!s1 || !s2)
                return (NULL);
        len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
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

char	*create_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;
	
	i = 0;
	while(buffer[i] != '\0')
	{
		i++;
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
	}
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char *result;
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	result = create_line(buffer);
	free(buffer);
	return (result);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
