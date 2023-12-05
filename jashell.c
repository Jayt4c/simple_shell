#include "shell.h"

/**
 * main - display, read, and execute prompt command
 * Return: infinite loop
 **/

int main(void)
{
	char command[101];

	for (;;)
	{
		display_prompt();
		get_input(command, sizeof(command));
		if (strlen(command) == 0)
		{
			continue;
		}
<<<<<<< HEAD
		path_handler(command);
=======

		if (strcmp(command, "exit") == 0)
		{
			printout("Exiting shell...\n");
			break;
		}

		execute_promptcommand(command);
>>>>>>> c5ce43d1a6db1bf8a07df454ccdf91c9c0984dc3
	}

	return (0);
}
