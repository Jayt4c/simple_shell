#include "shell.h"

/**
 * execute_file - executes file
 * @filename: name of file
 *
 **/


void execute_file(const char *filename)
{
	char *line = NULL;
	size_t line_size = 0;
	int fd;
	ssize_t line_length;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("Failed to open file");
		return;
	}

	while ((line_length = getline(&line, &line_size, fdopen(fd, "r"))) != -1)
	{
		if (line_length > 0 && line[line_length] - 1)
		{
			line[line_length - 1] = '\0';
		}

		execute_promptcommand(line);
	}

	close(fd);
	free(line);
}
