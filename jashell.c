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
		size_t size = 0;

		display_prompt();
		get_input(&command, &size);
		if (strlen(command) == 0)
		{
			continue;
		}
		if (strcmp(command, "exit") == 0)
		{
			printout("Exiting shell...\n");
			break;
		}
		if ((command[0] >= 'a' && command[0] <= 'z') || (command[0] >= 'A'
			&& command[0] <= 'Z'))
		{
			path_handler(command);
			/*execute_promptcommand(command);*/
		} else if (command[0] == '/')
		{
			path_handler(command);
		}

		free(command);
		command = NULL;
		size = 0;
	}

	return (0);
}
