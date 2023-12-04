#include "shell.h"

/**
 * main - display, read, and execute prompt command
 * Return: infinite loop
 **/

int main(void)
{
	char command[1024];

	for (;;)
	{
		display_prompt();
		get_input(command, sizeof(command));
		if (strlen(command) == 0)
		{
			continue;
		}
		execute_promptcommand(command);
	}

	return (0);
}
