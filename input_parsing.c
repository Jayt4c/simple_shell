#include "shell.h"

/**
 * get_input - Gets input from the standard input stream
 * @command: the strings command in a buffer
 * @size: size of command
 *
 **/

void get_input(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		printout("error due to end-of-file\n");
		exit(EXIT_FAILURE);
	}
	command[strcspn(command, "\n")] = '\0';
}
