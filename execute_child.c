#include "shell.h"

/**
 * execute_child_process - Execute the execve
 *
 * @args: pointer to a pointer that holds arguments
 * @command: command entered
 * @input_fd: input
 * @output_fd: output
void free_args(char **args, int count);
 *
 **/
void execute_child_process(char **args, const char *command, int input_fd, int output_fd)
{
	int i;

	if (input_fd != STDIN_FILENO)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}

	if (output_fd != STDOUT_FILENO)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}

	if (strcmp(args[0], "echo") == 0)
	{
		for (i = 1; args[i] != NULL; i++)
		{
			printout(args[i]);
		}
		printout("\n");
	} else
	{
		if (execve(command, args, NULL) == -1)
		{
			if (errno = ENOENT)
			{
				printout("No such files or directory found\n");
				printout("Exiting command: ");
				printout(command);
				printout("\n");
			} else
			{
				perror("child process failed");
				exit(EXIT_FAILURE);
			}
		}
	}
}
