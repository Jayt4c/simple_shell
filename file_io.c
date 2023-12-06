#include "shell.h"

/**
 * execute_file - executes file
 * @filename: name of file
 *
 **/

int file_descriptor;
char *line = NULL;
size_t line_size = 0;
ssize_t line_length; int file_decriptor;

void execute_file(const char *filename)
{
	file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
	{
		perror("Failed to open file");
		return;
	}

	while((line_length = getline(&line, &line_size, fdopen(file_descriptor, "r"))) != -1)
	{
		line[line_length - 1] = '\0';
		execute_promptcommand(line);
	}

	close(file_descriptor);
	free(line);
}
