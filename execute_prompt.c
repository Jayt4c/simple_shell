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
/*	int input_fd = STDIN_FILENO; 
	int output_fd = STDOUT_FILENO;*/
	size_t command_length = strlen(command) + 1;
	pid_t child_pid;

	args = malloc(2 * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	args[0] = malloc(command_length);
	if (args[0] == NULL)
	{
		perror("malloc failed");
		free(args);
		exit(EXIT_FAILURE);
	}
	strcpy(args[0], command);

	args[1] = NULL;

	child_pid = fork();
	switch (child_pid)
	{
		case -1:
			perror("fork child process failed");
			exit(EXIT_FAILURE);

		case 0:
			tokenize(command, args);
			execute_child_process(args, command/*, input_fd, output_fd*/);
			break;

		default:
			wait(NULL);
			free(args[0]);
			free(args);
			/*exit(EXIT_FAILURE);*/

	}

}
