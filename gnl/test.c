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
    // si le caractere en cours est egal a '\n', on sort de la boucle APRES L'AVOIR AJOUTE DANS LE BUFFER
	while (read(fd, &congoing, 1) > 0)
	{
		// on ajoute le caractere en cours dans le buffer1
        buffer[cread] = congoing;
		cread++;
		ctotal++;
		// si la position du caractere en cours est egale au BUFFER_SIZE, on remalloc le buffer grace a cette conndition
        if (cread == BUFFER_SIZE)
		{
			newbuffer = malloc(sizeof(char) * (ctotal + BUFFER_SIZE));
			if (newbuffer == NULL)
				return (NULL);
			// memcpy my beloved (j'ai deja oublie ce que tu faisais)
            memcpy(newbuffer, buffer, cread * sizeof(char));
			free(buffer);
			buffer = newbuffer;
		}
		if (congoing == '\n')
			break ;
	}
	// protection au cas ou le fichier texte est nul
	if (!cread)
	{
		free(buffer);
		return (NULL);
	}
    // ajout de la valeur nulle a la fin de la string parce que sinon voila quoi
	buffer[cread] = '\0';
    // malloc le resultat normal ma poule
	result = malloc(sizeof(char) * (cread + 1));
	if (!result)
		return (NULL);
    // memcpy la valeur du buffer dans la string result
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
	close(fd);
	return (0);
}
