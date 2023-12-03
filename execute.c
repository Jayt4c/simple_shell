#include "shell.h"

/**
 * execute_promptcommand - Execute the command entered at the prompt.
 *
 * @command: The command string to execute
 *
 **/

void execute_promptcommand(const char *command)
{
	char **args;
	size_t command_length = strlen(command) + 1;
	pid_t child_pid = fork();

	switch (child_pid)
	{
		case -1:
			perror("fork child process failed");
			exit(EXIT_FAILURE);

		case 0:
			;
			args = malloc(2 * sizeof(char *));
			args[0] = (char *)command;
			args[1] = NULL;

			if (args == NULL)
			{
				perror("malloc failed");
				exit(EXIT_FAILURE);
			}

			if (strncpy(args[0], command, command_length) != 0)
			{
				free(args);
				exit(EXIT_FAILURE);
			}

			args[1] = NULL;

			if (execve(command, args, NULL) == -1)
			{
				perror("child process execve failed");
				exit(EXIT_FAILURE);
			}

		default:
			wait(NULL);

	}
}
