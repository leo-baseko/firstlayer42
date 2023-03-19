#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 1024
#endif

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    size_t numBytesRead;

	fd = open("0-texte", O_RDONLY);
    if (fd == -1)
		return (0);

	numBytesRead = 1;
    while (numBytesRead > 0) {
		numBytesRead = read(fd, buffer, BUFFER_SIZE);
        write(1, buffer, numBytesRead);
	}
	buffer[numBytesRead] = 0;

    close(fd);
    return 0;
}
