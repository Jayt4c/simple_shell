#include "shell.h"

/**
 * main - display, read, and execute prompt command
 * Return: infinite loop
 **/

int main(void)
{
	/*char command[1024];*/
	char *command = NULL;
	char **cmd_args = NULL;
	size_t x;
	int measure;

	do
	{
		size_t size = 0;
		display_prompt();
		measure = getline(&command, &size, stdin);	
		if (measure == -1)
		{
			free(command);
			exit(0);
		}
		x = strlen(command);
		command[x - 1] = '\0';
		if (strlen(command) == 0)
		{
			free(command);
			continue;
		}
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			return (69);
		}
		cmd_args = tokenize(command);
		if (path_handler(cmd_args[0], cmd_args) == 0)
		{
			execute_promptcommand(cmd_args[0], cmd_args);
			free(cmd_args);
			free(command);
			continue;
		}
		else
		{
			free(cmd_args);
			free(command);
		}
	} while (isatty(STDIN_FILENO) || measure != EOF);
	
	return (0);
}