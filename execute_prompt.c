#include "shell.h"

/**
 * execute_promptcommand - Execute the command entered at the prompt.
 *
 * @command: The command string to execute
 *
 **/

void execute_promptcommand(const char *command)
{
	char **args, *hold;
	int x;
	pid_t child_pid;

	args = malloc(2 * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	hold = strtok((char *)command, " ");

	for (x = 0; hold; x++)
	{
		args[x] = malloc(64);
		if (!args[x])
		{
			x -= 1;
			for (; x >= 0; x--)
				free(args[x]);
			return;
		}
		strcpy(args[x], hold);
		hold = strtok(NULL, " ");
	}
	args[x] = NULL;

	child_pid = fork();
	switch (child_pid)
	{
		case -1:
			perror("fork child process failed");
			exit(EXIT_FAILURE);

		case 0:
			/*execv(args[0], args);*/
			execute_child_process(args, args[0]);
			break;

		default:
			wait(NULL);
			free(args[0]);
			free(args);
	}
}
