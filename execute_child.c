#include "shell.h"

/**
 * execute_child_process - Execute the execve
 *
 * @args: pointer to a pointer that holds arguments
 * @command: command entered
void free_args(char **args, int count);
 *
 **/
void execute_child_process(char **args, const char *command)
{
	if (execve(command, args, NULL) == -1)
	{
		if (errno = ENOENT)
		{
			printout("Exiting command: ");
			printout(command);
			printout("\n");
		}
		else 
		{
			perror("child process failed");
			exit(EXIT_FAILURE);
		}
	}
}
