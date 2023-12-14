#include "shell.h"

/**
 * redirect - directs the command to the function
 *
 * @command: The command that will be directed
 *
 * Return: error
*/

int redirect(char *command)
{
	if (strlen(command) == 0)
	{
		free(command);
		return (1);
	}
	if (strcmp(command, "exit") == 0)
	{
		free(command);
		return (1);
	}
	if (_strcmp(command, "env") == 0)
	{
		lst_env();
		free(command);
		return (1);
	}
	return (0);
}
