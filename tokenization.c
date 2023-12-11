#include "shell.h"

/**
 * execute_promptcommand - Execute the command entered at the prompt.
 *
 * @command: The command string to execute
 *
 **/

void tokenize(const char *command, char **args)
{
	size_t i; int j;
	
	char *token = strtok((char *)command, " ");
	i = 0;
	while (token != NULL)
	{
		args[i] = malloc(strlen(token) + 1);
		if (args[i] == NULL)
		{
			perror("malloc for tokenzation failed");
			for (j = 0; j < 1; j++)
			{
				free(args[j]);
			}
			free(args);
			exit(EXIT_FAILURE);
		}
		strcpy(args[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

}

void free_args(char **args)
{
	size_t i;
	for (i = 0; i < 1; i++)
	{
		free(args[i]);
	}
	free(args);
}
