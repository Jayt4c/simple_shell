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
	int i;

	if (strchr((char *)command, '|') != NULL)
	{
		execute_pipe_commands(command);
	}

	if (strcmp(args[0], "echo") == 0)
	{
		for (i = 1; args[i] != NULL; i++)
		{
			printout(args[i]);
		}
		printout("\n");
	}
	else if (strcmp(args[0], "cat") == 0)
	{
		cat(args[1]);
	}
	else
	{
		if (execv(command, args) == -1)
		{
			if (errno == ENOENT)
			{
				printout("No such files or directory found\n");
				printout("Exiting command: ");
				printout(command);
				printout(".\n");
			}
			else
			{
				perror("child process failed");
				exit(EXIT_FAILURE);
			}
		}
	}
}
