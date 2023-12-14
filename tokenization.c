#include "shell.h"

/**
 * tokenize - Tokenizes the entered command
 *
 * @cmd: The command string to be seperated
 *
 * Return: Array of arguments
*/

char **tokenize(char *cmd)
{
	char **arr;
	size_t x;
	int y;

	x = strlen(cmd);

	arr = malloc(sizeof(char *) * x);
	if (!arr)
		perror("Allocation failed\n");

	y = 0;
	arr[0] = strtok(cmd, " ");
	while (arr[y] != NULL)
	{
		y++;
		arr[y] = strtok(NULL, " ");
	}
	return (arr);
}

/**
 * free_args - frees array of strings
 *
 * @args: An array will be freed
 *
 * Return: void
 */

void free_args(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; ++i)
		free(args[i]);

	free(args);
}

/**
 * free_args_1 - frees array of strings
 *
 * @args: An array will be freed
 *
 * Return: void
*/
void free_args_1(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i + 1]; ++i)
		free(args[i]);

	free(args);
}

