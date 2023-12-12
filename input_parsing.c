#include "shell.h"

/**
 * get_input - Gets input from the standard input stream
 * @command: the strings command in a buffer
 * @size: size of command
 *
 **/

void get_input(char *command, size_t size)
{
	char command[1024];

	if (fgets(command, size, stdin) == NULL)
	{
		printout("exit due to end-of-file\n");
		exit(EXIT_FAILURE);
	}
	command[strcspn(command, "\n")] = '\0';
}

void non_interactive_mode(const char *filename)
{
	execute_file(filename);
}
