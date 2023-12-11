#include "shell.h"

/**
 * cat - fuction for cat
 * @file: parameter 1
 *
 */


#define BUFFER_SIZE 2048
void cat(const char *file)
{
	int fd, bytesRead;
	char buffer[BUFFER_SIZE];

	fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		perror("Cannot open file");
		return;
	}

	while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		write(STDOUT_FILENO, buffer, bytesRead);
	}

	close(fd);
}
