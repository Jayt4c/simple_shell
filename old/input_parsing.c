#include "shell.h"

/**
 * get_input - Gets input from the standard input stream
 * @command: the strings command in a buffer
 * @size: size of command
 *
 **/

void get_input(char **command, size_t *size)
{
	ssize_t input_size = getline(command, size, stdin);

	if (input_size == -1)
	{
		/*printout("exit due to end-of-file\n");*/
		exit(EXIT_FAILURE);
	}
	(*command)[input_size - 1] = '\0';
}

void non_interactive_mode(const char *filename)
{
	execute_file(filename);
}
