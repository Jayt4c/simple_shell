#include "shell.h"

/**
 * count_commands - count the number of commands in a string
 *
 * @command: the command string to count commands in
 *
 * Return: the number of commands in the string
 */
int count_commands(const char *command)
{
	int i;
	int count = 1;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '|')
		{
			count++;
		}
	}

	return (count);
}

