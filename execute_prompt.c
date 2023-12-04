#include "shell.h"

/**
 * execute_promptcommand - Execute the command entered at the prompt.
 *
 * @command: The command string to execute
 *
 **/

void execute_promptcommand(const char *command)
{
	char **args; int count; size_t i;
	size_t command_length = strlen(command) + 1;
	pid_t child_pid = fork();

	/*count no of arguments*/
	for (i = 0; i < command_length; i++)
	{
		if (command[i] == ' ')
		{
			count++;
		}
	}

	args = malloc((count + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	/* Tokenization */
	tokenize(command, args);

	switch (child_pid)
	{

		case -1:
			perror("fork child process failed");
			exit(EXIT_FAILURE);

		case 0:
			execute_child_process(args, command);
			break;

		default:
			wait(NULL);
			free_args(args);
	}
}
