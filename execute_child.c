#include "shell.h"

/**
 * execute_child_process - Execute the execve
 *
 * @args: pointer to a pointer that holds arguments
 * @command: command entered
 *
 **/

void execute_child_process(char **args, const char *command)
{
	if (execve(command, args, NULL) == -1)
	{
		if (errno == ENOENT)
			printout("directory not found.\n");
		else
			perror("child process execve failed");

		free(args[0]);
		free(args);
		exit(EXIT_FAILURE);
	}
}
