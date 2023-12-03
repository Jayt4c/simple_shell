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
		command[strcspn(command, "\n")] = '\0';
		execute_promptcommand(command);
	}
}
