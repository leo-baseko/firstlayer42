#include "get_next_line.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *res;
        size_t  len;
        size_t  i;
        size_t  j;

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

void savefd(int fd)
{
	char *buffer;
	static char *text;

	// malloc de buffer
	buffer = malloc(sizeof(char) * 5 + 1);
	if (!buffer)
		return ;
	read(fd, buffer, 5);
	buffer[5] = '\0';
	printf("premier read buffer : [%s]\n", buffer);
	text = malloc(sizeof(char) * 5 + 1);
	if (!text)
		return ;
	// creation de text a partir de strcpy
	strcpy(text, buffer);
	printf("premier read text : [%s]\n", text);
	read(fd, buffer, 5);
	buffer[5] = '\0';
	printf("deuxieme read buffer : [%s]\n", buffer);
	// ajout du contenu de buffer 
	text = ft_strjoin(text, buffer);
	printf("\n<conclusion>\n\nbuffer : [%s]\ntext : [%s]\n", buffer, text);
	free(buffer);
}

char	*gnl(int fd)
{
	char		*buffer;
	char		*line;
	// text ou on va piocher dedans pour line
	static char	*text;
	// garde en memoire la position dans text
	static int	pos;
	// permettra de verifier chaque caracteres du buffer
	char		currentc;
	int			i;
	int			j;
	int			leread;

	// malloc de buffer
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	text = malloc(sizeof(char) * 5 + 1);
	if (!text)
		return ;
	strcpy(text, buffer);
	leread = read(fd, buffer, BUFFER_SIZE);
	
	// si read return 0 et text est vide -> error
	if (leread <= 0 && !text)
		return (0);
	// si read return 0 et text pas vide -> line == reste de text a partir de pos
	if (leread <= 0 && text)
	{	
		line = buffer;
	}
	// si read return val > 0 mais text vide -> possible ?
	if (leread > 0 && !text)
	{
		ft_strjoin(text, buffer);
	}
	// si read return val > 0 et text non vide -> ajouter buffer dans text et line est de position pos a '\n' ou '\0'
	if (leread > 0 && text)
	{

	}
	free(buffer);
	return (line);
}

int main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", gnl(fd));
	close(fd);
	return (0);
}