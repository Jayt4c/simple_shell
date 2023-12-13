#include "shell.h"

/**
 * main - display, read, and execute prompt command
 * Return: infinite loop
 **/

int main(void)
{
	/*char command[1024];*/

	for (;;)
	{
		char *command = NULL;
		char** cmd_args = NULL;
		size_t size = 0;
		display_prompt();

		if (getline(&command, &size, stdin) = -1)
		{
			free(command);
			exit(0);
		}
		if (strlen(command) == 0)
			continue;

		if (strcmp(command, "exit") == 0)
		{
			printout("Exiting shell...\n");
			break;
		}
		if ((command[0] >= 'a' && command[0] <= 'z') || (command[0] >= 'A'
			&& command[0] <= 'Z'))
		{
			cmd_args = tokenize(command);
			path_handler(cmd_args[0], cmd_args);
			free_args(cmd_args);
		}
		else if (command[0] == '/')
		{
			cmd_args = tokenize(command);
			execute_promptcommand(cmd_args[0], cmd_args);
			free_args(cmd_args);
		}
		free(command);
	}

	return (0);
}
